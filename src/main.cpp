//    Copyright 2013 Dustin Bensing

//    This file is part of XInputSimulator.

//    XInputSimulator is free software: you can redistribute it and/or modify
//    it under the terms of the GNU Lesser Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    any later version.

//    XInputSimulator is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU Lesser Public License for more details.

//    You should have received a copy of the GNU Lesser Public License
//    along with XInputSimulator.  If not, see <http://www.gnu.org/licenses/>.

#include <iostream>
#include "xinputsimulator.h"

#ifdef __linux__
//sleep
#include <unistd.h>
#elif __APPLE__
//sleep
#include <unistd.h>
#elif _WIN32
//sleep
#include <windows.h>
#endif

#include <stdlib.h>
#include <time.h>
#include <SFML/Window.hpp>

void waitABit();
void HandleKeyPressed(const sf::Event &event);

XInputSimulator &sim = XInputSimulator::getInstance();

int main()
{

    while (true)
    {
        using sf::Keyboard;
        int offset;
        if (Keyboard::isKeyPressed(Keyboard::LShift) || 
            Keyboard::isKeyPressed(Keyboard::RShift))
        {
            offset=15;
        }
        else
        {
            offset=5;
        }
        if (Keyboard::isKeyPressed(Keyboard::LAlt) || 
            Keyboard::isKeyPressed(Keyboard::RAlt))
        {
            if (Keyboard::isKeyPressed(Keyboard::W))
            {
                sim.mouseMoveRelative(0, -offset);
            }
            else if (Keyboard::isKeyPressed(Keyboard::S))
            {
                sim.mouseMoveRelative(0,offset);
            }
            else if (Keyboard::isKeyPressed(Keyboard::A))
            {
                sim.mouseMoveRelative(-offset,0);
            }
            else if (Keyboard::isKeyPressed(Keyboard::D))
            {
                sim.mouseMoveRelative(offset,0);
            }
            else if (Keyboard::isKeyPressed(Keyboard::J))
            {
                // sim.mouseClick(-1);
                sim.mouseClick(XIS::LEFT_MOUSE_BUTTON);

                // sim.mouseDown(XIS::LEFT_MOUSE_BUTTON);
                // sim.mouseUp(XIS::MIDDLE_MOUSE_BUTTON)
                usleep(1000*200);
            }
            else if (Keyboard::isKeyPressed(Keyboard::K))
            {
                sim.mouseClick(XIS::RIGHT_MOUSE_BUTTON);
                usleep(1000*200);
            }
            else if (Keyboard::isKeyPressed(Keyboard::L))
            {
                sim.mouseDoubleClick(2);
                usleep(1000*200);
            }
            else if (Keyboard::isKeyPressed(Keyboard::SemiColon))
            {
                sim.mouseDoubleClick(3);
                usleep(1000*200);
            }
            else if (Keyboard::isKeyPressed(Keyboard::Q))
            {
                sim.mouseScrollY(-offset);
                usleep(1000*200);
            }
            else if (Keyboard::isKeyPressed(Keyboard::E))
            {
                sim.mouseScrollY(offset);
                usleep(1000*200);
            }
            // else if (Keyboard::isKeyPressed(Keyboard::I))
            // {
            //     sim.mouseDown(XIS::LEFT_MOUSE_BUTTON);
            //     usleep(1000*200);
            // }
            // else if (Keyboard::isKeyPressed(Keyboard::O))
            // {
            //     sim.mouseUp(XIS::LEFT_MOUSE_BUTTON);
            //     usleep(1000*200);
            // }
            
        }
        usleep(1000 * 20);
    }

    sf::Window window(sf::VideoMode(800, 600), "My window");
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::KeyPressed:
                // std::cout << "The value of the key is " << event.key.code << " and control :" << event.key.control<<std::flush;
                HandleKeyPressed(event);
                break;
            default:
                break;
            }
        }
    }

    waitABit();
    // srand(time(nullptr));
    // while (true)
    // {
    //     int x=rand()%2560,y=rand()%1600;
    //     sim.mouseMoveTo(x,y);
    // }
    //     sim.mouseMoveTo(500,400);
    //     waitABit();
    //     sim.mouseMoveRelative(400, -100);
    //     waitABit();
    //     sim.mouseDown(XIS::LEFT_MOUSE_BUTTON);
    //     waitABit();
    //     sim.mouseMoveRelative(0, 300);
    //     waitABit();
    //     sim.mouseUp(XIS::LEFT_MOUSE_BUTTON);
    //     waitABit();
    //     //scroll down and up
    //     sim.mouseScrollY(10);
    //     waitABit();
    //     sim.mouseScrollY(-10);
    //     //scroll left and right
    //     waitABit();
    //     sim.mouseScrollX(10);
    //     waitABit();
    //     sim.mouseScrollX(-10);

    // #if defined(__linux__) || defined(__APPLE__)
    // 	char anA = 'a';
    //     cout << "a: " << (int)anA << " " << sim.charToKeyCode(anA) << endl;
    //     std::cout << std::endl;
    //     waitABit();
    //     sim.keyClick(sim.charToKeyCode(anA));
    //     std::cout << std::endl;
    //     waitABit();
    //     sim.keySequence(" Simple sentence Here 123 ");
    // #elif _WIN32
    //not implemented
    // #endif

    waitABit();
    return 0;
}

void waitABit()
{
//std::this_thread::sleep_for(std::chrono::milliseconds(1000));
#ifdef __linux__
    sleep(1);
#elif __APPLE__
    sleep(1);
#elif _WIN32
    Sleep(1000);
#endif
}
