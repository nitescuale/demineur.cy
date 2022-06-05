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
