
#include "lose.h"
#include "../fade.h"

typedef struct _loseData {
    uint8_t count;
} loseData;

loseData lose_data;

void lose_init(void *data) {
    loseData *data_ptr = data;
    data_ptr->count = 0;
    fade_in();
}

uint8_t lose_iter(void *data) {
    loseData *data_ptr = data;

    return 0;
}

uint8_t lose_exit(void *data) {
    loseData *data_ptr = data;
    fade_out();
    return 1;
}
