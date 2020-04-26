#include <iostream>
#include<math.h>

int main()
{
    double A[3][3] = { 1,2,3,
                       2,4,5,
                       3,5,-1 };

    double x[3] = { 1,1,1 };
    double z[3] = { 0,0,0 };
    double lambda = 0;
    double temp = 0;
    double eps = 10e-8;
    int iteracje = 0;

   do {
       iteracje++;
        for (int i = 0; i < 3; i++) {
           z[i] = 0; 
           for (int j = 0; j < 3; j++) {
                
                z[i] += A[i][j] * x[j];
            }
        }
        temp = lambda;

        lambda = fabs(z[0]);
        for (int i = 1; i < 3; i++) {
            if (fabs(z[i]) > lambda)
                lambda = fabs(z[i]);
        }

        for (int i = 0; i < 3; i++) {
            z[i] = z[i] / lambda;
        }


        for (int i = 0; i < 3; i++) {
            x[i] = z[i];
        }

   } while (fabs(lambda - temp)>eps);

     printf("lambda_Rayleigha: %.9f \n", lambda_Rayleigha);
     printf("iteracje: %d \n", iteracje);
 
    return 0;
}

