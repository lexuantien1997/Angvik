#pragma once
#include "DxWindow.h"
#include "jump.h"

#define PLAYERSPEED 2.5f
#define JUMPPOWER 8.f
#define GRAVITY 0.4f

enum PLAYERHEADSTATE
{
	PLAYER_YOUNGEST,
	PLAYER_YOUNG,
	PLAYER_OLD,
	PLAYER_ELDEST
};

enum PLAYERBODYSTATE
{
	PLAYER_RIGHT_STOP,
	PLAYER_LEFT_STOP,
	PLAYER_RIGHT_MOVE,
	PLAYER_LEFT_MOVE,
	PLAYER_RIGHT_SIT,
	PLAYER_LEFT_SIT,
	PLAYER_RIGHT_JUMP,
	PLAYER_LEFT_JUMP,
	PLAYER_RIGHT_MOVE_JUMP,
	PLAYER_LEFT_MOVE_JUMP
};

class Player : public DxWindow
{
private:
	PLAYERHEADSTATE _headState;
	PLAYERBODYSTATE _bodyState;

	animation* _bodyMotion;
	animation* _armFrontMotion;
	animation* _armBackMotion;

	Sprite* _headImage;
	Sprite* _bodyRightImage;
	Sprite* _bodyLeftImage;
	Sprite* _armRightFrontImage;
	Sprite* _armRightBackImage;
	Sprite* _armLeftFrontImage;
	Sprite* _armLeftBackImage;

	RECT _rcHead;
	RECT _rcBody;

	jump* _playerJump;

	float _x, _y;
	float _probeY;

	bool _isRight;
	bool _isLive;

public:
	Player();
	~Player();

	void init(void);
	void release(void);
	void update(void);
	void render(void);

	//========== I N I T ==========
	void imageReverse(void);
	void keyAnimationInit(void);
	void imagePosUpdate(void);

	//========== U P D A T E ==========
	void keyInputSettings(void);

};