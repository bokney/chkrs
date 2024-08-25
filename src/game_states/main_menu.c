
#include "main_menu.h"
#include "../fade.h"

typedef struct _mainMenuData {
    uint8_t count;
} mainMenuData;

mainMenuData main_menu_data;

void main_menu_init(void *data) {
    mainMenuData *data_ptr = data;
    data_ptr->count = 0;
    fade_in();
}

uint8_t main_menu_iter(void *data) {
    mainMenuData *data_ptr = data;

    return 0;
}

uint8_t main_menu_exit(void *data) {
    mainMenuData *data_ptr = data;
    fade_out();
    return 1;
}
