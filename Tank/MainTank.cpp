#include "MainTank.h"

MainTank::MainTank() 
{
	m_pos.Set(300, 300);

	this->m_color = YELLOW;
	m_direc = UP;
	m_step = 5;
}

MainTank::~MainTank()
{

}

void MainTank::SetDirec(Dir _direc)
{
	m_direc = _direc;
}

void MainTank::SetStep(int _step)
{
	m_step = _step;
}

int MainTank::GetStep()
{
	return m_step;
}

void MainTank::Display()
{
	COLORREF fillcolor_save = getfillcolor();
	COLORREF color_save = getcolor();
 	setfillcolor(m_color);
	setcolor(m_color);

 	DrawTankBody();
	CalculateSphere();

 	setfillcolor(fillcolor_save);
	setcolor(color_save);
}

void MainTank::Move()
{
	int m_y, m_x;
	m_x = this->m_pos.GetX();
	m_y = this->m_pos.GetY();

// 	Point m_startPos = Graphic::m_rectBattleGround.GetStartPoint();
// 	Point m_endPos = Graphic::m_rectBattleGround.GetEndPoint();

	int battle_X1 = BATTLE_GROUND_X1;
	int battle_Y1 = BATTLE_GROUND_Y1;
	int battle_X2 = BATTLE_GROUND_X2;
	int battle_Y2 = BATTLE_GROUND_Y2;

	switch (m_direc)
	{
	case UP:
		m_y -= m_step;
		if (m_y - 6 < battle_Y1)
		{
			m_y = battle_Y2 - 6;
		}
		break;
	case DOWN:
		m_y += m_step;
		if (m_y + 6 > battle_Y2)
		{
			m_y = battle_Y1 + 6;
		}
		break;
	case LEFT:
		m_x -= m_step;
		if (m_x - 6 < battle_X1)
		{
			m_x = battle_X2 - 6;
		}
		break;
	case RIGHT:
		m_x += m_step;
		if (m_x + 6 > battle_X2)
		{
			m_x = battle_X1 + 6;
		}
		break;
	}
	this->m_pos.SetY(m_y);
	this->m_pos.SetX(m_x);
}

void MainTank::DrawTankBody()
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

void MainTank::CalculateSphere()
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