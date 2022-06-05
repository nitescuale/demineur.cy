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
