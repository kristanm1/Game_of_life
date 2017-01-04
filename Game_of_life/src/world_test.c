#include <SDL2/SDL.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>
#include "../heads/world.h"
#include "../heads/world_graphics.h"
#include "../heads/world_test.h"

#define TEST_COUNT 3
#define START_ITER 1000
#define DELTA_ITER 500
#define TEST_HEIGHT 100
#define TEST_WIDTH 250

double SE(casovna_t *c, int DEBUG) {
    double s = 0.0, sum = 0.0;
    int i;
    for(i = 0; i < c->len; i++) {
        sum += (c->tab[i] - c->povp) * (c->tab[i] - c->povp);
    }
    s = sum/(c->len - 1);
    s = sqrt(s)/sqrt(c->len);
    if(DEBUG) printf("---SE: %f\n", s);
    return s;
}

casovna_t* casovna_analiza_openCL(int n, int visina, int sirina, int st_iteracij, int DEBUG) {
    casovna_t* ct = malloc(sizeof(casovna_t));
    world *w = createWorld(visina, sirina);
    ct->tab = malloc(sizeof(double)*n);
    int i;
    double sum_time = 0, tmp_time;
    if(DEBUG) printf("---v:%d, s:%d, st_iteracij:%d :: %3d OCL---\n", visina, sirina, st_iteracij, omp_get_num_threads());
    for(i = 0; i < n; i++) {
        tmp_time = simulatemax_ocl(w, st_iteracij);
        if(DEBUG) printf("cas %3d: %.2f ms\n", i, tmp_time);
        ct->tab[i] = tmp_time;
        sum_time += tmp_time;
    }
    ct->sum = sum_time;
    sum_time /= n;
    ct->povp = sum_time;
    ct->len = n;
    if(DEBUG) {
        printf("povprecen cas: %.4f ms\n", sum_time);
        printf("standard error: %.4f ms\n", SE(ct, 0));
        printf("\n\n");
    }
    return ct;
}

casovna_t* casovna_analiza_1_nit(int n, int visina, int sirina, int st_iteracij, int DEBUG) {
    casovna_t* ct = malloc(sizeof(casovna_t));
    world *w = createWorld(visina, sirina);
    ct->tab = malloc(sizeof(double)*n);
    int i;
    double sum_time = 0, tmp_time;
    if(DEBUG) printf("---v:%d, s:%d, st_iteracij:%d :: 1 NIT---\n", visina, sirina, st_iteracij);
    for(i = 0; i < n; i++) {
        tmp_time = simulateMax(w, st_iteracij);
        if(DEBUG) printf("cas %3d: %.2f ms\n", i, tmp_time);
        ct->tab[i] = tmp_time;
        sum_time += tmp_time;
    }
    ct->sum = sum_time;
    sum_time /= n;
    ct->povp = sum_time;
    ct->len = n;
    if(DEBUG) {
        printf("povprecen cas: %.4f ms\n", sum_time);
        printf("standard error: %.4f ms\n", SE(ct, 0));
        printf("\n\n");
    }
    return ct;
}

casovna_t* casovna_analiza_vec_niti_OMP(int n, int visina, int sirina, int st_iteracij, int st_niti, int DEBUG) {
    casovna_t* ct = malloc(sizeof(casovna_t));
    world *w = createWorld(visina, sirina);
    ct->tab = malloc(sizeof(double)*n);
    int i;
    double sum_time = 0, tmp_time;
    omp_set_num_threads(st_niti);
    if(DEBUG) printf("---v:%d, s:%d, st_iteracij:%d :: %3d OMP---\n", visina, sirina, st_iteracij, omp_get_num_threads());
    for(i = 0; i < n; i++) {
        tmp_time = simulateOMPMax(w, st_iteracij);
        if(DEBUG) printf("cas %3d: %.2f ms\n", i, tmp_time);
        ct->tab[i] = tmp_time;
        sum_time += tmp_time;
    }
    ct->sum = sum_time;
    sum_time /= n;
    ct->povp = sum_time;
    ct->len = n;
    if(DEBUG) {
        printf("povprecen cas: %.4f ms\n", sum_time);
        printf("standard error: %.4f ms\n", SE(ct, 0));
        printf("\n\n");
    }
    return ct;
}

casovna_t* casovna_analiza_vec_niti(int n, int visina, int sirina, int st_iteracij, int st_niti, int DEBUG) {
    casovna_t* ct = malloc(sizeof(casovna_t));
    world *w = createWorld(visina, sirina);
    ct->tab = malloc(sizeof(double)*n);
    int i;
    double sum_time = 0, tmp_time;
    if(DEBUG) printf("---v:%d, s:%d, st_iteracij:%d :: %3d NITI---\n", visina, sirina, st_iteracij, st_niti);
    for(i = 0; i < n; i++) {
        tmp_time = simulateMaxMulty(w, st_niti, st_iteracij);
        if(DEBUG) printf("cas %3d: %.2f ms\n", i, tmp_time);
        ct->tab[i] = tmp_time;
        sum_time += tmp_time;
    }
    ct->sum = sum_time;
    sum_time /= n;
    ct->povp = sum_time;
    ct->len = n;
    if(DEBUG) {
        printf("povprecen cas: %.4f ms\n", sum_time);
        //printf("casovna_t:%p tab:%p len:%d\n", ct, ct->tab, ct->len);
        printf("standard error: %.4f ms\n", SE(ct, 0));
        printf("\n\n");
    }
    return ct;
}

casovna_t* casovna_analiza_vec_niti2(int n, int visina, int sirina, int st_iteracij, int st_niti, int DEBUG) {
    casovna_t* ct = malloc(sizeof(casovna_t));
    world *w = createWorld(visina, sirina);
    //initTest(w);
    //printWorld(w);

    if(DEBUG) {printf("multy2:\n");}
    ct->tab = malloc(sizeof(double)*n);
    int i;
    double sum_time = 0, tmp_time;
    if(DEBUG) printf("---v:%d, s:%d, st_iteracij:%d :: %3d NITI---\n", visina, sirina, st_iteracij, st_niti);
    for(i = 0; i < n; i++) {
        tmp_time = simulateMaxMulty2(w, st_niti, st_iteracij);
        //printWorld(w);
        if(DEBUG) printf("cas %3d: %.2f ms\n", i, tmp_time);
        ct->tab[i] = tmp_time;
        sum_time += tmp_time;
    }
    ct->sum = sum_time;
    sum_time /= n;
    ct->povp = sum_time;
    ct->len = n;
    if(DEBUG) {
        printf("povprecen cas: %.4f ms\n", sum_time);
        //printf("casovna_t:%p tab:%p len:%d\n", ct, ct->tab, ct->len);
        printf("standard error: %.4f ms\n", SE(ct, 0));
        printf("\n\n");
    }
    return ct;
}

void initTest(world *w) {
    w->area[5][3] = 1;
    w->area[4][4] = 1;
    w->area[3][4] = 1;
    w->area[3][2] = 1;
    w->area[2][4] = 1;
    w->area[1][3] = 1;
    w->area[3][5] = 1;
}

void initWorld(world *w) {
    w->area[15][2] = 1;
    w->area[15][1] = 1;
    w->area[16][2] = 1;
    w->area[16][1] = 1;

    w->area[15][11] = 1;
    w->area[16][11] = 1;
    w->area[17][11] = 1;
    w->area[14][12] = 1;
    w->area[13][13] = 1;
    w->area[13][14] = 1;
    w->area[18][12] = 1;
    w->area[19][13] = 1;
    w->area[19][14] = 1;

    w->area[18][16] = 1;
    w->area[17][17] = 1;
    w->area[16][17] = 1;
    w->area[16][15] = 1;
    w->area[15][17] = 1;
    w->area[14][16] = 1;
    w->area[16][18] = 1;

    w->area[14][21] = 1;
    w->area[15][21] = 1;
    w->area[16][21] = 1;
    w->area[14][22] = 1;
    w->area[15][22] = 1;
    w->area[16][22] = 1;
    w->area[17][23] = 1;
    w->area[17][25] = 1;
    w->area[18][25] = 1;
    w->area[13][23] = 1;
    w->area[13][25] = 1;
    w->area[12][25] = 1;

    w->area[13][35] = 1;
    w->area[13][36] = 1;
    w->area[14][35] = 1;
    w->area[14][36] = 1;

}

/*
    Inicializa zacetni svet: kvadrati v vogalih
*/
void initInf2World(world *w) {

    w->area[0][0] = 1;
    w->area[0][1] = 1;
    w->area[1][0] = 1;
    w->area[1][1] = 1;

    w->area[0][w->width-1] = 1;
    w->area[0][w->width-2] = 1;
    w->area[1][w->width-1] = 1;
    w->area[1][w->width-2] = 1;

    w->area[w->height-1][0] = 1;
    w->area[w->height-1][1] = 1;
    w->area[w->height-2][0] = 1;
    w->area[w->height-2][1] = 1;

    w->area[w->height-1][w->width-1] = 1;
    w->area[w->height-1][w->width-2] = 1;
    w->area[w->height-2][w->width-1] = 1;
    w->area[w->height-2][w->width-2] = 1;

}

/*
    Inicializa zacetni svet za demo, svet mora biti vecji ali enak 94x94 celic
*/
void initInfWorld(world *w) {

    w->area[0][0] = 1;
    w->area[0][1] = 1;
    w->area[1][0] = 1;
    w->area[1][1] = 1;

    w->area[0][w->width-1] = 1;
    w->area[0][w->width-2] = 1;
    w->area[1][w->width-1] = 1;
    w->area[1][w->width-2] = 1;

    w->area[w->height-1][0] = 1;
    w->area[w->height-1][1] = 1;
    w->area[w->height-2][0] = 1;
    w->area[w->height-2][1] = 1;

    w->area[w->height-1][w->width-1] = 1;
    w->area[w->height-1][w->width-2] = 1;
    w->area[w->height-2][w->width-1] = 1;
    w->area[w->height-2][w->width-2] = 1;

    w->area[4][4] = 1;
    w->area[4][5] = 1;
    w->area[5][4] = 1;
    w->area[5][5] = 1;

    w->area[3][80] = 1;
    w->area[3][81] = 1;
    w->area[4][80] = 1;
    w->area[4][81] = 1;

    w->area[10][10] = 1;
    w->area[10][11] = 1;
    w->area[10][12] = 1;
    w->area[9][12] = 1;
    w->area[8][11] = 1;

    w->area[20][80] = 1;
    w->area[20][81] = 1;
    w->area[20][82] = 1;
    w->area[19][80] = 1;
    w->area[18][81] = 1;

    w->area[50][50] = 1;
    w->area[50][51] = 1;
    w->area[50][52] = 1;

    w->area[60][60] = 1;
    w->area[60][61] = 1;
    w->area[60][62] = 1;
    w->area[61][63] = 1;
    w->area[61][61] = 1;
    w->area[61][62] = 1;

    w->area[90][90] = 1;
    w->area[91][90] = 1;
    w->area[90][91] = 1;
    w->area[91][91] = 1;
    w->area[92][92] = 1;
    w->area[92][93] = 1;
    w->area[93][92] = 1;
    w->area[93][93] = 1;
}
