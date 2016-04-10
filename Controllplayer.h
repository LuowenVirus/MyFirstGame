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

//----------------------------------���Ǽ�����ȴ--------------------------------------------------
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

//---------------------------------��������ͣ����---------------------------------------------------

	void stopFunc(Ref* psender);

	void is_startlistener(Ref* psender);  //  ����ҡ�ˣ� �����ƶ�

	void is_stoplistener(Ref* psender);   //  �ر�ҡ�ˣ� ������Ҫͣ��

	virtual void attackEvent(Ref*, TouchEventType type);

	virtual void skillEvent(Ref*, TouchEventType type);

	virtual void bigskillEvent(Ref*, TouchEventType type);

	virtual void sxEvent(Ref*, TouchEventType type);

//--------------------------------------������ȴʱ�䣬������ȴͼƬ�����ܰ�ť��ͼƬ���ţ�����ѡ��----------------------------------------------
	void cdImg(float time, std::string name1, std::string name2, Button* but, float scale, MyEnum type);

//---------------------------------------�ر�ȫ����ť---------------------------------------------
	void ccdbut();

//----------------------------------------����������ť--------------------------------------------
	void oscdbut(float dt);

	void oacdbut(float dt);

	void obscdbut(float dt);

	void osxcdbut(float dt);

	//-------------------------------------���Ƕ���ִ����ָ�����-----------------------------------------------
	void Cdskill(float dt);

	//������

	void bangdingplayer(Player* m_player);

private:
	//ҡ��
	HRocker*  rocker;

	Point Speed = Point(0,0); // ��ʼ x y ��


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