#pragma once

#include "class/Scene.hpp"
#include "class/Entity.hpp"

class Collection
{
    public:
        static void loadCollection();

        // scenes
        static Scene INTRO_CREDITS;
        static Menu START_MENU;
        static Level LEVEL_1;
};