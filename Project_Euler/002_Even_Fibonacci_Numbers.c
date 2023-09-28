/* Even Fibonacci Numbers
 * Problem 2:
 * Each new term in Fibonacci sequence is generated by adding the previous two terms. By starting with 1 and 2
 * 10 terms will be :
 * 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...
 * By considering the terms in the Fibonacci sequence whose values do not exceed four million, find the sum of the even valued terms
 *
*/

#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

uint64_t evenFibonacciCalculator(uint32_t uppercap)
{
    uint64_t sum;
    uint32_t previousnumber = 1;
    for(int i = 2; i < uppercap; i += previousnumber)
    {
        if(i % 2 == 0)
            sum += i;
    }
    return sum;
}

int main()
{
    printf("%" PRIu64 "\n", evenFibonacciCalculator(4000000));
}