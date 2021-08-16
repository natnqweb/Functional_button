#ifndef Functional_button_h
#define Functional_button_h
#include <Arduino.h>
class button/*functional button class it helps you to manage all buttons*/
{

public:
	uint8_t _buttonPin;/*your button pin*/
	int _debounce_delay;/*debounce for button*/
	button(uint8_t buttonPin = 2/*your button pin*/,int debounce_delay=125/*debounce for button*/)// what to write inside -- nameofyourobj(PIN,Debounce_delay)
	{
		_buttonPin = buttonPin;
		_debounce_delay=debounce_delay;
		pinMode(_buttonPin, INPUT);
	}
	void start();//this function checks the button, you need to place it at the the beggining of the program this won't block your code
	unsigned long get_holdtime();//get your button hold time works on next press !its not real time function you need to press button again to read hold time value
	unsigned long get_idletime();//get your button idle time it works on next press!
	bool get_lastbuttonstate();// get your last button state
	bool get_buttonstate(); // checks if button was pressed it doesnt implement debounce so you need to do it yourself if needed
	bool get_On_Off(); // changes the stats to on and off whenever button is pressed it have debounce implemented!
	bool isReleased();
	bool isPressed();


private:
	bool buttonreleased=1;
	bool buttonState = 0;			// current state of the button
	bool lastButtonState = 0;		// previous state of the button
	unsigned long startPressed = 0; // the moment the button was pressed
	unsigned long endPressed = 0;	// the moment the button was released
	unsigned long holdTime = 0;		// how long the button was hold
	unsigned long idleTime = 0;
	bool onoff= false;              // on off function of button
	unsigned long before;           // special buffor to calculate time diff for debounce
	bool buttonstate_marker=0;
	
	
};

#endif