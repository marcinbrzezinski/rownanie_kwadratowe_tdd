#include <stdio.h>
#include <math.h>

void test_oblicz_rownanie_kwadratowe();

void test_oblicz_rodzaj_rw_kw();

void test_oblicz_delta();

void test_oblicz_pierwiastek1();

void test_oblicz_pierwiastek2();

double oblicz_delta(double a, double b, double c);

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

void test_oblicz_pierwiastek2() {
    double pierwiastek;

    pierwiastek = oblicz_pierwiastek2(2.0, 4.0, 6.0);
    if (pierwiastek != (0.0)) {
        printf("Blad funkcji oblicz_pierwiastek1, pierwiastek = %lf\n", pierwiastek);
    }

    pierwiastek = oblicz_pierwiastek2(5.0, 16.0, 3.0);
    if (pierwiastek != (-1.0 / 6.0)) {
        printf("Blad funkcji oblicz_pierwiastek1, pierwiastek = %lf\n", pierwiastek);
    }
}

void test_oblicz_pierwiastek1() {
    double pierwiastek;

    pierwiastek = oblicz_pierwiastek1(2.0, 4.0, 6.0);
    if (pierwiastek != (-4.0 / 12.0)) {
        printf("Blad funkcji oblicz_pierwiastek1, pierwiastek = %lf\n", pierwiastek);
    }

    pierwiastek = oblicz_pierwiastek1(5.0, 16.0, 3.0);
    if (pierwiastek != (-9.0 / 6.0)) {
        printf("Blad funkcji oblicz_pierwiastek1, pierwiastek = %lf\n", pierwiastek);
    }
}

void test_oblicz_delta() {
    double delta;

    delta = oblicz_delta(2.0, -5.0, 2.0);
    if (delta != 9.0) {
        printf("Blad funkcji oblicz_delta, delta = %lf", delta);
    }

    delta = oblicz_delta(6.0, -8.0, -2.6);
    if (delta != 126.4) {
        printf("Blad funkcji oblicz_delta, delta = %lf", delta);
    }

}

void test_oblicz_rodzaj_rw_kw() {
    int rodzaj;

    rodzaj = oblicz_rodzaj_rw_kw(2.0, -5.0, 2.0);
    if (rodzaj != 2) {
        printf("Blad funkcji oblicz_rodzaj_rw_kw, powinien byc 2\n");
    }

    rodzaj = oblicz_rodzaj_rw_kw(1.0, 0.0, 5.0);
    if (rodzaj != 0) {
        printf("Blad funkcji oblicz_rodzaj_rw_kw, powinien byc 0\n");
    }

    rodzaj = oblicz_rodzaj_rw_kw(1.0, 0.0, -5.0);
    if (rodzaj != 2) {
        printf("Blad funkcji oblicz_rodzaj_rw_kw, powinien byc 2\n");
    }

    rodzaj = oblicz_rodzaj_rw_kw(1.0, 0.0, 0.0);
    if (rodzaj != 1) {
        printf("Blad funkcji oblicz_rodzaj_rw_kw, powinien byc 1\n");
    }
}

void test_oblicz_rownanie_kwadratowe() {
    double x1, x2;
    int rodzaj;

    oblicz_rownanie_kw(2.0, -5.0, 2.0, &x1, &x2, &rodzaj);
    if (x1 != 0.5) {
        printf("Niepoprawny wynik x1, %lf\n", x1);
    }
    if (x2 != 2.0) {
        printf("Niepoprawny wynik x2, %lf\n", x2);
    }
    if (rodzaj != 2) {
        printf("Niepoprawny rodzaj\n");
    }
}