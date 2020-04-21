#include <iostream>
#include <fstream>
#include "Stiva.h"
#include "Coada.h"
#include "Exceptions.h"

using namespace std;



int main() {
	cout << endl;
	cout << "########################## Stiva #######################" << endl;
	cout << endl;

	ifstream fi("In.txt");
	Stiva stiva;

	fi >> stiva;
	cout << "######## Test: creare stiva din fisier:" << endl;
	cout <<"Continut stiva creata: "<<stiva<<endl<<endl;
	cout << "######## Test: pop until empty:" << endl;
	while (!stiva.isEmpty()) {
		cout << stiva.pop()<<endl;
	}

	cout << endl;
	cout << "######## Test: cout after all items are popped" << endl;
	cout << stiva<<endl;

	cout << endl;
	cout << "######## Test: push and pop:" << endl;
	stiva.push({0,4545});
	stiva.push({78,9});
	stiva.pop();
	stiva.push({0,28});
	cout << "continut stiva: " << stiva << endl;


	cout << endl;
	cout << "######## Test: is imaginary:" << endl;
	cout << stiva.isCompletelyImaginary()<<endl;

	cout << endl;
	cout << "######## Test: creare stiva din Vector:" << endl;
	Complex list[4];
	fi >> list[0];
	fi >> list[1];
	fi >> list[2];
	fi >> list[3];
	Stiva stiva2(4, list);
	cout << "Stiva creata prin Vector: " << stiva2 << endl;

	cout << endl;
	cout << "######## Test: underflow pt. pop:" << endl;
	try {
		stiva.pop();
		stiva.pop();
		stiva.pop();		// This actually produces the error
	} catch (std::exception& ex) {
		cout << "eroare captata: " << ex.what()<<endl;
	}

	/////////////////////////////////////
	cout << endl;
	cout << "########################## Coada #######################" << endl;
	cout << endl;

	Coada coada;
	fi >> coada;

	cout << "######## Test: creare coada din fisier:" << endl;
	cout << "Continut coada creata: " << coada << endl << endl;

	cout << "######## Test: pop until empty:" << endl;
	while (!coada.isEmpty()) {
		cout << coada.pop() << endl;
	}

	cout << endl;
	cout << "######## Test: cout after all items are popped" << endl;
	cout << coada << endl;

	cout << endl;
	cout << "######## Test: push and pop:" << endl;
	coada.push({ 8780,2143 });
	coada.push({ 0,91 });
	coada.pop();
	coada.push({ 0,714 });
	cout << "continut coada: " << coada << endl;

	cout << endl;
	cout << "######## Test: is imaginary:" << endl;
	cout << coada.isCompletelyImaginary() << endl;

	cout << endl;
	cout << "######## Test: creare coada din Vector:" << endl;
	coada=Coada(4, list);
	cout << "Coada creata prin Vector: " << coada << endl;

	cout << endl;
	cout << "######## Test: underflow pt. pop:" << endl;
	while (!coada.isEmpty()) {
		coada.pop();
	}

	try {
		coada.pop();
	} catch (exception& ex) {
		cout << "eroare captata: " << ex.what() << endl;
	}


	/////////////////////////////////////
	cout << endl;
	cout << "########################## Vector #######################" << endl;
	cout << endl;

	cout << endl;
	cout << "######## Test: exceptie pentru Vector.pop/push:" << endl;
	Vector test_vector;

	try {
		test_vector.pop();
	} catch (exception & ex) {
		cout << "eroare captata: " << ex.what() << endl;
	}
	try {
		test_vector.push({0,0});
	} catch (exception & ex) {
		cout << "eroare captata: " << ex.what() << endl;
	}
	return 0;
}