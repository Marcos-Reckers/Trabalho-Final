#ifndef tiros_H_
#define tiros_H_
typedef struct TIRO{
    Vector2 pos;
    float sentido;
    float velocidade;
    float raio;
}TIRO;
TIRO maketiro(Vector2 pos , float sentido , float velocidade);
int dispara(void);
#endif