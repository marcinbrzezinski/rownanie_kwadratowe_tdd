#include <math.h>
#include "tests.h"
#include "main.h"

double oblicz_pierwiastek1(double b, double delta, double a) {
    return ((-b - sqrt(delta)) / (2 * a));
}

double oblicz_pierwiastek2(double b, double delta, double a) {
    return ((-b + sqrt(delta)) / (2 * a));
}

void oblicz_rownanie_kw(double a, double b, double c, double *x1, double *x2, int *rodzaj) {
    *rodzaj = oblicz_rodzaj_rw_kw(a, b, c);

    *x1 = oblicz_pierwiastek1(b, oblicz_delta(a, b, c), a);
    *x2 = oblicz_pierwiastek2(b, oblicz_delta(a, b, c), a);
}

double oblicz_delta(double a, double b, double c) {
    return b * b - 4 * a * c;
}

int oblicz_rodzaj_rw_kw(double a, double b, double c) {

    double delta;

    delta = oblicz_delta(a, b, c);

    if (delta > 0.0) {
        return 2;
    } else if (delta < 0.0) {
        return 0;
    } else {
        return 1;
    }
}

int main() {
    test_oblicz_rownanie_kwadratowe();
    test_oblicz_rodzaj_rw_kw();
    test_oblicz_delta();
    test_oblicz_pierwiastek1();
    test_oblicz_pierwiastek2();
}
