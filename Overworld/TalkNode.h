//
//  TalkNode.h
//  Overworld
//
//  Created by Noah Kittleson on 2/17/16.
//  Copyright (c) 2016 Noah. All rights reserved.
//

#pragma once
#include "PrefixHeader.pch"
#include "DNode.h"

struct TextBox {
public:
	Dialogue::Speaker speakerID;
	sf::String string;
};

class TalkNode: public DNode
{
public:
	TalkNode(const sf::Font&, Dialogue::ID, Dialogue::Speaker);
    ~TalkNode();
    
	void addText(sf::String&&, Dialogue::Speaker speaker);
	void addPath(DPath path);						//paths need to be added in sequential order of priority
	void setPosition(sf::Vector2f xy) override;
	void setPosition(float x, float y) override;
	
    void clear() override;
    void update(float elapsed, AudioHandler& audio) override;
    void draw(sf::RenderWindow &rw) override;
	void handleInput(sf::Event&) override;
	Dialogue::ID getNext(const std::vector<Condition>& cv) override;

private:
	Dialogue::Speaker speakerID;
    float totalElapsed {0};
    IterVector<TextBox> text;
	sf::Text speakerText;
	std::vector<DPath> potentialPaths;
    
    std::string getText() override;
};

