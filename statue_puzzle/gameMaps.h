/*****************************************************************
 COPYRIGHT (C):    2013, All Rights Reserved.
 PROJECT:          TowerDefense
 FILE:             gameMaps.h
 PURPOSE:          Initiates all Maps with paths, enemies and waves
 COMPILER:         i686-apple-darwin10-g++-4.2.1 (GCC) 4.2.1 (Apple Inc. build 5664)
 TARGET:           Mac OS X
 PROGRAMMER:       Helen Wauck and Kevin Dexter
 START DATE:       01/21/2013
 *****************************************************************/

#ifndef GAMEMAPS_H_
#define GAMEMAPS_H_

#include "map.h"
//#include "EnemyUnit.h"
//#include "wave.h"
//#include "type.h"
#include "drawConstants.h"
#include <vector>
#include <string>

class GameMaps {
public:
	GameMaps();
	vector<Map*> getMaps() const;
	void removeMap();
private:
	vector<Map*> maps;
};

#endif /* GAMEMAPS_H_ */
