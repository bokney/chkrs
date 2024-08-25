
CC = /opt/gbdk/bin/lcc
CFLAGS = #-Wa-l -Wl-m -Wl-j
MFLAGS = #-Wl-yt1 -Wl-yo4 -Wl-ya0

all: build open clean

build:
	# $(CC) $(CFLAGS) -c -o gfx.o data/gfx.s
	$(CC) $(CFLAGS) -c -o gfx.o src/gfx/gfx.c
	$(CC) $(CFLAGS) -c -o fade.o src/fade.c
	$(CC) $(CFLAGS) -c -o splash.o src/game_states/splash.c
	$(CC) $(CFLAGS) -c -o intro.o src/game_states/intro.c
	$(CC) $(CFLAGS) -c -o main_menu.o src/game_states/main_menu.c
	$(CC) $(CFLAGS) -c -o game_intro.o src/game_states/game_intro.c
	$(CC) $(CFLAGS) -c -o game.o src/game_states/game.c
	$(CC) $(CFLAGS) -c -o lose.o src/game_states/lose.c
	$(CC) $(CFLAGS) -c -o win.o src/game_states/win.c
	$(CC) $(CFLAGS) -c -o settings.o src/game_states/settings.c
	$(CC) $(CFLAGS) -c -o stateManager.o src/stateManager.c
	$(CC) $(CFLAGS) -c -o game_states.o src/game_states.c
	$(CC) $(CFLAGS) -c -o main.o src/main.c
	$(CC) $(MFLAGS) -o output.gb main.o game_states.o stateManager.o settings.o win.o lose.o game.o game_intro.o main_menu.o intro.o splash.o fade.o gfx.o #gfx.o

open:
	open -a /Applications/SameBoy.app output.gb

clean:
	rm -rf ./*.asm ./*.ihx ./*.lst ./*.o ./*.sym
