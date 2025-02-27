//Library.h
#pragma once
#include <SFML/Graphics.hpp>
#include "Melodie.h"
#include "User.h"
#include "Album.h"
#include "Data_aparitie.h"

class Library
{
public:
	Library();
	//std::vector<std::string> getIcons() const;
	void displayLibrary(std::string& currentUser, std::vector<Data_aparitie>& dates, std::vector<Melodie>& songs, std::vector<Album>& albums);
	
private:
	sf::Texture backgroundTexture;
	Melodie song;
	sf::Font font;
	std::vector<std::string> icons;
	sf::Texture coverTexture;
	std::string currentSong;
	Data_aparitie currentData;
	std::string currentAlbum;
};
