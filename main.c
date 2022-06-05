int main(){
    int c, win,goon, nom, diff, replay;
    char a ;
    srand(time(NULL));
    printf(" ________________________________\n" );
    printf("|                                |\n" );
    printf("|        Jeu du demineur         |\n" );
    printf("|________________________________|\n\n\n" );

    Rules();

    diff=difficulty();

    Initialisation();

    printf("\nCombien de mines voulez-vous ?\n\n");
    scanf("%d",&bombsNum);
    while(bombsNum>=sizej*sizei/6.5){
        printf("\nVous avez choisi trop de bombes, veuillez ressayer :)\n\n" );
        scanf("%d",&bombsNum);
    }
    printf("D'accord, vous avez choisi de jouer avec %d mines\n\n",bombsNum);

    time_t begin = time( NULL );
    PlaceBomb();
    BombsAdd();
    Clean();
    ShowGame();
    do {
        goon = Choice();
        ShowGame();
        win = nbHidden()==bombsNum;
    } while ( !win && goon);
    time_t end = time( NULL);
    unsigned long secondes = (unsigned long) difftime( end, begin );
    printf("%d", diff);
    if (win==1){
        printf( "Félicitations, vous avez gagné en %ld sec !!\n", secondes );
        printf( "Quel est votre nom?\n");
        scanf("%s", &nom);
        FILE * scores;
        scores = fopen("Scores.txt", "ab+");
        if (scores != NULL){
            fprintf(scores, "\n %s : %ld (Facile)", &nom, secondes);
            fclose(scores);
        }
        else
            perror("Scores.txt");
    } else {
    printf( "BOOM !! Perdu...\n");
    }
    printf( "Rejouer ?\n");
    printf( "1.Oui\n");
    printf( "2.Non\n");
    scanf("%d",&replay);
    while(replay != 1 && replay!=2){
        printf("Erreur, il faut entrer 1 ou 2 !");
        scanf("%d", &replay);
        if (replay==1){
            main();
        }
    }
    return 0;
}
