#ifndef _MAINTANK_H_
#define _MAINTANK_H_

#include "Vehicle.h"
#include "Model/point.h"
#include "Model/rect.h"

class MainTank : public Vehicle
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
	
protected:
	void CalculateSphere();
	void DrawTankBody();
};



#endif