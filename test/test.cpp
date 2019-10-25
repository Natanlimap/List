#include <iostream>
#include <cassert>
#include <sstream>
#include <array>
#include <functional>
#include "../include/list.h"

int main(){
	sc::list<int> L{1,2,3,4,5,6};
	sc::list<int>G(10);

	std::cout<<"G VVVVV"<<std::endl;
	G.print();
	std::cout<<"L VVVVV"<<std::endl;
	L.print();
	assert((G != L));

	G = L;
	assert(G == L);
	std::cout<<"G VVVVV"<<std::endl;
	G.print();
	std::cout<<"L VVVVV"<<std::endl;
	L.print();
}