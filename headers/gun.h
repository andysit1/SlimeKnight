#include <raylib.h>
#include <raymath.h>


// struct Bullet{
//   Vector2 position;
//   Vector2 current_speed;
//   float speed;
//   int radius;
//   bool active;
//   int lifeSpawn;
//   Color color;

//   void update();
//   void draw();
// };

struct Gun{
  Gun(Texture2D gunTex,  Vector2 position, Vector2 origin ,float rotation);

  Vector2 getTip();
  //Vector2 tip = getTip();
  Color color{RAYWHITE};
  Texture texture;
  int height{};
  int width{};
  float *rotations{};

  void update();
  void draw();
  void getRotations();
  float gunRotations{};
  Vector2 positionPlayer{};
  Vector2 gunPos{};
};
