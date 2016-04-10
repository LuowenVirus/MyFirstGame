#ifndef PLAYER_H
#define PLYAER_H

#include "cocos2d.h"
#include "Entity.h"
#include "cocostudio\CocoStudio.h"
using namespace cocostudio;

USING_NS_CC;

class EventFsm;
class Player : public Entity
{
public:
	Player();
	~Player();

	CREATE_FUNC(Player);

	virtual bool init();

	virtual void stand();

	virtual void run();

	virtual void attack();

	virtual void skill();

	virtual void hurt();

	virtual void dead();

	virtual void win();

	void bigfuck();

	void sxskill();

	virtual void setViewPointByPlayer();

	void setTiledMap(TMXTiledMap* map);

	virtual void setTagPosition(float x, float y);

	void change();

	void changes();

	void sdingditu();

private:
	Armature* animate;

	Armature* animateq;

	EventFsm* fsm;

	TMXTiledMap* m_map;

	TMXLayer* meta;

	Point tileCoordForPosition(Point pos);

	bool lrxs = true;

	bool sdmap = false;


};

#endif