#include "stdafx.h"
#include "Turtle_crash.h"


Turtle_crash::Turtle_crash()
{
}


Turtle_crash::~Turtle_crash()
{
}


void Turtle_crash::init(float x, float y)
{
	spt = IMAGEMANAGER->findImage(L"�ź��̴���");   //�ź��̴���
	spt->setCoord({ 0,0 });

	dir = eRIGHT;
	state = eIDLE;
	life = 2;
	ptX = x;
	ptY = y;
	frameCnt = spt->getMaxFrameX();
	frameTime = 0;
	rc = RectMakeCenter(x, y, 100, 60);
	sptrc = RectMakeCenter(x, y, 110, 70);
	probeY = rc.bottom;
}
void Turtle_crash::update(void)
{
	rc = RectMakeCenter(ptX, ptY, 100, 60);
	sptrc = RectMakeCenter(ptX, ptY, 110, 70);
	probeY = sptrc.bottom;
	spt->setCoord(sptrc.left, sptrc.top);

	frameTime += TIMEMANAGER->getElapsedTime();
	if (frameTime >= 0.1f)
	{
		frameTime = 0;

		frameCnt--;
		if (frameCnt <= 0) frameCnt = spt->getMaxFrameX();
	}
	move();
}
void Turtle_crash::render(void)
{
	spt->frameRender(frameCnt, 0, 255);
}
void Turtle_crash::move(void)
{
	if (dir == eLEFT && state == eIDLE)
	{
		ptX -= 1;
	}
	if (dir == eRIGHT && state == eIDLE)
	{
		ptX += 1;
	}
	if (state == eFALL)
	{
		ptY += 1;
	}
	for (int i = probeY - 10; i < probeY + 10; ++i)//Y�� Ž��
	{
		COLORREF color = PBGMANAGER->getPixelColor(L"Stage1-PBG", ptX, i);

		int r = GetRValue(color);
		int g = GetGValue(color);
		int b = GetBValue(color);

		if ((r == 0 && g == 0 && b == 0))
		{
			ptY = i - 35;
			state = eIDLE;
			break;
		}
		else
		{
			state = eFALL;
		}
	}
	//Y�� Ž��

	for (int i = ptX - 50; i < ptX + 50; ++i) // x�� Ž��
	{
		COLORREF color = PBGMANAGER->getPixelColor(L"Stage1-PBG", i, ptY + 10);

		int r = GetRValue(color);
		int g = GetGValue(color);
		int b = GetBValue(color);

		if ((r == 0 && g == 255 && b == 255))
		{
			if (i >= ptX)
			{
				ptX = i - 50;
				dir = eLEFT;
				spt->setScale({ -1,1 });
				spt->setScaleOffset(100, 0);
			}
			else if (i < ptX)
			{
				ptX = i + 50;
				dir = eRIGHT;
				spt->setScale({ 1,1 });
			}
			break;
		}
	}
	// x�� Ž��

}