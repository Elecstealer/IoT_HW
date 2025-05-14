#include <stdio.h>
#include <pigpio.h>

int main(){
	int pin = 18;
	int switch_pin = 24;
	
	int input = 0;
	int led_state = 0;
	int prev_switch = 1;
	
	gpioInitialise();

	gpioSetMode(pin, PI_OUTPUT);
	gpioSetMode(switch_pin, PI_INPUT);

	while(1){
		input = gpioRead(switch_pin);

		if(input == 0 && prev_switch == 1){
			led_state = !led_state;			
			gpioWrite(pin, led_state);
			gpioDelay(2000000);
		}
		prev_switch = input;
	}

	gpioTerminate();
	return 0;
}
