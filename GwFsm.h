#ifndef GWFSM_H
#define GWFSM_H

#include "cocos2d.h"
USING_NS_CC;

class GWSkillExecute;
class Monster;

class GwFsm : public Node
{
public:
	~GwFsm();

	static GwFsm* createEventFsm(Monster* m_monster);

	bool init(Monster* m_monster);

private:
	void standFunc(Ref* psender);

	void runFunc(Ref* psender);

	void attackFunc(Ref* psender);

	void skillFunc(Ref* psender);

	void hurtFunc(Ref* psender);

	void winFunc(Ref* psender);

	void deadFunc(Ref* psender);

	Monster* m_monster;

	GWSkillExecute* momsterecut;
};

#endif