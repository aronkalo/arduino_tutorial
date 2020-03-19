/*
    #############################################
   #  Microcontroller Development - Beginners[1] #
   #                Practice Tasks               #
    #############################################

---------------------------
    TINKERCAD PROJECT LINK: https://www.tinkercad.com/things/cokG3lsmwmC-first-course/
    Ennek a k�d r�sz�be, kell beimport�lni ezt a forr�sk�dot m�sol�ssal
---
    A projektben egy Arduino UNO - microcontrollert tudunk programozni
    Tov�bb� haszn�lunk:
        Fejlesz�i panelt,
        LED di�d�kat,
        Vezet�keket,
        Soros monitort, ==> A soros monitor a k�dblokk alatt helyezkedik el, el�h�vhat�.
---
    8 darab Z�ld LED van elhelyezve, mindegyik k�l�n digit�lis kimenettel
    1 darab Piros LED van elhelyezve ezis k�l�n ir�ny�that�
---------------------------
*/

//  For base Arduino functions
#include <Arduino.h>

/*
---------------------------
    V�ltoz�k:
---
    (Itt hozzuk most l�tre az olyan v�ltoz�kat amelyekre sz�ks�g�nk lesz k�s�bb is,
    p�ld�ul a pinNumbers amelyeket nem akarunk)
*/
//  --- Alap pin param�terek ( LEHETNE mind #define is )
uint8_t errorPin = 10;
//  --- Az els� z�ld LED csatlakoz�j�nak sz�ma
uint8_t firstPin = 2;
//  --- H�ny darab z�ld LED van Lehelyezve
uint8_t pinCount = 8;
//  --- Legnagyobb kijelezhet� "sz�m"
int maxNumberInEightBit = pow(2, 8) - 1;
//  ---
//  2-es feladatban sz�ks�ges az ir�ny eld�nt�s�hez.
bool direction = 0;
/*
---------------------------
    F�ggv�nyek, Met�dusok:
---
    (Itt tal�lhat�ak az el�zetesen l�trehozott keretek)

    Mindegyik feladatn�l lesz egy referencia f�ggv�ny, azut�n pedig egy ahhoz nagyon hasonl�,
    amelynek csak a kerete lesz megadva �s lekell implement�lni
*/
//  Neg�ljuk a LED �rt�k�t az eddigi �llapot�hoz k�pest.
void negatePin(uint8_t pinNumber, uint16_t miliseconds) {
    //  A digitalRead f�ggv�nnyel lek�rdezz�k a LED jelenlegi �rt�k�t
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
            2. V�rjunk a delay( eg�sz ) f�ggv�nnyel
            3. Kapcsoljuk ki a LEDET
    */
    //  K�D ELEJE...

    //  K�D V�GE
}

void runningLight(uint8_t firstPin, uint8_t pinCount, uint16_t miliseconds) {
    /*
        Fut�f�nyt fogunk k�sz�teni, megkeress�k az, aktiv LEDET, ha nincs akkor
        -1 marad az activePin, akkor a 0 �s pin kapja meg az egyet, ez csak
        1 szer fordul el� a program fut�sa k�zben amikor elindul.
    */
    //Valamilyen el�rhetetlen �rt�k kellett ide
    uint8_t activePin = 255;
    //  for ciklus, a ciklus v�ltoz�t n�velj�k amig kissebb mint a k�sz�bsz�m, jelenleg a LEDEK sz�ma
    uint8_t max = (pinCount + firstPin);
    for (int index = firstPin; index < max; index++) {
        //  Leolvassuk az �ppen aktu�lis pinr�l az �rt�ket
        bool currentPinValue = digitalRead(index);
        //  Ha felvan kapcsolva akkor lementj�k a pin sz�m�t
        if (currentPinValue) {
            activePin = index;
        }
    }
    //  Miut�n v�gig �rt n�h�ny ellen�rz�st futtatunk:
    //  Ha nemvolt aktiv pin akkor a 0 �sat felkapcsoljuk, �s a directiont igazra �ll�tjuk, ez most a jobb ir�ny
    if (activePin == 255)
    {
        digitalWrite(firstPin, HIGH);
        direction = true;
    }
    else // k�l�nben, m�r van felkapcsolt LED
    {
        // && ==> �s oper�tor , k�z�sen kell teljes�lnie k�t felt�telnek. ! ==> nem oper�tor pl: !true = false 
        // ha a 0 �s pin �g �s jobbra �ll�tottuk az ir�nyt akkor ir�nyv�lt�s
        if (activePin == firstPin && direction)
        {
            // ir�nyv�lt�s balra
            direction = false;
            //  Kikapcsoljuk az aktiv pint
            digitalWrite(activePin, LOW);
            //  az egyel balra l�v�t bekapcsoljuk
            digitalWrite(activePin + 1, HIGH);
        }
        else if (activePin == max - 1 && !direction) // ha az utolso pin akitv �s balra van �llitva.
        {
            // ir�nyv�lt�s balra
            direction = true;
            //  Kikapcsoljuk az aktiv pint
            digitalWrite(activePin, LOW);
            //  az egyel balra l�v�t bekapcsoljuk
            digitalWrite(activePin - 1, HIGH);
        }
        else //Ha nincs ir�nyv�lt�s
        {
            //  eld�ntj�k, hogy a jobbra vagy balra l�v�t kell �ll�tani 
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
            //  az egyel mellette l�v�t bekapcsoljuk
            digitalWrite(activePin + plus, HIGH);
        }
    }
    delay(miliseconds);
}

//  MASODIK FELADAT KERETE
void progressBar(uint8_t firstPin, uint8_t pinCount, uint8_t finishedPin, uint16_t miliseconds) {
    /*
        Feladat:
        Folyamatjelz�t k�sz�t�nk, amelyik, hogyha k�sz akkor a finish LED kigyullad.
        Nem probl�ma, ha balr�l telik jobbra teh�t:
        00000001 ==> 00000011 ==> 00000111 ==> 00001111 ... ha megtelik akkor a k�vetkez� l�p�sben finish legyen
        Ha finish volt akkor kezd�dj�n �jra a folyamat.
        Sz�ks�g lesz : ciklusra, el�gaz�sra (if, else) is
        Feladat:
            1. n�zz�k meg melyik ledek vannak bekapcsolva (valszeg balr�l jobbra lesznek bekapcsolva, vagy egy sem)
            2. ha megvan legnagyobb pin sz�m� bekapcsolt akkor a n�la egyel nagyobbat kapcsoljuk be, ha nem � a legnagyobb.
            3. ha nincs egy sem bekapcsolva akkor elkell kezdeni balr�l a kapcsol�st
            4. ha v�get�rt akkor mindent kikell kapcsolni ami bevolt kapcsolva
            5. !!!!!!!!! a v�g�re egy delay( miliszekundum ) kell, mert k�l�nben megbolondul
        Hasonl� a fut�f�nyhez, valamennyivel k�nnyeb, mert nemkell az ir�nyt n�zni.

        Hajr�.
    */
    //  K�D ELEJE...

    //  K�D V�GE
}


//  Itt csak b�ll�tjuk a portokat kimenetire/ bemenetire
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
    //  A Soros Monitor haszn�lat�hoz sz�ks�ges, sebess�get �ll�tunk be
    Serial.begin(9600);
}


void loop()
{
    /*
        FELADATOK:
            Mindig csak egy f�ggv�ny legyen kikommentezve,
            nehogy egyik a m�sik m�k�d�s�t megzavarja
    */
    //  1.) A:
    negatePin(errorPin, 500);
    //  1.) B: (Kommentezni 1/A ezt Kikommentezni)
    //turnOnAndOffPin(errorPin, 200);
    //---
    //  2.) A: (Kommentezni az elso 2 f�ggv�nyt! Ez pedig Kikommentezni)
    //runningLight(firstPin, pinCount, 150);
    //  2.) B: (Komment 2/A ezt kikommentezni)
    //progressBar(firstPin, pinCount, errorPin, 200);
}