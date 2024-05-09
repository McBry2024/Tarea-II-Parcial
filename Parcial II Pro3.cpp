#include <iostream>
#include <ofstream>
#include <string>


using namespace std;
// realizar El CRUD


const string FILENAME = "notas.dat";

struct Estudiante {
	
	string id;
	string nombres;
	string apellidos;
	float notas[4];
	float promedio;
	string resultado;
};

// funcion para agregar un estudiante al archivo
void agregarEstudiante() {
	ofstream archivo(FILENAME, ios::binary | ios::app);
	if (!archivo) {
		cout << "Error al abrir el archivo." << endl;
		return;
	}
	
	Estudiante estudiante;
	
	cout << "Ingrese el ID del estudiante: ";
	cin >> estudiante.id;
	cout << "Ingrese los nombres del estudiante: ";
	cin >> estudiante.nombres;
	cout << "Ingrese apellidos del estudiante: ";
    cin >> estudiante.apellidos;
	cout << "Ingrese las notas del estudiante (nota1 nota2 nota3 nota4): ";
	for (int i = 0; i < 4; ++i) {
		cin >> estudiante.notas[i];
	}
    // Calcular promedio
    float suma = 0;
    for (int i = 0; i < 4; ++i) {
		suma += estudiante.notas[i];
	}
	estudiante.promedio = / 4;
	
	// Verificar aprobacion
	estudiante.resultado =(estudiante.promedio >=60) ? "Aprobado" : "Reprobado"	;
	
	archivo.write(reinterpret_cast<char*>(&estudiante), sizeof(Estudiante));
	
	archivo.close();
	
	cout << "Estudiante agregado correctamente." << endl;
}

// Funcion para leer todos los estudiantes del archivo
void mostrarEstudiantes() {
	ifstream archivo(FILENAME, ios::binary);
	if (!archivo) {
		cout <<"Error al abrir archivo." << endl;
		return;
	}


	Estudiante estudiante;
	
	cout <<"\nListado de estudiantes:\n";
	while (archivo.read(reinterpret_cast<char*>(&estudiante), sizeof(Estudiante);
		cout << "ID: " << estudiante.id << endl;
		cout << "Nombres: " << estudiante.nombres << endl;
		cout << "Apellidos: " << estudiante.apellidos << endl;
		cout << "Promedio: " << estudiante.promedio << endl;
		cout << "Resultado: " << estudiante.resultado << endl;
		cout << endl;
	}
	
	archivo.close();
}

int main(){
	int opcion;
	
	do {
		
		cout << "\nMenu:\n";
		cout << "1. Agregar estudiante\n";
		cout << "2. Mostrar estudiantes\n";
		cout << "3. Salir\n";
		cout << "Ingrese su opcion: ";
		cin >> opcion;
		
		switch (opcion) {
			case 1:
				agregarEstudiante();
				break;
			case 2:
				mostrarEstudiante();
				break;
			case 3:
				cout << "Saliendo del programa...\n";
				break;
			default:
				cout << "Opcion no valida. Intente de nuevo.\n";
				break;
		}
	}while (opcion !=3);
	
	return 0;
} 

