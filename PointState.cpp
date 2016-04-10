#include "PointState.h"
#include "Player.h"

 PointState::PointState()
{
	xSpeed = 0;

	ySpeed = 0;

}


void PointState::speedX(int x)
{
	this->xSpeed = x;

}

void PointState::speedY(int y)
{
	this->ySpeed = y;
}

int PointState::gspeedX()
{
	return xSpeed;
}

int PointState::gspeedY()
{
	return ySpeed;
}