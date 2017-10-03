#ifndef CRULES_H
#define CRULES_H
#include "food.h"
#include "snake.h"


class CRules {
public:
	bool SelfCollid(const CSnake&);
	bool WallCollid(const CSnake&, const CWindow&);
	bool EatFood(CSnake&, CFood&);
};

#endif