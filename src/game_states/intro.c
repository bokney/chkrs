
#include "intro.h"
#include "../fade.h"

typedef struct _introData {
    uint8_t count;
} introData;

introData intro_data;

void intro_init(void) {
    intro_data.count = 0;

    fade_in();
}

uint8_t intro_iter(void) {

    intro_data.count++;
    return 0;
}

uint8_t intro_exit(void) {

    fade_out();
    return 1;
}
