#include "Player.h"
#include<DirectXMath.h>
#include"../window/input.h"



void Player::initialize(DirectX::XMFLOAT3 pos, DirectX::XMFLOAT4 color)noexcept {
	world_ = DirectX::XMMatrixTranslation(pos.x, pos.y, pos.z);

	color_ = color;
}

void Player::update() noexcept
{
	constexpr float	 moveSpeed = 0.05f;

	DirectX::XMFLOAT3 pos{};
	if (input::instance().getKey('W')) {
		pos.z += moveSpeed;
	}
	if (input::instance().getKey('S')) {
		pos.z -= moveSpeed;
	}
	if (input::instance().getKey('A')) {
		pos.x -= moveSpeed;
	}
	if (input::instance().getKey('D')) {
		pos.x += moveSpeed;
	}

	if (input::instance().getTrigger('B'))
	{
		isShot = true;
		if (shotCount < 5) {
			shotCount++;
		}
	}
	/*if (!input::instance().getTrigger('B'))
	{
		isShot = false;
	}*/


	DirectX::XMVECTOR temp = DirectX::XMVectorSet(pos.x, pos.y, pos.z, 0.0f);
	world_.r[3] = DirectX::XMVectorAdd(world_.r[3], temp);
}
DirectX::XMMATRIX Player::world()const noexcept {
	return world_;
}

DirectX::XMFLOAT4 Player::color()const noexcept {
	return color_;
}


