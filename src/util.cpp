#include <SFML/Window.hpp>
#include "xinputsimulator.h"

extern XInputSimulator &sim;

void HandleKeyPressed(const sf::Event &event)
{
    if (event.key.control == 1 &&
        event.key.shift == 0 &&
        event.key.alt == 0)
    {
        switch (event.key.code)
        {
        case sf::Keyboard::W:
            sim.mouseMoveRelative(0,-20);
            break;
        case sf::Keyboard::S:
            sim.mouseMoveRelative(0,20);
            break;
        case sf::Keyboard::A:
            sim.mouseMoveRelative(-20,0);
            break;
        case sf::Keyboard::D:
            sim.mouseMoveRelative(20,0);
            break;
        case sf::Keyboard::Return:
            sim.mouseClick(XIS::LEFT_MOUSE_BUTTON);
            break;
        default:
            break;
        }
    }
}