#ifndef CFOOD_H
#define CFOOD_H
#include "snake.h"
#include "window.h"

class CWindow;
class CFood {
public:
	pair<int, int> food;

	CFood();
	void RandomFood(const CSnake&, const CWindow&);
};

#endif