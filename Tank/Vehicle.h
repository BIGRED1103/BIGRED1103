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
	virtual BOOL CrashCheck(Rect rectSpaher) {return FALSE;};//δ��ʵ�֣�����
	virtual BOOL IsDisappear();
	
protected:
	virtual void CalculateSphere() {};
	virtual void DrawBody() {};
	virtual void Boom();

	int m_nRadius;  //��ը�뾶�ĳ�ʼֵ  //�������Ϊ˽�б������������г�ʼ���ͻ��ʼ��ʧ��
};

inline BOOL Vehicle::IsDisappear()  //�������inline����˴�����ʧ��
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
		//��ը�Ķ���Ч������
		//1.�����߳�,���߳�����ɱ�ը������ֱ������
		//2.����һ����ը�������ӳ���������ʧʱ��  
		//3.����һ����ը�࣬����һ����ը���󣬱�ը������ɱ�ը����ʾ
		// ʹ�÷���2
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
