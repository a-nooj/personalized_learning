*****************************************************************
 COPYRIGHT (C):    2013, All Rights Reserved.
 PROJECT:          TowerDefense
 COMPILER:         i686-apple-darwin10-g++-4.2.1 (GCC) 4.2.1 (Apple Inc. build 5664)
 TARGET:           Mac OS X
 PROGRAMMER:       Kevin Dexter and Helen Wauck
 START DATE:       01/21/2013
 *****************************************************************
 
 GAC Tower Defense
 *****************************************************************
 
 Overview/Objective
 *****************************************************************
 In GAC Tower Defense, Gustavus is under attack by the Oles!
 Defend Gustavus from the invaders by building towers to destroy
 them. Each time you destroy an Ole with your towers, you get 
 gold, which is used to build more towers. Each time an Ole gets
 past your defenses, you lose health. If your health reaches 0, 
 you lose!
 
 Interface
 *****************************************************************
 When the game starts, you'll see a map in the center of the 
 screen with a path winding through it. This is where the game's
 action takes place.  Towers are built on the map and Oles move 
 along the path. Above the map is your name, your score, your
 current health, and your current gold. Below the map are your 
 options for the Tower Building Cycle with their costs in gold 
 displayed above.
 
 Tower Building Cycle
 *****************************************************************
 The game begins with the tower building cycle. In the tower 
 building cycle, you can build towers on the game map. Select the 
 tower you want from the Towers box at the bottom of the screen 
 and then click where you want to build that tower on the map. You 
 cannot build towers on the path. Every tower costs money to
 build, so each tower's cost will be subtracted from your gold
 supply every time you build a tower. If you don't have enough
 gold to build a tower, you won't be able to build it on the map.
 If you have selected a tower to build but you don't have enough
 gold for it, you change your mind about building it, or you want
 to build a different tower instead, click the cancel button. When
 you're done building towers, click the "I'm Ready" button to 
 release the Oles in the Wave Cycle.
 
 Wave Cycle
 *****************************************************************
 Every Wave Cycle, a group of Oles will appear from one side of
 the map, one by one. They will move across the path until they 
 reach the end of the path or they are destroyed by your towers.
 Every time an Ole reaches the end of the path, you lose health, 
 but every time your towers destroy an Ole, you get gold to build
 more towers. During the Wave Cycle, you cannot build towers. The
 Wave Cycle ends when all of the Oles reach the end of the path or
 are destroyed. After each Wave Cycle, the Tower Building Cycle
 begins again. Tower Building Cycles and Wave Cycles continue
 until you complete all the levels in the game or you lose.
 
 Types
 *****************************************************************
 Every Ole has a type, and so do all of the towers you can build.
 Every type has a strength and a weakness, so if a tower is of
 type A, which is strong against type B but weak against type C,
 the tower of type A will deal bonus damage to Oles of type B and
 reduced damage to Oles of type C. 
 
 Every type in GAC Tower Defense is an area of study at Gustavus:
 Liberal Arts, Math and Computer Science, Athletics, Humanities,
 Social Sciences, and Laboratory Sciences. 
 
 Thus, the following type strengths and weaknesses apply:
 
 Type		| LArts | MatCs | Athlt | Humns | SoSci | LabSc
 -----------------------------------------------------------------
 Strength	| None  | LabSc | MatCs | Athlt | Humns | SoSci
 -----------------------------------------------------------------
 Weakness	| None  | Athlt | Humns | SoSci | LabSc | MatCs
 
 Note that at the bottom of the screen, your tower options are
 arranged according to type strengths and weaknesses (with the 
 exception of Liberal Arts).
 
 Oles are colored according to their type: black for Liberal Arts,
 blue for Math and Computer Science, red for Athletics, gold for 
 Humanities, green for Social Sciences, and turquoise for 
 Laboratory Sciences.
 
 Tower Data
 *****************************************************************
 In addition to a type, every tower has a different attack range, 
 attack speed, and cost, and deals a different amount of base
 damage to Oles.
 
  Type		| LArts | MatCs | Athlt | Humns | SoSci | LabSc
 -----------------------------------------------------------------
 Speed  	| Med   | Med   | High  | Low   | Low   | Med
 -----------------------------------------------------------------
 Damage 	| Low   | High  | Med   | High  | Low   | Low
 -----------------------------------------------------------------
 Range  	| Med   | Low   | Low   | Med   | HUGE  | High
 
 By combining what you know of the stats of towers, the oncoming
 waves, and unit weaknesses, you can stop the Oles with as few
 towers as possible, giving you a higher score.
 
 Now stop reading and go put an end to the waves of Ole's
 invading our campus!!!
 
 *****************************************************************
 *****************************************************************
 *****************************************************************
 
 Bugs
 *****************************************************************
 The only bug we are aware of is that while a wave is running,
 any clicks you make are registered by the game and happen
 immediately after the wave ends (such as selecting a tower,
 starting another wave, or quitting the game).
 
 *****************************************************************
 *****************************************************************
 *****************************************************************
 
 Large Scale Information
 *****************************************************************
 The game is handled in the TowerDefense.cc source file, where all
 the classes and commands are in some way passed through. The 
 SystemUpdater class handles all the work that occurs during the
 waves, updating information for the user as needed and displaying
 what is going on. The GameMaps class stores all the game data 
 relative to the gameplay section, such as maps, enemies, and 
 waves.  Finally, the Player class stores all the interface data
 such as what towers the player has and their current and max
 health.
 
 *****************************************************************
 *****************************************************************
 *****************************************************************

 Summary of Classes
 *****************************************************************
 AttributeBox: Displays the current Player's current stats: name, 
	gold, health, and score 
	
 Button: Buttons display text on the user interface and read user 
	input
	
 Category: Categories keep track of player stats, like score, 
	health, and gold
	
 ConstructionBox: The user interface for building towers, ending 
	the current game, and starting the next wave
	
 EnemyUnit: EnemyUnits move across a map's path and must be 
	destroyed by a player's towers
	
 GameMaps: Initiates all Maps with paths, enemies and waves

 Map: Keeps track of the visuals concerning constructed Towers, 
	paths, and EnemyUnits
	
 Path: A class for keeping track of the shape of a path in a map
 
 Player: A Player is the person playing the TowerDefense game

 Square: A Map is made up of a 2D vector of Squares - each square
	can contain an EnemyUnit or a Tower
	
 SystemUpdater: A class for updating the states of all objects in 
	the game
	
 Tower: Towers are objects built on the map by the player that 
	destroy units.
	
 TowerButton: Towerbuttons are buttons that allow a player to 
	construct towers on the map
	
 Type: A class for keeping track of a unit or tower's type, which
	indicates whether bonus damage may be dealt
	
 Wave: A class that holds a group of EnemyUnits that move through
	the map's path when systemUpdater updates

 *****************************************************************
 *****************************************************************
 *****************************************************************
 
 Summary of Auxiliary Files
 *****************************************************************
 drawConstants: A series of constant values for the game

 drawFunctions: A series of frequently used functions to help 
	display the game
