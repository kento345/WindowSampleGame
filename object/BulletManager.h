#pragma once


class BulletManager
{
public:
	BulletManager() = default;
	~BulletManager() = default;
	void create() noexcept;
	
	/*void draw(ID3D12GraphicsCommandList* commandList, 
		ConstantBuffer<bullet::ConstBufferData>* constBuffBullet) noexcept;*/
};

