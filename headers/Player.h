#ifndef PLAYER_H
#define PLAYER_H

#include "../include/raylib.h"
struct Player
{
  Vector2 position;
  float speed {250.0f};
  //Texture playertex;
  void getInputs();
  void init();
  void update();
  void draw();
  void unloadTextures();
  void playerAnimation();
  Vector2 getPosition();
  int maxFrame{6};

  Texture2D playerTexIdle{};
  Texture2D playerTexRun{};
  Texture2D weaponTex{};
  int texWidth{};
  int texHeight{};
};


#endif /* PLAYER_H */