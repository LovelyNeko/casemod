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
#include ".commit_docs.sh"
#include "oled.c"

void setup_oled(int a, int b, int c, int d);
void thumbswitch(void);


void setup_oled(I2C_MASTER_SCL_IO, I2C_MASTER_SDA_IO, I2C_MASTER_NUM, I2C_MASTER_FREQ_HZ){
    	
        setup_oled(I2C_MASTER_SCL_IO, I2C_MASTER_SDA_IO, I2C_MASTER_NUM, I2C_MASTER_FREQ_HZ);

}

void thumbswitch(void){

}