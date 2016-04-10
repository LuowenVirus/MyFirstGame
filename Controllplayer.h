#ifndef CONTROLLPLAYER_H
#define CONTROLLPLAYER_H

#define PlayerAction NotificationCenter::getInstance()->postNotification

#include "cocos2d.h"
#include "editor-support\cocostudio\CCSGUIReader.h"
#include "ui\CocosGUI.h"
using namespace cocos2d::ui;
using namespace cocostudio;

#include "Controller.h"
USING_NS_CC;

//----------------------------------主角技能冷却--------------------------------------------------
enum MyEnum
{
	skillcd,

	attackcd,

	bigskillcd,

	shangxiancd
};

class Player;
class HRocker;

class ControllerPlayer : public Controller
{
public:
	CREATE_FUNC(ControllerPlayer);

	virtual bool init();

	virtual void update(float dt);

//---------------------------------上下左右停控制---------------------------------------------------

	void stopFunc(Ref* psender);

	void is_startlistener(Ref* psender);  //  开启摇杆， 继续移动

	void is_stoplistener(Ref* psender);   //  关闭摇杆， 动作须要停留

	virtual void attackEvent(Ref*, TouchEventType type);

	virtual void skillEvent(Ref*, TouchEventType type);

	virtual void bigskillEvent(Ref*, TouchEventType type);

	virtual void sxEvent(Ref*, TouchEventType type);

//--------------------------------------技能冷却时间，技能冷却图片，技能按钮，图片缩放，技能选择----------------------------------------------
	void cdImg(float time, std::string name1, std::string name2, Button* but, float scale, MyEnum type);

//---------------------------------------关闭全部按钮---------------------------------------------
	void ccdbut();

//----------------------------------------开启其他按钮--------------------------------------------
	void oscdbut(float dt);

	void oacdbut(float dt);

	void obscdbut(float dt);

	void osxcdbut(float dt);

	//-------------------------------------主角动作执行完恢复函数-----------------------------------------------
	void Cdskill(float dt);

	//绑定主角

	void bangdingplayer(Player* m_player);

private:
	//摇杆
	HRocker*  rocker;

	Point Speed = Point(0,0); // 开始 x y 的


	Player* m_player;


	Button* attack;

	Button*	skill;

	Button* bigskill;

	Button* shangxian;

	bool skillisCD = false;

	bool attackisCD = false;

	bool bigisCD = false;

	bool sxisCD = false;


};

#endif