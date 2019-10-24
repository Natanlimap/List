#include <iostream>
#include <cassert>
#include <sstream>
#include <array>
#include <functional>
#include "../include/list.h"

int main(){
	sc::list<int> L{1,2,3,4,5,6};
	sc::list<int>::iterator it = L.end();
	L.push_front(9);
	L.push_back(10);
	L.print();
	L.pop_front();
	L.print();
	L.pop_back();
	*L.end() = 100;
	L.print();
	std::cout<<"FRONT ="<<L.front() << "||BACK = "<<L.back() << std::endl;
	L.assign(7);
	L.print();	
	L.clear();
	L.print();
}