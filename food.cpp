#include <stdlib.h>
#include <time.h>
#include "food.h"

CFood::CFood(){
	srand(time(nullptr));
}

void CFood::RandomFood(const CSnake& snake, const CWindow&){
	bool sgn;
	do{
		food.first = rand() % WIDTH + 1;
		food.second = rand() % HEIGHT + 1;
		sgn = false;
		for (auto &a : snake.snakeBody){
			if (food == a){
				sgn = true;
				break;
			}
		}
	}while(sgn);
}