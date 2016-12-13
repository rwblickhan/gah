//
// Created by Russell Blickhan on 12/12/16.
//

#include <GameWorld.h>
#include <SDL_events.h>
#include <SDL.h>
#include <iostream>

GameWorld::GameWorld()
{

}

GameWorld::~GameWorld()
{

}

void GameWorld::Setup() {
    if (SDL_Init(SDL_INIT_VIDEO))
    {
        std::cout << "SDL_Init error: " << SDL_GetError() << std::endl;
    }
    m_pMainWindow = SDL_CreateWindow("Main Window", 100, 100, 640, 400, SDL_WINDOW_SHOWN);
    if (m_pMainWindow == nullptr)
    {
        std::cout << "SDL_CreateWindow error: " << SDL_GetError() << std::endl;
        Deinit();
    }
    m_pRen = SDL_CreateRenderer(m_pMainWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (m_pRen == nullptr)
    {
        std::cout << "SDL_CreateRenderer error: " << SDL_GetError() << std::endl;
        Deinit();
    }
}

void GameWorld::Deinit() {
    if (m_pRen)
    {
        SDL_DestroyRenderer(m_pRen);
    }
    if (m_pMainWindow)
    {
        SDL_DestroyWindow(m_pMainWindow);
    }
    SDL_Quit();
}

void GameWorld::Run() {
    m_running = true;
    while (m_running)
    {
        HandleInput();
        Update();
        Render();
    }
}

void GameWorld::HandleInput() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_KEYDOWN:
                if (event.key.keysym.sym == SDLK_q) m_running = false;
                break;
            case SDL_QUIT:
                m_running = false;
                break;
        }
    }
}

void GameWorld::Update() {
    for (auto& entity : m_entityList)
    {
        entity->Update();
    }
}

void GameWorld::Render() {



    for (auto& entity : m_entityList)
    {
        entity->Render();
    }
}