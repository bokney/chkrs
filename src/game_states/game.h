
#include <gb/gb.h>

typedef struct _gameData gameData;

extern gameData game_data;

void game_init(void *data);
uint8_t game_iter(void *data);
uint8_t game_exit(void *data);
