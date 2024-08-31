
#include <gb/gb.h>


typedef enum _peonState {
    P1MAN = 0,
    P1KING = 1,
    P1CAPTURED = 2,
    P2MAN = 3,
    P2KING = 4,
    P2CAPTURED = 5
} peonState;


typedef struct _peonData {

    peonState state;
    uint8_t x, y;

} peonData;


typedef struct _gameData {

    uint8_t turn;
    uint8_t score[2];

    peonData *board[8][8];
    peonData peons[2][12];

    uint8_t cursor_x, cursor_y;
    uint8_t cursor_cooldown;
    peonData *cursor_target;

    uint16_t move_counter;

} gameData;

extern gameData game_data;
