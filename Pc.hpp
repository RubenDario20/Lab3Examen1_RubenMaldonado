#include <vector>
#include <string>
using namespace std;
class Pc {
		string direccionIP;
		string hostname;
		string mascara;
	public:
		Pc();
		Pc(string, string, string);
		string getDireccion();
		string getHostname();
		string getmascara();
		string Ping(string);
		void setDireccion(string);
		void setHostname(string);
		void setMascara(string);

};