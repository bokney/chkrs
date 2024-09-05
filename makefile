
CC = /opt/gbdk/bin/lcc
CFLAGS = #-Wa-l -Wl-m -Wl-j
MFLAGS = #-Wl-yt1 -Wl-yo4 -Wl-ya0

all: build open clean

build:
	$(CC) $(CFLAGS) -c -o sfx.o src/utils/sfx.c
	$(CC) $(CFLAGS) -c -o gfx.o src/gfx/gfx.c
	$(CC) $(CFLAGS) -c -o fade.o src/utils/fade.c

	$(CC) $(CFLAGS) -c -o select.o src/game_states/game/flow_states/select.c
	$(CC) $(CFLAGS) -c -o pass.o src/game_states/game/flow_states/pass.c
	$(CC) $(CFLAGS) -c -o declare.o src/game_states/game/flow_states/declare.c
	$(CC) $(CFLAGS) -c -o drop.o src/game_states/game/flow_states/drop.c
	$(CC) $(CFLAGS) -c -o jump.o src/game_states/game/flow_states/jump.c
	$(CC) $(CFLAGS) -c -o crown.o src/game_states/game/flow_states/crown.c
	$(CC) $(CFLAGS) -c -o capture.o src/game_states/game/flow_states/capture.c
	$(CC) $(CFLAGS) -c -o handover.o src/game_states/game/flow_states/handover.c
	$(CC) $(CFLAGS) -c -o end.o src/game_states/game/flow_states/end.c

	$(CC) $(CFLAGS) -c -o view.o src/game_states/game/view.c
	$(CC) $(CFLAGS) -c -o flow_states.o src/game_states/game/flow_states.c
	$(CC) $(CFLAGS) -c -o flow_manager.o src/game_states/game/flow_manager.c

	$(CC) $(CFLAGS) -c -o splash.o src/game_states/splash.c
	$(CC) $(CFLAGS) -c -o intro.o src/game_states/intro.c
	$(CC) $(CFLAGS) -c -o main_menu.o src/game_states/main_menu.c
	$(CC) $(CFLAGS) -c -o game_intro.o src/game_states/game_intro.c
	$(CC) $(CFLAGS) -c -o game.o src/game_states/game.c
	$(CC) $(CFLAGS) -c -o lose.o src/game_states/lose.c
	$(CC) $(CFLAGS) -c -o win.o src/game_states/win.c
	$(CC) $(CFLAGS) -c -o settings.o src/game_states/settings.c
	$(CC) $(CFLAGS) -c -o stateManager.o src/utils/stateManager/stateManager.c
	$(CC) $(CFLAGS) -c -o game_states.o src/game_states.c

	$(CC) $(CFLAGS) -c -o main.o src/main.c

	$(CC) $(MFLAGS) -o output.gb main.o game_states.o stateManager.o settings.o win.o lose.o game.o game_intro.o main_menu.o intro.o splash.o flow_manager.o flow_states.o view.o end.o handover.o capture.o crown.o jump.o drop.o declare.o pass.o select.o fade.o gfx.o sfx.o

open:
	open -a /Applications/SameBoy.app output.gb

clean:
	rm -rf ./*.asm ./*.ihx ./*.lst ./*.o ./*.sym
