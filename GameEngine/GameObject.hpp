#pragma once
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <iostream>

class GameObject
{
private:
	sf::Texture texture;
	sf::Sprite sprite;

public:
	GameObject();
	void SetTexture(std::string texturePath, sf::IntRect rect);
	sf::Sprite& GetSprite();
	void Render(sf::RenderWindow& renderWindow);
};