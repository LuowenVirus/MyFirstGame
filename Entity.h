#ifndef ENTITY_H
#define ENTITY_H

#include "cocos2d.h"
#include "Controller.h"
#include "ControllerListener.h"
#include "cocostudio\CocoStudio.h"
using namespace cocostudio;
USING_NS_CC;

class Entity : public Node, public ControllerListener 
{
public:
	//�󶨾������
	void bindSprite(Sprite* sprite);

	Sprite* getSprite();

	//���ÿ�����
	void setController(Controller* controller);

	virtual void setTagPosition(float x, float y);

	virtual Point getTagPosition();

	void fighting();

	

protected:

	void stopFt(float dt);

	Sprite* m_sprite;

	Controller* m_controller;
};

#endif