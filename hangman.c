#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include "hangman.h"


int get_word(char secret[]){
    // check if file exists first and is readable
    FILE *fp = fopen(WORDLIST_FILENAME, "rb");
    if( fp == NULL ){
        fprintf(stderr, "No such file or directory: %s\n", WORDLIST_FILENAME);
        return 1;
    }

    // get the filesize first
    struct stat st;
    stat(WORDLIST_FILENAME, &st);
    long int size = st.st_size;

    do{
        // generate random number between 0 and filesize
        long int random = (rand() % size) + 1;
        // seek to the random position of file
        fseek(fp, random, SEEK_SET);
        // get next word in row ;)
        int result = fscanf(fp, "%*s %20s", secret);
        if( result != EOF )
            break;
    }while(1);

    fclose(fp);

    return 0;
}
// task_1
int is_word_guessed(const char secret[], const char letters_guessed[]){
    // vypocet dlzky slova
    int position = 0;
    int length = 0;
    while (secret[position] != '\0')
    {
        length++;
        position++;
    }

    // vypocet dlzky retazca s pismenami
    int position2 = 0;
    int length2 = 0;
    while (letters_guessed[position2] != '\0')
    {
        length2++;
        position2++;
    }

    // zistovanie ci tam su potrebne pismena na uhadnutie, 'pocet' sa zvacsi ked tam dane pismeno je
    int pocet = 0;
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length2; j++)
        {
            if (secret[i] == letters_guessed[j])
            {
                pocet++;
            }
            
        }
        
    }
    // ak by slovo malo viac rovnakych pismen, 'pocet' moze byt vacsi preto to podmienka musi zohladnit
    if (pocet == length || pocet > length)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// task_2
void get_guessed_word(const char secret[], const char letters_guessed[], char guessed_word[]){
    // zistenie dlzky tajneho slova
    int u =0;
    int length = 0;
    while (secret[u] != '\0')
    {
        length++;
        u++;
    }
    // zistenie dlzky retazca s pismenami
    int y = 0;
    int length2 = 0;
    while (letters_guessed[y] != '\0')
    {
        y++;
        length2++;
    }
    // prepisovanie slova
    if (letters_guessed[0] < 97 || letters_guessed[0] > 122)
    {
        // printf("prazdny retazec");
        for (int i = 0; i < length; i++)
        {
            guessed_word[i] = '_';
        }
        
    }
    else{
        for (int i = 0; i < length; i++)
        {
        for (int j = 0; j < length2; j++)
        {
            if (secret[i] == letters_guessed[j])
            {
                guessed_word[i] = secret[i];
                break;
            }
            else
            {
                guessed_word[i] = '_';
            }
            }        
        }
    }
    guessed_word[length] = '\0';
    /* vypis pola guessed_word
   for (int i = 0; i < length; i++)
   {
       printf("%c", guessed_word[i]);
   }
   printf("\n");
   */       
}

// task_3
void get_available_letters(const char letters_guessed[], char available_letters[])
{
    char abeceda[] = "abcdefghijklmnopqrstuvwxyz";
    // zistenie dlzky retazca s hadanymi pismenami
    int length = 0;
    int x = 0;
    while (letters_guessed[x] != '\0')
    {
        length++;
        x++;
    }
    // printf("%d\n", length);
    // zistovanie ktore pismena chybaju
    int najdene = 0;
    int zapis = 0;
    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < length; j++)
        {   
            najdene = 0;
            if (abeceda[i] == letters_guessed[j])
            {
                // printf("Nasiel som %c\n", abeceda[i]);
                najdene = 1;
                break;

            }
            
                        
        }
        if (najdene == 0)
            {
                // printf(" najdene je nula\n");
                available_letters[zapis] = abeceda[i];
                zapis++;
            }
    }
    available_letters[zapis] = '\0';
    /* vypis chybajucich pismen
    int length2 = 0;
    int a = 0;
    while (available_letters[a] != '\0')
    {
        length2++;
        a++;
    }
    // printf("%d\n", length2);
    for (int i = 0; i < length2; i++)
    {
        printf("%c", available_letters[i]);
    }
    */
}

// task 4
void hangman(const char secret[]){
    // vypocitanie dlzky slova v secret[]
    int dlzka_slova = 0, counter = 0;
    while (secret[counter] != '\0')
    {
        counter++;
        dlzka_slova++;
    }
    printf("Welcome to the game, Hangman!\nI am thinking of a word that is %d letters long.\n-------------\n", dlzka_slova);

    int pocet_pokusov = 8;
    int pocitadlo = 0;
    char pismeno;
    char pismeno_pole[15];
    char dostupne_pismena[] = "abcdefghijklmnopqrstuvwxyz";
    char hadane_pismena[] = "                                                     ";
    char hadane_slovo[16];
    int hadal_cele = 0;
    int vypisy = 0;
    
    
    while (pocet_pokusov != 0 ){
        int spravne = 0;
        int uz_pouzite = 0;
        int zly_znak = 0;
        
        printf("You have %d guesses left.\n", pocet_pokusov);
        printf("Available letters: ");
        get_available_letters(hadane_pismena, dostupne_pismena);
        // vypis dostupnych pismen
        int length2 = 0;
        int a = 0;
        while (dostupne_pismena[a] != '\0')
        {
            length2++;
            a++;
        }
        // printf("%d\n", length2);
        for (int i = 0; i < length2; i++)
        {
            printf("%c", dostupne_pismena[i]);
        }

        printf("\nPlease guess a letter: ");
        scanf("%s", pismeno_pole);
        pismeno = pismeno_pole[0];
        // zistujeme ci pouzivatel nezadal cele slovo
        if (pismeno_pole[1] > 1)
        {
            hadal_cele = 1;
            if (strcmp(pismeno_pole, secret) == 0)
            {
                printf("Congratulations, you won!\n");
                break;
            }
            else
            {
                printf("Sorry, bad guess. The word was %s.\n", secret);
                break;
            }
            
            
        }
        
        
        // prevod pismena
        if ((pismeno > 64 && pismeno < 91) || (pismeno > 96 && pismeno < 123))
        {
            if (pismeno > 64 && pismeno < 91)
            {
                pismeno = pismeno + 32;
            }
            
        }
        else{
            zly_znak = 1;
        }
        
        // hlada ci je pismeno v tajnom slove
        for (int i = 0; i < 15; i++)
        {
            if (secret[i] == pismeno)
            {
               spravne = 1;
               
               break;
            }
            else
            {
                spravne = 0;
            }
        }

        // hlada ci pismeno uz nebolo hadane
        for (int i = 0; i < 30; i++)
        {
            if (pismeno == hadane_pismena[i])
            {
                uz_pouzite = 1;
            }
            
        }

        // vypisy        
        if (zly_znak == 1)
        {
            printf("Oops! '%c' is not a valid letter:", pismeno);
            get_guessed_word(secret, hadane_pismena, hadane_slovo);
            vypisy = 0;
            while (hadane_slovo[vypisy] != '\0')
            {
                printf(" %c", hadane_slovo[vypisy]);
                vypisy++;
            }
            
            /*for (int i = 0; i < sizeof(hadane_slovo); i++)
            {
                printf(" %c", hadane_slovo[i]);
            }
            */
            printf("\n-------------\n");
        }
        
        else if (uz_pouzite == 1)
        {
            printf("Oops! You've already guessed that letter:");
            get_guessed_word(secret, hadane_pismena, hadane_slovo);
            vypisy = 0;
            while (hadane_slovo[vypisy] != '\0')
            {
                printf(" %c", hadane_slovo[vypisy]);
                vypisy++;
            }
            /*
            for (int i = 0; i < sizeof(hadane_slovo); i++)
            {
                printf("%c ", hadane_slovo[i]);
            }
            */
            printf("\n-------------\n");
        }
        
        else if (spravne == 1)
        {
            hadane_pismena[pocitadlo] = pismeno;
            pocitadlo++;
            printf("Good guess:");
            get_guessed_word(secret, hadane_pismena, hadane_slovo);
            vypisy = 0;
            while (hadane_slovo[vypisy] != '\0')
            {
                printf(" %c", hadane_slovo[vypisy]);
                vypisy++;
            }
            /*
            for (int i = 0; i < sizeof(hadane_slovo); i++)
            {
                printf("%c ", hadane_slovo[i]);
            }
            */
            printf("\n-------------\n");
        }
        
        else if (spravne == 0)
        {
            hadane_pismena[pocitadlo] = pismeno;
            pocitadlo++;
            pocet_pokusov--;
            get_guessed_word(secret, hadane_pismena, hadane_slovo);
            printf("Oops! That letter is not in my word:");
            vypisy = 0;
            while (hadane_slovo[vypisy] != '\0')
            {
                printf(" %c", hadane_slovo[vypisy]);
                vypisy++;
            }
            /*
            get_guessed_word(secret, hadane_pismena, hadane_slovo);
            for (int i = 0; i < sizeof(hadane_slovo); i++)
            {
                printf("%c ", hadane_slovo[i]);
            }
            */
            printf("\n-------------\n");
        }
        
        if (is_word_guessed(secret, hadane_pismena) == 1)
        {
            printf("Congratulations, you won!\n");
            break;
        }
        
        
       
    }
    if (is_word_guessed(secret, hadane_pismena) != 1 && hadal_cele == 0)
    {
        printf("Sorry, you ran out of guesses. The word was %s.\n", secret);
    }
    
    
}