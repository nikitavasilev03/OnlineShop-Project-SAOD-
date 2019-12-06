#include "Entity.h"


Entity::Entity() {
	this->id = 0;
}

Entity::Entity(int id) {
	this->id = id;
}

int Entity::GetID() {
	return id;
}

void Entity::SetID(int value) {
	id = value;
}