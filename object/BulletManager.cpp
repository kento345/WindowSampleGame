#include "BulletManager.h"

//ConstantBuffrの配列の4にしか作られていない(複製されてない)
void BulletManager::createConstant(constant_buffer & bulletConst, device& deviceInstance, descriptor_heap& constantBufferDescriptorInstance_) noexcept {
	if (!bulletConst.create(deviceInstance, constantBufferDescriptorInstance_, sizeof(bullet::ConstBufferData), 3)) {
		assert(false && "バレット用コンスタントバッファの作成に失敗しました");
		return;
	}
}

void BulletManager::createBullet(bullet& bulletInstance, constant_buffer* bulletConstantInstant, bullet_Polygon& bulletPolygonInstance, command_list& commandlistInstance,int i) noexcept {

	bullet_Polygon::ConstBufferData bulletData{
		DirectX::XMMatrixTranspose(bulletInstance.world()),
		bulletInstance.color()
	};
	UINT8* pBulletData{};
	bulletConstantInstant[3].constanceBuffer()->Map(0, nullptr, reinterpret_cast<void**>(&pBulletData));
	memcpy_s(pBulletData, sizeof(bulletData), &bulletData, sizeof(bulletData));
	bulletConstantInstant[3].constanceBuffer()->Unmap(0, nullptr);
	commandlistInstance.get()->SetGraphicsRootDescriptorTable(1, bulletConstantInstant[3].getGpuDescriptorHandle());

	bulletPolygonInstance.draw(commandlistInstance);

	bulletInstance.update();
}



//void BulletManager::resetBullet() noexcept {
//    
//}