#ifndef GAMESCENE_H
#define GAMESCENE_H

#include "cocos2d.h"
#include "editor-support\cocostudio\CCSGUIReader.h"
#include "ui\CocosGUI.h"
using namespace cocos2d::ui;
using namespace cocostudio;

USING_NS_CC;

class Player;
class MonsterManager;
class ControllerPlayer;

class GameScene : public Layer
{
public:
	static Scene* createScene();

	virtual bool init();


//---------------------------------�ڵ�ͼ���������---------------------------------------------------
	virtual void addPlayer(TMXTiledMap* map);

	virtual void exitGame(Ref* psender);

//----------------------------------��Ϸ�е�UODATE--------------------------------------------------
	virtual void update(float dt);

	CREATE_FUNC(GameScene);
private:

	Player* m_player;

	ControllerPlayer* treecontroll;

	MonsterManager* m_monster;

};





#endif
