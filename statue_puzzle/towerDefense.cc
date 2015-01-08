/*****************************************************************
 COPYRIGHT (C):    2013, All Rights Reserved.
 PROJECT:          TowerDefense
 FILE:             towerDefense.cc
 PURPOSE:          Tower Defense Game: Main Game
 COMPILER:         i686-apple-darwin10-g++-4.2.1 (GCC) 4.2.1 (Apple Inc. build 5664)
 TARGET:           Mac OS X
 PROGRAMMER:       Helen Wauck
 START DATE:       01/21/2013
 *****************************************************************/
#include "ccc_win.h"
#include "Unit.h"
#include "map.h"
#include "constructionBox.h"
#include "button.h"
#include "drawFunctions.h"
#include "drawConstants.h"
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <unistd.h> 
#include <fstream>
#include<time.h>

using namespace std;
Button clockwise;
Button counterClockwise;
Button reset;
Button end;
Button move;
Button cantMoveOntoStatue1;
Button cantMoveOntoStatue2;
Button cantMoveOntoStatue3;
Button crushedByStatue1;
Button crushedByStatue2;
Button crushedByStatue3;
Button cantMoveOffScreen1;
Button cantMoveOffScreen2;
Button cantMoveOffScreen3;
Button continueToGame;
Button help;
Map* currentMap;
Point clickPos(-1,-1);
Point cantDoThat1(MAP_WIDTH * 0.69, MAP_HEIGHT * 0.5);
Point cantDoThat2(MAP_WIDTH * 0.69, MAP_HEIGHT * 0.46);
Point cantDoThat3(MAP_WIDTH * 0.69, MAP_HEIGHT * 0.42);
int playerPos = 7;
int statueTopPos = 17;
int statueBottomPos = 27;
string playerDir = "north";
string statueTopDir = "south";
string statueBottomDir = "north";
Unit* player;
Unit* statueTop;
Unit* statueBottom;
string playerName;

void drawWinScreen() {
	//draw background
	Point llcorner(0,0);
	drawSolidRectangle(SCREEN_WIDTH, SCREEN_HEIGHT, llcorner, WIDTH_INCREMENT, "black");

	// Draw title
	string titleText = "Congratulations! You won!";
	int titleTextWidth = titleText.size() * CHAR_WIDTH;
	Point titlePos(SCREEN_WIDTH / 2 - titleTextWidth / 2, SCREEN_HEIGHT * 0.6);
	cwin << Message(titlePos, titleText, "yellow");
}

void drawNameScreen() {
	//draw background
	Point llcorner(0,0);
	drawSolidRectangle(SCREEN_WIDTH, SCREEN_HEIGHT, llcorner, WIDTH_INCREMENT, "black");

	// Draw title
	string titleText = "Data-Driven Gaming";
	int titleTextWidth = titleText.size() * CHAR_WIDTH;
	Point titlePos(SCREEN_WIDTH / 2 - titleTextWidth / 2, SCREEN_HEIGHT - 5 * CHAR_OFFSET);
	cwin << Message(titlePos, titleText, "yellow");

	// Draw prompt to enter name
	cwin << Message(llcorner, "", "black");
	playerName = cwin.get_string("Enter a name: ");

}

void drawHelpScreen(bool firstTime) {
	//draw background
	Point llcorner(0,0);
	drawSolidRectangle(SCREEN_WIDTH, SCREEN_HEIGHT, llcorner, WIDTH_INCREMENT, "black");

	// Draw title
	string titleText = "How to Play";
	int titleTextWidth = titleText.size() * CHAR_WIDTH;
	Point titlePos(SCREEN_WIDTH / 2 - titleTextWidth / 2, SCREEN_HEIGHT - 3 * CHAR_OFFSET);
	cwin << Message(titlePos, titleText, "yellow");

	// Objectives
	string objectiveText = "Objective:";
	string goals1Text = "You (Blue Arrow) guide the 2 statues (Red Arrows)";
	string goals2Text = "to yellow squares on the board. In order to win,";
	string goals3Text = "you must get both statues on yellow squares."; 
	string goals4Text = "";

	Point objPos(1, SCREEN_HEIGHT - 5 * CHAR_OFFSET);
	Point goals1Pos(1, SCREEN_HEIGHT - 6 * CHAR_OFFSET);
	Point goals2Pos(1, SCREEN_HEIGHT - 7 * CHAR_OFFSET);
	Point goals3Pos(1, SCREEN_HEIGHT - 8 * CHAR_OFFSET);
	Point goals4Pos(1, SCREEN_HEIGHT - 9 * CHAR_OFFSET);

	cwin << Message(objPos, objectiveText, "yellow");
	cwin << Message(goals1Pos, goals1Text, "white");
	cwin << Message(goals2Pos, goals2Text, "white");
	cwin << Message(goals3Pos, goals3Text, "white");
	cwin << Message(goals4Pos, goals4Text, "white");

	// Controls
	string controlsText = "Controls:";
	string controls1Text = "The direction of arrows indicate the direction of";
	string controls2Text = "movement. Use 'turn' to change directions.";
	string controls3Text = "Play the game by clicking on the buttons at the";
	string controls4Text = "bottom of the screen:";
	string controls5Text = "Move - move everyone in the direction they are";
	string controls6Text = "       currently facing.";
	string controls7Text = "TurnC - turn everyone 90 degrees clockwise.";
	string controls8Text = "TurnCC - turn everyone 90 degrees counterclockwise.";
	string controls9Text = "Reset - Stuck? Start over from the beginning.";
	string controls10Text = "End Game - Quits the game and ends your session.";


	Point controlsPos(1, SCREEN_HEIGHT - 11 * CHAR_OFFSET);
	Point controls1Pos(1, SCREEN_HEIGHT - 12 * CHAR_OFFSET);
	Point controls2Pos(1, SCREEN_HEIGHT - 13 * CHAR_OFFSET);
	Point controls3Pos(1, SCREEN_HEIGHT - 14 * CHAR_OFFSET);
	Point controls4Pos(1, SCREEN_HEIGHT - 15 * CHAR_OFFSET);
	Point controls5Pos(1, SCREEN_HEIGHT - 16 * CHAR_OFFSET);
	Point controls6Pos(1, SCREEN_HEIGHT - 17 * CHAR_OFFSET);
	Point controls7Pos(1, SCREEN_HEIGHT - 18 * CHAR_OFFSET);
	Point controls8Pos(1, SCREEN_HEIGHT - 19 * CHAR_OFFSET);
	Point controls9Pos(1, SCREEN_HEIGHT - 20 * CHAR_OFFSET);
	Point controls10Pos(1, SCREEN_HEIGHT - 21 * CHAR_OFFSET);

	cwin << Message(controlsPos, controlsText, "yellow");
	cwin << Message(controls1Pos, controls1Text, "white");
	cwin << Message(controls2Pos, controls2Text, "white");
	cwin << Message(controls3Pos, controls3Text, "white");
	cwin << Message(controls4Pos, controls4Text, "white");
	cwin << Message(controls5Pos, controls5Text, "orange");
	cwin << Message(controls6Pos, controls6Text, "orange");
	cwin << Message(controls7Pos, controls7Text, "orange");
	cwin << Message(controls8Pos, controls8Text, "orange");
	cwin << Message(controls9Pos, controls9Text, "orange");
	cwin << Message(controls10Pos, controls10Text, "orange");

	//continue button
	string continueButtonText;
	if (firstTime) {
		continueButtonText = "Play Game!";
	} else {
		continueButtonText = "Back to Game";
	}
	Point llToGame(SCREEN_WIDTH/2 - (continueButtonText.size() * CHAR_WIDTH) / 2, 1);
	continueToGame = Button(llToGame, 3, continueButtonText, "yellow");
	continueToGame.draw();
}


void drawControls() {
	Point llHelp(1,1);
	Point llreset(5, 1);
	Point llclkwise(9, 1);
	Point llcclkwise(13, 1);
	Point llmove(17, 1);
	Point llend(21,1);

	help = Button(llHelp, 3, "Help", "white");
	end = Button(llend, 3, "End Game", "white"); //reset+write to log file
	clockwise = Button(llclkwise, 3, "TurnC", "white");
	counterClockwise = Button(llcclkwise, 3, "TurnCC", "white");
	reset = Button(llreset, 3, "Reset", "white"); //simply reset board
	move = Button(llmove, 3, "Move", "white");
	cantMoveOntoStatue1 = Button(cantDoThat1, 1.2, "You can't move", "red");
	cantMoveOntoStatue2 = Button(cantDoThat2, 1.2, "onto a statue's", "red");
	cantMoveOntoStatue3 = Button(cantDoThat3, 1.2, " square!", "red");
	crushedByStatue1 = Button(cantDoThat1, 1.2, "Can't move there.", "red");
	crushedByStatue2 = Button(cantDoThat2, 1.2, "You'd be crushed", "red");
	crushedByStatue3 = Button(cantDoThat3, 1.2, "by the statue!", "red");
	cantMoveOffScreen1 = Button(cantDoThat1, 1.2, "You can't move", "red");
	cantMoveOffScreen2 = Button(cantDoThat2, 1.2, "off the edge", "red");
	cantMoveOffScreen3 = Button(cantDoThat3, 1.2, "of the board!", "red");
	counterClockwise.draw();
	clockwise.draw();
	reset.draw();
	move.draw();
	end.draw();
	help.draw();
}

void redrawControls() {
	counterClockwise.draw();
	clockwise.draw();
	reset.draw();
	move.draw();
	end.draw();
	help.draw();
}

void drawCantMove() {
	cantMoveOntoStatue1.draw();
	cantMoveOntoStatue2.draw();
	cantMoveOntoStatue3.draw();
}

void drawCrushed() {
	crushedByStatue1.draw();
	crushedByStatue2.draw();
	crushedByStatue3.draw();
}

void drawOffScreen() {
	cantMoveOffScreen1.draw();
	cantMoveOffScreen2.draw();
	cantMoveOffScreen3.draw();
}


void drawInterface() {
    drawControls();

    
}

void drawMap(Map* map, bool isRedraw) {
	map->draw(isRedraw);
}

bool buttonClicked() {
	return (clockwise.inRange(clickPos) || counterClockwise.inRange(clickPos) || move.inRange(clickPos) || reset.inRange(clickPos) || end.inRange(clickPos) || help.inRange(clickPos));
}

void outputBoardConfig() {
	playerPos = player->getSquare()->get_num();
	statueTopPos = statueTop->getSquare()->get_num();
	statueBottomPos = statueBottom->getSquare()->get_num();		
	playerDir = player->getOrientation();
	statueTopDir = statueTop->getOrientation();
	statueBottomDir = statueBottom->getOrientation();			
	cout << playerPos << "," << statueTopPos << "," << statueBottomPos << "," << playerDir << "," << statueTopDir << "," << statueBottomDir << endl;
}


void takeOutTheTrash() {
	delete currentMap;
	delete player;
}

class timer {
	private:
		unsigned long begTime;
	public:
		void start() {
			begTime = time(0)*1000;
		}

		unsigned long elapsedTime() {
			return ((unsigned long) time(0)*1000 - begTime);
		}
};

int ccc_win_main() {
	cwin.coord(0,30,30,0);

	//player starts new game, enters a name
	drawNameScreen();
	cwin.clear();

	//set up data collection
	ofstream file;
	string filename = "gameData/gameStream_" + playerName + ".txt";
	const char * c = filename.c_str();
        file.open(c, ios::app);

	//help screen shown
	timer helpTimer; // time how long player spends in help screen
	helpTimer.start(); 
	drawHelpScreen(true);
	clickPos = cwin.get_mouse();

	while(!continueToGame.inRange(clickPos)) {
			clickPos = cwin.get_mouse();
	}
	unsigned long timeInFirstHelp = helpTimer.elapsedTime();
	
	cwin.clear();

	currentMap = new Map ("forest green", MAP_HEIGHT, MAP_WIDTH, SQUARE_SIZE);
	drawMap(currentMap, false);
	drawInterface();

	int clicks = 0;
	int helpClicked = 0;
	int moves = 0;
	int turns = 0;
	int resets = 0;
	int movesOffBoard = 0;
	int movesIntoStatue = 0;
	int sameSquare = 0;
	int turnC = 0;
	int turnCC = 0;
	int sameSquareStatues = 0;				
	int statuesBlockEachOther = 0;
	int movesOffBoardTStatue = 0;
	int movesOffBoardBStatue = 0;

	//prevTime = 0;

	timer t;                     //timer related
	t.start(); 			 //timer related

	
	player = currentMap->get_player();
	statueTop = currentMap->get_top_statue();
	statueBottom = currentMap->get_bottom_statue();


        //unsigned long start_time = t.elapsedTime(); 	 //timer related

	while(true) {
			
			// new map, new gameMaps
			bool playerEndsGame = false;
			bool win = false;
			//Board config order: player, statueTop, statueBottom
			file << "ACTION 0" << endl;
			file << 17 << "," << 7 << "," << 27 << "," << "north," << "south," << "north" << endl;

 			//steady_clock::time_point start = steady_clock::now();
  			//prevTime = start;
			while(!playerEndsGame && !win) {
				// read in clicks until a button is pressed

				clickPos = cwin.get_mouse();

				while(!buttonClicked()) {
					clickPos = cwin.get_mouse();
				}
				clicks++;

				file << "ACTION " << clicks << endl;
				if (move.inRange(clickPos)) {
					bool hasMoved = player->move();
					moves++;
					file << "MOVES " << player->getOrientation() << endl;
					file << "TIMESTAMP: " << t.elapsedTime() << endl;
					// if player can move
					if (hasMoved) {
						drawSolidRectangle(10, 5, cantDoThat3,WIDTH_INCREMENT, "forest green");
						//if player is right behind a statue
						if(player->getSquare() == statueTop->getSquare()) {
							player->revert();
							statueTop->redraw();
							drawCantMove();
							file << "MOVES INTO STATUE" << endl;
							movesIntoStatue++;
						} else if (player->getSquare() == statueBottom->getSquare()) {
							player->revert();
							statueBottom->redraw();		
							drawCantMove();		
							file << "MOVES INTO STATUE" << endl;
							movesIntoStatue++;	
						} else {
							bool hasMovedT = statueTop->move();
							//if statues are adjacent and facing each other, don't let them move
							if(!hasMovedT) {
								file << "TOP STATUE CAN'T MOVE OFF SCREEN" << endl;
								movesOffBoardTStatue++;
							}
							if(statueTop->getSquare() == statueBottom->getSquare()) {
								statueTop->revert();
								statueBottom->redraw();
								file << "STATUES BLOCKING EACH OTHER" << endl;
								statuesBlockEachOther++;
							} else {
								bool hasMovedB = statueBottom->move();
								if(!hasMovedB) {
									file << "BOTTOM STATUE CAN'T MOVE OFF SCREEN" << endl;
									movesOffBoardBStatue++;
								}	
							}						
						}

						// if two units land on same square
						if (player->getSquare() == statueTop->getSquare() || player->getSquare() == statueBottom->getSquare()) {
							statueTop->revert();
							statueBottom->revert();
							player->revert();
							drawCrushed();
							file << "CRUSHED BY STATUE" << endl;
							sameSquare++;
						} else if (statueTop->getSquare() == statueBottom->getSquare()) {
							statueTop->revert();
							statueBottom->revert();
							file << "STATUES MOVE ONTO SAME SQUARE" << endl;
							sameSquareStatues++;
						} 
						if (statueTop->getSquare()->get_num() == 6 && statueBottom->getSquare()->get_num() == 8) {
							win = true;
						} else if (statueTop->getSquare()->get_num() == 8 && statueBottom->getSquare()->get_num() == 6) {
							win = true;
						}
						
					} else {
						drawOffScreen();
						file << "TRIES TO MOVE OFFSCREEN" << endl;
						movesOffBoard++;
					}

				} else if (clockwise.inRange(clickPos)) {
					player->turn("right");
					statueTop->turn("right");
					statueBottom->turn("right");
					turns++;
					turnC++;
					file << "TURNS " << player->getOrientation() << endl;
					file << "TIMESTAMP: " << t.elapsedTime() << endl;
				} else if (counterClockwise.inRange(clickPos)) {
					player->turn("left");
					statueTop->turn("left");
					statueBottom->turn("left");
					turns++;
					turnCC++;
					file << "TURNS " << player->getOrientation() << endl;
					file << "TIMESTAMP: " << t.elapsedTime() << endl;
				} else if (reset.inRange(clickPos)) {
					//delete currentMap;
					currentMap = new Map ("forest green", MAP_HEIGHT, MAP_WIDTH, SQUARE_SIZE);
					player = currentMap->get_player();
					statueTop = currentMap->get_top_statue();
					statueBottom = currentMap->get_bottom_statue();
					currentMap->draw(false);
					drawControls();
					resets++;
					file << "RESETS " << endl;
					file << "TIMESTAMP: " << t.elapsedTime() << endl;
				} else if (help.inRange(clickPos)) {
					helpClicked++;
					cwin.clear();
					drawHelpScreen(false);
					helpTimer.start(); 
					clickPos = cwin.get_mouse();
					while(!continueToGame.inRange(clickPos)) {
						clickPos = cwin.get_mouse();
					}
					file << "TIME IN HELP SCREEN: " << helpTimer.elapsedTime() << endl;
					cwin.clear();
					drawMap(currentMap, true);
					redrawControls();
					player->redraw();
					statueTop->redraw();
					statueBottom->redraw();
				} else {
					file << "ENDS GAME" << player->getOrientation() << endl;
					//timeNow = steady_clock::now();
					//duration<double> time_span = duration_cast<duration<double>>(timeNow - prevTime);
					//prevTime = timeNow;
  					//file << "TIME: " << time_span.count() << endl;
 					file << "END GAME - ABORT" << endl;
					file << "TIME IN FIRST HELP SCREEN: " << timeInFirstHelp << endl;
					file << "HELP SCREEN ACCESSED: " << helpClicked << endl;
					file << "ACTIONS: " << clicks << endl; //number of button clicks
					file << "TURNS: " << turns << endl; //number of turnCC's and turnC's
					file << "TURNC: " << turnC << endl; //number of turnC's
					file << "TURNCC: " << turnCC << endl; //number of turnCC's
					file << "MOVES: " << moves << endl; //number of attempted moves
					file << "RESETS: " << resets << endl;
					file << "MOVES OFF BOARD: " << movesOffBoard << endl;
					file << "MOVES INTO STATUE: " << movesIntoStatue << endl;
					file << "PLAYER AND STATUE ON SAME SQUARE: " << sameSquare << endl;
					file << "STATUES MOVE ONTO SAME SQUARE: " << sameSquareStatues << endl;
					file << "STATUES BLOCK EACH OTHER: " << statuesBlockEachOther << endl;
					file << "TOP STATUE EDGE OF BOARD: " << movesOffBoardTStatue << endl;
					file << "BOTTOM STATUE EDGE OF BOARD: " << movesOffBoardBStatue << endl;
					unsigned long end_time = t.elapsedTime();
					file << "TIMESTAMP: " << end_time << endl;

					

					file.close();
					takeOutTheTrash();
					exit(0);
				}
				playerPos = player->getSquare()->get_num();
				statueTopPos = statueTop->getSquare()->get_num();
				statueBottomPos = statueBottom->getSquare()->get_num();		
				playerDir = player->getOrientation();
				statueTopDir = statueTop->getOrientation();
				statueBottomDir = statueBottom->getOrientation();			
				file << playerPos << "," << statueTopPos << "," << statueBottomPos << "," << playerDir << "," << statueTopDir << "," << statueBottomDir << endl;

 				//timeNow = steady_clock::now();
				//duration<double> time_span = duration_cast<duration<double>>(timeNow - prevTime);
				//prevTime = timeNow;
  				//file << "TIME: " << time_span.count() << endl;

			}
  			//file << "TIME: " << time_span.count() << endl;
 			file << "\nEND GAME - WIN" << endl;
			file << "TIME IN FIRST HELP SCREEN: " << timeInFirstHelp << endl;
			file << "HELP SCREEN ACCESSED: " << helpClicked << endl;
			file << "ACTIONS: " << clicks << endl;//number of button clicks
			file << "TURNS: " << turns << endl;//number of turnCC's and turnC's
			file << "TURNC: " << turnC << endl; //number of turnC's
			file << "TURNCC: " << turnCC << endl; //number of turnCC's
			file << "MOVES: " << moves << endl;//number of attempted moves
			file << "RESETS: " << resets << endl;
			file << "MOVES OFF BOARD: " << movesOffBoard << endl;
			file << "MOVES INTO STATUE: " << movesIntoStatue << endl;
			file << "PLAYER AND STATUE ON SAME SQUARE: " << sameSquare << endl;
			file << "STATUES MOVE ONTO SAME SQUARE: " << sameSquareStatues << endl;
			file << "STATUES BLOCK EACH OTHER: " << statuesBlockEachOther << endl;
			file << "TOP STATUE EDGE OF BOARD: " << movesOffBoardTStatue << endl;
			file << "BOTTOM STATUE EDGE OF BOARD: " << movesOffBoardBStatue << endl;
			unsigned long end_time = t.elapsedTime();
			file << "TIMESTAMP: " << end_time << endl;
			file.close();
			//duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;	
			//cout << "GAME TIME: " << duration << endl;		
			usleep(1000000);
			cwin.clear();
			drawWinScreen();
			Point llend2(MAP_HEIGHT-MAP_HEIGHT/2-1.5, 1);
			end = Button(llend2, 3, "End Game", "white");
			end.draw();
			// player loses or ends game, so return to start screen and garbage collect
			clickPos = cwin.get_mouse();

			while(!(end.inRange(clickPos))) {
				clickPos = cwin.get_mouse();
			}
			exit(0);
	}
	
	return 0;

}
