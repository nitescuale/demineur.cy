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
