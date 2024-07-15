#include<iostream>
//#include<bits/stdc++.h>
#include <cmath>

#include "iGraphics.h"
using namespace std;
#define screenwidthOfFirstGame 1000
#define screenheightOfFirstGame (screenwidthOfFirstGame)*(0.47)
int boardsizeOfFirstGame = 100;
int Xball = screenwidthOfFirstGame*(0.5);
int Yball = screenheightOfFirstGame*(0.5);
int dxball = 5;
int dyball = 6;
int boardHeight = 10;
int radiusball = 6;
int gap_board_wall = 5;
int playerAboard_X = gap_board_wall;
int playerAboard_Y = screenheightOfFirstGame*0.4;
int playerAboard_dx = boardHeight;
int playerBboard_X = screenwidthOfFirstGame - gap_board_wall - boardHeight;
int playerBboard_Y = screenheightOfFirstGame*0.4;
int playerBboard_dx = boardHeight;
char stages[20][50] = { "assets\\openingpage.bmp", "assets\\home.bmp", "assets\\instraction.bmp", "assets\\background.bmp", "assets\\score.bmp", "assets\\ending.bmp", "assets\\winnerpost.bmp", "assets\\selection.bmp" };
int game = 0;
int gamestateOfFirstGame = 7;
int PlayerAScore = 0;
int PlayerBScore = 0;
//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::Idraw Here::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::://

#define totalBricks 5*10
#define tottalBricks2 5*12
#define screenWidth 1156
#define screenHeight 650
#define yAxisMargin 50
#define qetaDefine 0
#define PI 3.14159265
int mposx, mposy;
struct brickStructure
{
	int x;
	int y;
	int dx = 100;
	int dy = 20;
	bool show = true;
	int red;
	int green;
	int blue;


};
brickStructure bricks[totalBricks];


int score = 0;
int score2 = 0;
int gamestate = -1;

int red = 0;
int green = 255;
int blue = 0;

// for board  


int boardSpeed = 35;

// Co Ordinate of Ball 


int xBall = (int)screenWidth / 2;
int yBall = yAxisMargin;
int radiusBall = 10;
//int dx = 7;
//int dy = 5;

// for changing angle(Change Variable)

int v = 15;
int qeta = 30;
int dx = (int)v*cos(qeta*PI / 180);
int dy = (int)v*sin(qeta*PI / 180);

// board position

int xBoard = (xBall - 50);
int yBoard = yBall - 20;
int dxBoard = 100;
int dyBoard = 10;

// Music,Life,High Score Controller Variable

bool isStarted = false;
bool musicOn = false;
int life = 3;
int high = 0;
// function
void ballChange();
void restartBall();
void defineBricks();
char *num_to_char(long long num, char *scr){
	long long r, i = 0, n = num, j;
	while (1){
		r = n % 10;
		scr[i] = (48 + r);
		n /= 10;
		if (n == 0){
			break;
		}
		i++;
	}
	scr[i + 1] = '\0';
	for (i = 0, j = strlen(scr) - 1; i<strlen(scr) / 2; i++, j--){
		swap(scr[i], scr[j]);
	}
	return scr;
}

char backGroundImage[100] = "pic//bg4.bmp";
char menu[20][100] = { "pic//start.bmp", "pic//b_help.bmp", "pic//b_instruction.bmp", "pic//b_highScore.bmp" };
char menu2[20][100] = { "pic//musicOn.bmp", "pic//musicOff.bmp", "pic//b_aboutUs.bmp", "pic//exitGame.bmp" };

void restartBall()
{
	xBall = (int)screenWidth / 2;
	yBall = yAxisMargin;
	dx = (int)v*cos(qeta*PI / 180);
	dy = (int)v*sin(qeta*PI / 180);
	xBoard = xBall - 50;
	yBoard = yBall - 20;

	isStarted = false;

}
void defineBricks()
{
	int sumx = 100;
	int sumy = 450;
	for (int i = 0; i < totalBricks; i++)
	{
		bricks[i].red = rand() % 255;
		bricks[i].green = rand() % 255;
		bricks[i].blue = rand() % 255;
		bricks[i].x = sumx;
		bricks[i].y = sumy;
		sumx += 100;
		if (sumx>1000)
		{
			sumx = 100;
			sumy += 20;

		}


	}
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void iDraw()
{
	iClear();
	if (game == 0 && gamestateOfFirstGame == 7){
		iShowBMP(0, 0, stages[gamestateOfFirstGame]);
	}
	if (game == 2){
		if (gamestateOfFirstGame == 0)
		{
			iShowBMP(0, 0, stages[gamestateOfFirstGame]);
		}
		else if (gamestateOfFirstGame == 1)
		{
			iShowBMP(0, 0, stages[gamestateOfFirstGame]);
		}
		else if (gamestateOfFirstGame == 2)
		{
			iShowBMP(0, 0, stages[gamestateOfFirstGame]);
		}
		else if (gamestateOfFirstGame == 3){
			iShowBMP(0, 0, stages[gamestateOfFirstGame]);
			iSetColor(255, 165, 0);
			iFilledCircle(Xball, Yball, radiusball, 1000);
			iSetColor(116, 161, 142);
			iFilledRectangle(playerAboard_X, playerAboard_Y, playerAboard_dx, boardsizeOfFirstGame);

			iSetColor(165, 42, 42);
			iFilledRectangle(playerBboard_X, playerBboard_Y, playerBboard_dx, boardsizeOfFirstGame);

			iSetColor(255, 255, 255);
			for (int i = screenheightOfFirstGame; i >= 10; i = i - 20)
			{
				iLine(500, i, 500, i - 10);
				iLine(499, i, 499, i - 10);
			}

			if (PlayerAScore == 0)
			{
				iText(467, 433, "0", GLUT_BITMAP_TIMES_ROMAN_24);

				//iText(518, 433, "0", GLUT_BITMAP_TIMES_ROMAN_24);

			}
			else if (PlayerAScore == 1)
			{
				iText(467, 433, "1", GLUT_BITMAP_TIMES_ROMAN_24);
			}
			else if (PlayerAScore == 2)
			{
				iText(467, 433, "2", GLUT_BITMAP_TIMES_ROMAN_24);
			}
			else if (PlayerAScore == 3)
			{
				iText(467, 433, "3", GLUT_BITMAP_TIMES_ROMAN_24);
			}
			else if (PlayerAScore == 4)
			{
				iText(467, 433, "4", GLUT_BITMAP_TIMES_ROMAN_24);
			}
			else if (PlayerAScore == 5)
			{
				iText(467, 433, "5", GLUT_BITMAP_TIMES_ROMAN_24);
			}
			else if (PlayerAScore == 6)
			{
				iText(467, 433, "6", GLUT_BITMAP_TIMES_ROMAN_24);
			}
			else if (PlayerAScore == 7)
			{
				iText(467, 433, "7", GLUT_BITMAP_TIMES_ROMAN_24);
			}
			else if (PlayerAScore == 8)
			{
				iText(467, 433, "8", GLUT_BITMAP_TIMES_ROMAN_24);
			}
			else if (PlayerAScore == 9)
			{
				iText(467, 433, "9", GLUT_BITMAP_TIMES_ROMAN_24);
			}
			else if (PlayerAScore == 10)
			{
				iText(467, 433, "10", GLUT_BITMAP_TIMES_ROMAN_24);
			}
			if (PlayerBScore == 0)
			{
				iText(518, 433, "0", GLUT_BITMAP_TIMES_ROMAN_24);
			}
			else if (PlayerBScore == 1)
			{
				iText(518, 433, "1", GLUT_BITMAP_TIMES_ROMAN_24);
			}
			else if (PlayerBScore == 2)
			{
				iText(518, 433, "2", GLUT_BITMAP_TIMES_ROMAN_24);
			}
			else if (PlayerBScore == 3)
			{
				iText(518, 433, "3", GLUT_BITMAP_TIMES_ROMAN_24);
			}
			else if (PlayerBScore == 4)
			{
				iText(518, 433, "4", GLUT_BITMAP_TIMES_ROMAN_24);
			}
			else if (PlayerBScore == 5)
			{
				iText(518, 433, "5", GLUT_BITMAP_TIMES_ROMAN_24);
			}
			else if (PlayerBScore == 6)
			{
				iText(518, 433, "6", GLUT_BITMAP_TIMES_ROMAN_24);
			}
			else if (PlayerBScore == 7)
			{
				iText(518, 433, "7", GLUT_BITMAP_TIMES_ROMAN_24);
			}
			else if (PlayerBScore == 8)
			{
				iText(518, 433, "8", GLUT_BITMAP_TIMES_ROMAN_24);
			}
			else if (PlayerBScore == 9)
			{
				iText(518, 433, "9", GLUT_BITMAP_TIMES_ROMAN_24);
			}
			else if (PlayerBScore == 10)
			{
				iText(518, 433, "10", GLUT_BITMAP_TIMES_ROMAN_24);
			}
			if (PlayerAScore == 10 || PlayerBScore == 10){
				gamestateOfFirstGame = 6;
			}
		}
		else if (gamestateOfFirstGame == 4)
		{
			iShowBMP(0, 0, stages[gamestateOfFirstGame]);
		}
		else if (gamestateOfFirstGame == 5)
		{
			iShowBMP(0, 0, stages[gamestateOfFirstGame]);
		}
		else if (gamestateOfFirstGame == 6){
			if (PlayerAScore == 10){
				iShowBMP(0, 0, stages[gamestateOfFirstGame]);
				iText(112, 289, "Player A Win The Game !!! ", GLUT_BITMAP_TIMES_ROMAN_24);
			}
			else {
				iShowBMP(0, 0, stages[gamestateOfFirstGame]);
				iText(112, 289, "Player B Win The Game !!! ", GLUT_BITMAP_TIMES_ROMAN_24);
			}
		}
	}
	else if (game == 1){
		if (gamestate == -1)
		{

			iShowBMP(0, 0, "pic//home0.bmp");

			iSetColor(rand() % 255, rand() % 255, rand() % 255);
			iText((int)screenWidth / 2 - 120, (int)screenHeight / 2 - 100, "Press 'ENTER' Key to Continue!!", GLUT_BITMAP_HELVETICA_18);
		}

		// main menu 

		if (gamestate == 0)
		{
			iShowBMP(0, 0, "pic//home1.bmp");
			int sum = 0;
			int button_x = 290;
			int button_y = 30;
			for (int i = 3; i >= 0; i--)
			{
				iShowBMP2(button_x, button_y, menu[i], 0);
				button_y += 120;
			}
			for (int i = 3, button_y = 30; i >= 0; i--)
			{
				iShowBMP2(button_x + 380, button_y, menu2[i], 0);
				button_y += 120;
			}


		}

		// main Game

		if (gamestate == 1)
		{

			iShowBMP(0, 0, backGroundImage);
			char s[10];
			char t[20] = "SCORE :";
			char l[20] = "LIFE :";
			char li[10];
			num_to_char(score, s);
			num_to_char(life, li);

			//iSetColor(0, 255, 0);
			//iText(1030, 630, t, GLUT_BITMAP_TIMES_ROMAN_24);
			iShowBMP2(1016, 620, "pic//score.bmp", 0);

			iSetColor(255, 0, 0);
			iText(1125, 628, s, GLUT_BITMAP_TIMES_ROMAN_24);

			//iSetColor(0, 255, 0);
			//iText(0, 630, l, GLUT_BITMAP_TIMES_ROMAN_24);
			iShowBMP2(0, 620, "pic//life.bmp", 0);
			iSetColor(255, 0, 0);
			iText(110, 628, li, GLUT_BITMAP_TIMES_ROMAN_24);

			//iShowBMP(0, 0, "pic//exit.bmp");
			iSetColor(255, 0, 0);

			iFilledCircle(xBall, yBall, radiusBall, 1000);
			iSetColor(red, green, blue);
			iFilledRectangle(xBoard, yBoard, dxBoard, dyBoard);
			iSetColor(100, 15, 0);
			iFilledRectangle(0, 0, screenWidth, yAxisMargin - dyBoard - 9);
			iShowBMP2(0, 0, "pic//mainMenu2.bmp", 0);
			iShowBMP2(1056, 0, "pic//exit.bmp", 0);
			//iSetColor(255, 0, 0);
			//iText(20, 20, "EXIT", GLUT_BITMAP_HELVETICA_18);
			//iShowBMP2(20, 20, "pic//exit.bmp",0);

			for (int i = 0; i < totalBricks; i++)
			{
				if (bricks[i].show)
				{
					iSetColor(bricks[i].red, bricks[i].green, bricks[i].blue);
					iFilledRectangle(bricks[i].x, bricks[i].y, bricks[i].dx, bricks[i].dy);
				}
			}


		}
		// high Score
		if (gamestate == 2)
		{

			iShowBMP(0, 0, "pic//highScore.bmp");
			char s[10];
			num_to_char(high, s);
			iText((int)screenWidth / 2, (int)screenHeight / 2, s, GLUT_BITMAP_TIMES_ROMAN_24);


			iShowBMP2(10, 10, "pic//mainMenu.bmp", 0);
			iShowBMP2(966, 10, "pic//exitGame.bmp", 0);



		}
		// Instruction

		if (gamestate == 3)
		{
			iShowBMP(0, 0, "pic//instruction.bmp");
			iShowBMP2(0, 0, "pic//mainMenu.bmp", 0);
			iShowBMP2(976, 0, "pic//exitGame.bmp", 0);
		}

		// Help

		if (gamestate == 4)
		{
			iShowBMP(0, 0, "pic//help.bmp");
			iShowBMP2(0, 0, "pic//mainMenu.bmp", 0);
			iShowBMP2(976, 0, "pic//exitGame.bmp", 0);
		}

		// Exit

		if (gamestate == 5)
		{
			exit(0);
		}

		// About Us

		if (gamestate == 6)
		{
			iShowBMP(0, 0, "pic//aboutUs.bmp");
			iShowBMP2(0, 0, "pic//mainMenu.bmp", 0);
			iShowBMP2(976, 0, "pic//exitGame.bmp", 0);
		}

		// Your Score

		if (gamestate == 7)
		{
			char s[10];
			num_to_char(score, s);
			iShowBMP(0, 0, "pic//yourScore.bmp");
			iSetColor(255, 0, 0);
			iText(700, 440, s, GLUT_BITMAP_TIMES_ROMAN_24);
			iShowBMP2(10, 10, "pic//playAgain.bmp", 0);
			iShowBMP2((int)iScreenWidth / 2 - 90, 10, "pic//mainMenu.bmp", 0);
			iShowBMP2(966, 10, "pic//exitGame.bmp", 0);

		}
	}

}





/*function iMouseMove() is called when the user presses and drags the mouse.
(mx, my) is the position where the mouse pointer is.
*/


void iMouseMove(int mx, int my)
{

}
//*******************************************************************ipassiveMouse***********************************************************************//
void iPassiveMouseMove(int mx, int my)
{

}

void iMouse(int button, int state, int mx, int my)
{

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		cout << mx << " " << my << endl;
		if (gamestateOfFirstGame == 7){
			int radiusOfFirstGameLogo = 80, radisuOfSecondLogo = 73;
			int centerOfFirstLogoX = 366, centerOfFirstLogoY = 210, centerOfSecondLogoX = 629, centerOfSecondLogoY = 208;
			int isValidFirstGame = pow(abs(mx - centerOfFirstLogoX), 2) + pow(abs(my - centerOfFirstLogoY), 2);
			int isValidSecondGame = pow(abs(mx - centerOfSecondLogoX), 2) + pow(abs(my - centerOfSecondLogoY), 2);
			cout << isValidFirstGame << " ";
			//int diameterOfSecondGameLogo=
			if (isValidFirstGame <= radiusOfFirstGameLogo*radiusOfFirstGameLogo){
				//cout << "YES";
				game = 1;
				
			}
			else if (isValidSecondGame <= radisuOfSecondLogo*radisuOfSecondLogo){
				game = 2;
				gamestateOfFirstGame = 0;
				//cout << "YES";
			}
		}
		if (game == 2){
			if (gamestateOfFirstGame == 1)
			{
				if (mx >= 282 && mx <= 350 && my >= 269 && my <= 323)
				{
					gamestateOfFirstGame = 3;
				}
				else if (mx >= 595 && mx <= 664 && my >= 268 && my <= 330)
				{
					gamestateOfFirstGame = 2;
				}
				else if (mx >= 428 && mx <= 511 && my >= 270 && my <= 322)
				{
					gamestateOfFirstGame = 4;
				}
				else if (mx >= 532 && mx <= 608 && my >= 164 && my <= 201)
				{
					exit(0);
				}
			}
			else if (gamestateOfFirstGame == 2)
			{
				if (mx >= 460 && mx <= 531 && my >= 28 && my <= 77)
				{
					gamestateOfFirstGame = 1;
				}
			}
			else if (gamestateOfFirstGame == 4)
			{
				if (mx >= 440 && mx <= 510 && my >= 43 && my <= 92)
				{
					gamestateOfFirstGame = 1;
				}
			}
			else if (gamestateOfFirstGame == 5)
			{
				if (mx >= 512 && mx <= 585 && my >= 71 && my <= 112)
				{
					gamestateOfFirstGame = 1;
				}
				if (mx >= 624 && mx <= 698 && my >= 70 && my <= 113){
					exit(0);

				}
			}

		}
		else if (game == 1){
			if (gamestate == 0){
				int sum = 0;
				int button_x = 290;
				int button_y = 30;

				if (mx >= button_x && mx <= button_x + 180 && my >= button_y + sum  && my <= button_y + sum + 80)
				{

					gamestate = 2;

				}
				sum += 120;
				if (mx >= button_x && mx <= button_x + 180 && my >= button_y + sum  && my <= button_y + sum + 80)
				{

					gamestate = 3;

				}
				sum += 120;
				if (mx >= button_x && mx <= button_x + 180 && my >= button_y + sum  && my <= button_y + sum + 80)
				{

					gamestate = 4;

				}
				sum += 120;
				if (mx >= button_x && mx <= button_x + 180 && my >= button_y + sum  && my <= button_y + sum + 80)
				{

					gamestate = 1;

				}
				sum += 120;
				int sum2 = 0;
				int rightB = button_x + 380;
				if (mx >= rightB && mx <= rightB + 180 && my >= button_y + sum2 && my <= button_y + sum2 + 80)
				{

					gamestate = 5;

				}
				sum2 += 120;
				if (mx >= rightB && mx <= rightB + 180 && my >= button_y + sum2 && my <= button_y + sum2 + 80)
				{

					gamestate = 6;

				}
				sum2 += 120;
				if (mx >= rightB && mx <= rightB + 180 && my >= button_y + sum2 && my <= button_y + sum2 + 80)
				{

					musicOn = false;
					PlaySound(0, 0, 0);

				}
				sum2 += 120;
				if (mx >= rightB && mx <= rightB + 180 && my >= button_y + sum2 && my <= button_y + sum2 + 80)
				{

					musicOn = true;
					if (musicOn)
						PlaySound("music\\bg1.wav", NULL, SND_LOOP || SND_ASYNC);

				}
			}
			if (gamestate == 1)
			{
				if (mx <= 100 && my <= 30)
				{
					gamestate = 0;
				}
				if (mx >= 1056 && mx <= 1156 && my >= 0 && my <= 30)
				{

					gamestate = 5;

				}


			}
			if (gamestate == 2)
			{
				if (mx >= 10 && mx <= 190 && my >= 10 && my <= 90)

				{

					gamestate = 0;
				}
				if (mx >= 966 && mx <= 1146 && my >= 10 && my <= 90)
				{

					gamestate = 5;
				}

			}
			if (gamestate == 3)
			{
				if (mx >= 0 && mx <= 180 && my >= 0 && my <= 80)
				{

					gamestate = 0;
				}
				if (mx >= 976 && mx <= 1156 && my >= 0 && my <= 80)

				{

					gamestate = 5;
				}
			}
			if (gamestate == 4)
			{
				if (mx >= 0 && mx <= 180 && my >= 0 && my <= 80)
				{

					gamestate = 0;
				}
				if (mx >= 976 && mx <= 1156 && my >= 0 && my <= 80)
				{

					gamestate = 5;
				}

			}
			if (gamestate == 6)
			{
				if (mx >= 0 && mx <= 180 && my >= 0 && my <= 80)
				{

					gamestate = 0;
				}

				if (mx >= 976 && mx <= 1156 && my >= 0 && my <= 80)
				{

					gamestate = 5;
				}

			}
			if (gamestate == 7)
			{
				if (mx >= 10 && mx <= 190 && my >= 10 && my <= 90)

				{

					life = 3;

					score = 0;
					for (int i = 0; i < totalBricks; i++)
					{
						bricks[i].show = true;
					}
					gamestate = 1;
				}

				if (mx >= 966 && mx <= 1146 && my >= 10 && my <= 90)
				{

					life = 3;

					score = 0;
					for (int i = 0; i < totalBricks; i++)
					{
						bricks[i].show = true;
					}
					gamestate = 5;
				}
				if (mx >= ((int)iScreenWidth / 2 - 90) && mx <= ((int)iScreenWidth / 2 + 90) && my >= 10 && my <= 90)
				{

					gamestate = 0;
				}
			}

		}

	}

	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{

	}
}

/*
function iKeyboard() is called whenever the user hits a key in keyboard.
key- holds the ASCII value of the key pressed.
*/


void iKeyboard(unsigned char key)
{
	if (game = 2){
		if (key == 'w')
		{
			if (playerAboard_Y < screenheightOfFirstGame - boardsizeOfFirstGame)
			{
				playerAboard_Y += 14;
			}
		}
		if (key == 's')
		{
			if (playerAboard_Y>0)
			{
				playerAboard_Y -= 14;
			}
		}
		if (key == ' ')
		{
			gamestateOfFirstGame = 1;
		}
	}
	else if (game == 1){
		if (key == '\r')
		{
			gamestate = 0;
		}
		else if (key == 'm')
		{

			musicOn = false;

			PlaySound(0, 0, 0);

			if (!musicOn)
			{
				musicOn = true;
				if (musicOn)
					PlaySound("music\\bg1.wav", NULL, SND_LOOP || SND_ASYNC);
			}



		}

		// Moving The Borad with Ball

		else if (key == 's')
		{
			if (xBoard > 0)
			{
				xBoard -= boardSpeed;
				if (!isStarted && gamestate == 1)
				{
					xBall -= boardSpeed;
				}
			}
		}
		else if (key == 'd')
		{
			if (xBoard < screenWidth - dxBoard)
			{
				xBoard += boardSpeed;
				if (!isStarted && gamestate == 1)
				{
					xBall += boardSpeed;
				}
			}
		}
		// start the  ball moving

		else if (key == ' ')
		{

			if (!isStarted && gamestate == 1)
			{
				isStarted = true;
			}
		}
	}

}

/*
function iSpecialKeyboard() is called whenver user hits special keys like-
function keys, home, end, pg up, pg down, arraows etc. you have to use
appropriate constants to detect them. A list is:
GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{
	if (game == 2){

		if (key == GLUT_KEY_DOWN)
		{
			if (playerBboard_Y > 0){
				playerBboard_Y -= 9;
			}
		}
		if (key == GLUT_KEY_UP)
		{
			if (playerBboard_Y < screenheightOfFirstGame - boardsizeOfFirstGame){
				playerBboard_Y += 9;
			}
		}
	}
	else if (game == 1){
		if (key == GLUT_KEY_RIGHT)
		{
			if (xBoard < screenWidth - dxBoard)
			{
				xBoard += boardSpeed;
				if (!isStarted && gamestate == 1)
				{
					xBall += boardSpeed;
				}
			}
		}
		if (key == GLUT_KEY_LEFT)
		{
			if (xBoard > 0)
			{
				xBoard -= boardSpeed;
				if (!isStarted && gamestate == 1)
				{
					xBall -= boardSpeed;
				}
			}
		}

		if (key == GLUT_KEY_HOME)
		{

		}
	}

}
void ballchange(){
	if (game == 2){
		if (gamestateOfFirstGame == 3){
			Xball += dxball;
			Yball += dyball;
			if (Xball + radiusball >= screenwidthOfFirstGame || Xball - radiusball <= 0){
				//dxball *= (-1);
				if (Xball + radiusball >= screenwidthOfFirstGame)
				{
					dxball *= (-1);
					if (PlayerAScore < 10)
					{
						PlayerAScore++;
					}
				}
				else
				{
					dxball *= (-1);
					PlayerBScore++;
				}
			}
			if (Yball + radiusball >= screenheightOfFirstGame || Yball - radiusball <= 0){
				dyball *= (-1);
			}
			if (Xball - radiusball >= playerAboard_X && Xball - radiusball <= playerAboard_X + boardHeight &&  Yball - radiusball >= playerAboard_Y && Yball - radiusball <= playerAboard_Y + boardsizeOfFirstGame)
			{
				PlaySound("assets\\pong_sound.wav", NULL, SND_ASYNC);
				dxball *= (-1);
			}
			if (Xball + radiusball >= playerBboard_X && Xball + radiusball <= playerBboard_X + boardHeight &&  Yball + radiusball >= playerBboard_Y && Yball + radiusball <= playerBboard_Y + boardsizeOfFirstGame)
			{
				PlaySound("assets\\pong_sound.wav", NULL, SND_ASYNC);
				dxball *= (-1);
			}
			/*if (PlayerAScore == 10 || PlayerBScore == 10)
			{
			if (PlayerAScore > PlayerBScore)
			{
			PlayerAScore = 11;
			}
			else
			{
			PlayerBScore = 11;
			}
			}*/
		}
	}
	else if (game == 1){
		if (isStarted && gamestate == 1)
		{
			// Moving The Ball

			xBall += dx;
			yBall += dy;
			if (xBall >= screenWidth || xBall <= 0)
				dx *= (-1);
			if (yBall >= screenHeight || yBall <= 0)
				dy *= (-1);

			//collision
			for (int i = 0; i < totalBricks; i++)
			{

				if (bricks[i].show)
				{
					if (xBall >= bricks[i].x && xBall <= bricks[i].x + bricks[i].dx)
					{
						if (yBall >= bricks[i].y && yBall <= bricks[i].y + bricks[i].dy)
						{
							PlaySound("music\\brick.wav", NULL, SND_LOOP || SND_ASYNC);
							dy *= (-1);
							bricks[i].show = false;
							score++;
							if (score > high)
								high = score;

						}
					}

					else if (yBall >= bricks[i].y && yBall <= bricks[i].y + bricks[i].dy)
					{
						if (xBall >= bricks[i].x && xBall <= bricks[i].x + bricks[i].dx)
						{
							PlaySound("music\\brick.wav", NULL, SND_ASYNC);
							dy *= (-1);
							bricks[i].show = false;
							score++;
							if (score > high)
								high = score;
						}
					}

				}


			}


			if (xBall >= xBoard && xBall <= xBoard + dxBoard && yBall >= yBoard && yBall <= yBoard + dyBoard)
			{
				/*
				xBoard =200;
				dxBoard =100;
				xBall =150;

				*/
				qeta = (xBoard + dxBoard - xBall) + 40;
				dx = (int)v*cos(qeta*PI / 180);
				dy = (int)v*sin(qeta*PI / 180);



			}

			// restart ball after losing

			else
			{
				if (yBall < yBoard)
				{

					PlaySound("music\\lifelost.wav", NULL, SND_LOOP || SND_ASYNC);
					life--;
					restartBall();
					if (life == 0)
					{
						dx = (int)v*cos(qeta*PI / 180);
						dy = (int)v*sin(qeta*PI / 180);
						PlaySound("music\\gameOver.wav", NULL, SND_LOOP || SND_ASYNC);
						gamestate = 7;

					}

				}
			}

		}
	}

}


int main()
{
	iSetTimer(20, ballchange);
	///srand((unsigned)time(NULL));
	if (gamestateOfFirstGame == 7 && game == 0){
		iInitialize(screenwidthOfFirstGame, screenheightOfFirstGame, "select Game");
	}
	///updated see the documentations
	if (game == 1){
		iInitialize(screenwidthOfFirstGame, screenheightOfFirstGame, "pong Game");

	}
	else if (game == 2){
		defineBricks();
		iInitialize(screenWidth, screenHeight, "pong Game");

	}
	iStart();
	return 0;
}