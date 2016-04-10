#include "EventFSM.h"
#include "Execute.h"
#include "Player.h"
#include "Actions.h"

EventFsm::~EventFsm()
{
	NotificationCenter::getInstance()->removeAllObservers(this);
}

EventFsm* EventFsm::createEventFsm(Player* m_player)
{
	EventFsm* fsm = new EventFsm();

	if (fsm && fsm->init(m_player))
	{
		fsm->autorelease();
	}
	else
	{
		CC_SAFE_DELETE(fsm);
		fsm = NULL;
	}

	return fsm;
}

bool EventFsm::init(Player* m_player)
{
	SkillExecute* State = new SkillExecute();
	this->mstate = State;

	this->m_player = m_player;

	NotificationCenter::getInstance()->addObserver(this, callfuncO_selector(EventFsm::standFunc), StringUtils::toString(standType), NULL);

	NotificationCenter::getInstance()->addObserver(this, callfuncO_selector(EventFsm::runFunc), StringUtils::toString(runType), NULL);

	NotificationCenter::getInstance()->addObserver(this, callfuncO_selector(EventFsm::attackFunc), StringUtils::toString(attackType), NULL);

	NotificationCenter::getInstance()->addObserver(this, callfuncO_selector(EventFsm::skillFunc), StringUtils::toString(skillType), NULL);

	NotificationCenter::getInstance()->addObserver(this, callfuncO_selector(EventFsm::hurtFunc), StringUtils::toString(hurtType), NULL);

	NotificationCenter::getInstance()->addObserver(this, callfuncO_selector(EventFsm::winFunc), StringUtils::toString(winType), NULL);

	NotificationCenter::getInstance()->addObserver(this, callfuncO_selector(EventFsm::deadFunc), StringUtils::toString(deadType), NULL);

	NotificationCenter::getInstance()->addObserver(this, callfuncO_selector(EventFsm::rightFunc), StringUtils::toString(rightType), NULL);

	NotificationCenter::getInstance()->addObserver(this, callfuncO_selector(EventFsm::leftFunc), StringUtils::toString(leftType), NULL);


	return true;
}


void EventFsm::standFunc(Ref* psender)
{
	mstate->execute(m_player, standType);
}

void EventFsm::runFunc(Ref* psender)
{
	mstate->execute(m_player, runType);
}

void EventFsm::attackFunc(Ref* psender)
{
	mstate->execute(m_player, attackType);
}

void EventFsm::skillFunc(Ref* psender)
{
	mstate->execute(m_player, skillType);
}

void EventFsm::hurtFunc(Ref* psender)
{
	mstate->execute(m_player, hurtType);
}

void EventFsm::winFunc(Ref* psender)
{
	mstate->execute(m_player, winType);
}

void EventFsm::deadFunc(Ref* psender)
{
	mstate->execute(m_player, deadType);
}

void  EventFsm::rightFunc(Ref* psender)
{
	mstate->execute(m_player, rightType);
}

void  EventFsm::leftFunc(Ref* psender)
{
	mstate->execute(m_player, leftType);
}