/*	File: gcdlcm.c
	
	Finds Greatest Common Divisor (GCD) & Least Common Multiple (LCM)
	of a pair of positive integers entered by the user, 
	using the Euclidean algorith

	Euclid: https://en.wikipedia.org/wiki/Euclid
*/

#include <stdio.h>

int main(void)
{
	int x , y , max , min , rmder;

	printf("Enter the first integer: ");
	scanf("%d" , &x);
	printf("Enter the second integer: ");
	scanf("%d" , &y);

	max = x > y ? x : y;
	min = x <= y ? x : y;

	// Euclidean algorithm

	while (min) {
		rmder = max % min;
		max = min;
		min = rmder;
	}

	printf("The GCD of %d and %d is %d.\n", x , y , max);
	printf("The LCM of %d and %d is %d.\n", x , y , x * y / max);

	return 0;
}
