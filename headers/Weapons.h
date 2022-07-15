#ifndef WEAPONS_H
#define WEAPONS_H

#include "settings.h"
#include <raylib.h>

struct Weapon{
  Texture2D texture;
  Weapon(Texture2D text){
    texture = text;
  }

  virtual void Attack();
};


struct Weapon{
  Texture2D weapon;
  virtual void Attack();
};



//-------------------------------------------
//PROJECTILES
struct Projectile
{
protected:
  Texture2D texture;
  Vector2 position;
  string name;
  float speed;
  int projectile_onscreen{1};
public:
  Projectile(int ammo){projectile_onscreen = ammo;}
  virtual void ProjectileInit();
  virtual void DrawProjectile(){};
  void update();
  void draw();
};

// --------------------------------------------------------
// BULLETS

struct Bullets : Projectile
{
  Bullets(int ammo) : Projectile(ammo){}

};

struct SmallBullets: Bullets{
  SmallBullets(int ammo) : Bullets(ammo){}
};

struct MediumBullets: Bullets{
  MediumBullets(int ammo) : Bullets(ammo){}
};

struct BigBullets: Bullets{
  BigBullets(int ammo) : Bullets(ammo){}
};

// --------------------------------------------------------
// ARROWS
struct Arrow : Projectile{
  Arrow(int ammo) : Projectile(ammo){}
};

struct BronzeArrow: Arrow{
  BronzeArrow(int ammo) : Arrow(ammo){}
};

struct SliverArrow: Arrow{
  SliverArrow(int ammo) : Arrow(ammo){}
};

struct GoldenArrow: Arrow{
  GoldenArrow(int ammo) : Arrow(ammo){}
};
// -------------------------------------------------------

#endif /* WEAPONS_H */