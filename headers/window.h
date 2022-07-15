#include "raylib.h"

namespace game{ namespace graphics{

class Window{
public:
  Window(int width, int height, int fps, const char* title);
  ~Window() noexcept;

  bool isWindowUp();
  bool isWindowRunning() const;
  void InitGame(void);
  void Tick();

private:
  void Draw();
  void Update();
};

}}