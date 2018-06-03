#include "Graphic.h"

Rect Graphic::m_rectScreen;
Rect Graphic::m_rectBattleGround;


void Graphic::Create()
{
	initgraph(SCREEN_WIDTH, SCREEN_HEIGHT);
	setbkcolor(DARKGRAY);

	m_rectScreen.Set(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
	m_rectBattleGround.Set(BATTLE_GROUND_X1, BATTLE_GROUND_Y1, BATTLE_GROUND_X2, BATTLE_GROUND_Y2);
}

void Graphic::Destroy()
{
	closegraph();
}

int Graphic::GetScreenWidth()
{
	return SCREEN_WIDTH;
}

int Graphic::GetScreenHeight()
{
	return SCREEN_HEIGHT;
}

void Graphic::DrawBattleGround()
{
	rectangle(BATTLE_GROUND_X1, BATTLE_GROUND_Y1, BATTLE_GROUND_X2, BATTLE_GROUND_Y2);
}

Rect Graphic::GetBattleGround()
{	
	return m_rectBattleGround;
}
