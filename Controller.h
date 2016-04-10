#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "cocos2d.h"
#include "ControllerListener.h"

USING_NS_CC;

//----------------------------���ÿ����������������а�����--------------------------------------------------------

class Controller : public Node
{
public:
	void setControllerListener(ControllerListener* controllerListener);

protected:
	ControllerListener* m_controllerListener;

};

#endif