/* LONGEST COLLATZ SEQUENCE
 *
 * The following iterative sequence is defined for the set of positive integers:
 * 
 * n -> n/2(n is even)
 * n -> 3n + 1(n is odd)
 * 
 * Using the rule above and starting with 13, we generate the following sequence:
 * 13 -> 40 -> 20 -> 10 -> 5 -> 16 -> 8 -> 4 -> 2 -> 1
 * 
 * It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. 
 * Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.
 * 
 * Which starting number, under one million, produces the longest chain?
 * Once the chain starts the terms are allowed to go above one million.
*/
#include <stdio.h>
#include <stdint.h>

#define CAP_NUMBER      1000000

uint64_t biggestCollatz = 0;
uint64_t longestChain = 0;

void findCollatz(void)
{
    for(uint64_t i = 0; i < CAP_NUMBER; i++)
    {
        uint64_t temp = i;
        uint64_t currentChain = 0;
        while(temp > 1)
        {
            if(temp % 2 == 1)   // odd
            {
                temp = 3 * temp + 1;
                currentChain++;
                continue;
            }
            else    // even
            {
                temp = temp / 2;
                currentChain++;
            }
        }
        if(currentChain > longestChain)
        {
            longestChain = currentChain;
            biggestCollatz = i;
        }
    }
    longestChain++;     // Inclusion for 1
}   
int main(void)
{
    findCollatz();
    printf("Biggest Collatz number chain number is : %d, Chain count is : %d",  biggestCollatz, longestChain);
}