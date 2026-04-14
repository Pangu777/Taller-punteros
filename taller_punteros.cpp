#include <iostream>
#include <windows.h>
using namespace std;

void sumaFilas(int** mat, int n, int m) {
    cout << "\n=== SUMA POR FILAS ===" << endl;
    cout << "// int* ptr = *(mat+i); — apuntando a cada fila" << endl;

    for (int i = 0; i < n; i++) {
        int suma = 0;
        int* ptr = *(mat + i);

        for (int j = 0; j < m; j++) {
            suma += *(ptr + j);
        }

        cout << "  Fila " << i << ": suma = " << suma << endl;
    }
}

void mayorElemento(int** mat, int n, int m) {
    cout << "\n=== MAYOR ELEMENTO ===" << endl;
    cout << "// int* maxPtr = &mat[0][0]; — el punto de partida" << endl;

    int* maxPtr = *(mat + 0) + 0;
    int maxFila = 0, maxCol = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int* actual = *(mat + i) + j;
            if (*actual > *maxPtr) {
                maxPtr = actual;
                maxFila = i;
                maxCol = j;
            }
        }
    }

    cout << "  Mayor valor: " << *maxPtr
         << "  en mat[" << maxFila << "][" << maxCol << "]" << endl;
    cout << "  // *maxPtr apunta a " << *maxPtr
         << ". Su momento de gloria." << endl;
}

int** transponerMatriz(int** mat, int n, int m) {
    cout << "\n=== TRANSPUESTA ===" << endl;
    cout << "// int** T = new int*[" << m << "]; — más peticiones al heap" << endl;

    int** T = new int*[m];
    for (int j = 0; j < m; j++) {
        T[j] = new int[n];
        for (int i = 0; i < n; i++) {
            *(*(T + j) + i) = *(*(mat + i) + j);
        }
    }

    cout << "\n  Matriz transpuesta [" << m << "x" << n << "]:" << endl;
    for (int j = 0; j < m; j++) {
        cout << "  ";
        for (int i = 0; i < n; i++) {
            cout.width(5);
            cout << *(*(T + j) + i);
        }
        cout << endl;
    }

    return T;
}

void liberarMatriz(int** mat, int filas) {
    for (int i = 0; i < filas; i++)
        delete[] *(mat + i);
    delete[] mat;
}

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    cout << "╔══════════════════════════════════════════════╗" << endl;
    cout << "║   TALLER DE PUNTEROS  ·  Matrices Dinámicas ║" << endl;
    cout << "║                'Soy un int**.'              ║" << endl;
    cout << "╚══════════════════════════════════════════════╝" << endl;

    int n, m;

    cout << "\n¿Cuántas filas (n)? ";
    cin >> n;
    cout << "¿Cuántas columnas (m)? ";
    cin >> m;

    int** mat = new int*[n];
    for (int i = 0; i < n; i++) {
        *(mat + i) = new int[m];
    }

    cout << "\nIngresa los " << n * m << " valores:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << "  mat[" << i << "][" << j << "] = ";
            cin >> *(*(mat + i) + j);
        }
    }
    
    cout << "\nMatriz ingresada [" << n << "x" << m << "]:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "  ";
        for (int j = 0; j < m; j++) {
            cout.width(5);
            cout << *(*(mat + i) + j);
        }
        cout << endl;
    }

    sumaFilas(mat, n, m);
    mayorElemento(mat, n, m);
    int** transpuesta = transponerMatriz(mat, n, m);

    cout << "\n// delete[][] mat; delete[][] transpuesta;" << endl;
    cout << "// El heap respira. Todo pasa." << endl;

    liberarMatriz(mat, n);
    liberarMatriz(transpuesta, m);

    cout << "\nPrograma finalizado. Nadie resultó herido." << endl;

    return 0;
}
