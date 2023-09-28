/* Smallest Multiple
 * Problem 5:
 * 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
 * What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
*/
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>

typedef struct _node
{
    int number;
    int count;
    struct _node *next;
}node;

bool isPrime(int n)
{
    for(int i = 2; i <= n / 2; i++)
    {
        if(n % i == 0)
            return false;
    }
    return true;
}
node *allocNode()
{
    node *temp = (node *)malloc(sizeof(node));
    temp->count = 0;
    temp->number = 0;
    temp->next = NULL;
    return temp;
}
bool doesItExistinLinkedList(int number, node *head)
{
    if(head == NULL)
        return false;
    node *temp = head;
    bool result = false;
    if(temp->number == number)
    {
        result = true;
    }
    while(temp->next != NULL)
    {
        temp = temp->next;
        if(temp->number == number)
        {
            result = true;
            break;
        }
    }
    return result;
}
// Make sure using it for that numbers you know for sure its exist. use doesItExistinLinkedList function first. Then call this
node *returnNodePointer(int number, node *head)
{
    node *temp = head;
    if(temp->number == number) 
        return temp;
    while(temp->number != number)
    {
        temp = temp->next;
        if(temp->number == number)
        {
            return temp;
        }
    }
    return NULL;
}
node *findPrimeFactors(int n)
{
    node *head = NULL;
    while(n % 2 == 0)
    {
        if(doesItExistinLinkedList(2, head) == true)
        {
            node *temp = returnNodePointer(2, head);
            temp->count++;
        }
        else
        {
            head = (node *)malloc(sizeof(node));
            head->number = 2;
            head->count = 1;
            head->next = NULL;
        }
        n = n / 2;
    }

    for(int i = 3; i <= n; i = i + 2)
    {
        while(n % i == 0)
        {
            if(doesItExistinLinkedList(i, head) == true)
            {
                node *temp = returnNodePointer(i, head);
                temp->count++;
            }
            else
            {
                if(head == NULL)
                {
                    head = allocNode();
                    head->number = i;
                    head->count = 1;
                    head->next = NULL;
                }
                else
                {
                    node *temp = head;
                    while(temp->next != NULL)
                        temp = temp->next;
                    temp->next = (node *)malloc(sizeof(node));
                    temp = temp->next;
                    temp->number = i;
                    temp->count = 1;
                    temp->next = NULL;
                }
                
            }
            n = n / i;
        }
    }
    return head;
}
void print_LL(node *head)
{
    do
    {
        printf("Number : %d, Count : %d\n",head->number, head->count);
        head = head->next;
    } while (head != NULL);
    
}
int findSmallest(int from, int to)
{
    node *head = NULL;
    if(from < 2)
        from = 2;
    for(int i = from; i <= to; i++)
    {
        if(isPrime(i))
        {
            if(head == NULL)
            {
                head = allocNode();
                head->number = i;
                head->count = 1;
            }
            else
            {
                node *temp = head;
                while(temp->next != NULL)
                    temp = temp->next;
                temp->next = allocNode();
                temp = temp->next;
                temp->number = i;
                temp->count = 1;
                temp->next = NULL;
            }
        }
        else
        {
            node *temp2 = findPrimeFactors(i);
            do
            {
                if(doesItExistinLinkedList(temp2->number, head) == true)
                {
                    node *temp4 = returnNodePointer(temp2->number, head);
                    if(temp2->count > temp4->count)
                        temp4->count = temp2->count;
                        
                }
                else
                {
                    node *temp3 = head;
                    while(temp3->next != NULL)
                        temp3 = temp3->next;
                    temp3->next = (node *)malloc(sizeof(node));
                    temp3 = temp3->next;
                    temp3->number = temp2->number;
                    temp3->count = 1;
                    temp3->next = NULL;
                }
                temp2 = temp2->next;
            } while (temp2 != NULL);
            
        }

    }
    printf("------------------------------------\n\n");
    print_LL(head);
    int result = 1;
    do
    {
        for(int i = 0; i < head->count; i++)
            result *= head->number;
        head = head->next;
    } while (head != NULL);

    return result;
}

int main()
{
    printf("From 1 to 10 is : %d\n", findSmallest(1, 10));
    printf("From 1 to 20 is : %d\n", findSmallest(2, 19));
}