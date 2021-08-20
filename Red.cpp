#include <iostream>
#include "Red.hpp"
using namespace std;
#include <vector>
#include <string>

Red::Red() {
}


void Red::AgregarPc(Pc x){
	this->computadoras.push_back(&x);
//	Pc *h = computadoras[0];
//	cout << h->getHostname();
}

vector<Pc*> Red::getComputadoras(){
	return this->computadoras;
}
//Al intentar hacer el delete me tira un error