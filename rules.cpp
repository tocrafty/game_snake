#include <set>
#include "rules.h"

using namespace std;

bool CRules::SelfCollid(const CSnake &snake){
	for (auto &a : snake.snakeBody){
		if (a == snake.next)
			return true;
	}
	return false;
}

bool CRules::WallCollid(const CSnake& snake, const CWindow &window){
	if (snake.next.first == 0 || snake.next.second == 0 ||
		snake.next.first == WIDTH+1 || snake.next.second == HEIGHT+1)
		return true;
	return false;
}

bool CRules::EatFood(CSnake &snake, CFood &food){
	return snake.next == food.food;
}