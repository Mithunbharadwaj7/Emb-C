#include <avr/io.h>
#include<util/delay.h>



int main(void)
{
    DDRB |=(1<<PB0);
    DDRD |=~(1<<PD0);
    PORTD |=(1<<PD0);
    DDRD |=~(1<<PD1);
    PORTD |=(1<<PD1);



    while(1)
    {
        if((!(PIND&(1<<PIND0))))
        {
            if ((!(PIND&(1<<PIND1))))
                {
                       PORTB |=(1<<PB0);
                }
          }
       else
       {
            PORTB &=~(1<<PB0);

       }

    }
}
