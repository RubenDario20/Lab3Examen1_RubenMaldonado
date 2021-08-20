#include <iostream>
#include "Pc.hpp"
#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

Pc::Pc() {
}

Pc::Pc(string direccion, string hostname, string mascara) {
	this->direccionIP = direccion;
	this->hostname = hostname;
	this->mascara = mascara;
}

string Pc::getDireccion() {
	return this->direccionIP;
}

string Pc::getHostname() {
	return this->hostname;
}
string Pc::getmascara() {
	return this->mascara;
}

void Pc::setDireccion(string d) {
	this->direccionIP = d;
}

void Pc::setHostname(string h) {
	this->hostname = h;
}

void Pc::setMascara(string m) {
	this->mascara = m;
}

string Pc::Ping(string x) {
	vector<string> tokens;
	stringstream check1(x);
	string intermediate;

	while(getline(check1, intermediate, '.')) {
		tokens.push_back(intermediate);
	}

	int temp1=0;
	vector<int> binarios;
	string ipBinario="";

	for(int i = 0; i < tokens.size(); i++) {
		temp1 = stoi(tokens[i]);
		string temp2 = "";
		//cout << to_string(temp1) << '\n';
		while(temp1!=0) {
			temp2 += to_string(temp1%2);
			temp1 = temp1/2;
		}

		//cout << temp2 << " ";
		string invertida = "";
		for(int j=temp2.size()-1; j>=0; j--)
			invertida += to_string(temp2[j]-48);

		//cout << ipBinario << " ";
		string relleno="";
		for(int j=invertida.size(); j<8; j++) {
			relleno += "0";
		}
		ipBinario += relleno+invertida+".";
	}
	return ipBinario;
}