
#include <stdlib.h>
#include <string>
#include <iostream>
#include "window.h"

using namespace std;
CWindow::CWindow(){
	for (int i = 0; i < WIDTH + 2; ++i){
		Walls.push_back({i, 0});
		Walls.push_back({i, HEIGHT+1});
	}
	for (int i = 1; i <= HEIGHT; ++i){
		Walls.push_back({0, i});
		Walls.push_back({WIDTH+1, i});
	}
}

void CWindow::Draw(const CSnake &snake, const CFood &food){
	system("cls");
	std::string str((WIDTH+3)*(HEIGHT+2), ' ');
	for (auto &a : Walls){
		str[a.second * (WIDTH+3) + a.first] = '#';
	}
	for (auto &a : snake.snakeBody){
		str[a.second * (WIDTH+3) + a.first] = '*';
	}
	str[food.food.second*(WIDTH+3) + food.food.first] = '@';
	for (int i = WIDTH+2; i < (WIDTH+3)*(HEIGHT+2); i += WIDTH+3)
		str[i] = '\n';
	cout << str << endl;
}