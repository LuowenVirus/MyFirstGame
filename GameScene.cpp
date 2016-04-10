#include "GameScene.h"
#include "Player.h"
#include "Controllplayer.h"
#include "ExecuteTypes.h"
#include "MonsterManager.h"

USING_NS_CC;

Scene* GameScene::createScene()
{
	auto scene = Scene::create();

	auto layer = GameScene::create();

	scene->addChild(layer);

	return scene;
}

bool GameScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();

	auto exitgame = MenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		CC_CALLBACK_1(GameScene::exitGame,this)
		);
	exitgame->setPosition(Point(visibleSize.width-15,visibleSize.height-15));
	Menu* menu = Menu::create(exitgame,NULL);
	menu->setPosition(Point::ZERO);
	this->addChild(menu,3);


	//主角
	TMXTiledMap* map = TMXTiledMap::create("maps.tmx");
	this->addChild(map, -1);

	Director::getInstance()->setProjection(Director::Projection::_2D);

	addPlayer(map);

	this->scheduleUpdate();

	return true;
}

void GameScene::addPlayer(TMXTiledMap* map)
{
	Size visibleSize = Director::getInstance()->getVisibleSize();

//------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------


//------------------------------------------------------------------------------------

	auto sprite = Sprite::create("m_sprite.png");

	m_player = Player::create();

	m_player->bindSprite(sprite);

	m_player->setPosition(Point(200, 200));


	m_player->setTiledMap(map);

	//控制
    treecontroll = ControllerPlayer::create();
	treecontroll->bangdingplayer(m_player);
	this->addChild(treecontroll,1);
	m_player->setController(treecontroll);

	//添加怪物

	m_monster = MonsterManager::create();

	m_monster->bangPlayer(m_player);

	m_monster->setTiledMap(map);

	map->addChild(m_monster, 1);


	map->addChild(m_player, 1);

}


void GameScene::exitGame(Ref* psender)
{

	m_player->sdingditu();
//#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
//	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.", "Alert");
//	return;
//#endif
//
//	Director::getInstance()->end();
//
//#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
//	exit(0);
//#endif
}

void GameScene::update(float dt)
{
	int x = m_player->getPosition().x;

	//log("-----------------------------------------%d",x);
}