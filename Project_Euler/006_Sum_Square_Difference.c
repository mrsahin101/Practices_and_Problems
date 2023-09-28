/* Sum Square Difference
 * Problem 6:
 * The sum of squares of the first ten natural numbers is 385
 * The square of the sum of the first ten natural numbers is 3025
 * Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 - 385 = 2640
 * 
 * Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
*/
#include <stdio.h>
#include <inttypes.h>

uint32_t integerPower(uint32_t base, uint32_t power)
{
    uint32_t result = 1;
    for(int i = 0; i < power; i++)
        result *= base;
    return result;
        
}
uint64_t findSumMinusSquare(int n)
{
    // uint64_t square = 0;
    // uint64_t sum = 0;
    // for(int i = 1; i <= n; i++)
    // {
    //     square += integerPower(i, 2);
    //     sum += i;
    // }
    // sum = integerPower(sum, 2);
    uint64_t square = (n * (n + 1) * (2 * n + 1)) / 6;
    uint64_t sum = (n * (n + 1)) / 2;
    sum = integerPower(sum , 2);
    return sum - square;
}
int main()
{
    printf("Result for first one-hundred numbers : ");
    printf("%" PRIu64 "\n", findSumMinusSquare(100));
}