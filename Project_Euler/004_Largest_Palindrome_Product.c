/* Largest Palindrome Product
 * Problem 4:
 * A palindromic number reads the same both ways. The largest palindrome made from the product of two digit numbers is 9009 = 91 x 99
 * Find the largest palindrome made from the product of 3-digit numbers.
*/
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

uint32_t integerPower(uint32_t base, uint32_t power)
{
    uint32_t result = 1;
    for(int i = 0; i < power; i++)
        result *= base;
    return result;
        
}
uint32_t getnthDigit(uint32_t number, uint32_t n)
{
    return (number % integerPower(10, n)) / integerPower(10, n -1);    
}
bool isPalindrome(uint32_t number, uint32_t digitCount)
{
    bool isPalindrome = true;
    for(int i = 1, j = digitCount; i <= digitCount / 2; i++, j--)
    {
        if(getnthDigit(number, i) != getnthDigit(number, j))
        {
            isPalindrome = false;
            break;
        }
    }
    return isPalindrome;
}
void palindromeProduct(uint32_t digits)
{
    uint32_t digitCount = digits * 2;
    uint32_t multiplication = 0;
    uint32_t foundBiggestPalindrome = 0;
    uint32_t pali1 = 0, pali2 = 0;
    for(uint32_t i = integerPower(10, digits - 1) ; i < integerPower(10, digits); i++)
    {
        for(uint32_t j = integerPower(10, digits - 1); j < integerPower(10, digits); j++)
        {
            multiplication = i * j;
            if(isPalindrome(multiplication, digitCount) && multiplication >= foundBiggestPalindrome)
            {
                foundBiggestPalindrome = multiplication;
                pali1 = i; 
                pali2 = j;
            }
            // if((j == 913 || i == 913) && (j == 993 || i == 993))
            //     printf("Match found, multiplication : %u, biggestPali : %u i : %u, j : %u, isPali : %d, digitCount : %d, digits : %d\n", multiplication, foundBiggestPalindrome, i, j, isPalindrome(multiplication, digitCount), digitCount, digits);
        }
    }
    printf("Biggest Palindrome for %d digits : %u, and its multiplication of %u and %u\n", digits, foundBiggestPalindrome, pali1, pali2);
}
int main()
{  
    // After 4 digit, uint32_t overflows, so it calculates wrong.
    palindromeProduct(4);
}