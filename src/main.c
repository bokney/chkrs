
#include <gb/gb.h>
#include <gb/crash_handler.h>
#include "game_states.h"
#include "utils/fade.h"

uint8_t joypad_previous, joypad_current;
uint16_t global_counter = 0;

void main(void) {

	fade_out();

	init_splashState();
	init_introState();
	init_mainMenuState();
	init_gameIntroState();
	init_gameState();
	init_loseState();
	init_winState();
	init_settingsState();

    state *currentState = &gameState;

    for (;;) {
        switch (runState(currentState)) {
            case 0:
                break;
			case 1:
				currentState = &splashState;
				break;
			case 2:
				currentState = &introState;
				break;
			case 3:
				currentState = &mainMenuState;
				break;
			case 4:
				currentState = &gameIntroState;
				break;
			case 5:
				currentState = &gameState;
				break;
			case 6:
				currentState = &loseState;
				break;
			case 7:
				currentState = &winState;
				break;
			case 8:
				currentState = &settingsState;
				break;
			default:
				__HandleCrash();
		}
		global_counter++;
		wait_vbl_done();
	}
}
