#include <stdio.h>

double pi(double eps);

int main() {

	printf("for eps 0.0001-> %.12lf\n", pi(0.0001));
	printf("for eps 0.0000001-> %.12lf\n", pi(0.0000001));
	printf("for eps 0.0000000001-> %.12lf\n", pi(0.0000000001));

}


double pi(double eps) {

	int i = 1;
	double api = 0.0;
	long long n = (2.0-eps)/eps; // calculated from equation for epsilon
	while (i<n) {
		if (i % 2 == 0) {  // case for even numbers
			api -= 4.0/((2.0*i)-1.0);
		}
		else if (i%2 == 1) {  // case for odd numbers
			api += 4.0/((2.0*i)-1.0);
		}
		i++;
	}

	return api;

}
