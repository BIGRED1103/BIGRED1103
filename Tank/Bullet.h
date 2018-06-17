#ifndef _BULLET_H_
#define _BULLET_H_

#include "Object.h"

class Bullet : public Object
{
public:
	Bullet() {};
	~Bullet() {};

	virtual void Display();
	virtual void Move() {};
	virtual void SetBoom();
	virtual BOOL IsDisappear();
	virtual BOOL CrashCheck(Rect rectSphere);
	
protected:
	virtual void CalculateSphere() {};
	virtual void DrawBody() {};
	virtual void Boom() {};

};


inline void Bullet::Display()  //inline 中如果有if等语句，就不是内联函数
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
		Boom();
	}
	
	setfillcolor(fillcolor_save);
	setcolor(color_save);
}

inline BOOL Bullet::IsDisappear()
{
	return m_bDisappear;
}

inline void Bullet::SetBoom()
{
	m_bBoom = TRUE;
}

inline BOOL Bullet::CrashCheck(Rect rectSphere)
{
	Point pos_BulletStart = this->m_rectSphere.GetStartPoint();
	Point pos_BulletEnd = this->m_rectSphere.GetEndPoint();
	Point pos_rectStart = rectSphere.GetStartPoint();
	Point pos_rectEnd = rectSphere.GetEndPoint();
	int nBulletUp = 0, nBulletDown = 0, nBulletLeft = 0, nBulletRight = 0;  //相对于运行方向的上下左右(左右的时候可以不考虑方向)
	int nRectUp = 0, nRectDown = 0, nRectLeft = 0, nRectRight = 0;

	switch (m_direc)
	{
	case UP:
		nBulletUp = pos_BulletStart.GetY();
		nBulletDown = pos_BulletEnd.GetY() + m_step;
		nRectUp = pos_rectStart.GetY();
		nRectDown = pos_rectEnd.GetY();
		if (nBulletUp <=  nRectDown && nBulletDown >= nRectUp)
		{
			nBulletLeft = pos_BulletStart.GetX();
			nBulletRight = pos_BulletEnd.GetX();
			nRectLeft = pos_rectStart.GetX();
			nRectRight = pos_rectEnd.GetX(); 
			if (nRectLeft <= nBulletLeft && nRectRight >= nBulletLeft)
			{
				this->m_pos.SetY(nRectDown);
				return TRUE;
			}
			if (nRectLeft <= nBulletRight && nRectRight >= nBulletRight)
			{
				this->m_pos.SetY(nRectDown);
				return TRUE;
			}
		}
		break;
	case DOWN:
		nBulletUp = pos_BulletEnd.GetY();
		nBulletDown = pos_BulletStart.GetY() - m_step;
		nRectUp = pos_rectEnd.GetY();
		nRectDown = pos_rectStart.GetY();
		if (nBulletUp >=  nRectDown && nBulletDown <= nRectUp)
		{
			nBulletLeft = pos_BulletStart.GetX();
			nBulletRight = pos_BulletEnd.GetX();
			nRectLeft = pos_rectStart.GetX();
			nRectRight = pos_rectEnd.GetX(); 
			if (nRectLeft <= nBulletLeft && nRectRight >= nBulletLeft)
			{
				this->m_pos.SetY(nRectDown);
				return TRUE;
			}
			if (nRectLeft <= nBulletRight && nRectRight >= nBulletRight)
			{
				this->m_pos.SetY(nRectDown);
				return TRUE;
			}
		}
		break;
	case LEFT:
		nBulletUp = pos_BulletStart.GetX();
		nBulletDown = pos_BulletEnd.GetX() + m_step;
		nRectUp = pos_rectStart.GetX();
		nRectDown = pos_rectEnd.GetX();
		if (nBulletUp <= nRectDown && nBulletDown >= nRectUp)
		{
			nBulletLeft = pos_BulletEnd.GetY();
			nBulletRight = pos_BulletStart.GetY();
			nRectLeft = pos_rectEnd.GetY();
			nRectRight = pos_rectStart.GetY(); 
			if (nRectLeft >= nBulletLeft && nRectRight <= nBulletLeft)
			{
				this->m_pos.SetX(nRectDown);
				return TRUE;
			}
			if (nRectLeft >= nBulletRight && nRectRight <= nBulletRight)
			{
				this->m_pos.SetX(nRectDown);
				return TRUE;
			}
		}
		break;
	case RIGHT:
		nBulletUp = pos_BulletEnd.GetX();
		nBulletDown = pos_BulletStart.GetX() - m_step;
		nRectUp = pos_rectEnd.GetX();
		nRectDown = pos_rectStart.GetX();
		if (nBulletUp >= nRectDown && nBulletDown <= nRectUp)
		{
			nBulletLeft = pos_BulletEnd.GetY();
			nBulletRight = pos_BulletStart.GetY();
			nRectLeft = pos_rectEnd.GetY();
			nRectRight = pos_rectStart.GetY(); 
			if (nRectLeft >= nBulletLeft && nRectRight <= nBulletLeft)
			{
				this->m_pos.SetX(nRectDown);
				return TRUE;
			}
			if (nRectLeft >= nBulletRight && nRectRight <= nBulletRight)
			{
				this->m_pos.SetX(nRectDown);
				return TRUE;
			}
		}
		break;
	default:
		break;
	}

	return FALSE;
}

#endif