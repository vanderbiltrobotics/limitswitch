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
	unsigned int pin = 98; //For GPIOX_Y, the absolute pin number is 32*X+Y. In this case, 32*3+2 = 98.
	//rc_set_pinmux_mode(pin, PINMUX_GPIO_PU); //this line also seems to work. Using default for now because I'm not totally clear on what Push Up is.
	rc_set_default_pinmux();
	rc_gpio_export(pin);
	rc_gpio_set_dir(pin, INPUT_PIN);
	

	//while(true) {
	printf("This is maybe a value: %d\n", rc_gpio_get_value(pin));
	if(rc_gpio_get_value(pin) == HIGH) {
		printf("VALUE CURRENTLY HIGH\n");
	}
	else if (rc_gpio_get_value(pin) == LOW) {
		printf("VALUE CURRENTLY LOW\n");
	}
	else {
		printf("Something's wrong\n");
	}
	rc_gpio_unexport(pin);
	//}



	return 0;
}
