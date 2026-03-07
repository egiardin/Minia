#include "minia.h"

int main()
{
    t_layers *layers;
    t_data *data;
    int nbr_layers;

    nbr_layers = 3;
    layers = (t_layers *)malloc(nbr_layers * sizeof(t_layers));
    data = (t_data *)malloc(sizeof(t_data));
    if(!layers || !data)
        return(-1);
    initialize_data(data);
    init_reseau(layers, 784, 30, 10);

    train(layers, data, 10, 0.0001, nbr_layers);
    return(0);
}
