#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int running = 1;
struct Cruciverba{
    int maxX;
    int maxY;
    char grigliaCorretta[25][25]; //la griglia con tutte le parole e lettere finita
    char grigliaUtente[25][25]; //la griglia su cui scrive l'utente
    char descrizioni[300];
};

int main(){
    int choice;
    char strTempChoice[20];
    while (running) //main userEventLoop
    {
        printf("\
_____C R U C I V E R B A____\n\
|\n\
|   1. Crea un nuovo Cruciverba  - (editor)\n\
|   2. Risolvi un Cruciverba     - (player)\n\
|\n\
|   3. Esci      ___|_|         b           \n\
|           __|_____|_|___      a           \n\
|       |  |  |_____|_          x           \n\
|       '--|__|__   |           t           \n\
|    --|___|     |  '--   l o r e n z i     \n\
|                               r           \n\
Scelta: ");
    scanf(" %s", &strTempChoice);
    choice = atoi(strTempChoice);
    switch (choice)
    {
    case 1:
        {
            struct Cruciverba cruciverba;
            printf("Hai scelto di creare un nuovo cruciverba\n");
            printf("Coordinata massima X: ");
            scanf(" %d", &cruciverba.maxX);
            printf("Coordinata massima Y: ");
            scanf(" %d", &cruciverba.maxY);
            if (cruciverba.maxX >= 9 && cruciverba.maxX <= 25 && cruciverba.maxY >= 9 && cruciverba.maxY <= 25)
            {
                printf("coordinate massime impostate, X: %d, Y: %d\nCreando il cruciverba ...\n", cruciverba.maxX, cruciverba.maxY);

                for (int x = 0; x < cruciverba.maxX; x++)
                {
                    for (int y = 0; y < cruciverba.maxY; y++)
                    {
                        cruciverba.grigliaCorretta[x][y] = '.';
                    }
                }
                
                for (int x = cruciverba.maxX; x < 25; x++)
                {
                    for (int y = 0; y < 25; y++)
                    {
                        cruciverba.grigliaCorretta[x][y] = '~';
                    }
                }

                for (int x = 0; x < cruciverba.maxX; x++)
                {
                    for (int y = cruciverba.maxY; y < 25; y++)
                    {
                        cruciverba.grigliaCorretta[x][y] = '~';
                    }
                }

                printf("\n");
                printf("Questo e' il risultato della griglia\n\n");


                int sceneRunning = 1;
                int sceneChoice;
                int chosenX = 3;
                int chosenY = 3;
                while (sceneRunning)
                {
                    for (int y = 0; y < cruciverba.maxY; y++)
                    {
                        for (int x = 0; x < cruciverba.maxX; x++)
                        {
                            if (chosenX == x && chosenY == y)
                            {
                                printf("@%c", cruciverba.grigliaCorretta[x][y]);
                            } else {
                                printf(" %c", cruciverba.grigliaCorretta[x][y]);
                            }
                        }
                        printf("\n");
                    }
                    printf("\
    ____E D I T O R   M E N U_____\n\
    |\n\
    |   0. carica una schematica\n\
    |   1. salva la schematica\n\
    |   \n\
    |   3. imposta la stringa di descrizioni\n\
    |   5. imposta carattere\n\
    |   \n\
    |   Usa il numpad per spostarti!\n\
    |            \n\
    |           /|\\          \n\
    |            8           \n\
    |       <- 4   6 ->  \n\
    |            2           \n\
    |           \\|/         \n\
    |   \n\
    |   7. muovi cursore a coordinate\n\
    |   9. esci\n\
    |\n\
    |   10. mostra la stringa di descrizioni\n\
    |   11. riempi tutti i punti vuoti con cancelletti\n\
    |______Scelta: \
    ");
                    scanf(" %d", &sceneChoice);
                    if (sceneChoice == 1)
                    {
                        int clearToSave = 0;
                        printf("Hai scelto di salvare lo schema in file. Inserire il nome del file (estensione inclusa): ");
                        char filename[20];
                        scanf(" %s", &filename);
                        FILE * advidoryFilePointer;
                        advidoryFilePointer = fopen(filename, "r");
                        if (advidoryFilePointer!=NULL)
                        {
                            fclose(advidoryFilePointer);
                            printf("Esiste gia' un file con lo stesso nome. Sovrascrivere? (y/n): ");
                            char tempChoice;
                            scanf(" %c", &tempChoice);
                            if (tempChoice == 'Y' || tempChoice == 'y')
                            {
                                clearToSave = 1;
                            }
                            
                            
                        } else {
                            clearToSave = 1;
                        }

                        if (clearToSave)
                        {
                            printf("scrivendo i contenuti della griglia in %s\n", filename);
                            FILE *filepointer;
                            filepointer = fopen(filename, "w");
                            if (filepointer != NULL)
                            {
                                for (int y = 0; y < 25; y++)
                                {
                                    for (int x = 0; x < 25; x++)
                                    {
                                        putc(cruciverba.grigliaCorretta[x][y], filepointer);
                                    }
                                    putc( '\n', filepointer);
                                }
                                int desLen = strlen(cruciverba.descrizioni);
                                for (int i = 0; i < desLen; i++)
                                {
                                    putc(cruciverba.descrizioni[i], filepointer);
                                }
                                fclose(filepointer);
                            } else {
                                printf("Non e' stato possibile aprire il file, riprova piu' tardi\n");
                            }
                            
                        }
                    } else if (sceneChoice == 2)
                    {
                        if (chosenY < cruciverba.maxY-1)
                        {
                            printf("moved! Y: \n", chosenY);
                            chosenY ++;
                        }
                    } else if(sceneChoice == 3)
                    {
                        printf("Hai scelto di impostare la stringa di descrizione: attenzione ai caratteri formattatori:\n\
    | carattere - azione               |\n\
    |     \\n      | fa andare a capo   |\n\
    |     \\s      | stampa uno spazio  |\n\
    |     \\t      | stampa 4 spazi     |\n\
    |     \\\\      | stampa una slash   |\n\
    |     _       |  stampa uno spazio |\n\
    |__________________________________|\n\
    |\n\
    ");
                        scanf(" %s", &cruciverba.descrizioni);
                        printf("Stringa impostastata!");
                    }else if (sceneChoice == 4)
                    {
                        if (chosenX > 0)
                        {
                            chosenX --;
                            printf("moved! X: \n", chosenX);
                        }
                    } else if (sceneChoice == 5)
                    {
                        printf("Inserire il carattere desiderato: \n");
                        scanf(" %c", &cruciverba.grigliaCorretta[chosenX][chosenY]);
                        if (cruciverba.grigliaCorretta[chosenX][chosenY] <= 90 && cruciverba.grigliaCorretta[chosenX][chosenY] >= 65)
                        {
                            cruciverba.grigliaCorretta[chosenX][chosenY] += 32;
                        }
                    } else if (sceneChoice == 6)
                    {
                        if (chosenX < cruciverba.maxX-1)
                        {
                            printf("moved! X: \n", chosenX);
                            chosenX ++;
                        }
                    } else if (sceneChoice == 7)
                    {
                        int tmpChosenX;
                        int tmpChosenY;
                        printf("Coordinata X: ");
                        scanf(" %d", &tmpChosenX);
                        printf("Coordinata Y: ");
                        scanf(" %d", &tmpChosenY);
                        if (tmpChosenX < 0)
                        {
                            chosenX = 0;
                        } else if (tmpChosenX > cruciverba.maxX-1)
                        {
                            chosenX = cruciverba.maxX-1;
                        } else {
                            chosenX = tmpChosenX;
                        }

                        if (tmpChosenY < 0)
                        {
                            chosenY = 0;
                        } else if (tmpChosenY > cruciverba.maxY-1)
                        {
                            chosenY = cruciverba.maxY-1;
                        } else {
                            chosenY = tmpChosenY;
                        }
                        
                    }else if (sceneChoice == 8)
                    {
                        if (chosenY > 0)
                        {
                            printf("moved! Y: \n", chosenY);
                            chosenY --;
                        }
                    } else if (sceneChoice == 9){
                        sceneRunning = 0;
                    } else if(sceneChoice == 0)
                    {
                        char filename[20];
                        printf("Hai scelto di caricare una schematica\nInserire il nome del file dal quale caricarla: ");
                        scanf(" %s", &filename);
                        FILE *filepointer;
                        filepointer = fopen(filename, "r");
                        if (filepointer != NULL)
                        {
                            int delLen = strlen(cruciverba.descrizioni);
                            for (int i = 0; i < delLen; i++)
                            {
                                cruciverba.descrizioni[i] = '\0';
                            }
                            for (int y = 0; y < 25; y++)
                            {
                                for (int x = 0; x < 25; x++)
                                {
                                    cruciverba.grigliaCorretta[x][y] = getc(filepointer);
                                }
                                getc(filepointer);
                            }
                            char tempChar = getc(filepointer);
                            int i = 0;
                            while (tempChar != EOF)
                            {
                                cruciverba.descrizioni[i] = tempChar;
                                i++;
                                tempChar = getc(filepointer);
                            }
                            fclose(filepointer);
                            chosenX = 3;
                            chosenY = 3;
                            cruciverba.maxX = 0;
                            while (cruciverba.grigliaCorretta[cruciverba.maxX][0] != '~' && cruciverba.maxX < 25)
                            {
                                cruciverba.maxX++;
                            }
                            cruciverba.maxY = 0;
                            while (cruciverba.grigliaCorretta[0][cruciverba.maxY] != '~' && cruciverba.maxY < 25)
                            {
                                cruciverba.maxY++;
                            }
                            printf("Griglia caricata, dimensioni impostate { X: %d, Y: %d}\n", cruciverba.maxX, cruciverba.maxY);
                            
                            
                            
                        } else {
                            printf("File specificato non e' stato trovato, non e' stato possibile caricare le informazioni nella griglia\n");
                        }
                        
                    } else if (sceneChoice == 10) {
                        int desLen = strlen(cruciverba.descrizioni);
                        if (desLen > 0)
                        {
                            for (int i = 0; i < strlen(cruciverba.descrizioni); i++)
                                {
                                    if (cruciverba.descrizioni[i] == '\\')
                                    {
                                        i++;
                                        if (cruciverba.descrizioni[i] == 'n')
                                        {
                                            printf("\n");
                                        } else if (cruciverba.descrizioni[i] == '\\')
                                        {
                                            printf("\\");
                                        } else if (cruciverba.descrizioni[i] == 't')
                                        {
                                            printf("    ");
                                        }
                                    } else if (cruciverba.descrizioni[i] == '_')
                                    {
                                        printf(" ");
                                    } else
                                    {
                                        printf("%c", cruciverba.descrizioni[i]);
                                    }
                                }
                        } else {
                            printf("Non ci sono indizi da mostrare\n");
                        }
                        printf("\n\n");
                    } else if (sceneChoice == 11)
                    {
                        for (int y = 0; y < cruciverba.maxY; y++)
                        {
                            for (int x = 0; x < cruciverba.maxX; x++)
                            {
                                if (cruciverba.grigliaCorretta[x][y] == '.')
                                {
                                    cruciverba.grigliaCorretta[x][y] == '#';
                                }
                            }
                        }
                        
                        
                    } else
                    {
                        printf("Il comando inserito non corrisponde a nulla all'interno del programma\n");
                    }
                }
                
            } else {
                printf("Le coordinate erano troppo grandi o troppo piccole per la griglia\nRiprova con altre coordinate massime\n");
            }
        }
        break;
        
        case 2:
            printf("Hai scelto di giocare ad un cruciverba!\n");
            char filename[20];
            printf("File contenente il cruciverba che vuoi giocare: ");
            scanf(" %s", &filename);
            FILE * filepointer;
            filepointer = fopen(filename, "r");
            if (filepointer != NULL)
            {
                struct Cruciverba cruciverba;
                printf("Caricando il cruciverba da %s!\n", filename);
                for (int y = 0; y < 25; y++)
                {
                    for (int x = 0; x < 25; x++)
                    {
                        cruciverba.grigliaCorretta[x][y] = getc(filepointer);
                    }
                    getc(filepointer);
                    
                }
                char tempChar = getc(filepointer);
                int i = 0;
                while (tempChar != EOF)
                {
                    cruciverba.descrizioni[i] = tempChar;
                    i++;
                    tempChar = getc(filepointer);
                }
                fclose(filepointer);
                cruciverba.maxX = 0;
                while (cruciverba.maxX<25 && cruciverba.grigliaCorretta[cruciverba.maxX][0] != '~')
                {
                    cruciverba.maxX++;
                }
                cruciverba.maxY = 0;
                while (cruciverba.maxY<25 && cruciverba.grigliaCorretta[0][cruciverba.maxY] != '~')
                {
                    cruciverba.maxY++;
                }
                for (int y = 0; y < cruciverba.maxY; y++)
                {
                    for (int x = 0; x < cruciverba.maxX; x++)
                    {
                        if (cruciverba.grigliaCorretta[x][y] >= 'a' && cruciverba.grigliaCorretta[x][y] <= 'z')
                        {
                            cruciverba.grigliaUtente[x][y] = '.';
                        } else {
                            cruciverba.grigliaUtente[x][y] = cruciverba.grigliaCorretta[x][y];
                        }
                    }
                }
                printf("Cruciverba caricato da %s con X: %d, Y: %d\n", filename, cruciverba.maxX, cruciverba.maxY);
                int sceneRunning = 1;
                int chosenX = 3;
                int chosenY = 3;
                int sceneSubChoice;
                while (sceneRunning)
                {
                    printf("\
._________P L A Y E R   M E N U_____.\n\
|\n\
|   1. Finito!\n\
|   \n\
|   Usa il numpad per spostarti!\n\
|            \n\
|           /|\\          \n\
|            8           \n\
|       <- 4   6 ->  \n\
|            2           \n\
|           \\|/         \n\
|   \n\
|   5. Immetti un carattere\n\
|   3. Mostra descrizioni\n\
|   \n\
|   \n\
|   9. Esci al menu'\n\
");
                    printf("Cruciverba:\n");
                    for (int y = 0; y < cruciverba.maxY; y++)
                    {
                        for (int x = 0; x < cruciverba.maxX; x++)
                        {
                            if (cruciverba.grigliaCorretta[x][y] == '#')
                            {
                                if (chosenX == x && chosenY == y)
                                {
                                    printf("@ ");
                                } else {
                                    printf("  ");
                                }
                            } else {
                                if (chosenX == x && chosenY == y)
                                {
                                    printf("@%c", cruciverba.grigliaUtente[x][y]);
                                } else {
                                    printf(" %c", cruciverba.grigliaUtente[x][y]);
                                }
                            }
                        }
                        printf("\n");
                    }
                    scanf(" %d", &sceneSubChoice);
                    switch (sceneSubChoice)
                    {
                    case 1:
                    {                       
                        int errori = 0;
                        for (int y = 0; y < cruciverba.maxY; y++)
                        {
                            for (int x = 0; x < cruciverba.maxX; x++)
                            {
                                if (cruciverba.grigliaCorretta[x][y] != cruciverba.grigliaUtente[x][y])
                                {
                                    errori++;
                                }
                                
                            }
                            
                        }
                        
                        
                        
                        
                        
                        if (errori == 0)
                        {
                            printf("\
.______________________________________________________________________________________.\n\
|                                                                                      |\n\
|-----------    H A I   C O M P L E T A T O   I L   C R U C I V E R B A !   -----------|\n\
| / \\------------------, \n\
| \\_,|                 | \n\
|    |    Hai vinto!   |  \n\
|    |  ,---------------- \n\
|    \\_/_______________/ \n\
\n\
|-+-|-|-----------------------------------------------------|-|-+-|\n\
|-+-|-|   _                             .-.                 |-|-+-|\n\
|-+-|-|  / )  .-.    ___          __   (   )                |-|-+-|\n\
|-+-|-| ( (  (   ) .'___)        (__'-._) (                 |-|-+-|\n\
|-+-|-|  \\ '._) (,'.'               '.     '-.              |-|-+-|\n\
|-+-|-|   '.      /  '\\               '    -. '.            |-|-+-|\n\
|-+-|-|     )    /   \\ \\   .-.   ,'.   )  (  ',_)    _      |-|-+-|\n\
|-+-|-|   .'    (     \\ \\ (   \\ . .' .'    )    .-. ( \\     |-|-+-|\n\
|-+-|-|  (  .''. '.    \\ \\|  .' .' ,',--, /    (   ) ) )    |-|-+-|\n\
|-+-|-|   \\ \\   ', :    \\    .-'  ( (  ( (     _) (,' /     |-|-+-|\n\
|-+-|-|    \\ \\   : :    )  / _     ' .  \\ \\  ,'      /      |-|-+-|\n\
|-+-|-|  ,' ,'   : ;   /  /,' '.   /.'  / / ( (\\    (       |-|-+-|\n\
|-+-|-|  '.'      '   (    .-'. \\       ''   \\_)\\    \\      |-|-+-|\n\
|-+-|-|                \\  |    \\ \\__             )    )     |-|-+-|\n\
|-+-|-|              ___\\ |     \\___;           /  , /      |-|-+-|\n\
|-+-|-|             /  ___)                    (  ( (       |-|-+-|\n\
|-+-|-|             '.'                         ) ;) ;      |-|-+-|\n\
|-+-|-|                                        (_/(_/       |-|-+-|\n\
-------------------------------------------------------------------\n\
");
                            sceneRunning = 0;
                        } else {
                            printf("\
.____ non hai completato il cruciverba! ___.\n\
|                                          |\n\
|              prova ancora!               |\n\
:__________________________________________:\n\
\n");
printf("Ci sono %d errori\n", errori);
                        }
                        }
                        break;
                    
                    case 2:
                        if (chosenY < cruciverba.maxY-1)
                            {
                                printf("moved! Y: %d\n", chosenY);
                                chosenY ++;
                            }
                        break;
                    case 3:
                        {
                            printf("___I N D I Z I___\n\n");
                            int desLen = strlen(cruciverba.descrizioni);
                            if (desLen > 0)
                            {
                                for (int i = 0; i < strlen(cruciverba.descrizioni); i++)
                                    {
                                        if (cruciverba.descrizioni[i] == '\\')
                                        {
                                            i++;
                                            if (cruciverba.descrizioni[i] == 'n')
                                            {
                                                printf("\n");
                                            } else if (cruciverba.descrizioni[i] == '\\')
                                            {
                                                printf("\\");
                                            } else if (cruciverba.descrizioni[i] == 't')
                                            {
                                                printf("    ");
                                            }
                                        } else if (cruciverba.descrizioni[i] == '_')
                                        {
                                            printf(" ");
                                        } else
                                        {
                                            printf("%c", cruciverba.descrizioni[i]);
                                        }
                                    }
                            } else {
                                printf("Non ci sono indizi da mostrare\n");
                            }
                            printf("\n\n");
                        }
                        break;
                    case 4:
                        if (chosenX > 0)
                        {
                            chosenX --;
                            printf("moved! X: \n", chosenX);
                        }
                        break;
                    case 5:
                        if ( cruciverba.grigliaCorretta[chosenX][chosenY] == '.' || (cruciverba.grigliaCorretta[chosenX][chosenY] > 60 && cruciverba.grigliaCorretta[chosenX][chosenY] < 123))
                        {
                            printf("Inserire il carattere da voler inserire:\n");
                            scanf(" %c", &cruciverba.grigliaUtente[chosenX][chosenY]);
                            if (cruciverba.grigliaUtente[chosenX][chosenY] <= 90 && cruciverba.grigliaUtente[chosenX][chosenY] >= 65)
                            {
                                cruciverba.grigliaUtente[chosenX][chosenY] += 32;
                            }
                            
                        }
                        
                        break;
                    case 6:
                        if (chosenX < cruciverba.maxX-1)
                        {
                            printf("moved! X: \n", chosenX);
                            chosenX ++;
                        }
                        break;
                    case 8:
                        if (chosenY > 0)
                        {
                            printf("moved! Y: \n", chosenY);
                            chosenY --;
                        }
                        break;

                    case 9:
                        sceneRunning = 0;
                        break;

                    default:
                        break;
                    }
                    
                }
            } else {
                printf("File non trovato, riprova!\n");
            }
            
            break;

        case 3:
            printf("Uscendo dal programma\n");
            running = 0;
            break;

        
        
    default:
        break;
    }
    }
    
    return 0;
}