#ifndef HROCKER_H
#define HROCKER_H

#include <iostream>
#include "cocos2d.h"
using namespace cocos2d;

//ö���ͣ����ڱ�ʶҡ����ҡ�˵ı���
typedef enum{

	tag_rocker,
	tag_rockerBG,

}tagForHRocker;

class HRocker : public Layer
{
public:
	//����ҡ�ˣ�ҡ��ͼƬ��ҡ�˱���ͼƬ����ʼ����
	static HRocker* createHRocker(const char* rockerImageName, const char* rockerBGImageName, Point position);

	void startlistener();     //ע�����

	void stoplistener();      //ע������

	//���ؽǶ�
	float is_getRad();

	bool is_move();// �Ƿ��ƶ�

	//�õ��뾶Ϊr��Բ���˶���һ���Ƕ�Ӧ��Ӧ��x,y����
	Point getAnglePosition(float r);
private:

	EventListenerTouchOneByOne* listener1; //ҡ�˼���

	EventListenerTouchOneByOne* listener2; //ҡ�˱���

	Sprite* spRocker;

	void rockerInit(const char* rockerImageName, const char* rockerBGImageName, Point position);

	//�Ƿ�ɲ���ҡ��
	bool isCanMove = false;

	//��Ⱦһ�ζ���
	bool isaction = true;

	//�õ�ҡ�����û�������ĽǶ�
	float getRad(Point pos1, Point pos2);


	//ҡ�˱���������
	Point rockerBGPosition;

	//ҡ�˱����İ뾶
	float rockerBGR;

	virtual void update(float dt);

	Sprite* spRockerBG;

	float rad = 0; // �Ƕ�


	bool moveed = false;

	CREATE_FUNC(HRocker);
};

#endif