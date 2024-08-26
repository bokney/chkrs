
import sys

if len(sys.argv) <= 1:
    print("Expected 1 argument or more state names as arguments")
    exit()

args = sys.argv[1:]

words = [s.lower().split() for s in args]
print(words)
snake_case_list = ["_".join(i) for i in words]
camel_case_list = ["".join(x.capitalize() for x in i.lower().split("_")) for i in snake_case_list]
lower_camel_case_list = [i[0].lower() + i[1:] for i in camel_case_list]

print(snake_case_list)
print(camel_case_list)
print(lower_camel_case_list)

for arg in args:

    words = arg.lower().split()

    snake_case = "_".join(words)

    camel_case = "".join(x.capitalize() for x in snake_case.lower().split("_"))

    lower_camel_case = camel_case[0].lower() + camel_case[1:]

    c_contents = f"""
#include "{snake_case}.h"
#include "../fade.h"

typedef struct _{lower_camel_case}Data {{
    uint8_t count;
}} {lower_camel_case}Data;

{lower_camel_case}Data {snake_case}_data;

void {snake_case}_init(void) {{
    {snake_case}_data.count = 0;

    fade_in();
}}

uint8_t {snake_case}_iter(void) {{

    {snake_case}_data.count++;
    return 0;
}}

uint8_t {snake_case}_exit(void) {{

    fade_out();
    return 1;
}}
"""
    h_contents = f"""
#include <gb/gb.h>

void {snake_case}_init(void);
uint8_t {snake_case}_iter(void);
uint8_t {snake_case}_exit(void);
"""
 
    with open(file = f"{snake_case}.c", mode = "w") as f:
        f.write(c_contents)
        print(f"created {snake_case}.c")

    with open(file = f"{snake_case}.h", mode = "w") as f:
        f.write(h_contents)
        print(f"created {snake_case}.h")

define_states = ""
for i in range(len(lower_camel_case_list) - 1):
    define_states += f"\t{lower_camel_case_list[i]}State,\n"
define_states += f"\t{lower_camel_case_list[-1]}State;\n"

init_states = ""
for i in range(len(lower_camel_case_list)):
    init_states += f"""
state *init_{lower_camel_case_list[i]}State(void) {{
    {lower_camel_case_list[i]}State.step = 0;
    {lower_camel_case_list[i]}State.init = {snake_case_list[i]}_init;
    {lower_camel_case_list[i]}State.iter = {snake_case_list[i]}_iter;
    {lower_camel_case_list[i]}State.exit = {snake_case_list[i]}_exit;
    return &{lower_camel_case_list[i]}State;
}}
"""

game_state_includes = ""
for i in range(len(snake_case_list)):
    game_state_includes += f'#include "game_states/{snake_case_list[i]}.h"\n'

game_state_c = f"""
#include <gb/gb.h>
#include "game_states.h"
"""
game_state_c += game_state_includes
game_state_c += """

state
"""
game_state_c += define_states
game_state_c += init_states

extern_states = ""
declare_states = ""
for i in range(len(lower_camel_case_list)):
    extern_states += f"extern state {lower_camel_case_list[i]}State;\n"
    declare_states += f"state *init_{lower_camel_case_list[i]}State(void);\n"

game_state_h = """
#include "stateManager.h"

"""
game_state_h += extern_states
game_state_h += "\n"
game_state_h += declare_states
# + f"{["\n\t" + i + "," for i in snake_case_list]}"
# + "\b;\n\n"
# + f"{"state *init_(void)"}"
#     {[s + ",\n\t" for s in snake_case_list]}\b\;

# state *init_splashState(void) {
#     # splashState.step = 0;
#     # splashState.init = 
# }


with open(file = "game_states.c", mode = "w") as f:
    f.write(game_state_c)
    print("created game_states.c")

with open(file = "game_states.h", mode = "w") as f:
    f.write(game_state_h)
    print("created game_states.h")

main_c = """
#include <gb/gb.h>
#include <gb/crash_handler.h>
#include "game_states.h"

void main(void) {

"""

invoke_inits = ""
for i in range(len(lower_camel_case_list)):
    invoke_inits += f"\tinit_{lower_camel_case_list[i]}State();\n"

main_c += invoke_inits
main_c += f"""
    state *currentState = &{lower_camel_case_list[0]}State;
    
    for (;;) {{
        switch (runState(currentState)) {{
            case 0:
                break;
"""

cases = ""
for i in range(len(lower_camel_case_list)):
    cases += f"\t\t\tcase {i + 1}:\n\t\t\t\tcurrentState = &{lower_camel_case_list[i]}State;\n\t\t\t\tbreak;\n"
main_c += cases
main_c += "\t\t\tdefault:\n\t\t\t\t__HandleCrash();\n\t\t}\n\t}\n}\n"

with open(file = "main.c", mode = "w") as f:
    f.write(main_c)
    print("created main.c")