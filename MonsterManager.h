#ifndef _MONSTERMANAGER_H
#define _MONSTERMANAGER_H

#include "cocos2d.h"


#include "editor-support/cocostudio/CCSGUIReader.h"
#include "ui/CocosGUI.h"
using namespace cocos2d::ui;
using namespace cocostudio;       //  UI��Ҫ����������


USING_NS_CC;

class Monster;
class Player;

class MonsterManager : public Node
{
public:
	MonsterManager();
	~MonsterManager();
	CREATE_FUNC(MonsterManager);

	virtual bool init();    //��ʼ������

	void bangPlayer(Player* player);   //  ��һ������  �����ײ

	virtual void update(float dt);     //�������ù����״̬��·��

	virtual void lookplayer(float dt); //׷������

	void setTiledMap(TMXTiledMap* map); //�󶨵�ͼ

private:

	Player* m_player;      //   �趨һ������   �����ײ

	float xspeed = 0;

	float yspeed = 0;

	void createMonsters();    //��������
private:
	Vector<Monster*>m_monsterArr;     // ������������   

	TMXTiledMap* m_map;

	TMXLayer* meta;

	Monster*  m_monster;
};

#endif