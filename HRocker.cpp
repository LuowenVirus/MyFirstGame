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
	//���ҡ�˱���ͼ
    spRockerBG = Sprite::create(rockerBGImageName);
	spRockerBG->setOpacity(150);
	spRockerBG->setPosition(position);
	addChild(spRockerBG,0);


	//���ҡ���Ϸ��Ǹ����ƶ���ͼ
    spRocker = Sprite::create(rockerImageName);
	spRocker->setOpacity(150);
	spRocker->setPosition(position);
	addChild(spRocker,1);

	//ҡ�˱���ͼ����
	rockerBGPosition = spRockerBG->getPosition();

	this->scheduleUpdate();//����ҡ�˷�Χ

	//ҡ�˱���ͼ�뾶
	rockerBGR = spRockerBG->getContentSize().width*0.5;
   
	//��Ӵ����¼�

	listener1 = EventListenerTouchOneByOne::create();

	listener1->onTouchBegan = [&](Touch* touch, Event* event)
	{
		Point point = touch->getLocation();
		
		auto target = static_cast<Sprite*>(event->getCurrentTarget());

		Point locationInNode = target->convertToNodeSpace(touch->getLocation());

		Size s = target->getContentSize();
		Rect rect = Rect(0, 0, s.width, s.height);//��ȡ����ľ��η�Χ

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

		//�ж�����Բ�ĵľ����Ƿ����ҡ�˱����İ뾶
		if (sqrt(pow(point.x - rockerBGPosition.x, 2) + pow(point.y - rockerBGPosition.y, 2)) >= rockerBGR)
		{
			//ȷ��СԲ�˶���Χ�ڱ���Բ��
			target->setPosition(ccpAdd(getAnglePosition(rockerBGR), ccp(rockerBGPosition.x, rockerBGPosition.y)));

		}
		else {
			//�����ڱ���Բ������津���˶�
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

//�õ�������ĽǶ�ֵ
float HRocker::getRad(cocos2d::Point pos1, cocos2d::Point pos2)
{
	//�õ����������x,y����ֵ
	float px1 = pos1.x;
	float py1 = pos1.y;
	float px2 = pos2.x;
	float py2 = pos2.y;

	//������߳���
	float x = px2 - px1;
	float y = py1 - py2;

	//����   ��  ���η� ��ʽ
	float xie = sqrt(pow(x, 2) + pow(y, 2));
	float cos = x / xie;

	//�����Ҷ���֪�����߳���Ƕȣ�cos = �ڱ�/б��
	float rad = acos(cos);

	//������Y���� <ҡ�˵�Y����ʱ��ȡ��ֵ
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

//-----------------------------------------------�õ���Ƕȶ�Ӧ�İ뾶Ϊr��Բ��һ�����-------------------------------------------------------------------------
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

bool HRocker::is_move()// �Ƿ��ƶ�
{
	return this->moveed;
}