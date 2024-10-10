#include "GameState.h"

int main(int argc, char* argv[]) {
    initSDL();

    GameState::currentGameState = GameState::start;
    GameState::currentGameState->enter();

    while (true) {
        GameState::currentGameState->update();
    }

    GameState::currentGameState->exit();
    GameState::currentGameState->shutdown();
    return 0;
}











//states: start[play], menu[new game and exit], difficulty[easy and hard btn], welcome[left], instruction[left and right], 
        // funfacts[forward and back], game proper, result [home], 

//to improve: start button (buttons in fun fact), hovered and clicked effect, music hehe, trivia after result, 
// adjust dimensions, home button

//proceeding to funfact from instruction
//make hover more precise
