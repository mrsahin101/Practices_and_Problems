/* Multiples of 3 or 5
 * Problem 1:
 * If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6, 9. The sum of these multiples is 23.
 * Find the sum of all the multiples of 3 or 5 below 1000.
*/
#include <stdio.h>


int findMultiplesSum(int capNumber, int multiplier1, int multiplier2)
{
    int sum = 0;

    for(int i = 1; i < capNumber; i++)
    {
        if(i % multiplier1 == 0 || i % multiplier2 == 0)
        {
            printf("i : %d, multi1 : %d, multi2 : %d\n", i, multiplier1, multiplier2);
            sum += i;
        }
            
    }
    return sum;
}

int main()
{
    int cap = 1000;
    int multiplier1 = 3, multiplier2 = 5;

    printf("Result = %d", findMultiplesSum(cap, multiplier1, multiplier2));
    return 0;
}