#ifndef __DRV2605L_PORT_H__
#define __DRV2605L_PORT_H__
#include <stdint.h>
#include <driver/gpio.h>
#include <driver/i2c.h>

#define DRV2605L_PORT_I2C_ADDRESS (0x5A)
#define DRV2605L_PORT_I2C_PORT (I2C_NUM_0)
#define DRV2605L_PORT_I2C_SCL_GPIO (GPIO_NUM_22)
#define DRV2605L_PORT_I2C_SDA_GPIO (GPIO_NUM_21)
#define DRV2605L_PORT_I2C_CLOCK_FREQUENCY (100 * 1000)
#define DRV2605L_PORT_I2C_SCL_PULLUP (GPIO_PULLUP_ENABLE)
#define DRV2605L_PORT_I2C_SDA_PULLUP (GPIO_PULLUP_ENABLE)

typedef enum
{
    DRV2605L_PORT_STATUS_OK = 0,
    DRV2605L_PORT_STATUS_ERROR,
    DRV2605L_PORT_STATUS_MAX,
} drv2605l_port_status_t;

uint8_t drv2605l_port_Init(void);

uint8_t drv2605l_port_WriteRegister(uint8_t addr, uint8_t const *const pVal);

uint8_t drv2605l_port_ReadRegister(uint8_t addr, uint8_t *const buff);

void drv2605l_port_DeInit(void);

#endif //__DRV2605L_PORT_H__
