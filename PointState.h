#ifndef POINTSTATE_H
#define POINTSTATE_H

#include "Execute.h"
class State;
class Player;

class PointState 
{
public:
	PointState();

	void speedX(int x);

	void speedY(int y);

	int gspeedX();

	int gspeedY();
private:
	Player* m_players;

	int xSpeed =0;

	int ySpeed =0;
};

#endif