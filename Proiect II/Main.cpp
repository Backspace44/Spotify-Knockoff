//Main.cpp
#include <SFML/Graphics.hpp>
#include <iostream>
#include "BazaDate.h"
#include "FirstMenu.h"

int main()
{
	BazaDate database;
	FirstMenu firstMenu;
	firstMenu.displayMenu(database);
}
