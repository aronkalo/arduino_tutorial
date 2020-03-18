/*
	#############################################
   #  Microcontroller Development - Beginners[1] #
	#############################################
*/


//	Egy soros komment készítése

/*
	Így tudsz több soros kommentet készíteni.
    Mindent kommentelj fel, amit éremesnek találsz rá.
*/

/*
	1.) Hogyan működnek ezek a mikrokontrollerek?
    
    Harvard féle achitectúra alapján,
    Ellentétben a Neumann Arch.-al az utasítások és
    a változók külön memóriában foglalnak helyet.
    
    Neumann: 1 háttértár(pl SD kártya), 
    1 futásidejű memória (RAM)
    
    Harvard: 1 háttértár (pl SD kártya, vagy flash memória[ 256 kB])
   	2 futásidejű memória: 1 változóknak( 8kB), 1 utasításoknak
    
    Azért ezt használjuk, mert gyorsabban működik a mi
    rendszereinken.
    
    Előnyök:
    Nem kell olyan kódot írni, ami bármilyen gépen elfut
    Ezáltal, ha működik akkor nem fog lefagyni soha.
    Nagy a rendelkezésre állása
    (Nem romlanak el a szervókormány vezérlők kb soha)
    
    Hátrány:
    Nagyon kevés RAM (8-32 kB) Ebbe kell beleférni
    C++ használata, ami a legösszetettebb nyelv
	
	Link: https://wjsz.bme.hu/kiskor/wiki/Mikrokontroller
	
	Na de akkor nézzünk is pár dolgot
*/

/*
	3.) Mi ez a C++, hogyan működik?
	
	A C++ a C ből fejlődött ki, egyedisége abban rejlik, hogy lehet benne több paradigma szerint is programozni
	pl: deklaratívan, imperatívan, objektum orientáltan, szkriptelés módján is.
	Link: https://people.inf.elte.hu/groberto/elte_am3/eloadas_anyagok/elte_am3_ea01_dia.pdf
	
	A lényeg az, hogy nagyjából egy Objektum Orientált C, ami a vason fut nem kell hozzá virtuális gép mint a Java vagy C#-hoz,
	vagy más magasszintű nyelvekhez.
	
	Szuper, tudjuk hogy mi ez, de hogyan működik?
	
	térjünk ki a forráskód felépítéséhez:
	
	A legfontosabb dolog!!!!!
		Ha egy függvényt, vagy változót szeretnél használni egy függvényben, akkor azt mindenképpen fölé helyezd el a forráskódban,
		különben amikor a fordító fordít akkor hibát fog jelezni, mert nem ismert változót/függvényt használsz.
	
	alapvetően ez fogad minket egy .cpp fájlnál:
	--------------------------------------------
	void setup(){
		
	}
	
	void loop(){
		
	}
	--------------------------------------------
	Kielemzés után:
	--------------------------------------------
	A void egy különleges típus, azt jelenti, hogy üres.
	---
	Tehát a void helyére írhatok más típusokat is is?
	
	Igen,
	azokat metódusokat ahol a visszatérési érték nem void függvényeknek nevezzük.
	---
	Rendben, az első amit leírok az a visszatérési érték, és mi az a setup meg loop?
	
	Az szimplán a neve, amit szeretnénk neki adni, érdemes beszédes neveket adni,
	hogy később emlékezzünk, hogy mire jó az a függvény
	---
	A zárójelbe kerülhet valami, és ha igen akkor mi(k)?
	
	Igen,
	a zárójelbe kerülnek a paraméterek.
	Ezek olyan változók, amelyeknek az értékét a függvény hívásakor már ismerjük és szeretnénk
	használni a függvényen belül.
	---
	Az egész függvényes részhez egy link:
	https://www.webotlet.hu/?p=1846
	--------------------------------------------
*/


/*
	4.) Mi az a #define?

	A define az egy makró ==> Mindenhova ahova ezt 
	írod behelyettesíti az értéket a fordításkor.
    Tehát ha leírom azt, hogy:
    ---------------------------
    #define eletKor = 21;
    int szuletesiEv = 2020 - eletkor;
    ---------------------------
    Azt ugy forditja le, hogy:
	---------------------------
    int szuletesiEv = 2020 - 21;
    ---------------------------
    Ezt nagyon fontos megérteni.
    
    A makró az soha nem kerül bele a memóriába,
    csak addig létezik, amig a forráskódból bináris
    állományt nem képzel.
    
    A #define-okat a kód elején szoktuk használni.
*/

#define MC = "mikrokontroller";

//Kommentben nem működik a #define de a vicc kedvéért csináltam egy makrót, hogy ne kelljen sokat írnom.

//2 függvény van, ami az MC világban mindig így lesz a setup és a loop

void setup()
{
	/*
		Ez a függvény az MC beindításakor fog lefutni 1-szer és utána soha többet.
		Sok mindent lehet csinálni benne, erről majd később amikor ténylegesen az MC -re írunk kódot.
	*/
}

void loop()
{
	/*
		Ez pedig a setup() lefutása után végtelenszer fog futni, amíg ki nem kapcsoljuk az MC -t.
		A loop jelentése ciklus.
	*/
    //delay(10); // Delay a little bit to improve simulation performance

}