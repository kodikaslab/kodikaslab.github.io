# C code (C kodikas)

* TOC
{:toc}

## Finds aliquot sequence terms
```c
/*	File: aliquot.c

	Finds aliquot sequence terms of a given int for a given length.
	If the given length is 0 it finds all the terms.
	However, max term is limited to 1000000000000000.
	Prints the terms or just the length according to user input.
	Does not terminate in case of perfect number as 6.
	Does not terminate in case of amicable numbers as 220 and 284.
	Does not terminate in case of sociable numbers as 12496.

	References
	-----------
	Aliquot sequence: https://en.wikipedia.org/wiki/Aliquot_sequence
	Perfect numbers: https://en.wikipedia.org/wiki/Perfect_number
	Amicable numbers: https://en.wikipedia.org/wiki/Amicable_numbers
	Sociable numbers: https://en.wikipedia.org/wiki/Sociable_number
	
*/

#include <stdio.h>

#define MAX_NUM 1000000000000000	// Max term.

int main(void)
{

	unsigned long long term , next_term, i, temp , p, s;
	int max_l , l = 0;
	char choise;

	printf("Please give the number to start the aliquot sequence from: ");
	scanf("%llu", &term);
	printf("Provide the max aliquot length to look for (0 for unlimited): ");
	scanf("%d", &max_l);
	printf("Do you want to print the full sequence ('f') or just the length ('l')? ");
	getchar();
	choise = getchar();	
	
	// Find next term as sum of term divisors.
	while (term > 0 && (!max_l || l < max_l) ) {
		next_term  = 1;
		temp = term;
		
		// Use prime factorization to find the sum o divisors
		// Find the prime factorization of term
		// Calculate the geometric sum for each prime
		// The sum of divisors equals with the gemetr. sum - term
		p = s = 1;
		while (!(temp % 2)) {	// First check if 2 is prime factor and calculate geom. series
			p *= 2;
			s += p;
			temp /= 2;		
		}
		next_term *= s;
		
		p = s = 1;
		while (!(temp % 3)) {	// Then check if 3 is prime factor and calculate geom. series
			p *= 3;
			s += p;
			temp /= 3;			
		}
		next_term *= s;
		
		for (i = 5 ; i * i  <= temp  ; i += 6 ) { // Then 5 and 7 and so on, adding 6
       			p = s = 1;	
			while (!(temp % i)) {
				p *= i;
				s += p;
				temp /= i;			
			}
			next_term *= s;

       			p = s = 1;	
			while (!(temp % (i + 2))) {
				p *= i + 2;
				s += p;
				temp /= i + 2;			
			}	
			next_term *= s;

		}
		if (temp > 1)				// Take into consideration a possible remainder
			next_term *= (1 + temp);	
		next_term -= term;			// Calculates the sum of divisors
	
		if (choise == 'f')
			printf("%llu\n", term);
		term = term > 1 ? next_term : 0;
		l++;
		
		if (term > MAX_NUM){                   // Checking if term surpassed max limi term.
			printf("%llu\n", term);
			printf("Number exceeds maximum supported integer (%llu). Stopping.\n", MAX_NUM);
			return 1;
		}
	}

	
	if (choise == 'l')
		printf("Length of aliquot sequence: %d\n", l);
	else
		printf("%llu\n", term);

	return 0;
}
```

## Finds Greatest Common Divisor (GCD) & Least Common Multiple (LCM)
```c
/*      Finds Greatest Common Divisor (GCD) & Least Common Multiple (LCM)
        of a pair of positive integers entered by the user,
        using the Euclidean algorith

        Eucleides: https://en.wikipedia.org/wiki/Eucleides
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
```
