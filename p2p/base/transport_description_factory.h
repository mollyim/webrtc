/*
 *  Copyright 2012 The WebRTC Project Authors. All rights reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */

#ifndef P2P_BASE_TRANSPORT_DESCRIPTION_FACTORY_H_
#define P2P_BASE_TRANSPORT_DESCRIPTION_FACTORY_H_

#include <memory>

#include "p2p/base/ice_credentials_iterator.h"
#include "p2p/base/transport_description.h"
#include "rtc_base/rtc_certificate.h"

namespace rtc {
class SSLIdentity;
}

namespace cricket {

struct TransportOptions {
  bool ice_restart = false;
  bool prefer_passive_role = false;
  // If true, ICE renomination is supported and will be used if it is also
  // supported by the remote side.
  bool enable_ice_renomination = false;
};

// Creates transport descriptions according to the supplied configuration.
// When creating answers, performs the appropriate negotiation
// of the various fields to determine the proper result.
class TransportDescriptionFactory {
 public:
  // Default ctor; use methods below to set configuration.
  TransportDescriptionFactory();
  ~TransportDescriptionFactory();

  // The certificate to use when setting up DTLS.
  const rtc::scoped_refptr<rtc::RTCCertificate>& certificate() const {
    return certificate_;
  }

  // Specifies the certificate to use.
  // When a certificate is set, transport will be encrypted.
  void set_certificate(
      const rtc::scoped_refptr<rtc::RTCCertificate>& certificate) {
    certificate_ = certificate;
  }

  bool IsEncrypted() const { return certificate_ != nullptr; }

  // Creates a transport description suitable for use in an offer.
  std::unique_ptr<TransportDescription> CreateOffer(
      const TransportOptions& options,
      const TransportDescription* current_description,
      IceCredentialsIterator* ice_credentials) const;
  // Create a transport description that is a response to an offer.
  //
  // If `require_transport_attributes` is true, then TRANSPORT category
  // attributes are expected to be present in `offer`, as defined by
  // sdp-mux-attributes, and null will be returned otherwise. It's expected
  // that this will be set to false for an m= section that's in a BUNDLE group
  // but isn't the first m= section in the group.
  std::unique_ptr<TransportDescription> CreateAnswer(
      const TransportDescription* offer,
      const TransportOptions& options,
      bool require_transport_attributes,
      const TransportDescription* current_description,
      IceCredentialsIterator* ice_credentials) const;

 private:
  bool SetSecurityInfo(TransportDescription* description,
                       ConnectionRole role) const;

  rtc::scoped_refptr<rtc::RTCCertificate> certificate_;
};

}  // namespace cricket

#endif  // P2P_BASE_TRANSPORT_DESCRIPTION_FACTORY_H_
