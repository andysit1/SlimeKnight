#include "../headers/settings.h"
#include "../headers/game.h"

int main(){
  Game game(SCREENWIDTH, SCREENHEIGHT , 100, "SandBox3");


  game.InitGame();
  while (!game.isGameRunning())    // Detect window close button or ESC key
  {
    game.tick();
  }

  CloseWindow();        // Close window and OpenGL context

  return 0;
}