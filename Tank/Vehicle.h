#ifndef _VEHICLE_H_
#define _VEHICLE_H_

#include "Object.h"
#include "NBullet.h"
#include <list>

using namespace std;

class Vehicle : public Object 
{
public:
	Vehicle() {};
	~Vehicle() {};

	virtual void Display();
	virtual void Move() {};

	virtual void Shoot(list<Object *>& lstBullets) {};
	
protected:
	virtual void CalculateSphere() {};
	virtual BOOL IsDisappear();
	virtual void DrawBody() {};
};

inline BOOL Vehicle::IsDisappear()  //如果不加inline，则此处编译失败(等效于直接在定义中实现)
{
	return m_bDisappear;
}

inline void Vehicle::Display()
{
	COLORREF fillcolor_save = getfillcolor();
	COLORREF color_save = getcolor();
	setfillcolor(m_color);
	setcolor(m_color);
	
	DrawBody();
	CalculateSphere();
	
	setfillcolor(fillcolor_save);
	setcolor(color_save);
}

#endif
