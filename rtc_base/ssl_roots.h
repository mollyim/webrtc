/*
 *  Copyright 2023 The WebRTC Project Authors. All rights reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */

#ifndef RTC_BASE_SSL_ROOTS_H_
#define RTC_BASE_SSL_ROOTS_H_

#include <cstddef>

// This file is the root certificates in C form.

// It was generated with the following script:
// tools_webrtc/sslroots/generate_sslroots.py Mozilla_CA_bundle.pem

// clang-format off
// Don't bother formatting generated code,
// also it would breaks subject/issuer lines.

/* subject:/C=US/ST=California/L=Mountain View/O=Signal Messenger, LLC/CN=Signal Messenger */
/* issuer :/C=US/ST=California/L=Mountain View/O=Signal Messenger, LLC/CN=Signal Messenger */


const unsigned char Signal_Messenger__certificate[1503]={
0x30,0x82,0x05,0xDB,0x30,0x82,0x03,0xC3,0xA0,0x03,0x02,0x01,0x02,0x02,0x14,0x00,
0xC1,0xF3,0xE2,0x0E,0xB4,0x70,0x80,0xC1,0xA4,0xFA,0xF5,0x83,0x26,0x7F,0x24,0x36,
0x9A,0x3E,0x97,0x30,0x0D,0x06,0x09,0x2A,0x86,0x48,0x86,0xF7,0x0D,0x01,0x01,0x0B,
0x05,0x00,0x30,0x75,0x31,0x0B,0x30,0x09,0x06,0x03,0x55,0x04,0x06,0x13,0x02,0x55,
0x53,0x31,0x13,0x30,0x11,0x06,0x03,0x55,0x04,0x08,0x13,0x0A,0x43,0x61,0x6C,0x69,
0x66,0x6F,0x72,0x6E,0x69,0x61,0x31,0x16,0x30,0x14,0x06,0x03,0x55,0x04,0x07,0x13,
0x0D,0x4D,0x6F,0x75,0x6E,0x74,0x61,0x69,0x6E,0x20,0x56,0x69,0x65,0x77,0x31,0x1E,
0x30,0x1C,0x06,0x03,0x55,0x04,0x0A,0x13,0x15,0x53,0x69,0x67,0x6E,0x61,0x6C,0x20,
0x4D,0x65,0x73,0x73,0x65,0x6E,0x67,0x65,0x72,0x2C,0x20,0x4C,0x4C,0x43,0x31,0x19,
0x30,0x17,0x06,0x03,0x55,0x04,0x03,0x13,0x10,0x53,0x69,0x67,0x6E,0x61,0x6C,0x20,
0x4D,0x65,0x73,0x73,0x65,0x6E,0x67,0x65,0x72,0x30,0x1E,0x17,0x0D,0x32,0x32,0x30,
0x31,0x32,0x36,0x30,0x30,0x34,0x35,0x35,0x31,0x5A,0x17,0x0D,0x33,0x32,0x30,0x31,
0x32,0x34,0x30,0x30,0x34,0x35,0x35,0x30,0x5A,0x30,0x75,0x31,0x0B,0x30,0x09,0x06,
0x03,0x55,0x04,0x06,0x13,0x02,0x55,0x53,0x31,0x13,0x30,0x11,0x06,0x03,0x55,0x04,
0x08,0x13,0x0A,0x43,0x61,0x6C,0x69,0x66,0x6F,0x72,0x6E,0x69,0x61,0x31,0x16,0x30,
0x14,0x06,0x03,0x55,0x04,0x07,0x13,0x0D,0x4D,0x6F,0x75,0x6E,0x74,0x61,0x69,0x6E,
0x20,0x56,0x69,0x65,0x77,0x31,0x1E,0x30,0x1C,0x06,0x03,0x55,0x04,0x0A,0x13,0x15,
0x53,0x69,0x67,0x6E,0x61,0x6C,0x20,0x4D,0x65,0x73,0x73,0x65,0x6E,0x67,0x65,0x72,
0x2C,0x20,0x4C,0x4C,0x43,0x31,0x19,0x30,0x17,0x06,0x03,0x55,0x04,0x03,0x13,0x10,
0x53,0x69,0x67,0x6E,0x61,0x6C,0x20,0x4D,0x65,0x73,0x73,0x65,0x6E,0x67,0x65,0x72,
0x30,0x82,0x02,0x22,0x30,0x0D,0x06,0x09,0x2A,0x86,0x48,0x86,0xF7,0x0D,0x01,0x01,
0x01,0x05,0x00,0x03,0x82,0x02,0x0F,0x00,0x30,0x82,0x02,0x0A,0x02,0x82,0x02,0x01,
0x00,0xC4,0x79,0xC8,0x9F,0xC4,0xC1,0xC7,0x94,0x38,0x71,0x6C,0x44,0x55,0x74,0x4A,
0xCE,0x84,0x6B,0x0B,0x3B,0x4F,0x0F,0x51,0xD3,0x64,0x01,0x38,0xD9,0xD6,0x44,0xF9,
0xD6,0xE3,0xDF,0xE4,0x93,0xE2,0x45,0xBB,0xAC,0xF4,0x5E,0x09,0xFC,0x68,0x01,0x43,
0x80,0x0D,0x48,0x08,0xC8,0x0D,0x9B,0x85,0x63,0x45,0x8E,0xBC,0x6F,0xE2,0xD2,0xAB,
0xF1,0xB6,0x1A,0x56,0xEF,0x4A,0x1C,0xA7,0xC2,0x23,0x92,0x25,0x93,0x36,0x20,0x3C,
0xD7,0x34,0x0D,0x41,0xD0,0xA2,0x59,0xB1,0x83,0x53,0x80,0x75,0xB0,0xB8,0xB6,0xA3,
0x82,0x60,0x24,0xCC,0x1E,0x4A,0x44,0x05,0x8B,0x20,0xF2,0x9E,0xA5,0xA0,0x1E,0x9C,
0x3E,0x2A,0x6B,0xF2,0xB4,0x2C,0xD1,0x5A,0x7B,0xEB,0xAE,0x9B,0x48,0x7C,0x4E,0x06,
0x3F,0x13,0x4E,0xB0,0x0B,0x57,0x15,0xB5,0x47,0xFB,0xEF,0x09,0x3B,0x8D,0x88,0x68,
0xA4,0x55,0x95,0xB7,0xE9,0x7B,0xF9,0x54,0x1D,0xB8,0xE2,0x62,0x62,0x29,0x42,0xBA,
0x19,0x3C,0x63,0xD8,0xE0,0xEA,0xA5,0xF0,0xA3,0x37,0xA3,0x7F,0x4E,0x6C,0xF9,0xD3,
0xA3,0x55,0xA8,0x33,0x89,0xA8,0xC8,0xE3,0x99,0xA5,0x4D,0xE5,0x57,0x56,0xB0,0x7E,
0xDB,0xD6,0x07,0x1D,0x6C,0x6D,0x30,0x4B,0xD3,0x6B,0x10,0x59,0xF1,0xD1,0xC6,0x03,
0x55,0x17,0xE3,0xE3,0xD1,0xF7,0x43,0x30,0xC1,0x5D,0x14,0x9A,0x1B,0x02,0xBA,0xCB,
0x55,0xF2,0xB6,0x51,0xAF,0x9D,0x60,0xDE,0x29,0x57,0x95,0xC8,0xC7,0x35,0x5A,0xAD,
0x24,0x56,0xEF,0x70,0x97,0xA9,0x0F,0xB6,0xAA,0x5A,0x0F,0x5B,0xFC,0xA7,0xA5,0xAD,
0xE0,0x46,0xD6,0x1E,0x19,0x65,0x78,0x8E,0x5E,0xDE,0x0F,0x43,0xE6,0x78,0x7A,0x4A,
0x39,0x8E,0xFC,0x89,0xD3,0xF8,0x1F,0x58,0xDF,0x02,0xFD,0x13,0x01,0x57,0x8A,0xA6,
0xE0,0x79,0x64,0x56,0x76,0xB3,0x37,0x32,0x4B,0x1A,0xD0,0x6B,0xC7,0x7B,0x14,0x87,
0xF4,0x90,0xD2,0x5E,0xF6,0x02,0x11,0x8D,0xB4,0x3E,0x5E,0xBB,0xE7,0x37,0xE6,0x59,
0xBE,0x3E,0x9D,0xFB,0xCB,0x81,0x26,0xAF,0x0B,0x7D,0x06,0x85,0x86,0x55,0x5F,0x23,
0x4F,0xDA,0x21,0xD8,0x20,0x49,0xC6,0xA9,0x47,0xBC,0x3C,0xA0,0xBA,0x6F,0x75,0xF9,
0x54,0x5A,0xA7,0x13,0x2D,0xE5,0xD5,0x34,0xB5,0x6B,0x83,0x5E,0x5C,0x10,0x3C,0x1D,
0x95,0x5F,0x0F,0x56,0xC7,0x13,0xFC,0xA4,0xF4,0x6D,0xF3,0x73,0x28,0x8F,0x34,0xA8,
0x1A,0xBC,0x2F,0x24,0x66,0x6A,0xE0,0x2A,0x3F,0x40,0x83,0x8D,0xAC,0x98,0x19,0xBD,
0x94,0x01,0xA6,0xE7,0x85,0xE7,0xE0,0x99,0x16,0x3A,0x68,0x11,0x39,0x99,0x7C,0x5D,
0x6F,0x20,0x04,0xCF,0x30,0x92,0xDE,0xF0,0xF1,0x8D,0xE4,0xC3,0xF2,0xFF,0x27,0x6C,
0x3A,0xBE,0x48,0x3E,0xA5,0x26,0x2D,0x22,0xEE,0x38,0x30,0x11,0xF3,0x43,0x85,0xEF,
0x57,0x2B,0x9D,0x1B,0x68,0xAD,0x79,0x51,0xD7,0x3C,0x0A,0xBF,0xD9,0x96,0x11,0x8C,
0x8C,0xD9,0x96,0xA8,0x17,0x74,0x8C,0x8A,0x5A,0x66,0x6D,0x6B,0xCD,0x60,0x34,0x93,
0x85,0x70,0x5E,0xD0,0xF0,0xA4,0x15,0xD2,0xCF,0xCA,0x01,0x16,0xC8,0x62,0x5E,0xCD,
0xC5,0x0F,0xA8,0xC7,0x63,0x62,0x21,0x39,0x1D,0xE9,0xA5,0xBC,0x9D,0xE2,0xA4,0x54,
0xA7,0x02,0x03,0x01,0x00,0x01,0xA3,0x63,0x30,0x61,0x30,0x0E,0x06,0x03,0x55,0x1D,
0x0F,0x01,0x01,0xFF,0x04,0x04,0x03,0x02,0x01,0x06,0x30,0x0F,0x06,0x03,0x55,0x1D,
0x13,0x01,0x01,0xFF,0x04,0x05,0x30,0x03,0x01,0x01,0xFF,0x30,0x1D,0x06,0x03,0x55,
0x1D,0x0E,0x04,0x16,0x04,0x14,0xB5,0xF3,0x4B,0xC6,0xE5,0xD6,0x4B,0xD0,0xE5,0x80,
0x6B,0x8C,0x50,0xC3,0x67,0x5B,0xBC,0xB1,0xF3,0x71,0x30,0x1F,0x06,0x03,0x55,0x1D,
0x23,0x04,0x18,0x30,0x16,0x80,0x14,0xB5,0xF3,0x4B,0xC6,0xE5,0xD6,0x4B,0xD0,0xE5,
0x80,0x6B,0x8C,0x50,0xC3,0x67,0x5B,0xBC,0xB1,0xF3,0x71,0x30,0x0D,0x06,0x09,0x2A,
0x86,0x48,0x86,0xF7,0x0D,0x01,0x01,0x0B,0x05,0x00,0x03,0x82,0x02,0x01,0x00,0x15,
0x1E,0x8A,0xBC,0x92,0xD2,0xA8,0xF2,0x90,0x13,0x7B,0xE5,0xAA,0x07,0x3B,0xD6,0xD5,
0x3E,0xBA,0xD7,0xF8,0x34,0x89,0x20,0x1F,0x55,0xD9,0x8C,0xE4,0x15,0x5C,0xA1,0xFE,
0x2A,0x3A,0xE5,0x02,0x4C,0x1B,0xC9,0xDA,0x59,0x51,0x8E,0x4A,0x95,0x51,0xC1,0x4C,
0x21,0x65,0x52,0xA1,0xDC,0x95,0x69,0xFE,0x68,0x8F,0x83,0x34,0xC6,0x02,0x8E,0xF3,
0x86,0xB0,0xC8,0xA1,0x77,0x3E,0x8A,0x1E,0xE8,0xAC,0x03,0x1B,0xD7,0xDA,0xA8,0x97,
0xFD,0x87,0x6B,0xC3,0x99,0x2D,0xAE,0xF9,0x2E,0x88,0xC9,0x35,0x16,0xD9,0xA0,0x24,
0x79,0x0B,0xE8,0x0C,0xF0,0x2F,0xAC,0xA4,0xC2,0xE3,0x15,0xFF,0x64,0xDC,0x95,0x71,
0x75,0xA8,0xE1,0xB5,0x15,0x1C,0x47,0x4C,0xD8,0x87,0x0B,0x01,0x4B,0xBA,0x99,0xE4,
0xC7,0xB4,0x77,0xA8,0x11,0x5C,0x3D,0x19,0x89,0x26,0xDA,0x74,0xC3,0x31,0x4B,0x0E,
0x8A,0x7C,0xA9,0x37,0x78,0xF9,0x8F,0x6F,0xD8,0x17,0xF8,0xC4,0x53,0x4B,0xAD,0xDC,
0xF2,0x62,0xF3,0x55,0x80,0x7F,0xDD,0xF7,0xBF,0x6E,0x4A,0x6A,0xE1,0x15,0x30,0xCD,
0x41,0xEF,0xA1,0x97,0xFE,0x49,0x40,0xFB,0x37,0x34,0x90,0x45,0x04,0x0C,0x7E,0xF0,
0x07,0x97,0x19,0x35,0xD5,0x35,0x4D,0xC5,0x27,0x18,0x3E,0xDC,0x57,0x0F,0x28,0xB2,
0xDC,0x2B,0x2C,0x97,0xD8,0x16,0xAE,0xB5,0xAA,0x43,0xFA,0x26,0xB8,0x78,0xA9,0xA0,
0x7E,0xB6,0x27,0xB8,0x7C,0x28,0x06,0x1B,0xAF,0xAA,0x04,0x22,0xAF,0x82,0xCE,0xE7,
0xA7,0x73,0x77,0x82,0x20,0x11,0x81,0x05,0xFB,0xC2,0xA6,0xE1,0x4E,0x81,0xC9,0x00,
0x5D,0x71,0x38,0x32,0x50,0x5A,0xB0,0x45,0x34,0x30,0xEE,0xBA,0x1A,0xB4,0xC2,0x80,
0xCB,0x7D,0x6C,0x09,0x92,0xC3,0x74,0xEB,0x44,0xFD,0x76,0xF9,0x95,0x05,0xC5,0x83,
0x6D,0xA9,0x69,0x6E,0x45,0x4F,0x09,0x59,0x0E,0x05,0x08,0x23,0xDC,0xCF,0xDA,0x60,
0x31,0x10,0x4E,0x82,0x7E,0x25,0x4F,0x10,0xD9,0x1B,0xE2,0x38,0xEC,0xE2,0x8D,0xB9,
0x24,0x63,0x14,0x43,0xFD,0xE1,0xC7,0x60,0xC5,0xDD,0xC7,0xFF,0x90,0x4A,0xED,0x61,
0xD4,0xCF,0x5B,0x40,0x19,0x0E,0x01,0x81,0xEA,0x52,0x5E,0x09,0xA3,0xCE,0x27,0xC5,
0x4F,0x91,0x55,0x4C,0x34,0xE5,0xDD,0x99,0xD6,0x51,0x50,0x57,0x88,0x76,0x2D,0x6C,
0xE0,0x60,0x2E,0x24,0x88,0x91,0xBA,0x86,0x30,0x22,0xED,0xAC,0x1B,0x45,0x21,0xE4,
0x3B,0x45,0x14,0xDB,0xDC,0xBF,0x88,0x13,0xD4,0x74,0x50,0x1D,0x1C,0x24,0x1D,0xC0,
0x5D,0xB7,0xF5,0x95,0x59,0x0E,0x72,0x6A,0xDD,0xBB,0x68,0x7C,0x03,0x7D,0x9A,0x0B,
0x0B,0x6B,0xE5,0x2D,0x5F,0x04,0x5D,0x6E,0x9E,0x51,0xBB,0x8A,0x63,0xE6,0xA8,0x97,
0xE9,0x38,0xC5,0x9A,0xF3,0x22,0x05,0xFC,0xA5,0x95,0x9B,0x6F,0x49,0x00,0xFA,0xBC,
0x2E,0xBB,0x32,0x6D,0xBD,0x33,0xE6,0x08,0x3C,0xC3,0xB6,0x5B,0x94,0x4B,0x81,0xF7,
0x33,0x96,0xF4,0xCD,0xE5,0xEB,0x40,0xD7,0xB8,0x93,0xBA,0x97,0xB8,0x3E,0x75,0xE5,
0x7A,0x3F,0xDE,0xAB,0xBF,0x6B,0xA7,0x1D,0x2F,0x14,0x96,0xF5,0xA2,0x55,0x60,0xF2,
0xF6,0xA7,0xE0,0x00,0x98,0xB3,0xCB,0x2D,0xE4,0xA8,0xCE,0x25,0x3B,0x00,0x47,
};


const unsigned char* const kSSLCertCertificateList[] = {
 Signal_Messenger__certificate,
};

const size_t kSSLCertCertificateSizeList[] = {
  1503,
};

// clang-format on

#endif  // RTC_BASE_SSL_ROOTS_H_
