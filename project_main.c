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
                       InitADC();
                       uint16_t temp;
                      temp=ReadADC(0);
                      _delay_ms(200);
                
            }
          }
       else
       {
            PORTB &=~(1<<PB0);

       }

    }
}
void InitADC()
{
    ADMUX=(1<<REFS0);
    ADCSRA=(1<<ADEN)|(7<<ADPS0);
}

uint16_t ReadADC(uint8_t ch)
{
    ADMUX &=0xf8;
    ch=ch&0b00000111;
    ADMUX |=ch;
    ADCSRA |=(1<<ADSC);
    while (!(ADCSRA &(1<<ADIF)));
    ADCSRA |=(1<<ADIF);
    return(ADC);
}

