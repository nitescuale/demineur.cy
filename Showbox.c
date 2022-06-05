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
