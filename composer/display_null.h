/*
 * Copyright (c) 2017-2021, The Linux Foundation. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above
 *       copyright notice, this list of conditions and the following
 *       disclaimer in the documentation and/or other materials provided
 *       with the distribution.
 *     * Neither the name of The Linux Foundation nor the names of its
 *       contributors may be used to endorse or promote products derived
 *       from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
 * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
 * IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef __DISPLAY_NULL_H__
#define __DISPLAY_NULL_H__

#include <core/display_interface.h>
#include <string>
#include <vector>

namespace sdm {

using std::string;
using std::vector;

#define MAKE_NO_OP(virtual_method_signature) \
      virtual DisplayError virtual_method_signature { return kErrorNone; }

class DisplayNull : public DisplayInterface {
 public:
  virtual ~DisplayNull() { }
  virtual DisplayError Init();
  virtual DisplayError GetMixerResolution(uint32_t *width, uint32_t *height);

  virtual DisplayError GetFrameBufferConfig(DisplayConfigVariableInfo *variable_info);
  virtual DisplayError GetConfig(uint32_t index, DisplayConfigVariableInfo *disp_attr);
  virtual DisplayError GetConfig(DisplayConfigFixedInfo *fixed_info);
  virtual DisplayError GetRealConfig(uint32_t index, DisplayConfigVariableInfo *disp_attr);
  virtual DisplayError GetRefreshRateRange(uint32_t *min_refresh_rate, uint32_t *max_refresh_rate);
  virtual DisplayError GetActiveConfig(uint32_t *config);
  virtual DisplayError GetNumVariableInfoConfigs(uint32_t *count);
  virtual DisplayError Prepare(LayerStack *layer_stack);
  virtual bool IsPrimaryDisplay() { return true; }
  virtual bool IsUnderscanSupported() { return true; }
  virtual void SetIdleTimeoutMs(uint32_t active_ms, uint32_t inactive_ms) { }
  virtual DisplayError GetDisplayIdentificationData(uint8_t *out_port, uint32_t *out_data_size,
                                                    uint8_t *out_data);
  virtual bool CheckResourceState() { return false; }
  virtual string Dump() { return ""; }
  virtual bool IsSupportSsppTonemap() { return false; }
  virtual bool CanSkipValidate() { return true; }
  virtual bool GameEnhanceSupported() { return false; }

  MAKE_NO_OP(Commit(LayerStack *))
  MAKE_NO_OP(GetDisplayState(DisplayState *))
  MAKE_NO_OP(SetDisplayState(DisplayState, bool, shared_ptr<Fence> *))
  MAKE_NO_OP(SetFrameBufferConfig(const DisplayConfigVariableInfo &))
  MAKE_NO_OP(Flush(LayerStack *))
  MAKE_NO_OP(GetVSyncState(bool *))
  MAKE_NO_OP(SetActiveConfig(uint32_t))
  MAKE_NO_OP(SetActiveConfig(DisplayConfigVariableInfo *))
  MAKE_NO_OP(SetMaxMixerStages(uint32_t))
  MAKE_NO_OP(ControlPartialUpdate(bool, uint32_t *))
  MAKE_NO_OP(DisablePartialUpdateOneFrame())
  MAKE_NO_OP(SetDisplayMode(uint32_t))
  MAKE_NO_OP(SetPanelBrightness(float))
  MAKE_NO_OP(CachePanelBrightness(int))
  MAKE_NO_OP(OnMinHdcpEncryptionLevelChange(uint32_t))
  MAKE_NO_OP(ColorSVCRequestRoute(const PPDisplayAPIPayload &, PPDisplayAPIPayload *,
                                  PPPendingParams *))
  MAKE_NO_OP(GetColorModeCount(uint32_t *))
  MAKE_NO_OP(GetColorModes(uint32_t *, vector<string> *))
  MAKE_NO_OP(GetColorModeAttr(const string &, AttrVal *))
  MAKE_NO_OP(SetColorMode(const string &))
  MAKE_NO_OP(SetColorModeById(int32_t))
  MAKE_NO_OP(GetColorModeName(int32_t, string *))
  MAKE_NO_OP(SetColorTransform(const uint32_t, const double *))
  MAKE_NO_OP(GetDefaultColorMode(string *))
  MAKE_NO_OP(ApplyDefaultDisplayMode())
  MAKE_NO_OP(SetCursorPosition(int, int))
  MAKE_NO_OP(SetRefreshRate(uint32_t, bool, bool))
  MAKE_NO_OP(GetPanelBrightness(float *))
  MAKE_NO_OP(GetPanelMaxBrightness(uint32_t *))
  MAKE_NO_OP(GetRefreshRate(uint32_t *))
  MAKE_NO_OP(SetVSyncState(bool))
  MAKE_NO_OP(SetMixerResolution(uint32_t, uint32_t))
  MAKE_NO_OP(SetDetailEnhancerData(const DisplayDetailEnhancerData &))
  MAKE_NO_OP(GetDisplayPort(DisplayPort *))
  MAKE_NO_OP(GetDisplayId(int32_t *))
  MAKE_NO_OP(GetDisplayType(DisplayType *))
  MAKE_NO_OP(SetCompositionState(LayerComposition, bool))
  MAKE_NO_OP(GetClientTargetSupport(uint32_t, uint32_t, LayerBufferFormat,
                                    const ColorMetaData &))
  MAKE_NO_OP(HandleSecureEvent(SecureEvent, bool *))
  MAKE_NO_OP(SetQSyncMode(QSyncMode))
  MAKE_NO_OP(ControlIdlePowerCollapse(bool, bool))
  MAKE_NO_OP(SetDisplayDppsAdROI(void *))
  MAKE_NO_OP(SetDynamicDSIClock(uint64_t bit_clk_rate))
  MAKE_NO_OP(GetDynamicDSIClock(uint64_t *bit_clk_rate))
  MAKE_NO_OP(GetSupportedDSIClock(vector<uint64_t> *bitclk_rates))
  MAKE_NO_OP(SetFrameTriggerMode(FrameTriggerMode))
  MAKE_NO_OP(SetPanelLuminanceAttributes(float min_lum, float max_lum))
  MAKE_NO_OP(SetBLScale(uint32_t))
  MAKE_NO_OP(GetQSyncMode(QSyncMode *))
  MAKE_NO_OP(colorSamplingOn());
  MAKE_NO_OP(colorSamplingOff());
  MAKE_NO_OP(SetDisplayElapseTime(uint64_t))
  MAKE_NO_OP(GetStcColorModes(snapdragoncolor::ColorModeList *))
  MAKE_NO_OP(SetStcColorMode(const snapdragoncolor::ColorMode &))
  MAKE_NO_OP(ClearLUTs())
  MAKE_NO_OP(IsSupportedOnDisplay(SupportedDisplayFeature feature, uint32_t *supported))
  MAKE_NO_OP(GetCwbBufferResolution(CwbTapPoint, uint32_t *, uint32_t *))
  MAKE_NO_OP(NotifyDisplayCalibrationMode(bool))

 protected:
  DisplayConfigVariableInfo default_variable_config_ = {};
  DisplayConfigFixedInfo default_fixed_config_ = {};
  // 1920x1080 60fps panel of name Null Display with PnPID QCM
  // Contains many 'don't-care' fields and valid checksum bytes
  const vector<uint8_t> edid_{
    0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x44, 0x6D, 0x01, 0x00, 0x01, 0x00, 0x00, 0x00,
    0x1B, 0x10, 0x01, 0x03, 0x80, 0x50, 0x2D, 0x78, 0x0A, 0x0D, 0xC9, 0xA0, 0x57, 0x47, 0x98, 0x27,
    0x12, 0x48, 0x4C, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x02, 0x3A, 0x80, 0x18, 0x71, 0x38, 0x2D, 0x40, 0x58, 0x2C,
    0x45, 0x00, 0x50, 0x1D, 0x74, 0x00, 0x00, 0x1E, 0x00, 0x00, 0x00, 0xFE, 0x00, 0x4E, 0x75, 0x6C,
    0x6C, 0x20, 0x44, 0x69, 0x73, 0x70, 0x6C, 0x61, 0x79, 0x0A, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xD1
  };
};

class DisplayNullExternal : public DisplayNull {
 public:
  virtual DisplayError Commit(LayerStack *layer_stack);
  virtual DisplayError GetDisplayState(DisplayState *state);
  virtual DisplayError SetDisplayState(DisplayState state, bool teardown,
                                       shared_ptr<Fence> *release_fence);
  virtual DisplayError SetFrameBufferConfig(const DisplayConfigVariableInfo &variable_info);
  virtual DisplayError GetFrameBufferConfig(DisplayConfigVariableInfo *variable_info);
  virtual DisplayError GetDisplayIdentificationData(uint8_t *out_port, uint32_t *out_data_size,
                                                    uint8_t *out_data);
  void SetActive(bool active) { active_ = active; }
  bool IsActive() { return active_; }

 private:
  bool active_ = false;
  DisplayState state_ = kStateOff;
  DisplayConfigVariableInfo fb_config_ = {};
};

}  // namespace sdm

#endif  // __DISPLAY_NULL_H__
