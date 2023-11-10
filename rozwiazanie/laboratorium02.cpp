/*
 Autor: Dominik Kaczmarek
 Grupa: Pn/P 13:15
 Temat: Laboratorium 2
 Data: 07.11.2023 r.
 */

#include <stdio.h>
#include <math.h>


void tabliczka_mnozenia() {
    int liczba_wierszy, liczba_kolumn, max_wierszy = 23, max_kolumn = 28;
    printf("Podaj liczbe wierszy tabliczki mnozenia: ");
    scanf("%d", &liczba_wierszy);
    printf("Podaj liczbe kolumn tabliczki mnozenia: ");
    scanf("%d", &liczba_kolumn);

    while (liczba_wierszy > max_wierszy) {
        printf("Podano zbyt duza liczbe wierszy. Limit to %d. Podaj inna liczbe: ", max_wierszy);
        scanf("%d", &liczba_wierszy);
    }
    while (liczba_kolumn > max_kolumn) {
        printf("Podano zbyt duza liczbe kolumn. Limit to %d. Podaj inna liczbe: ", max_kolumn);
        scanf("%d", &liczba_kolumn);
    }

    printf("\n     | ");
    for (int kolumna = 1; kolumna <= liczba_kolumn; kolumna++) {
        printf("%3d ", kolumna);
    }
    printf("\n-----|-");
    for (int kolumna = 1; kolumna <= liczba_kolumn; kolumna++) {
        printf("----");
    }
    printf("\n");
    for (int wiersz = 1; wiersz <= liczba_wierszy; wiersz++) {
        printf(" %3d | ", wiersz);
        for (int kolumna = 1; kolumna <= liczba_kolumn; kolumna++){
            printf("%3d ", wiersz*kolumna);
        }
        printf("\n");
    }
    //
    printf("\n\nKliknij Enter, aby kontynuowac.");
    fflush(stdin);
    getchar();
    }

void liczenie_cyfr() {
    unsigned long long int liczba, oryginalna_liczba;
    printf("Podaj duza liczbe calkowita dodatnia: ");
    scanf("%llu", &oryginalna_liczba);
    printf("Twoja liczba to %llu w systemie dziesietnym,\n%llo w systemie osemkowym,"
           "\n%llx w systemie szesnastkowym.\n", oryginalna_liczba, oryginalna_liczba, oryginalna_liczba);
    liczba = oryginalna_liczba;
    int suma_cyfr = 0;
    do{
        suma_cyfr += liczba % 10;
        liczba = (liczba - liczba%10)/10;
        // printf("suma: %d, liczba: %llu\n", suma_cyfr, liczba);
    } while (liczba > 0);
    printf("\nSuma cyfr w postaci dziesietnej wynosi: %d.\n", suma_cyfr);
    liczba = oryginalna_liczba;
    suma_cyfr = 0;
    do{
        suma_cyfr += liczba % 8;
        liczba = (liczba - liczba % 8) / 8;
        // printf("suma: %d, liczba: %llu\n", suma_cyfr, liczba);
    } while (liczba > 0);
    printf("\nSuma cyfr w postaci osemkowej wynosi: %d.\n", suma_cyfr);
    liczba = oryginalna_liczba;
    suma_cyfr = 0;
    do{
        suma_cyfr += liczba % 16;
        liczba = (liczba - liczba % 16) / 16;
        // printf("suma: %d, liczba: %llu\n", suma_cyfr, liczba);
    } while (liczba > 0);
    printf("\nSuma cyfr w postaci szesnastkowej wynosi: %d.\n", suma_cyfr);
    //
    printf("\n\nKliknij Enter, aby kontynuowac.");
    fflush(stdin);
    getchar();
}

void suma_szeregow_z_dokladnoscia(){
    double eps, suma1 = 0, suma2 = 0, wyraz1, wyraz2;
    printf("Podaj dokladnosc obliczen: ");
    scanf("%lf", &eps);
    while (eps > 0.1) {
        printf("Podano zbyt duza liczbe. Podaj liczbe mniejsza od 0.1:");
        scanf("%lf", &eps);
    }
    // pierwszy szereg
    wyraz1 = 1.0;
    for (int k = 1; fabs(wyraz1) >= eps; k++) {
        if (k%2 != 0) wyraz1 = 1.0/(2*k-1);
        else wyraz1 = 1.0/(2*k-1)*(-1);
        suma1 += wyraz1;
    }
    suma1 *= 4;
    // printf("Suma wynosi: %lf.", suma1);
    // drugi szereg
    wyraz2 = 1.0;
    suma2 += wyraz2;
    for (int k = 1; fabs(1/wyraz2) >= eps; k++) {
        wyraz2 = (wyraz2*k);
        suma2 += 1/wyraz2;
    }
    // printf("Suma wynosi: %lf.", suma2);
    printf("Suma szeregow z podana dokladnoscia to: %lf.", suma1+suma2);
    //
    printf("\n\nKliknij Enter, aby kontynuowac.");
    fflush(stdin);
    getchar();
}

void srednia_liczb_losowych() {
    int minimalna, maksymalna, ile_liczb;
    printf("Wybierz przedzial wartosci do losowania liczb. \nPodaj najmniejsza wartosc: ");
    scanf("%d", &minimalna);
    printf("Podaj najwieksza wartosc: ");
    scanf("%d", &maksymalna);
    printf("Podaj ile liczb ma zostac wylosowanych: ");
    scanf("%d", &ile_liczb);
    srand(time_t(NULL));
    printf("Wylosowane liczby: \n");
    int losowa, ile_dodatnich = 0, ile_ujemnych = 0, suma_dodatnich = 0, suma_ujemnych = 0;
    for (int liczba = 1; liczba <= ile_liczb; liczba++) {
        losowa = minimalna + rand()%(maksymalna - minimalna + 1);
        printf("%d\n", losowa);
        if (losowa > 0) {
            ile_dodatnich ++;
            suma_dodatnich += losowa;
        }
        if (losowa < 0) {
            ile_ujemnych ++;
            suma_ujemnych += losowa;
        }
    }
    printf("\nIlosc wylosowanych liczb dodatnich: %d. Ich srednia to %.3f. "
           "\nIlosc wylosowanych liczb ujemnych: %d. Ich srednia to %.3f.",
           ile_dodatnich, float(suma_dodatnich)/ile_dodatnich, ile_ujemnych, float(suma_ujemnych)/ile_ujemnych);
    //
    printf("\n\nKliknij Enter, aby kontynuowac.");
    fflush(stdin);
    getchar();
}

void rysowanie_szachownicy() {
    const char FIOLETOWY[] = "\033[35m";
    const char NIEBIESKI[] = "\033[36m";
    const char DOMYSLNY[] = "\033[0m";

    int wymiar_pola_x, wymiar_pola_y, wymiar_szachownicy_x, wymiar_szachownicy_y, zmiana_koloru;
    printf("Podaj wymiary pojedynczego pola szachownicy (dlugosc i wysokosc) oddzielone spacja: ");
    scanf("%d %d", &wymiar_pola_x, &wymiar_pola_y);
    printf("Podaj wymiary szachownicy (dlugosc i wysokosc) oddzielone spacja: ");
    scanf("%d %d", &wymiar_szachownicy_x, &wymiar_szachownicy_y);
    printf("\nOto twoja szachownica\n\n");
    for (int wysokosc_szachownicy = 0; wysokosc_szachownicy < wymiar_szachownicy_y; wysokosc_szachownicy++) {
        if (wysokosc_szachownicy % 2 == 0) zmiana_koloru = 0;
        else zmiana_koloru = 1;
        for (int wysokosc_pola = 0; wysokosc_pola < wymiar_pola_y; wysokosc_pola++) {
            for (int dlugosc_szachownicy = 0; dlugosc_szachownicy < wymiar_szachownicy_x; dlugosc_szachownicy++) {
                if (dlugosc_szachownicy % 2 == zmiana_koloru) printf(FIOLETOWY);
                else printf(NIEBIESKI);
                for (int dlugosc_pola = 0; dlugosc_pola < wymiar_pola_x; dlugosc_pola++) {
                    printf("# ");
                }
            }
            printf("\n");
        }
    }
    printf(DOMYSLNY);
    //
    printf("\n\nKliknij Enter, aby kontynuowac.");
    fflush(stdin);
    getchar();

}

int main() {
    printf("Autor: Dominik Kaczmarek Pn/P 13:15\n\n\n");
    // tabliczka_mnozenia();
    // liczenie_cyfr();
    // suma_szeregow_z_dokladnoscia();
    // srednia_liczb_losowych();
    // rysowanie_szachownicy();
    int wybranaOpcja;
    do {
        printf("\n\n\n=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=\n");
        printf("||                  Wybierz zadanie do uruchomienia                      ||\n");
        printf("|| *1* Zadanie 1 - Tabliczka mnozenia                                    ||\n");
        printf("|| *2* Zadanie 2 - Liczenie sumy cyfr wprowadzonej liczby                ||\n");
        printf("|| *3* Zadanie 3 - Obliczanie sumy dwoch szeregow z podana dokladnoscia  ||\n");
        printf("|| *4* Zadanie 4 - Obliczanie sredniej liczb losowych                    ||\n");
        printf("|| *5* Zadanie 5 - Rysowanie szachownicy o podanych wymiarach            ||\n");
        printf("|| *6* Zakoncz dzialanie programu                                        ||\n");
        printf("=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=\n");
        printf("Wprowadz numer wybranej opcji: ");
        scanf("%i", &wybranaOpcja);
        system("cls");
        switch (wybranaOpcja) {
            case 1: tabliczka_mnozenia();
                break;
            case 2: liczenie_cyfr();
                break;
            case 3: suma_szeregow_z_dokladnoscia();
                break;
            case 4: srednia_liczb_losowych();
                break;
            case 5: rysowanie_szachownicy();
                break;
            case 6:
                break;
            default:
                printf("Wprowadzono nieprawidlowa cyfre.");
                break;
        }
        system("cls");
    } while (wybranaOpcja != 6);
    return 0;
}
