/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby,
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

char Playground[100][100];                                                      // define max Playground
int sizei = 100, sizej = 100, i, j;                                             // declare, i for rows and j for columns
char BOOM [100][100];                                                           // hidden Playground (with all the values, used for testing)
int bombsNum;                                                                   // declare, number of bombs choosed by the player

  //////////////////////
 /// Rules Function ///                                                         // Used in case the player doesn't know the rules yet
//////////////////////

void Rules(){
    int rep ;
    printf("Bonjour, ceci est le jeu du démineur, avant de commencer à jouer, souhaitez-vous un rappel des règles du jeu ? \n");
    printf("1. Oui \n");
    printf("2. Non \n");
    scanf("%d", &rep);
    while(rep != 1 && rep!=2){
        printf("Erreur, il faut entrer 1 ou 2 !");
        scanf("%d", &rep);
    }
    if (rep == 1 ){
        printf("\n Voici les règles du jeu :\n Le but des différents jeux du démineur en ligne est simple. Il faut découvrir toutes les cases libres sans faire exploser les mines présentes dans la grille. Vous pouvez placer un drapeau sur une case que vous pensez être une bombe. Les numéros qui s'affichent sur les cases que vous aurez révélées représentent le nombre de bombes sur les 8 cases autour de cette dernière. Plus vous irez vite, meilleur sera votre score ! Bonne chance :) \n\n\n");
    }
    if (rep == 2){
        printf("\n\n\n Le jeu va débuter !\n\n\n");
    }
}


  ///////////////////////////////
 /// Initialisation Function ///                                                // fills the arrays
///////////////////////////////
void Initialisation(){
    for(i=0;i<sizei;i++){
           for(j=0;j<sizej;j++){
                Playground[i][j]='-';                                           // - is used for hidden boxes
                BOOM [i][j]= 0;
           }
    }
}


  /////////////////////////////
 /// custom sizes Function ///                                                  // allows i and j to be chosen
/////////////////////////////

int sizeiCustom(){
    printf("Nombre de lignes ?\n");
    scanf("%d", &sizei);
    return sizei;
}

int sizejCustom(){
    printf("Nombre de colonnes ?\n");
    scanf("%d", &sizej);
    return sizej;
}




  ///////////////////////////
 /// difficulty Function ///                                                    // allows player to chose between 1.Easy (9x9) 2.Medium (16x16) and 3.Custom (max: 100x100, can be rectangular thanks to sizei and sizej)
///////////////////////////

int difficulty(){
    int size;
    printf("Quelle sera la taille de votre tableau ?\n");
    printf("1.Facile (9x9)\n");
    printf("2.Standard (16x16)\n");
    printf("3.Custom (max 100x100, can be rectangular)\n");
    scanf("%d", &size);
    while(size<1 || size>3){
        printf("Entrez un choix valide\n");
        scanf("%d", &size);
    }
    if (size==1){
        sizei = 9;
        sizej = 9;
        return size;
    }
    if (size==2){
        sizei = 16;
        sizej = 16;
        return size;

    } if (size==3){
        sizei = sizeiCustom();
        sizej = sizejCustom();
        return size;
    }
}

  //////////////////////////
 /// ShowGame Function  ///                                                     // prints the playground, seen by the player
//////////////////////////

void ShowGame (){
    printf("\n\n" );

    printf("   |");
    for (j=0; j<sizej; j++){
        if (j<10){
            printf(" %d ",j );
        } else {
            printf("%d ",j );
        }
    }
    printf("\n");
    printf("___|");
    for (j=0; j<sizej; j++){
        printf("___" );
    }
    printf("\n");

    for(i=0;i<sizei;i++){
        if (i<10){
            printf(" %d | ",i);
        } else {
            printf("%d | ",i);
        }
        for(j=0;j<sizej;j++){
            printf("%c  ",Playground[i][j]);
        }
        printf("\n" );
    }
}

  ////////////////////////////
 /// hiddenGame Function  ///                                                     // prints the hidden/test playground, used to see if everything worked well
////////////////////////////

void hiddenGame (){
    printf("\n\n" );
    printf("   |");
    for (j=0; j<sizej; j++){
        if (j<10){
            printf(" %d ",j );
        } else {
            printf("%d ",j );
        }
    }
    printf("\n");
    printf("___|");
    for (j=0; j<sizej; j++){
        printf("___" );
    }
    printf("\n");

    for(i=0;i<sizei;i++){
        if (i<10){
            printf(" %d | ",i);
        } else {
            printf("%d | ",i);
        }
        for(j=0;j<sizej;j++){
            printf("%d  ",BOOM[i][j]);
        }
        printf("\n" );
    }
}

  ///////////////////////////////
 /// Showbox/reveal Function ///                                                // after i,j input, reveals the box at i,j coordinates, returns used as exits for the Function
///////////////////////////////                                                 // return 0 in case i,j is a bomb, used in a later function as a lose condition

int Showbox(int i, int j){
int P, K, bomb;
    if (Playground[i][j]!='-'){                                                 // if i, j != '-', i, j has already been revealed
        return 1;
    }
    if(BOOM[i][j]>=1 && BOOM[i][j]<=8){
        Playground[i][j]=BOOM[i][j]+48;
    } else if(BOOM[i][j]==9){                                                   // if i,j is  a bomb, reveals all the boxes, marking bombs as 'X'
        for(i=0;i<sizei;i++){
            for(j=0;j<sizej;j++){
                if(BOOM[i][j]==9){
                    Playground[i][j]='X';
                } else {
                    Playground[i][j]=BOOM[i][j]+48;
                }
            }
        }
        return 0;
    } else if(BOOM[i][j]==0){                                                   // if i,j is a 0, meaning no bombs surround it, reveals all the surrounding boxes (from i-1,j-1 to i+1, j+1), recusivity if it's an 0 again
                Playground[i][j]='0';
                for(P=-1;P<2;P++){
                        for(K=-1;K<2;K++){
                            if (i+P>=0 && i+P<=sizei && j+K>=0 && j+K<=sizej){
                                if(BOOM[i+P][j+K]==0){
                                    Showbox(i+P, j+K);
                                } else if(BOOM[i+P][j+K]>=1 && BOOM[i+P][j+K]<=8){
                                    Playground[i+P][j+K]=BOOM[i+P][j+K]+48;
                                }
                            }
                        }
                }
    }
    return 1;
}

  ////////////////////
 /// Win Function ///                                                           // counts the number of hidden boxes (hidden '-' + flags'#'), with int hidden later used as a win condition
////////////////////

int nbHidden(){
    int hidden=0;
    for(i=0;i<sizei;i++){
        for(j=0;j<sizej;j++){
            if (Playground[i][j]=='-' || Playground[i][j]=='#'){
            hidden ++;
            }
        }
    }
    printf("\n" );
    return hidden;
}

  ////////////////////////////
 /// Turn Choice Function ///
////////////////////////////

int Choice(){                                                                   // return 0 = lost, 1 = continue
    int rep, i, j;
    printf ("Quelle case souhaitez-vous modifier ?\n");
    printf ("Ligne :");
    scanf("%d", &i);
    while(i<0 || i>sizei-1){                                                    // doesn't allow you to chose an i beyond sizei
        printf ("Cette ligne n'existe pas !\n");
        printf ("Ligne :");
        scanf("%d", &i);
    }
    printf ("Colonne :");
    scanf("%d", &j);
    while(j<0 || j>sizej-1){                                                    // doesn't allow you to chose a j beyond sizej
        printf ("Cette colonne n'existe pas !\n");
        printf ("Colonne :");
        scanf("%d", &j);
    }
    while (Playground[i][j]!= '#' && Playground[i][j]!= '-'){                   // restart if the box has already been revealed or flagged
        printf("Cette case est déjà affichée !\n");
        printf ("Quelle case souhaitez-vous modifier ?\n");
        printf ("Ligne :");
        scanf("%d", &i);
        while(i<0 || i>sizei-1){
            printf ("Cette ligne n'existe pas !\n");
            printf ("Ligne :");
            scanf("%d", &i);
        }
        printf ("Colonne :");
        scanf("%d", &j);
        while(j<0 || j>sizej-1){
            printf ("Cette colonne n'existe pas !\n");
            printf ("Colonne :");
            scanf("%d", &j);
        }
    }
    printf("Voulez-vous afficher ou marquer la case ? \n");
    if(Playground[i][j]=='#'){                                                  // flag option becomes remove flag if i,j is already a flag
            printf("1. Afficher \n");
            printf("2. Retirer le drapeau \n");
            scanf("%d", &rep);
            while(rep != 1 && rep!=2){
                printf("erreur, il faut entrer 1 ou 2 comme valeur");
                scanf("%d", &rep);
            }
        if (rep == 1){
            return Showbox(i, j);                                               //Showbox returns 0 if i,j is a 9, else return 1
        }
        if (rep == 2){
            Playground[i][j]='-';
            return 1;
        }
    } else {
        printf("1. Afficher \n");
        printf("2. Drapeau \n");
        scanf("%d", &rep);
        while(rep != 1 && rep!=2){
            printf("erreur, il faut entrer 1 ou 2 comme valeur");
            scanf("%d", &rep);
        }
        if (rep == 1){
        return Showbox(i, j);
        }
        if (rep == 2){
            Playground[i][j]='#';
            return 1;
        }
    }
}


  /////////////////////////////
 /// Bombs Placing Function///                                                  // places the bombs
/////////////////////////////
void PlaceBomb(){

    int ConterBomb;
    for (ConterBomb=0;ConterBomb<bombsNum;ConterBomb++){
        i=rand()%sizei;                                                         // chooses random row
        j=rand()%sizej;                                                         // chooses random column
        if(BOOM[i][j]==0){                                                      // checks if isn't already a bomb
            BOOM[i][j]= 9;                                                      // place bomb as a 9
        }
        else{
            bombsNum++;                                                         // does the loop one more time if i,j is already a bomb
        }
    }
}


  /////////////////////////////////
 /// Surrounding Bombs Function///                                              // adds 1 around each i,j bomb, from i-1,j-1 to i+1,j+1
/////////////////////////////////


void BombsAdd(){
    int P,K;
    for(i=0;i<sizei;i++){                                                       // priority : corners first, then rows and columns, then the rest
        for(j=0;j<sizej;j++){
            if(BOOM[i][j]>=9){
                if(i==0 && j==0){                                               // top left corner
                    for(P=0;P<2;P++){
                        for(K=0;K<2;K++){
                            BOOM[i+P][j+K]=BOOM[i+P][j+K]+1;
                        }
                    }

                } else if(i==0 && j==sizej-1){                                  // top right corner
                        for(P=0;P<2;P++){
                            for(K=-1;K<1;K++){
                                BOOM[i+P][j+K]=BOOM[i+P][j+K]+1;
                            }
                        }
                } else if(i==sizei-1 && j==0){                                  // bottom left corner
                        for(P=0;P<2;P++){
                            for(K=-1;K<1;K++){
                                BOOM[i+P][j+K]=BOOM[i+P][j+K]+1;
                            }
                        }
                } else if(i==sizei-1 && j==sizej-1){                            // bottom right corner
                        for(P=-1;P<1;P++){
                            for(K=-1;K<1;K++){
                                BOOM[i+P][j+K]=BOOM[i+P][j+K]+1;
                            }
                        }
                } else if(i==sizei-1){                                          // bottom row
                        for(P=-1;P<1;P++){
                            for(K=-1;K<2;K++){
                                BOOM[i+P][j+K]=BOOM[i+P][j+K]+1;
                            }
                        }
                } else if(j==0){                                                // left column
                        for(P=-1;P<2;P++){
                            for(K=0;K<2;K++){
                                BOOM[i+P][j+K]=BOOM[i+P][j+K]+1;
                            }
                        }
                } else if(j==sizej-1){                                          // right column
                        for(P=-1;P<2;P++){
                            for(K=-1;K<1;K++){
                                BOOM[i+P][j+K]=BOOM[i+P][j+K]+1;
                            }
                        }
                } else if(i==0){                                                // top row
                        for(P=0;P<2;P++){
                            for(K=-1;K<2;K++){
                                BOOM[i+P][j+K]=BOOM[i+P][j+K]+1;
                            }
                        }
                } else if(i>0 || i<sizei-1 || j>0 || j<sizej-1){                // rest
                        for(P=-1;P<2;P++){
                            for(K=-1;K<2;K++){
                                BOOM[i+P][j+K]=BOOM[i+P][j+K]+1;
                            }
                        }
                }
            }
        }
    }
}

  ////////////////////////
 /// Cleaning Function///                                                       // after the +1 around the bombs, make it that all the bombs = 9 and not 10, 11, etc.
////////////////////////

void Clean(){
    for(i=0;i<sizei;i++){
        for(j=0;j<sizej;j++){
                if (BOOM[i][j]>9){
                    BOOM[i][j]=9;
            }
        }
   }
}


/////////////////////////////////////////////////////////////////////////////
int main(){
    int c, win,goon, nom, diff, replay;
    char a ;
    srand(time(NULL));
    printf(" ________________________________\n" );
    printf("|                                |\n" );
    printf("|        Jeu du demineur         |\n" );
    printf("|________________________________|\n\n\n" );

    Rules();

    diff=difficulty();

    Initialisation();

    printf("\nCombien de mines voulez-vous ?\n\n");
    scanf("%d",&bombsNum);
    while(bombsNum>=sizej*sizei/6.5){
        printf("\nVous avez choisi trop de bombes, veuillez ressayer :)\n\n" );
        scanf("%d",&bombsNum);
    }
    printf("D'accord, vous avez choisi de jouer avec %d mines\n\n",bombsNum);

    time_t begin = time( NULL );
    PlaceBomb();
    BombsAdd();
    Clean();
    ShowGame();
    do {
        goon = Choice();
        ShowGame();
        win = nbHidden()==bombsNum;
    } while ( !win && goon);
    time_t end = time( NULL);
    unsigned long secondes = (unsigned long) difftime( end, begin );
    if (win==1){
        printf( "Félicitations, vous avez gagné en %ld sec !!\n", secondes );
        printf( "Quel est votre nom?\n");
        scanf("%s", &nom);
        FILE * scores;
        scores = fopen("Scores.txt", "ab+");
        if (scores != NULL){
            fprintf(scores, "\n %s : %ld (Facile)", &nom, secondes);
            fclose(scores);
        }
        else
            perror("Scores.txt");
    } else {
    printf( "BOOM !! Perdu...\n");
    }
    printf( "Rejouer ?\n");
    printf( "1.Oui\n");
    printf( "2.Non\n");
    scanf("%d",&replay);
    while(replay != 1 && replay!=2){
        printf("Erreur, il faut entrer 1 ou 2 !");
        scanf("%d", &replay);
        if (replay==1){
            main();
        }
    }
    return 0;
}
