#pragma once
#include "DxWindow.h"
#include "Player.h"

//���漱��
class EnemyManager;
class stageManager;
class itemManager;

class PlayerManager : public DxWindow
{
private:
	Player* _player;



	EnemyManager* _em;
	stageManager* _sm;
	itemManager* _im;

public:
	PlayerManager();
	~PlayerManager();

	void init(void);
	void release(void);
	void update(void);
	void render(void);




	//getter, setter
	inline void setLinkAdressEnemyManager(EnemyManager*   em) { _em = em; }
	inline void setLinkAdressStageManager(stageManager*   sm) { _sm = sm; }
	inline void setLinkAdressItemManager(itemManager*     im) { _im = im; }


	inline Player* getPlayer(void) { return _player; }
};

