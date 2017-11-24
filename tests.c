#include "tests.h"
#include "main.h"

#include <stdio.h>

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
        printf("Blad funkcji oblicz_delta, delta = %lf\n", delta);
    }

    delta = oblicz_delta(6.0, -8.0, -2.6);
    if (delta != 126.4) {
        printf("Blad funkcji oblicz_delta, delta = %lf\n", delta);
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
