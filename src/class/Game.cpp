#include "class/Game.hpp"
#include "class/Asset.hpp"
#include "class/Collection.hpp"

Game::Game()
{
    Asset::loadAssets();
    Collection::loadCollection();
    Timer::start();
    Player::instance = new Player();
    m_render = new Render();
    m_currentScene = &Collection::MAIN_MENU;
}

Game* Game::instance;

bool Game::isRunning() const { return m_render->getWindow()->isOpen(); }

Render* Game::getRender() { return m_render; }

Scene* Game::getCurrentScene() { return m_currentScene; }

void Game::setCurrentScene(Scene* scene) { m_currentScene = scene; }

void Game::pollEvents()
{
    while (m_render->getWindow()->pollEvent(m_event)) {
        switch (m_event.type) {
            case Event::Closed:
                m_render->getWindow()->close();
                break;
        }
    }
}

void Game::updateFpsIndicator()
{
    static float clock = 0;

    if (Timer::getSeconds() > clock + 0.15) {
        clock = Timer::getSeconds();
        m_currentScene->getText()->setString("fps : " + \
        to_string((int)Timer::getFps()));
    }
}

void Game::updateSceneLogic(Scene* scene)
{
    // Updates scene logic
    scene->updateLogic(getRender()->getWindow());
}

void Game::update()
{
    Timer::update();
    updateFpsIndicator();
    updateSceneLogic(m_currentScene);
    pollEvents();
}

void Game::render()
{
    m_render->getWindow()->clear();
    m_currentScene->display(getRender()->getWindow());
    m_render->getWindow()->display();
}
