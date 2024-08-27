
#include <gb/gb.h>
#include "game_states.h"
#include "game_states/select.h"
#include "game_states/pass.h"
#include "game_states/declare.h"
#include "game_states/drop.h"
#include "game_states/jump.h"
#include "game_states/crown.h"
#include "game_states/capture.h"
#include "game_states/handover.h"
#include "game_states/end.h"

void init_selectState(state *state) {
    state->init = &select_init;
    state->iter = &select_iter;
    state->exit = &select_exit;
}

void init_passState(state state) {
    state->init = &pass_init;
    state->iter = &pass_iter;
    state->exit = &pass_exit;
}

void init_declareState(state state) {
    state->init = &declare_init;
    state->iter = &declare_iter;
    state->exit = &declare_exit;
}

void init_dropState(state state) {
    state->init = &drop_init;
    state->iter = &drop_iter;
    state->exit = &drop_exit;
}

void init_jumpState(state state) {
    state->init = &jump_init;
    state->iter = &jump_iter;
    state->exit = &jump_exit;
}

void init_crownState(state state) {
    state->init = &crown_init;
    state->iter = &crown_iter;
    state->exit = &crown_exit;
}

void init_captureState(state state) {
    state->init = &capture_init;
    state->iter = &capture_iter;
    state->exit = &capture_exit;
}

void init_handoverState(state state) {
    state->init = &handover_init;
    state->iter = &handover_iter;
    state->exit = &handover_exit;
}

void init_endState(state state) {
    state->init = &end_init;
    state->iter = &end_iter;
    state->exit = &end_exit;
}
