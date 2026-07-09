#ifndef INTERACTION_H
#define INTERACTION_H

#include <stdbool.h>
#include <raylib.h>
#include "physics.h"

bool DragCircleMouse(Circle *circle, Vector2 mousePosition, Vector2 mouseDelta, float deltaTime);

#endif