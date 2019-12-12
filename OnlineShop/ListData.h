#pragma once

#include "Entity.h"

class ListData
{
private:
	list<shared_ptr<Entity>> items;
protected:

public:
	ListData();
	virtual void Add(shared_ptr<Entity> item);
	void Remove(shared_ptr<Entity> item);
	void Remove(int id);
	virtual void EditItem(Entity* new_item) = 0;
	int GetCount();
	list<shared_ptr<Entity>>* GetItems();
	int NextID();
	shared_ptr<Entity> findById_shr(int id);
	Entity* findById(int id);
};

