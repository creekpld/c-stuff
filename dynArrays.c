#include <stdio.h>
#include <stdlib.h>

void ausgabe(int *, int);

int main()
{
	int anz = 0;
	printf("Wieviel Elemente wollen sie eingeben? ");
	scanf("%d", &anz);
	//int zahlen[anz]; //Anzahl muss konstant sein
	//int zahlen[] entspricht int *zahlen
	//malloc liefert Anfangsadresse zur�ck auf einen Bereich mit der
	//Größe in Bytes. Wenn was schief l�uft, gibt malloc/calloc NULL zur�ck.
	//casten in int *, da malloc() void * zurückgibt
	//int *zahlen = (int *)malloc(anz*sizeof(int));

	//calloc wie malloc, initialisiert aber noch alles mit 0
	int *zahlen = (int *)calloc(anz, sizeof(int));

	if (zahlen == NULL)
	{
		printf("Konnte keinen Speicher reservieren\n");
		getchar();
		return 0;
	}

	ausgabe(zahlen, anz);
	
	for (int i = 0; i < anz;i++)
	{
		printf("Wert %d eingeben: ", i+1);
		scanf("%d",&zahlen[i]);
		fflush(stdin);
	}

	ausgabe(zahlen, anz);

	//Während Laufzeit kommt noch ein Wert dazu
	//wenn ich malloc/calloc nutze mit vergrößerter Anzahl
	//sind die alten Werte weg, deshalb realloc
	zahlen = (int *)realloc(zahlen, (anz + 1)*sizeof(int));

	if (zahlen == NULL)
	{
		printf("Konnte keinen Speicher reservieren\n");
		getchar();
		return 0;
	}

	//realloc initialisiert nicht mit 0
	zahlen[anz] = 10;
	ausgabe(zahlen, anz + 1);

	getchar();
}

void ausgabe(int *zahlen, int anzahl)
{
	printf("\n");
	//for (int i = 0; i < anzahl; i++)
		//printf("%d ", zahlen[i]);
	for (int i = 0; i < anzahl; i++, zahlen++)
		printf("%d ", *zahlen);
	printf("\n");
}