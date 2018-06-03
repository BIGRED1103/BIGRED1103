#ifndef _POINT_H_
#define _POINT_H_

class Point
{
public:
	Point(){};
	Point(int x, int y): m_x(x), m_y(y){};
	~Point(){};

public:
	Point& operator=(const Point &p)
	{
		m_x = p.m_x;
		m_y = p.m_y;

		return *this;
	}

	void Set(int x, int y)
	{
		m_x = x;
		m_y = y;
	}

	void SetX(int x) {m_x = x;}
	void SetY(int y) {m_y = y;}

	int GetX() {return m_x;}
	int GetY() {return m_y;}

private:
	int m_x;
	int m_y;

};



#endif