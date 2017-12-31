#include <Windows.h> // console sizing, sleep()
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

#include "json.hpp"

void WindowController();
void TitleScreen();
void LoadingScreen();
void MainMenu();
void NewGame();
void NewGame(std::string);
void LoadGame();
void LoadGame(std::string);
void RunCredits();

int main()
{
	bool gameIsOver = false;

	// Seed the random number generator with the system time, so the
	// random numbers produced by rand() will be different each time
	std::srand(std::time(nullptr));

	// Maximizes the console window
	WindowController();

	//TitleScreen();

	//Sleep(4000);
	//system("cls");

	//LoadingScreen();

	MainMenu();

	//GameLoop();

	while (gameIsOver == false)
	{
		//Player(playerName, playerLevel, playerRace, playerClass, double playerMaxHP, double playerHP, double playerDMG, double playerEVA, double playerAGI, double playerXP)
		//Player player = Player("PotatoMan", 51, "Elf", "Archer", 10000, 9999, 555, 444, 333, 654321);

		//std::cout << player.playerName;

		gameIsOver = true;
	}

	return EXIT_SUCCESS;
}

void WindowController()
{
	// Renames the console window
	SetConsoleTitle(TEXT("Game Title"));

	// Sets the position and size of the console window on startup
	HWND consoleWindow = GetConsoleWindow();
	SetWindowPos(consoleWindow, 0, 250, 0, 1000, 1000, /*SWP_NOSIZE |*/ SWP_NOZORDER);
}

/*void TitleScreen()
{
//std::cout << std::endl;
for (int i = 0; i <= 26; i++)
{
std::cout << " " << std::string(78, '=') << std::endl;
}

std::cout << " " << std::string(20, '=')
<< " Welcome to the game, user "
<< std::string(31, '=')
<< std::endl;
std::cout << " " << std::string(30, '=')
<< " Prepare for the battle ahead "
<< std::string(18, '=')
<< std::endl;

for (int i = 0; i <= 27; i++)
{
std::cout << " " << std::string(78, '=') << std::endl;
}
}*/

void TitleScreen()
{
	std::cout << "	   ]z" << std::endl;
	std::cout << "           `@@_" << std::endl;
	std::cout << "            @@@L" << std::endl;
	std::cout << "      .d@L,]@@@@L," << std::endl;
	std::cout << "-z__   ]@@@a@@@@@@_" << std::endl;
	std::cout << " `@@@@zza@@@@@@@@@@L" << std::endl;
	std::cout << "  `]@@@@@@@@@@@@@@@@@_" << std::endl;
	std::cout << "    `@@@@@@@@@@@@@@@@@L" << std::endl;
	std::cout << "     `-@@@@@@@@@@@@@@@@'" << std::endl;
	std::cout << "       `@@@@@@@@@@@@@@[" << std::endl;
	std::cout << "        `@@@@@@@@@@@@@[" << std::endl;
	std::cout << "          ]@@@@@@@@@@@@[" << std::endl;
	std::cout << "             ~~~~-@@@@@@," << std::endl;
	std::cout << "                   ~-@@@_" << std::endl;
	std::cout << "                     ~@@@L" << std::endl;
	std::cout << "                      `@@@L_" << std::endl;
	std::cout << "                       `~@@@L" << std::endl;
	std::cout << "                         `@@@z," << std::endl;
	std::cout << "                          `]@@@_" << "\t\tGame Title" << std::endl;
	std::cout << "                            `@@@z" << std::endl;
	std::cout << "                             `]@@L_" << std::endl;
	std::cout << "                               ~@@@z" << std::endl;
	std::cout << "                                `@@@z," << std::endl;
	std::cout << "                                 `]@@@L" << std::endl;
	std::cout << "                                   `@@@z" << std::endl;
	std::cout << "                                     ]@@L," << std::endl;
	std::cout << "                                      ~@@@z" << std::endl;
	std::cout << "                                       -@@@z" << std::endl;
	std::cout << "                                        `-@@@_" << std::endl;
	std::cout << "                                          ~@@@_" << std::endl;
	std::cout << "                                           `@@@z" << std::endl;
	std::cout << "                                            `-@@@_" << std::endl;
	std::cout << "                                              ]@@@_" << std::endl;
	std::cout << "                                               ~@@@z" << std::endl;
	std::cout << "                                                `]@@L," << std::endl;
	std::cout << "                                                  `@@@L" << std::endl;
	std::cout << "                                                   `@@@z," << std::endl;
	std::cout << "                                                    `-@@@_" << std::endl;
	std::cout << "                                                      `@@@L" << std::endl;
	std::cout << "                                                       `@@@L    ]e" << std::endl;
	std::cout << "                                                         ~@@b_  a@b" << std::endl;
	std::cout << "                                                          `@@@e]@@L" << std::endl;
	std::cout << "                                                    -zzzz___@@@U@@@," << std::endl;
	std::cout << "                                                      ~~-@@@@@@@@@@@" << std::endl;
	std::cout << "                                                         `~-@@@@@@@@L" << std::endl;
	std::cout << "                                                            ~~-@@@@@@," << std::endl;
	std::cout << "                                                               ~~@@@@L" << std::endl;
	std::cout << "                                                                 `~@@@e" << std::endl;
	std::cout << "                                                                    ~@@_" << std::endl;
	std::cout << "                                                                      ~@" << std::endl;
}

void LoadingScreen()
{
	system("cls");

	for (int loadingPercent = 0; loadingPercent <= 99; loadingPercent++)
	{
		std::cout << std::string(25, '\n');
		std::cout << "\t\t\t\tLoading: " << loadingPercent << "%";
		int sleepRandom = 5 + (rand() % (int)(50 - 5 + 1)); // min = 5, max = 50
		Sleep(sleepRandom);
		system("cls");
	}
	system("cls");
}

void MainMenu()
{
	int mainMenuChoice;

	std::cout << std::string(13, '\n');
	//std::cout << "\t\t\t\tMAIN MENU\n\n\n";

	std::cout << "\t    /\\\\,/\\\\,                        /\\\\,/\\\\,\n";
	std::cout << "\t   /| || ||    _    '              /| || ||\n";
	std::cout << "\t   || || ||   < \\, \\\\ \\\\/\\\\        || || ||   _-_  \\\\/\\\\ \\\\ \\\\\n";
	std::cout << "\t   ||=|= ||   /-|| || || ||        ||=|= ||  || \\\\ || || || ||\n";
	std::cout << "\t  ~|| || ||  (( || || || ||       ~|| || ||  ||/   || || || ||\n";
	std::cout << "\t   |, \\\\,\\\\,  \\/\\\\ \\\\ \\\\ \\\\        |, \\\\,\\\\, \\\\,/  \\\\ \\\\ \\\\/\\\\\n";
	std::cout << "\t  _-                              _-\n\n\n";
	std::cout << std::string(3, '\n');
	std::cout << "\t\t\t1. New Game" << std::endl << std::endl;
	std::cout << "\t\t\t2. Load Game" << std::endl << std::endl;
	std::cout << "\t\t\t3. Credits" << std::endl << std::endl;
	std::cout << "\t\t\t4. Exit Game";
	std::cout << "\t\t\t4. Exit Game2";
	std::cout << "\n\n\t\t  Choice: ";
	std::cin >> mainMenuChoice;

	switch (mainMenuChoice)
	{
	case 1:
		system("cls");
		NewGame();
		break;
	case 2:
		system("cls");
		LoadGame();
		break;
	case 3:
		system("cls");
		RunCredits();
		break;
	case 4:
		exit(0);
		break;
	default:
		system("cls");
		std::cout << "[[Error: Invalid Entry.]]" << std::endl;
		std::cout << " Returning to main menu in ";
		for (int mainMenuErrorCountdown = 3; mainMenuErrorCountdown > 0; mainMenuErrorCountdown--)
		{
			std::cout << mainMenuErrorCountdown << " ";
			Sleep(1000);
		}
		system("cls");
		MainMenu();
	}
}

// called from MainMenu()
void NewGame()
{
	std::string charToCreate = "";
	std::string ifilename = "";
	std::cout << std::string(25, '\n');
	std::cout << "Character name: ";
	std::cin >> charToCreate;
	ifilename = charToCreate + ".dat";

	std::ifstream inputFile(ifilename, std::ios::in);
	if (inputFile.is_open())
	{
		std::cout << "That character already exists." << std::endl;
		std::cout << "Would you like to load that character? (y/n)";
		char x;
		std::cin >> x; // load this char?
		if (x == 'y')
		{
			system("cls");
			LoadGame(charToCreate);
		}
	}
}

// called from LoadGame()
void NewGame(std::string charName)
{
	std::string charToCreate = charName;
	std::string ofilename = charToCreate + ".dat";
	std::cout << std::string(25, '\n');
	std::cout << "Character name: " << charToCreate << std::endl;
	std::ofstream outputFile(ofilename, std::ios::out); // creates character's save file
	//Player player = Player();
}

// called from MainMenu()
void LoadGame()
{
	std::string charToLoad = "";
	std::string ifilename = "";
	std::cout << std::string(25, '\n');
	std::cout << "Character to load: ";
	std::cin >> charToLoad;
	ifilename = charToLoad + ".dat";

	std::ifstream inputFile(ifilename, std::ios::in);
	if (inputFile.is_open())
	{
		std::cout << "Successfully found savegame: " << ifilename << std::endl;
		inputFile.close();
	}
	else
	{
		std::cout << "That character does not exist." << std::endl;
		std::cout << "Would you like to create that character? (y/n) ";
		char x = ' ';
		std::cin >> x; // create this char?
		if (x == 'y')
		{
			system("cls");
			NewGame(charToLoad);
		}
		else
		{
			system("cls");
			MainMenu();
		}
	}
}

// called from NewGame()
void LoadGame(std::string charName)
{
	std::string charToLoad = charName;
	std::string ifilename = "";
	std::cout << std::string(25, '\n');
	std::cout << "Character to load: " << charToLoad << std::endl;
	ifilename = charToLoad + ".dat";

	std::ifstream inputFile(ifilename, std::ios::in); // loads character's save file
	if (inputFile.is_open() && !inputFile.eof())
	{
		std::cout << "Successfully loaded this character." << std::endl;
	}
}

// called from MainMenu()
void RunCredits()
{
	std::cout << std::string(13, '\n');
	std::cout << "\t\t    ,- _~.              |\\        , \n";
	std::cout << "\t\t   (' /|                 \\\\   '  || \n";
	std::cout << "\t\t  ((  ||   ,._-_  _-_   / \\\\ \\\\ =||=  _-_, \n";
	std::cout << "\t\t  ((  ||    ||   || \\  || || ||  ||  ||_.  \n";
	std::cout << "\t\t   ( / |    ||   ||/   || || ||  ||   ~ || \n";
	std::cout << "\t\t    -____-  \\\\,  \\\\,/   \\\\/  \\\\  \\\\, ,-_-";
	std::cout << std::string(4, '\n');
	std::cout << "\t\t          Created by - Dalton Marshall";
	Sleep(10000);
	system("cls");
	MainMenu();
}