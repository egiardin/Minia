#include "minia.h"

void label_to_vect(mat expect_vect, int label)
{
    clear_vect(expect_vect);
    expect_vect.mat[0][label] = (float)1;
}

int *fisher_yates_shuffle(uint32_t size)
{
    int *lst;
    int i;
    int j;
    int tmp;

    lst = (int *)calloc(sizeof(int), size);
    if (!lst)
        return (NULL);

    i = 0;
    while (i < (int)size)
    {
        lst[i] = i;
        i++;
    }

    i = size - 1; 
    while (i > 0)
    {
        j = rand() % (i + 1);
        tmp = lst[i];
        lst[i] = lst[j];
        lst[j] = tmp;

        i--;
    }
    return (lst);
}

int get_prediction(mat output)
{
    float max_prob;
    int i;
    int max;

    i = 0;
    max_prob = output.mat[0][i];
    max = 0;
    i = 1;
    while (i < output.column)
    {
        if (max_prob <= output.mat[0][i])
        {
            max_prob = output.mat[0][i];
            max = i;
        }
        i++;
    }
    return(max);
}
