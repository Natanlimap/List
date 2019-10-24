#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <cstdlib> // size_t
#include <initializer_list> // std::initializer_list
#include <algorithm> 


namespace sc{ //sequence container 
    template <typename T>
        class list{
            private: 
            	struct Node
				{
					T data;
					Node * next;
					Node * prev;

					Node(T value = T(), Node * next = nullptr, Node *prev = nullptr)
					: data{value}, next{next}, prev{prev}{};
				};
               	Node *head;
               	Node *tail;

            public:
            list(){
            	head = nullptr;
            	tail = head;
            }
            void push_front(const T& e){
                Node *temp = new Node{e, head, nullptr};
                head = temp;
            }
            void push_back(const T& e){
                Node *s;
                Node *f;
                f = head;
                while(f!=nullptr){
                    s = f;
                    f = f->next;
                }
                Node *temp = new Node{e, nullptr, s};
                s->next = temp;
                tail = temp;

            }
            bool empty(list <T>* & head){
                if(head == nullptr){
                    return true;
                }
                else{
                    return false;
                }

            }
            void print(){
                std::cout<<"List --->";
                Node *temp;
                temp = new Node;
                temp = head;
                while(temp){
                    std::cout<<"["<<temp->data<<"]";
                    temp = temp->next;
                }
                std::cout<<std::endl;
            }
            size_t size(list <T>*head){
                size_t count{0};
                while(head!=nullptr){
                    count++;
                    head = head->next;
                }
                return count;
            }
            void assign(list <T>* &L, const T& value){
                Node *temp;
                temp = L;
                while(temp){
                    temp->data = value;
                    temp = temp->next;
                }
            }
            T& back(list <T>*&L){
                Node *temp;
                temp = L;
                while(temp->next){
                    temp = temp->next;
                }
                return temp->data;

            }

            void pop_front(list <T>* &L){
                L = L->next;
            }

	};
};
#endif