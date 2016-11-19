#ifndef _WORLD_TEST_H_
#define _WORLD_TEST_H_

typedef struct {
    double *tab, povp, sum;
    int len;
} casovna_t;

void        initInfWorld(world*);
void        initInf2World(world*);
void        initWorld(world*);
void        initTest(world *w);
double      SE(casovna_t*, int);
casovna_t*  casovna_analiza_1_nit(int, int, int, int, int);
casovna_t*  casovna_analiza_vec_niti(int, int, int, int, int, int);
casovna_t*  casovna_analiza_vec_niti2(int n, int visina, int sirina, int st_iteracij, int st_niti, int DEBUG);

#endif