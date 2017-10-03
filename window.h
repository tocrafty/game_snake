#ifndef CWINDOW_H
#define CWINDOW_H

#include <vector>
#include "snake.h"
#include "food.h"
#define WIDTH 		20
#define HEIGHT 		15

class CFood;
class CWindow {
public:
	vector<pair<int, int>> Walls;
	
	CWindow();
	int width, height;
	void Draw(const CSnake &, const CFood &);
};
#endif