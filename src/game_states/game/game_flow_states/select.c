
#include "select.h"

typedef struct _selectData {
    uint8_t count;
} selectData;

selectData select_data;

void select_init(void) {
    select_data.count = 0;

}

uint8_t select_iter(void) {

    select_data.count++;
    return 0;
}

uint8_t select_exit(void) {

    return 1;
}
