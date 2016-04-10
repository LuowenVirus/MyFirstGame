#include "Controllplayer.h"
#include "HRocker.h"
#include "ExecuteTypes.h"
#include "Player.h"

bool ControllerPlayer::init()
{

    rocker = HRocker::createHRocker("yao2.png", "yao1.png", Point(60, 60));
	rocker->startlistener();   // ×¢²á¼àÌý
	this->addChild(rocker);

	NotificationCenter::getInstance()->addObserver(this, callfuncO_selector(ControllerPlayer::stopFunc), "stop", NULL);

	NotificationCenter::getInstance()->addObserver(this, callfuncO_selector(ControllerPlayer::is_startlistener), "startlistener", NULL);

	NotificationCenter::getInstance()->addObserver(this, callfuncO_selector(ControllerPlayer::is_stoplistener), "stoplistener", NULL);


	auto UI_1 = cocostudio::GUIReader::getInstance()->widgetFromJsonFile("fight_1.ExportJson");
	UI_1->setPosition(Point(0, 0));
	UI_1->setSwallowTouches(false);
	this->addChild(UI_1, 2);

	attack = (Button*)Helper::seekWidgetByName(UI_1, "Button_4");
	attack->addTouchEventListener(this, toucheventselector(ControllerPlayer::attackEvent));

	skill = (Button*)Helper::seekWidgetByName(UI_1, "Button_1");
	skill->addTouchEventListener(this, toucheventselector(ControllerPlayer::skillEvent));

	shangxian = (Button*)Helper::seekWidgetByName(UI_1, "Button_3");
	shangxian->addTouchEventListener(this, toucheventselector(ControllerPlayer::sxEvent));

	bigskill = (Button*)Helper::seekWidgetByName(UI_1, "Button_2");
	bigskill->addTouchEventListener(this, toucheventselector(ControllerPlayer::bigskillEvent));


	this->scheduleUpdate();

	return true;
}


void ControllerPlayer::update(float dt)
{
	if (m_controllerListener == NULL)
	{
		return;
	}

	if (rocker->is_move())
	{


		Speed = rocker->getAnglePosition(4);



		if (Speed.x > 0)
		{
			NotificationCenter::getInstance()->postNotification(StringUtils::toString(rightType));

		}
		if (Speed.x < 0)
		{
			NotificationCenter::getInstance()->postNotification(StringUtils::toString(leftType));

		}
	}
	else
	{
		Speed = Point(0, 0);
	}
	Point curPos = m_controllerListener->getTagPosition();
	curPos.x += Speed.x;
	curPos.y += Speed.y;

	m_controllerListener->setTagPosition(curPos.x, curPos.y);

}

void  ControllerPlayer::stopFunc(Ref* psender)
{
	Speed = Point(0,0);
}

void ControllerPlayer::is_startlistener(Ref* psender)  //  ¿ªÆôÒ¡¸Ë£¬ ¼ÌÐøÒÆ¶¯
{
	rocker->startlistener();
}
void ControllerPlayer::is_stoplistener(Ref* psender)   //  ¹Ø±ÕÒ¡¸Ë£¬ ¶¯×÷ÐëÒªÍ£Áô
{
	rocker->stoplistener();
}

void ControllerPlayer::bangdingplayer(Player* m_player)
{
	this->m_player = m_player;
}

void ControllerPlayer::attackEvent(Ref*, TouchEventType type)
{
	switch (type)
	{
	case TouchEventType::TOUCH_EVENT_BEGAN:
	{
											  cdImg(1.5, "500010001.png", "CD1.png", attack, 1, attackcd);
											  break;
	}
	case TouchEventType::TOUCH_EVENT_ENDED:
	{
											  break;
	}

	}
}

void ControllerPlayer::skillEvent(Ref*, TouchEventType type)
{
	switch (type)
	{
	case TouchEventType::TOUCH_EVENT_BEGAN:
	{

											  cdImg(5, "500010003.png", "CD2.png", skill, 0.74, skillcd);
											  break;
	}
	case TouchEventType::TOUCH_EVENT_MOVED:
	{

											  break;
	}
	case TouchEventType::TOUCH_EVENT_ENDED:
	{

											  break;
	}

	}
}

void ControllerPlayer::bigskillEvent(Ref*, TouchEventType type)
{
	switch (type)
	{
	case TouchEventType::TOUCH_EVENT_BEGAN:
	{
											  m_player->bigfuck();

											  cdImg(15, "500010005.png", "CD3.png", bigskill, 0.74, bigskillcd);
											  break;
	}
	case TouchEventType::TOUCH_EVENT_ENDED:
	{

											  break;
	}

	}
}

void ControllerPlayer::sxEvent(Ref*, TouchEventType type)
{
	switch (type)
	{
	case TouchEventType::TOUCH_EVENT_BEGAN:
	{
											  PlayerAction("stop");

											  cdImg(3, "500303001.png", "CD4.png", shangxian, 0.74, shangxiancd);

											  break;
	}
	case TouchEventType::TOUCH_EVENT_ENDED:
	{

											  break;
	}

	}
}


void ControllerPlayer::Cdskill(float dt)
{
	PlayerAction(StringUtils::toString(standType));
	PlayerAction("stop");
}



void ControllerPlayer::cdImg(float time, std::string name1, std::string name2, Button* but, float scale, MyEnum type)
{
	CallFunc* cding;
	CallFunc* cded;

	ccdbut();
	switch (type)
	{
	case attackcd:
	{
					 cding = CallFunc::create([&](){attackisCD = true; });
					 cded = CallFunc::create([&](){attackisCD = false; });
					 this->scheduleOnce(schedule_selector(ControllerPlayer::oscdbut), 1.0f);
					 PlayerAction(StringUtils::toString(attackType));
					 this->scheduleOnce(schedule_selector(ControllerPlayer::Cdskill), 0.8f);
					 break;
	}
	case skillcd:
	{
					cding = CallFunc::create([&](){skillisCD = true; });
					cded = CallFunc::create([&](){skillisCD = false; });
					this->scheduleOnce(schedule_selector(ControllerPlayer::oacdbut), 1.2f);
					PlayerAction(StringUtils::toString(skillType));
					this->scheduleOnce(schedule_selector(ControllerPlayer::Cdskill), 1.2f);
					break;
	}
	case bigskillcd:
	{
					   cding = CallFunc::create([&](){ bigisCD = true; });
					   cded = CallFunc::create([&](){ bigisCD = false; });
					   this->scheduleOnce(schedule_selector(ControllerPlayer::obscdbut), 2.0f);
					   PlayerAction(StringUtils::toString(skillType));
					   this->scheduleOnce(schedule_selector(ControllerPlayer::Cdskill), 1.2f);
					   break;
	}
	case shangxiancd:
	{
						cding = CallFunc::create([&](){ sxisCD = true; });
						cded = CallFunc::create([&](){ sxisCD = false; });
						this->scheduleOnce(schedule_selector(ControllerPlayer::osxcdbut), 0.6f);
						m_player->sxskill();
						this->scheduleOnce(schedule_selector(ControllerPlayer::Cdskill), 0.6f);
						break;
	}
	}


	SpriteFrameCache* frameCache = SpriteFrameCache::getInstance();
	frameCache->addSpriteFramesWithFile("fight0.plist", "fight0.png");

	Point thepoint = but->getPosition();

	auto cds = Sprite::createWithSpriteFrameName(name2);
	cds->setPosition(thepoint);
	cds->setScale(scale, scale);
	addChild(cds, 3);


	auto funk = [cds, but]()
	{
		cds->setVisible(false);
		but->setEnabled(true);
	};

	CallFunc* func = CallFunc::create(funk);



	auto cd = ProgressTimer::create(Sprite::createWithSpriteFrameName(name1));
	cd->setType(ProgressTimer::Type::RADIAL);
	cd->setPosition(thepoint);
	cd->setScale(0.74, 0.74);
	auto to1 = Sequence::create(cding, ProgressTo::create(time, 100), ProgressTo::create(0, 0), func, cded, nullptr);
	cd->runAction(to1);
	addChild(cd, 4);
}

void ControllerPlayer::ccdbut()
{
	PlayerAction("stoplistener");

	attack->setEnabled(false);

	skill->setEnabled(false);

	bigskill->setEnabled(false);

	shangxian->setEnabled(false);


}

void ControllerPlayer::oscdbut(float dt)
{
	PlayerAction("startlistener");

	if (!skillisCD)
	{
		skill->setEnabled(true);
	}

	if (!bigisCD)
	{
		bigskill->setEnabled(true);
	}

	if (!sxisCD)
	{
		shangxian->setEnabled(true);
	}


}

void ControllerPlayer::oacdbut(float dt)
{
	PlayerAction("startlistener");

	if (!attackisCD)
	{
		attack->setEnabled(true);
	}

	if (!bigisCD)
	{
		bigskill->setEnabled(true);
	}

	if (!sxisCD)
	{
		shangxian->setEnabled(true);
	}


}

void ControllerPlayer::obscdbut(float dt)
{
	PlayerAction("startlistener");

	if (!attackisCD)
	{
		attack->setEnabled(true);
	}


	if (!skillisCD)
	{
		skill->setEnabled(true);
	}

	if (!sxisCD)
	{
		shangxian->setEnabled(true);
	}
}

void ControllerPlayer::osxcdbut(float dt)
{
	PlayerAction("startlistener");

	if (!attackisCD)
	{
		attack->setEnabled(true);
	}


	if (!skillisCD)
	{
		skill->setEnabled(true);
	}

	if (!bigisCD)
	{
		bigskill->setEnabled(true);
	}

}