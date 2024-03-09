#include "drv2605l_port.h"
#include <string.h>
#include <esp_err.h>
#include <esp_log.h>

#define DRV2605L_RX_BUFFER_SIZE (127)
#define DRV2605L_TX_BUFFER_SIZE (127)
#define DRV2605L_MAX_TIMEOUT_MS (100)

#define DRV2605L_DEFAULT_I2C_CONFIG()                         \
    {                                                         \
        .mode = I2C_MODE_MASTER,                              \
        .sda_io_num = DRV2605L_PORT_I2C_SDA_GPIO,             \
        .scl_io_num = DRV2605L_PORT_I2C_SCL_GPIO,             \
        .sda_pullup_en = DRV2605L_PORT_I2C_SDA_PULLUP,        \
        .scl_pullup_en = DRV2605L_PORT_I2C_SCL_PULLUP,        \
        .master.clk_speed = DRV2605L_PORT_I2C_CLOCK_FREQUENCY \
    }

static const char *TAG = __FILE__;

static struct
{
    uint8_t cmdLinkBuff[I2C_LINK_RECOMMENDED_SIZE(5)];
} gInst = {0};

uint8_t drv2605l_port_Init(void)
{
    i2c_config_t config = DRV2605L_DEFAULT_I2C_CONFIG();

    esp_err_t err = i2c_param_config(DRV2605L_PORT_I2C_PORT, &config);
    if (err != ESP_OK)
    {
        ESP_LOGE(TAG, "%s : %d :Param config failed, %s", TAG, __LINE__, esp_err_to_name(err));
        return DRV2605L_PORT_STATUS_ERROR;
    }

    err = i2c_driver_install(DRV2605L_PORT_I2C_PORT,
                             I2C_MODE_MASTER,
                             DRV2605L_RX_BUFFER_SIZE,
                             DRV2605L_TX_BUFFER_SIZE,
                             0);
    if (err != ESP_OK)
    {
        ESP_LOGE(TAG, "%s : %d :Driver installation failed, %s", TAG, __LINE__, esp_err_to_name(err));
        return DRV2605L_PORT_STATUS_ERROR;
    }

    return DRV2605L_PORT_STATUS_OK;
}

uint8_t drv2605l_port_WriteRegister(uint8_t addr, uint8_t const *const pVal)
{
    if (pVal == NULL)
        return DRV2605L_PORT_STATUS_ERROR;

    uint8_t writeBuff[] = {(DRV2605L_PORT_I2C_ADDRESS << 1) | I2C_MASTER_WRITE, addr, (*pVal)};
    i2c_cmd_handle_t cmd = i2c_cmd_link_create_static(gInst.cmdLinkBuff, sizeof(gInst.cmdLinkBuff));
    if (i2c_master_start(cmd) != ESP_OK)
        return DRV2605L_PORT_STATUS_ERROR;
    if (i2c_master_write(cmd, writeBuff, sizeof(writeBuff), true) != ESP_OK)
        return DRV2605L_PORT_STATUS_ERROR;
    if (i2c_master_stop(cmd) != ESP_OK)
        return DRV2605L_PORT_STATUS_ERROR;
    if (i2c_master_cmd_begin(DRV2605L_PORT_I2C_PORT, cmd, pdMS_TO_TICKS(DRV2605L_MAX_TIMEOUT_MS)) != ESP_OK)
        return DRV2605L_PORT_STATUS_ERROR;
    return DRV2605L_PORT_STATUS_OK;
}

uint8_t drv2605l_port_ReadRegister(uint8_t addr, uint8_t *const buff)
{
    if (buff == NULL)
        return DRV2605L_PORT_STATUS_ERROR;

    uint8_t writeBuff1[] = {(DRV2605L_PORT_I2C_ADDRESS << 1) | I2C_MASTER_WRITE, addr};
    uint8_t writeBuff2[] = {(DRV2605L_PORT_I2C_ADDRESS << 1) | I2C_MASTER_READ};
    i2c_cmd_handle_t cmd = i2c_cmd_link_create_static(gInst.cmdLinkBuff, sizeof(gInst.cmdLinkBuff));
    if (i2c_master_start(cmd) != ESP_OK)
        return DRV2605L_PORT_STATUS_ERROR;
    if (i2c_master_write(cmd, writeBuff1, sizeof(writeBuff1), true) != ESP_OK)
        return DRV2605L_PORT_STATUS_ERROR;
    if (i2c_master_start(cmd) != ESP_OK)
        return DRV2605L_PORT_STATUS_ERROR;
    if (i2c_master_write(cmd, writeBuff2, sizeof(writeBuff2), true) != ESP_OK)
        return DRV2605L_PORT_STATUS_ERROR;
    if (i2c_master_read_byte(cmd, buff, true) != ESP_OK)
        return DRV2605L_PORT_STATUS_ERROR;
    if (i2c_master_stop(cmd) != ESP_OK)
        return DRV2605L_PORT_STATUS_ERROR;
    if (i2c_master_cmd_begin(DRV2605L_PORT_I2C_PORT, cmd, pdMS_TO_TICKS(DRV2605L_MAX_TIMEOUT_MS)) != ESP_OK)
        return DRV2605L_PORT_STATUS_ERROR;
    return DRV2605L_PORT_STATUS_OK;
}

void drv2605l_port_DeInit(void)
{
    esp_err_t err = i2c_driver_delete(DRV2605L_PORT_I2C_PORT);
    if (err != ESP_OK)
    {
        ESP_LOGE(TAG, "%s : %d :Failed to delete driver, %s", TAG, __LINE__, esp_err_to_name(err));
    }
}
