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
