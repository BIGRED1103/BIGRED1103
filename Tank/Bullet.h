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

protected:
	virtual BOOL IsDisappear();
	virtual void CalculateSphere() {};
	virtual void DrawBody() {};
};


inline void Bullet::Display()
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

inline BOOL Bullet::IsDisappear()
{
	return m_bDisappear;
}


#endif