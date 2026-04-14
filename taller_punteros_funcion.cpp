#include <iostream>
#include <windows.h>
using namespace std;

double cuadrado(double x) {
    return x * x;
}

double doble(double x) {
    return 2 * x;
}

double inverso(double x) {
    if (x == 0) {
        cout << "  Error: el inverso de 0 no existe." << endl;
        return 0;
    }
    return 1.0 / x;
}

void aplicarFuncion(double* arr, int n, double (*func)(double), const char* nombre) {
    cout << "\n  Aplicando: " << nombre << endl;
    cout << "  ";
    for (int i = 0; i < n; i++) {
        double resultado = func(*(arr + i));
        cout.precision(4);
        cout << "[" << *(arr + i) << " -> " << resultado << "]";
        if (i < n - 1) cout << "  ";
    }
    cout << endl;
}

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    cout << "╔═══════════════════════════════════════════════════╗" << endl;
    cout << "║  TALLER DE PUNTEROS  ·  Funciones como Parámetros ║" << endl;
    cout << "╚═══════════════════════════════════════════════════╝" << endl;

    int n;
    cout << "\n¿Cuántos elementos tiene el arreglo? ";
    cin >> n;

    double* arr = new double[n];

    cout << "Ingresa los " << n << " valores (pueden ser decimales):\n";
    for (int i = 0; i < n; i++) {
        cout << "  arr[" << i << "] = ";
        cin >> *(arr + i);
    }

    cout << "\nArreglo original: [ ";
    for (int i = 0; i < n; i++) {
        cout << *(arr + i);
        if (i < n - 1) cout << ", ";
    }
    cout << " ]" << endl;

    double (*pCuadrado)(double) = cuadrado;
    double (*pDoble)(double)    = doble;
    double (*pInverso)(double)  = inverso;

    int opcion;
    bool continuar = true;

    while (continuar) {
        cout << "\n¿Qué función deseas aplicar?" << endl;
        cout << "  1. Cuadrado  (x²)" << endl;
        cout << "  2. Doble     (2x)" << endl;
        cout << "  3. Inverso   (1/x)" << endl;
        cout << "  0. Salir" << endl;
        cout << "Opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                aplicarFuncion(arr, n, pCuadrado, "cuadrado(x) = x²");
                break;
            case 2:
                aplicarFuncion(arr, n, pDoble, "doble(x) = 2x");
                break;
            case 3:
                aplicarFuncion(arr, n, pInverso, "inverso(x) = 1/x");
                break;
            case 0:
                continuar = false;
                break;
            default:
                cout << "  Opción no válida. Ingresa 0, 1, 2 o 3." << endl;
        }
    }

    delete[] arr;

    cout << "\nPrograma finalizado." << endl;

    return 0;
}
