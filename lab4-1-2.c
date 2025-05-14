#include <stdio.h>
#include <pigpio.h>

int main(){
	int pin1 = 18;
	int pin2 = 23;
	int pin3 = 24;

	gpioInitialise();

	gpioSetMode(pin1, PI_OUTPUT);
	gpioSetMode(pin2, PI_OUTPUT);
	gpioSetMode(pin3, PI_OUTPUT);

	while(1) {
		gpioWrite(pin1 , 1);
		gpioDelay(3000000);
		gpioWrite(pin1 , 0);
		gpioWrite(pin2, 1);
		gpioDelay(3000000);
		gpioWrite(pin2, 0);
		gpioWrite(pin3, 1);
		gpioDelay(3000000);
		gpioWrite(pin3, 0);
	}

	gpioTerminate();
	return 0;

			
}
