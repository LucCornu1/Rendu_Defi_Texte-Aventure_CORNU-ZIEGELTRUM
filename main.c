#include <stdio.h>
#include <stdlib.h>
#include <winsock2.h>
#include <string.h>
#include <windows.h>

#define PORT 23

typedef int socklen_t;

typedef struct PAVE
{
	int x;
	int y;
	char c;
}PAVE;

typedef struct MOVE
{
	char c;
	char direction;
}MOVE;

//Prototype fonctions
void affichageFresque(char [3][2]);
void moveFresque(char [3][2], int);
int ComparaisonFresque(char [3][2], char [3][2], int);
PAVE setStructPAVE(PAVE);

int main()
{
	WSADATA WSAData;
	WSAStartup(MAKEWORD(2,2), &WSAData);

	//Initialisation variables sockets
	SOCKET sock;
	SOCKET servSock;
	SOCKADDR_IN sin;
	SOCKET csock;
	char buffer[64]="";
	SOCKADDR_IN csin;
	socklen_t recsize = sizeof(csin);
	int sock_err;

	//Initialisation variables jeu
	int booleenX = 0;
	char FresqueE[3][2];
	FresqueE[0][0]='P';
	FresqueE[0][1]='M';
	FresqueE[1][0]='F';
	FresqueE[1][1]='V';
	FresqueE[2][0]='B';
	FresqueE[2][1]='A';

	char FresqueA[3][2];
	FresqueA[0][0]='P';
	FresqueA[0][1]='A';
	FresqueA[1][0]='V';
	FresqueA[1][1]='B';
	FresqueA[2][0]='M';
	FresqueA[2][1]='F';

	PAVE pBrique;

	//Introduction / Menu
	printf("Bienvenue dans Deadly adventure\n\n");

	printf("Appuyez sur une touche pour jouer\n");

	fflush(stdin);
	getchar();
	system("cls");

	//Sélection du personnage
	int x;
	do{
		printf("Veuillez entrer votre numero de joueur : ");
		scanf("%d", &x);
	}while(x != 1 && x != 2);

	system("cls");

	/////////////////////////////////////////////////// ELLA ///////////////////////////////////////////////////

	if(x == 1)
	{
		sock = socket(AF_INET, SOCK_STREAM, 0);

		/* Si la socket est valide */
		if(sock != INVALID_SOCKET)
		{
			//printf("La socket %d est maintenant ouverte en mode TCP/IP\n", sock);

			/* Configuration */
			sin.sin_addr.s_addr = htonl(INADDR_ANY); /* Adresse IP automatique */
			sin.sin_family = AF_INET; /* Protocole familial (IP) */
			sin.sin_port = htons(PORT); /* Listage du port */
			sock_err = bind(sock, (SOCKADDR*)&sin, sizeof(sin));

			/* Si la socket fonctionne */
			if(sock_err != SOCKET_ERROR)
			{
				/* Démarrage du listage (mode server) */
				sock_err = listen(sock, 5);

				/* Si la socket fonctionne */
				if(sock_err != SOCKET_ERROR)
				{
					/* Attente pendant laquelle le client se connecte */
					printf("Vous tentez de vous connecter au canal numéro : %d...\n", PORT);

					csock = accept(sock, (SOCKADDR*)&csin, &recsize);

					system("cls");

					printf("1939. L'Allemagne nazi est en pleine preparation du conflit a venir. La Legion Condor est rentree de la Guerre d'Espagne \n");
					printf("et la dictature pousse la machine de guerre dans tous les secteurs. Meme les plus secrets. \n");
					printf("Depuis 1936, l'Ahnenerbe, branche occultiste de la SS, s'est mise en quete d'artefacts anciens aux proprietes mysterieuses. \n");
					printf("D'aucun dirais, des artefacts magiques. Leurs recherches, bien que secretes n'ont pas echappee au MI6. \n");
					printf("Les Britanniques ont donc affecte deux agents sur une mission de surveillance. \n");
					printf("Ella Saint Claire, fille d'un archeologue renomme de l'universite d'Oxford, pilote renommee aussi bien sur terre que dans les airs. \n");
					printf("Elle est accompagnee d'un expatrie Italien fuyant le regime de Mussolini, Aleandro Santorini. Expert en explosifs, bon tireur et fumeur invetere. \n");
					printf("Leur traque des Nazi les ont mis sur la piste d'un ancien artefact que ces derniers convoitent. ");
					printf("Ils n'en connaissent pas la nature profonde mais si les Nazi le veulent, il vaudrais mieux qu'ils mettent la main dessus avant eux. \n");
					printf("Leur recherche les ont mene de l'Egypte a des ruines oubliees en Antarctiques, le tout ponctue d'accrochage avec leurs opposants ainsi \n");
					printf("qu'avec diverses momies et autres creatures mythologiques vexees par la venue d'intrus dans leur territoire oublie. \n");
					printf("Leurs dernieres decouvertes les ont menes au Guatemala dans un complexe Maya sous-terrain. \n");
					printf("Apres avoir elimine quelques morts-vivants, ils ont ete forces de se separer pour echapper a un piege de feu. \n");
					printf("Ils sont maintenant chacun isole dans des couloirs differents et doivent avancer si ils veulent esperer sortir. \n\n");

					Sleep(4000);

					//////////////////////////////////// DISCUSSION ////////////////////////////////////

					sock_err = send(csock, "Ella : Aleandro ! Ca va ?", 64, 0);

					if(sock_err != SOCKET_ERROR)
					{
						printf("Ella : Aleandro ? Ca va ?\n");
						Sleep(4000);
						if(recv(csock, buffer, sizeof(buffer), 0) != SOCKET_ERROR)
						{
							printf("Aleandro : %s\n", buffer);
						}
					}else{
						printf("Erreur de transmission\n");
					}
					Sleep(4000);

					//////////////////////////////////// DISCUSSION SUITE ////////////////////////////////////

					if(send(csock, "Quelque meches roussis, mais ca va. Il y a quoi de ton cote ?", 64, 0) != SOCKET_ERROR)
					{
						printf("Ella : Quelque meches roussis, mais ca va. Il y a quoi de ton cote ?\n");
						Sleep(4000);
						if(recv(csock, buffer, sizeof(buffer), 0) != SOCKET_ERROR)
						{
							printf("Aleandro : %s\n", buffer);
							Sleep(4000);
							if(recv(csock, buffer, sizeof(buffer), 0) != SOCKET_ERROR)
							{
								printf("Aleandro : %s\n", buffer);
							}
						}
					}else{
						printf("Erreur de transmission\n");
					}
					Sleep(4000);

					//////////////////////////////////// DISCUSSION SUITE 2 ////////////////////////////////////

					if(send(csock, "Qu'est ce qui est represente chez toi ?", 64, 0) != SOCKET_ERROR)
					{
						printf("Ella : Qu'est ce qui est represente chez toi ?\n");
						Sleep(4000);
						if(recv(csock, buffer, sizeof(buffer), 0) != SOCKET_ERROR)
						{
							printf("Aleandro : %s\n", buffer);
							Sleep(4000);
							if(recv(csock, buffer, sizeof(buffer), 0) != SOCKET_ERROR)
							{
								printf("Aleandro : %s\n", buffer);
							}
						}
					}else{
						printf("Erreur de transmission\n");
					}
					Sleep(4000);

					//////////////////////////////////// DISCUSSION SUITE 3 ////////////////////////////////////

					if(send(csock, "On essais de la reproduire de ton cote ?", 64, 0) != SOCKET_ERROR)
					{
						printf("Ella : On essais de la reproduire de ton cote ?\n");
						Sleep(4000);
						if(recv(csock, buffer, sizeof(buffer), 0) != SOCKET_ERROR)
						{
							printf("Aleandro : %s\n", buffer);
						}
					}else{
						printf("Erreur de transmission\n");
					}

					Sleep(6000);

					printf("Lorsque vous avancez, la porte se ferme derriere vous... vous etes desormais isole de votre coequipier\n");

					fflush(stdin);
					getchar();
					system("cls");

					//////////////////////////////////// ENIGME ////////////////////////////////////

					printf("La pierre P brille !\n");
					do{
						affichageFresque(FresqueE);
						printf("\n\nVous devez indiquer les coordonees des lettres a vos coequipiers pour qu'il recompose son tableau a l'identique.\n");
						printf("Les pierres se mettent a briller lorsqu'elles sont a la bonne position.\n\n");

						pBrique = setStructPAVE(pBrique);

						if(send(csock, &pBrique, sizeof(pBrique), 0) != SOCKET_ERROR)
						{
							printf("Vous envoyez le message suivant en morse : x %d y %d %c.\n", pBrique.x, pBrique.y, pBrique.c);
							if(recv(csock, &FresqueA, sizeof(FresqueA), 0) != SOCKET_ERROR)
							{
								printf("Vous entendez quelque chose bouger");
							}
						}else{
							printf("Erreur de transmission\n");
						}

						system("cls");
						booleenX = ComparaisonFresque(FresqueE, FresqueA, x);
					}while(booleenX == 0);

					printf("La porte devant vous s'ouvre. Vous avancez dans les tenebres...\n");

					/////////////////////////////////////////////////////////////////////////////

					fflush(stdin);
					getchar();

					shutdown(csock, 2);

					/* Il ne faut pas oublier de fermer la connexion (fermée dans les deux sens) */
				}
			}

			/* Fermeture de la socket */
			printf("Fermeture de la socket...\n");
			closesocket(sock);
			printf("Fermeture du serveur terminee\n");
		}
	}
	else if(x == 2) /////////////////////////////////////////////////// Aleandro ///////////////////////////////////////////////////
	{
		servSock = socket(AF_INET, SOCK_STREAM, 0);

		/* Création de la socket */
		sock = socket(AF_INET, SOCK_STREAM, 0);

		/* Configuration de la connexion */
		sin.sin_addr.s_addr = inet_addr("127.0.0.1");
		sin.sin_family = AF_INET;
		sin.sin_port = htons(PORT);

		/* Si l'on a réussi a se connecter */
		if(connect(sock, (SOCKADDR*)&sin, sizeof(sin)) != SOCKET_ERROR)
		{
			printf("Connection a %s sur le port %d\n", inet_ntoa(sin.sin_addr), htons(sin.sin_port));

			system("cls");

			printf("1939. L'Allemagne nazi est en pleine preparation du conflit a venir. La Legion Condor est rentree de la Guerre d'Espagne \n");
			printf("et la dictature pousse la machine de guerre dans tous les secteurs. Meme les plus secrets. \n");
			printf("Depuis 1936, l'Ahnenerbe, branche occultiste de la SS, s'est mise en quete d'artefacts anciens aux proprietes mysterieuses. \n");
			printf("D'aucun dirais, des artefacts magiques. Leurs recherches, bien que secretes n'ont pas echappee au MI6. \n");
			printf("Les Britanniques ont donc affecte deux agents sur une mission de surveillance. \n");
			printf("Ella Saint Claire, fille d'un archeologue renomme de l'universite d'Oxford, pilote renommee aussi bien sur terre que dans les airs. \n");
			printf("Elle est accompagnee d'un expatrie Italien fuyant le regime de Mussolini, Aleandro Santorini. Expert en explosifs, bon tireur et fumeur invetere. \n");
			printf("Leur traque des Nazi les ont mis sur la piste d'un ancien artefact que ces derniers convoitent. ");
			printf("Ils n'en connaissent pas la nature profonde mais si les Nazi le veulent, il vaudrais mieux qu'ils mettent la main dessus avant eux. \n");
			printf("Leur recherche les ont mene de l'Egypte a des ruines oubliees en Antarctiques, le tout ponctue d'accrochage avec leurs opposants ainsi \n");
			printf("qu'avec diverses momies et autres creatures mythologiques vexees par la venue d'intrus dans leur territoire oublie. \n");
			printf("Leurs dernieres decouvertes les ont menes au Guatemala dans un complexe Maya sous-terrain. \n");
			printf("Apres avoir elimine quelques morts-vivants, ils ont ete forces de se separer pour echapper a un piege de feu. \n");
			printf("Ils sont maintenant chacun isole dans des couloirs differents et doivent avancer si ils veulent esperer sortir. \n\n");

			Sleep(4000);

			//////////////////////////////////// DISCUSSION ////////////////////////////////////

			/* Si l'on reçoit des informations : on les affiche a l'écran */
			if(recv(sock, buffer, sizeof(buffer), 0) != SOCKET_ERROR)
			{
				printf("Ella : %s\n", buffer);
				Sleep(4000);
				if(send(sock, "Ca va, ma clope a cramer mais ca va. Et toi ?", 64, 0) != SOCKET_ERROR)
				{
					printf("Aleandro : Ca va, ma clope a cramer mais ca va. Et toi ?\n");
				}else{
					printf("Erreur de transmission\n");
				}
			}
			Sleep(4000);

			//////////////////////////////////// DISCUSSION SUITE ////////////////////////////////////

			if(recv(sock, buffer, 64, 0) != SOCKET_ERROR)
			{
				printf("Ella : %s\n", buffer);
				Sleep(4000);
				if(send(sock, "Euh pas grand-chose. Une porte fermee et une fresque.", 64, 0) != SOCKET_ERROR)
				{
					printf("Aleandro : Euh pas grand-chose. Une porte fermee et une fresque.\n");
					Sleep(4000);
					if(send(sock, "On dirait que les pieces peuvent bouger. Et chez toi ?", 64, 0) != SOCKET_ERROR)
					{
						printf("Aleandro : On dirait que les pieces peuvent bouger. Et chez toi ?\n");
					}else{
						printf("Erreur de transmission\n");
					}
				}else{
					printf("Erreur de transmission\n");
				}
			}
			Sleep(4000);

			//////////////////////////////////// DISCUSSION SUITE 2 ////////////////////////////////////

			if(recv(sock, buffer, 64, 0) != SOCKET_ERROR)
			{
				printf("Ella : %s\n", buffer);
				Sleep(4000);
				if(send(sock, "Un arbre mort avec une tete, des squelettes...", 64, 0) != SOCKET_ERROR)
				{
					printf("Aleandro : Un arbre mort avec une tete, des squelettes...\n");
					Sleep(4000);
					if(send(sock, "...et deux gars avec des plumes.", 64, 0) != SOCKET_ERROR)
					{
						printf("Aleandro : ...et deux gars avec des plumes.\n");
					}else{
						printf("Erreur de transmission\n");
					}
				}else{
					printf("Erreur de transmission\n");
				}
			}
			Sleep(4000);

			//////////////////////////////////// DISCUSSION SUITE 3 ////////////////////////////////////

			if(recv(sock, buffer, 64, 0) != SOCKET_ERROR)
			{
				printf("Ella : %s\n", buffer);
				Sleep(4000);
				if(send(sock, "On a pas vraiment d'autres choix...", 64, 0) != SOCKET_ERROR)
				{
					printf("Aleandro : On a pas vraiment d'autres choix...\n");
				}else{
					printf("Erreur de transmission\n");
				}
			}

			Sleep(6000);

			printf("Lorsque vous avancez, la porte se ferme derriere vous... vous etes desormais isole de votre coequipier\n");

			fflush(stdin);
			getchar();
			system("cls");

			//////////////////////////////////// ENIGME ////////////////////////////////////

			do{
				printf("Vous devez attendre que votre coequipier vous communique en morse les coordonees des briques a deplacer.\n\n");
				affichageFresque(FresqueA);

				if(recv(sock, &pBrique, sizeof(pBrique), 0) != SOCKET_ERROR)
				{
					printf("Vous recevez le message suivant en morse : x %d y %d %c\n", pBrique.x, pBrique.y, pBrique.c);

					fflush(stdin);
					getchar();

					moveFresque(FresqueA, x);

					if(send(sock, &FresqueA, sizeof(FresqueA), 0) != SOCKET_ERROR)
					{
						printf("Vous bougez la tuile\n");
					}else{
						printf("Erreur de transmission\n");
					}
				}
				booleenX = ComparaisonFresque(FresqueE, FresqueA, x);
			}while(booleenX == 0);

			printf("La porte devant vous s'ouvre. Vous avancez dans les tenebres...\n");

			/////////////////////////////////////////////////////////////////////
		}
		/* sinon, on affiche "Impossible de se connecter" */
		else
		{
			printf("Impossible de se connecter\n");
		}

		/* On ferme la socket */
		closesocket(sock);
	}

	WSACleanup();

	/* On attend que l'utilisateur tape sur une touche, puis on ferme */
	fflush(stdin);
	getchar();

	return EXIT_SUCCESS;
}

void affichageFresque(char Fresque[3][2])
{
	int i, j;
	for(i=0; i<3; i++)
	{
		for(j=0; j<2; j++)
		{
			printf("%c", Fresque[i][j]);
		}
		printf("\n");
	}
}

void moveFresque(char FresqueA[3][2], int joueur)
{
	int i, j;
	char cSelect, cSelect2, cValid = 'N';

	if(joueur == 2)
	{
		while(cValid != 'O')
		{
			do{
				printf("Veuillez entrer une lettre parmi 'P', 'M', 'F', 'V', 'B' ou 'A' : ");
				fflush(stdin);
				scanf("%c", &cSelect);
			}while(cSelect != 'P' && cSelect != 'M' && cSelect != 'F' && cSelect != 'V' && cSelect != 'B' && cSelect != 'A');

			do{
				printf("Veuillez entrer une lettre parmi 'P', 'M', 'F', 'V', 'B' ou 'A' : ");
				fflush(stdin);
				scanf("%c", &cSelect2);
			}while(cSelect2 != 'P' && cSelect2 != 'M' && cSelect2 != 'F' && cSelect2 != 'V' && cSelect2 != 'B' && cSelect2 != 'A');

			printf("Voici les cases que vous allez echanger %c avec %c. Etes-vous sur de changer O/N ?\n", cSelect, cSelect2);
			fflush(stdin);
			scanf("%c",&cValid);
		}
	}

	for(i=0; i<3; i++)
	{
		for(j=0; j<2; j++)
		{
			if(FresqueA[i][j] == cSelect)
			{
				FresqueA[i][j] = cSelect2;
			}else{
				if(FresqueA[i][j] == cSelect2)
				{
					FresqueA[i][j] = cSelect;
				}
			}
		}
	}
}

int ComparaisonFresque(char FresqueE[3][2], char FresqueA[3][2], int joueur)
{
	int i, j, compteur = 0, b = 0;
	for(i=0; i<3; i++)
	{
		for(j=0; j<2; j++)
		{
			if(FresqueE[i][j] == FresqueA[i][j])
			{
				compteur++;
				if(joueur == 1)
				{
					printf("La pierre %c brille !\n", FresqueE[i][j]);
				}
			}
		}
	}

	if(compteur >= 6)
	{
		b = 1;
	}
	return b;
}

PAVE setStructPAVE(PAVE brique)
{
	char cValid = 'N';

	while(cValid != 'O')
	{
		do{
			printf("Veuillez entrer une coordonnee X entre 1 et 2 : ");
			scanf("%d", &brique.x);
		}while(brique.x < 1 || brique.x > 2);

		do{
			printf("Veuillez entrer une coordonnee Y entre 1 et 3 : ");
			scanf("%d", &brique.y);
		}while(brique.y < 1 || brique.y > 3);

		do{
			printf("Veuillez entrer une lettre parmi 'P', 'M', 'F', 'V', 'B' ou 'A' : ");
			fflush(stdin);
			scanf("%c", &brique.c);
		}while(brique.c != 'P' && brique.c != 'M' && brique.c != 'F' && brique.c != 'V' && brique.c != 'B' && brique.c != 'A');

		printf("Voici le message que vous allez envoyer : x %d y %d %c. Etes-vous sûr d'envoyer ce message O/N ?\n", brique.x, brique.y, brique.c);
		fflush(stdin);
		scanf("%c",&cValid);
	}

	return brique;
}
