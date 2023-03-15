#pragma once
#include <functional>
#include "TNode.h";
#include "iostream";
using namespace std;

class LinList
{
private:
	TNode* head;
	TNode* cur;
public:
	LinList()
	{
		head = nullptr;
	}
	~LinList()
	{
		delete head;
	}
	void add(int a)
	{
		TNode* newNode = new TNode(a);
		TNode* current = head;
		if (head == nullptr)
		{
			head = newNode;
		}
		else
		{
			while (current->getNext() != nullptr)
			{
				current = current->getNext();
			}

			current->setNext(newNode);
		}
	}

	LinList(const LinList& tmp)
	{
		if (tmp.head == 0)
		{
			head = 0;
		}
		else
		{
			head = new TNode(*(tmp.head));
		}
		TNode* cur = tmp.head->getNext();
		while (cur != 0)
		{
			TNode* p = new TNode(cur->getInfo());
			this->add(int(p));
			cur = cur->getNext();
		}
	}

	bool isEmpty()
	{
		return head == nullptr;
	}

	void Print()
	{
		TNode* current = head;

		while (current != nullptr)
		{
			std::cout << current->getInfo() << " ";
			current = current->getNext();
		}
	}

	LinList& operator=(LinList tmp)
	{
		if (tmp.head == 0)
		{
			delete head;
			head = 0;
		}
		else
		{
			delete head;
			head = new TNode(tmp.head->getInfo());
		}
		TNode* cur = tmp.head->getNext();
		TNode* new_cur = head;
		while (cur != 0)
		{
			TNode* p = new TNode(tmp.cur->getInfo());
			new_cur->setNext(p);
			cur = cur->getNext();
		}
		return *this;
	}

	//Удалить все звенья за звеном с максимальной информацией
	void deleteNextMax()
	{
		int max = -INT_MAX;
		TNode* p = nullptr;
		TNode* current = head;
		while (current != 0)
		{
			if (current->getInfo() > max)
			{
				max = current->getInfo();
				p = current;
			}
			current = current->getNext();
		}
		if (p != nullptr)
		{
			current = p->getNext();
			while (current != 0)
			{
				p->setNext(current->getNext());
				current->setNext(nullptr);
				delete current;
				current = p->getNext();
			}
		}
	}

	//Задана инфа, которую надо вставить в список после к-го звена
	void insert(int k, int a)
	{
		int i;
		TNode* p = head;
		for (i = 0; (i < k) && (p != 0); i++)
		{
			p = p->getNext();
		}
		if (i == k)
		{
			TNode* current = new TNode(a);
			current->setNext(p->getNext());
			p->setNext(current);
		}
	}

	//Удалить из списка все звенья содержащие нулевую инфу
	void deletenullinfo()
	{
		TNode* p = head;
		while ((p != 0) && (p->getInfo() != 0));
		{
			head = p->getNext();
			p->setNext(nullptr);
			delete p;
			p = head;
		}
		if (p->getInfo() != 0)
		{
			TNode* prev = head;
			TNode* current = p->getNext();
			while (current != nullptr)
			{
				if (current->getInfo() == 0)
				{
					prev->setNext(current->getNext());
					current->setNext(nullptr);
					delete current;
					current = prev->getNext();
				}
				else
				{
					prev = current;
					current = current->getNext();
				}
			}
		}
	}

	void deleteNegative()
	{
		TNode* current = head;
		TNode* previous = nullptr;
		while (current != nullptr) {
			if (current->getInfo() < 0) {
				if (previous == nullptr) {
					head = current->getNext();
				}
				/*else {
					previous->getInfo() = current->getNext();
				}*/
				TNode* temp = current;
				current = current->getNext();
				delete temp;
			}
			else {
				previous = current;
				current = current->getNext();
			}
		}
	}

	void removeIf(function<bool(TNode)> EbaloOff) {
		if (isEmpty()) {
			return;
		}
		else {
			TNode* lastNode =nullptr;
			if (EbaloOff(*head)) {
				lastNode = head->getNext();
				delete head;
				head = lastNode;
			}
			else {
				lastNode = head;

			}
		}
	}
};