
#include "select.h"
#include "../game_data.h"
#include "../../../utils/sfx.h"

#define CURSOR_COOLDOWN 9

extern uint8_t joypad_previous, joypad_current;
uint8_t wall_hit_x = 0;
uint8_t wall_hit_y = 0;
uint8_t destination = 0;

typedef struct _moveCommand {
    uint8_t move_type;
    /*
        0: none, skip
        1: move (-> crown)
        2: capture (-> capture)
    */
    uint8_t target_x, target_y;
    struct _moveCommand *next;
} moveCommand;

void init_moveCommand(moveCommand *target) {
    target->move_type = 0;
    target->target_x = 0;
    target->target_y = 0;
    target->next = NULL;
}

moveCommand possible_moves[32];
peonData *can_move[12];

void get_possible_moves(peonData *peon, uint8_t player) {
    for (uint8_t i = 0; i < 32; i++) {
        init_moveCommand(&possible_moves[i]);
    }
    // is space empty
    // if (!game_data.board[peon->x + 1][peon->y + 1])
    if (1 < peon->x < 6) {

    }
}

uint8_t is_valid_move(peonData *peon, uint8_t target_x, uint8_t target_y) {
    // is space free to move to
    if (!game_data.board[target_x][target_y]) {
        
    }
}

void select_init(void) {

}

uint8_t select_iter(void) {
    joypad_previous = joypad_current;
    joypad_current = joypad();
    if (game_data.cursor_cooldown == 0) {
        if (joypad_current & J_UP) {
            game_data.cursor_cooldown = CURSOR_COOLDOWN;
            if (game_data.cursor_y > 0) {
                game_data.cursor_y--;
                wall_hit_x = 0;
                wall_hit_y = 0;
            } else if (!wall_hit_y) {
                snd_nuhuh();
                wall_hit_x = 0;
                wall_hit_y = 1;
            }
        } else if (joypad_current & J_DOWN) {
            game_data.cursor_cooldown = CURSOR_COOLDOWN;
            if (game_data.cursor_y < 7) {
                game_data.cursor_y++;
                wall_hit_x = 0;
                wall_hit_y = 0;
            } else if (!wall_hit_y) {
                snd_nuhuh();
                wall_hit_x = 0;
                wall_hit_y = 1;
            }
        } else if (joypad_current & J_LEFT) {
            game_data.cursor_cooldown = CURSOR_COOLDOWN;
            if (game_data.cursor_x > 0) {
                game_data.cursor_x--;
                wall_hit_x = 0;
                wall_hit_y = 0;
            } else if (!wall_hit_x) {
                snd_nuhuh();
                wall_hit_x = 1;
                wall_hit_y = 0;
            }
        } else if (joypad_current & J_RIGHT) {
            game_data.cursor_cooldown = CURSOR_COOLDOWN;
            if (game_data.cursor_x < 7) {
                game_data.cursor_x++;
                wall_hit_x = 0;
                wall_hit_y = 0;
            } else if (!wall_hit_x) {
                snd_nuhuh();
                wall_hit_x = 1;
                wall_hit_y = 0;
            }
        } else if (joypad_current != joypad_previous) {
            if (joypad_current & J_A) {
                game_data.cursor_cooldown = CURSOR_COOLDOWN;
                if (game_data.board[game_data.cursor_x][game_data.cursor_y]) {
                    // a piece exists here
                    if (game_data.cursor_target) {
                        game_data.cursor_target = NULL;
                        snd_nuhuh();
                    } else {
                        game_data.cursor_target = game_data.board[game_data.cursor_x][game_data.cursor_y];
                        snd_bleoop();
                        destination = 3; // declareState
                        return 1;
                    }
                }
            } else if (joypad_current & J_B) {
                if (game_data.cursor_x % 2) snd_fall_down();
                else snd_star_fall();
            }
        }
    } else {
        game_data.cursor_cooldown--;
    }
    return 0;
}

uint8_t select_exit(void) {
    return destination;
}
