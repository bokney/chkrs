
#include <gb/gb.h>
#include <gb/crash_handler.h>
#include "view.h"
#include "game_data.h"


extern const uint8_t tiles;
extern const uint8_t sprites;

extern uint16_t global_counter;

void init_gfx(void) {
    set_bkg_data(0, 12, &tiles);
    SPRITES_8x8;
    set_sprite_data(0, 2, &sprites);
}

void init_cursor(void) {
    HIDE_SPRITES;
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
                peonData *peon_ptr = game_data.board[ix][iy];
                switch (peon_ptr->state) {
                    case P1MAN:
                        set_bkg_tile_xy(ix + x_offset, iy + y_offset, 10);
                        break;
                    case P1KING:
                        set_bkg_tile_xy(ix + x_offset, iy + y_offset, 10);
                        break;
                    case P1CAPTURED:
                        __HandleCrash();
                        break;
                    case P2MAN:
                        set_bkg_tile_xy(ix + x_offset, iy + y_offset, 11);
                        break;
                    case P2KING:
                        set_bkg_tile_xy(ix + x_offset, iy + y_offset, 11);
                        break;
                    case P2CAPTURED:
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
