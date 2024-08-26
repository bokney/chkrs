
#include "drop.h"

typedef struct _dropData {
    uint8_t count;
} dropData;

dropData drop_data;

void drop_init(void) {
    drop_data.count = 0;

}

uint8_t drop_iter(void) {

    drop_data.count++;
    return 0;
}

uint8_t drop_exit(void) {

    return 1;
}
