#ifndef __DRV2605L_REG_H__
#define __DRV2605L_REG_H__
#include <stdint.h>

#define DRV2605L_REG_ADDR_STATUS (0x00)
#define DRV2605L_REG_ADDR_MODE (0x01)
#define DRV2605L_REG_ADDR_RTP_INPUT (0x02)
#define DRV2605L_REG_ADDR_LIBRARY_SEL (0x03)
#define DRV2605L_REG_ADDR_WAVEFORM_SEQ_START (0x04)
#define DRV2605L_REG_ADDR_WAVEFORM_SEQ_END (0x0B)
#define DRV2605L_REG_ADDR_GO (0x0C)
#define DRV2605L_REG_ADDR_OVERDRIVE_TIME_OFFSET (0x0D)
#define DRV2605L_REG_ADDR_SUSTAIN_TIME_OFFSET_POS (0x0E)
#define DRV2605L_REG_ADDR_SUSTAIN_TIME_OFFSET_NEG (0x0F)
#define DRV2605L_REG_ADDR_BRAKE_TIME_OFFSET (0x10)
#define DRV2605L_REG_ADDR_AUDIO_TO_VIBE_CTRL (0x11)
#define DRV2605L_REG_ADDR_AUDIO_TO_VIBE_MIN_INPUT_LEVEL (0x12)
#define DRV2605L_REG_ADDR_AUDIO_TO_VIBE_MAX_INPUT_LEVEL (0x13)
#define DRV2605L_REG_ADDR_AUDIO_TO_VIBE_MIN_INPUT_DRIVE (0x14)
#define DRV2605L_REG_ADDR_AUDIO_TO_VIBE_MAX_INPUT_DRIVE (0x15)
#define DRV2605L_REG_ADDR_RATED_VOLTAGE (0x16)
#define DRV2605L_REG_ADDR_OVERDRIVE_CLAMP_VOLTAGE (0x17)
#define DRV2605L_REG_ADDR_AUTOCAL_COMPENSTAION_RESULT (0x18)
#define DRV2605L_REG_ADDR_AUTOCAL_BACK_EMF_RESULT (0x19)
#define DRV2605L_REG_ADDR_FEEDBACK_CTRL (0x1A)
#define DRV2605L_REG_ADDR_CTRL1 (0x1B)
#define DRV2605L_REG_ADDR_CTRL2 (0x1C)
#define DRV2605L_REG_ADDR_CTRL3 (0x1D)
#define DRV2605L_REG_ADDR_CTRL4 (0x1E)
#define DRV2605L_REG_ADDR_CTRL5 (0x1F)
#define DRV2605L_REG_ADDR_LRA_OPENLOOP_PERIOD (0x20)
#define DRV2605L_REG_ADDR_VBAT_VOLTAGE_MONITOR (0x21)
#define DRV2605L_REG_ADDR_LRA_RESONANCE_PERIOD (0x22)

typedef enum
{
    DRV2605L_REG_DEVICE_DRV2604 = 2,
    DRV2605L_REG_DEVICE_DRV2605 = 3,
    DRV2605L_REG_DEVICE_DRV2604L = 6,
    DRV2605L_REG_DEVICE_DRV2605L = 7,
} drv2605l_reg_device_t;

typedef enum
{
    DRV2605L_REG_DEVICE_STATE_READY = 0,
    DRV2605L_REG_DEVICE_STATE_STANDBY = 1,
} drv2605l_reg_deviceState_t;

typedef enum
{
    DRV2605L_REG_DEVICE_MODE_INTERNAL_TRIGGER = 0,
    DRV2605L_REG_DEVICE_MODE_EXTERNAL_TRIGGER_EDGE = 1,
    DRV2605L_REG_DEVICE_MODE_EXTERNAL_TRIGGER_LEVEL = 2,
    DRV2605L_REG_DEVICE_MODE_PWM_AND_ANALOG_INPUT = 3,
    DRV2605L_REG_DEVICE_MODE_AUDIO_TO_VIBE = 4,
    DRV2605L_REG_DEVICE_MODE_REALTIME_PLAYBACK = 5,
    DRV2605L_REG_DEVICE_MODE_DIAGNOSTICS = 6,
    DRV2605L_REG_DEVICE_MODE_AUTO_CALIBRATION = 7,
} drv2605l_reg_deviceMode_t;

typedef enum
{
    DRV2605L_REG_LIBRARY_EMPTY = 0,
    DRV2605L_REG_LIBRARY_TS2200_A = 1,
    DRV2605L_REG_LIBRARY_TS2200_B = 2,
    DRV2605L_REG_LIBRARY_TS2200_C = 3,
    DRV2605L_REG_LIBRARY_TS2200_D = 4,
    DRV2605L_REG_LIBRARY_TS2200_E = 5,
    DRV2605L_REG_LIBRARY_LRA = 6,
    DRV2605L_REG_LIBRARY_TS2200_F = 7,
} drv2605l_reg_library_t;

typedef enum
{
    DRV2605L_REG_ATH_PEAK_TIME_10MS = 0,
    DRV2605L_REG_ATH_PEAK_TIME_20MS = 1,
    DRV2605L_REG_ATH_PEAK_TIME_30MS = 2,
    DRV2605L_REG_ATH_PEAK_TIME_40MS = 3,
} drv2605l_reg_athPeakTime_t;

typedef enum
{
    DRV2605L_REG_ATH_FILTER_100HZ = 0,
    DRV2605L_REG_ATH_FILTER_125HZ = 1,
    DRV2605L_REG_ATH_FILTER_150HZ = 2,
    DRV2605L_REG_ATH_FILTER_200HZ = 3,
} drv2605l_reg_athFilter_t;

typedef enum
{
    DRV2605L_REG_ACTULATOR_ERM = 0,
    DRV2605L_REG_ACTULATOR_LRA = 1,
} drv2605l_reg_actuator_t;

typedef enum
{
    DRV2605L_REG_FB_BRAKE_FACTOR_1X = 0,
    DRV2605L_REG_FB_BRAKE_FACTOR_2X = 1,
    DRV2605L_REG_FB_BRAKE_FACTOR_3X = 2,
    DRV2605L_REG_FB_BRAKE_FACTOR_4X = 3,
    DRV2605L_REG_FB_BRAKE_FACTOR_6X = 4,
    DRV2605L_REG_FB_BRAKE_FACTOR_8X = 5,
    DRV2605L_REG_FB_BRAKE_FACTOR_16X = 6,
    DRV2605L_REG_FB_BRAKE_FACTOR_DIABLE = 7,
} drv2605l_reg_fbBrakeFactor_t;

typedef enum
{
    DRV2605L_REG_LOOP_GAIN_LOW = 0,
    DRV2605L_REG_LOOP_GAIN_MEDIUM = 1,
    DRV2605L_REG_LOOP_GAIN_HIGH = 2,
    DRV2605L_REG_LOOP_GAIN_VERY_HIGH = 3,
} drv2605l_reg_loopGain_t;

typedef enum
{
    DRV2605L_REG_ERM_BEMF_GAIN_0_255X = 0,
    DRV2605L_REG_ERM_BEMF_GAIN_0_7875X = 1,
    DRV2605L_REG_ERM_BEMF_GAIN_1_365X = 2,
    DRV2605L_REG_ERM_BEMF_GAIN_3X = 3,
} drv2605l_reg_ermBemfGain_t;

typedef enum
{
    DRV2605L_REG_LRA_BEMF_GAIN_3_75X = 0,
    DRV2605L_REG_LRA_BEMF_GAIN_7_5X = 1,
    DRV2605L_REG_LRA_BEMF_GAIN_15X = 2,
    DRV2605L_REG_LRA_BEMF_GAIN_22_5X = 3,
} drv2605l_reg_lraBemfGain_t;

typedef enum
{
    DRV2605L_REG_BIDIR_INPUT_MODE_UNIDIRECTIONAL = 0,
    DRV2605L_REG_BIDIR_INPUT_MODE_BIDIRECTIONAL = 1,
} drv2605l_reg_bidirInputMode_t;

typedef enum
{
    DRV2605L_REG_LRA_SMPLING_TIME_150US = 0,
    DRV2605L_REG_LRA_SMPLING_TIME_200US = 1,
    DRV2605L_REG_LRA_SMPLING_TIME_250US = 2,
    DRV2605L_REG_LRA_SMPLING_TIME_300US = 3,
} drv2605l_reg_lraSamplingTime_t;

typedef enum
{
    DRV2605L_REG_ERM_BLANKING_TIME_45US = 0,
    DRV2605L_REG_ERM_BLANKING_TIME_75US = 1,
    DRV2605L_REG_ERM_BLANKING_TIME_150US = 2,
    DRV2605L_REG_ERM_BLANKING_TIME_225US = 3,
} drv2605l_reg_ermBlankingTime_t;

typedef enum
{
    DRV2605L_REG_LRA_BLANKING_TIME_15US = 0,
    DRV2605L_REG_LRA_BLANKING_TIME_25US = 1,
    DRV2605L_REG_LRA_BLANKING_TIME_50US = 2,
    DRV2605L_REG_LRA_BLANKING_TIME_75US = 3,
    DRV2605L_REG_LRA_BLANKING_TIME_90US = 4,
    DRV2605L_REG_LRA_BLANKING_TIME_105US = 5,
    DRV2605L_REG_LRA_BLANKING_TIME_120US = 6,
    DRV2605L_REG_LRA_BLANKING_TIME_135US = 7,
    DRV2605L_REG_LRA_BLANKING_TIME_150US = 8,
    DRV2605L_REG_LRA_BLANKING_TIME_165US = 9,
    DRV2605L_REG_LRA_BLANKING_TIME_180US = 10,
    DRV2605L_REG_LRA_BLANKING_TIME_195US = 11,
    DRV2605L_REG_LRA_BLANKING_TIME_210US = 12,
    DRV2605L_REG_LRA_BLANKING_TIME_235US = 13,
    DRV2605L_REG_LRA_BLANKING_TIME_260US = 14,
    DRV2605L_REG_LRA_BLANKING_TIME_285US = 15,
} drv2605l_reg_lraBlankingTime_t;

typedef enum
{
    DRV2605L_REG_ERM_I_DISCHARGE_TIME_45US = 0,
    DRV2605L_REG_ERM_I_DISCHARGE_TIME_75US = 1,
    DRV2605L_REG_ERM_I_DISCHARGE_TIME_150US = 2,
    DRV2605L_REG_ERM_I_DISCHARGE_TIME_225US = 3,
} drv2605l_reg_ermIDisschageTime_t;

typedef enum
{
    DRV2605L_REG_LRA_I_DISCHAGE_TIME_15US = 0,
    DRV2605L_REG_LRA_I_DISCHAGE_TIME_25US = 1,
    DRV2605L_REG_LRA_I_DISCHAGE_TIME_50US = 2,
    DRV2605L_REG_LRA_I_DISCHAGE_TIME_75US = 3,
    DRV2605L_REG_LRA_I_DISCHAGE_TIME_90US = 4,
    DRV2605L_REG_LRA_I_DISCHAGE_TIME_105US = 5,
    DRV2605L_REG_LRA_I_DISCHAGE_TIME_120US = 6,
    DRV2605L_REG_LRA_I_DISCHAGE_TIME_135US = 7,
    DRV2605L_REG_LRA_I_DISCHAGE_TIME_150US = 8,
    DRV2605L_REG_LRA_I_DISCHAGE_TIME_165US = 9,
    DRV2605L_REG_LRA_I_DISCHAGE_TIME_180US = 10,
    DRV2605L_REG_LRA_I_DISCHAGE_TIME_195US = 11,
    DRV2605L_REG_LRA_I_DISCHAGE_TIME_210US = 12,
    DRV2605L_REG_LRA_I_DISCHAGE_TIME_235US = 13,
    DRV2605L_REG_LRA_I_DISCHAGE_TIME_260US = 14,
    DRV2605L_REG_LRA_I_DISCHAGE_TIME_285US = 15,
} drv2605l_reg_lraIDisschageTime_t;

typedef enum
{
    DRV2605L_REG_NOISE_GATE_THRESHOLD_DISBALED = 0,
    DRV2605L_REG_NOISE_GATE_THRESHOLD_2 = 1,
    DRV2605L_REG_NOISE_GATE_THRESHOLD_4 = 2,
    DRV2605L_REG_NOISE_GATE_THRESHOLD_8 = 3,
} drv2605l_reg_noiseGateThreshold_t;

typedef enum
{
    DRV2605L_REG_ERM_OPERAION_CLOSED_LOOP = 0,
    DRV2605L_REG_ERM_OPERAION_OPEN_LOOP = 1,
} drv2605l_reg_ermOperation_t;

typedef enum
{
    DRV2605L_REG_SUPPLY_COMPENSATION_ENABLED = 0,
    DRV2605L_REG_SUPPLY_COMPENSATION_DISABLED = 1,
} drv2605l_reg_supplyCompensation_t;

typedef enum
{
    DRV2605L_REG_DATA_FORMAT_RTP_SIGNED = 0,
    DRV2605L_REG_DATA_FORMAT_RTP_UNSIGNED = 1,
} drv2605l_reg_dataFormatRtp_t;

typedef enum
{
    DRV2605L_REG_LRA_DRIVE_MODE_ONCE_PER_CYCLE = 0,
    DRV2605L_REG_LRA_DRIVE_MODE_TWICE_PER_CYCLE = 1,
} drv2605l_reg_lraDriveMode_t;

typedef enum
{
    DRV2605L_REG_EXTERNAL_INPUT_TYPE_PWM = 0,
    DRV2605L_REG_EXTERNAL_INPUT_TYPE_ANALOG = 1,
} drv2605l_reg_externalInputType_t;

typedef enum
{
    DRV2605L_REG_LRA_OPERAION_AUTO_RESONANCE = 0,
    DRV2605L_REG_LRA_OPERAION_OPEN_LOOP = 1,
} drv2605l_reg_lraOperation_t;

typedef enum
{
    DRV2605L_REG_ZERO_CROSSING_TIME_100US = 0,
    DRV2605L_REG_ZERO_CROSSING_TIME_200US = 1,
    DRV2605L_REG_ZERO_CROSSING_TIME_300US = 2,
    DRV2605L_REG_ZERO_CROSSING_TIME_390US = 3,
} drv2605l_reg_zeroCrossingTime_t;

typedef enum
{
    DRV2605L_REG_AUTO_CAL_TIME_150_TO_250 = 0,
    DRV2605L_REG_AUTO_CAL_TIME_250_TO_550 = 1,
    DRV2605L_REG_AUTO_CAL_TIME_500_TO_700 = 2,
    DRV2605L_REG_AUTO_CAL_TIME_1000_TO_1200 = 3,
} drv2605l_reg_autoCalTime_t;

typedef enum
{
    DRV2605L_REG_OTP_STATUS_NOT_PROGRAMED = 0,
    DRV2605L_REG_OTP_STATUS_PROGRAMED = 1,
} drv2605l_reg_otpStatus_t;

typedef enum
{
    DRV2605L_REG_SYNC_ATTEMPTS_3 = 0,
    DRV2605L_REG_SYNC_ATTEMPTS_4 = 1,
    DRV2605L_REG_SYNC_ATTEMPTS_5 = 2,
    DRV2605L_REG_SYNC_ATTEMPTS_6 = 3,
} drv2605l_reg_syncAttempts_t;

typedef enum
{
    DRV2605L_REG_LRA_AUTO_TRANSITION_DISABLE = 0,
    DRV2605L_REG_LRA_AUTO_TRANSITION_OPEN_LOOP = 1,
} drv2605l_reg_lraAutoTransition_t;

typedef enum
{
    DRV2605L_REG_PLAYBACK_INTV_5MS = 0,
    DRV2605L_REG_PLAYBACK_INTV_1MS = 1,
} drv2605l_reg_playbackIntv_t;

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