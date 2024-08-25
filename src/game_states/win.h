
#include <gb/gb.h>

typedef struct _winData winData;

extern winData win_data;

void win_init(void *data);
uint8_t win_iter(void *data);
uint8_t win_exit(void *data);
