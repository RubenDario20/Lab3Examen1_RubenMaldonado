#include <iostream>
#include <string>
#include "Red.hpp"
#include <iomanip>
#include <string.h>
#include <sstream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int menu() {
	int opcion = 0;
	cout << "--------Menu---------\n"
	     << "1) Agregar Pc\n"
	     << "2) Ingresar a Pc\n"
	     << "3) Salir \n"
	     << "---------------------";
	cout << "\nIngrese la opcion que desea desarrollar: " << endl;
	cin >> opcion;
	return opcion;
}

Pc* nuevaPc() {
	string ip, host, mascara;
	cout  <<"Ingrese la direccion Ip: ";
	cin >> ip;
	cout << "Ingrese su hostname: ";
	cin >> host;
	cout<< "Ingrese la mascara del pc: ";
	cin >> mascara;
	return new Pc(ip, host, mascara);
}

bool verificar(Red *r, int xx, string w) {
	vector<Pc*> temporal;
	int f= 0;
	string ax;
	temporal = r->getComputadoras();
	for(int i = 0; i < xx ; i++) {
		Pc *h = temporal[i];
		ax = h->getHostname();
		if (ax == w) {
			f++;
		}
	}
	if (f) {
		return true;
	} else {
		return false;
	}
}

int verificar2(Red *r, int xx, string w) {
	vector<Pc*> temporal;
	int f= 0;
	string ax;
	temporal = r->getComputadoras();
	int xy, yx;
	xy = sizeof(temporal);
	yx = sizeof(temporal[0]);
	int total = xy/yx;
	for(int i = 0; i < xx ; i++) {
		Pc *h = temporal[i];
		ax = h->getHostname();
		if (ax == w) {
			f = i;
			i = xx;
		}
	}
	return f;
}

bool verificar3(string ip1, string ip2, string mask) {
	int contadorunos = 0;
	string aux1, aux2;
	for (int i = 0; i < mask.length(); i++) {
		if (mask[i] == '1') {
			contadorunos++;
		}
	}
	if (ip1.length() >= contadorunos++) {
		for (int i = 0; i < contadorunos; i++) {
			aux1 += ip1[i];
		}
	} else {
		aux1 = ip1;
	}
	if (ip2.length() >= contadorunos++) {
		for (int i = 0; i < contadorunos; i++) {
			aux2 += ip2[i];
		}
	} else {
		aux2 = ip2;
	}
	if (aux1 == aux2) {
		return true;
	} else {
		return false;
	}

}

int main(int argc, char** argv) {
	int x = 0;
	int xx = 0;
	Red *redes = new Red();
	while ((x = menu()) != 3) {
		if (x == 1) {
			redes->AgregarPc(*nuevaPc());
			cout<< "Red agregada correctamente" << endl;
			xx++;
		} else if (x == 2) {
			string aux;
			cout << "Ingrese el hostname: ";
			cin >> aux;
			if (verificar(redes, xx, aux)) {
				int auxiliar = verificar2(redes, xx, aux);
				string flag;
				vector<Pc*> temporal;
				temporal = redes->getComputadoras();
				Pc *h = temporal[0];
				string dd = h->getDireccion();
				string nm = h->getmascara();
				string pi1 = h->Ping(dd);
				string pi2 = h->Ping(nm);
				while (flag != "exit") {
					cout << aux << "#";
					cin >> flag;
					cout << endl;
					if (flag == "show") {
						cout << "   " << "IP: " << dd << endl ;
						cout << "   " << "Netmask: " << nm << endl << endl;

					} else if(flag.find("ping_") == false) {



						if (flag == "ping_"+dd ) {
							string auxi;
							cout << "IP2: ";
							cin >> auxi;
							auxi = h->Ping(auxi);
							cout << endl;
							if (verificar3(pi1, auxi, pi2)) {
								cout << "Pinging with 32 bytes of data:\nReply from "<<dd << ": bytes=32 time=37ms TTL:46\n";
								cout << "Reply from "<<dd << ": bytes=32 time=37ms TTL:46\n";
								cout << "Reply from "<<dd << ": bytes=32 time=37ms TTL:46\n";
								cout << "Reply from "<<dd << ": bytes=32 time=37ms TTL:46\n";
								cout << "\nPing statics for " << dd << ":\n";
								cout << "   Packets: Sent = 4; Recieved = 4, Lost = 0 (0% loss)" << endl << endl ;
							} else {
								cout << "Pinging with 32 bytes of data:\nReply from "<<dd << ": Destination Host unreachable\n";
								cout << "Reply from "<<dd << ": Destination Host unreachable\n";
								cout << "Reply from "<<dd << ": Destination Host unreachable\n";
								cout << "Reply from "<<dd << ": Destination Host unreachable\n";
								cout << "\nPing statics for " << dd << ":\n";
								cout << "   Packets: Sent = 4; Recieved = 4, Lost = 0 (0% loss)" << endl << endl ;
							}

						} else {
							cout << "Pinging with 32 bytes of data:\nRequest timed out.\nRequest timed out.\nRequest timed out.\nRequest timed out.\n" ;
							cout << endl << "Ping statics for " << flag << ":" << endl;
							cout << "   Packets: Sent = 4; Recieved = 0, Lost = 4 (100% loss)" << endl << endl ;
						}

					} else if (flag != "exit") {
						cout << "comando incorrecto" << endl << endl;
					}
				}
			} else {
				cout << "no funciona" << endl;
			}
		}
	}
	delete redes;
	return 0;
}




