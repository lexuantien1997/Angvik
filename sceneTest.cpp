#include "stdafx.h"
#include "sceneTest.h"

sceneTest::sceneTest()
{
}


sceneTest::~sceneTest()
{
}

void sceneTest::init(void)
{
	initImage();
	initSound();
	initText();

	frameCnt = 0;
	frameTime = 0.0f;
	angleDeg = 0.0f;

}

void sceneTest::initImage(void)
{
	IMAGEMANAGER->addFrameImage(DEVICE, L"더미", L"image/dummy.png", 2, 3);
	IMAGEMANAGER->addImage(DEVICE, L"더미2", L"image/dummy.png");
	RECTMANAGER->addRect(DEVICE, L"더미", { 100, 100 }, { 0, 0 });
	Sprite* background = IMAGEMANAGER->addImage(DEVICE, L"테스트배경", L"image/Stage/Stage1-Background.png");
	MAINCAMERA->setMinMax(0, 0, background->getSize().x - WINSIZEX, background->getSize().y - WINSIZEY);

	IMAGEMANAGER->setCoord(L"더미", 100, 100);
	IMAGEMANAGER->setCoord(L"더미2", 100, 100);
}

void sceneTest::initSound(void)
{

}

void sceneTest::initText(void)
{
	TEXTMANAGER->init(DEVICE, L"테스트");
	TEXTMANAGER->setFont(L"테스트", 20, L"돋움체");
}

void sceneTest::release(void)
{

}

void sceneTest::update(void)
{
	frameTime += TIMEMANAGER->getElapsedTime();
	if (frameTime >= 0.2f)
	{
		frameTime -= 0.2f;

		frameCnt++;
		if (frameCnt >= 6) frameCnt = 0;
	}

	if (KEYMANAGER->isStayKeyDown(VK_RETURN))
	{
		IMAGEMANAGER->move(L"더미", 10, 0);
		IMAGEMANAGER->move(L"더미2", 10, 0);
	}

	if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
	{
		static int dir = 1;
		dir *= -1;
		IMAGEMANAGER->setScale(L"더미", dir, 1);
		IMAGEMANAGER->setScale(L"더미2", dir, 1);
	}

	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		//center에 카메라 옵셋 더해야함
		angleDeg += 3.0f;
		IMAGEMANAGER->setRotate(L"더미", angleDeg);
		IMAGEMANAGER->setRotate(L"더미2", angleDeg);
	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		angleDeg -= 3.0f;
		IMAGEMANAGER->setRotate(L"더미", angleDeg);
		IMAGEMANAGER->setRotate(L"더미2", angleDeg);
	}

	if (KEYMANAGER->isOnceKeyDown(MK_LBUTTON) && _ptMouse.x < 100 && _ptMouse.y < 100)
	{
		frameCnt++;
		if (frameCnt >= 6) frameCnt = 0;
	}

	if (KEYMANAGER->isStayKeyDown(VK_NUMPAD8))
	{
		MAINCAMERA->moveCamera(DIRECTION_UP);
	}
	if (KEYMANAGER->isStayKeyDown(VK_NUMPAD5))
	{
		MAINCAMERA->moveCamera(DIRECTION_DN);
	}
	if (KEYMANAGER->isStayKeyDown(VK_NUMPAD4))
	{
		MAINCAMERA->moveCamera(DIRECTION_LF);
	}
	if (KEYMANAGER->isStayKeyDown(VK_NUMPAD6))
	{
		MAINCAMERA->moveCamera(DIRECTION_RG);
	}

	if (KEYMANAGER->isOnceKeyDown('T'))
	{

	}

	Sprite* imgdummy = IMAGEMANAGER->findImage(L"더미");
	Rect* rcdummy = RECTMANAGER->findRect(L"더미");
	rcdummy->setCoord(imgdummy->getCoord());
	rcdummy->setSize(imgdummy->getSize());
	rcdummy->setScale(&imgdummy->getScale());
	rcdummy->setCenterPos(imgdummy->getCenter());
	rcdummy->setRotate(imgdummy->getAngle());

	float anglexx = imgdummy->getAngle();

	
	TCHAR str[200];
	_stprintf(str, L"camera X = %d, camera Y = %d", _mainCamera.x, _mainCamera.y);
	TEXTMANAGER->addText(L"테스트", str);
	_stprintf(str, L"imgdummy center X = %d, Y = %d", imgdummy->getCenter().x, imgdummy->getCenter().y);
	TEXTMANAGER->addText(L"테스트", str);
	_stprintf(str, L"rcdummy center X = %d, Y = %d", rcdummy->getCenter().x, rcdummy->getCenter().y);
	TEXTMANAGER->addText(L"테스트", str);

	_stprintf(str, L"angle = %d, %d", (int)imgdummy->getAngle(), (int)rcdummy->getAngle());
	TEXTMANAGER->addText(L"테스트", str);

}

void sceneTest::render(void)
{
	int frameX = frameCnt % 2;
	int frameY = frameCnt / 2;

	IMAGEMANAGER->findImage(L"테스트배경")->render();
	//IMAGEMANAGER->findImage(L"더미")->frameRender(frameX, frameY);
	IMAGEMANAGER->findImage(L"더미2")->render();
	RECTMANAGER->findRect(L"더미")->render();

	TEXTMANAGER->render(L"테스트");

}
