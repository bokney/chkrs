
#include <gb/gb.h>

void init_sound(void) {
    NR52_REG=0x80;
    NR50_REG=0x77;
    NR51_REG=0xFF;
}

void snd_nuhuh(void) {
    NR10_REG=0x6A;
    NR11_REG=0x86;
    NR12_REG=0x82;
    NR13_REG=0xA6;
    NR14_REG=0x82;
}

void snd_bleoop(void) {
    NR10_REG=0x5E;
    NR11_REG=0x3F;
    NR12_REG=0x61;
    NR13_REG=0x06;
    NR14_REG=0x87;
}

void snd_fall_down(void) {
    NR10_REG=0x5F;
    NR11_REG=0x81;
    NR12_REG=0xC7;
    NR13_REG=0x06;
    NR14_REG=0x87;
}

void snd_star_fall(void) {
    NR10_REG=0x7F;
    NR11_REG=0x46;
    NR12_REG=0xC7;
    NR13_REG=0xFF;
    NR14_REG=0x87;
}
