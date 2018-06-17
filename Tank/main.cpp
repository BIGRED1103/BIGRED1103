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
	Rect rectTemp;
	
	/**初始化敌军坦克**/
	Vehicle *pVehicle;
	list<Vehicle *> lstVehicle;
	list<Vehicle *>::iterator it_Vehicle;
	lstVehicle.clear();

	int nIndexEnemy;
	for (nIndexEnemy = 0; nIndexEnemy < ENEMYTANK_MAX; nIndexEnemy++)
	{
		pVehicle = new EnemyTank();
		lstVehicle.push_back(pVehicle);
		pVehicle = NULL;
	}

	list<Bullet * > lstBullets;
	lstBullets.clear();
	list<Bullet *>::iterator it_Bullet;

	list<Bullet * > lstEnemyBullets;
	lstEnemyBullets.clear();
	
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
			
			for (it_Vehicle = lstVehicle.begin(); it_Vehicle != lstVehicle.end(); it_Vehicle++)
			{
				(*it_Vehicle)->Move();
				(*it_Vehicle)->Shoot(lstEnemyBullets);
				(*it_Vehicle)->Display();
				if ((*it_Vehicle)->IsDisappear())
				{
					delete (*it_Vehicle);
					it_Vehicle = lstVehicle.erase(it_Vehicle);
					continue;
				}
			}

			for (it_Bullet = lstBullets.begin(); it_Bullet != lstBullets.end(); it_Bullet++)
			{
				(*it_Bullet)->Move();
				for (it_Vehicle = lstVehicle.begin(); it_Vehicle != lstVehicle.end(); it_Vehicle++)
				{
					//碰撞检测
		 			if((*it_Bullet)->CrashCheck((*it_Vehicle)->GetSphere()))	  //使用父类承接子类，只能调用父类中声明的公有方法
					{
						(*it_Vehicle)->SetBoom();
						(*it_Bullet)->SetBoom();
						break;
					}
				}

				(*it_Bullet)->Display();
				if ((*it_Bullet)->IsDisappear())
				{
					delete (*it_Bullet);
					it_Bullet = lstBullets.erase(it_Bullet);
					continue;
				}  
			}

			for (it_Bullet = lstEnemyBullets.begin(); it_Bullet != lstEnemyBullets.end(); it_Bullet++)
			{
				(*it_Bullet)->Move();
				//碰撞检测
				if((*it_Bullet)->CrashCheck(mainTank.GetSphere()))	  
				{
					// mainTank.SetBoom();
					(*it_Bullet)->SetBoom();
				}

				(*it_Bullet)->Display();
				if ((*it_Bullet)->IsDisappear())
				{
					delete (*it_Bullet);
					it_Bullet = lstEnemyBullets.erase(it_Bullet);
					continue;
				}  
			}
        }  
		
        Sleep(50);  
    }  

	for (it_Vehicle = lstVehicle.begin(); it_Vehicle != lstVehicle.end(); it_Vehicle++)
	{
		delete (*it_Vehicle);
		*it_Vehicle = NULL;
	}

	for (it_Bullet = lstBullets.begin(); it_Bullet != lstBullets.end(); it_Bullet++)
	{
		delete *it_Bullet;
		it_Bullet = NULL;
	}

	for (it_Bullet = lstEnemyBullets.begin(); it_Bullet != lstEnemyBullets.end(); it_Bullet++)
	{
		delete *it_Bullet;
	}
	lstBullets.clear();
	lstEnemyBullets.clear();
	
    Graphic::Destroy();  
}  