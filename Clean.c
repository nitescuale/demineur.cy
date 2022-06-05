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
