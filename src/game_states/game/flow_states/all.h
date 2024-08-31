
#include <gb/gb.h>

void select_init(void);
uint8_t select_iter(void);
uint8_t select_exit(void);

void pass_init(void);
uint8_t pass_iter(void);
uint8_t pass_exit(void);

void declare_init(void);
uint8_t declare_iter(void);
uint8_t declare_exit(void);

void drop_init(void);
uint8_t drop_iter(void);
uint8_t drop_exit(void);

void jump_init(void);
uint8_t jump_iter(void);
uint8_t jump_exit(void);

void crown_init(void);
uint8_t crown_iter(void);
uint8_t crown_exit(void);

void capture_init(void);
uint8_t capture_iter(void);
uint8_t capture_exit(void);

void handover_init(void);
uint8_t handover_iter(void);
uint8_t handover_exit(void);

void end_init(void);
uint8_t end_iter(void);
uint8_t end_exit(void);
