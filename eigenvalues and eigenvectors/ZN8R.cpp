#include <iostream>
#include<math.h>

int main()
{
    double A[3][3] = { 1,2,3,
        2,4,5,
        3,5,-1 };

    double x[3] = { 1,1,1 };
    double z[3] = { 0,0,0 };
    double temp = 0;
    double eps = 10e-8;
    int iteracje = 0;
    double lambda_Rayleigha = 0;
    double licznik = 0;
    double mianownik = 0;
    double s[3];
    double t;
    do {

        iteracje++;
        for (int i = 0; i < 3; i++) {
            z[i] = 0;
            for (int j = 0; j < 3; j++) {

                z[i] += A[i][j] * x[j];
            }
        }

        t = fabs(z[0]);
        for (int i = 1; i < 3; i++) {
            if (fabs(z[i]) > t)
                t = fabs(z[i]);
        }

        for (int i = 0; i < 3; i++) {
            z[i] = z[i] / t;
        }

        for (int i = 0; i < 3; i++) {
            x[i] = z[i];
        }
        for (int i = 0; i < 3; i++) {
            s[i] = 0;
        }

        for (int i = 0; i < 3; i++) {

            for (int j = 0; j < 3; j++) {

                s[i] += A[i][j] * x[j];
            }
        }

        licznik = 0;

        for (int i = 0; i < 3; i++) {
            licznik += s[i] * x[i];
        }

        double mianownik = 0;

        for (int i = 0; i < 3; i++) {
            mianownik += x[i] * x[i];
        }
        temp = lambda_Rayleigha;
        lambda_Rayleigha = licznik / mianownik;


    } while (fabs(lambda_Rayleigha - temp) > eps);

    printf("lambda: %.9f \n", lambda_Rayleigha);
    printf("iteracje: %d \n", iteracje);

    return 0;
}