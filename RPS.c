#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <process.h>
#include <malloc.h>
#include <time.h>
FILE *fp;
int *highscore;

char* onThree(){
//Generates a random choice from the computer. It returns this as a char*, not a char[].
int randomGen = 0;
char robotRandArray[1];
//char* robotRandCharPointer = (char* )malloc(20 * sizeof(char));
char* robotRandCharPointer;
robotRandCharPointer = robotRandArray;
srand(time(0));
randomGen = rand()%3;
if(randomGen == 0){
  strncpy(robotRandArray, "R", 1);
}
else if(randomGen == 1){
  strncpy(robotRandArray, "P", 1);
}
else{
  strncpy(robotRandArray, "S", 1);
}
return robotRandCharPointer;
//free(robotRandCharPointer);
}


int outcome (char* userchoice, char* botchoice){
//userchoice  = (char* )malloc(20 * sizeof(char));
//botchoice  = (char* )malloc(20 *sizeof(char));
  //Returns a 0 or 1 to add to the current score, based on the comparisons of the player and computer choices. this also contains a function for changing the highscore back
  //to 1 via overwriting the source file for said score.
  int result = 0;
  if(strcmp(userchoice,"Z") == 0){
    printf("Reseting high score to default.........");
    fp = fopen("C:/Users/calum/Desktop/RPS Sim/highscoresourcefile.txt", "w+");
    fprintf(fp, "1");
    *highscore = 1;
    exit(0);
  }
  //rock beats scissors, paper beats rock, scissors beats paper
  else if(strcmp(userchoice,"R") == 0 && strcmp(botchoice,"S") == 0){
    result = 1;
  }
  else if(strcmp(userchoice,"P") == 0 && strcmp(botchoice,"R") == 0){
    result = 1;
  }
  else if(strcmp(userchoice,"S") == 0 && strcmp(botchoice,"P") == 0){
    result = 1;
  }

  else{
    printf("Tie.\n");
    /*
    printf("User choice is %s\n", userchoice);
    printf("Bot choice is %s\n", botchoice);
    */
    result = 0;
  }
  return result;
//free(userchoice);
//free(botchoice);
}


int main(){
  //The process of this is to read the txt doc for a high score and call the onThree and outcome methods. onThree is to be stored in a char*, which is used to get a result from
  //outcome() that adds to the current score. This will go on for 60 seconds (in this case 60 rounds since I cannot get a timer to work) to where if the current score
  //is higher than the high score, a new txt doc is made based on that.
  char txtcontents[2];
  fp = fopen("C:/Users/calum/Desktop/RPS Sim/highscoresourcefile.txt", "r+");
  fgets(txtcontents, 2, fp);
  int hs = atoi(txtcontents);//atoi coinverts a string/char array to int or returns an error.
  highscore = &hs;
  int currentscore = 0;

  printf("Score to beat is %d!\n", hs);
  for(int i = 0; i < 3; i++){
    char user[1] = {""};
    printf("%s\n", user);
    while (strcmp(user,"R") != 0 && strcmp(user,"P") != 0 && strcmp(user,"S") != 0 && strcmp(user,"Z") != 0){
      printf("Type in your choice. ");
      scanf("%s", user);
    }

    //char* opponent  = (char*)malloc(20 * sizeof(char));
    char* opponent;
    char Pika[] = {"R"};
    //char Pika[] = {""};
    opponent = Pika;
    //strcpy(Pika,onThree());//This is where the garbage text comes from
    //strcpy(Pika,"R"); //after this line, user loses it's value?
    //printf("User is %s.\n", user);
    currentscore += outcome(user,opponent);
    printf("The current score is %d.\n", currentscore);
  }
  //free(opponent);
  if(currentscore > hs){
    hs = currentscore;
    fp = fopen("C:/Users/calum/Desktop/RPS Sim/highscoresourcefile.txt", "w+");
    fprintf(fp, "%d", hs);
  }
  else{
    printf("The high score is %d.\n", hs);
}
}

/*
char str[1024] = "Hello World";
char tmp[4] = ".";

void append(char* s, char c) {
        int len = strlen(s);
        s[len] = c;
        s[len+1] = '\0';
}

append(str, tmp);

char opponent[9] = " ";
*/
/*
void onThree(char* opponentchoice){
opponentchoice = malloc(sizeof(char));
int randomGen = 0;
char robotRandArray[1];

srand(time(0));
randomGen = rand()%3;

//char Rock[1] = "R";
//char Paper[1] = "P";
//char Scissors[1] = "S";

if(randomGen == 0){
  strncpy(opponentchoice , "R", 1);
}
else if(randomGen == 1){
  strncpy(opponentchoice , "P", 1);
}
else{
  strncpy(opponentchoice , "S", 1);
}
//opponentchoice = Rock;
//since this is a pointer, you don't have to return a value to change anything. Remember this technique!
}
*/
