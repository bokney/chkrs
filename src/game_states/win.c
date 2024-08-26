
#include "win.h"
#include "../fade.h"

typedef struct _winData {
    uint8_t count;
} winData;

winData win_data;

void win_init(void) {
    win_data.count = 0;

    fade_in();
}

uint8_t win_iter(void) {

    win_data.count++;
    return 0;
}

uint8_t win_exit(void) {

    fade_out();
    return 1;
}
