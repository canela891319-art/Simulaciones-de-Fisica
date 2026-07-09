#include "interaction.h"

bool DragCircleMouse(Circle *circle, Vector2 mousePosition, Vector2 mouseDelta, float deltaTime) {

    static bool isDragging = false;

    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        if (CheckCollisionPointCircle(mousePosition, circle->body->position, circle->radius + 40.0f)) {
            isDragging = true;
        }
    }

    if (isDragging) {
        if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
            
            if (deltaTime > 0) {
                circle->body->velocity.x = (float) mouseDelta.x / deltaTime;
                circle->body->velocity.y = (float) mouseDelta.y / deltaTime;
                circle->body->position.x = mousePosition.x;
                circle->body->position.y = mousePosition.y;
            }
            return true;
        } else {
            isDragging = false;
        }
    }
    return false;
}