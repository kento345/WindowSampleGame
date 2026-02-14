#include "bullet.h"
#include<cmath>

Vector Vector1,Vecotr2, Vector3;

void bullet::initialize(DirectX::XMFLOAT3 pos,DirectX::XMFLOAT4 color_)noexcept {
	startPos_ = { 0.0f,0.0f,0.0f };
	startPos_ = pos;

	color_ = color();
}

void bullet::update()noexcept {
	constexpr float	 moveSpeed = 0.05f;

	move_ += moveSpeed;
	DirectX::XMFLOAT3 pos{};

	//Vector1.SetVectorX(pos.x -  )

	world_ = DirectX::XMMatrixTranslation(startPos_.x,startPos_.y,startPos_.z + move_ * 1.5f);

	color_ = DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f);
}


DirectX::XMMATRIX bullet::world()const noexcept {
	return world_;
}

DirectX::XMFLOAT4 bullet::color()const noexcept {
	return color_;
}