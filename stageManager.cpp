#include "stdafx.h"
#include "stageManager.h"
#include "PlayerManager.h"
#include "EnemyManager.h"
#include "itemManager.h"


stageManager::stageManager()
	: _pm(NULL)
	, _em(NULL)
	, _im(NULL)
{
}


stageManager::~stageManager()
{
}


void stageManager::init(void)
{
	//_imgBackground = IMAGEMANAGER->findImage(L"Stage1-BG");
	_imgBackground = IMAGEMANAGER->findImage(L"Stage1-PBG");
	_imgPBG = PBGMANAGER->findImage(L"Stage1-PBG");

	for (int i = 0; i < TREETRAP_MAX; i++)
	{
		ZeroMemory(&_treeTrap[i], sizeof(tagTreeTrap));
	}

	_treeTrap[0].rc  = RectMake(2600, 432, 53, 15);	// -1
	_treeTrap[1].rc  = RectMake(2705, 411, 53, 15);			
	_treeTrap[2].rc  = RectMake(2710, 520, 53, 15);			
	_treeTrap[3].rc  = RectMake(2710, 636, 53, 15);			
	_treeTrap[4].rc  = RectMake(2838, 479, 53, 15);	// -1
	_treeTrap[5].rc  = RectMake(2838, 596, 53, 15);	// -1
	_treeTrap[6].rc  = RectMake(3227, 468, 53, 15);			
	_treeTrap[7].rc  = RectMake(3226, 638, 53, 15);			
	_treeTrap[8].rc  = RectMake(3442, 376, 53, 15);	// -1
	_treeTrap[9].rc  = RectMake(3444, 552, 53, 15);	// -1
	_treeTrap[10].rc = RectMake(3448, 721, 53, 15);	// -1

	//int dir[11] = { -1, 1, 1, 1, -1, -1, 1, 1, -1, -1, -1 };
	int dir[11] = { 1, -1, -1, -1, 1, 1, -1, -1, 1, 1, 1 };

	for (int i = 0; i < TREETRAP_MAX; i++)
	{
		_treeTrap[i].num = i;
		_treeTrap[i].dir = dir[i];
		_treeTrap[i].img = new Sprite(DEVICE, L"image/Stage/treetrap.png");
		_treeTrap[i].img->init(1, 6);
		_treeTrap[i].img->setCoord(_treeTrap[i].rc.left, _treeTrap[i].rc.top);
		_treeTrap[i].img->setScale(dir[i], 1);
		_treeTrap[i].img->setScaleOffset((float)_treeTrap[i].img->getTexture()->getFrameWidth(), 0.0f);

		_treeTrap[i].frameCnt = 0;
		_treeTrap[i].frameTime = 0.0f;
		_treeTrap[i].frameFPS = 5.0f;
		_treeTrap[i].refreshTime = 1.0f;
		
		_treeTrap[i].show = true;

		PBGMANAGER->addRect(i, _treeTrap[i].rc, RGB(0, 0, 0));
	}

}

void stageManager::release(void)
{
	for (int i = 0; i < TREETRAP_MAX; i++)
	{
		SAFE_RELEASE2(_treeTrap[i].img);
	}
}

void stageManager::update(void)
{
	if (_pm == NULL)
		return;

	frameUpdate();
	PBGUpdate();

}

void stageManager::render(void)
{
	_imgBackground->render();
	//PBGMANAGER->render(L"Stage1-PBG");

	for (int i = 0; i < TREETRAP_MAX; i++)
	{
		if (_treeTrap[i].show)
		{
			_treeTrap[i].img->frameRender(0, _treeTrap[i].frameCnt);
		}
	}

}

void stageManager::GoNextStage(void)
{

}


void stageManager::frameUpdate(void)
{
	for (int i = 0; i < TREETRAP_MAX; i++)
	{
		RECT temp;

		if (_treeTrap[i].show)
		{
			if (IntersectRect(&temp, &_pm->getPlayer()->getRectFoot(), &_treeTrap[i].rc))
			{
				_treeTrap[i].frameTime += TIMEMANAGER->getElapsedTime();
				if (_treeTrap[i].frameTime >= 1 / _treeTrap[i].frameFPS)
				{
					_treeTrap[i].frameTime -= 1 / _treeTrap[i].frameFPS;
					_treeTrap[i].frameCnt++;
					if (_treeTrap[i].frameCnt > _treeTrap[i].img->getMaxFrameY())
					{
						_treeTrap[i].frameTime = 0.0f;
						_treeTrap[i].show = false;

						//PBGMANAGER->setRectColor(_treeTrap[i].num, RGB(255, 0, 255));
					}
				}
			}
			else
			{
				_treeTrap[i].frameTime = 0.0f;
				_treeTrap[i].frameCnt = 0;
			}

		}
		else
		{
			_treeTrap[i].frameTime += TIMEMANAGER->getElapsedTime();
			if (_treeTrap[i].frameTime > _treeTrap[i].refreshTime)
			{
				_treeTrap[i].frameTime = 0.0f;
				_treeTrap[i].frameCnt = 0;
				_treeTrap[i].show = true;

				//PBGMANAGER->setRectColor(_treeTrap[i].num, RGB(0, 0, 0));
			}
		}
	}
}

void stageManager::PBGUpdate(void)
{
	
}
