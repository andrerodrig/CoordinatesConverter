#include <stdio.h>
#include <stdlib.h>
#include "EsfCylRectConvert.h"
#include <math.h>

struct pontor{
	float x, y, z;
};

struct pontocilindrico {
	float r, t, z;
};

struct pontoesferico {
	float r, f, t;
};

/*Cria um ponto em coordenadas retangulares (x,y,z)*/
PontoR* prCriar(float x, float y, float z)
{
	PontoR* pr = (PontoR*) malloc(sizeof(PontoR));
	pr->x = x;
	pr->y = y;
	pr->z = z;
	return pr;
}

/*Cria um ponto em coordenadas cilindricas (r,t,z), em que r é o raio, t é o angulo em rad e z é a altura */
PontoCilindrico* pcCriar(float r, float t, float z)
{
	PontoCilindrico* pc = (PontoCilindrico*) malloc(sizeof(PontoCilindrico));
	pc->r = r;
	pc->t = t;
	pc->z = z;
	return pc;
}

/*Cria um ponto em coordenadas esfericas (r,f,t), em que r é o raio, f é o angulo entre x e y e t é o angulo entre r e z*/
PontoEsferico* peCriar(float r, float f, float t)
{
	PontoEsferico* pe = (PontoEsferico*) malloc(sizeof(PontoEsferico));
	pe->r = r;
	pe->f = f;
	pe->t = t;
	return pe;
}

/*Imprime as coordenadas do ponto(x,y,z) */
void prPrintCoord(PontoR* pr)
{
	printf("\n\tp(x,y,z) = (%f,%f,%f)\n", pr->x, pr->y, pr->z);
}

/*Imprime as coordenadas do ponto(r,t,z) */
void pcPrintCoord(PontoCilindrico* pc)
{
	printf("\n\tp(r,t,z) = (%f,%f,%f)\n", pc->r,pc->t,pc->z);
}

/*Imprime as coordenadas do ponto(r,f,t) */
void pePrintCoord(PontoEsferico* pe)
{
	printf("\n\tp(r,f,t) = (%f,%f,%f)\n", pe->r, pe->f, pe->t);
}


/*Apaga ponto(x,y,z)*/
void prLiberar(PontoR* pr)
{
	free(pr);
}

/*Apaga ponto(r,t,z)*/
void pcLiberar(PontoCilindrico* pc)
{
	free(pc);
}

/*Apaga ponto(r,f,t)*/
void peLiberar(PontoEsferico* pe)
{
	free(pe);
}

/*Soma dois pontos e retorna o ponto (x,y,z) resultante*/
PontoR* prSomar(PontoR* pr1, PontoR* pr2)
{
	return prCriar(pr1->x + pr2->x,pr1->y + pr2->y,pr1->z + pr2->z);
}

/*Subtrai dois pontos (x,y,z) e retorna o ponto resultante*/
PontoR* prSubtrair(PontoR* pr1, PontoR* pr2)
{
	return prCriar(pr2->x - pr1->x,pr2->y - pr1->y,pr2->z - pr1->z);
}

/*Retorna a distancia entre dois pontos (x,y,z)*/
float prDistancia(PontoR* pr1, PontoR* pr2)
{
	return sqrt(pow(pr1->x - pr2->x, 2) + pow(pr1->y - pr2->y, 2));
	
}

/*Transforma ponto cilindrico (r,t,z) em ponto retangular (x,y,z) */
PontoR* transformarCilRet(PontoCilindrico* pc)
{
	float x = pc->r*cos(pc->t);
	float y = pc->r*sin(pc->t);
	float z = pc->z;
	return prCriar(x,y,z);
}

/*Transforma ponto retangular (x,y,z) em ponto cilindrico(r,t,z)*/
PontoCilindrico* transformarRetCil(PontoR* pr)
{
	float r = sqrt(pr->x*pr->x + pr->y*pr->y);
	float t = atan(pr->y/pr->x);
	float z = pr->z;
	return pcCriar(r,t,z);
}

/*Transforma ponto esferico (r,f,t) em ponto retangular (x,y,z) */
PontoR* transformarEsfRet(PontoEsferico* pe)
{
	float x = pe->r*sin(pe->f)*cos(pe->t);
	float y = pe->r*sin(pe->f)*sin(pe->t);
	float z = pe->r*cos(pe->f);
	return prCriar(x,y,z);
}

PontoEsferico* transformarRetEsf(PontoR* pr)
{
	float r = sqrt(pr->x*pr->x + pr->y*pr->y + pr->z*pr->z);
	float f = acos(pr->z/r);
	float t = atan(pr->y/pr->x);
	return peCriar(r,f,t);
}
