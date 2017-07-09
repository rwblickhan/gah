//
// Created by Russell Blickhan on 12/17/16.
//

#pragma once

//gah
#include <GameEntity.h>

class TestMoustachioEntity : public GameEntity {
public:
    TestMoustachioEntity(std::shared_ptr<EntityCache> cache);

    virtual ~TestMoustachioEntity();

    virtual void Update(WorldStateUpdateCallback* worldState) override;

    virtual void Render(WorldStateRenderCallback* worldState, SDL_Renderer* renderer) override;
};