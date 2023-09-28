/* Largest Product in a Series
 * Problem 8:
 * The four adjacent digits in the 1000-digit number that have the greatest product are 9 x 9 x 8 x 9 = 5832.
 * 
 * 73167176531330624919225119674426574742355349194934
 * 96983520312774506326239578318016984801869478851843
 * 85861560789112949495459501737958331952853208805511
 * 12540698747158523863050715693290963295227443043557
 * 66896648950445244523161731856403098711121722383113
 * 62229893423380308135336276614282806444486645238749
 * 30358907296290491560440772390713810515859307960866
 * 70172427121883998797908792274921901699720888093776
 * 65727333001053367881220235421809751254540594752243
 * 52584907711670556013604839586446706324415722155397
 * 53697817977846174064955149290862569321978468622482
 * 83972241375657056057490261407972968652414535100474
 * 82166370484403199890008895243450658541227588666881
 * 16427171479924442928230863465674813919123162824586
 * 17866458359124566529476545682848912883142607690042
 * 24219022671055626321111109370544217506941658960408 
 * 07198403850962455444362981230987879927244284909188
 * 84580156166097919133875499200524063689912560717606
 * 05886116467109405077541002256983155200055935729725
 * 71636269561882670428252483600823257530420752963450 
 * 
 * Find the thirteen adjacent digits in the 1000-digit number that have the greatest product. What is the value of this product?
*/
#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char numArray[] =   "7316717653133062491922511967442657474235534919493496983520312774506326239578318016984801869478851843"
                    "8586156078911294949545950173795833195285320880551112540698747158523863050715693290963295227443043557"
                    "6689664895044524452316173185640309871112172238311362229893423380308135336276614282806444486645238749"
                    "3035890729629049156044077239071381051585930796086670172427121883998797908792274921901699720888093776"
                    "6572733300105336788122023542180975125454059475224352584907711670556013604839586446706324415722155397"
                    "5369781797784617406495514929086256932197846862248283972241375657056057490261407972968652414535100474"
                    "8216637048440319989000889524345065854122758866688116427171479924442928230863465674813919123162824586"
                    "1786645835912456652947654568284891288314260769004224219022671055626321111109370544217506941658960408"
                    "0719840385096245544436298123098787992724428490918884580156166097919133875499200524063689912560717606"
                    "0588611646710940507754100225698315520005593572972571636269561882670428252483600823257530420752963450";
typedef struct _node
{
    uint8_t digit;
    struct _node *previous;
    struct _node *next;
}node;
node *myAlloc()
{
    node *temp = malloc(sizeof(node));
    if(temp == NULL)
    {
        printf("Error occured during memory allocation\n");
        exit(1);
    }
    return (node *)malloc(sizeof(node));
}
uint64_t evaluate(node *head)
{
    node *temp = head;
    uint64_t product = 1;
    do
    {
        product *= temp->digit;
        temp = temp->next;
    } while (temp != NULL);
    return product;
}
uint8_t getDigit(char c)
{
    uint8_t ascii_digit_offset = 0x30;
    return c - ascii_digit_offset;
}
void print_LL(node *LinkedList)
{
    node *temp = LinkedList;
    do
    {
        printf("%d,", temp->digit);
        temp = temp->next;
    } while (temp != NULL);
    printf("\n");
}
void freeLL(node *head)
{
    node *temp = head;
    node *temp2 = head;
    do
    {
        temp2 = temp->next;
        free(temp);
        temp = temp2;
    } while (temp != NULL);
}
node *copyLL(node *dest, node *src)
{
    if(dest != NULL)
        freeLL(dest);
    node *srcTracker = src;
    node *destTemp = NULL;
    bool firstNode = true;

    do
    {
        /* code */
        if(firstNode == true)
        {
            dest = myAlloc();
            dest->digit = srcTracker->digit;
            dest->next = NULL;
            dest->previous= NULL; 
            destTemp = dest;  
            firstNode = false;
        }
        else
        {
            node *destPrev = destTemp;
            destTemp->next = myAlloc();
            destTemp = destTemp->next;
            destTemp->digit = srcTracker->digit;
            destTemp->previous = destPrev;
            destTemp->next = NULL;
        }
        srcTracker = srcTracker->next;
    } while (srcTracker != NULL);
    return dest;
}
void greatestProduct(char *string, uint64_t digitCount)
{
    uint8_t length = 0;
    node *head = NULL;
    node *tail = NULL;
    node *highestLL = NULL;
    uint64_t highestCalculated = 0;
    for(uint16_t i = 0; i < strlen(string); i++)
    {
        if(length < digitCount)
        {
            if(head == NULL)
            {
                head = myAlloc();
                head->digit = getDigit(string[i]);
                head->next = NULL;
                head->previous = NULL;
                tail = head;
            }
            else
            {
                tail->next = myAlloc();
                tail->next->previous = tail;
                tail = tail->next;
                tail->digit = getDigit(string[i]);
                tail->next = NULL;
            }
            length++;
        }
        else
        {
            head->next->previous = NULL;
            node *temp = head->next;
            free(head);
            head = temp;
            
            tail->next = myAlloc();
            tail->next->previous = tail;
            tail = tail->next;
            tail->digit = getDigit(string[i]);
            tail->next = NULL;
            if(evaluate(head) > highestCalculated)
            {
                highestCalculated = evaluate(head);
                highestLL = copyLL(highestLL, head);
            }
                
        }
    }
    printf("Biggest adjacent multiplication of %d digits is : ", digitCount);
    printf("%" PRIu64 "\n", highestCalculated);
    printf("Digits are :");
    print_LL(highestLL);
}
int main()
{
    greatestProduct(numArray, 5);
}