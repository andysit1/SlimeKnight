#include <iostream>
#include "../headers/Player.h"
#include "../headers/settings.h"
#include "../include/raylib.h"

void Player::init()
{
  playerTexIdle = LoadTexture("E:/Projects/RayLib/SlimeKnight/resources/knight_idle_spritesheet.png");
  playerTexRun = LoadTexture("E:/Projects/RayLib/SlimeKnight/resources/knight_run_spritesheet.png");
  //weaponTex = LoadTexture("E:/Projects/RayLib/Testing Grounds/resources/Sword.png");
  texWidth = playerTexRun.width / maxFrame;
  texHeight = playerTexRun.height;
  position = {(float)SCREENWIDTH/2, (float)SCREENHEIGHT/2};
}

int frame;
int playerDir{1};
float timer;
bool isMoving{false};
bool shouldMove{false};

void Player::getInputs()
{
  if(IsKeyUp('A') || IsKeyUp('W') || IsKeyUp('S') || IsKeyUp('D'))
  {
    isMoving = false;
  }
  if (IsKeyDown('D'))
  {
    position.x += speed * deltatime;
    playerDir = 1;
    isMoving = true;
    shouldMove = true;
  }
  if (IsKeyDown('A'))
  {
    position.x -= speed * deltatime;
    playerDir = -1;
    isMoving = true;
    shouldMove = true;
  }
  if (IsKeyDown('W'))
  {
    position.y -= speed * deltatime;
    isMoving = true;
    shouldMove = true;
  }
  if (IsKeyDown('S'))
  {
    position.y += speed * deltatime;
    isMoving = true;
    shouldMove = true;
  }

  if(IsKeyDown('A') && IsKeyDown('D'))
  {
    shouldMove = false;
  }

  if(IsKeyDown('W') && IsKeyDown('S'))
  {
    shouldMove = false;
  }
}


void Player::playerAnimation()
{
  timer += deltatime;
  if (timer > 0.2f)
  {
    timer = 0.0f;
    frame += 1;
  }
  frame = frame % 6;

  if (isMoving && shouldMove)
  {
    DrawTexturePro(playerTexRun,
                Rectangle{(float)(texWidth * frame), 0.0f, playerDir * (float)texWidth, (float)texHeight},
                Rectangle{position.x, position.y, 100,  100},
                {50, 50},
                0.0f,
                RAYWHITE);
  }
  else
  {
    DrawTexturePro(playerTexIdle,
            Rectangle{(float)(texWidth * frame), 0.0f, playerDir * (float)texWidth, (float)texHeight},
            Rectangle{position.x, position.y, 100,  100},
            {50, 50},
            0.0f,
            RAYWHITE);
  }
}

void Player::unloadTextures()
{
  UnloadTexture(playerTexRun);
  UnloadTexture(playerTexIdle);
}

Vector2 Player::getPosition()
{
  return position;
}

void Player::update()
{
  getInputs();
}

void Player::draw()
{

}

