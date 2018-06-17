#ifndef _ENEMYTANK_H_
#define _ENEMYTANK_H_

#include "Vehicle.h"

#define ENEMYTANK_MAX 20

class EnemyTank : public Vehicle
{
public:
	EnemyTank();
	~EnemyTank();
	
public:
	void Move();
	void Shoot(list<Bullet* > & lstBullets);
	
protected:
	void CalculateSphere();
	void DrawBody();
	BOOL IsDisappear();

	void RandChangeDirec();

private:
	int m_changeDirecProbality; //改变方向的概率
};


#endif