/*
All the stuffs for super-basic bounding rect collisions.
*/
#include <stdlib.h>
#include <stdbool.h>

// Super basic bounding rect.
// Defined as min/max so we can just use the sprite origin as the minimum (upper-left).
typedef struct {
    unsigned char x1, y1;   // The upper-left corner (min).
    unsigned char x2, y2;   // The lower-right corner (max).
} Rect;

// Checks if a rect contains a given point.
inline bool contains_point(const Rect* rect, unsigned char x, unsigned char y) {
    return (x > rect->x1 && x < rect->x2)
        && (y > rect->y1 && y < rect->y2); 
}

// Checks if two rects are intersecting.
inline bool check_intersection(const Rect* a, const Rect* b) {
    return (a->x1 < b->x2 && a->x2 > b->x1)
        && (a->y1 < b->y2 && a->y2 > b->y1);
}