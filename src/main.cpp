#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>

// 防止main函数被SDL2库重定义
#undef main

int main()
{
    // 初始化SDL2库
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        SDL_Log("SDL_Init Error: %s", SDL_GetError());
        return -1;
    }
    // 创建窗口
    SDL_Window *window = SDL_CreateWindow("SDL2Shooter", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
    if (window == nullptr)
    {
        SDL_Log("SDL_CreateWindow Error: %s", SDL_GetError());
        return -1;
    }
    // 创建渲染器
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr)
    {
        SDL_Log("SDL_CreateRenderer Error: %s", SDL_GetError());
        return -1;
    }

    // 初始化SDL_image库
    int imgFlag = IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);
    if (imgFlag & (IMG_INIT_PNG | IMG_INIT_JPG) != (IMG_INIT_PNG | IMG_INIT_JPG))
    {
        SDL_Log("IMG_Init Error: %s", IMG_GetError());
        return -1;
    }
    // 加载图片
    SDL_Surface *imageSurface = IMG_Load("assets/image/bg.png");
    if (imageSurface == nullptr)
    {
        SDL_Log("IMG_Load Error: %s", IMG_GetError());
        return -1;
    }
    // 创建纹理
    SDL_Texture *imageTexture = SDL_CreateTextureFromSurface(renderer, imageSurface);
    if (imageTexture == nullptr)
    {
        SDL_Log("SDL_CreateTextureFromSurface Error: %s", SDL_GetError());
        return -1;
    }

    // 加载音频文件
    int musicFlag = Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
    if (musicFlag != 0)
    {
        SDL_Log("Mix_OpenAudio Error: %s", Mix_GetError());
        return -1;
    }
    // 加载本地音频文件
    Mix_Music *music = Mix_LoadMUS("assets/music/1.mp3");
    if (music == nullptr)
    {
        SDL_Log("Mix_LoadMUS Error: %s", Mix_GetError());
        return -1;
    }

    // 播放音乐, -1表示循环播放
    Mix_PlayMusic(music, -1);

    // 设置渲染器颜色，清屏
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderClear(renderer);

    // 矩形框配置
    SDL_Rect rect = {100, 100, 50, 50};
    SDL_Rect fillRect = {150, 150, 100, 100};

    SDL_Rect imgDstRect = {300, 300, 100, 100};

    // 主循环
    bool isRunning = true;
    SDL_Event event;
    while (isRunning)
    {
        // SDL 退出事件，响应窗口关闭
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                isRunning = false;
                break;
            }
        }

        // 绘制矩形框
        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
        SDL_RenderDrawRect(renderer, &rect);

        // 填充矩形
        SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
        SDL_RenderFillRect(renderer, &fillRect);

        // 绘制图片纹理
        SDL_RenderCopy(renderer, imageTexture, nullptr, &imgDstRect);

        // 交换缓冲区
        SDL_RenderPresent(renderer);
    }

    // 释放音频资源
    Mix_FreeMusic(music);
    Mix_CloseAudio();

    // 释放图片资源
    SDL_FreeSurface(imageSurface);
    SDL_DestroyTexture(imageTexture);
    // 释放SDL_image资源
    IMG_Quit();

    // 窗口关闭，销毁SDL2资源
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}