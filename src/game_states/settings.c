
#include "settings.h"
#include "../fade.h"

typedef struct _settingsData {
    uint8_t count;
} settingsData;

settingsData settings_data;

void settings_init(void) {
    settings_data.count = 0;

    fade_in();
}

uint8_t settings_iter(void) {

    settings_data.count++;
    return 0;
}

uint8_t settings_exit(void) {

    fade_out();
    return 1;
}
