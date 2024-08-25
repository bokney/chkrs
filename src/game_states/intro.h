
#include <gb/gb.h>

typedef struct _introData introData;

extern introData intro_data;

void intro_init(void *data);
uint8_t intro_iter(void *data);
uint8_t intro_exit(void *data);
