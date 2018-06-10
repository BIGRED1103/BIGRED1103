#ifndef _ENEMYTANK_H_
#define _ENEMYTANK_H_

#include "Vehicle.h"

#define ENEMYTANK_MAX 10

class EnemyTank : public Vehicle
{
public:
	EnemyTank();
	~EnemyTank();
	
public:
	void Move();
	
protected:
	void CalculateSphere();
	void DrawBody();
	BOOL IsDisappear();

	void RandChangeDirec();

private:
	int m_changeDirecProbality; //改变方向的概率
};


#endif