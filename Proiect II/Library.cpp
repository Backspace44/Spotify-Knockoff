//Library.cpp
#include "Library.h"
#include "MusicPlayer.h"
#include <iostream>


Library::Library()
{
	if (!backgroundTexture.loadFromFile("poze/Dark-Gray-Backgrounds.jpg"))
	{
		std::cerr << "Failed to load background image" << std::endl;
		return;
	}

	if (!font.loadFromFile("fonts/coolvetica compressed hv.otf"))
	{
		std::cerr << "Failed to load font" << std::endl;
		return;
	}
}

void Library::displayLibrary(std::string& currentUser, std::vector<Data_aparitie>& dates, std::vector<Melodie>& songs, std::vector<Album>& albums)
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Library");
	sf::Sprite background(backgroundTexture);
	MusicPlayer musicplayer;
	while (window.isOpen())
	{
		float xOffset = 100.0f;
		float yOffset = 100.0f;
		const float coverWidth = 100.0f;
		const float coverHeight = 100.0f;

		const float spacingX = 20.0f;
		const float spacingY = 20.0f;

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					for (auto& song : songs)
					{
						sf::Text titleText;
						titleText.setFont(font);
						titleText.setString(song.getName());
						titleText.setCharacterSize(20);
						float titleXOffset = xOffset + (coverWidth - titleText.getLocalBounds().width);
						float titleYOffset = yOffset + coverHeight + 10.0f;

						if (event.mouseButton.x >= titleXOffset && event.mouseButton.x <= titleXOffset + titleText.getLocalBounds().width && event.mouseButton.y >= titleYOffset && event.mouseButton.y <= titleYOffset + titleText.getLocalBounds().height)
						{
							Data_aparitie data = song.getData();
							std::string album = song.getName();
				
							musicplayer.displayMusicPlayer(currentUser, data, song, album);
						}
					}
				}
			}
		}
		window.clear();
		window.draw(background);


		for (auto& song : songs)
		{
			sf::Texture coverTexture;
			if (!coverTexture.loadFromFile(song.getCover()))
			{
				std::cerr << "Failed to load cover image for " << song.getName() << std::endl;
				continue;
			}

			coverTexture.setSmooth(true);

			sf::Vector2u newSize(50, 50);
			sf::Vector2u textureSize = coverTexture.getSize();
			float scaleX = static_cast<float>(newSize.x) / textureSize.x;
			float scaleY = static_cast<float>(newSize.y) / textureSize.y;

			sf::Sprite coverSprite(coverTexture);
			coverSprite.setScale(scaleX, scaleY);
			coverSprite.setPosition(20.0f, 100.0f + yOffset);
			
			
			window.draw(coverSprite);

			sf::Text titleText;
			titleText.setFont(font);
			titleText.setString(song.getName());
			titleText.setCharacterSize(20);
			float titleXOffset = xOffset + (coverWidth - titleText.getLocalBounds().width) / 2.0f;
			float titleYOffset = yOffset + coverHeight + 10.0f;
			titleText.setPosition(titleXOffset, titleYOffset);
			
			window.draw(titleText);

			yOffset = yOffset + 70.0f;
		}
		window.display();
	}
}