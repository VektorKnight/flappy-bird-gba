/*
Current a dumping ground for all things graphics.
Just gonna be a bunch of helpful definitions and utility functions.
*/
#include <gba_video.h>

// Define the display control register and the correct display modes we want.
#define REG_DISPLAYCONTROL *((volatile u32*)(0x04000000))
#define VIDEOMODE_3         0x0003
#define BGMODE_2            0x0400

// Define the screen buffer address and dimensions.
#define SCREENBUFFER        ((volatile u16*)0x06000000)
#define SCREEN_W            240
#define SCREEN_H            160

// Simplest possible vsync. 
// TODO: This is pretty terrible.
inline void VSync() {
    while (REG_VCOUNT >= 160);
    while (REG_VCOUNT < 160);
}

// Makes a 15 bit color for the GBA to display properly in bitmap mode.
inline u16 MakeColor(u8 red, u8 green, u8 blue) {
    return red | green << 5 | blue << 10;
}

// Draws a rectangle to the screen.
// Must be in a bitmap graphics mode, usually mode 3.
void DrawRect(int left, int top, int width, int height, u16 color) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
    	   SCREENBUFFER[(top + y) * SCREEN_W + left + x] = color;
        }
    }
}