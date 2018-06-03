#ifndef _RECT_H_
#define _RECT_H_

#include "point.h"

class Rect
{
public:
	Rect() {};
	Rect(const Point p1, const Point p2) : m_startPoint(p1), m_endPoint(p2) {};
	Rect(int x1, int y1, int x2, int y2) : m_startPoint(x1, y1), m_endPoint(x2, y2) {};
	~Rect() {};

public:
	Rect& operator=(const Rect &rect)
	{
		m_startPoint = rect.m_startPoint;
		m_endPoint = rect.m_endPoint;

		return *this;
	}

	void Set(const Point dosStart, const Point dosEnd) {m_startPoint = dosStart; m_endPoint = dosEnd;};
	void Set(int x1, int y1, int x2, int y2);

	void SetStartPoint(const Point p) {m_startPoint = p;}
	void SetEndPoint(const Point p) {m_endPoint = p;}

	Point GetStartPoint();
	Point GetEndPoint();
	
	int GetWidth();
	int GetHeight();

private:
	void Check();

	Point m_startPoint;
	Point m_endPoint;
};

#endif