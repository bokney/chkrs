
#include <gb/gb.h>

typedef struct _loseData loseData;

extern loseData lose_data;

void lose_init(void *data);
uint8_t lose_iter(void *data);
uint8_t lose_exit(void *data);
