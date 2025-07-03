#ifndef GAME_H

#include <SDL.h>

// 主入口
class Game
{
public:
    Game();
    ~Game();
    void init();
    void update();
    void run();
    void clean();

private:
    SDL_Window *m_window = nullptr;
    SDL_Renderer *m_renderer = nullptr;
    bool running = true;
    int m_windowWidth = 800;
    int m_windowHeight = 600;
};
#endif