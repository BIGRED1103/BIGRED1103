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

	virtual void Shoot(list<Bullet *>& lstBullets) {};
	virtual void SetBoom();
	virtual Rect GetSphere();
	virtual BOOL CrashCheck(Rect rectSpaher) {return FALSE;};//未做实现，可以
	virtual BOOL IsDisappear();
	
protected:
	virtual void CalculateSphere() {};
	virtual void DrawBody() {};
	virtual void Boom();

	int m_nRadius;  //爆炸半径的初始值  //如果定义为私有变量，在子类中初始化就会初始化失败
};

inline BOOL Vehicle::IsDisappear()  //如果不加inline，则此处编译失败
{
	return m_bDisappear;
}

inline void Vehicle::Display()
{
	COLORREF fillcolor_save = getfillcolor();
	COLORREF color_save = getcolor();
	setfillcolor(m_color);
	setcolor(m_color);
	
	if (!m_bBoom)
	{
		DrawBody();
	}
	else
	{
		//爆炸的动画效果方案
		//1.创建线程,在线程中完成爆炸，对象直接销毁
		//2.增加一个爆炸变量，延长这个类的消失时间  
		//3.增加一个爆炸类，生成一个爆炸对象，爆炸对象完成爆炸的显示
		// 使用方案2
		Boom();
	}
	
	setfillcolor(fillcolor_save);
	setcolor(color_save);
}

inline void Vehicle::Boom()
{
	int m_x = this->m_pos.GetX();
	int m_y = this->m_pos.GetY();
	circle(m_x, m_y, m_nRadius);
	m_nRadius += 2;
	if (m_nRadius >= 9)
	{
		m_bDisappear = TRUE;
	}
}

inline void Vehicle::SetBoom()
{
	m_bBoom = TRUE;
}

inline Rect Vehicle::GetSphere()
{
	return m_rectSphere;
}

#endif
