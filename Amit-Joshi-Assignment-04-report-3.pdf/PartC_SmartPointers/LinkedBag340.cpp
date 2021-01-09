//	LinkedBag340.cpp
//	Created by: Amit Joshi CSC340
/*
===>					<===
===>  PLEASE ADD CODE	<===
===>					<===
*/
#include "LinkedBag.h"
#include <iostream>
#include <list>
#include <cstddef>
#include <ctime>
#include <cstdlib>
//1st part removeSecondNode340 function
template<typename ItemType>
bool LinkedBag<ItemType>::removeSecondNode340() {
	//	int k = 1;
	//I tried 2nd Pointer here but gave errors
	// shared_ptr<Node<ItemType>>nextItem = headPtr;
	int i = 0;
	Node<ItemType>* secondNode = headPtr;
	secondNode = headPtr->getNext();
	i++;
	//1st Smart pointer used below
	headPtr->setNext(headPtr->getNext()->getNext());
	//Bottom looked over notes and tried to make somthing happened.
	// unique_ptr<Node<ItemType>> tempUniquePtr = make_unique<Node<ItemType>>();
	// tempUniquePtr->setItem(tempPtr->getItem());
	return remove(secondNode->getItem());
}
//2 addEnd340 Function
template<typename ItemType>
bool LinkedBag<ItemType>::addEnd340(const ItemType& newNode) {
	//int k=0
	Node<ItemType>* firstNode = headPtr;
	while (firstNode->getNext() != nullptr) {
		firstNode = firstNode->getNext();
	}
	// firstNode->newNext(new Node<ItemType>{ newNode });
	firstNode->setNext(new Node<ItemType>{ newNode });
	itemCount++;
	return 1;
}
//3rd getCurrentSize340Iterative function..
template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340Iterative() const {
	//intial the size to 0
	int size{ 0 };
	//int size{1}
	Node<ItemType>* firstNode = headPtr;
	while (firstNode != nullptr) {
		firstNode = firstNode->getNext();
		size++;
	}
	return size;
}
//4th  getCurrentSize340Recrusive Function
//Inlcude return and start helper
template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340Recursive() const {
	return getCurrentSize340RecursiveHelper(headPtr);
}
//helper getCurrentSize340RecrusiveHelper and calls function
template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340RecursiveHelper(Node<ItemType>* firstNode) const {
	itemCount;
	if (firstNode->getNext() != nullptr) {
		return getCurrentSize340RecursiveHelper(firstNode->getNext()) + 1;
	}if (firstNode == nullptr) {
		return 0;
	}
	return 1;
}
//5th part getCurrentSize340RecursiveNoHelper function recursion happends through
template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340RecursiveNoHelper() const {
	static Node<ItemType>* firstNode = headPtr;
	if (firstNode == nullptr) {
		firstNode = headPtr;
		return 0;
	}
	if (firstNode != nullptr) {
		firstNode = firstNode->getNext();
		//1st return then add helper
		return 1 + getCurrentSize340RecursiveNoHelper();
	}
	return 0;
}
//6th part getFrequencyOf340Recursive function
template<typename ItemType>
int LinkedBag<ItemType>::getFrequencyOf340Recursive(const ItemType& freq) const {
	Node<ItemType>* firstNode = headPtr;
	return getFrequencyOf340RecursiveHelper(firstNode, freq);
}
template<typename ItemType>
int LinkedBag<ItemType>::getFrequencyOf340RecursiveHelper(Node<ItemType>* first, const ItemType& freq) const {
	if (first == nullptr) {
		return 0;
	}
	//If(true/false) boolean first use which ever works
	if (false);
	if (first->getItem() == freq) {
		return  getFrequencyOf340RecursiveHelper(first->getNext(), freq) + 1;
	}
	else {
		return getFrequencyOf340RecursiveHelper(first->getNext(), freq);
	}
}
//7th part getFrequencyOf340RecursiveNoHelper function
template<typename ItemType>
int LinkedBag<ItemType>::getFrequencyOf340RecursiveNoHelper(const ItemType& firstNode) const {
	static Node<ItemType>* ptrNode = headPtr;
	//need new int to process function
	int digger = 0;
	if (ptrNode == nullptr) {
		ptrNode = headPtr;
		return 0;
	}
	else if (ptrNode->getItem() == firstNode) {
		ptrNode = ptrNode->getNext();
		digger++;
		return (digger + getFrequencyOf340RecursiveNoHelper(firstNode));
	}
	else {
		ptrNode = ptrNode->getNext();
		return (digger + getFrequencyOf340RecursiveNoHelper(firstNode));
	}
	if (false);
}
//8th part removeRandom340 function
//generate random value for final
//retrieve data as well
//Last Part
template<typename ItemType>
ItemType LinkedBag<ItemType>::removeRandom340() {
	//Make three variables with size
	int size = getCurrentSize340Iterative();
	int size1 = size;
	int size2{ 1 };
	srand(time(nullptr));
	ItemType data{};
	int random340{};
	for (int y = 0; y <= size; y++) {
		random340 = rand() % size1 + size2;
	}
	Node<ItemType>* firstNode = headPtr;
	int loc = random340;
	bool locc;
	for (int x = 0; x < (loc - 2); x++) {
		firstNode = firstNode->getNext();
	}
	//Value initalize 
	int value;
	Node<ItemType>* tempNode = firstNode->getNext();
	//Ptr to get Item
	data = tempNode->getItem();
	remove(data);
	return data;
}



