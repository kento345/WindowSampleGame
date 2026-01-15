#include "BulletManager.h"



//void  BulletManager::createConstant(constant_buffer& bulletConst, device& deviceInstance, descriptor_heap& constantBufferDescriptorInstance_, bullet& bulletInst,int count) {
//	if (!bulletConst.create(deviceInstance, constantBufferDescriptorInstance_, sizeof(bullet::ConstBufferData), count)) {
//		assert(false && "バレット用コンスタントバッファの作成に失敗しました");
//		return ;
//	}
//}


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

void createBullet1(bullet& bulletInstance, constant_buffer& bulletConstant, bullet_Polygon& bulletPolygonInstance, command_list& comandlistInstance, device& deviceInstance, descriptor_heap& constantBufferDescriptorInstance_, int count)noexcept {
	if (!bulletConstant.create(deviceInstance, constantBufferDescriptorInstance_, sizeof(bullet::ConstBufferData), count)) {
		assert(false && "バレット用コンスタントバッファの作成に失敗しました");
		return;
	}
	
	bullet_Polygon::ConstBufferData bulletData{
		DirectX::XMMatrixTranspose(bulletInstance.world()),
		bulletInstance.color()
	};
	UINT8* pBulletData{};
	bulletConstant.constanceBuffer()->Map(0, nullptr, reinterpret_cast<void**>(&pBulletData));
	memcpy_s(pBulletData, sizeof(bulletData), &bulletData, sizeof(bulletData));
	bulletConstant.constanceBuffer()->Unmap(0, nullptr);
	comandlistInstance.get()->SetGraphicsRootDescriptorTable(1, bulletConstant.getGpuDescriptorHandle());

	bulletPolygonInstance.draw(comandlistInstance);

	bulletInstance.update();
}



//void BulletManager::resetBullet() noexcept {
//    
//}