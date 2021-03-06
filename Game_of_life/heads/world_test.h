#ifndef _WORLD_TEST_H_
#define _WORLD_TEST_H_

typedef struct {
    double *tab, povp, sum;
    int len;
} casovna_t;

void        initInfWorld(world*);
void        initInf2World(world*);
void        initWorld(world*);
void        initTest(world*);

double      SE(casovna_t*, int);

casovna_t*  casovna_analiza_1_nit(int, int, int, int, int);
casovna_t*  casovna_analiza_vec_niti(int, int, int, int, int, int);
casovna_t*  casovna_analiza_vec_niti_OMP(int, int, int, int, int, int);
casovna_t*  casovna_analiza_vec_niti2(int, int, int, int, int, int);
casovna_t* casovna_analiza_openCL(int, int, int, int, int);

#endif