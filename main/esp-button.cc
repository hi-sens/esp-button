#include <stdio.h>
#include "Button.h"

extern "C" void app_main(void)
{
    printf("Hello world!\n");
    Button button(7, 0, false);
    button.OnPressDown([](){
        printf("Button pressed down\n");
    });
}
