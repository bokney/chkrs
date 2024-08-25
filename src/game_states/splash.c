
#include "splash.h"
#include "../fade.h"

typedef struct _splashData {
    uint8_t count;
} splashData;

splashData splash_data;

void splash_init(void *data) {
    splashData *data_ptr = data;
    data_ptr->count = 0;
    fade_in();
}

uint8_t splash_iter(void *data) {
    splashData *data_ptr = data;

    return 0;
}

uint8_t splash_exit(void *data) {
    splashData *data_ptr = data;
    fade_out();
    return 1;
}
