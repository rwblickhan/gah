//
// Created by Russell Blickhan on 12/17/16.
//

#pragma once

//gah
#include <GameEntity.h>
#include <WorldStateUpdateCallback.h>
#include <WorldStateRenderCallback.h>

class TestMoustachioEntity : public GameEntity {
public:
    TestMoustachioEntity();
    virtual ~TestMoustachioEntity();

    virtual void Init(SDL_Renderer* mainWinRen) override;

    virtual void Update(WorldStateUpdateCallback* worldState) override;

    virtual void Render(WorldStateRenderCallback* worldState) override;

private:

    SDL_Renderer* m_pMainWinRen = nullptr;
    SDL_Texture* m_pIconUL = nullptr;
    SDL_Texture* m_pIconUR = nullptr;
    SDL_Texture* m_pIconDL = nullptr;
    SDL_Texture* m_pIconDR = nullptr;
};