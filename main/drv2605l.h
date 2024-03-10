#ifndef __DRV2605L_H__
#define __DRV2605L_H__
#include <stdint.h>
#include <stdbool.h>
#include <drv2605l_reg.h>

typedef enum
{
    DRV2605L_STATUS_OK = 0,
    DRV2605L_STATUS_ERROR,
    DRV2605L_STATUS_MAX,
} drv2605l_status_t;

typedef struct
{
    drv2605l_reg_actuator_t actuatorType;
    union
    {
        struct
        {
            drv2605l_reg_fbBrakeFactor_t brakeFactor;
            drv2605l_reg_loopGain_t loopGain;
            uint8_t ratedVolatge;
            uint8_t clampVoltage;
            drv2605l_reg_autoCalTime_t autoCalTime;
        } erm;

        struct
        {
            drv2605l_reg_fbBrakeFactor_t brakeFactor;
            drv2605l_reg_loopGain_t loopGain;
            uint8_t ratedVolatge;
            uint8_t clampVoltage;
            drv2605l_reg_autoCalTime_t autoCalTime;
            uint8_t driveTime;
            uint8_t sampleTime;
            drv2605l_reg_lraBlankingTime_t blankingTime;
            drv2605l_reg_lraIDisschageTime_t iDisschargeTime;
            drv2605l_reg_zeroCrossingTime_t zeroCrossingTime;
        } lra;

    } actuator;

} drv2605l_autoCalConfig_t;

uint8_t drv2605l_Rest(void);

uint8_t drv2605l_SetStandby(bool standby);

bool drv2605l_IsStandby(void);

uint8_t drv2605l_Go(void);

uint8_t drv2605l_Stop(void);

#endif //__DRV2605L_H__