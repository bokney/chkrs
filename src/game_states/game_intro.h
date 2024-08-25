
#include <gb/gb.h>

typedef struct _gameIntroData gameIntroData;

extern gameIntroData game_intro_data;

void game_intro_init(void *data);
uint8_t game_intro_iter(void *data);
uint8_t game_intro_exit(void *data);
