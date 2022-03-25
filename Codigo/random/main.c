// TODO: implementar tela de creditos

#include <raylib.h>
#include <stdlib.h>
#include "credits.h"
#include "start.h"


// Main entry point
int main(void){
    // Initialization
    const int screenWidth = 800;
    const int screenHeight = 450;
    int select = -1;

    InitWindow(screenWidth, screenHeight, "BattleINF");
    InitAudioDevice();
    
    while (select != 4){
        
        select = start();
        
        switch (select){
            case 0:
            {
                select = player();
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