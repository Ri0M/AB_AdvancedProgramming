#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void menu(){
	cout << "Bienvenido, por favor seleccione una opción: " << endl;
	cout << "1. Añadir cantante. " << endl;
	cout << "2. Salir. " << endl;
}

void guardarCantante(const vector<string>& lista_nombres) {

	ifstream empty_check("cantantes.csv");

	bool archivoVacio = empty_check.peek() == ifstream::traits_type::eof();
	empty_check.close();

	ofstream archivo("cantantes.csv", ios::app);

	if (archivo.is_open()) {

		//Se comprueba si el archivo está vacío, en caso de estarlo, se añade el nombre de la columna.
		if (archivoVacio) {
			archivo << "cantante" << endl;
		}

		for (const string& nombre : lista_nombres) {
			archivo << nombre << endl;
		}
		archivo.close();
		cout << "Los nombres de los cantantes han sido registrados correctamente. " << endl;
	}
	else {
		cout << "Error al cargar los nombres de los cantantes. " << endl;
	}
}

int main() {
	vector<string> lista_nombres;

	while (true) {
		menu();

		int opcion;
		cin >> opcion;

		switch (opcion) {
		case 1: {
			string nombre;
			cout << "Ingrese el nombre del cantate: " << endl;
			cin.ignore();
			getline(cin, nombre);
			lista_nombres.push_back(nombre);
			break;
		}
		case 2: {
			guardarCantante(lista_nombres);
			return 0;
		}
		default:
			cout << "Opcion no valida, introduzca una opcion valida. " << endl;
		}
	}

	return 0;
}