//
// Created by Russell Blickhan on 1/8/17.
//

#pragma once

struct EntityCache {
    //NOTE: cache owns all textures
    SDL_Texture* m_pIconUL = nullptr;
    SDL_Texture* m_pIconUR = nullptr;
    SDL_Texture* m_pIconDL = nullptr;
    SDL_Texture* m_pIconDR = nullptr;
};