#include "BulletManager.h"



void BulletManager::createBullet(bullet& bulletInstance, constant_buffer& bulletConstantInstant, bullet_Polygon bulletPolygonInstance, command_list commandlistInstance) noexcept {
	//bullet bulletInstance{};
	//constant_buffer bulletConstantBufferInstance_{};
	//bullet_Polygon bulletPolygonInstance_{};
	//command_list commandListInstance_{};

	bullet_Polygon::ConstBufferData bulletData{
		DirectX::XMMatrixTranspose(bulletInstance.world()),
		bulletInstance.color()
	};
	UINT8* pBulletData{};
	bulletConstantInstant.constanceBuffer()->Map(0, nullptr, reinterpret_cast<void**>(&pBulletData));
	memcpy_s(pBulletData, sizeof(bulletData), &bulletData, sizeof(bulletData));
	bulletConstantInstant.constanceBuffer()->Unmap(0, nullptr);
	commandlistInstance.get()->SetGraphicsRootDescriptorTable(1, bulletConstantInstant.getGpuDescriptorHandle());

	bulletPolygonInstance.draw(commandlistInstance);

	bulletInstance.update();
}
