#pragma once

#include<Windows.h>
#include<cstdint>

class input final
{
public:
	static input& instance() noexcept {
		static input instance;
		return instance;
	}

	bool getKey(uint16_t sKey) const noexcept;

	bool getTrigger(uint16_t sky) const noexcept;

	void updateKeyState(void* pState) noexcept;

	void updateprevKeyState(void* pState) noexcept;
private:

	input() = default;
	~input() = default;

private:
	byte keyState_[256];
	byte prevKeyState_[256]{};
};

