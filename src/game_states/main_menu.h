
#include <gb/gb.h>

typedef struct _mainMenuData mainMenuData;

extern mainMenuData main_menu_data;

void main_menu_init(void *data);
uint8_t main_menu_iter(void *data);
uint8_t main_menu_exit(void *data);
