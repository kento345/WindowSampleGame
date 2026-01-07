#pragma once
#include<DirectXMath.h>

#define BULLET_NUM 100

class bullet final	
{
	bullet* bullets_[BULLET_NUM];


public:
	struct  ConstBufferData
	{
		DirectX::XMMATRIX world_{};
		DirectX::XMFLOAT4 color_{};
	};
public:
	bullet() = default;
	~bullet() = default;

	void initialize(DirectX::XMFLOAT3 pos, DirectX::XMFLOAT4 color)noexcept;

	void update()noexcept;

	DirectX::XMMATRIX world()const noexcept;

	DirectX::XMFLOAT4 color()const noexcept;

private:
	DirectX::XMMATRIX world_ = DirectX::XMMatrixIdentity();
	DirectX::XMFLOAT4 color_ = DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f);
};

