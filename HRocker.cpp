#include "HRocker.h"
#include "ExecuteTypes.h"

HRocker* HRocker::createHRocker(const char *rockerImageName, const char *rockerBGImageName, cocos2d::Point position)
{
	HRocker* layer = HRocker::create();
	if (layer)
	{
		layer->rockerInit(rockerImageName, rockerBGImageName, position);
		return layer;
	}

	CC_SAFE_DELETE(layer);
	return NULL;

}

void HRocker::rockerInit(const char *rockerImageName, const char *rockerBGImageName, cocos2d::Point position)
{
	//添加摇杆背景图
    spRockerBG = Sprite::create(rockerBGImageName);
	spRockerBG->setOpacity(150);
	spRockerBG->setPosition(position);
	addChild(spRockerBG,0);


	//添加摇杆上方那个可移动的图
    spRocker = Sprite::create(rockerImageName);
	spRocker->setOpacity(150);
	spRocker->setPosition(position);
	addChild(spRocker,1);

	//摇杆背景图坐标
	rockerBGPosition = spRockerBG->getPosition();

	this->scheduleUpdate();//更新摇杆范围

	//摇杆背景图半径
	rockerBGR = spRockerBG->getContentSize().width*0.5;
   
	//添加触摸事件

	listener1 = EventListenerTouchOneByOne::create();

	listener1->onTouchBegan = [&](Touch* touch, Event* event)
	{
		Point point = touch->getLocation();
		
		auto target = static_cast<Sprite*>(event->getCurrentTarget());

		Point locationInNode = target->convertToNodeSpace(touch->getLocation());

		Size s = target->getContentSize();
		Rect rect = Rect(0, 0, s.width, s.height);//获取点击的矩形范围

		if (rect.containsPoint(locationInNode))
		{
			target->setPosition(touch->getLocation());
			target->setOpacity(255);
			isCanMove = true;
		}
		return true;
	
	};
	listener1->onTouchMoved = [&](Touch* touch, Event* event)
	{
		auto target = static_cast<Sprite*>(event->getCurrentTarget());

		if (!isCanMove)
		{
			return;
		}

		moveed = true;

		if (isaction)
		{
			NotificationCenter::getInstance()->postNotification(StringUtils::toString(runType));
			isaction = false;
		}


		Point point = touch->getLocation();

	    rad = getRad(rockerBGPosition, point);

		//判断两个圆心的距离是否大于摇杆背景的半径
		if (sqrt(pow(point.x - rockerBGPosition.x, 2) + pow(point.y - rockerBGPosition.y, 2)) >= rockerBGR)
		{
			//确保小圆运动范围在背景圆内
			target->setPosition(ccpAdd(getAnglePosition(rockerBGR), ccp(rockerBGPosition.x, rockerBGPosition.y)));

		}
		else {
			//触点在背景圆内则跟随触点运动
			target->setPosition(target->getPosition() + touch->getDelta());
		}


	};

	listener1->onTouchEnded = [=](Touch* touch, Event* event)
	{
		if (moveed)
		{
			NotificationCenter::getInstance()->postNotification(StringUtils::toString(standType));
		}
		
		spRocker->stopAllActions();

		spRocker->setOpacity(150);

		spRocker->runAction(MoveTo::create(0.08, position));

		rad = 0;

		isaction = true;

		isCanMove = false;

		moveed = false;
	};

	listener2 = EventListenerTouchOneByOne::create();

	listener2->onTouchBegan = [&](Touch* touch, Event* event)
	{
		auto target = static_cast<Sprite*>(event->getCurrentTarget());

		Point locationInNode = target->convertToNodeSpace(touch->getLocation());
		Size s = target->getContentSize();
		Rect rect = Rect(0, 0, s.width, s.height);
		if (rect.containsPoint(locationInNode))
		{
			target->setPosition(touch->getLocation());
			target->setOpacity(255);
			isCanMove = true;
		}

	

		return true;

	};
	listener2->onTouchMoved = [&](Touch* touch, Event* event)
	{
	
	};

	listener2->onTouchEnded = [=](Touch* touch, Event* event)
	{
		spRockerBG->stopAllActions();

		spRockerBG->setOpacity(150);

		spRockerBG->runAction(MoveTo::create(0.08, position));

		isCanMove = false;
	};

	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener1, spRocker);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener2, spRockerBG);
	
	listener1->setSwallowTouches(false);
	listener2->setSwallowTouches(false);

}

//得到两坐标的角度值
float HRocker::getRad(cocos2d::Point pos1, cocos2d::Point pos2)
{
	//得到两点的坐标x,y坐标值
	float px1 = pos1.x;
	float py1 = pos1.y;
	float px2 = pos2.x;
	float py2 = pos2.y;

	//求出两边长度
	float x = px2 - px1;
	float y = py1 - py2;

	//开方   与  几次方 公式
	float xie = sqrt(pow(x, 2) + pow(y, 2));
	float cos = x / xie;

	//反余弦定理，知道两边长求角度：cos = 邻边/斜边
	float rad = acos(cos);

	//当触屏Y坐标 <摇杆的Y坐标时，取反值
	if (py1 > py2)
	{
		rad = -rad;
	}

	return rad;

}

float  HRocker::is_getRad()
{
	return rad;
}

//-----------------------------------------------得到与角度对应的半径为r的圆上一坐标点-------------------------------------------------------------------------
Point HRocker::getAnglePosition(float r)
{
	return Point(r*cos(rad), r*sin(rad));
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------
void HRocker::update(float dt)
{
	rockerBGPosition = spRockerBG->getPosition();
}

void HRocker::startlistener()
{
	listener1->setEnabled(true);
	listener2->setEnabled(true);
}

void HRocker::stoplistener()
{
	listener1->setEnabled(false);
	listener2->setEnabled(false);
}

bool HRocker::is_move()// 是否移动
{
	return this->moveed;
}