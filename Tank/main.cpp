#include <iostream>  
#include <conio.h>  
#include <time.h>  

#include "Graphic.h"  
#include "MainTank.h" 
#include "EnemyTank.h" 
#include "NBullet.h"


#include <list>

using namespace std;  

void main()  
{  
	srand((unsigned)time(NULL)); //随机种子

    Graphic::Create(); 
	Graphic::DrawBattleGround();

    MainTank mainTank;
	Object *pVehicle[ENEMYTANK_MAX];

	int nIndexEnemy;
	for (nIndexEnemy = 0; nIndexEnemy < ENEMYTANK_MAX; nIndexEnemy++)
	{
		pVehicle[nIndexEnemy] = new EnemyTank();
	}

	list<Object * > lstBullets;
	lstBullets.clear();
	list<Object *>::iterator it_Bullet;
	
	int nStep;
    bool loop = true;  
    bool skip = false;  
    while (loop)  
    {  
        if (kbhit())  
        {  
            int key = getch();  
			
            switch (key)  
            {  
				// Up  
            case 72:  
                mainTank.SetDirec(UP); 
                break;  
				// Down  
            case 80:   
                mainTank.SetDirec(DOWN);  
                break;  
				// Left  
            case 75:   
                mainTank.SetDirec(LEFT);  
                break;  
				// Right  
            case 77:   
                mainTank.SetDirec(RIGHT);  
                break;  
            case 224: // 方向键高8位  
                break;  
				// Esc  
            case 27:  
                loop = false;  
                break;  
				// Space  
            case 32: 
				mainTank.Shoot(lstBullets);
                break;  
				// Enter  
            case 13:  
                if (skip)  
                    skip = false;  
                else  
                    skip = true;  
                break; 
			case 43:
				nStep = mainTank.GetStep();
				mainTank.SetStep(++nStep);
				break;
			case 45:
				nStep = mainTank.GetStep();
				mainTank.SetStep(--nStep);
				break;
            default:   
                break;  
            }  

			if (key == 72 || key == 80 || key == 75 || key == 77)
			{
				mainTank.Move();
			}
        }  
		
        if (!skip)  
        {  
            cleardevice();  
			Graphic::DrawBattleGround();  
            mainTank.Display();
			
			for (nIndexEnemy = 0; nIndexEnemy < ENEMYTANK_MAX; nIndexEnemy++)
			{
				pVehicle[nIndexEnemy]->Move();
				pVehicle[nIndexEnemy]->Display();
			}

			for (it_Bullet = lstBullets.begin(); it_Bullet != lstBullets.end(); )
			{
				(*it_Bullet)->Move();
				if ((*it_Bullet)->IsDisappear())
				{
					delete (*it_Bullet);
					it_Bullet = lstBullets.erase(it_Bullet);
				}
				(*it_Bullet)->Display();
				it_Bullet++;
			}
        }  
		
        Sleep(50);  
    }  

	for (nIndexEnemy = 0; nIndexEnemy < ENEMYTANK_MAX; nIndexEnemy++)
	{
		delete pVehicle[nIndexEnemy];
		pVehicle[nIndexEnemy] = NULL;
	}

	for (it_Bullet = lstBullets.begin(); it_Bullet != lstBullets.end(); it_Bullet++)
	{
		delete *it_Bullet;
	}
	lstBullets.clear();
	
    Graphic::Destroy();  
}  