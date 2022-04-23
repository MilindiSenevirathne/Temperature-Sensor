#define get_bit(reg,bitnum) ((reg & (1<<bitnum))>>bitnum)
#define F_CPU 16000000
#include <avr/io.h>


int main(void)

{
	int ADCOut=0;

	char Temperature;

	DDRD=0b0000100; // set pin 3 on port D as output to control the buzzer

	DDRA&=~(1<<7);

	ADMUX=0b11000111;

	ADCSRA=0b10000111;


	while(1)

	{

		ADCSRA|=(1<<6); //Set bit 6 n ADCSRA to start conversion

		while(get_bit(ADCSRA,6)==1) // poll bit 6 n ADCSRA till it is back to zero again

		{

		}


		ADCOut=ADCL|(ADCH<<8); // Save the ADC reading into an integer variable ADCOut. The ADCL must be read first as written here.

		Temperature=ADCOut/4; // Calculate Temperature


		if (Temperature>45) // Check if temperature is above 45 Celsius degrees

		{

			PORTD|=(1<<2); //turn on the buzzer

		}

		else

		{

			PORTD&=~(1<<2); //turn off the buzzer

		}

	}

}


