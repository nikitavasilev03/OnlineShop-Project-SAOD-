#pragma once

#include "Entity.h"

class ListData
{
private:
	list<shared_ptr<Entity>> items;
	int current_id;
public:
	ListData();
	virtual void Add(shared_ptr<Entity> item);
	void Remove(shared_ptr<Entity> item);
	void Remove(int id);
	int GetCount();
	list<shared_ptr<Entity>>* GetItems();
	int NextID();
};

