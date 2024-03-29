#include "rect.h"

void Rect::Set(int x1, int y1, int x2, int y2)
{
	m_startPoint.Set(x1, y1);
	m_endPoint.Set(x2,y2);
}

Point Rect::GetStartPoint()
{
	return this->m_startPoint;
}

Point Rect::GetEndPoint()
{
	return this->m_endPoint;
}


int Rect::GetWidth()
{
	return m_endPoint.GetX() - m_startPoint.GetX();
}

int Rect::GetHeight()
{
	return m_endPoint.GetY() - m_startPoint.GetY();
}

void Rect::Check()
{
	if (m_startPoint.GetX() > m_endPoint.GetX() || m_startPoint.GetY() > m_endPoint.GetY())
	{
		Point p = m_startPoint;
		m_startPoint = m_endPoint;
		m_endPoint = p;
	}
}