#pragma once

class Player;

class EquipmentWeapon {

private:
	Player* m_pOwner;

protected:
	Player* GetOwner() const { return m_pOwner; }

public:

	EquipmentWeapon(Player* pOwner) : m_pOwner(pOwner){}
	virtual ~EquipmentWeapon() = default;

	virtual void Attack() = 0;
	virtual void Draw() = 0;
};
