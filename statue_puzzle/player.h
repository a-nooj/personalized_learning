/*****************************************************************
 COPYRIGHT (C):    2013, All Rights Reserved.
 PROJECT:          TowerDefense
 FILE:             player.h
 PURPOSE:          A Player is the person playing the TowerDefense game
 COMPILER:         i686-apple-darwin10-g++-4.2.1 (GCC) 4.2.1 (Apple Inc. build 5664)
 TARGET:           Mac OS X
 PROGRAMMER:       Helen Wauck and Kevin Dexter
 START DATE:       01/21/2013
 *****************************************************************/

#ifndef PLAYER_H_
#define PLAYER_H_

#include <string>
#include <vector>
#include "ccc_win.h"
//#include "category.h"
//#include "tower.h"

class Player {

public:

	Player();

	Player(std::string name, int gold);

	/* PURPOSE: adds a tower to the player's current tower list - this is
	 * called every time a player constructs a tower on the map
	*/


private:
	/* REMARKS: The maximum health this player can have
	*/
	
};

#endif /* PLAYER_H_ */
