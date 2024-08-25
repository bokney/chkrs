
#include <gb/gb.h>

typedef struct _state {
    uint8_t step;
    void (*init)(void *data);
    uint8_t (*iter)(void *data);
    uint8_t (*exit)(void *data);
    void *data;
} state;

uint8_t runState(state *state);