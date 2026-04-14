/*
 * TALLER DE PUNTEROS — Matrices Dinámicas
 * Este programa:
 *   1. Crea una matriz dinámica n×m con puntero doble (int**)
 *   2. La llena con valores del usuario
 *   3. Calcula suma por filas usando aritmética de punteros
 *   4. Encuentra el mayor elemento con un puntero explorador
 *   5. Transpone la matriz (nueva en el heap, más drama)
 */

#include <iostream>
#include <windows.h>
using namespace std;

// Función 1: Suma de cada fila
// Usa puntero *(*(mat+i)+j) para recorrer

void sumaFilas(int** mat, int n, int m) {
    cout << "\n=== SUMA POR FILAS ===" << endl;
    cout << "// int* ptr = *(mat+i); — apuntando a cada fila" << endl;

    for (int i = 0; i < n; i++) {
        int suma = 0;
        int* ptr = *(mat + i);           // puntero a la fila i

        for (int j = 0; j < m; j++) {
            suma += *(ptr + j);          // aritmética de punteros pura
        }

        cout << "  Fila " << i << ": suma = " << suma << endl;
    }
}


// Función 2: Mayor elemento
// Un puntero que recorre TODO buscando la gloria

void mayorElemento(int** mat, int n, int m) {
    cout << "\n=== MAYOR ELEMENTO ===" << endl;
    cout << "// int* maxPtr = &mat[0][0]; — el punto de partida" << endl;

    int* maxPtr = *(mat + 0) + 0;       // apunta a mat[0][0]
    int maxFila = 0, maxCol = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int* actual = *(mat + i) + j;
            if (*actual > *maxPtr) {
                maxPtr = actual;        // el puntero asciende socialmente
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


// Función 3: Transponer (nueva matriz en el heap)
// Si crees que el heap ya sufrió bastante... sorpresa

int** transponerMatriz(int** mat, int n, int m) {
    cout << "\n=== TRANSPUESTA ===" << endl;
    cout << "// int** T = new int*[" << m << "]; — más peticiones al heap" << endl;

    int** T = new int*[m];              // T tiene m filas (antes columnas)
    for (int j = 0; j < m; j++) {
        T[j] = new int[n];             // cada fila tiene n columnas (antes filas)
        for (int i = 0; i < n; i++) {
            *(*(T + j) + i) = *(*(mat + i) + j);  // T[j][i] = mat[i][j]
        }
    }

    // Mostrar la transpuesta
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

// Función para liberar memoria
// "Hasta nunca, heap. Fue un honor fugar contigo."

void liberarMatriz(int** mat, int filas) {
    for (int i = 0; i < filas; i++)
        delete[] *(mat + i);            // libera cada fila
    delete[] mat;                       // libera el arreglo de punteros
}

// MAIN

int main() {
    // ── Configurar consola para UTF-8
    SetConsoleOutputCP(65001);          // salida en UTF-8 (caracteres especiales)
    SetConsoleCP(65001);                // entrada  en UTF-8

    cout << "╔══════════════════════════════════════════════╗" << endl;
    cout << "║   TALLER DE PUNTEROS  ·  Matrices Dinámicas ║" << endl;
    cout << "║                'Soy un int**.'              ║" << endl;
    cout << "╚══════════════════════════════════════════════╝" << endl;

    int n, m;

    // Leer dimensiones
    cout << "\n¿Cuántas filas (n)? ";
    cin >> n;
    cout << "¿Cuántas columnas (m)? ";
    cin >> m;

    // Crear matriz dinámica 
    // int** mat → puntero a un arreglo de punteros a int
    int** mat = new int*[n];            // arreglo de n punteros
    for (int i = 0; i < n; i++) {
        *(mat + i) = new int[m];        // cada puntero apunta a una fila de m ints
    }

    // Llenar la matriz
    cout << "\nIngresa los " << n * m << " valores:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << "  mat[" << i << "][" << j << "] = ";
            cin >> *(*(mat + i) + j);   // equivalente a mat[i][j]
        }
    }

    // Mostrar la matriz original
    cout << "\nMatriz ingresada [" << n << "x" << m << "]:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "  ";
        for (int j = 0; j < m; j++) {
            cout.width(5);
            cout << *(*(mat + i) + j);
        }
        cout << endl;
    }

    // Operaciones 
    sumaFilas(mat, n, m);
    mayorElemento(mat, n, m);
    int** transpuesta = transponerMatriz(mat, n, m);

    // Liberar memoria 
    cout << "\n// delete[][] mat; delete[][] transpuesta;" << endl;
    cout << "// El heap respira. Todo pasa." << endl;

    liberarMatriz(mat, n);
    liberarMatriz(transpuesta, m);

    cout << "\nPrograma finalizado. Nadie resultó herido." << endl;

    return 0;
}