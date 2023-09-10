#pragma once

class Entity
{
public:
	Entity();
	~Entity();

	virtual void Update();
	virtual void Render();

	virtual void Destroy();

private:
	int ID;
	static inline int IDCount;
};