#include "Gwexecute.h"
#include "Monster.h"

void GWSkillExecute::execute(Monster* m_monster, ExecuteType type)
{
	this->m_monsters = m_monster;

	switch (type)
	{
	case gwskillType:
	{
					  m_monsters->gwskill();

					  break;
	}

	case gwrunType:
	{
					m_monsters->gwmove();
					break;
	}
	case gwattackType:
	{
					   m_monsters->gwattack();
					   break;
	}

	case gwdeadType:
	{
					 m_monsters->gwdead();
					 break;
	}
	case gwhurtType:
	{
					 m_monsters->gwhurt();
					 break;
	}

	case gwstandType:
	{
					  m_monsters->gwstand();
					  break;
	}

	case gwwinType:
	{
					m_monsters->gwwin();
					break;
	}
	}
}