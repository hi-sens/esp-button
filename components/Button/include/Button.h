#ifndef __BUTTON_H__
#define __BUTTON_H__
#include <functional>
#include "iot_button.h"
#include "button_gpio.h"



class Button
{
private:
    button_handle_t btn_handle;  // Handle for the button
    /* data */
    std::function<void()> on_press_down_; // Callback for button press down event
public:
    Button(uint32_t button_num, uint8_t active_level = 0, bool enable_power_save = false);
    ~Button();
    void OnPressDown(std::function<void()> callback);
};

#endif
