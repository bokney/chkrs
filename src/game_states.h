
#include "utils/stateManager/stateManager.h"

extern state splashState;
extern state introState;
extern state mainMenuState;
extern state gameIntroState;
extern state gameState;
extern state loseState;
extern state winState;
extern state settingsState;

state *init_splashState(void);
state *init_introState(void);
state *init_mainMenuState(void);
state *init_gameIntroState(void);
state *init_gameState(void);
state *init_loseState(void);
state *init_winState(void);
state *init_settingsState(void);
