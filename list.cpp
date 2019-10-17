#include <iostream>
#include <cassert>
#include <sstream>
#include <array>
#include <functional>

template<typename T>
struct Node
{
	T data;
	Node * next;

	Node(T value = T(), Node * next = nullptr)
	: data{value}, next{next}{};
};
template<typename T>
void push_front(Node <T>* & head, const T& e);
template<typename T>
size_t size(Node <T>*head);
template<typename T>
void print(Node <T>*head);
template<typename T>
bool empty(Node <T>* & head);
template<typename T>
void assign(Node <T>* &L, const T& value);
template<typename T>
void pop_front(Node <T>* &L);
template<typename T>
T& back(Node <T>* &L);

int main(){
	Node<int> *L{};

	assert(empty(L) == true);

	push_front(L, 2);
	print(L);
	push_front(L, 4);
	print(L);
	assign(L, 5);
	print(L);
	pop_front(L);
	print(L);
}

template<typename T>
void push_front(Node <T>* & head, const T& e){
	Node<T> *temp = new Node<T>{e, head};
	head = temp;
}
template<typename T>
bool empty(Node <T>* & head){
	if(head == nullptr){
		return true;
	}
	else{
		return false;
	}

}

template<typename T>
void print(Node <T>*head){
	std::cout<<"List --->";
	while(head){
		std::cout<<"["<<head->data<<"]";
		head = head->next;
	}
	std::cout<<std::endl;
}
template<typename T>
size_t size(Node <T>*head){
	size_t count{0};
	while(head!=nullptr){
		count++;
		head = head->next;
	}
	return count;
}
template<typename T>
void assign(Node <T>* &L, const T& value){
	Node<T> *temp;
	temp = L;
	while(temp){
		temp->data = value;
		temp = temp->next;
	}
}
template<typename T>
T& back(Node <T>*&L){
	Node<T> *temp;
	temp = L;
	while(temp->next){
		temp = temp->next;
	}
	return temp->data;

}

template<typename T>
void pop_front(Node <T>* &L){
	L = L->next;
}