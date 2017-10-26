#pragma once

#define BTN_PLAYER_UP 		VK_UP		   //
#define BTN_PLAYER_DOWN		VK_DOWN		   //
#define BTN_PLAYER_LEFT		VK_LEFT		   //
#define BTN_PLAYER_RIGHT	VK_RIGHT	   //

#define CAMERA_SPEED		1

#define MAP_WIDTH			WINSIZEX
#define MAP_HEIGHT			WINSIZEY


#define DIR_L			0x01
#define DIR_R			0x02
#define DIR_U			0x04
#define DIR_D			0x08


typedef enum DIRECTION
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

