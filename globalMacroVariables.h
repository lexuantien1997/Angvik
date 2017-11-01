#pragma once

#define BTN_PLAYER_UP 			VK_UP			//
#define BTN_PLAYER_DOWN			VK_DOWN			//
#define BTN_PLAYER_LEFT			VK_LEFT			//
#define BTN_PLAYER_RIGHT		VK_RIGHT		//
#define BTN_PLAYER_BACK_HAND	'D'				//
#define BTN_PLAYER_FRONT_HAND	'A'				//
#define BTN_PLAYER_JUMP			'S'				//
#define BTN_PLAYER_HATCH_EGG	'W'				//
#define BTN_PLAYER_INVENTORY	VK_SPACE		//


#define CAMERA_SPEED		10

#define MAP_WIDTH			(WINSIZEX*10)
#define MAP_HEIGHT			(WINSIZEY*10)


#define DIR_L			0x01
#define DIR_R			0x02
#define DIR_U			0x04
#define DIR_D			0x08


enum DIRECTION
{
	DIRECTION_NONE = 0,
	DIRECTION_LF = DIR_L,
	DIRECTION_RG = DIR_R,
	DIRECTION_UP = DIR_U,
	DIRECTION_DN = DIR_D,
	DIRECTION_LU = DIR_L | DIR_U,
	DIRECTION_RU = DIR_R | DIR_U,
	DIRECTION_LD = DIR_L | DIR_D,
	DIRECTION_RD = DIR_R | DIR_D,
};

enum PlayerNum
{
	PLAYER_NONE = -1,
	PLAYER1,
	//PLAYER2,

	PLAYER_NUM
};

