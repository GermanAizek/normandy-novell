#include "pch.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>

void game(sf::RenderWindow & window)
{
	window.clear(sf::Color::Black);

	bool isGame = true;
	size_t countClick = 0;

	sf::Music music, ambient, ambient2, ambient3, buffer, buffer2, buffer3, buffer4, buffer5, buffer6, voiceBuffer;
	music.openFromFile("content/musics/music_intro.ogg");
	music.play();

	sf::Texture backgroundTexture;
	backgroundTexture.loadFromFile("content/textures/back_1.jpg");
	backgroundTexture.setSmooth(true);
	sf::Sprite back(backgroundTexture);
	back.setScale(1.5f, 1.5f);

	sf::Texture dialogueTexture;
	dialogueTexture.loadFromFile("content/textures/ui/dialogue.png");
	dialogueTexture.setSmooth(true);
	sf::Sprite dialogue(dialogueTexture);
	dialogue.setPosition(50, 850);
	dialogue.setScale(2.2f, 1.2f);

	sf::Font font;
	font.loadFromFile("content/fonts/arialbd.ttf");

	sf::Text text;
	text.setFont(font);
	text.setCharacterSize(38);
	text.setPosition(180, 850);
	text.setFillColor(sf::Color::White);
	text.setOutlineColor(sf::Color::Black);
	text.setOutlineThickness(2.0f);
	text.setLineSpacing(1.1f);

	ambient3.openFromFile("content/musics/sea_ambient.wav");
	ambient3.setVolume(0.8f);
	ambient3.play();

	while (window.isOpen())
	{
		sf::Event GameEvent;

		if (window.pollEvent(GameEvent))
		{
			if (GameEvent.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		if (isGame)
		{
			if (sf::IntRect(0, 0, 1920, 1080).contains(sf::Mouse::getPosition(window)))
			{
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					countClick += 1;
					sf::sleep(sf::milliseconds(250));
					switch (countClick)
					{
					case 1:
						text.setString("Author\nHello reader, we want to tell you a dramatic story about an ordinary schoolgirl\n Charlotte who found the war.");
						ambient2.openFromFile("content/musics/boats.ogg");
						ambient2.setVolume(0.7f);
						ambient2.play();
						buffer.openFromFile("content/musics/storm.wav");
						buffer.play();
						voiceBuffer.openFromFile("content/musics/scene_1.ogg");
						voiceBuffer.play();
						break;
					case 2: text.setString(L"Author\nCharlotte was unaware that she was waiting."); break;
					case 3:
						text.setString(L"Charlotte\nDamn heavy rain will disturb us.");
						backgroundTexture.loadFromFile("content/textures/back_2.jpg");
						buffer2.openFromFile("content/musics/ship_engine.wav");
						buffer2.play();
						voiceBuffer.openFromFile("content/musics/scene_2.ogg");
						voiceBuffer.play();
						break;
					case 4:
						text.setString(L"Charlotte\nWhere are our planes? They must clear a place for landing infantry.");
						voiceBuffer.openFromFile("content/musics/scene_3.ogg");
						voiceBuffer.play();
						break;
					case 5:
						text.setString(L"Elizabeth\nBut our little birds, show them our greeting.");
						backgroundTexture.loadFromFile("content/textures/back_3.jpg");
						ambient.openFromFile("content/musics/war_ambient.flac");
						ambient.play();
						buffer3.openFromFile("content/musics/plans.wav");
						buffer3.play();
						voiceBuffer.openFromFile("content/musics/scene_4.ogg");
						voiceBuffer.play();
						break;
					case 6:
						text.setString(L"Corporal Wilson\nPrivate Kossan collapse and listen to the action plan.\n We will fall under the heavy fire of the enemy,\nit is necessary to break through the defense of the enemy and take a position on the hill.");
						backgroundTexture.loadFromFile("content/textures/back_4.png");
						voiceBuffer.openFromFile("content/musics/scene_5.ogg");
						voiceBuffer.play();
						break;
					case 7:
						text.setString(L"Corporal Wilson\nWe go to hell and no one will help us except for partners in arms.\n They have an advantage in the terrain,\nthe main thing for us is to get to the slope and destroy the fortifications.");
						buffer4.openFromFile("content/musics/plans_exp.wav");
						buffer4.play();
						voiceBuffer.openFromFile("content/musics/scene_6.ogg");
						voiceBuffer.play();
						break;
					case 8:
						text.setString(L"Corporal Wilson\nAfter all, the historical course of events in the future depends only on us.");
						backgroundTexture.loadFromFile("content/textures/back_5.png");
						buffer5.openFromFile("content/musics/spitfire.wav");
						buffer5.play();
						voiceBuffer.openFromFile("content/musics/scene_7.ogg");
						voiceBuffer.play();
						break;
					case 9:
						text.setString(L"Corporal Wilson\nWe are approaching, cover your heads as the gangway descends to occupy the beach.");
						backgroundTexture.loadFromFile("content/textures/back_5.png");
						buffer2.openFromFile("content/musics/bullets.wav");
						buffer2.play();
						music.openFromFile("content/musics/battle.wav");
						music.play();
						voiceBuffer.openFromFile("content/musics/scene_8.ogg");
						voiceBuffer.play();
						break;
					case 10:
						text.setString(L"Nicolet\nWhy we were sent here to the front.");
						voiceBuffer.openFromFile("content/musics/scene_9.ogg");
						voiceBuffer.play();
						break;
					case 11:
						text.setString(L"Corporal Wilson\nBecause you are ordinary and you have a chance to prove yourself.");
						voiceBuffer.openFromFile("content/musics/scene_10.ogg");
						voiceBuffer.play();
						break;
					case 12:
						text.setString(L"Corporal Wilson\nDamn we ran aground. Driver lower the ladder!");
						buffer6.openFromFile("content/musics/fall_trap.wav");
						buffer6.play();
						buffer2.openFromFile("content/musics/bullets.wav");
						buffer2.play();
						voiceBuffer.openFromFile("content/musics/scene_11.ogg");
						voiceBuffer.play();
						break;
					case 13:
						text.setString(L"Charlotte\n*running*");
						backgroundTexture.loadFromFile("content/textures/back_6.jpg");
						buffer.openFromFile("content/musics/running.flac");
						buffer.play();
						voiceBuffer.openFromFile("content/musics/scene_12.ogg");
						voiceBuffer.play();
						break;
					case 14:
						text.setString(L"Charlotte\nAghrh, it hurts...");
						buffer2.openFromFile("content/musics/bullets.wav");
						buffer2.play();
						buffer2.openFromFile("content/musics/mud_fall.wav");
						buffer2.play();
						voiceBuffer.openFromFile("content/musics/scene_13.ogg");
						voiceBuffer.play();
						break;
					case 15:
						text.setString(L"Corporal Wilson\nTo leave nagging urgent run across to us will bypass from the right front!");
						backgroundTexture.loadFromFile("content/textures/back_7.jpg");
						buffer2.openFromFile("content/musics/heavy_guns.wav");
						buffer2.play();
						voiceBuffer.openFromFile("content/musics/scene_14.ogg");
						voiceBuffer.play();
						break;
					case 16:
						text.setString(L"Charlotte\n*running*");
						backgroundTexture.loadFromFile("content/textures/back_6.jpg");
						buffer.openFromFile("content/musics/running.flac");
						buffer.play();
						voiceBuffer.openFromFile("content/musics/scene_15.ogg");
						voiceBuffer.play();
						break;
					case 17:
						text.setString(L"Charlotte\n...");
						music.stop();
						buffer2.stop();
						buffer3.stop();
						buffer4.stop();
						buffer5.stop();
						buffer6.stop();
						buffer.openFromFile("content/musics/huge_exp.wav");
						buffer.play();
						window.clear(sf::Color::Black);
						break;
					case 18:
						text.setString(L"Charlotte\nWhat happened?");
						window.clear(sf::Color::Black);
						voiceBuffer.openFromFile("content/musics/scene_16.ogg");
						voiceBuffer.play();
						break;
					case 19:
						text.setString(L"Author\nWe will stop at the most interesting place and better tell\n the background zachem ty eto chitaesh, lol.");
						window.clear(sf::Color::Black);
						voiceBuffer.openFromFile("content/musics/scene_17.ogg");
						voiceBuffer.play();
						break;
					case 20:
						isGame = false;
						break;
					default: break;
					}
				}
			}

			if (!isGame)
				window.close();
		}

		window.clear(sf::Color::Black);
		window.draw(back);
		window.draw(dialogue);
		window.draw(text);

		window.display();
	}
}

void intro(sf::RenderWindow & window)
{
	bool isIntro = true;
	size_t countClick = 0;
	sf::Music music;
	music.openFromFile("content/musics/music_intro.ogg");
	music.setVolume(0.5f);
	music.play();
	//sf::sleep(sf::milliseconds(1000));

	sf::Font fontGlobal;
	fontGlobal.loadFromFile("content/fonts/stencilww2.ttf");

	sf::Text text;
	text.setFont(fontGlobal);
	text.setCharacterSize(50);
	sf::FloatRect bounds = text.getLocalBounds();
	text.setPosition((1920/6) - bounds.width, (1080/2));

	while (window.isOpen())
	{
		sf::Event GameEvent;

		if (window.pollEvent(GameEvent))
		{
			if (GameEvent.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		if (isIntro)
		{
			if (sf::IntRect(0, 0, 1920, 1080).contains(sf::Mouse::getPosition(window)))
			{
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					countClick += 1;
					sf::sleep(sf::milliseconds(250));
					switch (countClick)
					{
					case 1: text.setString("The Second World War is the bloodiest war in the history of mankind. Lasted 6 years."); break;
					case 2: text.setString("61 states with a total population of 1700 million people, that is 80% of the total\n population of the earth, participated in the military operations of the army.\nThe fighting went on in the territories of 40 countries."); break;
					case 3: text.setString("For the first time in the annals of mankind, the number of dead civilians exceeded\n the number of those killed directly in the battles, and almost twice."); break;
					case 4: text.setString("It is game maked of memory of those killed in the bloodiest war."); break;
					case 5: isIntro = false; break;
					default: break;
					}
				}
			}

			if (!isIntro)
				game(window);
		}

		window.clear(sf::Color::Black);
		window.draw(text);

		window.display();
	}
}

void menu(sf::RenderWindow & window)
{
	sf::Music musicMenu;
	musicMenu.openFromFile("content/musics/music_menu.ogg");
	musicMenu.play();

	sf::Texture menuLogo, menuTexture1, menuTexture2, menuTexture3, aboutTexture, menuBackground;
	menuLogo.loadFromFile("content/textures/ui/mm_logo.png");
	menuTexture1.loadFromFile("content/textures/ui/mm_newgame.png");
	menuTexture2.loadFromFile("content/textures/ui/mm_credits.png");
	menuTexture3.loadFromFile("content/textures/ui/mm_quit.png");
	aboutTexture.loadFromFile("content/textures/ui/mm_back_credits.jpg");
	menuBackground.loadFromFile("content/textures/ui/mm_back.jpg");

	sf::Sprite logo(menuLogo), menu1(menuTexture1), menu2(menuTexture2), menu3(menuTexture3), about(aboutTexture), menuBg(menuBackground);
	bool isMenu = 1;
	int menuNum = 0;
	logo.setPosition(1000, 0);
	logo.setScale(1.5f, 1.5f);
	menu1.setPosition(100, 530);
	menu2.setPosition(100, 630);
	menu3.setPosition(100, 730);
	menuBg.setPosition(0, 0);
	menuBg.setScale(1.5f, 1.5f);
	about.setScale(1.8f, 1.8f);

	while (window.isOpen())
	{
		sf::Event GameEvent;

		if (window.pollEvent(GameEvent))
		{
			if (GameEvent.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		if (isMenu)
		{
			menu1.setColor(sf::Color::White);
			menu2.setColor(sf::Color::White);
			menu3.setColor(sf::Color::White);
			menuNum = 0;
			window.clear(sf::Color(129, 181, 221));

			if (sf::IntRect(100, 550, 300, 100).contains(sf::Mouse::getPosition(window)))
			{
				menu1.setColor(sf::Color::Yellow);
				menuNum = 1;
			}
			if (sf::IntRect(100, 650, 300, 100).contains(sf::Mouse::getPosition(window)))
			{
				menu2.setColor(sf::Color::Yellow);
				menuNum = 2;
			}
			if (sf::IntRect(100, 750, 300, 100).contains(sf::Mouse::getPosition(window)))
			{
				menu3.setColor(sf::Color::Yellow);
				menuNum = 3;
			}

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				if (menuNum == 1)
				{
					isMenu = false;
					intro(window);
				}
				if (menuNum == 2)
				{
					window.draw(about);
					window.display();
					while (!sf::Keyboard::isKeyPressed(sf::Keyboard::Escape));
				}
				if (menuNum == 3)
				{
					window.close();
					isMenu = false;
				}
			}
		}

		window.draw(menuBg);
		window.draw(logo);
		window.draw(menu1);
		window.draw(menu2);
		window.draw(menu3);

		window.display();
	}
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Love Story: WW2", sf::Style::Fullscreen);

	menu(window);
}