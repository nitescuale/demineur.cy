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
