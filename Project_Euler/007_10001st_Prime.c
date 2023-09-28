/* 10001st Prime
 * Problem 7:
 * By listing the first six prime numbers : 2, 3, 5, 7, 11 and 13. We can see that the 6th prime is 13.
 * What is the 10001st prime Number?
*/
#include <stdio.h>
#include <stdbool.h>
#include <inttypes.h>

// #define DESIRED_INDEX       10001
#define DESIRED_INDEX      100000
bool isPrime(int n)
{
    for(int i = 2; i <= n / 2; i++)
    {
        if(n % i == 0)
            return false;
    }
    return true;
}

uint64_t find10001stPrime()
{
    uint32_t counter = 0;

    for(uint64_t i = 2; ;i++)
    {
        if(isPrime(i))
            counter++;
        if(counter == DESIRED_INDEX)
        {
            return i;
        }
    }
}
int main()
{
    printf("%dth prime number is : ", DESIRED_INDEX);
    printf("%" PRIu64 "\n", find10001stPrime());
}