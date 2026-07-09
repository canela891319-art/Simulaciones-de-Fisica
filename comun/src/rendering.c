#include "rendering.h"

void DrawCircleStruct(Circle circle, Color color) { 
    DrawCircle(circle.body->position.x, circle.body->position.y, circle.radius, color);
}

