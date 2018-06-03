#ifndef _GRAPHIC_H_
#define _GRAPHIC_H_

#include "graphics.h"
#include "conio.h"
#include "Model/Rect.h"

#define SCREEN_WIDTH 768
#define SCREEN_HEIGHT 480

#define BATTLE_GROUND_X1 5
#define BATTLE_GROUND_Y1 5
#define BATTLE_GROUND_X2 550
#define BATTLE_GROUND_Y2 475


class Graphic
{
public :
	static void Create();
	static void Destroy();

	static int GetScreenWidth();
	static int GetScreenHeight();
	
	static void DrawBattleGround();
	static Rect GetBattleGround();

private :
	static Rect m_rectScreen;
	static Rect m_rectBattleGround;
};


#endif