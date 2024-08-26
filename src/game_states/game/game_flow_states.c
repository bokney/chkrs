
#include <gb/gb.h>
#include "game_flow_states.h"
#include "game_flow_states/select.h"
#include "game_flow_states/drop.h"
#include "game_flow_states/jump.h"
#include "game_flow_states/crown.h"
#include "game_flow_states/capture.h"


state
	selectState,
	dropState,
	jumpState,
	crownState,
	captureState;

state *init_selectState(void) {
    selectState.step = 0;
    selectState.init = select_init;
    selectState.iter = select_iter;
    selectState.exit = select_exit;
    return &selectState;
}

state *init_dropState(void) {
    dropState.step = 0;
    dropState.init = drop_init;
    dropState.iter = drop_iter;
    dropState.exit = drop_exit;
    return &dropState;
}

state *init_jumpState(void) {
    jumpState.step = 0;
    jumpState.init = jump_init;
    jumpState.iter = jump_iter;
    jumpState.exit = jump_exit;
    return &jumpState;
}

state *init_crownState(void) {
    crownState.step = 0;
    crownState.init = crown_init;
    crownState.iter = crown_iter;
    crownState.exit = crown_exit;
    return &crownState;
}

state *init_captureState(void) {
    captureState.step = 0;
    captureState.init = capture_init;
    captureState.iter = capture_iter;
    captureState.exit = capture_exit;
    return &captureState;
}
