/*-------------------------------------------------------------------------
 * Image Processing using C-Ansi
 *
 * Trabalho..:  Contagem de feijoes
 * Professor.:  Luiz Eduardo da Silva
 * Aluno.....:  Lucas Pessoa Oliveira Alves
 *-------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#if defined(_WIN32) || defined(__WIN64__) || defined(__CYGWIN__)
#include "..\\utils\\imagelib.h"
#elif defined(__linux__)
#include "../utils/imagelib.h"
#endif

// funcao para a alteração de intensidade de cor da imagem
// utilizando threshold de 165 para o calculo
image intensity(image In, int threshold)
{
    float T[In->ml + 1];
    image Out = img_clone(In);
    for (int i = 0; i < In->ml + 1; i++)
    {
        T[i] = i < threshold ? 0 : In->ml;
    }
    for (int i = 0; i < In->nr * In->nc; i++)
        Out->px[i] = T[In->px[i]];
    return Out;
}

// funcao para encontrar o representante de um conjunto no Union-Find
int find(int parent[], int i)
{
    while (parent[i] != i)
        i = parent[i];
    return i;
}

// funcao para unir dois conjuntos no Union-Find
void Union(int parent[], int i, int j)
{
    int x = find(parent, i);
    int y = find(parent, j);
    parent[y] = x;
}

// funcao para contar o numero de conjuntos unicos na imagem utilizando Union-Find
int countBeans(image In, int parent[])
{
    int count = -1;
    int used[In->nc * In->nr];
    for (int i = 0; i < In->nc * In->nr; i++)
        used[i] = 0;
    for (int i = 0; i < In->nc * In->nr; i++)
    {
        int root = find(parent, In->px[i]);
        if (used[root] == 0)
        {
            used[root] = 1;
            count++;
        }
    }
    return count;
}

// funcao para rotular os componentes conectados na imagem utilizando Union-Find
void label(image In)
{
    int nr = In->nr;
    int nc = In->nc;
    int *px = In->px;
    int numLabel = 0;
    int parent[1000];
    for (int i = 0; i < 1000; i++)
        parent[i] = i;
    for (int i = 1; i < nr; i++)
        for (int j = 1; j < nc; j++)
        {
            int p = px[i * nc + j];
            int r = px[(i - 1) * nc + j];
            int t = px[i * nc + j - 1];
            if (p != 0)
            {
                if (r == 0 && t == 0)
                    px[i * nc + j] = ++numLabel;
                if (r != 0 && t == 0)
                    px[i * nc + j] = r;
                if (r == 0 && t != 0)
                    px[i * nc + j] = t;
                if (r != 0 && t != 0 && t == r)
                    px[i * nc + j] = r;
                if (r != 0 && t != 0 && t != r)
                {
                    px[i * nc + j] = t;
                    Union(parent, r, t);
                }
            }
        }

    for (int i = 0; i < nr * nc; i++)
        In->px[i] = find(parent, In->px[i]);

    In->ml = numLabel;
    printf("#componentes: %d\n", countBeans(In, parent));
}

// funcao para retornar o menor valor entre teês numeros
int min(int x, int y, int z)
{
    if (x < y && x < z)
        return x;
    if (y < z)
        return y;
    return z;
}

//funcao para calcular a distancia do pixel mais distante do fundo (preto) na imagem
int distance(image In)
{
    int nr = In->nr;
    int nc = In->nc;
    int *px = In->px;
    int distanceMax = -1;
    for (int i = 1; i < nr - 1; i++)
    {
        for (int j = 1; j < nc - 1; j++)
        {
            int pos = i * nc + j;
            int cur = px[pos];
            int up = px[(i - 1) * nc + j];
            int esq = px[i * nc + j - 1];
            if (cur != 0)
            {
                px[pos] = (up + 1) < (esq + 1) ? (up + 1) : (esq + 1);
            }
        }
    }
    for (int i = nr - 2; i > 0; i--)
    {
        for (int j = nc - 2; j > 0; j--)
        {
            int pos = i * nc + j;
            int cur = px[pos];
            int up = px[(i + 1) * nc + j];
            int esq = px[i * nc + j + 1];
            if (cur != 0)
            {
                px[pos] = min(up + 1, esq + 1, cur);
                if (distanceMax < px[pos])
                    distanceMax = px[pos];
            }
        }
    }
    return distanceMax;
}

// funcao para criar a imagem negativa de uma imagem dada
image neg(image img)
{
    image Out = img_clone(img);
    for (int i = 0; i < img->nr * img->nc; i++)
        Out->px[i] = img->ml - img->px[i];
    return Out;
}

void msg(char *s)
{
    printf("\nNegative image");
    printf("\n-------------------------------");
    printf("\nUsage:  %s  image-name[.pgm]\n\n", s);
    printf("    image-name[.pgm] is image file in pgm format \n\n");
    exit(1);
}

/*-------------------------------------------------------------------------
 * main function
 *-------------------------------------------------------------------------*/
int main(int argc, char *argv[])
{
    int nc, nr, ml, tp, threshold = 165;
    char *p, nameIn[100], nameOut[100], cmd[110];
    image In, Out;
    if (argc < 2)
        msg(argv[0]);

    //-- define input/output file name
    img_name(argv[1], nameIn, nameOut, GRAY, GRAY);

    //-- read image
    In = img_get(nameIn, GRAY);

    //-- negativar imagem
    Out = neg(In);

    //-- mudar intensidade
    Out = intensity(Out, threshold);

    //-- contagem de feijoes conectos
    label(Out);

    //-- save image
    img_put(Out, nameOut, GRAY);

    //-- show image
    // sprintf(cmd, "%s %s &", VIEW, nameOut);
    puts(cmd);
    system(cmd);
    img_free(In);
    img_free(Out);
    return 0;
}
