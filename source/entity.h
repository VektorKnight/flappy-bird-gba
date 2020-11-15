#include <stdbool.h>
#include "collision.h"

// Entity definition.
// For now just a bounding box and velocity.
// Will be stored in a table aligned with OAM.
typedef struct {
    Rect bounds;   // Bounding rect of the entity.
    char vX, vY;   // Velocity of the entity in pixels/frame.
} Entity;