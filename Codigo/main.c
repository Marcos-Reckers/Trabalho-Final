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
    int select = -1;

    InitWindow(screenWidth, screenHeight, "BattleINF");
    InitAudioDevice();
    
    while (select != 4){
        
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
    }

    CloseWindow();

    return 0;
}