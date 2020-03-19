/*
    #############################################
   #  Microcontroller Development - Beginners[1] #
   #                Practice Tasks               #
    #############################################

---------------------------
    TINKERCAD PROJECT LINK: https://www.tinkercad.com/things/cokG3lsmwmC-first-course/
    Ennek a kód részébe, kell beimportálni ezt a forráskódot másolással
---
    A projektben egy Arduino UNO - microcontrollert tudunk programozni
    Továbbá használunk:
        Fejleszõi panelt,
        LED diódákat,
        Vezetékeket,
        Soros monitort, ==> A soros monitor a kódblokk alatt helyezkedik el, elõhívható.
---
    8 darab Zöld LED van elhelyezve, mindegyik külön digitális kimenettel
    1 darab Piros LED van elhelyezve ezis külön irányítható
---------------------------
*/

//  For base Arduino functions
#include <Arduino.h>

/*
---------------------------
    Változók:
---
    (Itt hozzuk most létre az olyan változókat amelyekre szükségünk lesz késõbb is,
    például a pinNumbers amelyeket nem akarunk)
*/
//  --- Alap pin paraméterek ( LEHETNE mind #define is )
uint8_t errorPin = 10;
//  --- Az elsõ zöld LED csatlakozójának száma
uint8_t firstPin = 2;
//  --- Hány darab zöld LED van Lehelyezve
uint8_t pinCount = 8;
//  --- Legnagyobb kijelezhetõ "szám"
int maxNumberInEightBit = pow(2, 8) - 1;
//  ---
//  2-es feladatban szükséges az irány eldöntéséhez.
bool direction = 0;
/*
---------------------------
    Függvények, Metódusok:
---
    (Itt találhatóak az elõzetesen létrehozott keretek)

    Mindegyik feladatnál lesz egy referencia függvény, azután pedig egy ahhoz nagyon hasonló,
    amelynek csak a kerete lesz megadva és lekell implementálni
*/
//  Negáljuk a LED értékét az eddigi állapotához képest.
void negatePin(uint8_t pinNumber, uint16_t miliseconds) {
    //  A digitalRead függvénnyel lekérdezzük a LED jelenlegi értékét
    int switchedOn = digitalRead(pinNumber);
    //  Ha be van kapcsolva akkor kikapcsoljuk, ha nem akkor bekapcsoljuk.
    if (switchedOn == 1)
    {
        digitalWrite(pinNumber, LOW);
    }
    else
    {
        digitalWrite(pinNumber, HIGH);
    }
    delay(miliseconds);
}
//  ELSO FELADAT KERETE
void turnOnAndOffPin(uint8_t pinNumber, uint8_t miliseconds) {
    /*
        Feladat:
            1. Kapcsoljuk be a LEDET
            2. Várjunk a delay( egész ) függvénnyel
            3. Kapcsoljuk ki a LEDET
    */
    //  KÓD ELEJE...

    //  KÓD VÉGE
}

void runningLight(uint8_t firstPin, uint8_t pinCount, uint16_t miliseconds) {
    /*
        Futófényt fogunk készíteni, megkeressük az, aktiv LEDET, ha nincs akkor
        -1 marad az activePin, akkor a 0 ás pin kapja meg az egyet, ez csak
        1 szer fordul elõ a program futása közben amikor elindul.
    */
    //Valamilyen elérhetetlen érték kellett ide
    uint8_t activePin = 255;
    //  for ciklus, a ciklus változót növeljük amig kissebb mint a küszöbszám, jelenleg a LEDEK száma
    uint8_t max = (pinCount + firstPin);
    for (int index = firstPin; index < max; index++) {
        //  Leolvassuk az éppen aktuális pinrõl az értéket
        bool currentPinValue = digitalRead(index);
        //  Ha felvan kapcsolva akkor lementjük a pin számát
        if (currentPinValue) {
            activePin = index;
        }
    }
    //  Miután végig ért néhány ellenõrzést futtatunk:
    //  Ha nemvolt aktiv pin akkor a 0 ásat felkapcsoljuk, és a directiont igazra állítjuk, ez most a jobb irány
    if (activePin == 255)
    {
        digitalWrite(firstPin, HIGH);
        direction = true;
    }
    else // különben, már van felkapcsolt LED
    {
        // && ==> és operátor , közösen kell teljesülnie két feltételnek. ! ==> nem operátor pl: !true = false 
        // ha a 0 ás pin ég és jobbra állítottuk az irányt akkor irányváltás
        if (activePin == firstPin && direction)
        {
            // irányváltás balra
            direction = false;
            //  Kikapcsoljuk az aktiv pint
            digitalWrite(activePin, LOW);
            //  az egyel balra lévõt bekapcsoljuk
            digitalWrite(activePin + 1, HIGH);
        }
        else if (activePin == max - 1 && !direction) // ha az utolso pin akitv és balra van állitva.
        {
            // irányváltás balra
            direction = true;
            //  Kikapcsoljuk az aktiv pint
            digitalWrite(activePin, LOW);
            //  az egyel balra lévõt bekapcsoljuk
            digitalWrite(activePin - 1, HIGH);
        }
        else //Ha nincs irányváltás
        {
            //  eldöntjük, hogy a jobbra vagy balra lévõt kell állítani 
            uint8_t plus = 0;
            if (direction)
            {
                plus = -1;
            }
            else
            {
                plus = 1;
            }
            //  Kikapcsoljuk az aktiv pint
            digitalWrite(activePin, LOW);
            //  az egyel mellette lévõt bekapcsoljuk
            digitalWrite(activePin + plus, HIGH);
        }
    }
    delay(miliseconds);
}

//  MASODIK FELADAT KERETE
void progressBar(uint8_t firstPin, uint8_t pinCount, uint8_t finishedPin, uint16_t miliseconds) {
    /*
        Feladat:
        Folyamatjelzõt készítünk, amelyik, hogyha kész akkor a finish LED kigyullad.
        Nem probléma, ha balról telik jobbra tehát:
        00000001 ==> 00000011 ==> 00000111 ==> 00001111 ... ha megtelik akkor a következõ lépésben finish legyen
        Ha finish volt akkor kezdõdjön újra a folyamat.
        Szükség lesz : ciklusra, elágazásra (if, else) is
        Feladat:
            1. nézzük meg melyik ledek vannak bekapcsolva (valszeg balról jobbra lesznek bekapcsolva, vagy egy sem)
            2. ha megvan legnagyobb pin számú bekapcsolt akkor a nála egyel nagyobbat kapcsoljuk be, ha nem õ a legnagyobb.
            3. ha nincs egy sem bekapcsolva akkor elkell kezdeni balról a kapcsolást
            4. ha végetért akkor mindent kikell kapcsolni ami bevolt kapcsolva
            5. !!!!!!!!! a végére egy delay( miliszekundum ) kell, mert különben megbolondul
        Hasonló a futófényhez, valamennyivel könnyeb, mert nemkell az irányt nézni.

        Hajrá.
    */
    //  KÓD ELEJE...

    //  KÓD VÉGE
}


//  Itt csak bállítjuk a portokat kimenetire/ bemenetire
void setPinDirection(uint8_t firstPin, uint8_t pinCount, bool mode) {
    uint8_t max = firstPin + pinCount;
    for (int index = firstPin; index < max; index++) {
        pinMode(index, mode);
    }
}

void setup()
{
    setPinDirection(firstPin, pinCount, 1);
    setPinDirection(errorPin, 1, 1);
    //  A Soros Monitor használatához szükséges, sebességet állítunk be
    Serial.begin(9600);
}


void loop()
{
    /*
        FELADATOK:
            Mindig csak egy függvény legyen kikommentezve,
            nehogy egyik a másik mûködését megzavarja
    */
    //  1.) A:
    negatePin(errorPin, 500);
    //  1.) B: (Kommentezni 1/A ezt Kikommentezni)
    //turnOnAndOffPin(errorPin, 200);
    //---
    //  2.) A: (Kommentezni az elso 2 függvényt! Ez pedig Kikommentezni)
    //runningLight(firstPin, pinCount, 150);
    //  2.) B: (Komment 2/A ezt kikommentezni)
    //progressBar(firstPin, pinCount, errorPin, 200);
}