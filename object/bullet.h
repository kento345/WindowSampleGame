#pragma once
#include<DirectXMath.h>
#include"../object/Player.h"

class bullet final	
{
public:
	struct  ConstBufferData
	{
		DirectX::XMMATRIX world_{};
		DirectX::XMFLOAT4 color_{};
	};
public:
	bullet() = default;
	~bullet() = default;

	void initialize(DirectX::XMFLOAT3 pos, DirectX::XMFLOAT4 color_)noexcept;

	void update()noexcept;

	DirectX::XMMATRIX world()const noexcept;

	DirectX::XMFLOAT4 color()const noexcept;

private:
	DirectX::XMMATRIX world_ = DirectX::XMMatrixIdentity();
	DirectX::XMFLOAT4 color_ = DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f);

	DirectX::XMFLOAT3 startPos_{};
	float move_ = 0.0f;
};

