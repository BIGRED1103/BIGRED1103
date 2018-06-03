#ifndef _VEHICLE_H_
#define _VEHICLE_H_

#include "Graphic.h"
#include "Model/point.h"
#include "Model/rect.h"
#include "time.h"

enum Dir{ UP, DOWN, RIGHT, LEFT };

class Vehicle
{
public:
	virtual void Display()=0;
	virtual void Move()=0;

protected:
	virtual void CalculateSphere()=0;

	Point m_pos;
	Rect m_rectSphere; //ÊÆÁ¦·¶Î§
	

	COLORREF m_color;
	Dir m_direc;
	int m_step;
};

#endif