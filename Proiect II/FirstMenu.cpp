//FirstMenu.cpp
#include "FirstMenu.h"
#include "Listener.h"
#include "Album.h"
#include <iostream>

enum class FirstMenuPage
{
	FirstMenu,
	Library,
};

FirstMenuPage currentPage = FirstMenuPage::FirstMenu;

//Library library;

FirstMenu::FirstMenu()
{
	if (!backgroundTexture.loadFromFile("poze/Dark-Gray-Backgrounds.jpg"))
	{
		std::cerr << "Failed to load background image" << std::endl;
		return;
	}

	if (!buttonTexture.loadFromFile("poze/Light-Gray-Backgrounds.jpg"))
	{
		std::cerr << "Failed to load button image" << std::endl;
		return;
	}

	if (!font.loadFromFile("fonts/coolvetica compressed hv.otf"))
	{
		std::cerr << "Failed to load font" << std::endl;
		return;
	}
}

void FirstMenu::displayMenu(BazaDate& database)
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Meniu");
	sf::Sprite background(backgroundTexture);

	sf::Text titleLabel1;
	titleLabel1.setFont(font);
	titleLabel1.setString("Who is listening to ");
	titleLabel1.setCharacterSize(50);
	titleLabel1.setFillColor(sf::Color::White);
	titleLabel1.setPosition(250, 50);

	sf::Text titleLabel2;
	titleLabel2.setFont(font);
	titleLabel2.setString("Spotify");
	titleLabel2.setCharacterSize(50);
	sf::Color customGreen(30, 215, 96);
	titleLabel2.setFillColor(customGreen);
	titleLabel2.setPosition(475, 50);

	sf::Text titleLabel3;
	titleLabel3.setFont(font);
	titleLabel3.setString("?");
	titleLabel3.setCharacterSize(50);
	titleLabel3.setFillColor(sf::Color::White);
	titleLabel3.setPosition(570, 50);

	std::vector<sf::Sprite> buttons;
	std::vector<sf::Text> buttonTexts;

	std::unordered_map<ListenerId, Listener> listeners = database.getListeners();

	for (size_t i = 0; i < listeners.size(); ++i)
	{
		sf::Sprite button(buttonTexture);
		button.setPosition(300.0f, 300.0f + static_cast<float>(i) * 70.0f);

		float scaleX = static_cast<float>(200) / buttonTexture.getSize().x;
		float scaleY = static_cast<float>(50) / buttonTexture.getSize().y;
		button.setScale(scaleX, scaleY);

		sf::Text buttonText;
		buttonText.setFont(font);
		buttonText.setString(listeners[i].getName());
		buttonText.setCharacterSize(30);
		buttonText.setOrigin(buttonText.getLocalBounds().left + buttonText.getLocalBounds().width / 2.0f, buttonText.getLocalBounds().top + buttonText.getLocalBounds().height / 2.0f);
		buttonText.setPosition(button.getPosition().x + button.getLocalBounds().width * scaleX / 2.0f - buttonText.getLocalBounds().width / 2.0f + 20.0f, button.getPosition().y + button.getLocalBounds().height * scaleY / 2.0f - buttonText.getLocalBounds().height / 2.0f + 7.0f);
		buttonText.setFillColor(sf::Color::White);

		
		buttons.push_back(button);
		buttonTexts.push_back(buttonText);

		
	}

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					for (size_t i = 0; i < buttons.size(); ++i)
					{
						if (buttons[i].getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
						{
								currentPage = FirstMenuPage::Library;
								currentUser = buttonTexts[i].getString();
						}

					}
				}
			}
		}

		window.clear();

		window.draw(background);
		
		if (currentPage == FirstMenuPage::FirstMenu)
		{
			window.draw(titleLabel1);
			window.draw(titleLabel2);
			window.draw(titleLabel3);

			for (size_t i = 0; i < buttons.size(); ++i)
			{
				window.draw(buttons[i]);
				window.draw(buttonTexts[i]);
			}
		}
		/*else if (currentPage == FirstMenuPage::Library)
		{
			//library.displayLibrary(currentUser, dates, songs, albums);
		}

		*/

		window.display();
	}
}

