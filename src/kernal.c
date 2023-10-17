#include <zephyr.h>
#include <device.h>
#include <devicetree.h>
#include <drivers/gpio.h>

#define DEV_OUT DT_NODELABEL(gpioa)
#define PIN_OUT 0

void kernel_main(void)
{
    const struct device *dev_out;
    dev_out = device_get_binding(DT_LABEL(DEV_OUT));
    gpio_pin_configure(dev_out, PIN_OUT, GPIO_OUTPUT_ACTIVE);

	struct k_timer t;
	k_timer_init(&t, NULL, NULL);
    while (1) {
        gpio_pin_toggle(dev_out, PIN_OUT);
        //k_busy_wait(1200); //1200us delay-may be different compared to k_msec(250) delay due to offsets
        //k_busy_wait(2500); //2500us delay-may be different compared to k_msec(250) delay due to offsets
		k_timer_start(&t, K_MSEC(1), K_NO_WAIT);
        //k_busy_wait(500); //6500us delay-may be different compared to k_msec(250) delay due to offsets
        k_busy_wait(3500); //6500us delay-may be different compared to k_msec(250) delay due to offsets
		

		k_timer_status_sync(&t);
    }
}