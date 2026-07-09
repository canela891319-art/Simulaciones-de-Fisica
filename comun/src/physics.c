#include "physics.h"
#include <stdlib.h>

const float restitution = 0.8f;

void EdgeCollisionCircle(Circle *circle, int width, int height) {
    if (circle->body->position.x - circle->radius < 0) {
        circle->body->position.x = circle->radius;
        circle->body->velocity.x *= -restitution;
    }
    else if (circle->body->position.x + circle->radius > width) {
        circle->body->position.x = (float)width - circle->radius;
        circle->body->velocity.x *= -restitution;
    }

    if (circle->body->position.y - circle->radius < 0) {
        circle->body->position.y = circle->radius;
        circle->body->velocity.y *= -restitution;
    } 
    else if (circle->body->position.y + circle->radius >= height) {
        circle->body->position.y = (float)height - circle->radius;
        if (circle->body->velocity.y < 60.0f) {
            circle->body->velocity.y = 0.0f;
            circle->body->acceleration.y = 0.0f;
        }
        else {
            circle->body->velocity.y *= -restitution;
        }
    }
    else {
        circle->body->acceleration.y = 1000.0f;
    }
}

void UpdateBody(Body *self, float dt) {
    self->position.x +=  self->velocity.x * dt + 0.5f * self->acceleration.x * dt * dt;  // Position = x0 + v0*t + (a*t2)/2
    self->velocity.x += self->acceleration.x * dt;    // Velocity = v0 + a*t

    self->position.y +=  self->velocity.y * dt + 0.5f * self->acceleration.y * dt * dt;  // Position = x0 + v0*t + (a*t2)/2
    self->velocity.y += self->acceleration.y * dt;    // Velocity = v0 + a*t
}