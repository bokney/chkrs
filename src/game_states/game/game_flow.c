
#include <gb/gb.h>
#include <gb/crash_handler.h>
#include "game_flow_states.h"

void game_flow(void) {

	init_selectState();
	init_dropState();
	init_jumpState();
	init_crownState();
	init_captureState();

    state *currentState = &selectState;
    
    for (;;) {
        switch (runState(currentState)) {
            case 0:
                break;
			case 1:
				currentState = &selectState;
				break;
			case 2:
				currentState = &dropState;
				break;
			case 3:
				currentState = &jumpState;
				break;
			case 4:
				currentState = &crownState;
				break;
			case 5:
				currentState = &captureState;
				break;
			default:
				__HandleCrash();
		}
	}
}
