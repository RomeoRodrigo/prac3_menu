#include <iostream>
#include <cctype>//permite convertir un caracter a minuscula o mayuscula. 
#include <sstream>//se usa para convertir numeros u otros datos en texto, o viceversa.
#include <cstring>//para poder utilizar la funcion strtok que divide la cadena

using namespace std;

// Función para realizar la suma de una cadena numérica
int sumaCadenaNumerica(string cadena) {
	int suma = 0;
	stringstream ss(cadena);
	string numero;
	
	while (getline(ss, numero, '+')) {
		suma += stoi(numero);
	}
	
	return suma;
}

void separarNombre(string nombreCompleto) {
	/*esta es la funcion strtok para separar el nombre y los apellidos.
	El primer parametro es la cadena que queremos dividir, y el segundo parametro
	es el delimitador que utilizaremos para separar la cadena.*/
	char *nombre = strtok(&nombreCompleto[0], " ");
	char *apellidoPaterno = strtok(NULL, " ");
	char *apellidoMaterno = strtok(NULL, " ");
	
	
	// Utilizamos la funcion toupper para convertir la primera letra del nombre en mayuscula.
	nombre[0] = toupper(nombre[0]);
	apellidoPaterno[0] = toupper(apellidoPaterno[0]);
	apellidoMaterno[0] = toupper(apellidoMaterno[0]);
	
	// Imprimimos el nombre completo en el orden que se nos ha pedido, con las primeras letras en mayuscula.
	cout << "Nombre completo: " << apellidoPaterno << " " << apellidoMaterno << "  " << nombre << endl;
}

// Función para ofuscar una palabra de las letras dadas en clases
string ofuscarPalabra(string palabra) {
	for (char &c : palabra) {
		switch (c) {
		case 'A':
		case 'a':
			c = '4';
			break;
		case 'E':
		case 'e':
			c = '3';
			break;
		case 'I':
		case 'i':
			c = '1';
			break;
		case 'O':
		case 'o':
			c = '0';
			break;
		case 'S':
		case 's':
			c = '5';
			break;
		case 'T':
		case 't':
			c = '7';
			break;
		default:
			break;
		}
	}
	
	return palabra;
}

// Función principal que contiene el menú
void menuPrincipal() {
	char opcion;
	
	do {
		cout << "Menu Principal" << endl;
		cout << "(1) - String suma de una cadena" << endl;
		cout << "(2) - String Nombre completo" << endl;
		cout << "(3) - String ofuscar" << endl;
		cout << "(s) - Salir" << endl;
		
		cout << "Ingrese la opción deseada: ";
		cin >> opcion;
		cin.ignore(); 
		
		switch (opcion) {
		case '1': {
			string cadenaNumerica;
			cout << "Ingrese la cadena numérica ej. 15+5+5: ";
			getline(cin, cadenaNumerica);
			int resultado = sumaCadenaNumerica(cadenaNumerica);
			cout << "Resultado: " << resultado << endl;
			break;
		}
		case '2': {
			string nombreCompleto;
			// Pedimos al usuario que ingrese su nombre completo.
			cout << "Por favor, ingrese su nombre completo: ";
			// Leemos el nombre completo del usuario.
			getline(cin, nombreCompleto);
			// Llamamos a la funcion separarNombre para separar el nombre y los apellidos.
			separarNombre(nombreCompleto);
			break;
		}
		case '3': {
			string palabra;
			cout << "Ingrese la palabra a ofuscar: ";
			getline(cin, palabra);
			string resultado = ofuscarPalabra(palabra);
			cout << "Palabra ofuscada: " << resultado << endl;
			break;
		}
		case 's':
		case 'S':
			cout << "Saliendo del programa." << endl;
			break;
		default:
			cout << "Opción no válida. Por favor, ingrese una opción válida." << endl;
			break;
		}
		
	} while (opcion != 's' && opcion != 'S');
}

int main() {
	// Llamar a la función principal que contiene el menú
	menuPrincipal();
	
	return 0;
}
