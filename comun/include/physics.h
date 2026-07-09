#ifndef PHYSICS_H
#define PHYSICS_H

typedef struct Vector2 {
    float x;
    float y;
} Vector2;

typedef struct {    // The abstract part of an object for the physics
    Vector2 position;
    Vector2 velocity;
    Vector2 acceleration;
    float mass;
} Body;

typedef struct {    // The body + the graphical part of a circle
    Body *body;
    float radius;
} Circle;

void EdgeCollisionCircle(Circle *circle, int width, int height);

void UpdateBody(Body *self, float dt);

#endif