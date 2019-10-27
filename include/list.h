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
                class iterator{
                    private:
                        Node *ptr;

                    public:

                        typedef std::ptrdiff_t difference_type; //!< Difference type used to calculated distance between iterators.
                        typedef Node value_type;           //!< Value type the iterator points to.
                        typedef Node* pointer;             //!< Pointer to the value type.
                        typedef Node& reference;           //!< Reference to the value type.
                        typedef const T& const_reference;           //!< Reference to the value type.
                        typedef std::bidirectional_iterator_tag iterator_category; //!< Iterator category.
                        iterator(Node * pt=nullptr) : ptr{ pt }{}      // it( )
                        T& operator*(){return ptr->data;} //returns the pointer`s value
                        pointer operator&(void){return ptr;}//returns the pointer`s reference
                        pointer operator->(void){return ptr;}//returns the pointer`s reference
                        iterator operator=(const iterator &rhs){this->ptr = rhs.ptr; } //pointer`s reference
                        iterator operator+(size_t offset){
                            for(size_t i{0};i<offset;i++){
                                this->ptr = this->ptr->next; 
                            }
                        }
                        bool operator==(const iterator& rhs) const {return this->ptr == rhs.ptr;}
                        bool operator!=(const iterator& rhs) const {return this->ptr != rhs.ptr;}
                        bool operator>(const iterator &rhs) const {return this->ptr > rhs.ptr;}
                        bool operator<(const iterator &rhs) const {return this->ptr < rhs.ptr;}
                        bool operator<=(const iterator &rhs) const {return this->ptr <= rhs.ptr;}
                        iterator operator-(size_t offset){
                         for(size_t i{0};i<offset;i++){
                                this->ptr = this->ptr->prev; 
                            }
                        }
                        size_t operator-(const iterator& lhs){
                            size_t count{0};
                            while(this->ptr != lhs.ptr){
                                ptr = lhs.ptr;
                                count++;
                            }
                            return count;
                        }
                        iterator& operator++() {ptr = ptr->next; return *this;}
                        iterator operator++(int){return ptr->next;}
                        iterator& operator--() { ptr = ptr->prev; return *this;}
                        iterator operator--(int){return ptr->prev;}



                };

            public:

                class const_iterator{
                    private:
                        const T *ptr;
                    public: 

            
                        typedef std::ptrdiff_t difference_type; //!< Difference type used to calculated distance between iterators.
                        typedef Node value_type;           //!< Value type the iterator points to.
                        typedef Node* pointer;             //!< Pointer to the value type.
                        typedef Node& reference;           //!< Reference to the value type.
                        typedef const T& const_reference;           //!< Reference to the value type.
                        typedef std::bidirectional_iterator_tag iterator_category; //!< Iterator category.
                        
                        bool operator==(const iterator& rhs) const {return this->ptr == rhs.ptr;}
                        bool operator!=(const iterator& rhs) const {return this->ptr != rhs.ptr;}
                        bool operator>(const iterator &rhs) const {return this->ptr > rhs.ptr;}
                        bool operator<(const iterator &rhs) const {return this->ptr < rhs.ptr;}
                        bool operator<=(const iterator &rhs) const {return this->ptr <= rhs.ptr;}

                        const reference operator*(){return ptr->data;} //returns the pointer`s value
                        const pointer operator&(void){return ptr;}//returns the pointer`s reference
                        const pointer operator->(void){return ptr;}//returns the pointer`s reference
                        const iterator operator=(const iterator &rhs){this->ptr = rhs.ptr; } //pointer`s reference
                        const iterator operator+(size_t offset){
                            for(size_t i{0};i<offset;i++){
                                this->ptr = this->ptr->next; 
                            }
                        }
                        const iterator operator-(size_t offset){
                         for(size_t i{0};i<offset;i++){
                                this->ptr = this->ptr->prev; 
                            }
                        }
                        const size_t operator-(const iterator& lhs){
                            size_t count{0};
                            while(this->ptr!= lhs){
                                ptr = ptr->next;
                                count++;
                            }
                            return count;
                        }
                        const_iterator& operator++() {ptr = ptr->next; return *this;}
                        const_iterator operator++(int){return ptr->next;}
                        const_iterator& operator--() { ptr = ptr->prev; return *this;}
                        const_iterator operator--(int){return ptr->prev;}


                };
            public:
            list(){
                head = new Node;
                tail = new Node{T(), nullptr, head};
                head->next = tail;
            }
            list(size_t size){
                size_t count{0};
                head = new Node;
                tail = new Node{T(), nullptr, head};
                head->next = tail;
                while(count < size){
                    push_back(T());
                    count++;
                }
            }
            template< typename InputIt >
            list( InputIt first, InputIt last ){
                head = nullptr;
                tail = nullptr;
                size_t capacity = last - first, count{0};
                Node *temp;
                temp = head;
                while(count < capacity){
                    push_front(first->data);
                    first++;
                }


            }
            list(const std::initializer_list<T> & il ){ //Create a list from a initializer_list
                    size_t list_size = il.size();
                    size_t count{0};
                     head = new Node;
                     tail = new Node{T(), nullptr, head};
                     head->next = tail;
                    while(count < list_size){
                        push_front(T());
                        count++;
                }
                    Node *temp = head->next;
                    for(size_t i = 0; i < list_size;i++){
                        temp->data = *(il.begin() + i);
                        temp=temp->next;
                    }
                }
            ~list(){
                while(tail){
                    tail = tail->prev;
                 
                }
            }

            void push_front(const T& e){                                //AJEITAR
                Node *temp = new Node{e, head->next, head};
                (temp->next)->prev = temp;
                head->next = temp;

            }
            bool empty(){
                if(head->next == tail){
                    return true;
                }
                else{
                    return false;
                }

            }
      

            void push_back( const T &e )

            {
                Node *temp = new Node( e, tail, tail->prev);
                (temp->prev)->next = temp; // temp->prev é o nó anterior ao tail.
                tail->prev = temp;

            }


            void clear(){
                head = tail;
            }
            list& operator=(const list& other ){
                if(size() != other.size()){
                    while(size() > other.size()){
                        pop_back();
                    };
                    while(size() < other.size()){
                        push_back(T());
                    };
                };
                Node *left;
                Node *ptother;
                left = head;
                ptother = other.head;
                size_t count{0};
                while(count < other.size()){
                        left->data = ptother->data;
                        left = left->next;
                        ptother = ptother->next;
                        count++;
                };

            }
            // list& operator=(const std::initializer_list<T> ilist ){
            //    if(size() != ilist.size()){
            //         while(size() > ilist.size()){
            //             pop_back();
            //         };
            //         while(size() < ilist.size()){
            //             push_back(T());
            //         };
            //     };
            //     Node *left;
            //     // left = head->next;
            //     size_t count{0};
            //     while(count < ilist.size()){
            //             left->data = *(ilist.begin() + count);
            //             left = left->next;
            //             count++;
            //     };
            // }
            void print(){
                std::cout<<"List --->";
                Node *temp;
                temp = new Node;
                temp = head->next;
                while(temp!=tail){
                    std::cout<<"["<<temp->data<<"]";
                    temp = temp->next;
                }
                std::cout<<std::endl;
            }
            const size_t size()const{
                size_t count{0};
                Node *temp;
                temp = head->next;
                while(temp!=tail){
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
             iterator begin(){
                return head->next;
            }
            iterator end(){
                iterator it = tail;
                return it;
            }
            const_iterator cbegin(){
                iterator it = head->next;
                return it;
            }
            const_iterator cend(){
                iterator it = tail;
                return it;
            }
            friend bool operator==(const list& lhs, const list& rhs ){
                if(lhs.size() == rhs.size()){
                    size_t count{0};
                    Node *ptlhs;
                    Node *ptrhs;
                    ptlhs = lhs.head;
                    ptrhs = rhs.head;
                    while(count < lhs.size()){
                        if(ptlhs->data != ptrhs->data){
                            return false;
                        }
                            ptlhs = ptlhs->next;
                            ptrhs = ptrhs->next;
                            count++;
                    }
                    return true;
                }else{
                    return false;
                }
            }

             friend bool operator!=(const list& lhs, const list& rhs ){
                if(lhs.size() == rhs.size()){
                    size_t count{0};
                    Node *ptlhs;
                    Node *ptrhs;
                    ptlhs = lhs.head;
                    ptrhs = rhs.head;
                    while(count < rhs.size()){
                        if(ptlhs != ptrhs){
                            return true;
                        }
                            ptlhs = ptlhs->next;
                            ptrhs = ptrhs->next;
                            count++;
                    }
                    return false;
                }else{
                    return true;
                }
            }
    };
};
#endif