#include <bits/stdc++.h>
using namespace std;
void primeFactors(int n)
{

	// n must be odd at this point. So we can skip
	// one element (Note i = i +2)
	for (int i = 3; i <= sqrt(n); i = i + 2)
	{
		while (n % i == 0)
		{
			cout << i << " ";
			n = n/i;
		}
	}

	// This condition is to handle the case when n
	// is a prime number greater than 2
	if (n > 2)
		cout << n << " ";
}

/* Driver code */
int main()
{
	long long int n = 1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000726;
	primeFactors(n);
	return 0;
}

// This is code is contributed by rathbhupendra
//