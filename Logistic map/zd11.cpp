#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <fstream>

using namespace std;
double odwzorowanie(double x, double k) {
    return k * x * (1 - x);
}

int main()
{
    fstream plik;
    plik.open("zad11.txt", ios::out);
    plik.precision(6);
    int n;
    //punkt poczatkowy z przedzialu (0,1)
    double x = 0.1;
 
    for (double k = 2; k <= 4; k+=0.002) {
        n = 100;

        while (n < 700) {
            x = odwzorowanie(x, k);
             plik << k << " " << x <<endl;
            n++;
        }
    }
   plik.close();
    return 0;
}
