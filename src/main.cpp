#include <iostream>
#include <SDL.h>
#include "Game.h"
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>

// 防止main函数被SDL2库重定义
#undef main

int main()
{
    Game game;
    game.run();
    return 0;
}