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
#include "Player.h"
#include "Barrier.h"
#include "Utility.h"

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main()
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 600;
    const int screenHeight = 600;

    // Create and add the player
    Player* player = new Player(3);
    Texture2D playerSprite = LoadTexture("spaceship.png");
    player->sprite = &playerSprite;
    player->movementSpeed = 5;
    player->position = { screenWidth / 2, 400 };
    objects.push_back(player);

    // Create and add barriers
    Barrier* barrier1 = new Barrier(5);
    barrier1->name = "Barrier1";
    barrier1->position = { 125, 250 };
    barrier1->width = 100;
    barrier1->height = 25;
    Barrier* barrier2 = new Barrier(5);
    barrier2->name = "Barrier2";
    barrier2->position = { screenWidth / 2, 250 };
    barrier2->width = 100;
    barrier2->height = 25;
    Barrier* barrier3 = new Barrier(5);
    barrier3->name = "Barrier3";
    barrier3->position = { 475, 250 };
    barrier3->width = 100;
    barrier3->height = 25;
    objects.push_back(barrier1);
    objects.push_back(barrier2);
    objects.push_back(barrier3);

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
        Update();

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);

        Draw();

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