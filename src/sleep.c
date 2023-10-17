#include <zephyr.h>
#include <device.h>
#include <devicetree.h>
#include <drivers/gpio.h>

#define DEV_OUT DT_NODELABEL(gpioa)
#define PIN_OUT 0

void sleep_main(void)
{
    const struct device *dev_out;
    dev_out = device_get_binding(DT_LABEL(DEV_OUT));
    gpio_pin_configure(dev_out, PIN_OUT, GPIO_OUTPUT_ACTIVE);

    while (1) {
        gpio_pin_toggle(dev_out, PIN_OUT);
        //k_busy_wait(250); //250ms delay-may be different compared to k_msec(250) delay due to offsets
        //k_busy_wait(1200); //1200us delay-may be different compared to k_msec(250) delay due to offsets
        //k_busy_wait(2500); //2500us delay-may be different compared to k_msec(250) delay due to offsets

        //k_sleep(K_MSEC(1));

        ///busy.c section e
        //k_busy_wait(1000); //1000us delay-simulate k sleep k m sec =1
        //k_busy_wait(1500); //1500us delay-simulate k sleep k m sec =1.5
        k_busy_wait(2500); //1000us delay-simulate k sleep k m sec =2.5


    }
}