#pragma once

#include "class/system/Scene.hpp"
#include "class/Item.hpp"
#include "class/Entity.hpp"

class Collection
{
    public:
        static void loadCollection();

        // scenes
        static Scene INTRO_CREDITS;
        static MainMenu MAIN_MENU;
        static SettingsMenu SETTINGS_MENU;
        static Level LEVEL_1;

        //items
        static Item TEST_ITEM;

        // entities
        static Entity TEST_ENTITY;
};