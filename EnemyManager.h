#pragma once
#include "DxWindow.h"

//���漱��
class PlayerManager;
class stageManager;
class itemManager;

class EnemyManager : public DxWindow
{
private:


	PlayerManager* _pm;
	stageManager* _sm;
	itemManager* _im;

public:
	EnemyManager();
	~EnemyManager();

	void init(void);
	void release(void);
	void update(void);
	void render(void);


	//getter, setter
	inline void setLinkAdressPlayerManager(PlayerManager* pm) { _pm = pm; }
	inline void setLinkAdressStageManager(stageManager*   sm) { _sm = sm; }
	inline void setLinkAdressItemManager(itemManager*     im) { _im = im; }

};
