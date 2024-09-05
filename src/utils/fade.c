
#include <gb/gb.h>

uint8_t fadeStage;

void fade_out(void) {
    fadeStage = 0;
    while (1) {
        switch(fadeStage) {
            case 0: BGP_REG = 0xE4; break;
            case 1: BGP_REG = 0x90; break;
            case 2: BGP_REG = 0x40; break;
            case 3: BGP_REG = 0x00; break;
        }
        fadeStage++;
        if (fadeStage == 4) break;
        delay(80);
        wait_vbl_done();
    }
}

void fade_in(void) {
    fadeStage = 0;
    while (1) {
        switch(fadeStage) {
            case 0: BGP_REG = 0x00; break;
            case 1: BGP_REG = 0x40; break;
            case 2: BGP_REG = 0x90; break;
            case 3: BGP_REG = 0xE4; break;
        }
        fadeStage++;
        if (fadeStage == 4) break;
        delay(80);
        wait_vbl_done();
    }
}