
#include "win.h"
#include "../fade.h"

typedef struct _winData {
    uint8_t count;
} winData;

winData win_data;

void win_init(void *data) {
    winData *data_ptr = data;
    data_ptr->count = 0;
    fade_in();
}

uint8_t win_iter(void *data) {
    winData *data_ptr = data;

    return 0;
}

uint8_t win_exit(void *data) {
    winData *data_ptr = data;
    fade_out();
    return 1;
}
