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

	void createConstant(constant_buffer& bulletConst, device& deviceInstance, descriptor_heap& constantBufferDescriptorInstance_,int i) noexcept;

	void createBullet(bullet& bulletInstance, constant_buffer* bulletConstantInstant, command_list& commandlistInstance, bullet_Polygon& bulletPolygonInstance, int i)noexcept;

};

