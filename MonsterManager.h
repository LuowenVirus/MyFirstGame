#ifndef _MONSTERMANAGER_H
#define _MONSTERMANAGER_H

#include "cocos2d.h"


#include "editor-support/cocostudio/CCSGUIReader.h"
#include "ui/CocosGUI.h"
using namespace cocos2d::ui;
using namespace cocostudio;       //  UI需要。。。。。


USING_NS_CC;

class Monster;
class Player;

class MonsterManager : public Node
{
public:
	MonsterManager();
	~MonsterManager();
	CREATE_FUNC(MonsterManager);

	virtual bool init();    //初始化怪物

	void bangPlayer(Player* player);   //  绑定一个主角  检测碰撞

	virtual void update(float dt);     //检测和设置怪物的状态和路线

	virtual void lookplayer(float dt); //追踪主角

	void setTiledMap(TMXTiledMap* map); //绑定地图

private:

	Player* m_player;      //   设定一个主角   检测碰撞

	float xspeed = 0;

	float yspeed = 0;

	void createMonsters();    //创建怪物
private:
	Vector<Monster*>m_monsterArr;     // 将怪物放入队列   

	TMXTiledMap* m_map;

	TMXLayer* meta;

	Monster*  m_monster;
};

#endif