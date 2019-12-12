#include "ListData.h"

ListData::ListData() {
}

void ListData::Add(shared_ptr<Entity> item) {
	items.push_back(item);
}

void ListData::Remove(shared_ptr<Entity> item) {
	items.remove(item);
}

void ListData::Remove(int id) {
	for (auto item : items) {
		if (item->GetID() == id)
		{
			Remove(item);
			return;
		}
	}
	throw exception("Error! Object not found");
}

int ListData::GetCount() {
	return (int)items.size();
}

list<shared_ptr<Entity>>* ListData::GetItems() {
	return &items;
}

int ListData::NextID() {
	if (items.size() == 0)
		return 1;

	auto item = items.end();
	int new_id = (*(--item))->GetID() + 1;
	if (findById(new_id) == NULL)
		return new_id;

	for (int i = 0; i < INT_MAX; i++) {
		if (findById(i) == NULL) {
			return i;
		}
	}
	throw exception("LIST OVERFLOW");
}

shared_ptr<Entity> ListData::findById_shr(int id) {
	for (auto item : items) {
		if (item->GetID() == id)
		{
			return item;
		}
	}
	return NULL;
}

Entity* ListData::findById(int id) {
	for (auto item : items) {
		if (item->GetID() == id)
		{
			return item->GetEntity();
		}
	}
	return NULL;
}