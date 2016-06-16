#include <iostream>
#include <stdlib.h>
//#include <tuple>
using namespace std;

int main(){
	pair<int, int> a;
	a= make_pair(4,3);
	cout << a.first;

	return 0;
}