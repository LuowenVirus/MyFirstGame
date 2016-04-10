#ifndef ACTIONS_H
#define ACTIONS_H

#include "Execute.h"
class State;
class Player;

class SkillExecute : public State
{
public:
	virtual void execute(Player* m_player, ExecuteType type);

private:
	Player* m_players;
};

#endif