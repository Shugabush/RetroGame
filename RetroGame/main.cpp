/*******************************************************************************************
*
*   raylib [core] example - Basic window
*
*   Welcome to raylib!
*
*   To test examples, just press F6 and execute raylib_compile_execute script
*   Note that compiled executable is placed in the same folder as .c file
*
*   You can find all basic examples on C:\raylib\raylib\examples folder or
*   raylib official webpage: www.raylib.com
*
*   Enjoy using raylib. :)
*
*   Example originally created with raylib 1.0, last time updated with raylib 1.0
*
*   Example licensed under an unmodified zlib/libpng license, which is an OSI-certified,
*   BSD-like license that allows static linking with closed source software
*
*   Copyright (c) 2013-2022 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include <iostream>
#include <list>
#include <vector>

#include "raylib.h"
#include "GameObject.h"
#include "GameManager.h"
#include "Player.h"
#include "Barrier.h"
#include "Utility.h"
#include "Enemy.h"

const int screenWidth = 600;
const int screenHeight = 600;

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main()
{
    // Initialization
    //--------------------------------------------------------------------------------------

    //StartGame();

    InitWindow(screenWidth, screenHeight, "Space Invaders");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    Start();

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------
        switch (gameState)
        {
        case PENDING:
            GameManager::pendingScreen->Update();
            break;
        case ACTIVE:
            Update();
            break;
        case VICTORY:
            GameManager::winScreen->Update();
            break;
        case DEFEAT:
            GameManager::loseScreen->Update();
            break;
        }
        

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);

        Draw();

        switch (gameState)
        {
        case PENDING:
            GameManager::pendingScreen->Draw();
            break;
        case VICTORY:
            GameManager::winScreen->Draw();
            break;
        case DEFEAT:
            GameManager::loseScreen->Draw();
            break;
        }

        EndDrawing();

        ProcessPendingObjects();
        DestroyObjects();

        //----------------------------------------------------------------------------------
    }

    Quit();

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}