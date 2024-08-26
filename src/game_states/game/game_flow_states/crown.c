
#include "crown.h"

typedef struct _crownData {
    uint8_t count;
} crownData;

crownData crown_data;

void crown_init(void) {
    crown_data.count = 0;

}

uint8_t crown_iter(void) {

    crown_data.count++;
    return 0;
}

uint8_t crown_exit(void) {

    return 1;
}
