#include "stdafx.h"
#include "Item.h"

Item::Item()
{
}


Item::~Item()
{
}

void Item::init(void)
{
	_img = NULL;
	
	_rcImg = RectMake(300, 100, 100, 100);
	probeY = _rcImg.bottom;
}

void Item::release(void)
{

}

void Item::update(void)
{
	
	
	probeY = _rcImg.bottom;
	if (_state == ITEM_STATE_IDLE)
	{
		for (int i = probeY - 3; i < probeY + 5; ++i)
		{
			COLORREF color = PBGMANAGER->getPixelColor(L"Stage1-PBG", probeY, i);

			int r = GetRValue(color);
			int g = GetGValue(color);
			int b = GetBValue(color);

			if (!(r == 0 && g == 0 && b == 0)) // ������ �ٴ�
			{
				probeY = i + _rcImg.bottom;
				break;
			}
			else
			{
				_rcImg.top += 5;
				_rcImg.bottom += 5;
			}
		}
	}
}

void Item::render(void)	
{
	//if(KEYMANAGER->isStayKeyDown('R')) IMAGEMANAGER->findImage(L"�ȼ�")->render();
	
	_img->render();
	
}


void Item::createItem(ITEM_TYPE type, ITEM_KIND kind, ITEM_STATE state,float x, float y)
{

	_type = type;
	_kind = kind;
	_state = state;
	_pt.x = x;
	_pt.y = y;
	
	
	
	switch (_type)
	{
	case ITEM_TYPE_SWORD:		//����-��
		if (_kind == ITEM_KIND_WHITE)
		{
			_img = new Sprite(DEVICE, L"image/item/���Į.png");
			
			_img->setCoord(x, y);
			_img->init();
			_rcImg = RectMake(x, y, IMAGEMANAGER->findImage(L"���Į")->getRealSize().x, IMAGEMANAGER->findImage(L"���Į")->getRealSize().y);
			_durability = 4;
		}
		else if (_kind == ITEM_KIND_BLACK)
		{
			_img = new Sprite(DEVICE, L"image/item/����Į.png");
			_img->setCoord(x, y);
			_img->init();
			_rcImg = RectMake(x, y, IMAGEMANAGER->findImage(L"����Į")->getRealSize().x, IMAGEMANAGER->findImage(L"����Į")->getRealSize().y);
			_durability = 4;
		}
		else if (_kind == ITEM_KIND_GOLD)
		{
			_img = new Sprite(DEVICE, L"image/item/���Į.png");
			_img->setCoord(x, y);
			_img->init();
			_rcImg = RectMake(x, y, IMAGEMANAGER->findImage(L"���Į")->getRealSize().x, IMAGEMANAGER->findImage(L"���Į")->getRealSize().y);
			_durability = 4;
		}
		break;
	case ITEM_TYPE_LENCE:		//����-â
		if (_kind == ITEM_KIND_WHITE)
		{
			_img = new Sprite(DEVICE, L"image/item/�������.png");
			_img->setCoord(x, y);
			_img->init();
			_rcImg = RectMake(x, y, IMAGEMANAGER->findImage(L"�������")->getRealSize().x, IMAGEMANAGER->findImage(L"�������")->getRealSize().y);
			_durability = 4;
		}
		else if (_kind == ITEM_KIND_BLACK)
		{
			_img = new Sprite(DEVICE, L"image/item/��������.png");
			_img->setCoord(x, y);
			_img->init();
			_rcImg = RectMake(x, y, IMAGEMANAGER->findImage(L"��������")->getRealSize().x, IMAGEMANAGER->findImage(L"��������")->getRealSize().y);
			_durability = 4;
		}
		else if (_kind == ITEM_KIND_GOLD)
		{
			_img = new Sprite(DEVICE, L"image/item/��巣��.png");
			_img->setCoord(x, y);
			_img->init();
			_rcImg = RectMake(x, y, IMAGEMANAGER->findImage(L"��巣��")->getRealSize().x, IMAGEMANAGER->findImage(L"��巣��")->getRealSize().y);
			_durability = 4;
		}
		break;
	case ITEM_TYPE_BOOMERANG:	//����-�θ޶�
		if (_kind == ITEM_KIND_WHITE)
		{
			_img = new Sprite(DEVICE, L"image/item/����θ޶�.png");
			_img->setCoord(x, y);
			_img->init();
			_rcImg = RectMake(x, y, IMAGEMANAGER->findImage(L"����θ޶�")->getRealSize().x, IMAGEMANAGER->findImage(L"����θ޶�")->getRealSize().y);
			_durability = 4;
		}
		else if (_kind == ITEM_KIND_BLACK)
		{
			_img = new Sprite(DEVICE, L"image/item/�����θ޶�.png");
			_img->setCoord(x, y);
			_img->init();
			_rcImg = RectMake(x, y, IMAGEMANAGER->findImage(L"�����θ޶�")->getRealSize().x, IMAGEMANAGER->findImage(L"�����θ޶�")->getRealSize().y);
			_durability = 4;
		}
		else if (_kind == ITEM_KIND_GOLD)
		{
			_img = new Sprite(DEVICE, L"image/item/���θ޶�.png");
			_img->setCoord(x, y);
			_img->init();
			_rcImg = RectMake(x, y, IMAGEMANAGER->findImage(L"���θ޶�")->getRealSize().x, IMAGEMANAGER->findImage(L"���θ޶�")->getRealSize().y);
			_durability = 4;
		}
		break;
	case ITEM_TYPE_STAFF:		//����-������
		if (_kind == ITEM_KIND_WHITE)
		{
			_img = new Sprite(DEVICE, L"image/item/���������.png");
			_img->setCoord(x, y);
			_img->init();
			_rcImg = RectMake(x, y, IMAGEMANAGER->findImage(L"���������")->getRealSize().x, IMAGEMANAGER->findImage(L"���������")->getRealSize().y);
			_durability = 4;
		}
		else if (_kind == ITEM_KIND_BLACK)
		{
			_img = new Sprite(DEVICE, L"image/item/����������.png");
			_img->setCoord(x, y);
			_img->init();
			_rcImg = RectMake(x, y, IMAGEMANAGER->findImage(L"����������")->getRealSize().x, IMAGEMANAGER->findImage(L"����������")->getRealSize().y);
			_durability = 4;
		}
		else if (_kind == ITEM_KIND_GOLD)
		{
			_img = new Sprite(DEVICE, L"image/item/����������.png");
			_img->setCoord(x, y);
			_img->init();
			_rcImg = RectMake(x, y, IMAGEMANAGER->findImage(L"����������")->getRealSize().x, IMAGEMANAGER->findImage(L"����������")->getRealSize().y);
			_durability = 4;
		}
		break;
	case ITEM_TYPE_HEAD:			//��-�Ӹ�
		if (_kind == ITEM_KIND_WHITE)
		{
			_img = new Sprite(DEVICE, L"image/item/����.png");
			_img->setCoord(x, y);
			_img->init();
			_rcImg = RectMake(x, y, IMAGEMANAGER->findImage(L"����")->getRealSize().x, IMAGEMANAGER->findImage(L"����")->getRealSize().y);
			_durability = 4;
		}
		else if (_kind == ITEM_KIND_BLACK)
		{
			_img = new Sprite(DEVICE, L"image/item/����.png");
			_img->setCoord(x, y);
			_img->init();
			_rcImg = RectMake(x, y, IMAGEMANAGER->findImage(L"����")->getRealSize().x, IMAGEMANAGER->findImage(L"����")->getRealSize().y);
			_durability = 4;
		}
		else if (_kind == ITEM_KIND_GOLD)
		{
			_img = new Sprite(DEVICE, L"image/item/Ȳ��.png");
			_img->setCoord(x, y);
			_img->init();
			_rcImg = RectMake(x, y, IMAGEMANAGER->findImage(L"Ȳ��")->getRealSize().x, IMAGEMANAGER->findImage(L"Ȳ��")->getRealSize().y);
			_durability = 4;
		}
		break;
	case ITEM_TYPE_BODY:			//��-����
		if (_kind == ITEM_KIND_WHITE)
		{
			_img = new Sprite(DEVICE, L"image/item/�鰩.png");
			_img->setCoord(x, y);
			_img->init();
			_rcImg = RectMake(x, y, IMAGEMANAGER->findImage(L"�鰩")->getRealSize().x, IMAGEMANAGER->findImage(L"�鰩")->getRealSize().y);
			_durability = 4;
		}
		else if (_kind == ITEM_KIND_BLACK)
		{
			_img = new Sprite(DEVICE, L"image/item/�氩.png");
			_img->setCoord(x, y);
			_img->init();
			_rcImg = RectMake(x, y, IMAGEMANAGER->findImage(L"�氩")->getRealSize().x, IMAGEMANAGER->findImage(L"�氩")->getRealSize().y);
			_durability = 4;
		}
		else if (_kind == ITEM_KIND_GOLD)
		{
			_img = new Sprite(DEVICE, L"image/item/Ȳ��.png");
			_img->setCoord(x, y);
			_img->init();
			_rcImg = RectMake(x, y, IMAGEMANAGER->findImage(L"Ȳ��")->getRealSize().x, IMAGEMANAGER->findImage(L"Ȳ��")->getRealSize().y);
			_durability = 4;
		}
		break;
	case ITEM_TYPE_FOOT:			//��-�Ź�
		if (_kind == ITEM_KIND_WHITE)
		{
			_img = new Sprite(DEVICE, L"image/item/���.png");
			_img->setCoord(x, y);
			_img->init();
			_rcImg = RectMake(x, y, IMAGEMANAGER->findImage(L"���")->getRealSize().x, IMAGEMANAGER->findImage(L"���")->getRealSize().y);
			_durability = 4;
		}
		else if (_kind == ITEM_KIND_BLACK)
		{
			_img = new Sprite(DEVICE, L"image/item/���.png");
			_img->setCoord(x, y);
			_img->init();
			_rcImg = RectMake(x, y, IMAGEMANAGER->findImage(L"���")->getRealSize().x, IMAGEMANAGER->findImage(L"���")->getRealSize().y);
			_durability = 4;
		}
		else if (_kind == ITEM_KIND_GOLD)
		{
			_img = new Sprite(DEVICE, L"image/item/Ȳ��.png");
			_img->setCoord(x, y);
			_img->init();
			_rcImg = RectMake(x, y, IMAGEMANAGER->findImage(L"Ȳ��")->getRealSize().x, IMAGEMANAGER->findImage(L"Ȳ��")->getRealSize().y);
			_durability = 4;
		}
		break;
	case ITEM_TYPE_OIL:			//
		if (_kind == ITEM_KIND_WHITE)
		{
			_img = new Sprite(DEVICE, L"image/item/�������.png");
			_img->setCoord(x, y);
			_img->init();
			_rcImg = RectMake(x, y, IMAGEMANAGER->findImage(L"�������")->getRealSize().x, IMAGEMANAGER->findImage(L"�������")->getRealSize().y);
			_durability = 4;
		}
		else if (_kind == ITEM_KIND_BLACK)
		{
			_img = new Sprite(DEVICE, L"image/item/��������.png");
			_img->setCoord(x, y);
			_img->init();
			_rcImg = RectMake(x, y, IMAGEMANAGER->findImage(L"��������")->getRealSize().x, IMAGEMANAGER->findImage(L"��������")->getRealSize().y);
			_durability = 4;
		}
		else if (_kind == ITEM_KIND_GOLD)
		{
			_img = new Sprite(DEVICE, L"image/item/������.png");
			_img->setCoord(x, y);
			_img->init();
			_rcImg = RectMake(x, y, IMAGEMANAGER->findImage(L"������")->getRealSize().x, IMAGEMANAGER->findImage(L"������")->getRealSize().y);
			_durability = 4;
		}
		break;
	case ITEM_TYPE_EGG:
		if (_kind == ITEM_KIND_WHITE)
		{
			_img = new Sprite(DEVICE, L"image/item/��.png");
			_img->setCoord(x, y);
			_img->init();
			//_rcImg = RectMake(x, y, IMAGEMANAGER->findImage(L"��")->getRealSize().x, IMAGEMANAGER->findImage(L"��")->getRealSize().y);
			
		}
		else if (_kind == ITEM_KIND_BLACK)
		{
			_img = new Sprite(DEVICE, L"image/item/��.png");
			_img->setCoord(x, y);
			_img->init();
			//_rcImg = RectMake(x, y, IMAGEMANAGER->findImage(L"��")->getRealSize().x, IMAGEMANAGER->findImage(L"��")->getRealSize().y);
			
		}
		else if (_kind == ITEM_KIND_GOLD)
		{
			_img = new Sprite(DEVICE, L"image/item/��.png");
			_img->setCoord(x, y);
			_img->init();
			//_rcImg = RectMake(x, y, IMAGEMANAGER->findImage(L"��")->getRealSize().x, IMAGEMANAGER->findImage(L"��")->getRealSize().y);
			
		}
		break;
	}
	////////////////////�ȼ��浹
	
}

