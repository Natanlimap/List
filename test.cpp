#include <iostream>
#include <cassert>
#include <sstream>
#include <array>
#include <functional>
#include "list.h"

int main(){
	sc::list<int> L;
	L.push_front(2);
	L.print();
	L.push_front(2);
	L.print();
}