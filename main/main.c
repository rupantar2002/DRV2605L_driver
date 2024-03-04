#include <stdio.h>
#include <string.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <esp_err.h>
#include <esp_log.h>
#include <driver/gpio.h>
#include <driver/i2c.h>

#define MASTER_PORT (0)
#define SCL_GPIO (GPIO_NUM_22)
#define SDA_GPIO (GPIO_NUM_21)
#define CLOCK_FREQ (100 * 1000) // 100Khz
#define DEVICE_ADDR (0x5a)

static const char *TAG = __FILE__;
static uint8_t gCmdLinkBuff[I2C_LINK_RECOMMENDED_SIZE(5)] = {0};

static void I2cInit(void)
{
    i2c_config_t config = {
        .mode = I2C_MODE_MASTER,
        .sda_io_num = SDA_GPIO,
        .scl_io_num = SCL_GPIO,
        .sda_pullup_en = GPIO_PULLUP_ENABLE,
        .scl_pullup_en = GPIO_PULLUP_ENABLE,
        .master.clk_speed = CLOCK_FREQ,
    };

    ESP_ERROR_CHECK(i2c_param_config(MASTER_PORT, &config));
    ESP_ERROR_CHECK(i2c_driver_install(MASTER_PORT, I2C_MODE_MASTER, 512, 512, 0));
}

static uint8_t ReadRegister(uint8_t reg, uint8_t *const buff)
{
    uint8_t writeBuff1[] = {(DEVICE_ADDR << 1) | I2C_MASTER_WRITE, reg};
    uint8_t writeBuff2[] = {(DEVICE_ADDR << 1) | I2C_MASTER_READ};
    i2c_cmd_handle_t cmd = i2c_cmd_link_create_static(gCmdLinkBuff, sizeof(gCmdLinkBuff));
    if (i2c_master_start(cmd) != ESP_OK)
        return 1;
    if (i2c_master_write(cmd, writeBuff1, sizeof(writeBuff1), true) != ESP_OK)
        return 1;
    if (i2c_master_start(cmd) != ESP_OK)
        return 1;
    if (i2c_master_write(cmd, writeBuff2, sizeof(writeBuff2), true) != ESP_OK)
        return 1;
    if (i2c_master_read_byte(cmd, buff, true) != ESP_OK)
        return 1;
    if (i2c_master_stop(cmd) != ESP_OK)
        return 1;
    if (i2c_master_cmd_begin(MASTER_PORT, cmd, pdMS_TO_TICKS(100)) != ESP_OK)
        return 1;
    return 0;
}

static uint8_t WriteRegister(uint8_t reg, uint8_t const *const val)
{
    uint8_t writeBuff[] = {(DEVICE_ADDR << 1) | I2C_MASTER_WRITE, reg, val};
    i2c_cmd_handle_t cmd = i2c_cmd_link_create_static(gCmdLinkBuff, sizeof(gCmdLinkBuff));
    if (i2c_master_start(cmd) != ESP_OK)
        return 1;
    if (i2c_master_write(cmd, writeBuff, sizeof(writeBuff), true) != ESP_OK)
        return 1;
    if (i2c_master_stop(cmd) != ESP_OK)
        return 1;
    if (i2c_master_cmd_begin(MASTER_PORT, cmd, pdMS_TO_TICKS(100)) != ESP_OK)
        return 1;
    return 0;
}

void app_main(void)
{
    I2cInit();

    // uint8_t cmdLinkBuff[I2C_LINK_RECOMMENDED_SIZE(4)] = {0};
    // uint8_t addr = 0x5a;
    // uint8_t regAddr = 0x02;
    // uint8_t writeBuff[2] = {0};
    // uint8_t readBuff[2] = {0};

    while (1)
    {
        if (WriteRegister(0x02, 0xab) != 0)
        {
            ESP_LOGE(TAG, "failed to write");
        }
        else
        {
            ESP_LOGI(TAG, "write success");
        }
        uint8_t val = 0;
        if (ReadRegister(0x02, &val) != 0)
        {
            ESP_LOGE(TAG, "failed to read");
        }
        else
        {
            ESP_LOGI(TAG, "read success val: 0X%02X", val);
        }

        // uint8_t readBuff[10] = {0};
        // uint8_t writeBuff[] = {(0x5a << 1) | I2C_MASTER_WRITE, 0x02, 0xab};
        // esp_err_t ret = ESP_OK;
        // i2c_cmd_handle_t cmd = i2c_cmd_link_create_static(cmdLinkBuff, sizeof(cmdLinkBuff));
        // i2c_master_start(cmd);
        // i2c_master_write(cmd, writeBuff, sizeof(writeBuff), true);
        // i2c_master_stop(cmd);
        // ret = i2c_master_cmd_begin(MASTER_PORT, cmd, portMAX_DELAY);

        // // esp_err_t ret = i2c_master_write_to_device(MASTER_PORT,
        // //                                              (0x5a << 1) | I2C_MASTER_WRITE,
        // //                                              writeBuff,
        // //                                              2,
        // //                                              portMAX_DELAY);
        // if (ret == ESP_OK)
        // {
        //     ESP_LOGI(TAG, "Reading 0x%02x", 0x02);
        //     ESP_LOG_BUFFER_HEX(TAG, readBuff, 1);
        // }
        // else
        // {
        //     ESP_LOGE(TAG, "transfer failed...");
        // }

        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}
