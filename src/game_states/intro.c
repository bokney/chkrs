
#include "intro.h"
#include "../fade.h"

typedef struct _introData {
    uint8_t count;
} introData;

introData intro_data;

void intro_init(void *data) {
    introData *data_ptr = data;
    data_ptr->count = 0;
    fade_in();
}

uint8_t intro_iter(void *data) {
    introData *data_ptr = data;

    return 0;
}

uint8_t intro_exit(void *data) {
    introData *data_ptr = data;
    fade_out();
    return 1;
}
