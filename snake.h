#ifndef CSNAKE_H
#define CSNAKE_H

#include <list>
using namespace std;

#define UP		0x01
#define DOWN	0x02
#define LEFT	0x03
#define RIGHT	0x04
#define HIGH_SPEED		10  //frames per step
#define MIDDLE_SPEED	20
#define LOW_SPEED		40

class CSnake {
private:
	void NextToNext();
public:
	list<pair<int, int>> snakeBody;
	list<pair<int, int>>::iterator head;
	pair<int, int> next;
	int speed;
	int direction;

	CSnake();
	void Grow();
	void UpdateDirec(int);
	void Move();
};

#endif