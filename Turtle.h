#pragma once
#include "EnemyMother.h"
class Turtle :
	public EnemyMother
{
public:
	Turtle();
	~Turtle();

	void init(int num, float x, float y, wstring rcKey);
	void update(void);
	void render(void);
	void move(void);

};

