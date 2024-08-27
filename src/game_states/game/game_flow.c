
#include <gb/gb.h>
#include <gb/crash_handler.h>
#include "game_flow_states.h"

state currentState;

void game_flow_init(void) {
    init_selectState(&currentState);
}

uint8_t game_flow_iter(void) {
    for (;;) {
        switch (runState(&currentState)) {
            case 0:
                break;
			case 1:
				init_selectState(&currentState);
				break;
			case 2:
				init_passState(&currentState);
				break;
			case 3:
				init_declareState(&currentState);
				break;
			case 4:
				init_dropState(&currentState);
				break;
			case 5:
				init_jumpState(&currentState);
				break;
			case 6:
				init_crownState(&currentState);
				break;
			case 7:
				init_captureState(&currentState);
				break;
			case 8:
				init_handoverState(&currentState);
				break;
			case 9:
				init_endState(&currentState);
				return 1;
			default:
				__HandleCrash();
		}
	}
	return 0;
}

uint8_t game_flow_exit(void) {

    return 1;
}