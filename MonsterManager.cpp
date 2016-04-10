#include "MonsterManager.h"
#include "Monster.h"
#include "Player.h"
#include "ExecuteTypes.h"


MonsterManager::MonsterManager()
{}

MonsterManager::~MonsterManager()
{}

bool MonsterManager::init()
{
	createMonsters();

	this->schedule(schedule_selector(MonsterManager::lookplayer), 3.0f);

	this->scheduleUpdate();

	return true;
}

void MonsterManager::createMonsters()
{
	auto sprite_1 = Sprite::create("m_sprite.png");

	m_monster = Monster::create();

	m_monster->bindSprite(sprite_1);

	m_monster->setPosition(Point(500, 240));

	this->addChild(m_monster, 1);
}

void MonsterManager::update(float dt)
{
	Point s = m_player->getPosition();

	Point z = m_monster->getPosition();

	if (s.x < z.x)
	{
		m_monster->changeleft();
	}
	else
	{
		m_monster->changeright();
	}

	m_monster->setPosition(Point(z.x+xspeed,z.y+yspeed));

	log("%f------%f",s.x,s.y);
}

void MonsterManager::lookplayer(float dt)
{
	Point s = m_player->getPosition();
 
	Point z = m_monster->getPosition();


}

void MonsterManager::bangPlayer(Player* m_player)
{
	this->m_player = m_player;
}

void MonsterManager::setTiledMap(TMXTiledMap* map)
{
	this->m_map = map;

	this->meta = m_map->getLayer("ground2");
	this->meta->setVisible(false);
}
