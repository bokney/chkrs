
#include "capture.h"

typedef struct _captureData {
    uint8_t count;
} captureData;

captureData capture_data;

void capture_init(void) {
    capture_data.count = 0;

}

uint8_t capture_iter(void) {

    capture_data.count++;
    return 0;
}

uint8_t capture_exit(void) {

    return 1;
}
