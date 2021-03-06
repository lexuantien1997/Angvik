#pragma once
#include "DxWindow.h"

class sceneInit : public DxWindow
{
private:
	void initImage(void);
	void initSound(void);
	void initText(void);

	void stageInitImage(void);
	void playerInitImage(void);
	void enemyInitImage(void);
	void uiInitImage(void);


public:
	sceneInit();
	~sceneInit();

	void init(void);
	void release(void);
	void update(void);
	void render(void);
};

