
#include <gb/gb.h>
#include "flow_states.h"
#include "flow_states/select.h"
#include "flow_states/pass.h"
#include "flow_states/declare.h"
#include "flow_states/drop.h"
#include "flow_states/jump.h"
#include "flow_states/crown.h"
#include "flow_states/capture.h"
#include "flow_states/handover.h"
#include "flow_states/end.h"

void assign_selectState(state *state) {
    state->init = &select_init;
    state->iter = &select_iter;
    state->exit = &select_exit;
}

void assign_passState(state *state) {
    state->init = &pass_init;
    state->iter = &pass_iter;
    state->exit = &pass_exit;
}

void assign_declareState(state *state) {
    state->init = &declare_init;
    state->iter = &declare_iter;
    state->exit = &declare_exit;
}

void assign_dropState(state *state) {
    state->init = &drop_init;
    state->iter = &drop_iter;
    state->exit = &drop_exit;
}

void assign_jumpState(state *state) {
    state->init = &jump_init;
    state->iter = &jump_iter;
    state->exit = &jump_exit;
}

void assign_crownState(state *state) {
    state->init = &crown_init;
    state->iter = &crown_iter;
    state->exit = &crown_exit;
}

void assign_captureState(state *state) {
    state->init = &capture_init;
    state->iter = &capture_iter;
    state->exit = &capture_exit;
}

void assign_handoverState(state *state) {
    state->init = &handover_init;
    state->iter = &handover_iter;
    state->exit = &handover_exit;
}

void assign_endState(state *state) {
    state->init = &end_init;
    state->iter = &end_iter;
    state->exit = &end_exit;
}
