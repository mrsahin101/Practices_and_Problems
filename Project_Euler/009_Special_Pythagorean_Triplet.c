/* Special Pythagorean Triplet
 * Problem 9:
 * A Pythagorean triplet is a set of three natural numbers,  a < b < c, for which,
 * a^2 + b^2 = c^2;
 * For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.
 * There exists exactly one Pythagorean triplet for which a + b + c = 1000
 * Find the product abc
 * 
*/

#include <stdio.h>
#include <stdint.h>
uint32_t integerPower(uint32_t base, uint32_t power)
{
    uint32_t result = 1;
    for(int i = 0; i < power; i++)
        result *= base;
    return result;
        
}
void findSpecialPythagoreanTriplet(int n)
{
    for(int a = 1; a <= n; a++)
    {
        for(int b = 1; b <= n; b++)
        {
            for(int c = 1; c <= n; c++)
            {
                if((a < b) && (b < c))
                {
                    if((integerPower(c, 2) == (integerPower(a, 2) + integerPower(b, 2)) ) && ((a + b + c ) == n))
                    {
                        printf("Found : a -> %d, b -> %d, c -> %d\n", a, b, c);
                    }   
                }
            }
        }
    }
}
int main()
{
    findSpecialPythagoreanTriplet(1000);
}