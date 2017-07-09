//
// Created by Russell Blickhan on 12/12/16.
//

//std
#include <iostream>

//sdl
#include <SDL2/SDL_video.h>
#include <SDL2/SDL_events.h>
#include <SDL_image.h>

//gah
#include <GameWorld.h>
#include <TestMoustachioEntity.h>
#include <TestCookieEntity.h>

GameWorld::GameWorld()
    : m_entityList()
    , m_cache()
    , m_assetLoader()
    , m_running(false)
    , m_cursorPos()
    , m_mainWindow(SDL_CreateWindow("Main Window", 100, 100, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN),
                   [](SDL_Window* win){SDL_DestroyWindow(win);})
    , m_renderer(SDL_CreateRenderer(m_mainWindow.get(), -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC),
                 [](SDL_Renderer* ren){SDL_DestroyRenderer(ren);})
{

}

GameWorld::~GameWorld()
{

}

void GameWorld::Setup() {
    //TODO make this nicer
    std::string loadingPath = std::string(SDL_GetBasePath()) + "assets/loading.bmp";
    SDL_Surface* img = SDL_LoadBMP(loadingPath.c_str());
    if (img == nullptr) {
        std::cout << "SDL_LoadBMP Error: " << SDL_GetError() << std::endl;
        Deinit();
        return;
    }
    SDL_Texture* m_pTempTex = SDL_CreateTextureFromSurface(m_renderer.get(), img);
    SDL_FreeSurface(img);
    if (m_pTempTex == nullptr) {
        std::cout << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
        Deinit();
        return;
    }
    SDL_RenderClear(m_renderer.get());
    SDL_RenderCopy(m_renderer.get(), m_pTempTex, NULL, NULL);
    SDL_RenderPresent(m_renderer.get());

    if (!IMG_Init(IMG_INIT_PNG)) {
        std::cout << "Error: Couldn't init png loader, error: " << SDL_GetError() << std::endl;
    } else {
        std::cout << "Successfully initialized png loader" << std::endl;
    }

    m_assetLoader->LoadAssets(m_renderer.get(), m_cache);
    std::unique_ptr<GameEntity> moustachioEntity(new TestMoustachioEntity(m_cache));
    std::unique_ptr<GameEntity> cookieEntity(new TestCookieEntity(m_cache));
    m_entityList.push_back(std::move(moustachioEntity));
    m_entityList.push_back(std::move(cookieEntity));
}

void GameWorld::Deinit() {
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
            case SDL_MOUSEMOTION:
                SetCursorPos(event.motion.x, event.motion.y);
                break;
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
        entity->Update(static_cast<WorldStateUpdateCallback*>(this));
    }
}

void GameWorld::Render() {

    SDL_SetRenderDrawColor(m_renderer.get(), 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(m_renderer.get());
    for (auto& entity : m_entityList)
    {
        entity->Render(static_cast<WorldStateRenderCallback*>(this), m_renderer.get());
    }
    SDL_RenderPresent(m_renderer.get());
}

void GameWorld::SetCursorPos(int x, int y) {
    m_cursorPos.x = x;
    m_cursorPos.y = y;
}

WindowPos GameWorld::GetCursorPos() {
    return m_cursorPos;
}

Quadrant GameWorld::GetCursorQuadrant() {
    if (m_cursorPos.x < SCREEN_WIDTH / 2 && m_cursorPos.y < SCREEN_HEIGHT / 2) return Quadrant::UpLeft;
    if (m_cursorPos.x < SCREEN_WIDTH / 2 && m_cursorPos.y >= SCREEN_HEIGHT / 2) return Quadrant::DownLeft;
    if (m_cursorPos.x >= SCREEN_WIDTH / 2 && m_cursorPos.y < SCREEN_HEIGHT / 2) return Quadrant::UpRight;
    if (m_cursorPos.x >= SCREEN_WIDTH / 2 && m_cursorPos.y >= SCREEN_HEIGHT / 2) return Quadrant::DownRight;
    return Quadrant::Invalid;

}