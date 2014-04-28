/*
 * ListUtils.h
 *
 *  Created on: 27/04/2014
 *      Author: fernandobt8
 */

#ifndef LISTUTILS_H_
#define LISTUTILS_H_
#include <list>

using namespace std;

class ListUtils{
public:
	template<typename ListType>
	static void destroyList(list<ListType*> *lista) {
		ListType* c = lista->front();
		while (!lista->empty()) {
			delete c;
			lista->pop_front();
			c = lista->front();
		}
		delete lista;
	}

	template<typename ListType, typename Condition>
	static void destroyListByCondition(list<ListType*> *lista, Condition condition) {
		ListType* c = lista->front();
		while (!lista->empty()) {
			if(condition(c)){
				delete c;
			}
			lista->pop_front();
			c = lista->front();
		}
		delete lista;
	}

	template<typename ListType>
	static int getIndexObject(list<ListType*> *lista, ListType* object) {
		_List_iterator<ListType*> it = lista->begin();
		int count = 0;
		for (; it != lista->end(); it++, count++) {
			if (object == (*it)) {
				return count;
			}
		}
		return -1;
	}

	template<typename ListType>
	static _List_iterator<ListType*> getIteratorInObject(list<ListType*> *lista, ListType* object) {
		_List_iterator<ListType*> it = lista->begin();
		for (; it != lista->end(); it++){
			if (object == (*it)) {
				return it;
			}
		}
		throw "object not found";
	}

	template<typename ListType>
	static _List_iterator<ListType*> incrementIteratorCircular(list<ListType* >* lista, _List_iterator<ListType*> iterator){
		iterator++;
		if(iterator == lista->end()){
			return lista->begin();
		}
		return iterator;
	}

	template<typename SortCondition, typename EqualCondition, typename ListType>
	static list<ListType* >* montListByConditionAndOrder(list<ListType* >* origem, ListType* equalAThis, EqualCondition equalCondition, SortCondition sortList){
		list<ListType* >* destino = new list<ListType*>();
		_List_iterator<ListType*> it = origem->begin();
		for(; it != origem->end(); it++){
			if(equalCondition(equalAThis, *it)){
				destino->push_back(*it);
			}
		}
		destino->sort(sortList);
		return destino;
	}

	template<typename ListType>
	static void splice(list<ListType* >* destino, list<ListType* >* origem, ListType* afterPosition){
		_List_iterator<ListType*> pos = destino->begin();
		for(; pos != destino->end(); pos++){
			if(afterPosition == *pos){
				break;
			}
		}
		pos++;
		_List_iterator<ListType*> it = origem->begin();
		for(; it != origem->end(); it++){
			destino->insert(pos, *it);
		}
	}
};
#endif /* LISTUTILS_H_ */
