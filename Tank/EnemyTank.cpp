#include "EnemyTank.h"

EnemyTank::EnemyTank()
{
	int m_x = rand() % (Graphic::GetBattleGround().GetWidth() - 8) + 8; //保证敌方坦克不会在战场外出生
	int m_y = rand() % (Graphic::GetBattleGround().GetHeight() - 8) + 8;

	m_pos.Set(m_x, m_y);
			
	m_color = WHITE;
	m_direc = (Dir)(rand() % 4);
	m_step = rand() % 2 + 1;

	m_changeDirecProbality = 50;
	m_bDisappear = FALSE;
}

EnemyTank::~EnemyTank()
{

}

void EnemyTank::DrawBody()
{
	int m_x = this->m_pos.GetX();
	int m_y = this->m_pos.GetY();
	
	solidrectangle(m_x - 4, m_y - 4, m_x + 4, m_y + 4);
	
	switch (m_direc)
	{
	case UP:
		solidrectangle(m_x - 8, m_y - 6, m_x - 6, m_y + 6);  
        solidrectangle(m_x + 6, m_y - 6, m_x + 8, m_y + 6);  
		line(m_x, m_y, m_x, m_y - 10);
		break;
	case DOWN:
		solidrectangle(m_x - 8, m_y - 6, m_x - 6, m_y + 6);  
        solidrectangle(m_x + 6, m_y - 6, m_x + 8, m_y + 6);  
		line(m_x, m_y, m_x, m_y + 10);
		break;
	case RIGHT:
		solidrectangle(m_x - 6, m_y - 8, m_x + 6, m_y - 6);  
        solidrectangle(m_x - 6, m_y + 6, m_x + 6, m_y + 8);
		line(m_x, m_y, m_x + 10, m_y);
		break;
	case LEFT:
		solidrectangle(m_x - 6, m_y - 8, m_x + 6, m_y - 6);  
        solidrectangle(m_x - 6, m_y + 6, m_x + 6, m_y + 8); 
		line(m_x, m_y, m_x - 10, m_y);
		break;
	default:
		break;
	}
}

void EnemyTank::Move()
{
	int m_y, m_x;
	m_x = this->m_pos.GetX();
	m_y = this->m_pos.GetY();
	
	int battle_X1 = BATTLE_GROUND_X1;
	int battle_Y1 = BATTLE_GROUND_Y1;
	int battle_X2 = BATTLE_GROUND_X2;
	int battle_Y2 = BATTLE_GROUND_Y2;

	RandChangeDirec();

	switch (m_direc)
	{
	case UP:
		m_y -= m_step;
		if (m_y - 8 < battle_Y1)
		{
			m_y += m_step;
			m_direc = (Dir)((rand() % 3 + 1 + (int)m_direc) % 4);
		}
		break;
	case DOWN:
		m_y += m_step;
		if (m_y + 8 > battle_Y2)
		{
			m_y -= m_step;
			m_direc = (Dir)((rand() % 3 + 1 + (int)m_direc) % 4);
		}
		break;
	case LEFT:
		m_x -= m_step;
		if (m_x - 8 < battle_X1)
		{
			m_x += m_step;
			m_direc = (Dir)((rand() % 3 + 1 + (int)m_direc) % 4);
		}
		break;
	case RIGHT:
		m_x += m_step;
		if (m_x + 8 > battle_X2)
		{
 		 	m_x -= m_step;
			m_direc = (Dir)((rand() % 3 + 1 + (int)m_direc) % 4);
		}
		break;
	default:
		break;
	}
	this->m_pos.SetY(m_y);
	this->m_pos.SetX(m_x);
}

void EnemyTank::CalculateSphere()
{
	int m_x = m_pos.GetX();
	int m_y = m_pos.GetY();
	
	switch (m_direc)
	{
	case UP:
	case DOWN:
		m_rectSphere.Set(m_x - 8, m_y - 6, m_x + 8, m_y + 6);
		break;
	case RIGHT:
	case LEFT:
		m_rectSphere.Set(m_x - 6, m_y - 8, m_x + 6, m_y + 8);
		break;
	default:
		break;
	}
}

void EnemyTank::RandChangeDirec()
{
	int seed = rand() % m_changeDirecProbality;
	
	if (seed == m_changeDirecProbality / 2)
	{
		m_direc = (Dir)(rand() % 4);
	}
}

BOOL EnemyTank::IsDisappear()
{
	return m_bDisappear;
}