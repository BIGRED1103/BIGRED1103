#include <iostream>  
#include <conio.h>  
#include <time.h>  

#include "Graphic.h"  
#include "MainTank.h" 
#include "EnemyTank.h" 

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
        }  
		
        Sleep(50);  
    }  

	for (nIndexEnemy = 0; nIndexEnemy < ENEMYTANK_MAX; nIndexEnemy++)
	{
		delete pVehicle[nIndexEnemy];
		pVehicle[nIndexEnemy] = NULL;
	}
	
    Graphic::Destroy();  
}  