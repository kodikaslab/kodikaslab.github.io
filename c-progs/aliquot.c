/*	File: aliquot.c

	Finds aliquot sequense terms of a given int for a given length.
	If the given length is 0 it finds all the terms.
	However, max term is limited to 1000000000000000.
	Prints the terms or just the length according to user input.
	Does not terminate in case of perfect number as 6.
	Does not terminate in case of amicable numbers as 220 and 284.
	Does not terminate in case of sociable numbers as 12496.

	Referrences
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

	unsigned long long term , next_term, i;
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
		for (i = 2 ; i * i < term ; i++)
			if (!(term % i)) 
				next_term += i + term / i;  // i is a term divisor. Add i and its sibling divisor term/i.
       	
		if (i * i == term)         // Checking if i^2 is a divisor of term.
			next_term += i;
				
	
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
