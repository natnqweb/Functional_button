#include <Functional_button.h>
// this program will light up arduino uno build in led on when button is pressed
#define ledpin 13
#define button_pin 2
#define debouncedelay 100//if pulldown then type 0 .-- if pull up then type 1. 

button button1(button_pin,debouncedelay);
//button button1; //it is same thing becouse the values above are default for this class
void setup()
{
    pinMode(ledpin, OUTPUT);
}
void loop()
{
    button1.start();
 
    button1.ispressed() ? digitalWrite(ledpin, 1) : digitalWrite(ledpin, 0);
   
}