
#include "LinkedList.h"
#include <iostream>

LinkedList::ListNode::ListNode(const Line &line, ListNode* prev, ListNode* next): data(line), prev(NULL), next(NULL){} // Linked list ctor

/*Getters ans Setters for data members*/
void LinkedList::ListNode::setData(Line line){
	data = line;
}

Line LinkedList::ListNode::getData(){
	return data;
}

void LinkedList::ListNode::setPrev(ListNode* prev){
	this->prev = prev;
}

LinkedList::ListNode* LinkedList::ListNode::getPrev(){
	return prev;
}

void LinkedList::ListNode::setNext(ListNode* next){
	this->next = next;
}

LinkedList::ListNode* LinkedList::ListNode::getNext(){
	return next;
}

LinkedList::ListNode::~ListNode(){
	
}

/*Default constructor: Initializing data members */
LinkedList::LinkedList(): theSize(0), head(NULL), tail(NULL){
	head = new ListNode (Line(), NULL, NULL);
	tail = new ListNode (Line(), NULL, NULL);
head -> setNext(tail);
tail ->setPrev(head);
}

/*Virtual destructor: Deleting data members*/
LinkedList::~LinkedList() {
	delete head;
	delete tail;
}

/*Copy constructor: same as deep copy*/
LinkedList::LinkedList(const LinkedList &llObj) : LinkedList(){
	deepCopy(llObj);

}

void LinkedList::deepCopy(const LinkedList &llObj){ // DeepCopy ctor

	ListNode * itllobj = llObj.head -> getNext();
	for (int i = 0; i != llObj.size(); ++i) {
		push_back(itllobj -> getData());
	}
	
}

const LinkedList & LinkedList::operator=(const LinkedList &llObj){ // Assingment operator overloaded
	if(this == &llObj){
		return *this;
	}else{
		removeAll();
		deepCopy(llObj);
		return *this;
	}


}

void LinkedList::removeAll(){ // function removeAll to remove list before copying
	while(!empty()){
		pop_front();
	}
}
/*Insert a double linked in front of the list*/
void LinkedList::push_front(const Line &line){
	ListNode* temp = new ListNode(line, NULL, NULL);

	temp->setNext(head->getNext());
	temp->setPrev (head);
	temp -> getNext() -> setPrev(temp);
	head -> setNext (temp);

	++theSize;
}

/*Insert a double linked in end of the list*/
void LinkedList::push_back(const Line &line){
	ListNode* temp = new ListNode(line, NULL, NULL);

	temp -> setNext (tail);
	temp -> setPrev(tail -> getPrev()) ;
	temp -> getPrev() -> setNext (temp);
	tail -> setPrev(temp);
	

	++theSize;
}

/*Delete an element from the front of a double linked list*/
void LinkedList::pop_front(){
	ListNode* temp = head->getNext();
	head -> setNext(temp -> getNext());
	temp -> getNext() -> setPrev(head);
	--theSize;
	delete temp;
}

/*Delete an element from the end of a double linked list*/
void LinkedList::pop_back(){
	ListNode* temp = tail->getPrev();
	tail -> setPrev(temp -> getPrev());
	temp -> getPrev() -> setNext(tail);
	--theSize;
	delete temp;
}

/*Return the size of the double linked list*/
int LinkedList::size() const{
	return theSize;
}

/*Returns whether the list is empty*/
bool LinkedList::empty()const{
	return(head-> getNext()==tail);
}

/*Inserts a new node at the specified position in the double linked list*/
void LinkedList::insert(const Line &line, int k){
	ListNode* temp = new ListNode(line, NULL, NULL);

	if(k<1 || k > theSize + 1){
		//cout<<"Index value entered is invalid";
		return;
	}
	else {
		ListNode* curr = head;
		for(int i = 1; i<= k-1; i++){
			curr = curr -> getNext();
		}

		temp -> setNext(curr -> getNext());
		curr -> getNext() -> setPrev(temp);
		curr -> setNext(temp);
		temp -> setPrev(curr);
	}
}

/*Deletes a node at the specified position in the double linked list*/
void LinkedList::remove(int k){
	if(k<1 || k > theSize){
		//cout<<"Index value entered is invalid";
		return;
	}
	else{
		ListNode* temp;
		ListNode* curr = head;
		for(int i = 1; i<= k-1; i++){
			curr = curr->getNext();
		}
		temp = curr->getNext();
		curr->setNext(temp->getNext());
		temp->getNext()->setPrev(curr);
		delete temp;
	}

}

void LinkedList::print(int position) {  // print function to be called from linekeeper class 
	if (position < 1 || position > theSize) {
		std::cout << "Invalid Position for Linked List";
		return;
	}

	ListNode *it = head;
	for (int i = 0; i != position; ++i) {
		it = it -> getNext();
	}

	std::cout << it -> getData();
	std::cout << "\n";
}





