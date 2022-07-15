#include <raylib.h>
#include <stdio.h>

struct Entity
{
public:
  Entity();
  //animations
  int maxFrames = 6;
  int *frame;
  float *timer;
  virtual void tick();
  Texture2D texture{};
  Texture2D idle{};
  Texture2D run{};
  Vector2 position{};
  Vector2 speed{};
  Vector2 worldpos{};
  bool alive{true};
};


