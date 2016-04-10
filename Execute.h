#ifndef EXECUTE
#define EXECUTE

#include "ExecuteTypes.h"
class Player;
class State
{
public:
	virtual  void execute(Player* m_player, ExecuteType type) = 0;
};

#endif