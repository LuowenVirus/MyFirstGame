#include "Monster.h"
#include"Player.h"
#include "cocos2d.h"
#include "GwFsm.h"

Monster::Monster()
{

}

Monster::~Monster()
{
}

bool Monster::init()
{
	gwfsm = GwFsm::createEventFsm(this);
	gwfsm->retain();

	ArmatureDataManager::getInstance()->addArmatureFileInfo("silingqishi.ExportJson");
	gwanimate = Armature::create("silingqishi");
	gwanimate->getAnimation()->play("idle");
	gwanimate->setScale(1, 1);
	gwanimate->setPosition(Point(0, 50));
	this->addChild(gwanimate);

	return true;
}

void Monster::addmoster()
{
	
}

void Monster::removemoster()
{
	if (die_is == true)
	{

	}
}


void Monster::gwstand()
{
	gwanimate->getAnimation()->play("idle");
}

void Monster::gwattack()
{
	gwanimate->getAnimation()->play("attack");
}

void Monster::gwskill()
{
	gwanimate->getAnimation()->play("skill");
}

void Monster::gwmove()
{
	gwanimate->getAnimation()->play("move");
}

void Monster::gwhurt()
{
	gwanimate->getAnimation()->play("hurt");
}

void Monster::gwwin()
{
	gwanimate->getAnimation()->play("win");
}

void Monster::gwdead()
{
	gwanimate->getAnimation()->play("dead");
}

void Monster::changeleft()//怪物向左
{
	gwanimate->setScaleX(1);
}

void Monster::changeright() //怪物向右
{
	gwanimate->setScaleX(-1);
}

bool Monster::is_die()
{
	die_is = true;

	return die_is;
}

bool Monster::is_hurt()
{
	hurt_is = true;

	return hurt_is;
}

bool Monster::is_attack()
{
	attack_is = true;

	return attack_is;
}

void Monster::setTagPosition(float x, float y)
{
	Entity::setTagPosition(x, y);

}

bool Monster::is_isCollide(Player* m_player)
{
	//Rect entityRect = m_player->getBoundingBox();  // 获取主角矩形范围

	//Point monsterPos = getPosition();

	//return entityRect.containsPoint(monsterPos);//  判断是否有交集

	return false;
}