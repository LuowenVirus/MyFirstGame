#ifndef GWEXECUTE_H
#define GWEXECUTE_H
#include "ExecuteTypes.h"
class Monster;

class GWSkillExecute
{
public:
	void execute(Monster* m_monster, ExecuteType type);

private:
	Monster* m_monsters;
};

#endif