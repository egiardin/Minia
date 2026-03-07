#include "minia.h"


void test_img(t_data *data)
{
    printf("\n----- img_magic -----\n");
    printf("%d", data->img_magic);
    printf("\n----- img_count -----\n");
    printf("%d", data->img_count);
    printf("\n----- columns -----\n");
    printf("%d", data->columns);
    printf("\n----- lines -----\n");
    printf("%d", data->lines);
    printf("\n----- total_alloc -----\n");
    printf("%zu", data->total_alloc);
    printf(" octets ou %.2zu Mo", data->total_alloc/1000000);
    printf("\n----- Image 1 -----\n");
    print_img(data->all_img + (1 * MNIST_SIZE_INPUT));
    printf("\n----- Image 6 978 -----\n");
    print_img(data->all_img + (6978 * MNIST_SIZE_INPUT));
    printf("\n----- Image 17 012 -----\n");
    print_img(data->all_img + (17012 * MNIST_SIZE_INPUT));
}


void test_labels(t_data *data)
{
    printf("\n----- lbl_magic -----\n");
    printf("%d", data->lbl_magic);
    printf("\n----- lbl_count -----\n");
    printf("%d", data->lbl_count);
    printf("\n----- total_alloc -----\n");
    printf("%.2u Mo", data->lbl_count/1000000);
    printf("\n----- Image 1 -----\n");
    printf("%d",data->labels[1]);
    printf("\n----- Image 6 978 -----\n");
    printf("%d",data->labels[6978]);
    printf("\n----- Image 17 012 -----\n");
    printf("%d",data->labels[17012]);
}