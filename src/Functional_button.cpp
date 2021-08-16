#include <Functional_button.h>


void button::start()
{
    buttonState = digitalRead(_buttonPin); // read the button input
  
	if (buttonState != lastButtonState)
    {
		if (millis()-before>=_debounce_delay&&buttonState==1)
		{
		
		onoff=!onoff;
		before=millis();
		
		
		}
      
        // button state changed
        // the button has been just pressed
        if (buttonState == 1)
        { buttonreleased=false;
            startPressed = millis();
            idleTime = startPressed - endPressed;
			
            // the button has been just released
        }
        else
        {	buttonreleased=true;
            endPressed = millis();
            holdTime = endPressed - startPressed;
			
        }
    }

    lastButtonState = buttonState; // save state for next loop
}
unsigned long button::get_holdtime()
{
    return holdTime;
}
unsigned long button::get_idletime()
{
    return idleTime;
}
bool button::get_lastbuttonstate()
{
    return lastButtonState;
}
bool button::get_buttonstate()
{
	return buttonState;  
}
bool button::get_On_Off()
{
	return onoff;
}

bool button::isPressed(){
	if(onoff!=buttonstate_marker){
		buttonstate_marker=onoff;
		return true;
	}else{
		return false;
	}
	

}
bool button::isReleased()
{
	return buttonreleased;
	

}
