// TODO: implementar tela de creditos

#include <raylib.h>
#include "screen.h"
#include <stdlib.h>
#include "credits.h"
#include "start.h"
#include "game.h"


// Main entry point
int main(void){
    // Initialization
    int select;

    InitWindow(screenWidth, screenHeight, "BattleINF");
    InitAudioDevice();
    
    do{    
        select = start();
        
        switch (select){
            case 0:
            {
                select = game();
            } break;

            case 3:
            {
                select = credits();
            } break;
        }
    } while (select != 4);

    CloseWindow();

    return 0;
}