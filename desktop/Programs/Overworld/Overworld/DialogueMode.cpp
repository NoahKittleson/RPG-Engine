//
//  DialogueMode.cpp
//  Overworld
//
//  Created by Noah Kittleson on 11/15/15.
//  Copyright (c) 2015 Noah. All rights reserved.
//

#include "DialogueMode.h"


DialogueMode::DialogueMode(DialogueThread* Start)
: spool(Start)
{
    assert (Start != nullptr);
    it = this->spool->getDialogue().begin();
    font.loadFromFile("sansation.ttf");
    displayText.setColor(sf::Color::Black);
    displayText.setFont(font);
    displayText.setPosition(20,20);
    displayFrame.setSize(sf::Vector2f(1000,200));
    displayFrame.setPosition(10, 10);
    displayFrame.setFillColor(sf::Color(153,76,0));
    displayFrame.setOutlineThickness(5);
    displayFrame.setOutlineColor(sf::Color::Red);
}

void DialogueMode::update(sf::RenderWindow &rw, sf::Clock& timer)
{
    //while (looping && rw.isOpen()) {
    totalElapsed += timer.restart().asSeconds();
    sf::Event event;
    rw.clear(sf::Color::White);
    sf::View MapView = rw.getView();
    sf::View HUD = rw.getDefaultView();
    rw.setView(MapView);
    currentMap->DrawAllObjects(rw, playerSprite);
    rw.setView(HUD);
    rw.draw(displayFrame);
    
    if (it != spool->getDialogue().end()) {
        displayText.setString(getGradualText(*it, displayText.getString()));
        while (rw.pollEvent(event)) {
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
                it++;
                displayText.setString("");
                totalElapsed = 0;
            }
        }
        rw.draw(displayText);
    }
    else if (!spool->getChoices().empty()) {
        while (rw.pollEvent(event)) {
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up) {
                if (choice == spool->getChoices().begin()) {
                    choice = spool->getChoices().end();
                }
                choice--;
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Down) {
                choice++;
                if (choice == spool->getChoices().end()) {
                    choice = spool->getChoices().begin();
                }
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::X) {
                spool = *choice;
                it = spool->getDialogue().begin();
            }
        }
        drawOptions(rw);
    }
    else {
        //end of dialogue
        deletionOrder = true;
        rw.pollEvent(event);            //necessary?!?!
    }
    rw.setView(MapView);                //can this lead to weird visual drawing behavior on the frame before DialogueMode Exit?
    rw.display();
    //}
}

void DialogueMode::drawOptions(sf::RenderWindow &rw)
{
    int Ypos = 0;
    for (auto&& it: spool->getChoices()) {
        displayText.setString(it->getStartingOption());
        displayText.setPosition(0, Ypos);
        Ypos += 50;
        
        if (it == *choice) {
            displayText.setColor(sf::Color::Red);
        }
        rw.draw(displayText);
        displayText.setColor(sf::Color::Black);
    }
}

sf::String DialogueMode::getGradualText(sf::String full, sf::String partial)
{
    if (partial.getSize() >= full.getSize()) {
        return full;
    }
    
    float time_per_letter = 0.02;
    
    while (totalElapsed >=  time_per_letter && partial.getSize() != full.getSize()) {
        partial += full[partial.getSize()];
        totalElapsed -= time_per_letter;
    }
    return partial;
}


/*void DialogueMode::update(sf::RenderWindow &rw, float elapsed)
 {
 float totalElapsed {0};             //what is this for?
 totalElapsed += elapsed;
 
 sf::Event event;
 while (rw.pollEvent(event)) {
 if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
 it++;
 if (it == spool->getDialogue().end()) {
 if (spool->getChoices().empty()) {
 return;
 }
 spool = getDecision(spool->getChoices(), rw);       //how do I handle new loops?
 }
 displayText.setString("");
 totalElapsed = 0;
 }
 }
 displayText.setString(getGradualText(*it, displayText.getString()));
 //drawEverything(rw);
 }


void DialogueMode::run(sf::RenderWindow &rw, DialogueThread* spool)
{
    it = spool->getDialogue().begin();
    
    sf::Clock clock;
    float elapsed;
    float totalElapsed{0};
    
    while (rw.isOpen()) {
        
        sf::Event event;
        elapsed = clock.restart().asSeconds();
        totalElapsed += elapsed;
        while (rw.pollEvent(event)) {
            
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
                it++;
                if (it == spool->getDialogue().end()) {
                    if (spool->getChoices().empty()) {
                        return;
                    }
                    spool = getDecision(spool->getChoices(), rw, clock);
                    it = spool->getDialogue().begin();
                }
                displayText.setString("");
                totalElapsed = 0;
            }
        }
        displayText.setString(getGradualText(*it, displayText.getString()));
        
        rw.clear(sf::Color::White);
        rw.draw(displayText);
        rw.display();
    }
}

DialogueThread* DialogueMode::getDecision(std::list<DialogueThread*> choices, sf::RenderWindow &rw, sf::Clock& timer)
{
    if (choices.size() == 1) {
        return *choices.begin();
    }
    
    sf::Font font;
    font.loadFromFile("sansation.ttf");
    sf::Text Display("BAD ERROR", font, 32);
    Display.setColor(sf::Color::Black);
    std::list<DialogueThread*>::iterator iter = choices.begin();
    
    while (rw.isOpen()) {
        rw.clear(sf::Color::White);
        timer.restart();                                //this is where I will make float elapsed if I have need of it
        
        int Ypos = 0;
        for (auto&& it: choices) {
            Display.setString(it->getStartingOption());
            Display.setPosition(0, Ypos);
            Ypos += 50;
            
            if (it == *iter) {
                Display.setColor(sf::Color::Red);
            }
            rw.draw(Display);
            Display.setColor(sf::Color::Black);
        }
        
        sf::Event event;
        while (rw.pollEvent(event)) {
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up) {
                if (iter == choices.begin()) {
                    iter = choices.end();
                }
                iter--;
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Down) {
                iter++;
                if (iter == choices.end()) {
                    iter = choices.begin();
                }
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
                return *iter;
            }
        }
        rw.display();
    }
    //I don't think this can be reached, but in case it does...
    return *iter;
}*/





