#include "minia.h"

void initialize_img(t_data *data)
{
    char *path;
    FILE *file;
    size_t lus;

    path = "data/train-images.idx3-ubyte";
    file = fopen(path, "rb");
    if (file == NULL)
    {
        perror("Erreur d'ouverture");
        return;
    }
    fread(&data->img_magic, sizeof(uint32_t), 1, file);
    data->img_magic = inverser_uint32(data->img_magic);
    if (data->img_magic != 2051)
    {
        printf("Erreur : ce n'est pas un fichier MNIST\n");
        fclose(file);
        return;
    }
    fread(&data->img_count, sizeof(uint32_t), 1, file);
    data->img_count = inverser_uint32(data->img_count);

    fread(&data->columns, sizeof(uint32_t), 1, file);
    data->columns = inverser_uint32(data->columns);

    fread(&data->lines, sizeof(uint32_t), 1, file);
    data->lines = inverser_uint32(data->lines);
    if ( data->lines != 28 || data->columns != 28)
    {
        printf("Erreur : Les dimensions ne sont pas les bonnes\n");
        fclose(file);
        return;
    }
    data->total_alloc = data->img_count * data->lines * data->columns * sizeof(unsigned char);
    data->all_img = calloc(1, data->total_alloc);
    if (!data->all_img)
    {
        perror("Erreur d'initialisation de all_img");
        fclose(file);
        return;
    }
    lus = fread(data->all_img, sizeof(unsigned char), data->total_alloc, file);
    if (lus != data->total_alloc)
    {
        printf("Erreur : fichier corrompu\n");
        fclose(file);
        return;
    }
    fread(data->all_img, sizeof(unsigned char), data->total_alloc, file);
   return;

}


void initialize_labels(t_data *data)
{
    char *path;
    FILE *file;
    size_t lus;

    path = "data/train-labels.idx1-ubyte";
    file = fopen(path, "rb");
    if (file == NULL)
    {
        perror("Erreur d'ouverture");
        return;
    }
    fread(&data->lbl_magic, sizeof(uint32_t), 1, file);
    data->lbl_magic = inverser_uint32(data->lbl_magic);
    if (data->lbl_magic != 2049)
    {
        printf("Erreur : ce n'est pas un fichier MNIST (labels)\n");
        fclose(file);
        return;
    }
    fread(&data->lbl_count, sizeof(uint32_t), 1, file);
    data->lbl_count = inverser_uint32(data->lbl_count);

   
    data->labels = calloc(data->lbl_count, sizeof(unsigned char));
    if (!data->labels)
    {
        perror("Erreur d'initialisation de data->labels");
        fclose(file);
        return;
    }
    lus = fread(data->labels, sizeof(unsigned char), data->lbl_count, file);
    if (lus != data->lbl_count)
    {
        printf("Erreur : fichier corrompu\n");
        fclose(file);
        return;
    }
    fread(data->labels, sizeof(unsigned char), data->lbl_count, file);
    return;

}
void initialize_data(t_data *data)
{
    initialize_labels(data);
    initialize_img(data);
    return;
}
