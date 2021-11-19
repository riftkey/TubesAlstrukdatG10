#include "Game.h"
#include "../../ADT/Configuration/Configuration.h"
#include <stdio.h>
#include <string.h>

int playersPlaying = 0;
boolean isEndGame = false;
player players[4];

void GameView(int opsi) {
    if (opsi == 1) { //New Game
        NewGame();
    } else { //Load Game
        LoadGame();
    }
    setConfigFile();
    loadConfig();
    printf("\n Let's Start The Game!\n");
    displayMap();
    StartGame();
    if (isEndGame) {
        displayRank();
    }
    ExitGame();
}

void NewGame() {
    printf("Starting game...\n");
    printf("Hello new players!, welcome to Uler tenggi \n");
    printf("How many are playing today (minimum 2, max 4) ? : ");
    scanf("%d", &playersPlaying);
    //Setup how many players are playing
    if (playersPlaying < 1 || playersPlaying > 4) {
        NewGame();
    } else {
        for (int i = 0; i < playersPlaying; i++) {
            player temp;
            printf("Player %d name :",i+1);
            setPlayer(&temp);
            printf("\n");
            players[i] = temp;
        }
    }
}

void LoadGame() {

}

// The Game
void StartGame() {
    boolean exitGame = false;
    int round = 1;
    //Loop per ronde
    //while (!isEndGame) {
        printf("Round %d\n",round);
        for (int i = 0; i < playersPlaying; i++) {

        }
        round++;
    //}
}

void ExitGame() {
    freeTeleporters();
    if (isEndGame == 1) {
        //sort user based on position
    } else {
        // Save progress
    }
}

void displayRank() {
    for (int i = 0; i < playersPlaying; i++) {
        printf("Rank #%d : %s \n",i+1,players[i].name);
    }
}

void displayMap() {
    printf("Game map :\n");
    printf("%s\n",map);
}