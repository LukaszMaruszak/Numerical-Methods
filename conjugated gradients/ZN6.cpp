#include <iostream>

using namespace std;
int main()
{

	double A[3][3] = { 4, -1, 0,
					  -1, 4, -1,
					   0, -1, 4 };

	double b[3] = { 2, 6 , 2 };
	double x[3] = { 0,0,0 };
	double r[3] = { 2,6,2 };
	double p[3] = { 2,6,2 };
	double rr[3];	
	double pp[3];
	double alfa;
	double beta;
	
	int t = 1;
	int T = 2;

	//wykonuje obliczenia interacyjnie o zadana ilosc razy
	while (t <= T) {
		
		alfa = (r[0] * r[0] + r[1] * r[1] + r[2] * r[2]) /
			((p[0] * A[0][0] + p[1] * A[0][1] + p[2] * A[0][2]) * p[0] + 
			(p[0] * A[1][0] + p[1] * A[1][1] + p[2] * A[1][2]) * p[1] + 
			(p[0] * A[2][0] + p[1] * A[2][1] + p[2] * A[2][2]) * p[2]);

		for (int i = 0; i < 3; i++) {
			x[i] = x[i] + alfa * p[i];
		}

		for (int i = 0; i < 3; i++) {
			rr[i] = r[i] - ((A[0][i] * p[0] + A[1][i] * p[1] + A[2][i] * p[2]) * alfa);
		}

		beta = (rr[0] * rr[0] + rr[1] * rr[1] + rr[2] * rr[2]) / 
			(r[0] * r[0] + r[1] * r[1] + r[2] * r[2]);

		for (int i = 0; i < 3; i++) {
			p[i] = rr[i] + beta * p[i];
					
			r[i] = rr[i];
		}


		t++;
		}

for (int i = 0; i < 3; i++) {
			cout << x[i] << endl;

		}
return 0;
}


