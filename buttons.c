/*
test10
*/
#include "buttons.h"

struct buttonState button;



void buttonUpdate()
{
	uint16_t state;
	static uint16_t last_state = BTN_PIN_YES | BTN_PIN_NO;

	state = gpio_port_read(BTN_PORT);

	if ((state & BTN_PIN_YES) == 0) {	// Yes button is down
		if ((last_state & BTN_PIN_YES) == 0) {		// last Yes was down
			if (button.YesDown < 2000000000) button.YesDown++;
			button.YesUp = false;
		} else {					// last Yes was up
			button.YesDown = 0;
			button.YesUp = false;
		}
	} else {				// Yes button is up
		if ((last_state & BTN_PIN_YES) == 0) {		// last Yes was down
			button.YesDown = 0;
			button.YesUp = true;
		} else {					// last Yes was up
			button.YesDown = 0;
			button.YesUp = false;
		}
	}

	if ((state & BTN_PIN_NO) == 0) {	// No button is down
		if ((last_state & BTN_PIN_NO) == 0) {		// last No was down
			if (button.NoDown < 2000000000) button.NoDown++;
			button.NoUp = false;
		} else {					// last No was up
			button.NoDown = 0;
			button.NoUp = false;
		}
	} else {				// No button is up
		if ((last_state & BTN_PIN_NO) == 0) {		// last No was down
			button.NoDown = 0;
			button.NoUp = true;
		} else {					// last No was up
			button.NoDown = 0;
			button.NoUp = false;
		}
	}

	last_state = state;
}
