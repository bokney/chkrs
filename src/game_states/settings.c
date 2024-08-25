
#include "settings.h"
#include "../fade.h"

typedef struct _settingsData {
    uint8_t count;
} settingsData;

settingsData settings_data;

void settings_init(void *data) {
    settingsData *data_ptr = data;
    data_ptr->count = 0;
    fade_in();
}

uint8_t settings_iter(void *data) {
    settingsData *data_ptr = data;

    return 0;
}

uint8_t settings_exit(void *data) {
    settingsData *data_ptr = data;
    fade_out();
    return 1;
}
