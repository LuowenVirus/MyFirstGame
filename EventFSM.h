#ifndef EVENTFSM_H
#define EVENTFSM_H

#include "cocos2d.h"
USING_NS_CC;

class State;
class Player;
class EventFsm : public Node
{
public:
	~EventFsm();

	static EventFsm* createEventFsm(Player* m_player);

	bool init(Player* m_player);

private:
	void standFunc(Ref* psender);

	void runFunc(Ref* psender);

	void attackFunc(Ref* psender);

	void skillFunc(Ref* psender);

	void hurtFunc(Ref* psender);

	void winFunc(Ref* psender);

	void deadFunc(Ref* psender);

	void rightFunc(Ref* psender);

	void leftFunc(Ref* psender);

	State* mstate;

	Player* m_player;
};

#endif