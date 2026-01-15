#pragma once

#include"bullet.h"
#include"../directx/constant_buffer.h"
#include"../draw_resource/bullet_Polygon.h"
#include"../directx/command_list.h"

#include"../object/Player.h"
#include"../directx/device.h"


class BulletManager
{
public:
	BulletManager() = default;
	~BulletManager() = default;

	//void createConstant(constant_buffer& bulletConst, device& deviceInstance, descriptor_heap& constantBufferDescriptorInstance_, bullet& bulletInst, int count) noexcept;

	void createBullet(bullet&  bulletInstance,constant_buffer& bulletConstant,bullet_Polygon& bulletPolygonInstance,command_list& comandlistInstance)noexcept;

	void createBullet1(bullet& bulletInstance, constant_buffer& bulletConstant, bullet_Polygon& bulletPolygonInstance, command_list& comandlistInstance, device& deviceInstance, descriptor_heap& constantBufferDescriptorInstance_, int count)noexcept;


	void resetBullet() noexcept;
};

