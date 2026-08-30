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

    Vector2Math vectorArray[] = {
        {150.0f, 200.0f},
        {-200.0f, -50.0f},
        {0.0f, 0.0f}
    };
    
    vectorArray[2] = VectorAddittion(vectorArray, sizeof(vectorArray) / sizeof(vectorArray[0]));
    Vector2 *vectorGraphArray = Vector2ToMathVector(vectorArray, sizeof(vectorArray) / sizeof(vectorArray[0]));
    
    bool mouseInWindow = false;
    Vector2 vectorMouse = (Vector2){windowSize.x / 2, windowSize.y / 2};
    while (!WindowShouldClose()) {
        Vector2 origin = {GetScreenWidth() / 2, GetScreenHeight() / 2};

        windowSize = (Vector2){GetScreenWidth(), GetScreenHeight()};
        if (GetMousePosition().x < windowSize.x && GetMousePosition().y < windowSize.y) {
            DragVector2(&vectorMouse, origin);
            mouseInWindow = true;
        }
        else {
            vectorMouse = origin;
            mouseInWindow = false;
        }
        
        BeginDrawing();

            ClearBackground(RAYWHITE);

            DrawCoordinatePlane(origin, windowSize, 100, BLACK, BLUE);

            DrawLineEx(origin, Vector2Addittion((Vector2[]){origin, vectorGraphArray[0]}, 2), 5.0f, RED);
            DrawLineEx(origin, Vector2Addittion((Vector2[]){origin, vectorGraphArray[1]}, 2), 5.0f, RED);
            DrawVector(origin, vectorGraphArray[2], 10.0f, GREEN);
             if (mouseInWindow) {DrawVector(origin, vectorMouse, 15.0f, GRAY);}

        EndDrawing();
    }
    
    CloseWindow();
    
}