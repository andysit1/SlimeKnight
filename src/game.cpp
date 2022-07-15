#include "../headers/game.h"
#include "../headers/Player.h"
#include <assert.h>

Player player;

Game::Game(int width, int height, int fps, const char* title)
{
  assert(!GetWindowHandle());
  SetTargetFPS(fps);
  InitWindow(width, height,title);
}

Game::~Game() noexcept
{
  player.unloadTextures();
  assert(GetWindowHandle());
  CloseWindow();
}

bool Game::isGameRunning() const
{
  return WindowShouldClose();
}

void Game::InitGame()
{
 player.init();
}

void Game::Update()
{
  ClearBackground(RAYWHITE);
  player.update();
}

void Game::Draw()
{
  player.draw();
  player.playerAnimation();
}

void Game::tick()
{
  BeginDrawing();
  Update();
  Draw();
  EndDrawing();
}
