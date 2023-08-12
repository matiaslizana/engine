#pragma once

#include "Component.h"
#include "IInputReceiver.h"
#include "SpriteRenderer.h"
#include "Weapon.h"

class Player : public Component, public IInputReceiver
{
private:
	float velocity;
	bool lastDirectionLeft;
	float lastShotTime;

	std::shared_ptr<SpriteRenderer> spriteRenderer;
	std::shared_ptr<Weapon> weapon;

public:
	Player(std::shared_ptr<GameObject> go);
	virtual ~Player() = default;

	void Update() override;

	void OnEventFired(const sf::Keyboard::Key& code) override;
};