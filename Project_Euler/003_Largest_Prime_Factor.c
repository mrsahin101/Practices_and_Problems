/* Largest Prime Factor
 * Problem 3:
 * The prime factors of 13195 are 5, 7, 13 and 29.
 * What is the largest prime factor of the number 600851475143
*/
#include <stdio.h>
#include <inttypes.h>

uint64_t findLargestPrimeFactor(uint64_t number)
{
    uint64_t largest_prime_factor = 0;
    uint64_t divisor = 2;

    while(divisor <= number)
    {
        if(number % divisor == 0)
        {
            largest_prime_factor = divisor;
            number = number / divisor;
        }
        else
            divisor = divisor + 1;
    }
    return largest_prime_factor;
}
int main()
{
    uint64_t t = 600851475143;
    printf("%" PRId64 "\n", t);
    printf("%" PRId64 "\n", findLargestPrimeFactor(t));
}
