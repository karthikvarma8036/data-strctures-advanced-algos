#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
typedef struct node
{

    int level;
    int pos;
    struct node *next;
} node;
node *start = NULL;
int pop()
{
    node *t = start;

    if (start != NULL)
    {
        start = start->next;
        free(t);
        return 1;
    }
}
int insert(int level)
{
    node *t =(node *) malloc(sizeof(node));
    t->level = level;
    t->pos = level;
    t->next = start;
    start = t;
}
void swapper(int lel, int n, char temp[])
{
    char t = temp[lel];
    temp[lel] = temp[n];
    temp[n] = t;
}

void main()
{

    int i = 0;

    char temp[5] = "abcd";
    int n = strlen(temp);
    node *t = (node *)malloc(sizeof(node));
    t->next = start;
    start = t;

    t->level = 0;
    t->pos = 0;

    while (start != NULL)
    {
        while (start->level != n - 1)
        {
            insert(start->level + 1);
        }
        printf("%s\n", temp);
        while (start != NULL && start->pos == (n - 1))
        {

            swapper(start->level, start->pos, temp);

            pop();
        }
        if (start)
        {
            swapper(start->pos, start->level, temp);
            start->pos += 1;

            swapper(start->pos, start->level, temp);

        }
    }
    printf("%s\n", temp);
}
