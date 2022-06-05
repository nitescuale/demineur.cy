/////////////////////////////////
/// Surrounding Bombs Function///                                              // adds 1 around each i,j bomb, from i-1,j-1 to i+1,j+1
/////////////////////////////////


void BombsAdd(){
  int P,K;
  for(int i=0;i<sizei;i++){                                                       // priority : corners first, then rows and columns, then the rest
      for(int j=0;j<sizej;j++){
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
