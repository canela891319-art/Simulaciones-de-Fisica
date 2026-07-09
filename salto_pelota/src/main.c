#include "raylib.h"
#include "rendering.h"
#include "physics.h"
#include "interaction.h"

#include <stdlib.h>


int main() 
{

    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    
    const int windowHeight = 400;
    const int windowWidth = 600;

    InitWindow(windowWidth, windowHeight, "Simulacion Fisica 1: Salto pelota");

    SetTargetFPS(60);
    
    Body circleBody = {
        {(float) windowWidth / 2, (float) windowHeight / 2},
        { 0.0f , 0.0f },
        { 0.0f , 1000.0f},
        .mass = 10.0f
    };

    Circle circle = {
        &circleBody,
        40.0f
    };

    float deltaTime;
    Vector2 gravitForce;

    while (!WindowShouldClose)
    {
        deltaTime = GetFrameTime();

        if (!DragCircleMouse(&circle, GetMousePosition(), GetMouseDelta(), deltaTime))
        {
            UpdateBody(&circleBody, deltaTime);
        }
        
        

        EdgeCollisionCircle(&circle, GetScreenWidth(), GetScreenHeight());

        BeginDrawing();

            ClearBackground(RAYWHITE);
            
            // DrawLineV(circleBody.position, )
            DrawCircleStruct(circle, BLUE);

        EndDrawing();    

    }

    CloseWindow();

    return 0;
}
