#include "drv2605l.h"
#include "drv2605l_port.h"

uint8_t drv2605l_Rest(void)
{
    drv2605l_reg_mode_t modeReg = {0};
    modeReg.dev_reset = 1;
    if (drv2605l_port_WriteRegister(DRV2605L_REG_ADDR_MODE,
                                    (uint8_t *)&modeReg) != DRV2605L_PORT_STATUS_OK)
        return DRV2605L_STATUS_ERROR;
    else
        return DRV2605L_STATUS_OK;
}

uint8_t drv2605l_SetStandby(bool standby)
{
    drv2605l_reg_mode_t modeReg = {0};

    if (drv2605l_port_ReadRegister(DRV2605L_REG_ADDR_MODE,
                                   (uint8_t *)&modeReg) != DRV2605L_PORT_STATUS_OK)
        return DRV2605L_STATUS_ERROR;
    else
        return DRV2605L_STATUS_OK;

    modeReg.standby = standby ? DRV2605L_REG_DEVICE_STATE_STANDBY : DRV2605L_REG_DEVICE_STATE_READY;
    if (drv2605l_port_WriteRegister(DRV2605L_REG_ADDR_MODE,
                                    (uint8_t *)&modeReg) != DRV2605L_PORT_STATUS_OK)
        return DRV2605L_STATUS_ERROR;
    else
        return DRV2605L_STATUS_OK;
}

uint8_t drv2605l_Go(void)
{
    drv2605l_reg_go_t goReg = {0};
    goReg.go = 1;
    if (drv2605l_port_WriteRegister(DRV2605L_REG_ADDR_GO,
                                    (uint8_t *)&goReg) != DRV2605L_PORT_STATUS_OK)
        return DRV2605L_STATUS_ERROR;
    else
        return DRV2605L_STATUS_OK;
}

uint8_t drv2605l_Stop(void)
{
    drv2605l_reg_go_t goReg = {0};
    goReg.go = 0;
    if (drv2605l_port_WriteRegister(DRV2605L_REG_ADDR_GO,
                                    (uint8_t *)&goReg) != DRV2605L_PORT_STATUS_OK)
        return DRV2605L_STATUS_ERROR;
    else
        return DRV2605L_STATUS_OK;
}

bool drv2605l_IsStandby(void)
{
    drv2605l_reg_mode_t modeReg = {0};
    if (drv2605l_port_ReadRegister(DRV2605L_REG_ADDR_MODE,
                                   (uint8_t *)&modeReg) != DRV2605L_PORT_STATUS_OK)
        return DRV2605L_STATUS_ERROR;
    else
        return DRV2605L_STATUS_OK;
    return modeReg.standby == DRV2605L_REG_DEVICE_STATE_STANDBY ? true : false;
}