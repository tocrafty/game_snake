#include <iostream>
#include <time.h>
#include <windows.h>
#include "snake.h"
#include "window.h"
#include "rules.h"

using namespace std;
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)

int main(){
	cout << "Welcome to Game Snake!" << endl;
	cout << "Select the difficulty level: 1, 2, or 3:" << endl;
	int dif;
	cin >> dif;
	//Game Initialazation
	CSnake snake;
	switch(dif){
	case 1:
		snake.speed = HIGH_SPEED;
		break;
	case 2:
		snake.speed = MIDDLE_SPEED;
		break;
	case 3:
		snake.speed = LOW_SPEED;
		break;
	}
	CWindow window;
	CRules rules;
	CFood food;
	food.RandomFood(snake, window);
	bool gameover = false;
	clock_t start = clock();
	while(!gameover){
		if (KEY_DOWN('W')){
			snake.UpdateDirec(UP);
		}
		else if (KEY_DOWN('A')){
			snake.UpdateDirec(LEFT);
		}
		else if (KEY_DOWN('S')){
			snake.UpdateDirec(DOWN);
		}
		else if (KEY_DOWN('D')){
			snake.UpdateDirec(RIGHT);
		}
		if (clock() - start > CLOCKS_PER_SEC/60.0f*snake.speed){
			start = clock();
			if (rules.SelfCollid(snake) || rules.WallCollid(snake, window))
				gameover = true;
			if (rules.EatFood(snake, food)){
				snake.Grow();
				food.RandomFood(snake, window);
			}
			else snake.Move();
			window.Draw(snake, food);
		}
	}
	cout << "You Lose!" << endl;
	system("pause");
}