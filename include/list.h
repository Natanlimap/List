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
                        iterator operator=(const iterator &rhs){this->ptr = rhs.ptr;return this->ptr; } //pointer`s reference
                        iterator operator+(size_t offset){
                            for(size_t i{0};i<offset;i++){
                                this->ptr = this->ptr->next; 
                            }
                            return this->ptr;
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
                            return this->ptr;
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
                        iterator operator++(int){return ptr = ptr->next;}
                        iterator& operator--() { ptr = ptr->prev; return *this;}
                        iterator operator--(int){return ptr = ptr->prev;}



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
                        const Node* operator&(void){return &ptr;}//returns the pointer`s reference
                        const pointer operator->(void){return ptr;}//returns the pointer`s reference
                        const iterator operator=(const iterator &rhs){this->ptr = rhs.ptr;return this->ptr; } //pointer`s reference
                        const iterator operator+(size_t offset){
                            for(size_t i{0};i<offset;i++){
                                this->ptr = this->ptr->next; 
                            }
                            return this->ptr;
                        }
                        const iterator operator-(size_t offset){
                         for(size_t i{0};i<offset;i++){
                                this->ptr = this->ptr->prev; 
                            }
                            return this->ptr;
                        }
                        const difference_type operator-(const iterator& lhs){
                            size_t count{0};
                            iterator *temp;
                            temp = this->ptr;
                            while(temp!= lhs){
                                temp = temp->next;
                                count++;
                            }
                            return count;
                        }
                        const_iterator& operator++() {ptr = ptr->next; return *this;}
                        const_iterator operator++(int){return ptr = ptr->next;}
                        const_iterator& operator--() { ptr = ptr->prev; return *this;}
                        const_iterator operator--(int){return ptr = ptr->prev;}


                };
            public:
                //Default constructor that creates an empty list.
            list(){
                head = new Node;
                tail = new Node{T(), nullptr, head};
                head->next = tail;
            }
            // /Constructs the list with count default-inserted instances of T .
            list(size_t count){
                size_t cont{0};
                head = new Node;
                tail = new Node{T(), nullptr, head};
                head->next = tail;
                while(cont < count){
                    push_back(T());
                    cont++;
                }
            }
            //Constructs the list with the contents of the range [first, last) .
            template< typename InputIt >
            list( InputIt first, InputIt last ){
                    size_t count{0};
                    head = new Node;
                    tail = new Node{T(), nullptr, head};
                    head->next = tail;
                    iterator aux = first;
                    while(aux != last){
                        push_back(*aux);
                        aux++;
                    }
            }
            //Constructs the list with the contents of the initializer list il .
            list(const std::initializer_list<T> & il ){ 
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
            //Copy constructor. Constructs the list with the deep copy of the contents of other .
            list( const list& other ){
                head = new Node;
                tail = new Node{T(), nullptr, head};
                head->next = tail;
                Node *temp;
                temp = (other.head)->next;
                while(temp != other.tail){
                    push_back(temp->data);
                    temp = temp->next;
                }
            }
            //Destructs the list. The destructors of the elements are called and the used storage is deallocated. Note, that if the elements are pointers, the pointed-to objects are not destroyed.
            ~list(){
                while(tail != head){
                    tail = tail->prev;
                    delete[] tail->next;
                }
                delete[] head;
            }
            //Copy assignment operator. Replaces the contents with a copy of the contents of other.
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
                while(count < other.size() + 1){
                        left->data = ptother->data;
                        left = left->next;
                        ptother = ptother->next;
                        count++;
                };

            }
            //Replaces the contents with those identified by initializer list ilist .
            list& operator=(const std::initializer_list<T> ilist ){
               if(size() != ilist.size()){
                    while(size() > ilist.size()){
                        pop_back();
                    };
                    while(size() < ilist.size()){
                        push_back(T());
                    };
                };
                Node *left;
                left = head->next;
                size_t count{0};
                while(count < ilist.size()){
                        left->data = *(ilist.begin() + count);
                        left = left->next;
                        count++;
                };
            }
            //return the number of elements in the container.
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
            //remove all elements from the container.
            void clear(){
               while(tail->prev != head){
                tail = tail->prev;
                delete[] tail->next;
               }
            }
            //adds value to the front of the list
            void push_front(const T& e){                             
                Node *temp = new Node{e, head->next, head};
                (temp->next)->prev = temp;
                head->next = temp;

            }
            //adds value to the end of the list.
            void push_back( const T &e )

            {
                Node *temp = new Node( e, tail, tail->prev);
                (temp->prev)->next = temp; // temp->prev é o nó anterior ao tail.
                tail->prev = temp;

            }
            //removes the object at the front of the list.
            void pop_front(){
                head = head->next;
                delete[]head->prev;
                head->prev = nullptr;
            }
            //removes the object at the end of the list.
            void pop_back(){
                tail = tail->prev;
                delete[]tail->next;
                tail->next = nullptr;
            }
            //returns the object at the end of the list.
            const T & back() const{
                return tail->prev->data;
            }
            const T & front() const{
                return head->next->data;
            }
            bool empty(){
                if(head->next == tail){
                    return true;
                }
                else{
                    return false;
                }

            }
      



             friend std::ostream & operator<<(std::ostream &os, const list& lista ){
                list temp = lista;
                temp.print();
                return os;
            }
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
                        if(ptlhs->data != ptrhs->data){
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
        const_iterator find( const T & value ) const{
                Node *temp;
                temp = head->next;
                const_iterator here;
                while(temp!=tail->prev){
                    if(temp->data = value){
                        here = temp;
                        return here;
                    }
                else{
                    return nullptr;
                }
            }
        }

        iterator insert(iterator pos, const T & value ){
           size_t count{0};
           while(pos!=nullptr){
            pos--;
            count++;
           }
            count = count - 2   ;
            std::cout<<count<<std::endl;

            Node *aux;
            aux = head->next;
            while(count!= 0){
                aux = aux->next;
                count--;
            }
            Node *temp = new Node( value, aux, aux->prev);
            (temp->prev)->next = temp; // temp->prev é o nó anterior ao tail.
            aux->prev = temp;
            pos = temp;
            return pos;
        };
        iterator insert(iterator pos, iterator first, iterator last){
           size_t count{0};
           while(pos!=nullptr){
            pos--;
            count++;
           }
            count = count - 2   ;
            std::cout<<count<<std::endl;

            Node *aux;
            aux = head->next;
            while(count!= 0){
                aux = aux->next;
                count--;
            }
            Node *temp = new Node;
            while(first != last){
                Node *temp = new Node(*first, aux, aux->prev);
                (temp->prev)->next = temp; // temp->prev é o nó anterior ao tail.
                aux->prev = temp;
                first++;
            }
            pos = temp;
            return pos;
        };
        iterator insert(iterator pos, const std::initializer_list<T> ilist){
           size_t count{0};
           while(pos!=nullptr){
            pos--;
            count++;
           }
            count = count - 2   ;

            Node *aux;
            aux = head->next;
            while(count!= 0){
                aux = aux->next;
                count--;
            }

            Node *temp = new Node;
            while((ilist.begin() + count )!= ilist.end()){
                Node *temp = new Node(*ilist.begin() + count, aux, aux->prev);
                (temp->prev)->next = temp; // temp->prev é o nó anterior ao tail.
                aux->prev = temp;
                count++;
            }
            pos = temp;
            return pos;
        };
        iterator erase( iterator pos ){
            size_t count{0};
            while(pos!=nullptr){
            pos--;
            count++;
           }
            count = count - 2   ;
            Node *aux;
            aux = head->next;
            while(count!= 0){
                aux = aux->next;
                count--;
            }
            aux->prev->next = aux->next;
            aux->next->prev = aux->prev;
            delete[] aux;
            return aux->next;

        }

        iterator erase(iterator first, iterator last){
            size_t count{0};
            iterator aux = first;
            while(aux!=last){
                erase(aux);
                aux++;
                count++;
            }
            return last;

        }
    };
};
#endif