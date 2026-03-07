#include "minia.h"

const int MNIST_SIZE_PIXEL = 28;
const int MNIST_SIZE_INPUT = (MNIST_SIZE_PIXEL * MNIST_SIZE_PIXEL);

int main()
{
    t_layers *layers;
    t_data *data;
    int nbr_layers;

	setvbuf(stdout, NULL, _IONBF, 0);
    nbr_layers = 3;
    layers = (t_layers *)calloc(nbr_layers, sizeof(t_layers));
    data = (t_data *)calloc(1, sizeof(t_data));
    if (!layers || !data)
        return(-1);
    initialize_data(data);
    init_reseau(layers, MNIST_SIZE_INPUT, 30, 10);

    train(layers, data, 10, 0.0001, nbr_layers);
    return(0);
}
