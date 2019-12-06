#include "ListData.h"

ListData::ListData() {
	current_id = 0;
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
			items.remove(item);
			break;
		}
	}
}

int ListData::GetCount() {
	return items.size();
}

list<shared_ptr<Entity>>* ListData::GetItems() {
	return &items;
}

int ListData::NextID() {
	current_id++;
	return current_id;
}