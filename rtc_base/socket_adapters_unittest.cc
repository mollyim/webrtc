/*
 *  Copyright 2026 The WebRTC Project Authors. All rights reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */

#include "rtc_base/socket_adapters.h"

#include <cstddef>
#include <cstdint>
#include <cstring>
#include <memory>
#include <span>

#include "rtc_base/crypt_string.h"
#include "rtc_base/mock_socket.h"
#include "rtc_base/socket.h"
#include "rtc_base/socket_address.h"
#include "test/gmock.h"
#include "test/gtest.h"

namespace webrtc {
namespace {

using ::testing::_;
using ::testing::ElementsAre;
using ::testing::ElementsAreArray;
using ::testing::Ge;
using ::testing::InSequence;
using ::testing::Return;
using ::testing::StrictMock;

void ExpectSocksConnectRequest(const SocketAddress& destination,
                               std::span<const uint8_t> expected_request) {
  const SocketAddress proxy_address("192.0.2.1", 1080);
  auto socket = std::make_unique<StrictMock<MockSocket>>();
  MockSocket* transport = socket.get();
  AsyncSocksProxySocket proxy(socket.release(), proxy_address, "",
                              CryptString());

  {
    InSequence sequence;
    EXPECT_CALL(*transport, Connect(proxy_address)).WillOnce(Return(0));
    EXPECT_CALL(*transport, Send(_, 3))
        .WillOnce([](const void* data, size_t size) {
          EXPECT_THAT(std::span(static_cast<const uint8_t*>(data), size),
                      ElementsAre(5, 1, 0));
          return static_cast<int>(size);
        });
    EXPECT_CALL(*transport, Recv(_, Ge(2u), _))
        .WillOnce([](void* data, size_t, int64_t*) {
          const uint8_t reply[] = {5, 0};
          std::memcpy(data, reply, sizeof(reply));
          return static_cast<int>(sizeof(reply));
        });
    EXPECT_CALL(*transport, Send(_, expected_request.size()))
        .WillOnce([expected_request](const void* data, size_t size) {
          EXPECT_THAT(std::span(static_cast<const uint8_t*>(data), size),
                      ElementsAreArray(expected_request));
          return static_cast<int>(size);
        });
  }

  ASSERT_EQ(0, proxy.Connect(destination));
  transport->NotifyConnectEvent(transport);
  transport->NotifyReadEvent(transport);
}

TEST(AsyncSocksProxySocketTest, EncodesIpv6Destination) {
  const uint8_t request[] = {5,    1,    0,    4,    0x20, 0x01, 0x0d, 0xb8,
                             0x12, 0x34, 0x56, 0x78, 0x90, 0xab, 0xcd, 0xef,
                             0x01, 0x02, 0x03, 0x04, 0x01, 0xbb};
  ExpectSocksConnectRequest(
      SocketAddress("2001:db8:1234:5678:90ab:cdef:102:304", 443), request);
}

TEST(AsyncSocksProxySocketTest, PreservesIpv4Destination) {
  const uint8_t request[] = {5, 1, 0, 1, 192, 0, 2, 2, 0x01, 0xbb};
  ExpectSocksConnectRequest(SocketAddress("192.0.2.2", 443), request);
}

TEST(AsyncSocksProxySocketTest, PreservesHostnameForProxyResolution) {
  const uint8_t request[] = {5,   1,   0,   3,   11,  'e', 'x', 'a',  'm',
                             'p', 'l', 'e', '.', 'o', 'r', 'g', 0x01, 0xbb};
  ExpectSocksConnectRequest(SocketAddress("example.org", 443), request);
}

}  // namespace
}  // namespace webrtc
