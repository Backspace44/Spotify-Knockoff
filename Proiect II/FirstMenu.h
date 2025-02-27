//FirstMenu.h
#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "BazaDate.h"
#include "FirstMenu.h"

class FirstMenu
{
public:
	FirstMenu();
	void displayMenu(BazaDate& database);

private:
	sf::Texture backgroundTexture;
	sf::Texture buttonTexture;
	sf::Font font;
	std::string currentUser;
};
