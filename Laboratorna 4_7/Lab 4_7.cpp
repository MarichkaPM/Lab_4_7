#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
	double xp, xk, x, dx, eps, R = 0, a = 0, S = 0;
	double Pi = 4 * atan(1.0);
	int n = 0;
	cout << "xp = "; cin >> xp;
	cout << "xk = "; cin >> xk;
	cout << "dx = "; cin >> dx;
	cout << "eps = "; cin >> eps;
	cout << fixed;
	cout << "-----------------------------------------" << endl;
	cout << "|" << setw(5) << "x" << setw(4) << " |"
		<< setw(10) << "acos(x)" << " |"
		<< setw(7) << "S" <<setw(5)<< " |"
		<< setw(4) << "n" << setw(3)<<" |"
		<< endl;
	cout << "-----------------------------------------" << endl;
	x = xp;
	if (-1 < x && x < 1)
	{
		while (x <= xk)
		{
			n = 1;
			a = (x * x * x) / (2 * 3);
			S = a;
			do {
				n++;
				R = ((1.0 * (2 * n - 1) / (2 * n)) * (1.0 * (2 * n - 1) / (2 * n + 1)) * x * x);
				//R = (1.0*(2 * n - 1) / (2 * n + 1)) * x * x * (1.0*(2 * n - 2) * (2 * n - 1)) /(1.0*(2 * n * (2 * n - 3)));
				a *= R;
				S += a;
			} while (abs(a) >= eps);

			double result = Pi / 2.0 - (x + S);
			cout << "|" << setw(7) << setprecision(2) << x << " |"
				<< setw(10) << setprecision(5) << acos(x) << " |"
				<< setw(10) << setprecision(5) << result << " |"
				<< setw(5) << n << " |"
				<< endl;
			x += dx;
		}
	}
	else
	{
		cout << "\tNon correct meaning of x" << setw(9) << "|" << endl <<
			"\tx need to be - 1 < x && x < 1 " << setw(3) << "|" << endl;
	}
		cout << "-----------------------------------------" << endl;
	

	return 0;
}
