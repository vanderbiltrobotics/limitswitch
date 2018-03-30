#include <stdint.h>
#include <unistd.h>
#include <stdio.h>
#include <math.h>
extern "C" {
  #include <roboticscape.h>
  #include <rc_usefulincludes.h>
}

int main()
{
	rc_initialize();
	rc_set_pinmux_mode(2, PINMUX_GPIO); //GPIO3_2
	rc_gpio_export(2);
	rc_gpio_set_dir(2, OUTPUT_PIN);

	printf("This is maybe a value: %f\n", rc_gpio_get_value(2));



	return 0;
}
