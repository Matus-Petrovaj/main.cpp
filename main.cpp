/*
Meno a priezvisko: Matúš Petrovaj

POKYNY:
(1)  Implementujte funkcie tak, aby splnali popis pri ich deklaraciach.
(2)  Cela implementacia musi byt v tomto jednom subore.
(3)  Odovzdajte len tento zdrojovy subor (s vypracovanymi rieseniami).
(4)  Program musi byt kompilovatelny.
(5)  Globalne a staticke premenne su zakazane.
(6)  V ziadnom pripade nemente deklaracie funkcii, ktore mate za ulohu naprogramovat
     (nemente nazvy, navratove hodnoty, ani typ a pocet parametrov v zadanych funkciach).
     Nemente implementacie zadanych datovych typov, ani implementacie hotovych pomocnych funkcii
     (ak nie je v zadani ulohy uvedene inak).
(7)  V pripade potreby mozete kod doplnit o dalsie pomocne funkcie alebo datove typy.
(8)  Vase riesenie otestujte (vo funkcii 'main' a pomocou doplnenych pomocnych funkcii alebo datovych typov).
     Testovaci kod ale nebude hodnoteny.
(9)  Funkcia 'main' musi byt v zdrojovom kode posledna.
*/

#include <iostream>
#include <climits>
#include <cstring>
#include <new>

using namespace std;

//-------------------------------------------------------------------------------------------------
// DATOVE TYPY
//-------------------------------------------------------------------------------------------------

// Pozicia v rovine
struct Position {
    int x; // x-ova suradnica
    int y; // y-ova suradnica
};

// Datum
struct Date {
    int year;  // rok
    int month; // mesiac
    int day;   // den
};

// Uspesnost vykonania funkcie
enum class Result {
    SUCCESS, // funkcia vykonana uspesne
    FAILURE  // chyba pri vykonavani funkcie
};

//-------------------------------------------------------------------------------------------------
// 1. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia na standardny vystup vytlaci udaje v strukture.
    V implementacii musi byt pouzity 'std::cout'.

    Format tlace musi byt podla nasledujucich prikladov. Bez odriadkovania. Bez uvodzoviek. Dodrzte pouzitie medzier.
    Priklady:
        "x: 10, y: 20"
        "x: -12345, y: 2"

    PARAMETER:
        [in] position - pozicia, ktora bude vytlacena
*/


void print(const Position *position) {
    cout << "x: " << position->x << ", y: " << position->y;
}


//-------------------------------------------------------------------------------------------------
// 2. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Implementujte rovnaku funkcionalitu ako v prvom priklade. Rozdiel je len typ parametra funkcie.
*/


void print(const Position &position) {
    cout << "x: " << position.x << ", y: " << position.y;
}


//-------------------------------------------------------------------------------------------------
// 3. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia zo standardneho vstupu nacita postupne dve cisla. Ulozi ich ako x-ovu a y-ovu zlozku pozicie 'position'.
    V implementacii musi byt pouzity 'std::cin' a formatovany vstup.

    PARAMETER:
        - [out] position - pozicia, ktorej hodnoty sa nastavia podla udajov zo standardneho vstupu.

    VSTUPNE PODMIENKY:
        Text zadany na standardny vstup obsahuje dve cele cisla, ktore mozno reprezetovat typom 'int'.
        Nemusite osetrovat moznost chybnych udajov na standardnom vstupe.
 */
void readFromStandardInput(Position *position) {
    cin >> position->x >> position->y;
}

//-------------------------------------------------------------------------------------------------
// 4. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia vrati najvacsiu hodnotu prvku pola 'data' a nastavi 'result' podla uspesnosti hladania.

    Ak pole obsahuje prvky, tak vrati ich maximum a nastavi 'result' na 'SUCCESS'.
    Ak pole neobsahuje ziadne prvky (jeho dlzka je nulova),
    tak vrati minimalnu hodnotu, ktoru moze reprezentovat datovy typ 'int' a nastavi result na 'FAILURE'.

    PARAMETRE:
        [in] data    - adresa zaciatku pola
        [in] length  - pocet prvkov pola (dlzka pola)
        [out] result - indikuje uspesnost najdena maxima

    NAVRATOVA HODNOTA:
        Ak pole obsahuje prvky, tak vrati hodnotu najvacsieho prvku pola 'data'.
        Ak pole neobsahuje prvky, tak vrati minimalnu hodnotu reprezentovatelnu datovym typom 'int'.

    PRIKLADY:
        vstup: (1, 2, 5, 0, 1) => navratova hodnota: 5,  result: 'Result::SUCCESS'
        vstup: (-5, -2, -10)   => navratova hodnota: -2, result: 'Result::SUCCESS'
        vstup: () => navratova hodnota: minimalna hodnota reprezentovatelna datovym typom 'int', result: 'Result::FAILURE'
*/
int maximum(const int *data, std::size_t length, Result *result) {

    int largest = INT_MIN;
    int tmp = INT_MIN;

    if(length == 0){
        Result r1 = Result::FAILURE;
        return INT_MIN; // tento riadok zmente podla zadania, je tu len kvoli kompilacii
    }

    else{
        for(int i = 0; i < length; ++i){
            tmp = data[i];
            if(tmp > largest){
                largest = tmp;
            }

        }
        Result r2 = Result::SUCCESS;
        // cout << largest;
        return largest;
    }
    // return INT_MIN; // tento riadok zmente podla zadania, je tu len kvoli kompilacii
}

//-------------------------------------------------------------------------------------------------
// 5. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia vrati pocet znakov, ktore su potrebne na zapis cisla 'value' (v desiatkovej ciselnej sustave).

    PARAMETER:
        - [in] value - analyzovana hodnota

    NAVRATOVA HODNOTA:
        Pocet znakov, potrebnych pre textovu reprezentaciu hodnoty 'value'

    PRIKLADY:
        - vstup: 18002 => vystup: 5
        - vstup: 2     => vystup: 1
        - vstup: 0     => vystup: 1
        - vstup: -500  => vystup: 4
*/
int numDigits(int value) {

    int value_test = value;
    int cnt = 1;
    if(value_test < 0){
        cnt++;
    }
    while(abs(value_test) >= 10){
        value_test = value_test / 10;
        cnt++;
    }
    // cout << cnt;
    return cnt; // tento riadok zmente podla zadania, je tu len kvoli kompilacii
}

//-------------------------------------------------------------------------------------------------
// 6. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia vytlaci na standardny vystup datum, podla zadaneho formatu.

    Vytlaceny text bude obsahovat kopiu textu vo 'format', ale
    znak 'D' nahradi dnom,
    znak 'M' nahradi mesiacom,
    znak 'Y' nahradi rokom v datume.

    PARAMETRE:
        - [in] date - datum
        - [in] format - format vylacenia datumu

    PRIKLADY:
        Nech datum je 10. aprila 2020
        - format: "D. M. Y" => "10. 4. 2020"
        - format: "D. M."   => "10. 4."
        - format: "Pisomka bude D. M. Y, v miestnosti BC 300" => "Pisomka bude 10. 4. 2020, v miestnosti BC 300"
        - format: "M/D/Y"   => "4/10/2020"
        - format: "Y-M-D"   => "2020-4-10"

    POZNAMKA:
        Vsimnite si pretazenie funkcie. Tento zdrojovy subor obsahuje 3 funkcie s nazvom 'print'.
*/
void print(const Date *date, const char *format) {
    int D = date->day;
    int M = date->month;
    int Y = date->year;

    // cout << strlen(format);

    for(int i = 0; i < strlen(format); i++){
        if(format[i] == *"D"){
            cout << D;
        }
        else if(format[i] == *"M"){
            cout << M;
        }
        else if(format[i] == *"Y"){
            cout << Y;
        }
        else{
            cout << format[i];
        }
    }

    // cout << D;
    // cout << M;
    // cout << Y;

}

//-------------------------------------------------------------------------------------------------
// 7. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia vytvori novy datum podla parametrov a vrati jeho adresu.
    Pre dynamicku alokaciu pamate pouzite operator 'new'.

    PARAMETRE:
        [in] day   - den v datume
        [in] month - mesiac v datume
        [in] year  - rok v datume

    NAVRATOVA HODNOTA:
        Adresa na dynamicky alokovany datum, ktoreho obsah je dany parametrami
*/
Date* create(int day, int month, int year) {

    Date *d1 = new Date;
    d1->day = day;
    d1->month = month;
    d1->year = year;

    return d1; // tento riadok zmente podla zadania, je tu len kvoli kompilacii
}

//-------------------------------------------------------------------------------------------------
// 8. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia dealokuje datum. Smernik na datum nastavi na 'nullptr'.
    Na dealokaciu pamate pouzite operator 'delete'.

    PARAMETER:
        [in, out] date - adresa smernika na datum

    VYSTUPNE PODMIENKY:
        Datum na adrese (*date) je dealokovany.
        (*date) ma hodnotu 'nullptr'.
*/
void destroy(Date **date) {

    delete *date;
    *date = nullptr;

}

//-------------------------------------------------------------------------------------------------
// 9. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia zisti, ci je rok v datume priestupny.

    PARAMETER:
        [in] date - datum

    NAVRATOVA HODNOTA:
        'true'  - ak rok je priestupny
        'false' - ak rok nie je priestupny

    VSTUPNA PODMIENKA:
        Rok v datume je kladne cislo

    URCENIE PRIESTUPNEHO ROKU:
        Rok delitelny cislom 4 je priestupny okrem pripadu, ked je delitelny cislom 100, ale nie je delitelny cislom 400.
        Priklady:
            - priestupne roky: 2000, 2004, 2008
            - nepriestupne roky: 2001, 2002, 2003, 2005, 2006, 2007, 2009, 2010
            - priestupne roky: 1600, 2000, 2400
            - nepriestupne roky: 1500, 1700, 1800, 1900, 2100, 2200, 2300, 2500
*/
bool isInLeapYear(const Date *date) {

    if(date->year % 100 == 0 && date->year % 400 != 0){
        // cout << "0";
        return false;
    }
    else if(date->year > 0 && date->year % 4 == 0){
        // cout << "1";
        return true;
    }
    else{
        // cout << "0";
        return false;
    }
}

//-------------------------------------------------------------------------------------------------
// 10. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia zisti, ci je datum platny.

    Treba overit, ci datum moze existovat. Napriklad
    v januari moze byt den od 1 do 31,
    vo februari od 1 do 28 alebo 29, podla toho, ci je rok priestupny.
    Rok ma mesiac 1 az 12.

    PARAMETER:
        [in] date - datum

    NAVRATOVA HODNOTA:
        'true'  - ak datum je platny
        'false' - ak datum nie je platny

    VSTUPNA PODMIENKA:
        Rok v datume je kladne cislo
*/
bool isValid(const Date *date) {

    int months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if(isInLeapYear(date)){
        months[1] = 29;
    }

    if(date->year >= 0){
        if(1 <= date->month && date->month <= 12){
            if(date->day >= 1 && date->day <= months[date->month - 1]){
                return true;
            }
        }
    }

    return false; // tento riadok zmente podla zadania, je tu len kvoli kompilacii
}

//-------------------------------------------------------------------------------------------------
// TESTOVANIE
//-------------------------------------------------------------------------------------------------

// tu mozete doplnit pomocne testovacie funkcie a struktury

int main() {

    /*
    U 1/2
    Position position_1;
    position_1.x = 10;
    position_1.y = 20;
    print(&position_1);
     */

    /* U 3
    Position position_1;
    readFromStandardInput(&position_1);
    print(&position_1);
    */

    /* U 4
    Result res;
    const int vstup_1[] = {1, 2, 5, 0, 1};
    const int vstup_2[] = {-50, -1, 10};
    const int vstup_3[] = {0};

    cout << maximum(vstup_1, 5, &res);
     */


    /* U 5
    cout << numDigits(-0);
    */


    /*
    Date date_1;
    date_1.day = 30;
    date_1.month = 3;
    date_1.year = 2023;
     */


    /* U 6
    const char* format_1 = "D.M.Y";
    print(&date_1,format_1);
    */

    /* U 9
    cout << isInLeapYear(&date_1);
    */

    /* U 10
    cout << isValid(&date_1);
     */

    /* U 7
    cout << create(16, 1, 2022);
     */

    return 0;
}