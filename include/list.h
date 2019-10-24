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
                // class iterator{
                //     private:
                //         Node *ptr;
                //     public:
                //         typedef std::ptrdiff_t difference_type; //!< Difference type used to calculated distance between iterators.
                //         typedef Node value_type;           //!< Value type the iterator points to.
                //         typedef Node* pointer;             //!< Pointer to the value type.
                //         typedef Node& reference;           //!< Reference to the value type.
                //         typedef const T& const_reference;           //!< Reference to the value type.
                //         typedef std::bidirectional_iterator_tag iterator_category; //!< Iterator category.
                //         iterator(T * pt=nullptr) : ptr{ pt }{}      // it( )
                //         reference operator*(){return *ptr;} //returns the pointer`s value
                //         pointer operator&(void){return ptr;}//returns the pointer`s reference
                //         pointer operator->(void){return ptr;}//returns the pointer`s reference
                //         iterator operator=(const iterator &rhs){this->ptr = rhs.ptr; } //returns the pointer`s value
                //         iterator operator=(Node a){*this->ptr = a; } 
                //         iterator operator+(size_t offset){return this->ptr = this->ptr + offset; }
                //         iterator operator-(size_t offset){ptr = ptr - offset; }
                //         size_t operator-(const iterator& lhs){return this->ptr - lhs.ptr;}
                //         iterator& operator++() {ptr = ptr->next; return *this;}
                //         iterator operator++(int){return ptr->next;}
                //         iterator& operator--() { ptr = ptr->prev; return *this;}
                //         iterator operator--(int){return ptr->prev;}

                //         friend size_t operator-(T *a, const iterator &lhs){return (a - lhs.ptr);} //distance

                //         bool operator==(const iterator& rhs) const {return *this->ptr == *rhs.ptr;}
                //         bool operator!=(const iterator& rhs) const {return *this->ptr != *rhs.ptr;}
                //         bool operator>(const iterator &rhs) const {return this->ptr > rhs.ptr;}
                //         bool operator<(const iterator &rhs) const {return this->ptr < rhs.ptr;}
                //         bool operator<=(const iterator &rhs) const {return this->ptr <= rhs.ptr;}

                // };

            public:

                // class const_iterator{
                //     private:
                //         const T *ptr;
                //     public: 

                //         // typedef std::ptrdiff_t difference_type; //!< Difference type used to calculated distance between iterators.
                //         // typedef T value_type;           //!< Value type the iterator points to.
                //         // typedef T* pointer;             //!< Pointer to the value type.
                //         // typedef T& reference;           //!< Reference to the value type.
                //         // typedef const T& const_reference;           //!< Reference to the value type.
                //         // typedef std::bidirectional_iterator_tag iterator_category; //!< Iterator category.
                //         // const T& operator*(void){return *ptr;}
                //         // const T*& operator&(void){return ptr;}
                //         // const T*& operator->(void){return ptr;}
                //         // const iterator operator= (const iterator rhs){this->ptr = rhs.ptr; }
                //         // const iterator operator+(size_t offset){return ptr = ptr + offset; }
                //         // const iterator operator-(size_t offset){ptr -= offset; }
                //         // const iterator operator-(const iterator &rhs){this->ptr = this->ptr - rhs.ptr; }
                //         // const iterator& operator++() { ++ptr; return *this;}
                //         // const iterator operator++(int){return ptr++;}
                //         // const iterator& operator--() { --ptr; return *this;}
                //         // const iterator operator--(int){return ptr--;}


                //         // bool operator==(const iterator& other) const{return *this->ptr == *other.ptr;}
                //         // bool operator!=(const iterator& other) const{return *this->ptr != *other.ptr;}
                //         // bool operator>(const iterator rhs) const {return this->ptr > rhs.ptr;}
                //         // bool operator<(const iterator rhs) const {return this->ptr < rhs.ptr;}


                // };
            public:
            list(){
            	head = nullptr;
            	tail = head;
            }
            list(size_t size){
                size_t count{0};
                head = nullptr;
                tail = head;
                while(count < size){
                    push_front(T());
                    count++;
                }
            }
            list(const std::initializer_list<T> & il ){ //Create a list from a initializer_list
                    size_t list_size = il.size();
                    size_t count{0};
                    head = nullptr;
                    tail = head;
                    while(count < list_size){
                        push_front(T());
                        count++;
                }
                    Node *temp = head;
                    for(size_t i = 0; i < list_size;i++){
                        temp->data = *(il.begin() + i);
                        temp=temp->next;
                    }
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
            bool empty(){
                if(head == nullptr){
                    return true;
                }
                else{
                    return false;
                }

            }
            void clear(){
                while(head!=tail){
                    head = head->next;
                    delete[]head->prev;
                }
                delete[]tail;
                delete[]head->next;
                head = nullptr;
                tail = head;
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
            size_t size(){
                size_t count{0};
                Node *temp;
                temp = head;
                while(temp!=nullptr){
                    count++;
                    temp = temp->next;
                }
                return count;
            }
            void assign(const T& value){
                Node *temp;
                temp = head;
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

            void pop_front(){
                head = head->next;
                delete[]head->prev;
                head->prev = nullptr;
            }
            void pop_back(){
                tail = tail->prev;
                delete[]tail->next;
                tail->next = nullptr;
            }
            const T & back() const{
                return tail->data;
            }
            const T & front() const{
                return head->data;
            }
            // iterator begin(){
            //     iterator begin = head;
            //     return begin;
            // }
            // iterator end(){
            //     return tail;
            // }
            // friend bool operator==(Node a, int b){
            //     if(a.data == b)
            //         return true;
            //     else
            //         return false;
            // }
	};
};
#endif