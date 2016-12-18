//
// Created by Russell Blickhan on 12/17/16.
//

#pragma once

//gah
#include <GameEntity.h>

class TestCookieEntity : public GameEntity {
public:
    TestCookieEntity();
    virtual ~TestCookieEntity();

    virtual void Init(SDL_Renderer* mainWinRen) override;

    virtual void Update(WorldStateUpdateCallback* worldState) override;

    virtual void Render(WorldStateRenderCallback* worldState) override;

private:
    SDL_Renderer* m_pMainWinRen = nullptr;
    SDL_Texture* m_pIconCookie = nullptr;

};