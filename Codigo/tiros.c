

#include <stdio.h>
#include <raylib.h>
#include <math.h>


typedef struct TIRO{
    Vector2 pos;
    float sentido;
    float velocidade;
    float raio;
}TIRO;

TIRO maketiro(Vector2 pos , float sentido , float velocidade)
{
    TIRO tiro;

    tiro.pos = pos;
    tiro.sentido = sentido;
    tiro.velocidade = velocidade;

    return tiro;
}

int dispara(){
    TIRO tiro = (TIRO){ { 70 , 70 } , 0 ,  2 , 5 };

    SetTargetFPS(60);

    do{
        
        if( IsKeyPressed( KEY_SPACE ) ){

            maketiro(tiro.pos, tiro.sentido, tiro.velocidade);
        }

        tiro.pos.x += tiro.velocidade * cos( tiro.sentido );
        tiro.pos.y += tiro.velocidade * sin( tiro.sentido );

        BeginDrawing();
            ClearBackground( RAYWHITE );
            DrawCircleV( tiro.pos , tiro.raio , RED );
        EndDrawing();


    }while( !WindowShouldClose() );


    return 0;
}

