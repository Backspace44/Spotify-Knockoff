// MusicPlayer.cpp
/*#include "MusicPlayer.h"
#include <iostream>

MusicPlayer::MusicPlayer()
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

void MusicPlayer::displayMusicPlayer(std::string& currentUser, Data_aparitie& data, Melodie& song, std::string& album)
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Music Player");
    sf::Sprite background(backgroundTexture);

    if (!music.openFromFile(song.getSong()))
    {
        std::cerr << "Failed to load music file for " << song.getName() << std::endl;
        return;
    }

    if (!coverTexture.loadFromFile(song.getCover()))
    {
        std::cerr << "Failed to load cover image for " << song.getName() << std::endl;
        return; 
    }

    sf::Sprite coverSprite(coverTexture);
    coverSprite.setPosition((window.getSize().x - coverTexture.getSize().x) / 2, (window.getSize().y - coverTexture.getSize().y) / 2);

 
    sf::RectangleShape playPauseButton(sf::Vector2f(100, 50));
    playPauseButton.setFillColor(sf::Color::Green);
    playPauseButton.setPosition((window.getSize().x - playPauseButton.getSize().x) / 2, window.getSize().y - 100);

    sf::FloatRect buttonBounds = playPauseButton.getGlobalBounds();

    sf::Text playPauseText;
    playPauseText.setFont(font);
    playPauseText.setCharacterSize(20);
    playPauseText.setString("Play");
    playPauseText.setFillColor(sf::Color::White);
    playPauseText.setPosition(buttonBounds.left + (buttonBounds.width - playPauseText.getLocalBounds().width) / 2, buttonBounds.top + (buttonBounds.height - playPauseText.getLocalBounds().height) / 2);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (playPauseButton.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                {
                    if (music.getStatus() == sf::Music::Playing)
                    {
                        music.pause();
                        playPauseText.setString("Play");
                    }

                    else if (music.getStatus() == sf::Music::Paused || music.getStatus() == sf::Music::Stopped)
                    {
                        music.play();
                        playPauseText.setString("Pause");
                    }
                }
            }

            window.clear();
            window.draw(background);
            window.draw(coverSprite);
            window.draw(playPauseButton);
            window.draw(playPauseText);
            window.display();
        }
    }
}
*/