#ifndef _ENEMYTANK_H_
#define _ENEMYTANK_H_

#include "Object.h"

#define ENEMYTANK_MAX 10

class EnemyTank : public Object
{
public:
	EnemyTank();
	~EnemyTank();
	
public:
	void Display();
	void Move();
	BOOL IsDisappear();
	
protected:
	void CalculateSphere();
	void DrawTankBody();
	void RandChangeDirec();

private:
	int m_changeDirecProbality; //改变方向的概率
};


#endif