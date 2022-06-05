  ////////////////////////
 /// scanfpb Function ///                                                         // to make sure letters won't make an int choice bug
////////////////////////

void scanfpb(){
    int c = 0;
    while (c != '\n' && c != EOF)
    {
        c = getchar();
    }
} 