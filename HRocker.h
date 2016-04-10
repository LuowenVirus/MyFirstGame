#ifndef HROCKER_H
#define HROCKER_H

#include <iostream>
#include "cocos2d.h"
using namespace cocos2d;

//枚举型：用于标识摇杆与摇杆的背景
typedef enum{

	tag_rocker,
	tag_rockerBG,

}tagForHRocker;

class HRocker : public Layer
{
public:
	//创建摇杆，摇杆图片，摇杆背景图片，起始坐标
	static HRocker* createHRocker(const char* rockerImageName, const char* rockerBGImageName, Point position);

	void startlistener();     //注册监听

	void stoplistener();      //注销监听

	//返回角度
	float is_getRad();

	bool is_move();// 是否移动

	//得到半径为r的圆周运动上一个角度应对应的x,y坐标
	Point getAnglePosition(float r);
private:

	EventListenerTouchOneByOne* listener1; //摇杆监听

	EventListenerTouchOneByOne* listener2; //摇杆背景

	Sprite* spRocker;

	void rockerInit(const char* rockerImageName, const char* rockerBGImageName, Point position);

	//是否可操作摇杆
	bool isCanMove = false;

	//渲染一次动画
	bool isaction = true;

	//得到摇杆与用户触屏点的角度
	float getRad(Point pos1, Point pos2);


	//摇杆背景的坐标
	Point rockerBGPosition;

	//摇杆背景的半径
	float rockerBGR;

	virtual void update(float dt);

	Sprite* spRockerBG;

	float rad = 0; // 角度


	bool moveed = false;

	CREATE_FUNC(HRocker);
};

#endif