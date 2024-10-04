
#include <gb/gb.h>
#include <gb/crash_handler.h>
#include "game_states.h"
#include "utils/fade.h"

uint8_t joypad_previous, joypad_current;
uint16_t global_counter = 0;

void main(void) {

	fade_out();

    state currentState;
	assign_gameState(&currentState);

    for (;;) {
		
        switch (runState(&currentState)) {
            case 0:
				__HandleCrash();
                break;
			case 1:
				assign_splashState(&currentState);
				break;
			case 2:
				assign_introState(&currentState);
				break;
			case 3:
				assign_mainMenuState(&currentState);
				break;
			case 4:
				assign_gameIntroState(&currentState);
				break;
			case 5:
				assign_gameState(&currentState);
				break;
			case 6:
				assign_loseState(&currentState);
				break;
			case 7:
				assign_winState(&currentState);
				break;
			case 8:
				assign_settingsState(&currentState);
				break;
			default:
				__HandleCrash();
		}

		global_counter++;
		wait_vbl_done();
	}


}
