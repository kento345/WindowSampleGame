#include "Player.h"
#include<DirectXMath.h>
#include"../window/input.h"




void Player::initialize(DirectX::XMFLOAT3 pos, DirectX::XMFLOAT4 color)noexcept {
	position_ = pos;
	world_ = DirectX::XMMatrixTranslation(pos.x, pos.y, pos.z);

	color_ = color;
}

void Player::update() noexcept
{
	constexpr float	 moveSpeed = 0.05f;
	DirectX::XMFLOAT3 pos{};

	if (input::instance().getKey('W')) {
		position_.z += moveSpeed;
	}
	if (input::instance().getKey('S')) {
		position_.z -= moveSpeed;
	}
	if (input::instance().getKey('A')) {
		position_.x -= moveSpeed;
	}
	if (input::instance().getKey('D')) {
		position_.x += moveSpeed;
	}

	constexpr float deltaTime = 0.016f;
	
	if (input::instance().getTrigger('B'))
	{
		isShot = true;
		isS = true;
		timer = 1.0f;
		if (shotCount < 5) {
			shotCount++;
			if (shotCount == 5) {
				shotCount = 0;
			}
		}
	}
	else if (!input::instance().getTrigger('B')) {
		isS = false;
	}
	

	if (isShot && timer >= 0.0f)
	{
		timer -= deltaTime;
		if (timer <= 0.01f)
		{
			isShot = false;
			timer = 0.0f;
		}
	}
	world_ = DirectX::XMMatrixTranslation(
		position_.x,
		position_.y,
		position_.z
	);
	/*DirectX::XMVECTOR temp = DirectX::XMVectorSet(pos.x, pos.y, pos.z, 0.0f);
	world_.r[3] = DirectX::XMVectorAdd(world_.r[3], temp);*/
}

DirectX::XMMATRIX Player::world()const noexcept {
	return world_;
}

DirectX::XMFLOAT4 Player::color()const noexcept {
	return color_;
}
DirectX::XMFLOAT3 Player::position() const noexcept {
	return position_;
}


