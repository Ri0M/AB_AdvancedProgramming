#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	const string df = "C:\\Users\\USUARIO\\Desktop\\SpotifyData_ML.csv";

	ifstream archivo(df);

	if (!archivo.is_open()) {
		cerr << "No se pudo abrir el archivo" << endl;
		return 1;
	}

	for (int i = 0; i < 5; i++) {
		string linea;
		getline(archivo, linea);
		cout << linea << endl;
	}

	archivo.close();
	return 0;
}