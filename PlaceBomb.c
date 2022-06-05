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
