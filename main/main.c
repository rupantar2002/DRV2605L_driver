#include <stdio.h>
#include <string.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <esp_err.h>
#include <esp_log.h>
#include <driver/gpio.h>
#include <driver/i2c.h>
#include <drv2605l_port.h>
#include <drv2605l.h>
#include <drv2605l_reg.h>

static const char *TAG = __FILE__;

void app_main(void)
{
    drv2605l_port_Init();
    drv2605l_Rest();
    vTaskDelay(pdMS_TO_TICKS(10));
    if (drv2605l_IsStandby())
    {
        drv2605l_SetStandby(false);
    }

    // drv2605l_reg_bitwise_t reg = {0};
    // reg.bit7 = 1;
    // reg.bit4 = 1;
    // reg.bit0 = 1;

    // if (drv2605l_port_WriteRegister(0x02, (uint8_t *)&reg) != DRV2605L_PORT_STATUS_OK)
    // {
    //     ESP_LOGE(TAG, "failed to write");
    // }
    // else
    // {
    //     ESP_LOGI(TAG, "write success val:[%d : %d :%d :%d :%d :%d :%d :%d ]",
    //              reg.bit7,
    //              reg.bit6,
    //              reg.bit5,
    //              reg.bit4,
    //              reg.bit3,
    //              reg.bit2,
    //              reg.bit1,
    //              reg.bit0);
    // }

    // (void)memset(&reg, 0, sizeof(reg));
    // if (drv2605l_port_ReadRegister(0x02, (uint8_t *)&reg) != DRV2605L_PORT_STATUS_OK)
    // {
    //     ESP_LOGE(TAG, "failed to read");
    // }
    // else
    // {
    //     // ESP_LOGI(TAG, "read success val: 0X%02X", val);
    //     ESP_LOGI(TAG, "read success val:[%d : %d :%d :%d :%d :%d :%d :%d ]",
    //              reg.bit7,
    //              reg.bit6,
    //              reg.bit5,
    //              reg.bit4,
    //              reg.bit3,
    //              reg.bit2,
    //              reg.bit1,
    //              reg.bit0);
    // }

    while (1)
    {
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}
