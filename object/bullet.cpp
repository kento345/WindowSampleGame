#include "bullet.h"
#include<cmath>

void bullet::initialize(DirectX::XMFLOAT3 pos, DirectX::XMFLOAT4 color)noexcept {
	world_ = DirectX::XMMatrixTranslation(pos.x, pos.y, pos.z);
	color_ = color;
}

void bullet::update()noexcept {
	constexpr float	 moveSpeed = 0.05f;

	DirectX::XMFLOAT3 pos{};

	pos.z += moveSpeed;

	world_ = DirectX::XMMatrixTranslation(0.0f, 0.0f, pos.z);

	color_ = DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f);
}

DirectX::XMMATRIX bullet::world()const noexcept {
	return world_;
}

DirectX::XMFLOAT4 bullet::color()const noexcept {
	return color_;
}