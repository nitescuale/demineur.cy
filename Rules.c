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
