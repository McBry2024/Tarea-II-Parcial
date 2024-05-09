#include <iostream>
#include <string>

using namespace std;
// calcular automaticamente el promedio //

struct Estudiante {
	string id;
	string nombres;
	string apellidos;
	float notas[4];
	float promedio;
	string estado;
};
 
void verificarpromedio(Estudiante* estudiante) { 
	float suma = 0;
	for (int i = 0; i < 4; ++i) {
		suma += estudiante->notas[i];
	}

	estudiante->promedio = suma / 4;	
}

void verificarAprobacion(Estudiante* estudiante) {
	if (estudiante->promedio >= 60) {
		estudiante->estado = "Aprobado";
		} else {
			estudiante->estado = "Reprobado";
	}
}
int main() {
	int numEstudiantes;
	
	cout << "Ingrese la cantidad de estudiantes: ";
	cin >> numEstudiantes;
	
	Estudiante* estudiantes = new Estudiante[numEstudiantes];
	
	for (int i = 0; i < numEstudiantes; ++i) {
		cout << "Ingreses datos del estudiante " << i + i << ":" << endl;
		cout << "ID del estudiante: ";
		cin >> estudiantes [i].id;
		cout << "Nombres: ";
		cin >> estudiantes[i].nombres;
		cout << "Apellidos: ";
		cin >> estudiantes[i].apellidos ;
		cout << "Notas (nota1 nota2 nota3 nota4): ";
        for (int j = 0; j < 4; ++j) {
        	cin >> estudiantes[i].notas[j];
		}
	
	}
	
	cout << "\nResultados:" <<endl;
	for (int i = 0; i <numEstudiantes; ++i) {
		cout << "\nID " << estudiantes[i].id << endl;
		cout << "Nombres: " << estudiantes[i].nombres << endl;
		cout << "Apellidos: " << estudiantes[i].apellidos << endl;
		cout << "Promedio: " << estudiantes[i].promedio << endl;
		cout << "Estado: " << estudiantes[i].estado << endl;
	}
	
	delete[] estudiantes;
		
	return 0;
}

