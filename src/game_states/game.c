
#include "game.h"
#include "game/game_flow_states.h"
#include "game/game_flow_states/select.h"
#include "game/game_flow_states/drop.h"
#include "game/game_flow_states/jump.h"
#include "game/game_flow_states/crown.h"
#include "game/game_flow_states/capture.h"
#include <gb/crash_handler.h>
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
    uint8_t x, y;
} peon;

typedef struct _gameData {

    uint8_t cursor_x, cursor_y;
    uint8_t cursor_cooldown;
    peon *cursor_target;

    uint8_t move_counter;
    peon peons[24];
    peon *board[8][8];

} gameData;

gameData game_data;
state *flow_state = &selectState;

uint8_t joypad_current, joypad_previous;

extern uint16_t global_counter;

extern const uint8_t tiles;
extern const uint8_t sprites;

void init_sound(void) {
    NR52_REG=0x80;
    NR50_REG=0x77;
    NR51_REG=0xFF;
}

void do_sound(void) {
    NR10_REG=0x6A;
    NR11_REG=0x86;
    NR12_REG=0x82;
    NR13_REG=0xA6;
    NR14_REG=0x82;
}

void init_board(void) {
    uint8_t p_count = 0;
        for (uint8_t ix = 0; ix < 8; ix++) {
        for (uint8_t iy = 0; iy < 8; iy++) {
            if ((ix + iy) % 2) {
                if (iy < 3) {
                    game_data.peons[p_count].state = P1MAN;
                    game_data.board[ix][iy] = &game_data.peons[p_count];
                    p_count++;
                } else if (iy > 4) {
                    game_data.peons[p_count].state = P2MAN;
                    game_data.board[ix][iy] = &game_data.peons[p_count];
                    p_count++;
                } else {
                    game_data.board[ix][iy] = NULL;
                }
            } else {
                game_data.board[ix][iy] = NULL;
            }
        }
    }
}

void init_cursor(void) {
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
    SHOW_SPRITES;
}

void draw_bkg(void) {
    gameData *data_ptr = &game_data;
    uint8_t x_offset = 6;
    uint8_t y_offset = 5;
    HIDE_BKG;
    init_bkg(2);
    for (uint8_t ix = 0; ix < 8; ix++) {
        for (uint8_t iy = 0; iy < 8; iy++) {
            if (game_data.board[ix][iy]) {
                peon *peon_ptr = game_data.board[ix][iy];
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
    if ((global_counter >> 3) % 2) {
        move_sprite(0, 51 + game_data.cursor_x * 8, 51 + game_data.cursor_y * 8);
        move_sprite(1, 51 + game_data.cursor_x * 8, 61 + game_data.cursor_y * 8);
        move_sprite(2, 61 + game_data.cursor_x * 8, 51 + game_data.cursor_y * 8);
        move_sprite(3, 61 + game_data.cursor_x * 8, 61 + game_data.cursor_y * 8);
    } else {
        move_sprite(0, 52 + game_data.cursor_x * 8, 52 + game_data.cursor_y * 8);
        move_sprite(1, 52 + game_data.cursor_x * 8, 60 + game_data.cursor_y * 8);
        move_sprite(2, 60 + game_data.cursor_x * 8, 52 + game_data.cursor_y * 8);
        move_sprite(3, 60 + game_data.cursor_x * 8, 60 + game_data.cursor_y * 8);
    }
    SHOW_SPRITES;
}

void game_init(void) {
    game_data.move_counter = 0;
    game_data.cursor_x = 0;
    game_data.cursor_y = 0;
    game_data.cursor_cooldown = 0;
    game_data.cursor_target = NULL;
    
    init_board();

    init_selectState();
    init_dropState();
    init_jumpState();
    init_crownState();
    init_captureState();

    set_bkg_data(0, 12, &tiles);
    draw_bkg();

    init_cursor();
    draw_sprites();

    fade_in();
    init_sound();
    do_sound();
}

void cursor_poll(void) {
    joypad_previous = joypad_current;
    joypad_current = joypad();
    if (game_data.cursor_cooldown == 0) {
        if (joypad_current & J_UP) {
            game_data.cursor_cooldown = 7;
            if (game_data.cursor_y > 0) {
                game_data.cursor_y--;
            } else {
                // buzz
            }
        } else if (joypad_current & J_DOWN) {
            game_data.cursor_cooldown = 7;
            if (game_data.cursor_y < 7) {
                game_data.cursor_y++;
            } else {
                // buzz
            }
        } else if (joypad_current & J_LEFT) {
            game_data.cursor_cooldown = 7;
            if (game_data.cursor_x > 0) {
                game_data.cursor_x--;
            } else {
                // buzz
            }
        } else if (joypad_current & J_RIGHT) {
            game_data.cursor_cooldown = 7;
            if (game_data.cursor_x < 7) {
                game_data.cursor_x++;
            } else {
                // buzz
            }
        } else if (joypad_current & J_A) {
            if (game_data.board[game_data.cursor_x][game_data.cursor_y]) {
                // a piece exists here
                // if (game_data.move_counter % 2)
                if (game_data.cursor_target) {
                    game_data.cursor_target = NULL;
                } else {
                    game_data.cursor_target = game_data.board[game_data.cursor_x][game_data.cursor_y];
                }
            }
        }
    } else {
        game_data.cursor_cooldown--;
    }
}

uint8_t game_iter(void) {



    cursor_poll();
    
    //     if (game_data.cursor_target) {
    //         // game_data.cursor_target-
    //     }
    // } else {
    //     game_data.cursor_cooldown--;
    // }


    draw_sprites();

    delay(16);
    return 0;
}

uint8_t game_exit(void) {
    
    // fade_out();
    return 1;
}
