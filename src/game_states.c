
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

state *init_splashState(void) {
    splashState.step = 0;
    splashState.init = splash_init;
    splashState.iter = splash_iter;
    splashState.exit = splash_exit;
    return &splashState;
}

state *init_introState(void) {
    introState.step = 0;
    introState.init = intro_init;
    introState.iter = intro_iter;
    introState.exit = intro_exit;
    return &introState;
}

state *init_mainMenuState(void) {
    mainMenuState.step = 0;
    mainMenuState.init = main_menu_init;
    mainMenuState.iter = main_menu_iter;
    mainMenuState.exit = main_menu_exit;
    return &mainMenuState;
}

state *init_gameIntroState(void) {
    gameIntroState.step = 0;
    gameIntroState.init = game_intro_init;
    gameIntroState.iter = game_intro_iter;
    gameIntroState.exit = game_intro_exit;
    return &gameIntroState;
}

state *init_gameState(void) {
    gameState.step = 0;
    gameState.init = game_init;
    gameState.iter = game_iter;
    gameState.exit = game_exit;
    return &gameState;
}

state *init_loseState(void) {
    loseState.step = 0;
    loseState.init = lose_init;
    loseState.iter = lose_iter;
    loseState.exit = lose_exit;
    return &loseState;
}

state *init_winState(void) {
    winState.step = 0;
    winState.init = win_init;
    winState.iter = win_iter;
    winState.exit = win_exit;
    return &winState;
}

state *init_settingsState(void) {
    settingsState.step = 0;
    settingsState.init = settings_init;
    settingsState.iter = settings_iter;
    settingsState.exit = settings_exit;
    return &settingsState;
}
