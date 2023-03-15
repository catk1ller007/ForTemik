#include <iostream>
#include "Line_Spisok.h"
#include "TNode.h"
#include <locale>
using namespace std;



int main() {
	setlocale(LC_ALL, "Rus");
	LinList  A;
	
	A.add(-4);
	A.add(24);
	A.add(-5);
	A.add(-6);
	A.add(-7);
	A.Print();

	A.deleteNextMax();
	cout << "после удаления \n";
	A.Print();

	return 0;
}