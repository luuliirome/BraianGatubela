#include <iostream>
#include "dato.h"

using namespace std;

int main(){
	
	dato a;
	dato b;
	a.nuevoDatoNat(4);
	b.nuevoDatoNat(6);
	cout << b.esMenor(a)<<endl;
	

	return 0;
}