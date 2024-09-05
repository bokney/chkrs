
#include "game.h"
#include "game/game_data.h"
#include "game/flow_states.h"
#include "game/flow_manager.h"
#include "game/view.h"

#include <gb/crash_handler.h>
#include "../utils/fade.h"

gameData game_data;
// uint8_t joypad_current, joypad_previous;

void init_board(void) {
    uint8_t p_count = 0;
    for (uint8_t ix = 0; ix < 8; ix++) {
        for (uint8_t iy = 0; iy < 8; iy++) {
            if ((ix + iy) % 2) {
                if (iy < 3) {
                    game_data.peons[0][p_count].state = P1MAN;
                    game_data.board[ix][iy] = &game_data.peons[0][p_count];
                    p_count++;
                } else if (iy == 4) {
                    p_count = 0;
                } else if (iy > 4) {
                    game_data.peons[1][p_count].state = P2MAN;
                    game_data.board[ix][iy] = &game_data.peons[1][p_count];
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



void game_init(void) {
    game_data.move_counter = 0;
    game_data.cursor_x = 0;
    game_data.cursor_y = 0;
    game_data.cursor_cooldown = 0;
    game_data.cursor_target = NULL;
    
    init_board();

    init_gfx();
    init_cursor();

    draw_bkg();

    draw_sprites();

    fade_in();
    init_sound();

    game_flow_init();
}

uint8_t game_iter(void) {

    game_flow_iter();

    draw_sprites();

    delay(16);
    return 0;
}

uint8_t game_exit(void) {
    game_flow_exit();
    fade_out();
    return 1;
}
