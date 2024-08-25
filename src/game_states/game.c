
#include "game.h"
#include <gb/crash_handler.h>
// #include "../gfx/tiles.h"
#include "../fade.h"

typedef enum _peonState {
    P1MAN = 0,
    P1KING = 1,
    P1LOST = 2,
    P2MAN = 3,
    P2KING = 4,
    P2LOST = 5
} peonState;

typedef struct _peon {
    peonState state;
} peon;

typedef struct _gameData {
    uint8_t move_counter;
    uint8_t cursor_x;
    uint8_t cursor_y;
    uint8_t cursor_cooldown;
    peon peons[24];
    peon *board[8][8];
} gameData;

gameData game_data;

extern uint16_t global_counter;

extern const uint8_t tiles;
extern const uint8_t sprites;

void draw_bkg(void) {
    gameData *data_ptr = &game_data;
    uint8_t x_offset = 6;
    uint8_t y_offset = 5;
    HIDE_BKG;
    init_bkg(2);
    for (uint8_t ix = 0; ix < 8; ix++) {
        for (uint8_t iy = 0; iy < 8; iy++) {
            if (data_ptr->board[ix][iy]) {
                peon *peon_ptr = data_ptr->board[ix][iy];
                switch (peon_ptr->state) {
                    case P1MAN:
                        set_bkg_tile_xy(ix + x_offset, iy + y_offset, 10);
                        break;
                    case P1KING:
                        set_bkg_tile_xy(ix + x_offset, iy + y_offset, 10);
                        break;
                    case P1LOST:
                        __HandleCrash();
                        break;
                    case P2MAN:
                        set_bkg_tile_xy(ix + x_offset, iy + y_offset, 11);
                        break;
                    case P2KING:
                        set_bkg_tile_xy(ix + x_offset, iy + y_offset, 11);
                        break;
                    case P2LOST:
                        __HandleCrash();
                        break;
                    default:
                        __HandleCrash();
                        break;
                }
            } else {
                if ((ix + iy) % 2) {
                    set_bkg_tile_xy(ix + x_offset, iy + y_offset, 1);
                } else {
                    set_bkg_tile_xy(ix + x_offset, iy + y_offset, 3);
                }
            }
        }
    }
    SHOW_BKG;
}

void draw_sprites(void) {
    gameData *data_ptr = &game_data;
    HIDE_SPRITES;
    if ((global_counter / 4) % 2) {
        move_sprite(0, 51 + data_ptr->cursor_x * 8, 51 + data_ptr->cursor_y * 8);
        move_sprite(1, 51 + data_ptr->cursor_x * 8, 61 + data_ptr->cursor_y * 8);
        move_sprite(2, 61 + data_ptr->cursor_x * 8, 51 + data_ptr->cursor_y * 8);
        move_sprite(3, 61 + data_ptr->cursor_x * 8, 61 + data_ptr->cursor_y * 8);
    } else {
        move_sprite(0, 52 + data_ptr->cursor_x * 8, 52 + data_ptr->cursor_y * 8);
        move_sprite(1, 52 + data_ptr->cursor_x * 8, 60 + data_ptr->cursor_y * 8);
        move_sprite(2, 60 + data_ptr->cursor_x * 8, 52 + data_ptr->cursor_y * 8);
        move_sprite(3, 60 + data_ptr->cursor_x * 8, 60 + data_ptr->cursor_y * 8);
    }
    SHOW_SPRITES;
}

void game_init(void *data) {
    gameData *data_ptr = data;
    data_ptr->move_counter = 0;
    data_ptr->cursor_x = 0;
    data_ptr->cursor_y = 0;
    data_ptr->cursor_cooldown = 0;

    uint8_t p_count = 0;

    for (uint8_t ix = 0; ix < 8; ix++) {
        for (uint8_t iy = 0; iy < 8; iy++) {
            if ((ix + iy) % 2) {
                if (iy < 3) {
                    data_ptr->peons[p_count].state = P1MAN;
                    data_ptr->board[ix][iy] = &data_ptr->peons[p_count];
                    p_count++;
                } else if (iy > 4) {
                    data_ptr->peons[p_count].state = P2MAN;
                    data_ptr->board[ix][iy] = &data_ptr->peons[p_count];
                    p_count++;
                } else {
                    data_ptr->board[ix][iy] = NULL;
                }
            } else {
                data_ptr->board[ix][iy] = NULL;
            }
        }
    }

    set_bkg_data(0, 12, &tiles);
    draw_bkg();

    SPRITES_8x8;
    HIDE_SPRITES;
    set_sprite_data(0, 2, &sprites);
    set_sprite_tile(0, 0);
    set_sprite_tile(1, 0);
    set_sprite_prop(1, S_FLIPY);
    set_sprite_tile(2, 0);
    set_sprite_prop(2, S_FLIPX);
    set_sprite_tile(3, 0);
    set_sprite_prop(3, S_FLIPY | S_FLIPX);
    draw_sprites();

    fade_in();
}

uint8_t game_iter(void *data) {
    gameData *data_ptr = data;

    if (data_ptr->cursor_cooldown == 0) {
        if (joypad() & J_UP) {
            data_ptr->cursor_cooldown = 4;
            if (data_ptr->cursor_y > 0) {
                data_ptr->cursor_y--;
            } else {
                // buzz
            }
        } else if (joypad() & J_DOWN) {
            data_ptr->cursor_cooldown = 4;
            if (data_ptr->cursor_y < 7) {
                data_ptr->cursor_y++;
            } else {
                // buzz
            }
        } else if (joypad() & J_LEFT) {
            data_ptr->cursor_cooldown = 4;
            if (data_ptr->cursor_x > 0) {
                data_ptr->cursor_x--;
            } else {
                // buzz
            }
        } else if (joypad() & J_RIGHT) {
            data_ptr->cursor_cooldown = 4;
            if (data_ptr->cursor_x < 7) {
                data_ptr->cursor_x++;
            } else {
                // buzz
            }
        }
    } else {
        data_ptr->cursor_cooldown--;
    }


    draw_sprites();

    data_ptr->move_counter++;
    delay(20);
    return 0;
}

uint8_t game_exit(void *data) {
    gameData *data_ptr = data;
    // fade_out();
    return 1;
}
