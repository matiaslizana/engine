#include "GameObject.hpp"

GameObject::GameObject(std::string& name, GameObject* parent) : transform {}, localTransform{}, components{}, parent{ parent }, name{ name }
{
	if (parent != nullptr)
		parent->AddChildren(this);
}

GameObject::~GameObject()
{
	//TODO: This is breaking on deleting scripts
	//for (int i = 0; i < components.size(); i++)
	//	delete(components[i]);

	//for (int i = 0; i < scripts.size(); i++)
	//	delete(scripts[i]);
}

//Updates localTransform, transform and children transform
void GameObject::SetPosition(sf::Vector2f localPosition)
{
	localTransform.SetPosition(localPosition);
	SetTransform();

	for (int i = 0; i < children.size(); i++)
		children[i]->SetTransform();	

#if(_DEBUG)
	BoxCollider::DrawBoxCollider(collider, renderWindow);
#endif
}

//Updates transform position from parent
void GameObject::SetTransform()
{
	if (parent == nullptr)
		transform.SetPosition(localTransform.GetPosition());
	else
		transform.SetPosition(parent->GetPosition() + localTransform.GetPosition());
	
	for (int i = 0; i < components.size(); i++)
		components[i]->SetTransform(&transform);
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

void GameObject::AddChildren(GameObject* go)
{
	children.push_back(go);
}
