#include "GameObject.h"

GameObject::GameObject(const std::string& name, std::shared_ptr<GameObject> parent) :
	components{}, children{}, localTransform {}, name{ name }, transform{}
{
	this->parent = parent;
	if (parent != nullptr)
		parent->AddChildren(std::make_shared<GameObject>(*this));
}

//Updates localTransform, transform and children transform
void GameObject::SetPosition(sf::Vector2f localPosition)
{
	localTransform.SetPosition(localPosition);
	SetTransform();

	for (const auto& child : children)
		child->SetTransform();	
}

//Updates transform position from parent
void GameObject::SetTransform()
{
	if (parent == nullptr)
		transform.SetPosition(localTransform.GetPosition());
	else
		transform.SetPosition(parent->GetPosition() + localTransform.GetPosition());
	
	for (const auto& component : components)
		component->SetTransform(&transform);
}

sf::Vector2f GameObject::GetPosition()
{
	return transform.GetPosition();
}

void GameObject::Update()
{

}

void GameObject::AddComponent(std::shared_ptr<Component> c)
{
	c->SetTransform(&transform);
	components.push_back(c);
}

void GameObject::AddChildren(std::shared_ptr<GameObject> go)
{
	children.push_back(go);
}
