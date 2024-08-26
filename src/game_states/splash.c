
#include "splash.h"
#include "../fade.h"

typedef struct _splashData {
    uint8_t count;
} splashData;

splashData splash_data;

void splash_init(void) {
    splash_data.count = 0;

    fade_in();
}

uint8_t splash_iter(void) {

    splash_data.count++;
    return 0;
}

uint8_t splash_exit(void) {

    fade_out();
    return 1;
}
