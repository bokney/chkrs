
#include <gb/gb.h>

typedef struct _peonData {

    uint8_t state;
    uint8_t x, y;

} peonData;


typedef struct _gameData {

    uint8_t cursor_x, cursor_y;
    uint8_t cursor_cooldown;
    peonData *cursor_target;

    uint8_t move_counter;
    uint8_t player_score[2];

    peonData *board[8][8];
    peonData peons[2][12];

} gameData;

typedef struct _captureData {
    uint8_t count;
} captureData;