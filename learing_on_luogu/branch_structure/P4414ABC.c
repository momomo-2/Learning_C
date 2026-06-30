#include <stdio.h>

int a, b, c;
char arrment[3];
int num_new[3];

void bubble_sort_desc(int arr[], int size)
{
    int i, j, mid;
    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - 1 - i; j++)
        {
            if (arr[j] < arr[j + 1])
            {
                mid = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = mid;
            }
        }
    }
}

int main()
{
    scanf("%d %d %d", &a, &b, &c);
    scanf("%s", &arrment);
    int num_old[3] = {a, b, c};

    bubble_sort_desc(num_old, 3);
    if (arrment[0] == 'C')
    {
        num_new[0] = num_old[0];
        if (arrment[1] == 'B')
        {
            num_new[1] = num_old[1];
            num_new[2] = num_old[2];
        }
        else if (arrment[1] == 'A')
        {
            num_new[1] = num_old[2];
            num_new[2] = num_old[1];
        }
    }
    else if (arrment[0] == 'B')
    {
        num_new[0] = num_old[1];
        if (arrment[1] == 'A')
        {
            num_new[1] = num_old[2];
            num_new[2] = num_old[0];
        }
        else if (arrment[1] == 'C')
        {
            num_new[1] = num_old[0];
            num_new[2] = num_old[2];
        }
    }
    else
    {
        num_new[0] = num_old[2];
        if (arrment[1] == 'B')
        {
            num_new[1] = num_old[1];
            num_new[2] = num_old[0];
        }
        else if (arrment[1] == 'C')
        {
            num_new[1] = num_old[0];
            num_new[2] = num_old[1];
        }
    }

    int i;
    for (i = 0; i < 3; i++)
    {
        printf("%d ", num_new[i]);
    }

    return 0;
}
