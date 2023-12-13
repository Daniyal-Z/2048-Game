#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <random>
#include <conio.h>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <time.h>
using namespace std;
using namespace sf;


//____________________________________________________________________GAME MECHANICS (FUNCTIONS)___________________________________________________________________________________________
bool Occupied(int board[][4], int xP, int yP, int xQ, int yQ)
{
	int valP = board[xP][yP];
	int valQ = board[xQ][yQ];

	if (valQ == 0)
	{
		return false;
	}
	else if (valQ % 2 == 0 && valQ != valP)
	{
		return true;
	}
	else  // valQ = valP
	{
		return false;
	}
}

void Assigns_0(int board[][4], int x, int y)
{
	board[x][y] = 0;
}

int Add(int board[][4], int xP, int yP, int xQ, int yQ, int& tileAddCount)
{

	if (!Occupied(board, xP, yP, xQ, yQ))
	{
		if (board[xQ][yQ] == 0)
		{
			board[xQ][yQ] += board[xP][yP];
			Assigns_0(board, xP, yP);
			return 0;     // used to determine if any moves were made
		}
		if (tileAddCount == 0 && board[xQ][yQ] != 0)
		{
			tileAddCount++;
			board[xQ][yQ] += board[xP][yP];
			Assigns_0(board, xP, yP);

			return 1;

		}
	}
	return 0;
}

void Right(int board[][4], int& tileAddCount)
{
	int minus_index = 4;
	tileAddCount = 0;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 3; j >= 0; j--)
		{
			if (board[i][j] != 0)
			{
				int k = j;
				int row_j = j + 1;
				while (row_j < minus_index)
				{
					minus_index -= Add(board, i, k, i, row_j, tileAddCount);
					k = row_j;
					row_j++;
					if (tileAddCount == 1)
					{
						break;
					}
				}
				tileAddCount = 0;
			}
		}
		minus_index = 4;
	}
}

void Left(int board[][4], int& tileAddCount)
{
	int minus_index = 0;
	tileAddCount = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (board[i][j] != 0)
			{
				int k = j;
				int row_j = j - 1;
				while (row_j >= minus_index)
				{
					minus_index += Add(board, i, k, i, row_j, tileAddCount);
					k = row_j;
					row_j--;
					if (tileAddCount == 1)
					{
						break;
					}
				}
				tileAddCount = 0;
			}
		}
		minus_index = 0;
	}
}

void Up(int board[][4], int& tileAddCount)
{
	int minus_index = 0;
	tileAddCount = 0;
	for (int j = 0; j < 4; j++)
	{
		for (int i = 0; i < 4; i++)
		{
			if (board[i][j] != 0)
			{
				int k = i;
				int col_i = i - 1;
				while (col_i >= minus_index)
				{
					minus_index += Add(board, k, j, col_i, j, tileAddCount);
					k = col_i;
					col_i--;
					if (tileAddCount == 1)
					{
						break;
					}
				}
				tileAddCount = 0;
			}
		}
		minus_index = 0;
	}
}

void Down(int board[][4], int& tileAddCount)
{
	int minus_index = 4;
	tileAddCount = 0;
	for (int j = 0; j < 4; j++)
	{
		for (int i = 3; i >= 0; i--)
		{
			if (board[i][j] != 0)
			{
				int k = i;
				int col_i = i + 1;
				while (col_i < minus_index)
				{
					minus_index -= Add(board, k, j, col_i, j, tileAddCount);
					k = col_i;
					col_i++;
					if (tileAddCount == 1)
					{
						break;
					}
				}
				tileAddCount = 0;
			}
		}
		minus_index = 4;
	}
}

bool randomTile(int board[][4])
{
	bool flag = false;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (board[i][j] == 0)
			{
				flag = true; // There is free space
			}
		}
	}
	while (flag == true)
	{
		int four_or_two = rand() % 2;
		int x = rand() % 4;
		int y = rand() % 4;
		if (board[x][y] == 0)
		{
			if (four_or_two == 0)
			{
				board[x][y] = 2;
			}
			else
			{
				board[x][y] = 4;
			}
			return 1; //Random Number inserted
		}
	}
	return 0;     //There was no free space
}

void color_code(int arr_color[], int num)
{
	//This function will provide us with the color codes we require.
	if (num > 256) {
		num -= 251;
	}
	if (num == 2) {
		arr_color[0] = 72;
		arr_color[1] = 201;
		arr_color[2] = 176;
		return;
	}
	else if (num == 4) {
		arr_color[0] = 88;
		arr_color[1] = 214;
		arr_color[2] = 141;
		return;

	}
	else if (num == 8) {
		arr_color[0] = 244;
		arr_color[1] = 208;
		arr_color[2] = 63;
		return;
	}
	else if (num == 16) {
		arr_color[0] = 220;
		arr_color[1] = 118;
		arr_color[2] = 51;
		return;
	}
	else if (num == 32) {
		arr_color[0] = 14;
		arr_color[1] = 102;
		arr_color[2] = 85;
		return;
	}
	else if (num == 64) {
		arr_color[0] = 26;
		arr_color[1] = 82;
		arr_color[2] = 185;
		return;
	}
	else if (num == 128) {
		arr_color[0] = 214;
		arr_color[1] = 137;
		arr_color[2] = 14;
		return;
	}
	else if (num == 256) {
		arr_color[0] = 153;
		arr_color[1] = 163;
		arr_color[2] = 164;
		return;
	}
	else if (num == 512) {
		arr_color[0] = 249;
		arr_color[1] = 231;
		arr_color[2] = 160;
		return;
	}
	else if (num == 1024) {
		arr_color[0] = 255;
		arr_color[1] = 215;
		arr_color[2] = 20;
		return;
	}
	else if (num == 2048) {
		arr_color[0] = 243;
		arr_color[1] = 156;
		arr_color[2] = 18;
		return;
	}
	else {
		for (int i = 0; i < 3; i++)
		{
			if (i == 0) {

				arr_color[i] = num * 10 + 256 + 1000 % 256;

			}
			if (i == 1) {
				arr_color[i] = num % 10 + 256 + 400 % 256;

			}
			if (i == 2) {
				arr_color[i] = 400 + num + 256 % 256;

			}
		}
	}
}

int countScore(int board[][4]) //Counts user's score
{
	int sum = 0;
	for (int a = 0; a < 4; ++a) {
		for (int b = 0; b < 4; ++b) {
			sum += board[a][b]; //This calculates and updates players score
		}
	}
	return sum;
}

int end_game(int board[][4])
{
	int zero_count = 0;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (board[i][j] == 2048)
			{
				return 1; //Game won
			}
			if (board[i][j] == 0)
			{
				zero_count += 1;
				return 0;  //Game continues
			}
		}
	}

	if (zero_count == 0)
	{
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				if (j < 3 && board[i][j] == board[i][j + 1])
				{   //this checks right
					return 0;     //Game Continues  
				}

				if (i < 3 && board[i][j] == board[i + 1][j])
				{
					return 0;    //Game Continues  
				}
			}
		}
	}
	return -1;   //Game Lost
}

void initialisation(int board[][4])
{
	for (int i = 0; i < 4; i++)     // initialises the board with '0'
	{
		for (int j = 0; j < 4; j++)
		{
			board[i][j] = 0;
		}
	}

	int x = rand() % 4;
	int y = rand() % 4;
	board[x][y] = 2;

	int a, b;
	a = rand() % 4;
	b = rand() % 4;

	while (a == x && b == y)
	{
		a = rand() % 4;
		b = rand() % 4;
	}

	board[a][b] = 2;
}

int main()
{
	//__________________________________________________SOUND_______________________________________________________________

		//sound objects
	SoundBuffer buffer_block;
	Sound sound_block;


	if (!buffer_block.loadFromFile("move3.wav"))
	{
		cerr << "No sound file found" << endl;
		return 0;
	}

	sound_block.setBuffer(buffer_block);
	sound_block.setVolume(60);



	Music start;
	if (!start.openFromFile("start.wav"))
	{
		return 0;
	}


	Music bg_music;
	if (!bg_music.openFromFile("bg1.1.wav"))
	{
		return 0;
	}

	bg_music.setVolume(20);
	bg_music.setLoop(true);
	bg_music.play();

	Music bg2_music;
	if (!bg2_music.openFromFile("bg_3.wav"))
	{
		return 0;
	}


	bg2_music.setVolume(100);
	bg2_music.setLoop(true);


	srand(time(0));
	int end;


	//__________________________________________________FILING______________________________________________________________
	const int arraySize = 500;
	int highScores[arraySize] = { 0 };

	// Read high scores from a file
	ifstream file1("File3.txt");
	if (!file1.is_open())
	{
		cerr << "No file found" << endl;
		return 0;
	}

	int score;
	int index = 0;

	while (file1 >> score && index < arraySize) 
	{
		highScores[index] = score;
		index++;
	}

	file1.close();


	//__________________________________________________INITIALIZATIONS_____________________________________________________________
	bool flag = false;
	//Weights for pixels
	int weight1 = 15;
	int weight2 = 10;


	//Changing colors, color codes
	int arr_color[3];
	int color_red;
	int color_green;
	int color_blue;
	int array_value_for_colors;


	const int size = 4;
	const float margin = 200.0f;
	int board[4][4] = { {0, 0, 0, 0},
						{0, 0, 0, 0},
						{0, 0, 0, 0},
						{0, 0, 0, 0} };
	float eachbox = 150.0f;

	// Initialising the first 2 tiles with 2 on a random place on the board
	initialisation(board);

	int tileAddCount = 0;

	bool game_play; // checks if there is space in the array


	//__________________________________________________FONTS USED_______________________________________________________________

	Font font;
	if (!font.loadFromFile("MinecraftTen-VGORe.ttf"))
	{
		cerr << "Error loading font" << endl;
		return 0;
	}
	Font font1;
	if (!font1.loadFromFile("BadMofo.ttf"))
	{
		cerr << "Error loading font" << endl;
		return 0;
	}
	Font font2;
	if (!font2.loadFromFile("trans___.ttf"))
	{
		cerr << "Error loading font" << endl;
		return 0;
	}

	Font font3;
	if (!font3.loadFromFile("pixel_2.ttf"))
	{
		cerr << "Error loading font" << endl;
		return 0;
	}

	RenderWindow window{ VideoMode(1920, 1080), "2048", Style::Default | Style::Fullscreen };

	//Menu
	//TEXT FOR MENU
	Text menu_text;
	menu_text.setFont(font1);
	menu_text.setFillColor(Color(255, 255, 255));
	menu_text.setCharacterSize(200);
	menu_text.setStyle(Text::Bold);
	//The String
	Text tx;
	tx.setFont(font);
	tx.setFillColor(Color(255, 255, 255));
	tx.setCharacterSize(42);
	tx.setStyle(Text::Bold);
	int size_windowx = (window.getSize().x - 600.0f) / 2;
	int size_windowy = (window.getSize().y - 600.0f) / 2;

	Text tx_samurai;
	tx_samurai.setFont(font3);
	tx_samurai.setFillColor(Color(255, 255, 255));
	tx_samurai.setCharacterSize(42);


	//Text for score

	//The String
	Text tx1;
	tx1.setFont(font1);
	tx1.setFillColor(Color(63, 56, 55));
	tx1.setCharacterSize(38);
	tx1.setStyle(Text::Bold);
	Text tx2;
	tx2.setFont(font1);
	tx2.setFillColor(Color(63, 56, 55));
	tx2.setCharacterSize(35);
	tx2.setStyle(Text::Bold);
	Text ex_text;
	ex_text.setFont(font);
	ex_text.setFillColor(Color(255, 255, 255));
	ex_text.setCharacterSize(24);
	ex_text.setStyle(Text::Bold);


	//allignment for menu text
	float centerX = window.getSize().x / 2.f;
	float centerY = window.getSize().y / 2.f;
	string menutx = "2048";
	string meanddaniboi = "Ahmed Salman 23L-0678\nDaniyal Zaidi 23L-0718";


	//__________________________________________________OBJECTS_____________________________________________________________

		//The Box

	RectangleShape box(Vector2f(eachbox, eachbox));
	box.setFillColor(Color(63, 56, 55));
	box.setOutlineColor(Color(194, 184, 182));
	box.setOutlineThickness(3.0f);

	//Creating player's score box

	int your_score = 0; //This displays the players score
	RectangleShape box1(Vector2f(150, 50));
	box1.setFillColor(Color(236, 240, 231));
	box1.setOutlineColor(Color(34, 31, 30));
	box1.setOutlineThickness(5.0f);
	FloatRect textBounds1 = tx.getLocalBounds();
	box1.setPosition(10.0f, 50.0f);

	//Creating a menu score box

	RectangleShape box2(Vector2f(150, 50));
	box2.setFillColor(Color(236, 240, 231));
	box2.setOutlineColor(Color(34, 31, 30));
	box2.setOutlineThickness(5.0f);
	box2.setPosition(10.0f, 150.0f);
	//Creating a menu for the game


//__________________________________________________TEXTURES_____________________________________________________________

	//Texture Background (image for the game's menu)
	Texture texture;
	texture.loadFromFile("texture 1.7.jpg");
	Sprite texture_Background;
	texture_Background.setTexture(texture);
	//Textures - Menu Boxes
	Texture texture_menu1, texture_menu2, texture_menu3;
	texture_menu1.loadFromFile("menu_box1.png");
	texture_menu3.loadFromFile("menu_box3.png");
	texture_menu2.loadFromFile("menu_box2.png");
	Sprite tex_men1;
	Sprite tex_men2;
	Sprite tex_men3;
	tex_men1.setTexture(texture_menu1);
	tex_men2.setTexture(texture_menu2);
	tex_men3.setTexture(texture_menu3);
	tex_men1.setScale(0.5, 0.2);
	tex_men2.setScale(0.2, 0.2);
	tex_men3.setScale(0.2, 0.2);
	//Movement Key Textures
	float iconSize = 50.0f;
	float spacing = 10.0f;
	Texture upTexture, downTexture, leftTexture, rightTexture;
	upTexture.loadFromFile("up.png");
	downTexture.loadFromFile("down.png");
	leftTexture.loadFromFile("left.png");
	rightTexture.loadFromFile("right.png");
	Sprite upArrow(upTexture);
	Sprite downArrow(downTexture);
	Sprite leftArrow(leftTexture);
	Sprite rightArrow(rightTexture);
	float scaleFactor = 0.25f;
	upArrow.setScale(scaleFactor, scaleFactor);
	downArrow.setScale(scaleFactor, scaleFactor);
	leftArrow.setScale(scaleFactor, scaleFactor);
	rightArrow.setScale(scaleFactor, scaleFactor);

	//Texture - Menu Background
	Texture tex1;
	tex1.loadFromFile("516519.jpg");
	Sprite tex;
	tex.setTexture(tex1);


	//__________________________________________________TIME____________________________________________________________

	Clock  timer4;

	float visibilityDuration4 = 1.0f; // seconds
	bool arrowsVisible4 = true;


	//This loop is for the menu
	while (window.isOpen())
	{
		sf::Event event;

		// To exit the window/game
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case Event::KeyPressed:
				if (event.key.code == Keyboard::Escape) 
				{
					window.close();
					break;
				}
				if (event.key.code == Keyboard::P) 
				{
					flag = true;
					bg2_music.play();
					start.play();
					bg_music.stop();

					break;
				}
			}
		}


		//________________________________________________________MENU SCREEN_______________________________________________________________________
		if (flag == false)
		{
			ex_text.setCharacterSize(24);
			string word = "TOP 10 HIGHSCORES ";
			string word2 = "";
			string word3 = "PRESS  P   TO   PLAY\nPRESS ESC TO EXIT";
			string word4 = "MOVEMENT KEYS";
			int x1 = 10, y1 = 120;
			tex.setTexture(tex1);
			menu_text.setOrigin(menu_text.getLocalBounds().width / 2.f, (menu_text.getLocalBounds().height + 75) / 2.f);
			menu_text.setPosition(centerX, centerY - 400);
			menu_text.setString(menutx);
			window.clear();
			window.draw(tex); //draws the background
			window.draw(menu_text);//Displays text 


			ex_text.setString(meanddaniboi);
			ex_text.setPosition(10, 10);
			window.draw(ex_text);


			ex_text.setString(word); //Filing text
			ex_text.setPosition(10, 90);
			window.draw(ex_text);
			for (int i = 0; i < 10; i++)
			{
				word2 = to_string(i + 1) + ". " + to_string(highScores[i]);

				ex_text.setString(word2);
				ex_text.setPosition(x1, y1);
				window.draw(ex_text);
				y1 += 30; //preset gap in Y axis between our file's text
			}


			//Press P to Play, ESC to exit

			tex_men2.setPosition(5, 580);
			ex_text.setCharacterSize(50);
			ex_text.setString(word3);
			ex_text.setPosition(75, 625);

			if (timer4.getElapsedTime().asSeconds() >= visibilityDuration4)
			{
				arrowsVisible4 = !arrowsVisible4;
				timer4.restart();
			}
			if (arrowsVisible4)
			{
				window.draw(tex_men2);
				window.draw(ex_text);
			}
			//arrow textures
			tx.setString(word4);
			tx.setPosition(window.getSize().x - iconSize - spacing - 550, window.getSize().y - iconSize - spacing - 500);
			tx.setCharacterSize(50);
			window.draw(tx);


			upArrow.setPosition(window.getSize().x - iconSize - spacing - 400, window.getSize().y - iconSize - spacing - 400);
			downArrow.setPosition(window.getSize().x - iconSize - spacing - 400, window.getSize().y - spacing - 300);
			leftArrow.setPosition(window.getSize().x - iconSize - spacing - 550, window.getSize().y - spacing - 300);
			rightArrow.setPosition(window.getSize().x - iconSize - spacing - 250, window.getSize().y - spacing - 300);


			window.draw(upArrow);
			window.draw(downArrow);
			window.draw(leftArrow);
			window.draw(rightArrow);
			window.display();
			window.clear();
		}


		//__________________________________________________________MAIN GAME______________________________________________________________________________

		ex_text.setCharacterSize(24);
		tx.setCharacterSize(42);//resets our main game's font size

		if (flag == true)
		{
			texture_Background.setTexture(texture);
			window.draw(texture_Background); //draws the background
			window.draw(box1);//Displays the box
			ex_text.setString("YOUR SCORE: ");
			ex_text.setPosition(10, 10);
			window.draw(ex_text);
			/*window.draw(box2);*/

			/* Draw the board*/
			for (int i = 0; i < 4; ++i)
			{
				for (int j = 0; j < 4; ++j)
				{
					box.setPosition(size_windowx + j * (eachbox), size_windowy + i * eachbox);
					array_value_for_colors = board[i][j];
					if (array_value_for_colors != 0)
					{
						color_code(arr_color, array_value_for_colors); //Function call to get our respective color
						color_red = arr_color[0];
						color_green = arr_color[1];
						color_blue = arr_color[2];
						box.setFillColor(Color(color_red, color_green, color_blue));
					}
					if (array_value_for_colors == 0)
					{
						box.setFillColor(Color(63, 56, 55));
					}
					window.draw(box);

					//adjusts weight for score
					if (board[i][j] >= 10)
					{
						weight1 = 35;
						weight2 = 15;
					}
					if (board[i][j] >= 100)
					{
						weight1 = 70;
						weight2 = 30;
					}
					if (board[i][j] >= 1000)
					{
						weight1 = 105;
						weight2 = 45;
					}
					if (board[i][j] < 10)
					{
						weight1 = 20;
						weight2 = 5;
					}


					if (board[i][j] != 0)
					{
						tx.setPosition((size_windowx - weight2 + 5) + j * (eachbox)+0.4f * eachbox, (size_windowy + 18) + i * eachbox + 0.2f * eachbox);
						tx.setString(to_string(board[i][j]));
						window.draw(tx);
					}

					//Calculates players score
					your_score = countScore(board);
					tx1.setString(to_string(your_score));

					tx1.setPosition(box1.getPosition().x + ((box1.getSize().x - 35) - textBounds1.width) / 2,
						box1.getPosition().y - 5 + ((box1.getSize().y - 30) - textBounds1.height) / 2);


					window.draw(tx1);
				}
			}

			string win_loss = "", replay = "Press R to Replay, M to return to main menu\nESC to exit";
			int end;
			end = end_game(board);
			if (end == 1)
			{
				//Winning Screen

				win_loss = "2048 REACHED!";
				menu_text.setOrigin(menu_text.getLocalBounds().width / 2.f, menu_text.getLocalBounds().height / 2.f);
				menu_text.setString(win_loss);
				menu_text.setPosition(centerX, centerY - 500);
				window.draw(menu_text);
			}

			else if (end == -1)
			{
				//Losing Screen
				
				win_loss = "GAME OVER!";
				menu_text.setOrigin(menu_text.getLocalBounds().width / 2.f, menu_text.getLocalBounds().height / 2.f);
				menu_text.setPosition(centerX, centerY - 500);
				menu_text.setString(win_loss);
				window.draw(menu_text);
			}
			//option box

			string r = "'R' TO RESET";
			string m = "'M' TO EXIT TO MENU";
			string m_save = "M/ESC SAVES YOUR SCORE";
			string esc = "'ESC' TO EXIT THE GAME";
			tex_men1.setPosition(10, 325);
			window.draw(tex_men1);
			//options
			tx_samurai.setCharacterSize(35);
			tx_samurai.setString(r);
			tx_samurai.setPosition(60, 375);
			window.draw(tx_samurai);
			tx_samurai.setString(m);
			tx_samurai.setPosition(60, 475);
			window.draw(tx_samurai);
			tx_samurai.setString(esc);
			tx_samurai.setPosition(60, 575);
			window.draw(tx_samurai);
			tx_samurai.setString(m_save);
			tx_samurai.setPosition(60, 675);
			window.draw(tx_samurai);
			window.display();    // displays all of the drawn objects

			//main game

			sf::Event keypres;

			while (window.pollEvent(keypres))
			{
				switch (keypres.type)
				{
				case Event::Closed:
					if (index < 500)
					{
						highScores[index] = your_score;
						index++;
					}

					for (int i = 0; i < index - 1; ++i)
					{
						for (int j = 0; j < index - i - 1; ++j)
						{
							if (highScores[j] < highScores[j + 1])
							{
								//Sorts in decsending
								swap(highScores[j], highScores[j + 1]);
							}
						}
					}
					window.close();
					break;


				case Event::KeyPressed:

					if (end != -1 && end != 1)
					{
						// registers the move made by the user: Right, Left, Up, Down
						if (keypres.key.code == Keyboard::Right)
						{
							Right(board, tileAddCount);
							game_play = randomTile(board); // generates a random tile on the unoccupied places on the board
						
							sound_block.play();
						}
						else if (keypres.key.code == Keyboard::Left)
						{
							Left(board, tileAddCount);
							game_play = randomTile(board); // generates a random tile on the unoccupied places on the board

							sound_block.play();
						}
						else if (keypres.key.code == Keyboard::Up)
						{
							Up(board, tileAddCount);
							game_play = randomTile(board); // generates a random tile on the unoccupied places on the board

							sound_block.play();	
						}
						else if (keypres.key.code == Keyboard::Down)
						{
							Down(board, tileAddCount);
							game_play = randomTile(board); // generates a random tile on the unoccupied places on the board

							sound_block.play();
						}
					}
					if (keypres.key.code == Keyboard::Escape)
					{
						bg2_music.stop();
						if (index < 500)
						{
							highScores[index] = your_score;
							index++;
						}

						for (int i = 0; i < index - 1; ++i)
						{
							for (int j = 0; j < index - i - 1; ++j)
							{
								if (highScores[j] < highScores[j + 1])
								{
									//Sorts in decsending
									swap(highScores[j], highScores[j + 1]);
								}
							}
						}
						window.close();
					}
					else if (keypres.key.code == Keyboard::R)
					{
						initialisation(board);

						highScores[index] = your_score;
						index++;
						for (int i = 0; i < index - 1; ++i)
						{
							for (int j = 0; j < index - i - 1; ++j)
							{
								if (highScores[j] < highScores[j + 1])
								{
									//Sorts in decsending
									swap(highScores[j], highScores[j + 1]);
								}
							}
						}
					}
					else if (keypres.key.code == Keyboard::M)
					{
						bg2_music.stop();
						bg_music.play();
						flag = false;

						highScores[index] = your_score;
						index++;

						initialisation(board);

						for (int i = 0; i < index - 1; ++i)
						{
							for (int j = 0; j < index - i - 1; ++j)
							{
								if (highScores[j] < highScores[j + 1])
								{
									//Sorts in decsending
									swap(highScores[j], highScores[j + 1]);
								}
							}
						}
					}
					break;
				}
			}

			
		}
	}


	//__________________________________________________FILING (2)______________________________________________________________

	ofstream file2("File3.txt", ios::out);

	if (!file2.is_open())
	{
		cerr << "No file found" << endl;
		return 0;
	}

	for (int i = 0; i < index; i++)
	{
		file2 << highScores[i] << '\n';
	}

	file2.close();
	//sound_bg.stop();
	return 0;
}
