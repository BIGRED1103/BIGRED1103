#ifndef _MAINTANK_H_
#define _MAINTANK_H_

#include "Object.h"
#include "Model/point.h"
#include "Model/rect.h"

class MainTank : public Object
{
public:
	MainTank();
	~MainTank();
	
public:
	void SetDirec(Dir direc);
	void SetStep(int _step);
	int GetStep();
	void SetColor(COLORREF _color);

	void Display();
	void Move();
	BOOL IsDisappear();
	
protected:
	void CalculateSphere();
	void DrawTankBody();
};



#endif