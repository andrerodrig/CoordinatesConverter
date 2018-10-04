#include <stdio.h>
#include <stdlib.h>
#include "EsfCylRectConvert.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	printf("Point in Rectangular Coordenates:");
	PontoR* pr = prCriar(10.0,10.0,10.0);
	prPrintCoord(pr);
	
	printf("Point in Cylindric Coordenates:");
	PontoCilindrico* pc = transformarRetCil(pr);
	pcPrintCoord(pc);
	
	printf("Point in Espherical Coordenates:");
	PontoEsferico* pe = transformarRetEsf(pr);
	pePrintCoord(pe);
	return 0;
}
