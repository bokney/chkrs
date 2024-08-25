
#include <gb/gb.h>

typedef struct _splashData splashData;

extern splashData splash_data;

void splash_init(void *data);
uint8_t splash_iter(void *data);
uint8_t splash_exit(void *data);
