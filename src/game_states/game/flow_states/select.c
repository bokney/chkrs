
#include "select.h"
#include "../game_data.h"

extern uint8_t joypad_previous, joypad_current;

void select_init(void) {
    
}

uint8_t select_iter(void) {
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
    return 0;
}

uint8_t select_exit(void) {

    return 1;
}
