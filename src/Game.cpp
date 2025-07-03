#include "Game.h"
#include <SDL.h>

Game::Game()
{
    SDL_Log("Game::Game()");
}

Game::~Game()
{
    SDL_Log("Game::~Game()");
    clean();
}

void Game::init()
{
    // 初始化 SDL2 库
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        SDL_Log("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
        exit(1);
    }
    // 初始化窗口
    m_window = SDL_CreateWindow("SDL2 Shooter", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                m_windowWidth, m_windowHeight, SDL_WINDOW_SHOWN);
    if (m_window == nullptr)
    {
        SDL_Log("Window could not be created! SDL Error: %s\n", SDL_GetError());
        exit(1);
    }
    // 初始化渲染器
    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
    if (m_renderer == nullptr)
    {
        SDL_Log("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
        exit(1);
    }
}

void Game::update()
{
}

void Game::run()
{
    // init sdl2
    init();
    while (running)
    {
        SDL_Event event;
        if (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                running = false;
            }
            update();
        }
        SDL_RenderClear(m_renderer);
        SDL_RenderPresent(m_renderer);
    }
}

void Game::clean()
{
    if (m_renderer != nullptr)
    {
        SDL_DestroyRenderer(m_renderer);
    }
    if (m_window != nullptr)
    {
        SDL_DestroyWindow(m_window);
    }
    SDL_Quit();
}
