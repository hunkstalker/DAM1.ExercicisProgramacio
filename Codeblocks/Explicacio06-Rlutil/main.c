#include <stdio.h>
#include <stdlib.h>
#include <rlutil.h>
#include <windows.h>

int xPos=0,yPos=0,xDir=0,yDir=0;// posiciones
int loops=0,cont=0,i=0,dir=0,p=0;   // contadores
char option='X',car='O';

int musicPlay=1;

// Método para reproducir música.
void music(){
    PlaySound(TEXT("happy_adventure.wav"), NULL, SND_LOOP | SND_ASYNC);
}

// Método de dibujo.
void dibuix(){
    for (i=1; i<xDir; i++){
        if (dir==0) gotoxy(xPos++,yPos);
        else gotoxy(xPos,yPos++);
        msleep(50);
        printf("%c",car);
    }
    for (i=1; i<yDir; i++){
        if (dir==0) gotoxy(xPos,yPos++);
        else gotoxy(xPos++,yPos);
        msleep(50);
        printf("%c",car);
    }
    for (i=1; i<xDir; i++){
        if (dir==0) gotoxy(xPos--,yPos);
        else gotoxy(xPos,yPos--);
        msleep(50);
        printf("%c",car);
    }
    for (i=1; i<yDir; i++){
        if (dir==0) gotoxy(xPos,yPos--);
        else gotoxy(xPos--,yPos);
        msleep(50);
        printf("%c",car);
    }
}

// Cuenta atrás.
void countdown(){
    cont=7;
    printf("\nEl programa es tancara en: ");
    printf("%d",cont);
    for (cont=6; cont>=0; cont--){
        msleep(1000);
        printf("\b%d",cont);
    }
}

int main()
{
    SetConsoleTitle("Exercici Dibuix - Denis Anfruns");

    int color=1;

    // Ejecuta la música 1 vez.
    if (musicPlay==1){
        music();
    }

    // Reinicio del programa.
    void repeat(){
        cont=0;
        musicPlay=0;
        cls();
        gotoxy(0,0);
        main();
    }

    // INICIO DEL PROGRAMA.
    printf("\t\t########################\n \t\t## ");
    setColor(2);
    printf("PROGRAMA DE DIBUIX");
    setColor(WHITE);
    printf(" ##\n \t\t########################\n");
    printf("\t\tv.1.1c\n");
    // Punto de inicio del recuadro en los ejes X-Y.
    setColor(14);
    printf("\n>> Escull el punt d'inici seleccionant coordenades...\n");
    setColor(WHITE);
    printf(">> Eix horitzontal X: ");
    scanf("%d",&xPos);
    while (xPos<0){ // Compr errores
        printf(">> No s'hi valen valors negatius et sortiries de la consola.\n>> Inclos 0 introdueix una coordenada X: ");
        scanf("%d",&xPos);
        cont=cont+2;
    }
    printf(">> Eix vertical Y: ");
    p=scanf("%d",&yPos);
    while (yPos<0){ // Compr errores
        printf(">> No s'hi valen valors negatius et sortiries de la consola.\n>> Inclos 0 introdueix una coordenada Y: ");
        scanf("%d",&yPos);
        cont=cont+2;
    }
    // Tamaño del recuadro X-Y.
    setColor(14);
    printf("\n>> Introdueix les dimensions del dibuix.\n");
    setColor(WHITE);
    printf(">> Eix horitzontal X: ");
    scanf("%d",&xDir);
    while (xDir<=0){ // Compr errores
        printf(">> No s'hi valen valors negatius ni el 0.\n>> Introdueix un altre nombre per l'eix vertical X: ");
        scanf("%d",&xDir);
        cont=cont+2;
    }
    printf(">> Eix vertical Y: ");
    scanf("%d",&yDir);
    fflush(stdin);
    while (yDir<=0){ // Compr errores
        printf(">> No s'hi valen valors negatius ni el 0.\n>> Introdueix un altre nombre per l'eix vertical Y: ");
        scanf("%d",&yDir);
        fflush(stdin);
        cont=cont+2;
    }
    // Dirección del recuadro.
    printf("\n>> Escull la direccio: ["); setColor(12); printf("D"); setColor(WHITE); printf("]reta o ["); setColor(12); printf("E"); setColor(WHITE); printf("]squerra?: ");
    scanf("%c",&option);
    fflush(stdin);
    if (option=='e' || option=='E'){
        p=xDir;
        xDir=yDir;
        yDir=p;
    }
    while (!(option=='D' || option=='d' || option=='E' || option=='e')){ // Compr errores
        printf(">> Error, introdueix els valors correctes\n>> Introdueix la direccio: ["); setColor(12); printf("D"); setColor(WHITE); printf("]reta o ["); setColor(12); printf("E"); setColor(WHITE); printf("]squerra: ");
        scanf("%c",&option);
        fflush(stdin);
        cont=cont+2;
    }

    // Pide al usuario un numero para la cantidad de vueltas que dará el recuadro.
    printf(">> Quantes voltes vols?: ");
    scanf("%d",&loops);
    fflush(stdin);
    while (loops<0){ // Compr errores
        printf(">> No s'hi valen valors negatius.\n>> Introdueix un altre nomero de voltes: ");
        scanf("%d",&loops);
        fflush(stdin);
        cont=cont+2;
    }

    yPos=yPos+(16+cont);
    xPos=xPos+1;
    for (cont=0; cont<loops; cont++){
        setBackgroundColor(color);
        setColor(color);
        color++;
        if (option=='D' || option=='d'){
            dir=0;
            // Llama al método que realiza el dibujo.
            dibuix();
        }
        else {
            // Llama al método que realiza el dibujo.
            // Invierte la dirección de 2 de los 'for' Sup e Inf. en el eje X.
            dir=1;
            dibuix();
        }
    }

    // FINAL DEL PROGRAMA.
    setBackgroundColor(BLACK);
    setColor(WHITE);
    // Recoloca el cursor por debajo del dibujo para no taparlo con el siguiente texto.
    if (dir==0) gotoxy(xPos,yPos+yDir);
    else  gotoxy(xPos,yPos+xDir);
    fflush(stdin);
    printf("\n>> Ara vols ["); setColor(12); printf("R"); setColor(WHITE); printf("]epetir l'exercici o vols ["); setColor(12); printf("S"); setColor(WHITE); printf("]ortir? ");
    scanf("%c",&option);
    fflush(stdin);
    // Compr errores
    while (!(option=='R' || option=='r' || option=='S' || option=='s')){
        fflush(stdin);
        printf(">> Vols ["); setColor(12); printf("R"); setColor(WHITE); printf("]epetir l'exercici o vols ["); setColor(12); printf("S"); setColor(WHITE); printf("]ortir? ");
        scanf("%c",&option);
        fflush(stdin);
    }
    if (option=='R' || option=='r') repeat(); // Llama al reinicio del programa.
    else {
        printf("\nPROGRAMA DE DIBUIX © 2020 Denis Anfruns. EDUCEM, Granollers.");
        printf("\n\nMUSICA 'happy_adventure' DE https://opengameart.org/content/happy-adventure-loop .");

        // Llama a la cuenta regresiva.
        countdown();
        // Llama a la salida del programa.
        exit(0);
    }
    return 0;
}
