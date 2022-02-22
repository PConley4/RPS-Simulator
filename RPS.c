#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <process.h>
#include <malloc.h>
#include <time.h>
FILE *fp;
int *highscore;

char generateRPS(){
//randomly generates a num 1-3 and returns that value
char opponentchoice;
int randomGen = 0;
srand(time(0));
randomGen = rand()%3;

if(randomGen == 0){
  opponentchoice = 'R';
}
else if(randomGen == 1){
  opponentchoice = 'P';
}
else{
  opponentchoice = 'S';
}
printf("Opponent chooses: %c\n", opponentchoice);
return opponentchoice;
}

void resethighscore (){
  //Resets the score in the text source file.
  printf("Reseting high score to default.........");
  fp = fopen("C:/Users/calum/Desktop/RPS Simulator/highscoresourcefile.txt", "w+");
  fprintf(fp, "1");
  *highscore = 1;
  exit(0);
}


int outcome (char userchoice, char botchoice){
  //Returns a 0 or 1 to add to the current score, based on the comparisons of the player and computer choices. This also contains a function call for changing the highscore back
  //to 1 via overwriting the source file for said score.

  int result = 0;
  if(userchoice == 'M'){
    resethighscore();
  }
  //rock beats scissors, paper beats rock, scissors beats paper
  else if(userchoice == 'R' && botchoice == 'S'){
    printf("         Win!\n");
    result = 1;
  }
  else if(userchoice == 'P' && botchoice == 'R'){
    printf("         Win!\n");
    result = 1;
  }
  else if(userchoice == 'S' && botchoice == 'P'){
    printf("         Win!\n");
    result = 1;
  }

  else{
    printf("         Tie.\n");
    result = 0;
  }
  return result;
}


int main(){
  //The process of this is to read the txt doc for a high score and call the onThree and outcome methods. onThree is to be stored in a char*, which is used to get a result from
  //outcome() that adds to the current score. This will go on for 60 seconds (in this case 60 rounds since I cannot get a timer to work) to where if the current score
  //is higher than the high score, a new txt doc is made based on that.
  char txtcontents[2];
  fp = fopen("C:/Users/calum/Desktop/RPS Simulator/highscoresourcefile.txt", "r+");
  fgets(txtcontents, 2, fp);
  int hs = atoi(txtcontents);
  //atoi coinverts a string/char array to int or returns an error.
  highscore = &hs;
  int currentscore = 0;
  printf("Score to beat is %d!\n", hs);

  for(int i = 0; i < 60; i++){
    //char user = ' ';
    char user[3] = " \0";
    printf("%c\n", user[0]);

    char opponentRPS = ' ';
    opponentRPS = generateRPS();
    while (user[0] != 'R' && user[0] != 'P' && user[0] != 'S' && user[0] != 'M'){
      printf("Type in your choice.\n");
      scanf(" %c", user);
    }

    if(user[0] != 'M'){
      printf("Opponent is %c.\n", opponentRPS);
    }

    currentscore += outcome(user[0],opponentRPS);
    printf("The current score is %d.\n\n\n\n", currentscore);
  }
  if(currentscore > hs){
    hs = currentscore;
    fp = fopen("C:/Users/calum/Desktop/RPS Simulator/highscoresourcefile.txt", "w+");
    fprintf(fp, "%d", hs);
    printf("New high score!");
  }
  else{
    printf("The high score is %d.\n", hs);
}
}
