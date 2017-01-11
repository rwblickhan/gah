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
    m_pMainWindow = SDL_CreateWindow("Main Window", 100, 100, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (m_pMainWindow == nullptr)
    {
        std::cout << "SDL_CreateWindow error: " << SDL_GetError() << std::endl;
        Deinit();
        return;
    }
    m_pRen = SDL_CreateRenderer(m_pMainWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (m_pRen == nullptr)
    {
        std::cout << "SDL_CreateRenderer error: " << SDL_GetError() << std::endl;
        Deinit();
        return;
    }
    //TODO make this nicer
    std::string loadingPath = std::string(SDL_GetBasePath()) + "assets/loading.bmp";
    SDL_Surface* img = SDL_LoadBMP(loadingPath.c_str());
    if (img == nullptr) {
        std::cout << "SDL_LoadBMP Error: " << SDL_GetError() << std::endl;
        Deinit();
        return;
    }
    SDL_Texture* m_pTempTex = SDL_CreateTextureFromSurface(m_pRen, img);
    SDL_FreeSurface(img);
    if (m_pTempTex == nullptr) {
        std::cout << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
        Deinit();
        return;
    }
    SDL_RenderClear(m_pRen);
    SDL_RenderCopy(m_pRen, m_pTempTex, NULL, NULL);
    SDL_RenderPresent(m_pRen);

    if (!IMG_Init(IMG_INIT_PNG)) {
        std::cout << "Error: Couldn't init png loader, error: " << SDL_GetError() << std::endl;
    } else {
        std::cout << "Successfully initialized png loader" << std::endl;
    }

    m_pCache = std::make_shared<EntityCache>();
    m_pAssetLoader = std::make_shared<AssetLoader>();
    m_pAssetLoader->LoadAssets(m_pRen, m_pCache);
    std::shared_ptr<GameEntity> moustachioEntity(new TestMoustachioEntity());
    std::shared_ptr<GameEntity> cookieEntity(new TestCookieEntity());
    m_entityList.push_back(moustachioEntity);
    m_entityList.push_back(cookieEntity);
    for (auto& entity: m_entityList)
    {
        entity->Init(m_pRen, m_pCache);
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

    SDL_SetRenderDrawColor(m_pRen, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(m_pRen);
    for (auto& entity : m_entityList)
    {
        entity->Render(static_cast<WorldStateRenderCallback*>(this));
    }
    SDL_RenderPresent(m_pRen);
}

void GameWorld::SetCursorPos(int x, int y) {
    cursorPos.x = x;
    cursorPos.y = y;
}

WindowPos GameWorld::GetCursorPos() {
    return cursorPos;
}

Quadrant GameWorld::GetCursorQuadrant() {
    if (cursorPos.x < SCREEN_WIDTH / 2 && cursorPos.y < SCREEN_HEIGHT / 2) return Quadrant::UpLeft;
    if (cursorPos.x < SCREEN_WIDTH / 2 && cursorPos.y >= SCREEN_HEIGHT / 2) return Quadrant::DownLeft;
    if (cursorPos.x >= SCREEN_WIDTH / 2 && cursorPos.y < SCREEN_HEIGHT / 2) return Quadrant::UpRight;
    if (cursorPos.x >= SCREEN_WIDTH / 2 && cursorPos.y >= SCREEN_HEIGHT / 2) return Quadrant::DownRight;
    return Quadrant::Invalid;

}