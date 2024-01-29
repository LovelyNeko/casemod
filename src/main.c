#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/uart.h"
#include "driver/gpio.h"
#include "sdkconfig.h"
#include "esp_log.h"
#include "driver/ledc.h"
#include "esp_err.h"
#include "ssd1306.h"

#define I2C_MASTER_SCL_IO 37        /*!< gpio number for I2C master clock */
#define I2C_MASTER_SDA_IO 21        /*!< gpio number for I2C master data  */
#define I2C_MASTER_NUM I2C_NUM_1    /*!< I2C port number for master dev */
#define I2C_MASTER_FREQ_HZ 100000   /*!< I2C master clock frequency */

static ssd1306_handle_t ssd1306_dev = NULL;

void setup();

void app_main(void)
{       
    setup();
    
    ssd1306_dev = ssd1306_create(I2C_MASTER_NUM, SSD1306_I2C_ADDRESS);
    ssd1306_refresh_gram(ssd1306_dev);
    ssd1306_clear_screen(ssd1306_dev, 0x00);

    printf("screen cleared \n");


    /*Use display by making -  "char a;" and assigning a size to it appropriate to the size of the message to be sent, 
    then using "sprintf(var, "i like cats")".
    
    note: gotta make sure that the char size encapsulates everything between the quotes,
    EVERYTHING spaces and any other char ( :) get it now? ) inbetween the quotes. 
    */

    char data_str[10] = {0};
    char data_str_2[13] = {0};

    sprintf(data_str, "dikke aap");
    ssd1306_draw_string(ssd1306_dev, 0, 0, (const uint8_t *)data_str, 16, 1);
    sprintf(data_str_2, "zoinks scoob");
    ssd1306_draw_string(ssd1306_dev, 0, 20, (const uint8_t *)data_str_2, 16, 1);
    ssd1306_refresh_gram(ssd1306_dev);

    printf("Displaying complete! \n");

    

}

void setup(){

    /*Setting up the I2C for the oled screen, using the library*/

    i2c_config_t conf;
    conf.mode = I2C_MODE_MASTER;
    conf.sda_io_num = (gpio_num_t)I2C_MASTER_SDA_IO;
    conf.sda_pullup_en = GPIO_PULLUP_ENABLE;
    conf.scl_io_num = (gpio_num_t)I2C_MASTER_SCL_IO;
    conf.scl_pullup_en = GPIO_PULLUP_ENABLE;
    conf.master.clk_speed = I2C_MASTER_FREQ_HZ;
    conf.clk_flags = I2C_SCLK_SRC_FLAG_FOR_NOMAL;

    printf("setup success \n");

    /*Configuring parameters*/

    i2c_param_config(I2C_MASTER_NUM, &conf);
    i2c_driver_install(I2C_MASTER_NUM, conf.mode, 0, 0, 0);

    printf("config success \n");

}