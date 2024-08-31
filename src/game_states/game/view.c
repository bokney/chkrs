
#include "view.h"
#include <gb/gb.h>
#include "game_data.h"

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
