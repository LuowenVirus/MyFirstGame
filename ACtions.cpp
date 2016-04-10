#include "Actions.h"
#include "Player.h"

void SkillExecute::execute(Player* m_player, ExecuteType type)
{
	this->m_players = m_player;

	switch (type)
	{
	case skillType:
	{
					  m_players->skill();

					  break;
	}

	case runType:
	{
					  m_players->run();
					  break;
	}
	case attackType:
	{
					   m_players->attack();
					   break;
	}

	case deadType:
	{
					 m_players->dead();
					 break;
	}
	case hurtType:
	{
					 m_players->hurt();
					 break;
	}

	case standType:
	{
					  m_players->stand();
					  break;
	}

	case winType:
	{
					m_players->win();
					break;
	}
	case rightType:
	{
					  m_players->changes();
					  break;
	}
	case leftType:
	{
					 m_players->change();
					 break;
	}
	}
}