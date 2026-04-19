#ifndef MINIA_H
 #define MINIA_H

 #include "stdio.h"
 #include "stdlib.h"
 #include "math.h"
 #include "unistd.h"
 #include "assert.h"
 #include "string.h"
 #include "stdbool.h"
 #include "stdint.h"
 #include "struct.h"

 #define PI 3.14159265359

/*====================================== NETWORK(Start) ====================================*/


 /* ===== mat_utils.c ===== */

 void   print_mat(mat mat);
 void   free_mat(mat mat1);
 void   fprint_mat(mat mat);
 float  floatmax(float nbr);
 void   clear_vect(mat vector);
 mat    transp_mat_dir(mat mat1);
 void   copy_vect(mat v1, mat v2);
 void   transp_mat(mat mat1, mat output);
 void   print_mat_without_index(mat mat);
 void   mult_nbr_mat(float nbr, mat mat1);
 void   free_partial_mat(mat mat1, int line);
 mat    init_matrice_he(int line, int column);
 void   fprint_info_mat(mat mat1, FILE *name);
 mat    init_matrice_zero(int line, int column);
 void   add_mat(mat mat1, mat mat2, mat output);
 void   fprint_mat_sortie(mat mat, FILE *sortie);
 mat    init_matrice_random(int line, int column);
 void   mult_mat(mat mat1, mat mat2, mat output);
 void   soust_mat(mat mat1, mat mat2, mat output);
 mat    init_matrice_zero_biais(int line, int column);
 void   produit_hadamard(mat tab1, mat tab2, mat output);
 void   mult_mat_transp_a(mat transp_a, mat mat2, mat output);
 void   print_info_reseau(t_layers *layers, FILE *sortie);

 /* ===== activ_utils.c ====== */

 float  relu(float nbr);
 void   deriv_relu(mat v1);
 void   relu_tab(mat mat1);
 float  sigmoid(float nbr);
 float  ft_tanh(float nbr);
 void   softmax(mat output);

 /* ===== network_utils.c ===== */

 void   print_layer(t_layers *layers, int index, FILE *sortie);
 void   print_reseau(t_layers *layers, int nbr_layers, mat expected_output, FILE *sortie);

 /* ===== math_utils.c ===== */

 float  normal_random(float mu, float sigma);
 float  calc_density_function(int x, float mu, float sigma);

 /* ===== init_reseau.c ===== */

 void init_reseau(t_layers *layers, int size_input, int size_middle_layer, int size_expected_output);

 /* ===== propagation.c  ===== */

void  calc_gradient(t_layers *layers, int nbr_layers, mat input);
void  forward_propagation(t_layers *layers, int nbr_layers, mat input);
void  calc_delta(t_layers *layers, mat expected_output, int nbr_layers);
void  update_weight(t_layers *layers, float learning_rate, int nbr_layers);
void  update_biais(t_layers *layers, float learning_rate, int nbr_layers);
void  back_propagation(t_layers *layers, mat expected_output, int nbr_layers, float learning_rate, mat input);

/*====================================== NETWORK(End)====================================*/





/*====================================== TEST(Start)====================================*/

/* ===== test_network_utils.c ===== */

 void   test_mat_utils(void);
 void   test_tab_utils(void);
 void   test_activ_utils(void);

 /* ===== test_network.c ===== */

 void   test_reseau_forward(void);
 void   test_reseau_backpropagation(void);

 /* ===== test_data.c ===== */

 void   test_img(t_data *data);
 void   test_labels(t_data *data);




/*====================================== TEST(End)====================================*/





/*====================================== DATA(Start)====================================*/

 /* ===== mnist_loader.c ===== */ 

 void   initialize_img(t_data *data);
 void   initialize_labels(t_data *data);
 void   initialize_data(t_data *data);

 /* ===== mnist_utils.c ===== */ 

 void   free_stuct(t_data *data);
 void   print_bits32(uint32_t octet);
 void   print_img(unsigned char *image1);
 uint32_t inverser_uint32(uint32_t input);
 void   print_img_unitaire(mat image1, FILE *sortie);
 void   normalize_img(t_data *img, mat normalized_output, int img_index);

/*====================================== DATA(End)====================================*/





/*====================================== TRAIN(Start)====================================*/



/* ===== train.c ===== */

 void   train(t_layers *layers, t_data *mnist_data, int epochs, float learning_rate, int nbr_layers);

/* ===== train_utils.c ===== */

 int  get_prediction(mat output);
 int  *fisher_yates_shuffle(uint32_t size);
 void label_to_vect(mat expect_vect, int label);

/*====================================== TRAIN(End)====================================*/


/*====================================== Monitoring(Start)====================================*/




/*====================================== Monitoring(End)====================================*/

#endif