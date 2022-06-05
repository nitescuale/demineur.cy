# Démineur

Projet d’informatique de pré ing 1, à Cy-tech, réalisé par Alexandru Nitescu et Mohamed Amine Khaldi.

## Lancement

Il vous suffit de compiler le projet via la commande "make", et d'ensuite lancer l'exécutable demineur. 

⚠️ Le Makefile ne fonctionne que sur Linux
⚠️ Nécessite Make et GCC

## Utilisation

### Commencement de la partie
Premièrement, vous aurez le choix entre afficher les règles du démineur ou ne pas si vous les connaissez déjà. Il vous sera alors demandé de choisir la taille du plateau de jeu, parmi les trois options suivantes : 
Facile, un tableau de 9 x 9
Standard : un tableau de 16 x 16
Custom : vous choisissez la taille que vous voulez (max. 100x100, possibilité d'être rectangulaire)

Vous pouvez choisir autant de bombes que vous voulez, mais attention, il faut en mettre un minimum ! Et pareil, n’essayez pas d’en mettre 20.000 ! ;)
Le chrono se lance et le plateau se présente à vous, la partie peut commencer ! Vous pourrez commencer à jouer, en sélectionnant la ligne puis la colonne de la case que vous souhaitez soit révéler, soit marquer par un drapeau. Si cette case est déjà marquée par un drapeau, vous aurez la possibilité de le retirer, un case marquée ne pouvant être affichée.

Vous gagnez la partie une fois que toutes les cases 'safe' auront été découvertes, le nombre de cases cachées + les drapeaux étant les bombes.

En cas de victoire, n'oubliez pas d'entrer votre pseudo, afin que votre temps soit affiché dans un fichier texte aux côtés de tous vos autres scores.

Bonne chance, gl & hf !
