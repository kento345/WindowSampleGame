#include "BulletManager.h"

//ConstantBuffrの配列の4にしか作られていない(複製されてない)
void BulletManager::createConstant(constant_buffer & bulletConst, device& deviceInstance, descriptor_heap& constantBufferDescriptorInstance_,int i) noexcept {
	if (!bulletConst.create(deviceInstance, constantBufferDescriptorInstance_, sizeof(bullet::ConstBufferData), i)) {
		assert(false && "バレット用コンスタントバッファの作成に失敗しました");
		return;
	}
}

void BulletManager::createBullet(bullet* bulletInstance, constant_buffer* bulletConstantInstant,command_list& commandlistInstance,bullet_Polygon& bulletPolygonInstance, int i) noexcept {

	bullet_Polygon::ConstBufferData bulletData{
		DirectX::XMMatrixTranspose(bulletInstance[i].world()),
		bulletInstance[i].color()
	};
	UINT8* pBulletData{};
	bulletConstantInstant[i].constanceBuffer()->Map(0, nullptr, reinterpret_cast<void**>(&pBulletData));
	memcpy_s(pBulletData, sizeof(bulletData), &bulletData, sizeof(bulletData));
	bulletConstantInstant[i].constanceBuffer()->Unmap(0, nullptr);
	commandlistInstance.get()->SetGraphicsRootDescriptorTable(1, bulletConstantInstant[i].getGpuDescriptorHandle());

	bulletPolygonInstance.draw(commandlistInstance);

	bulletInstance[i].update();
}

//void BulletManager::DrawBullet(bullet& bulletInstance,constant_buffer* bulletConstantInstant,int i) noexcept {
//	bullet_Polygon::ConstBufferData bulletData{
//						   DirectX::XMMatrixTranspose(bulletInstance.world()),
//						   bulletInstance.color()
//	};
//	UINT8* pBulletData{};
//	bulletConstantInstant[i].constanceBuffer()->Map(0, nullptr, reinterpret_cast<void**>(&pBulletData));
//	memcpy_s(pBulletData, sizeof(bulletData), &bulletData, sizeof(bulletData));
//	bulletConstantInstant[i].constanceBuffer()->Unmap(0, nullptr);
//}


//void BulletManager::resetBullet() noexcept {
//    
//}