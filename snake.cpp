#include "snake.h"

CSnake::CSnake() : direction(RIGHT) {//NOT order in order
	list<pair<int, int>>::iterator cur = snakeBody.begin();
	cur = snakeBody.insert(cur, pair<int, int>(1, 1));
	cur = snakeBody.insert(cur, pair<int, int>(2, 1));
	cur = snakeBody.insert(cur, pair<int, int>(3, 1));
	head = cur;
	next = {4,1};
}

void CSnake::NextToNext(){
	switch (direction){
	case UP:
		next.second--;
		break;
	case DOWN:
		next.second++;
		break;
	case LEFT:
		next.first--;
		break;
	case RIGHT:
		next.first++;
		break;
	}
}

void CSnake::Grow(){
	head = snakeBody.insert(head, next);
	NextToNext();
}

void CSnake::UpdateDirec(int i){
	pair<int, int> tmp;
	switch(i){
	case UP:
		tmp.first = head->first;
		tmp.second = head->second - 1;
		break;
	case DOWN:
		tmp.first = head->first;
		tmp.second = head->second + 1;
		break;
	case LEFT:
		tmp.first = head->first - 1;
		tmp.second = head->second;
		break;
	case RIGHT:
		tmp.first = head->first + 1;
		tmp.second = head->second;
		break;
	}
	if (tmp != *(++snakeBody.begin())){
		next = tmp;
		direction = i;
	}
}

void CSnake::Move(){
	head = snakeBody.insert(head, next);
	NextToNext();
	snakeBody.pop_back();
}