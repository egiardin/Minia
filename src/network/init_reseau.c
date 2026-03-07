#include "minia.h"

void init_reseau(t_layers *layers, int size_input, int size_middle_layer, int size_expected_output)
{

    /*----  définition des sizes du modèle. ----*/
    layers[0].size = size_input; //MNIST_SIZE_INPUT             input =  (1, 784) * W1 = (784, 30) * W2 = (30, 10)
    layers[1].size = size_middle_layer; //30
    layers[2].size = size_expected_output; //10

    layers[0].output.column = size_input;
    layers[1].output.column = size_middle_layer;
    layers[2].output.column = size_expected_output;

    layers[0].activation.column = size_input;
    layers[1].activation.column= size_middle_layer;
    layers[2].activation.column = size_expected_output;

    layers[1].delta.column = size_middle_layer; //size
    layers[2].delta.column = size_expected_output;

    layers[1].biais.column = size_middle_layer;
    layers[2].biais.column = size_expected_output;

    /*----  Allocation du modèle ----*/

    layers[0].output = init_matrice_zero(1, size_input);
    layers[1].output = init_matrice_zero(1, size_middle_layer);
    layers[2].output = init_matrice_zero(1, size_expected_output);

    layers[0].activation = init_matrice_zero(1, size_input);
    layers[1].activation = init_matrice_zero(1, size_middle_layer);
    layers[2].activation = init_matrice_zero(1, size_expected_output);

    layers[1].delta = init_matrice_zero(1, size_middle_layer);
    layers[2].delta = init_matrice_zero(1, size_expected_output);

    layers[1].biais = init_matrice_zero_biais(1, size_middle_layer);
    layers[2].biais = init_matrice_zero_biais(1, size_expected_output);

    layers[1].W = init_matrice_he(size_input, size_middle_layer);
    layers[2].W = init_matrice_he(size_middle_layer, size_expected_output);

    layers[1].gradient = init_matrice_zero(size_input, size_middle_layer);
    layers[2].gradient = init_matrice_zero(size_middle_layer, size_expected_output);


    return;
}
