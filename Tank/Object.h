#ifndef _OBJECT_H_
#define _OBJECT_H_

#include "Graphic.h"
#include "Model/point.h"
#include "Model/rect.h"
#include "time.h"

enum Dir{ UP, DOWN, RIGHT, LEFT };

class Object
{
public:
	virtual void Display()=0;
	virtual void Move()=0;

protected:
	virtual void CalculateSphere()=0;
	virtual BOOL IsDisappear()=0;

	Point m_pos;
	Rect m_rectSphere; //ÊÆÁ¦·¶Î§
	BOOL m_bDisappear;
	COLORREF m_color;
	Dir m_direc;
	int m_step;
};

#endif