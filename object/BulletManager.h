#pragma once

#include"bullet.h"
#include"../directx/constant_buffer.h"
#include"../draw_resource/bullet_Polygon.h"
#include"../directx/command_list.h"

class BulletManager
{
public:
	BulletManager() = default;
	~BulletManager() = default;

	void createBullet(bullet&  bulletInstance,constant_buffer& bulletConstant,bullet_Polygon& bulletPolygonInstance,command_list& comandlistInstance)noexcept;

	void resetBullet() noexcept;
};

