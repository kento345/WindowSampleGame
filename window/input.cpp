#include "input.h"


bool input::getKey(uint16_t sKey)const noexcept {
	return (keyState_[sKey] & 0x80) != 0;
}

bool input::getTrigger(uint16_t skey)const noexcept {
	return ((keyState_[skey] & 0x80) && !(prevKeyState_[skey] & 0x80));
}

void input::updateKeyState(void* pState)noexcept {
	memcpy_s(keyState_, sizeof(keyState_), pState, sizeof(keyState_));
}