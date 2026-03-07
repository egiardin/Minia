#include "minia.h"

mat init_matrice_he(int line, int column) 
{
    mat mat;
    int i;
    int j;

    i = 0;
    j = 0;
    if (line <= 0 || column <= 0)
    {
        ERR_LOG("La dimension de la colonne ou de la ligne est 0 => Impossible");
        exit(-1);
    }
    mat.line = line;
    mat.column = column;
    mat.mat = (float **)calloc(line, sizeof(float *));
    if (!mat.mat)
    {
        mat.line = 0;
        mat.column = 0;
        return(mat);
    }
    while (i < line)
    {
        mat.mat[i] = (float *)calloc(column, sizeof(float));
        if (!mat.mat[i])
        {
            free_partial_mat(mat, i);
            mat.line = 0;
            mat.column = 0;
            return(mat);
        }
        while (j < column)
        {
            mat.mat[i][j] = normal_random(0, sqrtf(2.0f / column));
            j++;
        }
        j = 0;
        i++;
    }
    return(mat);
}

mat init_matrice_random(int line, int column) 
{
    mat mat;
    int i;
    int j;
    int nbr;

    i = 0;
    j = 0;
    if (line <= 0 || column <= 0)
    {
        printf("La dimension de la colonne ou de la ligne est 0 => Impossible\n");
        exit(-1);
    }
    nbr = 1;
    mat.line = line;
    mat.column = column;
    mat.mat = (float **)calloc(line, sizeof(float *));
    if (!mat.mat)
    {
        mat.line = 0;
        mat.column = 0;
        return(mat);
    }
    while (i < line)
    {
        mat.mat[i] = (float *)calloc(column, sizeof(float));
        if (!mat.mat[i])
        {
            free_partial_mat(mat, i);
            mat.line = 0;
            mat.column = 0;
            return(mat);
        }
        while (j < column)
        {
            mat.mat[i][j] = nbr;
            nbr++;
            j++;
        }
        j = 0;
        i++;
    }
    return(mat);
}

mat init_matrice_zero(int line, int column)
{
    mat mat;
    int i;
    int j;

    i = 0;
    j = 0;
    if (line <= 0 || column <= 0)
    {
        ERR_LOG("La dimension de la colonne ou de la ligne est 0 => Impossible\n");
        exit(-1);
    }
    mat.line = line;
    mat.column = column;
    mat.mat = (float **)calloc(line, sizeof(float *));
    if (!mat.mat)
    {
        mat.line = 0;
        mat.column = 0;
        return(mat);
    }
    while (i < line)
    {
        mat.mat[i] = (float *)calloc(column, sizeof(float));
        if (!mat.mat[i])
        {
            free_partial_mat(mat, i);
            mat.line = 0;
            mat.column = 0;
            return(mat);
        }
        while (j < column)
        {
            mat.mat[i][j] = (float)0;
            j++;
        }
        j = 0;
        i++;
    }
    return(mat);
}

mat init_matrice_zero_biais(int line, int column)
{
    mat mat;
    int i;
    int j;

    i = 0;
    j = 0;
    if (line <= 0 || column <= 0)
    {
        fprintf(stdout, "La dimension de la colonne ou de la ligne est 0 => Impossible\n");
        exit(-1);
    }
    mat.line = line;
    mat.column = column;
    mat.mat = (float **)calloc(line, sizeof(float *));
    if (!mat.mat)
    {
        mat.line = 0;
        mat.column = 0;
        return(mat);
    }
    while (i < line)
    {
        mat.mat[i] = (float *)calloc(column, sizeof(float));
        if (!mat.mat[i])
        {
            free_partial_mat(mat, i);
            mat.line = 0;
            mat.column = 0;
            return(mat);
        }
        while (j < column)
        {
            mat.mat[i][j] = 0.01;
            j++;
        }
        j = 0;
        i++;
    }
    return(mat);
}

void print_mat(mat mat)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (i < mat.line)
    {
        while (j < mat.column)
        {
            printf("mat[%d][%d] = %.5f", i, j, mat.mat[i][j]);
            printf("\n");
            j++;
        }
        j = 0;
        i++;
    }
}

void fprint_mat(mat mat)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (i < mat.line)
    {
        while (j < mat.column)
        {
            fprintf(stdout, "mat[%d][%d] = %.5f", i, j, mat.mat[i][j]);
            fprintf(stdout, "\n");
            j++;
        }
        j = 0;
        i++;
    }
}

void fprint_mat_sortie(mat mat, FILE *sortie)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (i < mat.line)
    {
        while (j < mat.column)
        {
            fprintf(sortie, "mat[%d][%d] = %.5f", i, j, mat.mat[i][j]);
            fprintf(sortie, "\n");
            j++;
        }
        j = 0;
        i++;
    }
}

void print_mat_without_index(mat mat)
{
    int i;
    int j;

    i = 0;
    j = 0;
    printf("\n");
    while (i < mat.line)
    {
        while (j < mat.column)
        {
            if (j == 0)
            {
                if (mat.mat[i][j] >= 10)
                    printf("|%.4f   ",mat.mat[i][j]);
                else
                    printf("|%.5f   ",mat.mat[i][j]);   
            }
            else if (j == (mat.column -1))
            {
                if (mat.mat[i][j] >= 10)
                    printf("%.4f|",mat.mat[i][j]);
                else
                    printf("%.5f|",mat.mat[i][j]);  
            }
            else
            {
                if (mat.mat[i][j] >= 10)
                    printf("%.4f   ",mat.mat[i][j]);
                else
                    printf("%.5f   ",mat.mat[i][j]);   

            }
            j++;
        }
        printf("\n");
        j = 0;
        i++;
    }
}

void mult_mat(mat mat1, mat mat2, mat output) 
{
    int i;
    int j;
    int k;

    i = 0;
    j = 0;
    k = 0;
    while (i < output.line)
    {
        while (j < output.column)
        {
            while (k < mat1.column)
            {
                output.mat[i][j] += mat1.mat[i][k] * mat2.mat[k][j];
                k++;
            }
            k = 0;
            j++;
        }
        i++;
        j = 0;
        k =0;
    }
    return;
}

void mult_mat_transp_a(mat transp_a, mat mat2, mat output) 
{
    int i;
    int j;
    int k;

    i = 0;
    j = 0;
    k = 0;
    while (i < output.line)
    {
        while (j < output.column)
        {
            output.mat[i][j] = 0;// correction
            while (k < transp_a.line)
            {
                output.mat[i][j] += transp_a.mat[k][i] * mat2.mat[k][j];
                k++;
            }
            k = 0;
            j++;
        }
        i++;
        j = 0;
        k =0;
    }
    return;
}

void soust_mat(mat mat1, mat mat2, mat output)
{
    int i;
    int j;

    i = 0;
    j = 0;
    if (mat1.line != mat2.line || mat1.column != mat2.column)
    {
        printf("Impossible de faire une soustraction matricielle car dimension non-compatible\n");
        exit(-1);
    }
    while (i < mat1.line)
    {
        while (j < mat1.column)
        {
            output.mat[i][j] = mat1.mat[i][j] - mat2.mat[i][j];
            j++;
        }
        j = 0;
        i++;
    }
    return;
}

void add_mat(mat mat1, mat mat2, mat output)
{
    int i;
    int j;

    i = 0;
    j = 0;
    if (mat1.line != mat2.line || mat1.column != mat2.column)
    {
        printf("Impossible de faire une soustraction matricielle car dimension non-compatible\n");
        exit(-1);
    }
    while (i < mat1.line)
    {
        while (j < mat1.column)
        {
            output.mat[i][j] = mat1.mat[i][j] + mat2.mat[i][j];
            j++;
        }
        j = 0;
        i++;
    }
    return;
}

void mult_nbr_mat(float nbr, mat mat1)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (i < mat1.line)
    {
        while (j < mat1.column)
        {
            mat1.mat[i][j] = nbr * mat1.mat[i][j];
            j++;
        }
        j = 0;
        i++;
    }
    return;
}

void transp_mat(mat mat1, mat output) 
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (i < mat1.line)
    {
        while (j < mat1.column)
        {
            output.mat[j][i] = mat1.mat[i][j];
            j++;
        }
        j = 0;
        i++;
    }
    return;
}

mat transp_mat_dir(mat mat1) // pas alloc output
{
    mat output;
    output = init_matrice_zero(mat1.column, mat1.line);
    int i;
    int j;

    i = 0;
    j = 0;
    while (i < mat1.line)
    {
        while (j < mat1.column)
        {
            output.mat[j][i] = mat1.mat[i][j];
            j++;
        }
        j = 0;
        i++;
    }
    return(output);
}

void fprint_info_mat(mat mat1, FILE *name)
{
    fprintf(stdout, "\nles dimansions de %s : (%d, %d)\n",(char*)name, mat1.line, mat1.column);
    return;
    
}

void free_mat(mat mat1)
{
    int i;

    i = 0;
    while (i < mat1.line)
    {
        free(mat1.mat[i]);
        i++;
    }
    free(mat1.mat);
}

void free_partial_mat(mat mat1, int line)
{
    int i;

    i = 0;
    while (i < line)
    {
        free(mat1.mat[i]);
        i++;
    }
    free(mat1.mat);
}

void produit_hadamard(mat tab1, mat tab2, mat output)
{
    int i;

    i = 0;
    while (i < tab1.column)
    {
       output.mat[0][i] =  tab1.mat[0][i] * tab2.mat[0][i];
       i++;
    }
    return;
}

float floatmax(float nbr)
{

    if (nbr < 0)
        return(0);
    else
        return(nbr);
}

void  copy_vect(mat v1, mat v2)
{
    if (v1.column != v2.column)
    {
        write(1, "Erreur de size dans copy_vect", 30);
        return;
    }
    int i;

    i = 0;
    while (i < v1.column)
    {
        v2.mat[0][i] = v1.mat[0][i];
        i++;
    }
    return;
}

void clear_vect(mat vector)
{
    int i;

    i = 0;
    while (i < vector.column)
    {
        vector.mat[0][i] = (float)0;
        i++;
    }
    return;
}
