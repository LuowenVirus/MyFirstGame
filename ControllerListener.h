#ifndef CONTROLLERLISTENER_H 
#define CONTROLLERLISTENER_H

#include "cocos2d.h"
USING_NS_CC;

//---------------------------------�����࣬��Ϊ�ӿ�---------------------------------------------------

class ControllerListener
{
public:
	virtual void setTagPosition(float x, float y) = 0;

	virtual Point getTagPosition() = 0;

};

#endif