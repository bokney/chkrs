
#include "jump.h"

typedef struct _jumpData {
    uint8_t count;
} jumpData;

jumpData jump_data;

void jump_init(void) {
    jump_data.count = 0;

}

uint8_t jump_iter(void) {

    jump_data.count++;
    return 0;
}

uint8_t jump_exit(void) {

    return 1;
}
