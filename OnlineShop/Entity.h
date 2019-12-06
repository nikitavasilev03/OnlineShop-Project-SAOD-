#pragma once

#include "stdafx.h"

class Entity
{
private:

	int id;
public:

	Entity();
	Entity(int id);

	int GetID();
	void SetID(int value);
	
	virtual string ToString() = 0;


	bool operator == (const Entity& obj) const {
		return id == obj.id;
	}
	bool operator != (const Entity& obj) const {
		return id != obj.id;
	}
};

