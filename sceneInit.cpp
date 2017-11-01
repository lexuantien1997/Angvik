#include "stdafx.h"
#include "sceneInit.h"

sceneInit::sceneInit()
{
}


sceneInit::~sceneInit()
{
}

void sceneInit::init(void)
{
	initImage();
	initSound();
	initText();
}

void sceneInit::release(void)
{

}

void sceneInit::update(void) 
{

}

void sceneInit::render(void) 
{

}

void sceneInit::initImage(void)
{
	playerInitImage();	//	�÷��̾��� �̹��� �ʱ�ȭ �Լ�
	enemyInitImage(); //�� �̹��� ::

	IMAGEMANAGER->addImage(device, L"���ι��", L"image/etc/���.png");
	IMAGEMANAGER->addFrameImage(DEVICE, L"����", L"image/etc/����.png", 8, 1);

	//������ ���� & ����
	IMAGEMANAGER->addImage(device, L"���Į", L"image/item/���Į.png");
	IMAGEMANAGER->addImage(device, L"�������", L"image/item/�������.png");
	IMAGEMANAGER->addImage(device, L"����θ޶�", L"image/item/����θ޶�.png");
	IMAGEMANAGER->addImage(device, L"���������", L"image/item/���������.png");
	IMAGEMANAGER->addImage(device, L"�������", L"image/item/�������.png");
	IMAGEMANAGER->addImage(device, L"����Į", L"image/item/����Į.png");
	IMAGEMANAGER->addImage(device, L"��������", L"image/item/��������.png");
	IMAGEMANAGER->addImage(device, L"�����θ޶�", L"image/item/�����θ޶�.png");
	IMAGEMANAGER->addImage(device, L"����������", L"image/item/����������.png");
	IMAGEMANAGER->addImage(device, L"��������", L"image/item/��������.png");
	IMAGEMANAGER->addImage(device, L"���Į", L"image/item/���Į.png");
	IMAGEMANAGER->addImage(device, L"��巣��", L"image/item/��巣��.png");
	IMAGEMANAGER->addImage(device, L"���θ޶�", L"image/item/���θ޶�.png");
	IMAGEMANAGER->addImage(device, L"���������", L"image/item/���������.png");
	IMAGEMANAGER->addImage(device, L"������", L"image/item/������.png");
	//��
	IMAGEMANAGER->addImage(device, L"�鰩", L"image/item/�鰩.png");
	IMAGEMANAGER->addImage(device, L"����", L"image/item/����.png");
	IMAGEMANAGER->addImage(device, L"���", L"image/item/���.png");
	IMAGEMANAGER->addImage(device, L"�氩", L"image/item/�氩.png");
	IMAGEMANAGER->addImage(device, L"����", L"image/item/����.png");
	IMAGEMANAGER->addImage(device, L"���", L"image/item/���.png");
	IMAGEMANAGER->addImage(device, L"Ȳ��", L"image/item/Ȳ��.png");
	IMAGEMANAGER->addImage(device, L"Ȳ��", L"image/item/Ȳ��.png");
	IMAGEMANAGER->addImage(device, L"Ȳ��", L"image/item/Ȳ��.png");
	//��
	IMAGEMANAGER->addFrameImage(device, L"������", L"image/item/������.png", 8, 1);
	IMAGEMANAGER->addFrameImage(device, L"���", L"image/item/���.png", 8, 1);
	IMAGEMANAGER->addFrameImage(device, L"Ȳ�ݻ�", L"image/item/Ȳ�ݻ�.png", 8, 1);




	//����
	IMAGEMANAGER->addFrameImage(device, L"������", L"image/monster/������.png", 8, 1);
	IMAGEMANAGER->addFrameImage(device, L"������", L"image/monster/������.png", 7, 1);
	IMAGEMANAGER->addFrameImage(device, L"��������", L"image/monster/����������.png", 2, 1);





}

void sceneInit::initSound(void)
{

}

void sceneInit::initText(void)
{

}

void sceneInit::playerInitImage(void)
{
	//	BONE
	IMAGEMANAGER->addImage(DEVICE, L"boneHead", L"image/player/bone_head.png");
	IMAGEMANAGER->addImage(DEVICE, L"boneBody", L"image/player/bone_body.png");
	IMAGEMANAGER->addImage(DEVICE, L"boneEtc", L"image/player/bone_etc.png");

	//	UNARMED
	//		RIGHTSIDE
	IMAGEMANAGER->addImage(DEVICE, L"headRight0", L"image/player/unarmed/head_0.png");
	IMAGEMANAGER->addImage(DEVICE, L"headRight1", L"image/player/unarmed/head_1.png");
	IMAGEMANAGER->addImage(DEVICE, L"headRight2", L"image/player/unarmed/head_2.png");
	IMAGEMANAGER->addImage(DEVICE, L"headRight3", L"image/player/unarmed/head_3.png");

	//IMAGEMANAGER->addFrameImage(DEVICE, L"bodyRightIdle", L"image/player/unarmed/body_idle.png", 1, 1);
	//IMAGEMANAGER->addFrameImage(DEVICE, L"bodyRightSit", L"image/player/unarmed/body_sit.png", 1, 1);
	//IMAGEMANAGER->addFrameImage(DEVICE, L"bodyRightJumpUp", L"image/player/unarmed/body_jump_up.png", 1, 1);
	//IMAGEMANAGER->addFrameImage(DEVICE, L"bodyRightJumpDown", L"image/player/unarmed/body_jump_down.png", 1, 1);
	//IMAGEMANAGER->addFrameImage(DEVICE, L"bodyRightWalk", L"image/player/unarmed/body_walk.png", 12, 1);
	IMAGEMANAGER->addFrameImage(DEVICE, L"unarmedBodyRight", L"image/player/unarmed/body.png", 12, 2);

	IMAGEMANAGER->addFrameImage(DEVICE, L"armRightFront", L"image/player/unarmed/arm_front.png", 16, 3);
	IMAGEMANAGER->addFrameImage(DEVICE, L"armRightBack", L"image/player/unarmed/arm_back.png", 16, 3);

	//		LEFTSIDE
	IMAGEMANAGER->addImage(DEVICE, L"headLeft0", L"image/player/unarmed/head_0.png");
	IMAGEMANAGER->addImage(DEVICE, L"headLeft1", L"image/player/unarmed/head_1.png");
	IMAGEMANAGER->addImage(DEVICE, L"headLeft2", L"image/player/unarmed/head_2.png");
	IMAGEMANAGER->addImage(DEVICE, L"headLeft3", L"image/player/unarmed/head_3.png");

	//IMAGEMANAGER->addFrameImage(DEVICE, L"bodyLeftIdle", L"image/player/unarmed/body_idle.png", 1, 1);
	//IMAGEMANAGER->addFrameImage(DEVICE, L"bodyLeftSit", L"image/player/unarmed/body_sit.png", 1, 1);
	//IMAGEMANAGER->addFrameImage(DEVICE, L"bodyLeftJumpUp", L"image/player/unarmed/body_jump_up.png", 1, 1);
	//IMAGEMANAGER->addFrameImage(DEVICE, L"bodyLeftJumpDown", L"image/player/unarmed/body_jump_down.png", 1, 1);
	//IMAGEMANAGER->addFrameImage(DEVICE, L"bodyLeftWalk", L"image/player/unarmed/body_walk.png", 12, 1);
	IMAGEMANAGER->addFrameImage(DEVICE, L"unarmedBodyLeft", L"image/player/unarmed/body.png", 12, 2);

	IMAGEMANAGER->addFrameImage(DEVICE, L"armLeftFront", L"image/player/unarmed/arm_front.png", 16, 3);
	IMAGEMANAGER->addFrameImage(DEVICE, L"armLeftBack", L"image/player/unarmed/arm_back.png", 16, 3);

}

void sceneInit::enemyInitImage(void)
{
	IMAGEMANAGER->addFrameImage(DEVICE, L"������", L"image/monster/������.png", 8, 1);
	IMAGEMANAGER->addFrameImage(DEVICE, L"������", L"image/monster/������.png", 7, 1);
	//IMAGEMANAGER->addFrameImage(DEVICE, L"�ź���", L"image/monster/Turtle_6f.png", 6, 1);
	//IMAGEMANAGER->addFrameImage(DEVICE, L"�ź��̴���", L"image/monster/Turtle_crash_6f.png", 6, 1);
	//IMAGEMANAGER->addFrameImage(DEVICE, L"������", L"image/monster/Ent_move_6f.png", 6, 1);
	//IMAGEMANAGER->addFrameImage(DEVICE, L"�ᳪ��", L"image/monster/kong_idle_6f.png", 6, 1);
	//IMAGEMANAGER->addFrameImage(DEVICE, L"�ᳪ������", L"image/monster/kong_atk_8f.png", 8, 1);

}