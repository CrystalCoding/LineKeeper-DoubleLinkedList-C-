
#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include "Line.h"

class LinkedList {

private:
	

	class ListNode {

		private:

			Line data;
			ListNode* prev;
			ListNode* next;

		public:

			/*ListNode() = delete;
			  ListNode)(const Node&) = default;
			  ListNode()= default;*/

			ListNode(const Line &line, ListNode* prev, ListNode* next);
			void setData(Line obj);
			Line getData();
			void setPrev(ListNode* prev);
			ListNode* getPrev();
			void setNext(ListNode* next);
			ListNode* getNext();
			virtual ~ListNode();
	};

	int theSize;
	ListNode* head;
	ListNode* tail;
public:
	LinkedList();
	virtual ~LinkedList();
	LinkedList(const LinkedList &);
	const LinkedList & operator=(const LinkedList &);
	void push_front(const Line &);
	void push_back(const Line &);
	void pop_front();
	void pop_back();
	int size() const;
	bool empty()const;
	void insert(const Line &, int);
	void remove(int);
	void removeAll();
	void print(int position);

private:
	void deepCopy(const LinkedList &llObj);


};

#endif /* LINKEDLIST_H_ */
