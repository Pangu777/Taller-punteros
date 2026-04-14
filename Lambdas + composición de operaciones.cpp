#include <iostream>
#include <functional>
#include <vector>
using namespace std;

// Aplica varias transformaciones a un valor

double aplicarTransformaciones(double x,
    const vector<function<double(double)>>& funcs) {

    for (size_t i = 0; i < funcs.size(); i++) {
        x = funcs[i](x);
    }
    return x;
}

double procesar(double* arr, int n,
    const vector<function<double(double)>>& transformaciones,
    function<double(double, double)> combinar) {

    double resultado = aplicarTransformaciones(arr[0], transformaciones);

    for (int i = 1; i < n; i++) {
        double valor = aplicarTransformaciones(arr[i], transformaciones);
        resultado = combinar(resultado, valor);
    }

    return resultado;
}

int main() {
    int n = 3;
    double* arr = new double[n]{1, 2, 3};

    vector<function<double(double)>> transformaciones;

    transformaciones.push_back([](double x) { return x * 2; });
    transformaciones.push_back([](double x) { return x + 3; });
    transformaciones.push_back([](double x) { return x * x; });

    function<double(double, double)> combinar = [](double a, double b) {
        return a + b;
    };

    double resultado = procesar(arr, n, transformaciones, combinar);

    cout << "Resultado final: " << resultado << endl;

    delete[] arr;
    return 0;
}