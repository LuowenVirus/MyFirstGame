#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "cocos2d.h"
#include "ControllerListener.h"

USING_NS_CC;

//----------------------------设置控制器，在主角类中绑定主角--------------------------------------------------------

class Controller : public Node
{
public:
	void setControllerListener(ControllerListener* controllerListener);

protected:
	ControllerListener* m_controllerListener;

};

#endif