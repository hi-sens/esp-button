#include "Button.h"
#include "esp_log.h"
#include <iostream>


Button::Button(uint32_t button_num, uint8_t active_level, bool enable_power_save){
    button_config_t btn_cfg = {
        .long_press_time = 2000,
        .short_press_time = 0,
    };
    button_gpio_config_t gpio_cfg = {
        .gpio_num = (int32_t)button_num,
        .active_level = active_level,
        .enable_power_save = enable_power_save,
        .disable_pull = false
    };
    esp_err_t ret = iot_button_new_gpio_device(&btn_cfg, &gpio_cfg, &btn_handle);
    std::cout<< "Button created with handle: " << btn_handle << std::endl;
}

void Button::OnPressDown(std::function<void()> callback){
    if (btn_handle == nullptr) {
        return;
    }
    on_press_down_ = callback;
    if (btn_handle != nullptr) {
        printf("Registering button callback\n");
        iot_button_register_cb(btn_handle, BUTTON_PRESS_DOWN, NULL, [](void *button_handle, void *usr_data){
            printf("Button pressed down callback triggered\n");
            Button *button = static_cast<Button*>(usr_data);
            if (button->on_press_down_) {
                button->on_press_down_();
            }
        }, this);
    }
}
Button::~Button()
{
    if (btn_handle != nullptr) {
        iot_button_delete(btn_handle);
        btn_handle = nullptr;
    }
}