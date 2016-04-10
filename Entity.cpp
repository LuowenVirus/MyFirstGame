#include "Entity.h"


void Entity::bindSprite(Sprite* sprite)
{
	m_sprite = sprite;
	m_sprite->setAnchorPoint(Point(0.5,0.5));
	m_sprite->setVisible(false);
	this->addChild(m_sprite);
}

Sprite* Entity::getSprite()
{
	return  this->m_sprite;  //  这里可以知道是否有一个实体
}

void Entity::fighting()
{
	m_sprite->setScaleX(3.5);

	scheduleOnce(schedule_selector(Entity::stopFt), 1.0f);
}

void Entity::stopFt(float dt)
{
	m_sprite->setScaleX(1);
}

void Entity::setController(Controller* controller)
{
	this->m_controller = controller;
	m_controller->setControllerListener(this);
}

void Entity::setTagPosition(float x, float y)
{
	setPosition(Point(x, y));
}

Point Entity::getTagPosition()
{
	return getPosition();
}
