/*Program to convert a point p(x,y,z) in Retangular Coordenates to Cilindric - p(r,t,z) - and Spherical Coordinates p(r,f,t)*/
typedef struct pontor PontoR;

typedef struct pontocilindrico PontoCilindrico;

typedef struct pontoesferico PontoEsferico;

/*Cria um ponto Retangular (x,y)*/
PontoR* prCriar(float x, float y, float z);

/*Cria um ponto em coordenadas cilindricas (r,t,z)*/
PontoCilindrico* pcCriar(float r, float t, float z);

/*Cria um ponto em coordenadas esfericas (r,f,t), em que r é o raio, f é o angulo entre x e y e t é o angulo entre r e z*/
PontoEsferico* peCriar(float r, float f, float t);

/*Imprime as coordenadas do ponto (x,y,z)*/
void prPrintCoord(PontoR* pr);

/*Imprime as coordenadas do ponto(r,t,z) */
void pcPrintCoord(PontoCilindrico* pc);

/*Imprime as coordenadas do ponto(r,f,t) */
void pePrintCoord(PontoEsferico* pe);

/*Apaga ponto (x,y,z)*/
void prLiberar(PontoR* pr);

/*Apaga ponto(r,t,z)*/
void pcLiberar(PontoCilindrico* pc);

/*Apaga ponto(r,f,t)*/
void peLiberar(PontoEsferico* pe);

/*Soma dois pontos (x,y,z) e retorna o ponto resultante*/
PontoR* prSomar(PontoR* pr1, PontoR* pr2);

/*Subtrai dois pontos (x,y,z) e retorna o ponto resultante*/
PontoR* prSubtrair(PontoR* pr1, PontoR* pr2);

/*Retorna a distancia entre dois pontos (x,y,z)*/
float prDistancia(PontoR* pr1, PontoR* pr2);

/*Transforma ponto polar (r,t,z) em ponto cartesiano (x,y,z)*/
PontoR* transformarCilRet(PontoCilindrico* pc);

/*Transforma ponto retangular (x,y,z) em ponto cilindrico(r,t,z)*/
PontoCilindrico* transformarRetCil(PontoR* pr);

/*Transforma ponto esferico (r,f,t) em ponto retangular (x,y,z) */
PontoR* transformarEsfRet(PontoEsferico* pe);

/*Transforma ponto retangular (x,y,z) em ponto esferico (r,f,t)  */
PontoEsferico* transformarRetEsf(PontoR* pr);
