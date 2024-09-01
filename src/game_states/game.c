
#include "game.h"
#include "game/game_data.h"
#include "game/flow_states.h"
#include "game/flow_manager.h"
#include "game/view.h"

#include <gb/crash_handler.h>
#include "../fade.h"

gameData game_data;
// uint8_t joypad_current, joypad_previous;

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

    // init_bkg(1);

    init_gfx();
    init_cursor();

    draw_bkg();

    draw_sprites();

    fade_in();
    init_sound();
    do_sound();

    game_flow_init();
}

// void cursor_poll(void) {
//     joypad_previous = joypad_current;
//     joypad_current = joypad();
//     if (game_data.cursor_cooldown == 0) {
//         if (joypad_current & J_UP) {
//             game_data.cursor_cooldown = 7;
//             if (game_data.cursor_y > 0) {
//                 game_data.cursor_y--;
//             } else {
//                 // buzz
//             }
//         } else if (joypad_current & J_DOWN) {
//             game_data.cursor_cooldown = 7;
//             if (game_data.cursor_y < 7) {
//                 game_data.cursor_y++;
//             } else {
//                 // buzz
//             }
//         } else if (joypad_current & J_LEFT) {
//             game_data.cursor_cooldown = 7;
//             if (game_data.cursor_x > 0) {
//                 game_data.cursor_x--;
//             } else {
//                 // buzz
//             }
//         } else if (joypad_current & J_RIGHT) {
//             game_data.cursor_cooldown = 7;
//             if (game_data.cursor_x < 7) {
//                 game_data.cursor_x++;
//             } else {
//                 // buzz
//             }
//         } else if (joypad_current & J_A) {
//             if (game_data.board[game_data.cursor_x][game_data.cursor_y]) {
//                 // a piece exists here
//                 // if (game_data.move_counter % 2)
//                 if (game_data.cursor_target) {
//                     game_data.cursor_target = NULL;
//                 } else {
//                     game_data.cursor_target = game_data.board[game_data.cursor_x][game_data.cursor_y];
//                 }
//             }
//         }
//     } else {
//         game_data.cursor_cooldown--;
//     }
// }

uint8_t game_iter(void) {



    // cursor_poll();
    game_flow_iter();
    
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
    game_flow_exit();
    fade_out();
    return 1;
}
