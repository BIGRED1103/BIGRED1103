#ifndef _NBULLET_H_
#define _NBULLET_H_

#include "Bullet.h"

class NBullet : public Bullet
{
public:
	NBullet(Point pos, Dir dir, COLORREF color, int nStep);
	NBullet() {};
	~NBullet() {};
	
	virtual void Move();
	
protected:
	virtual void CalculateSphere();
	virtual void DrawBody();
	virtual void Boom();

private:
	int m_nRadius;
};

#endif