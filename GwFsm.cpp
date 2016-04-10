#include "GwFsm.h"
#include "Monster.h"
#include "Gwexecute.h"

GwFsm::~GwFsm()
{
	NotificationCenter::getInstance()->removeAllObservers(this);
}

GwFsm* GwFsm::createEventFsm(Monster* m_monster)
{
	GwFsm* fsm = new GwFsm();

	if (fsm && fsm->init(m_monster))
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

bool GwFsm::init(Monster* m_monster)
{
	momsterecut = new GWSkillExecute();

	this->m_monster = m_monster;

	NotificationCenter::getInstance()->addObserver(this, callfuncO_selector(GwFsm::standFunc), StringUtils::toString(gwstandType), NULL);

	NotificationCenter::getInstance()->addObserver(this, callfuncO_selector(GwFsm::runFunc), StringUtils::toString(gwrunType), NULL);

	NotificationCenter::getInstance()->addObserver(this, callfuncO_selector(GwFsm::attackFunc), StringUtils::toString(gwattackType), NULL);

	NotificationCenter::getInstance()->addObserver(this, callfuncO_selector(GwFsm::skillFunc), StringUtils::toString(gwskillType), NULL);

	NotificationCenter::getInstance()->addObserver(this, callfuncO_selector(GwFsm::hurtFunc), StringUtils::toString(gwhurtType), NULL);

	NotificationCenter::getInstance()->addObserver(this, callfuncO_selector(GwFsm::winFunc), StringUtils::toString(gwwinType), NULL);

	NotificationCenter::getInstance()->addObserver(this, callfuncO_selector(GwFsm::deadFunc), StringUtils::toString(gwdeadType), NULL);


	return true;
}


void GwFsm::standFunc(Ref* psender)
{
	momsterecut->execute(m_monster,gwstandType);
}

void GwFsm::runFunc(Ref* psender)
{
	momsterecut->execute(m_monster, gwrunType);
}

void GwFsm::attackFunc(Ref* psender)
{
	momsterecut->execute(m_monster, gwattackType);
}

void GwFsm::skillFunc(Ref* psender)
{
	momsterecut->execute(m_monster, gwskillType);
}

void GwFsm::hurtFunc(Ref* psender)
{
	momsterecut->execute(m_monster, gwhurtType);
}

void GwFsm::winFunc(Ref* psender)
{
	momsterecut->execute(m_monster, gwwinType);
}

void GwFsm::deadFunc(Ref* psender)
{
	momsterecut->execute(m_monster, gwdeadType);
}