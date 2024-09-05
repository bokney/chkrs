
#include <gb/gb.h>

typedef struct _state {
    uint8_t step;
    void (*init)(void);
    uint8_t (*iter)(void);
    uint8_t (*exit)(void);
} state;

uint8_t runState(state *state);