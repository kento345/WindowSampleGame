#pragma once

#include"../directx/device.h"
#include"../directx/command_list.h"
#include<DirectXMath.h>

class bullet_Polygon
{
public:
	struct ConstBufferData
	{
		DirectX::XMMATRIX world_{};
		DirectX::XMFLOAT4 color_{};
	};
public:
	bullet_Polygon() = default;
	~bullet_Polygon();

	bool create(const device& device)noexcept;
	void draw(const command_list& command_list)noexcept;

private:
	bool createVertexBuffer(const device& device)noexcept;
	bool createIndexBuffer(const device& devcie)noexcept;
private:
	ID3D12Resource* vertexBuffer_{};
	ID3D12Resource* indexBuffer_{};

	D3D12_VERTEX_BUFFER_VIEW vertexBufferView_ = {};
	D3D12_INDEX_BUFFER_VIEW indexBufferView_ = {};
};

