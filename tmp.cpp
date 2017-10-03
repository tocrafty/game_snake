#include "window.h"
#include "snake.h"
#include "food.h"
using namespace std;


int main(){
	CSnake snake;
	CWindow window;
	CFood food;
	food.RandomFood(snake, window);
	window.Draw(snake, food);
}