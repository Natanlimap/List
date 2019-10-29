#include <iostream>  // cout, endl
#include <cassert>   // assert()
#include "../include/list.h"

int main(){
	sc::list<int> seq{1, 2, 3};
	sc::list<int> seq2(100);
	sc::list<int>::iterator it = seq.begin();
	sc::list<int>::iterator it2 = seq.end();
	seq2.print();
	seq2.assign(it, it2);
	seq2.print();
	seq.assign(2, 3);
	seq.print();
}