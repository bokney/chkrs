
#include <gb/gb.h>
#include <gb/crash_handler.h>
#include "flow_states.h"

state currentState;

void game_flow_init(void) {
    assign_selectState(&currentState);
}

uint8_t game_flow_iter(void) {
	switch (runState(&currentState)) {
		case 0:
			__HandleCrash();
			break;
		case 1:
			assign_selectState(&currentState);
			break;
		case 2:
			assign_passState(&currentState);
			break;
		case 3:
			assign_declareState(&currentState);
			break;
		case 4:
			assign_dropState(&currentState);
			break;
		case 5:
			assign_jumpState(&currentState);
			break;
		case 6:
			assign_crownState(&currentState);
			break;
		case 7:
			assign_captureState(&currentState);
			break;
		case 8:
			assign_handoverState(&currentState);
			break;
		case 9:
			assign_endState(&currentState);
			return 1;
		default:
			__HandleCrash();
	}
	return 0;
}

uint8_t game_flow_exit(void) {

    return 1;
}