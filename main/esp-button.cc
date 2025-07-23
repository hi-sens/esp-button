#include <stdio.h>
#include "Button.h"
#include "freertos/FreeRTOS.h"

extern "C" void app_main(void)
{
    Button button(10, 0, false);
    button.OnPressDown([](){
        printf("Button pressed down\n");
    });
    while (true) {
        vTaskDelay(pdMS_TO_TICKS(1000));  // Keep the task alive
    }
}

