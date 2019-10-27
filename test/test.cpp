#include <iostream>
#include <cassert>
#include <sstream>
#include <array>
#include <functional>
#include "../include/list.h"

int main(){
	sc::list<int> L{1, 3, 4, 5};
	// sc::list<int>::iterator it = L.begin();
	sc::list<int>::iterator it = L.begin();

	// std::cout<<"G VVVVV"<<std::endl;
	// G.print();
	std::cout<<"L VVVVV"<<std::endl;
	L.print();
	// assert((G != L));
	*it = 100;
	L.print();

}