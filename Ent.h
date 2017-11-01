#pragma once
#include "EnemyMother.h"
class Ent :
	public EnemyMother
{
private:
	int probeY;

public:
	Ent();
	~Ent();

	void init(float x, float y);
	void update(void);
	void render(void);
	void move(void);
	void attack(void);
};

