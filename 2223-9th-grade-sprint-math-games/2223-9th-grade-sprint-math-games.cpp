#include <iostream>
#include <raylib.h>
using namespace std;

//Menu function
int main()
{
    InitWindow(800, 800, "twenty-one");
    while(!WindowShouldClose())
    {
        BeginDrawing();
        DrawText("twenty-one", 240, 350, 10, DARKGRAY);
        EndDrawing();
    }
}