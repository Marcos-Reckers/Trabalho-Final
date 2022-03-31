#include <raylib.h>
#include "screen.h"
#include "credits.h"
#include "start.h"
#include "play.h"
#include "highscores.h"
#include "inputNames.h"


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
                select = play();

                if (select == 0)
                {
                    inputNames();
                    highscores();
                }
            } break;

            case 1:
            {
                //TODO: implementar tela de load
            } break;

            case 2:
            {
                select = highscores();
            } break;


            case 3:
            {
                select = credits();
            } break;
        }
         if (WindowShouldClose())
        {
            select = 4;
        }
    } while (select != 4);

    CloseWindow();

    return 0;
}