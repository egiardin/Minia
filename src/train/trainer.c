#include "minia.h"


void train(t_layers *layers, t_data *mnist_data, int epochs, float learning_rate, int nbr_layers)
{
    FILE *file;
    mat input;
    mat expected_output;
    int i;
    int j;
    int *shuffle_index;
    int score; 
    int prediction;
    int real_index;
    char *path;
    float loss;
    // float n;
    
    path = "./loss.txt";

    input = init_matrice_zero(1, MNIST_SIZE_INPUT);
    expected_output = init_matrice_zero(1, 10);
    file = fopen(path, "w");
    if(file == NULL)
    {
        perror("Erreur d'ouverture");
        return;
   }
    loss = 1;
    i = 0;
    while(i < epochs)
    {
        score = 0;
        printf("--- Epoch %d / %d ---\n", i + 1, epochs);
        
        shuffle_index = fisher_yates_shuffle(mnist_data->lbl_count);
        if (!shuffle_index)
        {
            fprintf(stderr, "Erreur lors du mélange");
            return;
        }
        j = 0;
        while((uint32_t)j < mnist_data->lbl_count)
        {
            real_index = shuffle_index[j];
            normalize_img(mnist_data, input, real_index); //à verifier en detail
            label_to_vect(expected_output, mnist_data->labels[real_index]);
            forward_propagation(layers, nbr_layers, input);
            prediction = get_prediction(layers[nbr_layers - 1].activation); //à vérifier en detail
            if (prediction == mnist_data->labels[real_index])
            {
                score++;
            }
            int target = mnist_data->labels[real_index]; //
            float proba_correcte = layers[nbr_layers - 1].activation.mat[0][target]; //
            loss = -logf(proba_correcte + 1e-15); //
            fprintf(file, "Loss[%d] = %f\n", j, loss);
            back_propagation(layers, expected_output, nbr_layers, learning_rate, input);
            if (j % 1000 == 0)
            {
                fprintf(stderr, "Progression : %d / %d (Score actuel : %d)\r", j, mnist_data->lbl_count, score);
            }
            j++;
        }

        fprintf(stderr, "\r\033[KEpoch %d / %d terminée. Score : %d / %d\n", i + 1, epochs, score, mnist_data->lbl_count);

        free(shuffle_index);
        i++;
    }
    fclose(file); //ajt
    free_mat(input);
    free_mat(expected_output);
}


// void train(t_layers *layers, t_data *mnist_data, int epochs, float learning_rate, int nbr_layers)
// {
//     FILE *file;
//     mat input;
//     mat expected_output;
//     int i;
//     int j;
//     int *shuffle_index;
//     int score; 
//     int prediction;
//     int real_index;
//     char *path;
//     float loss;
//     float n;
    
//     path = "/Users/enzo.giardina/Desktop/Side project/Minia/loss.txt";

//     input = init_matrice_zero(1, MNIST_SIZE_INPUT);
//     expected_output = init_matrice_zero(1, 10);
//     file = fopen(path, "w");
//     if(file == NULL)
//     {
//         perror("Erreur d'ouverture");
//         return;
//     }
//     loss = 1;
//     i = 0;
//     while(i < epochs)
//     {
//         score = 0;
//         printf("--- Epoch %d / %d ---\n", i + 1, epochs);
        
//         shuffle_index = fisher_yates_shuffle(mnist_data->lbl_count);
//         if (!shuffle_index)
//         {
//             fprintf(stderr, "Erreur lors du mélange");
//             return;
//         }
//         j = 0;
//         while((uint32_t)j < mnist_data->lbl_count)
//         {
//             real_index = shuffle_index[j];
//             normalize_img(mnist_data, input, real_index); //à verifier en detail
//             label_to_vect(expected_output, mnist_data->labels[real_index]);
//             print_img_unitaire(input, file);
//             forward_propagation(layers, nbr_layers, input);
//             prediction = get_prediction(layers[nbr_layers - 1].activation); //à vérifier en detail
//             if (prediction == mnist_data->labels[real_index])
//             {
//                 score++;
//             }
//             int target = mnist_data->labels[real_index]; //
//             float proba_correcte = layers[nbr_layers - 1].activation.mat[0][target]; //
//             loss = -logf(proba_correcte + 1e-15); //
//             fprintf(file, "Loss[%d] = %f\n", j, loss);
//             back_propagation(layers, expected_output, nbr_layers, learning_rate, input);
//             fprintf(file, "passage[%d]", j);
//             print_reseau(layers, nbr_layers, expected_output, file);
//             fprintf(file, "\n");
//             if (j % 1000 == 0)
//             {
//                 fprintf(stderr, "Progression : %d / %d (Score actuel : %d)\r", j, mnist_data->lbl_count, score);
//             }
//             j++;
//         }

//         fprintf(stderr, "Epoch %d / %d terminée. Score : %d / %d\n", i + 1, epochs, score, mnist_data->lbl_count);

//         free(shuffle_index);
//         i++;
//     }
//     fclose(file); //ajt
//     free_vect(&input);
//     free_vect(&expected_output);
// }


