#include "BulletManager.h"


void BulletManager::createConstant(constant_buffer & bulletConst, device& deviceInstance, descriptor_heap& constantBufferDescriptorInstance_, int count) noexcept {
	if (!bulletConst.create(deviceInstance, constantBufferDescriptorInstance_, sizeof(bullet::ConstBufferData), count)) {
		assert(false && "バレット用コンスタントバッファの作成に失敗しました");
		return;
	}
}

void BulletManager::createBullet(bullet& bulletInstance, constant_buffer& bulletConstantInstant, bullet_Polygon& bulletPolygonInstance, command_list& commandlistInstance) noexcept {

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



//void BulletManager::resetBullet() noexcept {
//    
//}