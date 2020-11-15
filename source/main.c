#include <gba_console.h>
#include <gba_interrupt.h>
#include <gba_systemcalls.h>
#include <gba_input.h>
#include <stdio.h>
#include <stdlib.h>

// My terrible stuff.
#include "graphics.h"

// Just some convenience types.
int main(void) {
	// Configure the video hardware.
	REG_DISPLAYCONTROL = VIDEOMODE_3 | BGMODE_2;

	for (int i = 0; i < SCREEN_W * SCREEN_H; i++) {
		SCREENBUFFER[i] = MakeColor(0,0,0);
	}

	int x = 0;
	int stop = (SCREEN_W * SCREEN_H) / 10;
	while (1) { 
		// Wait for vertical sync.
		VSync();

		if (x < stop) {
			DrawRect(x % SCREEN_W, (x / SCREEN_W) * 10, 10, 10, MakeColor(x % 31, 2, x % 31));
			x += 10;
		}
	}

	return 0;
}


