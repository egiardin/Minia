#include "minia.h"

void  print_bits32(uint32_t octet)
{
    int i;
    uint32_t bit;

    i = 31;
    while(i >= 0)
    {
        bit = (octet >> i) & 1;
        printf("%d", bit);
        if(i % 8 == 0)
        {
            printf(" ");
        }
        i--;
        
    }
}

uint32_t inverser_uint32(uint32_t input)
{
    uint32_t B0;
    uint32_t B1;
    uint32_t B2;
    uint32_t B3;
    uint32_t res;

    B0 = (input << 24); 
    B1 = (input << 8) & 0x00FF0000;
    B2 = (input >> 8) & 0x0000FF00;
    B3 = (input >> 24);
    res = B0 | B1 | B2 | B3;
    return(res);
}

void print_img(unsigned char *image1)
{
    int i;

    i = 0;
    while(i < MNIST_SIZE_INPUT)
    {
        if(i % 28 == 0 && i != 0)
            printf("\n");
        if(image1[i] < 128)
            printf(" ");
        else
            printf("o");
        i++;
    }

}

void print_img_unitaire(mat image1, FILE *sortie)
{
    int i;

    i = 0;
    while(i < MNIST_SIZE_INPUT)
    {
        if(i % 28 == 0 && i != 0)
            fprintf(sortie, "\n");
        if(image1.mat[0][i] < 0.128)
            fprintf(sortie, " ");
        else
            fprintf(sortie, "o");
        i++;
    }

}

void free_stuct(t_data *data)
{
    data->columns = 0;
    data->lines = 0;
    data->img_magic = 0;
    data->total_alloc = 0;
    data->img_count = 0;
    if(data->all_img)
    {
        free(data->all_img);
        printf("free_struct !");
        return;
    }
}

void normalize_img(t_data *img, mat normalized_output, int img_index) //img_index => 
{
    int i;
    int start_position;
    unsigned char pixel;

    i = 0;
    start_position = img_index * MNIST_SIZE_INPUT;
    while(i < MNIST_SIZE_INPUT)
    {
        pixel = img->all_img[start_position + i];
        normalized_output.mat[0][i] = (float)pixel / 255.0;
        i++;

    }
    //sécuriser avec un free car je malloc
}