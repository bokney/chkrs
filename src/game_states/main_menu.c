
#include "main_menu.h"
#include "../fade.h"

typedef struct _mainMenuData {
    uint8_t count;
} mainMenuData;

mainMenuData main_menu_data;

void main_menu_init(void) {
    main_menu_data.count = 0;

    fade_in();
}

uint8_t main_menu_iter(void) {

    main_menu_data.count++;
    return 0;
}

uint8_t main_menu_exit(void) {

    fade_out();
    return 1;
}
