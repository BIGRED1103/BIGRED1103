#include "NBullet.h"

NBullet::NBullet(Point pos, Dir dir, COLORREF color, int nStep)
{
	m_pos = pos;
	m_direc = dir;
	m_color = color;
	m_step = nStep;

	m_nRadius = 3;

	m_bDisappear = FALSE;
	m_bBoom = FALSE;
	CalculateSphere();
}

void NBullet::DrawBody()
{
	solidcircle(m_pos.GetX(), m_pos.GetY(), m_nRadius);
}

void NBullet::CalculateSphere()
{
	int nSize = this->m_nRadius * 4 / 3;
	int m_x = this->m_pos.GetX();
	int m_y = this->m_pos.GetY();

	m_rectSphere.Set(m_x - nSize, m_y - nSize, m_x + nSize, m_y + nSize);
}


void NBullet::Move()
{	
	if (m_bBoom)
	{
		return ; //爆炸后不再移动
	}

	int m_x = this->m_pos.GetX();
	int m_y = this->m_pos.GetY();

	Point pointStatr, pointEnd;

	int nBattle_Y = Graphic::GetBattleGround().GetStartPoint().GetX();
	switch (m_direc)
	{
	case UP:
		this->m_pos.SetY(m_y - m_step);
		this->CalculateSphere();
		pointStatr = m_rectSphere.GetStartPoint();
		if (pointStatr.GetY() < BATTLE_GROUND_Y1)
		{
			m_bBoom = TRUE;
			this->m_pos.SetY(BATTLE_GROUND_Y1);
		}
		break;
	case DOWN:
		this->m_pos.SetY(m_y + m_step);
		this->CalculateSphere();
		pointEnd = m_rectSphere.GetEndPoint();
		if (pointEnd.GetY() > BATTLE_GROUND_Y2)
		{
			m_bBoom = TRUE;
			this->m_pos.SetY(BATTLE_GROUND_Y2);
		}
		break;
	case LEFT:
		this->m_pos.SetX(m_x - m_step);
		this->CalculateSphere();
		pointStatr = m_rectSphere.GetStartPoint();
		if (pointStatr.GetX() < BATTLE_GROUND_X1)
		{
			m_bBoom = TRUE;
			this->m_pos.SetX(BATTLE_GROUND_X1);
		}
		break;
	case RIGHT:
		this->m_pos.SetX(m_x + m_step);
		this->CalculateSphere();
		pointEnd = m_rectSphere.GetEndPoint();
		if (pointEnd.GetX() > BATTLE_GROUND_X2)
		{
			m_bBoom = TRUE;
			this->m_pos.SetX(BATTLE_GROUND_X2);
		}
		break;
	default:
		break;
	}

	CalculateSphere();
}

void NBullet::Boom()
{
	int m_x = this->m_pos.GetX();
	int m_y = this->m_pos.GetY();
	circle(m_x, m_y, m_nRadius);
	m_nRadius += 1;
	if (m_nRadius >= 7)
	{
		m_bDisappear = TRUE;
	}
}
