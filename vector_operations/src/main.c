#include <stdlib.h>
#include "raylib.h"

#include "math1.h"
#include "physics.h"
#include "rendering.h"
#include "interaction.h"


int main(void) {
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    
    const int windowHeight = 400;
    const int windowWidth = 600;

    InitWindow(windowWidth, windowHeight, "Simulacion Fisica 2: Vector Operations");
    
    SetTargetFPS(60);
    
    Vector2 windowSize = {windowWidth, windowHeight};

    while (!WindowShouldClose()) {

        windowSize = (Vector2){GetScreenWidth(), GetScreenHeight()};
        BeginDrawing();

            ClearBackground(RAYWHITE);

            DrawCoordinatePlane((Vector2){GetScreenWidth() / 2, GetScreenHeight() / 2}, windowSize, 100, BLACK, BLUE);

        EndDrawing();
    }
    
    CloseWindow();
    
}