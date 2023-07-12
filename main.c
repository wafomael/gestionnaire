#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxChar 50
#define maxMark 50

typedef struct appareil{
    char id[maxChar];
    char type[maxChar];
    char marque[maxChar];
    short anne;
    char etat[maxChar];
    int afectation;
}appareil;

typedef struct agent{
    int matricule;
    char nom[maxChar];
    char prenom[maxChar];
    int afectater;
}agent;

int lireApareil(appareil tabParck[], int cpt, int cptA, char* listeMarque[], agent listeAgent[], int chois, char* listeType[], char* listeEtat[]){
    int i, mark, appar, etate;
    appareil divice;
    agent personel;

    printf("-------------------------\n");
    if(chois==1){
        tabParck[cpt] = divice;

        printf("entrer l'ID de l'appareil %d        Ex:MD12S431 \n", cpt+1);
        printf("MD");
        scanf("%s", &tabParck[cpt].id);
        printf("***********************************************************************************************************************\n");
        printf("entrer le type de l'appareil %d\n", cpt+1);
        for(i=0; i<10; i++){
            if(i==5){
                printf("\n");
            }
            printf("%d.%s ", i+1, listeType[i]);
        }
        printf("\n*********************************************************************************************************************\n\n");
        scanf("%d", &appar);
        strcpy(tabParck[cpt].type, listeType[appar-1]);

        printf("entrer la marque %d\n", cpt+1);
        printf("Choisisez une marque\n");
        printf("***********************************************************************************************************************\n");
        for(i=0; i<13; i++){
            printf("%d.%s ", i+1, listeMarque[i]);
        }
        printf("\n*********************************************************************************************************************\n\n");
        scanf("%d", &mark);
        strcpy(tabParck[cpt].marque, listeMarque[mark-1]);

        printf("entrer l'annee de  l'appareil %d\n\n", cpt+1);
        scanf("%hd", &tabParck[cpt].anne);
        printf("entrer l'etat de l'appareil %d\n", cpt+1);
        printf("***********************************************************************************************************************\n");
        printf("choisiser l'etat de l'appareil %d\n", cpt+1);
        for(i=0; i<4; i++){
            printf("%d.%s ", i+1, listeEtat[i]);
        }
        printf("\n*********************************************************************************************************************\n\n");

        scanf("%d", &etate);
        strcpy(tabParck[cpt].etat, listeEtat[etate-1]);
        tabParck[cpt].afectation = 0;

        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nAppareil corectement ajoute\n");
    }
    if(chois==2){
        listeAgent[cptA] = personel;

        printf("entrer le maticule de l'agent %d     Ex:130012\n", cptA+1);
        scanf("%d", &listeAgent[cptA].matricule);
        printf("entrer le nom de l'agent %d\n", cptA+1);
        scanf("%s", &listeAgent[cptA].nom);
        printf("entrer le prenom de l'agent %d\n", cptA+1);
        scanf("%s", &listeAgent[cptA].prenom);
        listeAgent[cptA].afectater = 0;

        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nAgent corectement ajoute\n");
    }
    printf("-------------------------\n");
    return 0;
}

int suprimer(appareil tabParck[], int cpt, int cptA, agent personel[], int chois){
    int i;
    int posi;
    if(chois==1){
        printf("-----------Les Appareilles----------------\n");
        for(i=0; i<cpt; i++){
            printf("%d.MD%s %s %s %hd ans d'age %s\n", i+1, tabParck[i].id, tabParck[i].type, tabParck[i].marque, tabParck[i].anne, tabParck[i].etat);
        }

        printf("\nEntrer la position de l'appareil a retirer\n\n");
        scanf("%d", &posi);
        printf("L'appareil vient d'etre donner a un Orphelina\n");

        for(i=0; i<cptA; i++){
            if(tabParck[posi-1].afectation==personel[i].afectater){
                personel[i].afectater=0;
            }
        }

        for(i=posi; i<cpt+1; i++){
            tabParck[i-1] = tabParck[i];
        }
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nAppareil corectement retire\n");
    }
    if(chois==2){
        printf("-----------Les Agents----------------\n");
        for(i=0; i<cptA; i++){
            printf("%d.matricule %d nom %s prenom %s\n", i+1, personel[i].matricule, personel[i].nom, personel[i].prenom);
       }

        printf("entrer la position de l'agent a licensier.\n\n");
        scanf("%d", &posi);
        for(i=0; i<cpt; i++){
            if(tabParck[i].afectation==personel[posi-1].afectater){
                tabParck[i].afectation=0;
            }
        }

        for(i=posi; i<cptA+1; i++){
            personel[i-1] = personel[i];
        }
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nAgent corectement retire\n");

    }
    printf("-----------------------------------------\n");

    return 0;
}

int aficher(appareil tabParck[], int cpt, int cptA, char* listeMarque[], agent listeAgent[], char* listeType[], char* listeEtat){
    int i, j, chois, choiAfich, mark;

    printf("-----------------------------------------\n");
    printf("Que voulez vous afficher.\n1.Les appareil\n2.Les appareil avec une caracteristique specifique\n3.Les Agent\n4.Les agents et leur appareil\n5.Les appareil libres\n6.Les agent libres\n");
    scanf("%d", &chois);
    printf("\n\n");

    printf(".............................................................\n");
    if(chois==1){
       for(i=0; i<cpt; i++){
           printf("MD%s %s %s %hd  ans d'age %s\n", tabParck[i].id, tabParck[i].type, tabParck[i].marque, tabParck[i].anne, tabParck[i].etat);
       }
    }
    if(chois==2){
        printf("qu'elle est la caracteristique?\n");
        printf("1.la marque\n2.le type\n3.l'age\n4.l'etat\n");

        scanf("%d", &choiAfich);

        if(choiAfich==1){

            printf("Choisisez une marque\n");
            for(i=0; i<13; i++){
                printf("%d.%s ", i+1, listeMarque[i]);
            }
            printf("\n");
            scanf("%d", &mark);
            for(i=0; i<cpt; i++){
                if(strcmp(tabParck[i].marque, listeMarque[mark-1])== 0){
                    printf("\n.............................................................\n");
                    printf("MD%s %s %s %hd  ans d'age %s\n", tabParck[i].id, tabParck[i].type, tabParck[i].marque, tabParck[i].anne, tabParck[i].etat);
                }
            }
        }

        if(choiAfich ==2){
            printf("Choisisez un type d'appareil\n");
            for(i=0; i<10; i++){
                printf("%d.%s ", i+1, listeType[i]);
            }
            printf("\n");
            scanf("%d", &mark);
            for(i=0; i<cpt; i++){
                if(strcmp(tabParck[i].type, listeType[mark-1])== 0){
                    printf("\n.............................................................\n");
                    printf("MD%s %s %s %hd  ans d'age %s\n", tabParck[i].id, tabParck[i].type, tabParck[i].marque, tabParck[i].anne, tabParck[i].etat);
                }
            }
        }

        if(choiAfich ==3){
            printf("Choisisez l'age de l'appareil\n\n");
            scanf("%d", &mark);
            for(i=0; i<cpt; i++){
                if(tabParck[i].anne== mark){
                    printf("\n.............................................................\n");
                    printf("MD%s %s %s %hd  ans d'age %s\n", tabParck[i].id, tabParck[i].type, tabParck[i].marque, tabParck[i].anne, tabParck[i].etat);
                }
            }
        }

        if(choiAfich ==4){
            printf("Choisisez l'etat de l'appareil\n");
            for(i=0; i<4; i++){
                printf("%d.%s ", i+1, listeEtat[i]);
            }
            printf("\n");
            scanf("%d", &mark);
            for(i=0; i<cpt; i++){
                if(strcmp(tabParck[i].etat, listeEtat[mark-1])== 0){
                    printf("\n.............................................................\n");
                    printf("MD%s %s %s %hd  ans d'age %s\n", tabParck[i].id, tabParck[i].type, tabParck[i].marque, tabParck[i].anne, tabParck[i].etat);
                }
            }
        }

    }
    if(chois==3){
       for(i=0; i<cptA; i++){
           printf("matricule %d nom %s prenom %s\n", listeAgent[i].matricule, listeAgent[i].nom, listeAgent[i].prenom);
       }
    }

    if(chois==4){
       for(i=0; i<cpt; i++){
           if(tabParck[i].afectation!=0){
               for(j=0; j<cptA; j++){
                    if(tabParck[i].afectation==listeAgent[j].afectater){
                        printf("MD%s %s %s %hd  ans d'age %s\n", tabParck[i].id, tabParck[i].type, tabParck[i].marque, tabParck[i].anne, tabParck[i].etat);
                        printf("maricule %d nom %s prenom %s\n", listeAgent[j].matricule, listeAgent[j].nom, listeAgent[j].prenom);
                        printf(".............................................................\n");
                    }
               }
           }

       }
    }

    if(chois==5){
       for(i=0; i<cpt; i++){
           if(tabParck[i].afectation==0){
                printf("MD%s %s %s %hd  ans d'age %s\n", tabParck[i].id, tabParck[i].type, tabParck[i].marque, tabParck[i].anne, tabParck[i].etat);
                printf(".............................................................\n");
           }

       }
    }

    if(chois==6){
       for(i=0; i<cptA; i++){
           if(listeAgent[i].afectater==0){
                printf("%d.matricule %d nom %s prenom %s\n", i+1, listeAgent[i].matricule, listeAgent[i].nom, listeAgent[i].prenom);
                printf(".............................................................\n");
           }

       }
    }
    printf(".............................................................\n");


    return 0;
}


int afecter(appareil tabParck[], agent listeAgent[], int cpt, int cptA, int affect){
    int i, choiAp, choiAg;

    printf("-----------Les Appareilles----------------\n");
    for(i=0; i<cpt; i++){
        if(tabParck[i].afectation == 0){
            printf("%d.MD%s %s %s %hd  ans d'age %s\n", i+1, tabParck[i].id, tabParck[i].type, tabParck[i].marque, tabParck[i].anne, tabParck[i].etat);
        }
    }
    printf("\n");
    printf("-------------Les Agents-------------------\n");
    for(i=0; i<cptA; i++){
           if(listeAgent[i].afectater==0){
                printf("%d.matricule %d nom %s prenom %s\n", i+1, listeAgent[i].matricule, listeAgent[i].nom, listeAgent[i].prenom);
           }
    }
    printf("\n\n");
    printf("voisi les liste des appareil qui ne sont pas affectées, et les agent qui n'ont pas d'appareil.\n\n");
    printf("Choisiser un apareil a affecter.\n");
    scanf("%d", &choiAp);
    printf("Choisiser l'agent qui vas recevoir l'appareil.\n");
    scanf("%d", &choiAg);

    tabParck[choiAp-1].afectation = affect;
    listeAgent[choiAg - 1].afectater = affect;

    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nAfectation corectement efectue\n");
    printf("-----------------------------------------\n");

    return 0;
}

int reprendre(appareil tabParck[], int cpt, int cptA, char* listeMarque[], agent listeAgent[]){
    int i,j, chois;

    printf(".............................................................\n");
    for(i=0; i<cpt; i++){
        if(tabParck[i].afectation!=0){
            for(j=0; j<cptA; j++){
                if(tabParck[i].afectation==listeAgent[j].afectater){
                    printf("%d.MD%s %s %s %hd  ans d'age %s\n", i+1, tabParck[i].id, tabParck[i].type, tabParck[i].marque, tabParck[i].anne, tabParck[i].etat);
                    printf("  marticule %d nom %s prenom %s\n", listeAgent[j].matricule, listeAgent[j].nom, listeAgent[j].prenom);
                    printf(".............................................................\n");
                }
            }
        }
    }

    printf("Voissi les agents et leur appareil\n");
    printf("choisiser la position de l'appareil a reprendre\n\n");
    scanf("%d", &chois);

    for(i=0; i<cpt; i++){
        if(tabParck[chois-1].afectation == listeAgent[i].afectater){
            tabParck[chois-1].afectation = 0;
            listeAgent[i].afectater= 0;
        }
    }

    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nl'appareil corectement recupére\n");
    printf(".............................................................\n");


    return 0;
}



int main()
{
    int nbP, cpt = 0, cptA=0, affects=1, choix, activation=0, choixChangement, nbAgent, repeat;
    char* marque[maxMark] = {"Asus", "HP", "Lenovo", "Camon", "Rico", "Apple", "Samsung", "Sony", "Acer", "Dell", "LG", "Microsoft", "Toshiba"};
    char* type[maxMark] = {"Ordinateur Fixe", "Ordinateur Portable", "Telephone Portable", "Telelephone Fixe", "Tablette", "Imprimante", "Scanaire", "Disque Dur", "Apareil Photo", "Micro"};
    char* etat[maxMark] = {"Neuf", "Fonctionel", "Vieux", "Defectieux"};


    printf("Bonjour utilisateur, bienvenue dans votre gestionaire de parck.\nCombien de places maximal il y a dans votre parck?\n");
    scanf("%d", &nbP);
    appareil parck[nbP];
    printf("Combien d'Agent compte votre entreprise\n");
    scanf("%d", &nbAgent);
    agent personel[nbAgent];


    while(choix != 0){
        printf("\n\n");

        printf("================MENU======================\n\n");
        printf("               Que voulez vous faire\n         ----------------------------------\n         |1.Ajouter                       |\n         |2.Retirer                       |\n         |3.Aficher                       |\n         |4.Affecter                      |\n         |5.Reprendre                     |\n         |0.arreter le logiciel           |\n         ----------------------------------\n");
        scanf("%d", &choix);
        printf("=========================================\n\n");

        if(choix==1){
            printf("-----------------------------------------\n");
            printf("Que voulez vos ajouter?\n1.Un appareil\n2.Un agent\n");
            scanf("%d", &choixChangement);


            if(choixChangement==1){
                repeat=1;
                while(repeat==1){
                    lireApareil(parck, cpt, cptA, marque, personel, choixChangement, type, etat);
                    cpt++;
                    printf("voullez vous ajouter un autre appareil\n\n1.OUI      0.NON\n\n");
                    scanf("%d", &repeat);
                }
                printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
            }
            if(choixChangement==2){
                repeat=1;
                while(repeat==1){
                    lireApareil(parck, cpt, cptA, marque, personel, choixChangement, type, etat);
                    cptA++;
                    printf("voullez vous ajouter un autre Agent\n\n1.OUI      0.NON\n\n");
                    scanf("%d", &repeat);
                }
                printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
            }

            printf("\n");
        }

        if(choix==2){
            printf("Que voulez Retirer.\n1.Un appareil\n2.Un agent\n");
            scanf("%d", &choixChangement);


            if(choixChangement==1){
                repeat=1;
                while(repeat==1){
                    suprimer(parck, cpt, cptA, personel, choixChangement);
                    cpt--;
                    printf("voullez vous faire un autre don\n\n1.OUI      0.NON\n\n");
                    scanf("%d", &repeat);
                }
                printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
            }
            if(choixChangement==2){
                repeat=1;
                while(repeat==1){
                    suprimer(parck, cpt, cptA, personel, choixChangement);
                    cptA--;
                    printf("voullez vous licensier un autre agent\n\n1.OUI      0.NON\n\n");
                    scanf("%d", &repeat);
                }
                printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
            }
        }
        if(choix==3){
            aficher(parck, cpt, cptA, marque, personel, type, etat);
        }

        if(choix==4){
            repeat=1;
            while(repeat==1){
                afecter(parck, personel, cpt, cptA, affects);
                affects++;
                printf("voullez vous faire un autre afectation\n\n1.OUI      0.NON\n\n");
                scanf("%d", &repeat);
                printf("\n\n\n\n\n\n\n\n\n\n");
            }
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        }

        if(choix==5){
            repeat=1;
            while(repeat==1){
                reprendre(parck, cpt, cptA, marque, personel);
                printf("voullez vous reprndre un autre appareil\n\n1.OUI      0.NON\n\n");
                scanf("%d", &repeat);
            }
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        }
        if(choix==0){
            activation=0;
            while(activation!=1){
                printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n====================================================================================\n");
                printf("                                              --------------------------------------\n");
                printf("                                              |ATTENTION                           |\n                                              |VOTRE LOGICIEL ET EN VEILLE         |\n                                              |NE PAS SUIVRE L'INDICATION SUIVANTE |\n                                              |POURAIT VOUS FAIRE PERDRE VOS DONNEE|\n");
                printf("                                              --------------------------------------\n");
                printf("\n1.ON\n\n");
                scanf("%d", &activation);

                if(activation==1){
                    choix=10;
                }
                printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
            }
        }
    }



    return 0;
}
