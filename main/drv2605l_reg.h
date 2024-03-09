#ifndef __DRV2605L_REG_H__
#define __DRV2605L_REG_H__
#include <stdint.h>

#define DRV2605L_REG_STATUS (0x00)
#define DRV2605L_REG_MODE (0x01)
#define DRV2605L_REG_RTP_INPUT (0x02)
#define DRV2605L_REG_LIBRARY_SEL (0x03)
#define DRV2605L_REG_WAVEFORM_SEQ_START (0x04)
#define DRV2605L_REG_WAVEFORM_SEQ_END (0x0B)
#define DRV2605L_REG_GO (0x0C)
#define DRV2605L_REG_OVERDRIVE_TIME_OFFSET (0x0D)
#define DRV2605L_REG_SUSTAIN_TIME_OFFSET_POS (0x0E)
#define DRV2605L_REG_SUSTAIN_TIME_OFFSET_NEG (0x0F)
#define DRV2605L_REG_BRAKE_TIME_OFFSET (0x10)
#define DRV2605L_REG_AUDIO_TO_VIBE_CTRL (0x11)
#define DRV2605L_REG_AUDIO_TO_VIBE_MIN_INPUT_LEVEL (0x12)
#define DRV2605L_REG_AUDIO_TO_VIBE_MAX_INPUT_LEVEL (0x13)
#define DRV2605L_REG_AUDIO_TO_VIBE_MIN_INPUT_DRIVE (0x14)
#define DRV2605L_REG_AUDIO_TO_VIBE_MAX_INPUT_DRIVE (0x15)
#define DRV2605L_REG_RATED_VOLTAGE (0x16)
#define DRV2605L_REG_OVERDRIVE_CLAMP_VOLTAGE (0x17)
#define DRV2605L_REG_AUTOCAL_COMPENSTAION_RESULT (0x18)
#define DRV2605L_REG_AUTOCAL_BACK_EMF_RESULT (0x19)
#define DRV2605L_REG_FEEDBACK_CTRL (0x1A)
#define DRV2605L_REG_CTRL1 (0x1B)
#define DRV2605L_REG_CTRL2 (0x1C)
#define DRV2605L_REG_CTRL3 (0x1D)
#define DRV2605L_REG_CTRL4 (0x1E)
#define DRV2605L_REG_CTRL5 (0x1F)
#define DRV2605L_REG_LRA_OPENLOOP_PERIOD (0x20)
#define DRV2605L_REG_VBAT_VOLTAGE_MONITOR (0x21)
#define DRV2605L_REG_LRA_RESONANCE_PERIOD (0x22)

#define DRV2605L_REG_BIT_ORDER_MSBFIRST (1)

#define DRV2605L_REG_BIT_ORDER_LSBFIRST (0)

#define DRV2605L_REG_BIT_ORDER DRV2605L_REG_BIT_ORDER_LSBFIRST

#if (DRV2605L_REG_BIT_ORDER != DRV2605L_REG_BIT_ORDER_MSBFIRST) && \
    (DRV2605L_REG_BIT_ORDER != DRV2605L_REG_BIT_ORDER_LSBFIRST)
#error "Driver bit order undefine select proper\
         a bit order exp. DRV2605L_REG_BIT_ORDER_MSBFIRST or DRV2605L_REG_BIT_ORDER_LSBFIRST."
#endif

typedef struct
{
#if (DRV2605L_REG_BIT_ORDER == DRV2605L_REG_BIT_ORDER_MSBFIRST)
    uint8_t bit7 : 1;
    uint8_t bit6 : 1;
    uint8_t bit5 : 1;
    uint8_t bit4 : 1;
    uint8_t bit3 : 1;
    uint8_t bit2 : 1;
    uint8_t bit1 : 1;
    uint8_t bit0 : 1;
#else
    uint8_t bit0 : 1;
    uint8_t bit1 : 1;
    uint8_t bit2 : 1;
    uint8_t bit3 : 1;
    uint8_t bit4 : 1;
    uint8_t bit5 : 1;
    uint8_t bit6 : 1;
    uint8_t bit7 : 1;
#endif
} drv2605l_reg_bitwise_t;

typedef struct
{
#if (DRV2605L_REG_BIT_ORDER == DRV2605L_REG_BIT_ORDER_MSBFIRST)
    uint8_t device_id : 3;
    uint8_t reserved0 : 1;
    uint8_t diag_result : 1;
    uint8_t reserved1 : 1;
    uint8_t over_temp : 1;
    uint8_t oc_detect : 1;
#else
    uint8_t oc_detect : 1;
    uint8_t over_temp : 1;
    uint8_t reserved1 : 1;
    uint8_t diag_result : 1;
    uint8_t reserved0 : 1;
    uint8_t device_id : 3;
#endif
} drv2605l_reg_status_t;

typedef struct
{
#if (DRV2605L_REG_BIT_ORDER == DRV2605L_REG_BIT_ORDER_MSBFIRST)
    uint8_t dev_reset : 1;
    uint8_t standby : 1;
    uint8_t reserved0 : 3;
    uint8_t mode : 3;
#else
    uint8_t mode : 3;
    uint8_t reserved0 : 3;
    uint8_t standby : 1;
    uint8_t dev_reset : 1;
#endif
} drv2605l_reg_mode_t;

typedef struct
{
#if (DRV2605L_REG_BIT_ORDER == DRV2605L_REG_BIT_ORDER_MSBFIRST)
    uint8_t reserved0 : 3;
    uint8_t hi_z : 1;
    uint8_t reserved1 : 1;
    uint8_t library_sel : 3;
#else
    uint8_t library_sel : 3;
    uint8_t reserved1 : 1;
    uint8_t hi_z : 1;
    uint8_t reserved0 : 3;
#endif
} drv2605l_reg_librarySel_t;

typedef struct
{
#if (DRV2605L_REG_BIT_ORDER == DRV2605L_REG_BIT_ORDER_MSBFIRST)
    uint8_t wait : 1;
    uint8_t wav_frm_seq : 7;
#else
    uint8_t wav_frm_seq : 7;
    uint8_t wait : 1;
#endif
} drv2605l_reg_waveformSeq_t;

typedef struct
{
#if (DRV2605L_REG_BIT_ORDER == DRV2605L_REG_BIT_ORDER_MSBFIRST)
    uint8_t reserved0 : 7;
    uint8_t go : 1;
#else
    uint8_t go : 1;
    uint8_t reserved0 : 7;
#endif
} drv2605l_reg_go_t;

typedef struct
{
#if (DRV2605L_REG_BIT_ORDER == DRV2605L_REG_BIT_ORDER_MSBFIRST)
    uint8_t reserved0 : 4;
    uint8_t ath_peak_time : 2;
    uint8_t ath_filter : 2;
#else
    uint8_t ath_filter : 2;
    uint8_t ath_peak_time : 2;
    uint8_t reserved0 : 4;
#endif
} drv2605l_reg_audioToVibeCtrl_t;

typedef struct
{
#if (DRV2605L_REG_BIT_ORDER == DRV2605L_REG_BIT_ORDER_MSBFIRST)
    uint8_t n_erm_lra : 1;
    uint8_t fb_brake_factor : 3;
    uint8_t loop_gain : 2;
    uint8_t bemf_gain : 2;
#else
    uint8_t bemf_gain : 2;
    uint8_t loop_gain : 2;
    uint8_t fb_brake_factor : 3;
    uint8_t n_erm_lra : 1;
#endif
} drv2605l_reg_feedbackCtrl_t;

typedef struct
{
#if (DRV2605L_REG_BIT_ORDER == DRV2605L_REG_BIT_ORDER_MSBFIRST)
    uint8_t startup_boost : 1;
    uint8_t reserved0 : 1;
    uint8_t ac_couple : 1;
    uint8_t drive_time : 5;
#else
    uint8_t drive_time : 5;
    uint8_t ac_couple : 1;
    uint8_t reserved0 : 1;
    uint8_t startup_boost : 1;
#endif
} drv2605l_reg_ctrl1_t;

typedef struct
{
#if (DRV2605L_REG_BIT_ORDER == DRV2605L_REG_BIT_ORDER_MSBFIRST)
    uint8_t bidir_input : 1;
    uint8_t brake_stabilizer : 1;
    uint8_t sample_time : 2;
    uint8_t blanking_time : 2;
    uint8_t idiss_time : 2;
#else
    uint8_t idiss_time : 2;
    uint8_t blanking_time : 2;
    uint8_t sample_time : 2;
    uint8_t brake_stabilizer : 1;
    uint8_t bidir_input : 1;
#endif
} drv2605l_reg_ctrl2_t;

typedef struct
{
#if (DRV2605L_REG_BIT_ORDER == DRV2605L_REG_BIT_ORDER_MSBFIRST)
    uint8_t ng_thresh : 2;
    uint8_t erm_open_loop : 1;
    uint8_t supply_comp_dis : 1;
    uint8_t data_format_rtp : 1;
    uint8_t lra_driver_mode : 1;
    uint8_t n_pwm_analog : 1;
    uint8_t lra_open_loop : 1;
#else
    uint8_t lra_open_loop : 1;
    uint8_t n_pwm_analog : 1;
    uint8_t lra_driver_mode : 1;
    uint8_t data_format_rtp : 1;
    uint8_t supply_comp_dis : 1;
    uint8_t erm_open_loop : 1;
    uint8_t ng_thresh : 2;
#endif
} drv2605l_reg_ctrl3_t;

typedef struct
{
#if (DRV2605L_REG_BIT_ORDER == DRV2605L_REG_BIT_ORDER_MSBFIRST)
    uint8_t zc_det_time : 2;
    uint8_t auto_cal_time : 2;
    uint8_t reserved0 : 1;
    uint8_t otp_status : 1;
    uint8_t reserved1 : 1;
    uint8_t otp_program : 1;
#else
    uint8_t otp_program : 1;
    uint8_t reserved1 : 1;
    uint8_t otp_status : 1;
    uint8_t reserved0 : 1;
    uint8_t auto_cal_time : 2;
    uint8_t zc_det_time : 2;
#endif
} drv2605l_reg_ctrl4_t;

typedef struct
{
#if (DRV2605L_REG_BIT_ORDER == DRV2605L_REG_BIT_ORDER_MSBFIRST)
    uint8_t auto_ol_cnt : 2;
    uint8_t lra_auto_open_loop : 1;
    uint8_t playback_interval : 1;
    uint8_t blanking_time : 2;
    uint8_t idiss_time : 2;
#else
    uint8_t idiss_time : 2;
    uint8_t blanking_time : 2;
    uint8_t playback_interval : 1;
    uint8_t lra_auto_open_loop : 1;
    uint8_t auto_ol_cnt : 2;
#endif
} drv2605l_reg_ctrl5_t;

typedef struct
{
#if (DRV2605L_REG_BIT_ORDER == DRV2605L_REG_BIT_ORDER_MSBFIRST)
    uint8_t reserved : 1;
    uint8_t ol_lra_period : 7;
#else
    uint8_t ol_lra_period : 7;
    uint8_t reserved : 1;
#endif
} drv2605l_reg_lraOpenLoopPeriod_t;

#endif //__DRV2605L_REG_H__