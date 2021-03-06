#pragma once
#include "singletonBase.h"

class elements
{
public:


	elements() {};
	~elements() {};
};

class database : public singletonBase<database>
{
private:
	typedef vector<wstring> arrElements;
	typedef vector<wstring>::iterator iterElements;

	typedef map<wstring, elements*> arrElement;
	typedef map<wstring, elements*>::iterator iterElement;

	arrElement _mTotalElement;

	bool _isStart;
	bool _isEnd;
	bool _isMute;
	float _volume;

public:
	database();
	~database();

	void init();
	void release();

	//void loadDatabase(wstring name);

	//속성에 대한 접근자
	elements* getElementData(wstring str) { return _mTotalElement.find(str)->second; }

	//설정자
	void setElementCharactor(wstring str, int charactor);

	//게터세터
	bool getGameStart(void) { return _isStart; }
	void setGameStart(bool isStart) { _isStart = isStart; }

	bool getGameEnd(void) { return _isEnd; }
	void setGameEnd(bool isEnd) { _isEnd = isEnd; }

	float getVolume(void) { return _volume; }
	void setVolume(float volume) { _volume = volume; }

	bool getMute(void) { return _isMute; }
	void setMute(bool isMute) { _isMute = isMute; }
};

