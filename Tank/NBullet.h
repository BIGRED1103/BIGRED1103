#ifndef _NBULLET_H_
#define _NBULLET_H_

#include "Bullet.h"

class NBullet : public Bullet
{
public:
	NBullet(Point pos, Dir dir, COLORREF color);
	NBullet() {};
	~NBullet() {};
	
	virtual void Move();
	
protected:
	virtual void CalculateSphere();
	virtual void DrawBody();

private:
	int m_nRadius;
};

#endif