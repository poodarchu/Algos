#include <iostream>
#include "primality.h"

int main()
{
	int n = 0;
	while (true) {
		++n;
		if (n>=100) break;
		std::cout<<n<<"\n";
		int i = is_prime(n);
		if (i)
			std::cout<<"is prime\n";
		else
			std::cout<<"not prime\n";
		i = is_exact_prime(n);
		if (i)
			std::cout<<"exactly is prime\n";
		else
			std::cout<<"exactly not prime\n";
		}
	return 0;
}