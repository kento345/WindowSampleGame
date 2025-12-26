#pragma once
#include<DirectXMath.h>





class Player final
{
public:
	struct ConstBufferData
	{
		DirectX::XMMATRIX world_{};
		DirectX::XMFLOAT4 color_{};
	};

public:
	Player() = default;
	
	~Player() = default;

	void initialize(DirectX::XMFLOAT3 pos, DirectX::XMFLOAT4 color) noexcept;

	void update() noexcept;

	bool isShot = false;

	DirectX::XMMATRIX world() const noexcept;
	DirectX::XMFLOAT4 color()const noexcept;

private:
	DirectX::XMMATRIX world_ = DirectX::XMMatrixIdentity();
	DirectX::XMFLOAT4 color_ = DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f);
	
	float move_{};
	
};