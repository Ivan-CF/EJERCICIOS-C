#include "raylib.h"
 
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 1920;
    const int screenHeight = 1080;
   
    Color amarillo = { 255, 255, 0, 255 };
   
    Color cualquiera = { 242, 88, 17, 255 };
   
    int iniposx,iniposy,endposx,endposy = 0;
   
    iniposx = screenWidth/2;
    iniposy = 0;
   
    endposx = screenWidth/2;
    endposy = screenHeight;
   
    Vector2 vpos1, vpos2;
   
    vpos1.x = 0;
    vpos1.y = screenHeight/2;
   
    vpos2.x = screenWidth;
    vpos2.y = screenHeight/2;
   
    int rectanglex,rectangley, rectanglewidth,rectangleheight;
    rectanglewidth = 100;
    rectangleheight = 100;
    rectanglex = screenWidth/2 - rectanglewidth/2;
    rectangley = screenHeight/2 - rectangleheight/2;
   
    Vector2 posrec;
    posrec.x = screenWidth/2;
    posrec.y = screenHeight/2;
   
    Vector2 sizerec;
    sizerec.x = 100;
    sizerec.y = 100;
   
    posrec.x = posrec.x - sizerec.x /2;
    posrec.y = posrec.y - sizerec.y /2;
   
   
 
    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
 
    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------
 
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        if (IsKeyDown(KEY_Q)){
          vpos1.y -= 2.0f;
        }
       
        if (IsKeyDown(KEY_A)){
          vpos1.y += 2.0f;
        }
       
        if (IsKeyDown(KEY_W)){
          vpos2.y -= 2.0f;
        }
       
        if (IsKeyDown(KEY_S)){
          vpos2.y += 2.0f;
        }
       
        if (IsKeyDown(KEY_E)){
          iniposx -= 2.0f;
        }
       
        if (IsKeyDown(KEY_R)){
          iniposx += 2.0f;
        }
       
        if (IsKeyDown(KEY_D)){
          endposx -= 2.0f;
        }
       
        if (IsKeyDown(KEY_F)){
          endposx += 2.0f;
        }
        //----------------------------------------------------------------------------------
 
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
 
            ClearBackground(cualquiera);
 
            //DrawText("Congrats! You created your first window!", 190, 200, 20, PINK);
            //DrawText("JANDU", screenWidth/2 -50, screenHeight/2, 20, WHITE);
           
            DrawCircleGradient(screenWidth/2, screenHeight/2, 300, RED, YELLOW);
           
           
           
            DrawRectangle(rectanglex -150, rectangley -150, rectanglewidth, rectangleheight, SKYBLUE);
            DrawRectangle(rectanglex +150, rectangley -150, rectanglewidth, rectangleheight, SKYBLUE);
           
            DrawRectangleV(posrec, sizerec, SKYBLUE);
           
           
           
        EndDrawing();
        //----------------------------------------------------------------------------------
    }
 
    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------
 
    return 0;
}