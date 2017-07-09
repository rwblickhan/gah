//
// Created by Russell Blickhan on 12/13/16.
//

#pragma once

//std
#include <memory>

//gah
#include <WorldStateUpdateCallback.h>
#include <WorldStateRenderCallback.h>
#include <GameEntity.h>

class TestEntity : public GameEntity {
public:
    TestEntity(std::shared_ptr<EntityCache> cache);

    ~TestEntity();

    virtual void Update(WorldStateUpdateCallback* worldState) override;

    virtual void Render(WorldStateRenderCallback* worldState, SDL_Renderer* renderer) override;
};

