/* Summation of Primes
 * Problem 10:
 * The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17;
 * Find the sum of all the primes below two million.
*/

#include <stdio.h>
#include <stdbool.h>
#include <inttypes.h>

bool isPrime(int n)
{
    for(int i = 2; i <= n / 2; i++)
    {
        if(n % i == 0)
            return false;
    }
    return true;
}
uint64_t findSumBelow_n(uint64_t n)
{
    uint64_t sum = 0;
    for(uint64_t i = 0; i < n; i++)
    {
        if(isPrime(i) == true)
            sum += i;
    }
    return sum;
}
int main()
{
    uint64_t n = 2000000;
    printf("Sum of primes below ");
    printf("%" PRIu64 "\n", n);
    printf("Sum : %"PRId64 "\n", findSumBelow_n(n));
}