//MusicPlayer.h
#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Melodie.h"
#include "User.h"
#include "Album.h"
#include "Data_aparitie.h"

class MusicPlayer
{
public:
	MusicPlayer();
	void displayMusicPlayer(std::string& currentUser, Data_aparitie& data, Melodie& song, std::string& album);

private:
	sf::Texture backgroundTexture;
	sf::Font font;
	sf::Texture coverTexture;
	sf::Music music;
};