
#include <gb/gb.h>

typedef struct _settingsData settingsData;

extern settingsData settings_data;

void settings_init(void *data);
uint8_t settings_iter(void *data);
uint8_t settings_exit(void *data);
