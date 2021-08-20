#include <string>
#include <vector>
#include "Pc.hpp"
using namespace std;

class Red {
		vector<Pc*> computadoras;
	public:
		Red();
		vector<Pc*> getComputadoras();
		void AgregarPc(Pc);
};