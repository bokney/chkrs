
#include "game_intro.h"
#include "../fade.h"

typedef struct _gameIntroData {
    uint8_t count;
} gameIntroData;

gameIntroData game_intro_data;

void game_intro_init(void *data) {
    gameIntroData *data_ptr = data;
    data_ptr->count = 0;
    fade_in();
}

uint8_t game_intro_iter(void *data) {
    gameIntroData *data_ptr = data;

    return 0;
}

uint8_t game_intro_exit(void *data) {
    gameIntroData *data_ptr = data;
    fade_out();
    return 1;
}
