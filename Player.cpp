#include "Player.h"
#include "EventFSM.h"

Player::Player()
{

}
Player::~Player()
{
}

bool Player::init()
{
	fsm = EventFsm::createEventFsm(this);
	fsm->retain();

	ArmatureDataManager::getInstance()->addArmatureFileInfo("WarriorMale4.ExportJson");
    animate = Armature::create("WarriorMale4");
	animate->getAnimation()->play("idle");
	animate->setScale(1,1);
	animate->setPosition(Point(0,50));
	this->addChild(animate);



	return true;
}

void Player::stand()
{
	animate->getAnimation()->play("idle");
	
}

void Player::run()
{
	animate->getAnimation()->play("move");
}

void Player::attack()
{
	this->fighting();
	animate->getAnimation()->play("attack");
}

void Player::skill()
{   
	this->fighting();
	animate->getAnimation()->play("skill");

}

void Player::hurt()
{
	animate->getAnimation()->play("hurt");

}

void Player::dead()
{
	animate->getAnimation()->play("dead");

}

void Player::win()
{
	animate->getAnimation()->play("win");

}

void Player::bigfuck()
{
	ArmatureDataManager::getInstance()->addArmatureFileInfo("EffWarriorMale.ExportJson");
	animateq = Armature::create("EffWarriorMale");
	animateq->getAnimation()->play("skill_hit_middle_h");
	animateq->setPosition(Point(800, 100));

	if (lrxs == true)
	{
		animateq->setScaleX(1);
	}
	else
	{

		animateq->setScaleX(-1);
	}

	this->addChild(animateq);
	animateq->setPosition(Point(40, 100));
	animate->setVisible(true);
	animateq->getAnimation()->play("skill_hit_middle_h");
	
}

void Player::sxskill()
{
	ArmatureDataManager::getInstance()->addArmatureFileInfo("EffPastorMale.ExportJson");
	Armature* animatesx = Armature::create("EffPastorMale");
	animatesx->getAnimation()->playWithIndex(1, -1, -1);
	animatesx->getAnimation()->setSpeedScale(2);
	animatesx->setPosition(-15, 50);
	this->addChild(animatesx);

	animate->getAnimation()->play("move");
	animate->getAnimation()->setSpeedScale(2);

	CallFunc* huifsudu = CallFunc::create([&](){animate->getAnimation()->setSpeedScale(1);});

	animate->runAction(
		Sequence::create(
		FadeTo::create(0.2f, 0),
		DelayTime::create(0.2f),
		FadeTo::create(0.1f, 255),
		huifsudu,
		nullptr));

	int x = this->getPosition().x;

	int y = this->getPosition().y;

	if (lrxs == true)
	{
		//this->setVisible(false);
		MoveBy* tothere;
		if (x >= 1700)
		{
			tothere = MoveTo::create(0.3f, Point(1998, y));
		}
		else
		{
			tothere = MoveBy::create(0.3f, Point(300, 0));
		}
		auto yanshi = EaseIn::create(tothere->clone(), 0.2f);
		auto delay = DelayTime::create(0.3f);
		CallFunc* func = CallFunc::create([&](){this->setVisible(true); });
		auto seq1 = Sequence::create(tothere, delay, func, nullptr);
		this->runAction(seq1);
	}
	if (lrxs == false)
	{
		//this->setVisible(false);
		MoveBy* tothere;
		if (x <= 400)
		{
			tothere = MoveTo::create(0.3f, Point(100, y));
		}
		else
		{
			tothere = MoveBy::create(0.3f, Point(-300, 0));
		}

		auto yanshi = EaseIn::create(tothere->clone(), 0.2f);
		auto delay = DelayTime::create(0.3f);
		CallFunc* func = CallFunc::create([&](){this->setVisible(true); });
		auto seq1 = Sequence::create(tothere, delay, func, nullptr);
		this->runAction(seq1);
	}
}

void Player::setViewPointByPlayer()//地图移动
{
	if (m_sprite == NULL)
	{
		return;
	}
	Layer* parent = (Layer*)getParent();// 可视画面，camera

	Size mapTileNum = m_map->getMapSize();

	Size tiledSzie = m_map->getTileSize();

	//地图大小
	Size mapSize = Size(
		mapTileNum.width * tiledSzie.height,
		mapTileNum.width * tiledSzie.height);

	Size visibleSize = Director::getInstance()->getVisibleSize();

	Point spritePos = getPosition();

	float x = std::max(spritePos.x, visibleSize.width / 2);
	float y = std::max(spritePos.y, visibleSize.height / 2 );

	x = std::min(x, mapSize.width - visibleSize.width / 2);
	y = std::min(y, mapSize.height - visibleSize.height / 2);

	Point destPos = Point(x, y);

	Point centerPos = Point(visibleSize.width / 2, visibleSize.height / 2);

	Point viewPos = centerPos - destPos;


	parent->setPosition(viewPos);

}

void Player::setTagPosition(float x, float y)
{
   
	Point dstPos = Point(x, y);

	Point tiledPos = tileCoordForPosition(Point(dstPos.x, dstPos.y));

	int tiledGid = meta->getTileGIDAt(tiledPos);

	if (tiledGid != 0)
	{
		 Value properties = m_map->getPropertiesForGID(tiledGid);  //地图格子属性，全部的，如果要获取不同属性则判断属性，
		 ValueMap propertiesMap = properties.asValueMap();

		if (propertiesMap.find("Collidable") != propertiesMap.end())
		 {
					Value prop = propertiesMap.at("Collidable");
					if (prop.asString().compare("true") == 0)
					{ return; }
	     }
		Value prop = properties.asValueMap().at("Collidable");
	}

	Entity::setTagPosition(x, y);

	if (sdmap == false)
	{
		setViewPointByPlayer();
	}


}

void Player::sdingditu()

{
	if (sdmap == false)
	{
		sdmap = true;
	}
	else
	{
		sdmap = false;
	}
}

void Player::setTiledMap(TMXTiledMap* map)
{
	this->m_map = map;

	this->meta = m_map->getLayer("ground2");
	this->meta->setVisible(false);

}
Point Player::tileCoordForPosition(Point pos)
{
	Size mapTiledNum = m_map->getMapSize();
	Size tiledSize = m_map->getTileSize();

	int x = pos.x / tiledSize.width;
	int y = ((m_map->getMapSize().height * m_map->getTileSize().height) - pos.y) / tiledSize.height;

	return Point(x, y);
}
void Player::change()
{
	animate->setScaleX(-1);

	lrxs = false;
}
void Player::changes()
{
	animate->setScaleX(1);

	lrxs = true;
}

