#ifndef PHYSICS_H
#define PHYSICS_H

typedef struct {    // An independent 2D vector struct
    float x;
    float y;
} Vector2Phy;

typedef struct {    // The abstract part of an object for the physics
    Vector2Phy position;
    Vector2Phy velocity;
    Vector2Phy acceleration;
    float mass;
} Body;

typedef struct {    // The body of a circle
    Body *body;
    float radius;
} Circle;

void EdgeCollisionCircle(Circle *circle, int width, int height);    // Makes sure circles collide with edges of the screen

void UpdateBody(Body *body, float dt);  // Updates each attribute of a body

#endif