#include <stdio.h>
#include <stdlib.h>

#define rozmiar 9
int zajeta;

typedef struct Dane{
    int dana;
    struct Dane *nast;
    struct Dane *poprz;
}Dane;

void dodajliczbe (Dane**glowa, Dane**ogon, int x)
{
  if (zajeta == rozmiar) {printf("\nNie mozna dodac - pelna kolejka"); return;}
  Dane *nowy = (Dane*)malloc(sizeof(Dane));
  nowy->dana = x;
  if (*ogon == NULL)
  {
    *ogon = nowy;
    *glowa = nowy;
    nowy->nast = NULL;
    nowy->poprz = NULL;
  }
  if (*ogon != NULL)
  {
    if (nowy->dana < (*glowa)->dana)
    {
        (*glowa)->poprz = nowy;
        nowy->nast = *glowa;
        nowy->poprz = NULL;
        *glowa = nowy;
        zajeta++;
        return;
    }
    Dane *help=*glowa;
    while(((help->nast!=NULL))&&((help->dana)<(nowy->dana)))
    {
        if(help->nast->dana > nowy->dana)break;
        help=help->nast;
    }
    if (help->nast == NULL)
    {
        (*ogon)->nast = nowy;
        nowy->poprz = *ogon;
        nowy->nast = NULL;
        *ogon = nowy;
        zajeta++;
        return;
    }
    help->nast->poprz=nowy;
    nowy->poprz=help;
    nowy->nast=help->nast;
    help->nast=nowy;
  }
  zajeta++;
}

void zabierzliczbe(Dane**glowa, Dane**ogon)
{
    if(*glowa == NULL) {printf("/nKolejka jest pusta"); return;}
    if(*glowa == *ogon)
    {
        free(*glowa);
        free(*ogon);
        *glowa = *ogon = NULL;
    }
    if(*glowa != *ogon)
    {
        Dane* zdjety = *glowa;
        (*glowa) = (*glowa)->nast;
        (*glowa)->poprz = NULL;
        free(zdjety);
    }
    zajeta--;
}

void wyswietl(Dane *glowa)
{
    if (glowa == NULL) {printf("\nKolejka jest pusta"); return;}
    while(glowa)
    {
        printf("%d ", glowa->dana);
        glowa=glowa->nast;
    }
}

void wyswietl_ogon(Dane *ogon, Dane *glowa)
{
    if (ogon == NULL) {printf("\nKolejka jest pusta"); return;}
    while(ogon)
    {
        printf("%d ", ogon->dana);
        if(ogon == glowa) return;
        ogon=ogon->poprz;
    }
}

void wyczysc(Dane **glowa, Dane **ogon)
{
    if (*glowa == NULL) {printf("Kolejka jest pusta."); return;}
    Dane *clean;
    while (*glowa)
    {
        clean = *glowa;
        *glowa = (*glowa)->nast;
        free(clean);
    }
*ogon = *glowa;
zajeta=0;
}

int main()
{
    Dane *glowa, *ogon;
    ogon = glowa = NULL;
    int wybor;
    do
    {
    printf("\nProgram do zarzadzania kolejka priorytetowa o rozmiarze 10");
    printf("\n ---------------------------------------------------------");
    printf("\n[0] Wyjscie z programu");
    printf("\n[1] Dodaj liczbe do kolejki");
    printf("\n[2] Zabierz liczbe z kolejki");
    printf("\n[3] Wyswietl kolejke");
    printf("\n[4] Wyswietl kolejke w odwrotnej kolejnosci");
    printf("\n[5] Dodaj n liczb do kolejki");
    printf("\n[6] Zabierz n liczb z kolejki");
    printf("\n[7] Wyczysc kolejke");
    printf("\n ---------------------------------------------------------");
    printf("\n Wybrana komenda: ");
    scanf("%d", &wybor);

    switch(wybor)
    {
    case 1:
        {
            system("cls");
            printf("\nPodaj liczbe:");
            int x;
            scanf("%d", &x);
            dodajliczbe(&glowa, &ogon, x);
            break;
        }
    case 2:
        {
            zabierzliczbe(&glowa, &ogon);
            break;
        }
    case 3:
        {
            system("cls");
            wyswietl(glowa);
            break;
        }
    case 4:
        {
            system("cls");
            wyswietl_ogon(ogon, glowa);
            break;
        }
    case 5:
        {
            system("cls");
            printf("\nIle liczb chcesz dodac: ");
            int ile;
            scanf("%d", &ile);
            for (int i=0; i<ile; i++)
            {
                printf("\nPodaj liczbe: ");
                int x;
                scanf("%d", &x);
                dodajliczbe(&glowa, &ogon, x);
            }
            break;
        }
    case 6:
        {
            system("cls");
            printf("\nIle liczb chcesz zabrac: ");
            int ile;
            scanf("%d", &ile);
            for (int i=0; i<ile; i++)
            {
                zabierzliczbe(&glowa, &ogon);
            }
            break;
        }
    case 7:
        {
            wyczysc(&glowa, &ogon);
            break;
        }

    }
    }while (wybor!=0);
    return 0;
}
