/*
 *  Copyright (c) 2018 The WebRTC project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */

#ifndef CALL_RTP_PAYLOAD_PARAMS_H_
#define CALL_RTP_PAYLOAD_PARAMS_H_

#include <array>
#include <vector>

#include "absl/types/optional.h"
#include "api/transport/webrtc_key_value_config.h"
#include "api/video_codecs/video_encoder.h"
#include "call/rtp_config.h"
#include "modules/rtp_rtcp/source/rtp_generic_frame_descriptor.h"
#include "modules/rtp_rtcp/source/rtp_video_header.h"
#include "modules/video_coding/chain_diff_calculator.h"
#include "modules/video_coding/frame_dependencies_calculator.h"
#include "modules/video_coding/include/video_codec_interface.h"

namespace webrtc {

class RtpRtcp;

// State for setting picture id and tl0 pic idx, for VP8 and VP9
// TODO(nisse): Make these properties not codec specific.
class RtpPayloadParams final {
 public:
  RtpPayloadParams(const uint32_t ssrc,
                   const RtpPayloadState* state,
                   const WebRtcKeyValueConfig& trials);
  RtpPayloadParams(const RtpPayloadParams& other);
  ~RtpPayloadParams();

  RTPVideoHeader GetRtpVideoHeader(const EncodedImage& image,
                                   const CodecSpecificInfo* codec_specific_info,
                                   int64_t shared_frame_id);

  // Returns structure that aligns with simulated generic info. The templates
  // allow to produce valid dependency descriptor for any stream where
  // `num_spatial_layers` * `num_temporal_layers` <= 32 (limited by
  // https://aomediacodec.github.io/av1-rtp-spec/#a82-syntax, see
  // template_fdiffs()). The set of the templates is not tuned for any paricular
  // structure thus dependency descriptor would use more bytes on the wire than
  // with tuned templates.
  static FrameDependencyStructure MinimalisticStructure(
      int num_spatial_layers,
      int num_temporal_layers);

  uint32_t ssrc() const;

  RtpPayloadState state() const;

 private:
  void SetCodecSpecific(RTPVideoHeader* rtp_video_header,
                        bool first_frame_in_picture,
                        int64_t shared_frame_id);
  RTPVideoHeader::GenericDescriptorInfo GenericDescriptorFromFrameInfo(
      const GenericFrameInfo& frame_info,
      int64_t frame_id);
  void SetGeneric(const CodecSpecificInfo* codec_specific_info,
                  int64_t frame_id,
                  bool is_keyframe,
                  RTPVideoHeader* rtp_video_header);

  void Vp8ToGeneric(const CodecSpecificInfoVP8& vp8_info,
                    int64_t shared_frame_id,
                    bool is_keyframe,
                    RTPVideoHeader* rtp_video_header);

  void Vp9ToGeneric(const CodecSpecificInfoVP9& vp9_info,
                    int64_t shared_frame_id,
                    RTPVideoHeader& rtp_video_header);

  void H264ToGeneric(const CodecSpecificInfoH264& h264_info,
                     int64_t shared_frame_id,
                     bool is_keyframe,
                     RTPVideoHeader* rtp_video_header);

  void GenericToGeneric(int64_t shared_frame_id,
                        bool is_keyframe,
                        RTPVideoHeader* rtp_video_header);

  // TODO(bugs.webrtc.org/10242): Delete SetDependenciesVp8Deprecated() and move
  // the logic in SetDependenciesVp8New() into Vp8ToGeneric() once all hardware
  // wrappers have been updated.
  void SetDependenciesVp8Deprecated(
      const CodecSpecificInfoVP8& vp8_info,
      int64_t shared_frame_id,
      bool is_keyframe,
      int spatial_index,
      int temporal_index,
      bool layer_sync,
      RTPVideoHeader::GenericDescriptorInfo* generic);
  void SetDependenciesVp8New(const CodecSpecificInfoVP8& vp8_info,
                             int64_t shared_frame_id,
                             bool is_keyframe,
                             bool layer_sync,
                             RTPVideoHeader::GenericDescriptorInfo* generic);

  FrameDependenciesCalculator dependencies_calculator_;
  ChainDiffCalculator chains_calculator_;
  // TODO(bugs.webrtc.org/10242): Remove once all encoder-wrappers are updated.
  // Holds the last shared frame id for a given (spatial, temporal) layer.
  std::array<std::array<int64_t, RtpGenericFrameDescriptor::kMaxTemporalLayers>,
             RtpGenericFrameDescriptor::kMaxSpatialLayers>
      last_shared_frame_id_;
  // circular buffer of frame ids for the last 128 vp9 pictures.
  // ids for the `picture_id` are stored at the index `picture_id % 128`.
  std::vector<std::array<int64_t, RtpGenericFrameDescriptor::kMaxSpatialLayers>>
      last_vp9_frame_id_;
  // Last frame id for each chain
  std::array<int64_t, RtpGenericFrameDescriptor::kMaxSpatialLayers>
      chain_last_frame_id_;

  // TODO(eladalon): When additional codecs are supported,
  // set kMaxCodecBuffersCount to the max() of these codecs' buffer count.
  static constexpr size_t kMaxCodecBuffersCount =
      CodecSpecificInfoVP8::kBuffersCount;

  // Maps buffer IDs to the frame-ID stored in them.
  std::array<int64_t, kMaxCodecBuffersCount> buffer_id_to_frame_id_;

  // Until we remove SetDependenciesVp8Deprecated(), we should make sure
  // that, for a given object, we either always use
  // SetDependenciesVp8Deprecated(), or always use SetDependenciesVp8New().
  // TODO(bugs.webrtc.org/10242): Remove.
  absl::optional<bool> new_version_used_;

  const uint32_t ssrc_;
  RtpPayloadState state_;

  const bool generic_picture_id_experiment_;
  const bool simulate_generic_vp9_;
};
}  // namespace webrtc
#endif  // CALL_RTP_PAYLOAD_PARAMS_H_
