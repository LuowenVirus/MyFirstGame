#ifndef MONSTER_H
#define MONSTER_H

#include "cocos2d.h"
#include "Entity.h"
#include "cocostudio\CocoStudio.h"
using namespace cocostudio;

USING_NS_CC;

class Player;
class GwFsm;

class Monster : public Entity
{
public:
	Monster();
	~Monster();

	CREATE_FUNC(Monster);

	virtual bool init();

	void addmoster();

	void removemoster();

	void gwstand();

	void gwattack();

	void gwskill();

	void gwmove();

	void gwhurt();

	void gwwin();

	void gwdead();

	void changeleft(); //怪物向左

	void changeright(); //怪物向右

	bool is_die();

	bool is_hurt();

	bool is_attack();

	bool is_isCollide(Player* m_player);

	virtual void setTagPosition(float x, float y);

private:
	Armature* gwanimate;

	Armature* gwanimateq;

	GwFsm* gwfsm;


private:

	bool die_is = false;

	bool hurt_is = false;

	bool attack_is = false;

	bool is_Collide = false;

};

#endif