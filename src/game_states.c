
#include <gb/gb.h>
#include "game_states.h"
#include "game_states/splash.h"
#include "game_states/intro.h"
#include "game_states/main_menu.h"
#include "game_states/game_intro.h"
#include "game_states/game.h"
#include "game_states/lose.h"
#include "game_states/win.h"
#include "game_states/settings.h"


state
	splashState,
	introState,
	mainMenuState,
	gameIntroState,
	gameState,
	loseState,
	winState,
	settingsState;

void assign_splashState(state *state) {
    state->step = 0;
    state->init = &splash_init;
    state->iter = &splash_iter;
    state->exit = &splash_exit;
}

void assign_introState(state *state) {
    state->step = 0;
    state->init = &intro_init;
    state->iter = &intro_iter;
    state->exit = &intro_exit;
}

void assign_mainMenuState(state *state) {
    state->step = 0;
    state->init = &main_menu_init;
    state->iter = &main_menu_iter;
    state->exit = &main_menu_exit;
}

void assign_gameIntroState(state *state) {
    state->step = 0;
    state->init = &game_intro_init;
    state->iter = &game_intro_iter;
    state->exit = &game_intro_exit;
}

void assign_gameState(state *state) {
    state->step = 0;
    state->init = &game_init;
    state->iter = &game_iter;
    state->exit = &game_exit;
}

void assign_loseState(state *state) {
    state->step = 0;
    state->init = &lose_init;
    state->iter = &lose_iter;
    state->exit = &lose_exit;
}

void assign_winState(state *state) {
    state->step = 0;
    state->init = &win_init;
    state->iter = &win_iter;
    state->exit = &win_exit;
}

void assign_settingsState(state *state) {
    state->step = 0;
    state->init = &settings_init;
    state->iter = &settings_iter;
    state->exit = &settings_exit;
}
