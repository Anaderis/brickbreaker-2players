#include <SDL2/SDL.h>
#include <unistd.h>
#include "function.h"

#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080
#define FPS 60
#define nombreColonne 5
#define nombreLigne 5

/*-----------Initialisation de toutes les variables---------------*/

/*---------Jeu BONUS--------------*/

int lancementBonus;

int xjoueuse;
int yjoueuse;
int compteurPas;
int vitessejoueuse;

// lancement du jeu 
int start;
int lancementJeu;

// création du Danger

int xDanger;
int yDanger;
int vitesseDanger;

int xGnome;
int yGnome;
int vitessexGnome;
int vitesseyGnome;

// Elements de fond - jeu bonus

int xFish;
int yFish;
int vitesseFish;
int xTurtle;
int yTurtle;
int vitesseTurtle;


/*----------Jeu Casse-briques-----------*/

//position du carre dessiné dans drawGame()
int x;
int y;

//Variables du cercle joueur PEPE
int xRondPEP;
int yRondPEP;
int r;
int vitessexPEP;
int vitesseyPEP;

//Variables du cercle joueur ROGUE
int xRondROG;
int yRondROG;
int r;
int vitessexROG;
int vitesseyROG;

// Les briques de PEPE
int ecartxPEP;
int ecartyPEP;
int xBrickPEP;
int yBrickPEP;
int longBrickPEP;
int largBrickPEP;
int espaceBrickPEP;
int i;
int j;
int nombreBrickPEP;

int tabXPEP[nombreLigne][nombreColonne];
int tabYPEP[nombreLigne][nombreColonne];

int tabVieBrPEP[nombreLigne][nombreColonne];
int tabCartesXPEP[nombreLigne][nombreColonne];
int tabCartesYPEP[nombreLigne][nombreColonne];
int cartesMaxPEP;
int vieBrickMaxPEP;

// Les briques de ROGUE

int ecartxROG;
int ecartyROG;
int xBrickROG;
int yBrickROG;
int longBrickROG;
int largBrickROG;
int espaceBrickROG;
int i;
int j;
int nombreBrickROG;

int tabXROG[nombreLigne][nombreColonne];
int tabYROG[nombreLigne][nombreColonne];

int tabVieBrROG[nombreLigne][nombreColonne];
int tabCartesXROG[nombreLigne][nombreColonne];
int tabCartesYROG[nombreLigne][nombreColonne];
int cartesMaxROG;
int vieBrickMaxROG;

// Vie du joueur PEPE
int coeurPEP;
int xViePEP;
int yViePEP;
int longViePEP;
int largViePEP;
int k;

// Vie du joueur ROGUE
int coeurROG;
int xVieROG;
int yVieROG;
int longVieROG;
int largVieROG;
int k;

// Gamewin et game over PEPE

int compteurWinPEP;
int compteurOverPEP;

// Gamewin et game over ROGUE

int compteurWinROG;
int compteurOverROG;

/*---------------Fond d'écran du jeu Bonus--------------------------*/ 
void drawWallpaperBonus()
{	
	if ((lancementBonus==2 || lancementBonus==3) && lancementJeu==0)
	{
	sprite(0,0,"Assets/Bonus/beach_bonus.bmp");
	//sprite(0,320,"Assets/Bonus/palm-tree.bmp");
	//sprite(0,WINDOW_HEIGHT-20,"Assets/Bonus/sand.bmp");
	
	}
}

/*---------Poissons et élements dynamiques fond du jeu Bonus-------*/

void drawFish()
{

if (xFish+(r*r)>0 && lancementBonus==3)
{
	sprite(xFish,yFish,"Assets/Bonus/carp.bmp");
	
	xFish+=-vitesseFish;
	
}
else
{
	xFish=WINDOW_WIDTH;
	xFish+=-vitesseFish;
	sprite(xFish,yFish,"Assets/Bonus/carp.bmp");
	
}

if(xTurtle<WINDOW_WIDTH && lancementBonus==3)
	{
	sprite(xTurtle,yTurtle,"Assets/Bonus/turtle.bmp");
	xTurtle=vitesseTurtle;
	}
else if(xTurtle>=WINDOW_WIDTH && lancementBonus==3)
	{
	xTurtle=0;
	sprite(xTurtle,yTurtle,"Assets/Bonus/turtle.bmp");
	xTurtle=vitesseTurtle;
	}

}

/*-----------------lancement de ma gnome - jeu Bonus -------------*/
void gnomeBonus()
{

	if(lancementBonus==3)
	{
		printf("coucou\n");
	if (compteurPas==0)
	{	
	sprite(xjoueuse-r,yjoueuse-r,"Assets/Bonus/gnome1.bmp");
	}
	if (compteurPas==1)
	{
	sprite(xjoueuse-r,yjoueuse-r,"Assets/Bonus/gnome1.bmp");
	}
	if (compteurPas==2)
	{
	sprite(xjoueuse-r,yjoueuse-r,"Assets/Bonus/gnome2.bmp");
	}
	if (compteurPas==3)
	{
	sprite(xjoueuse-r,yjoueuse-r,"Assets/Bonus/gnome3.bmp");
	}
	if (compteurPas==4)
	{
	sprite(xjoueuse-r,yjoueuse-r,"Assets/Bonus/gnome4.bmp");
	}
	if (compteurPas==5)
	{
	sprite(xjoueuse-r,yjoueuse-r,"Assets/Bonus/gnome5.bmp");
	}
	if (compteurPas==6)
	{
	sprite(xjoueuse-r,yjoueuse-r,"Assets/Bonus/gnome6.bmp");
	}
	}
}

/*------------Collision de ma gnome - Jeu Bonus---------------------*/

void RebondsBonus ()
{
    if ((xjoueuse>=WINDOW_WIDTH-r)||(xjoueuse<=r))
    	{
    	xjoueuse=0;
		xjoueuse++; 
    	}
    	
    /*if((yjoueuse>=WINDOW_HEIGHT-r)||(yjoueuse<=r))
    	{
    	vitessejoueuse=-vitessejoueuse; // L'inverse de l'autre, si il est égal à -1, il fera l'inverse et inversement. 
    	}*/
}
/*------------Création du danger - jeu Bonus ------------------------*/

void drawDanger()
{

if (xDanger+(r*2)>0 && lancementBonus==3)
{
	sprite(xDanger,yDanger,"Assets/Bonus/danger.bmp");
	
	xDanger+=-vitesseDanger;
	
}
else
{
	xDanger=WINDOW_WIDTH;
	xDanger+=-vitesseDanger;
	sprite(xDanger,yDanger,"Assets/Bonus/turtle.bmp");
	
}

}

/*---------------- Ecran de démarrage Gnomes-------------------*/
void startGame()
{	

	if(start==0)
	{
        sprite(0,0,"Assets/start-play.bmp");
        actualize();
        }
}


/*---------------Fond d'écran du jeu casse-briques--------------------------*/ 
void drawWallpaper()
{	
		
	sprite(0,0,"Assets/wallpaper-zogzog.bmp");
}


/*---------------Pilote gnome--------------------------*/ 
void drawGnome()
{
if (xGnome<WINDOW_HEIGHT)
{
	sprite(xGnome,yGnome,"Assets/gnome.bmp");
	xGnome+=vitesseyGnome;
	yGnome+=vitesseyGnome;
}
else 
{
	yGnome=0;
	xGnome=0;
	sprite(xGnome,yGnome,"Assets/gnome.bmp");
	xGnome+=vitesseyGnome;
	yGnome+=vitesseyGnome;
}

}

/*----------------Déplacement de la balle PEPE---------------------*/ 
void drawBallPEP()
{   
    if(lancementJeu==1)
        {
        sprite(xRondPEP-r,yRondPEP-r,"Assets/fireball.bmp");
	xRondPEP+=vitessexPEP;
	yRondPEP+=vitesseyPEP;
		}
   
}

/*----------------Déplacement de la balle ROGUE---------------------*/ 
void drawBallROG()
{   
    if(lancementJeu==1)
        {
    sprite(xRondROG-r,yRondROG-r,"Assets/rogue.bmp");
	
	xRondROG+=vitessexROG;
    	yRondROG+=vitesseyROG;
		}

}


/*/*--------------Déplacement du Pad---------------------
void drawPad()
{
	changeColor(255,255,255);
	drawLine(xPad, yPad,xPad+longPad,yPad);
} */

/*-----------------Changement des briques et collisions-----------*/
void tabBrick()
{
    
// PEPE

    for(int i=0;i<nombreColonne;i++) //nombre de colonnes = nombre de briques par ligne
    {
   
	    for(int j=0;j<nombreLigne;j++) //nombre de lignes 
	    	
	    	{
	    	
	    	if (tabVieBrPEP[j][i]==2 && tabCartesXPEP[j][i]==2 && tabCartesYPEP[j][i]==1)
	    	{
	    	sprite(tabXPEP[j][i],tabYPEP[j][i],"Assets/stone-two.bmp");
	    	}
	    	else if (tabVieBrPEP[j][i]==2 && tabCartesXPEP[j][i]==4 && tabCartesYPEP[j][i]==1)
	    	{
	    	sprite(tabXPEP[j][i],tabYPEP[j][i],"Assets/stone-two.bmp");
	    	}
	    	else if(tabVieBrPEP[j][i]==2 && tabCartesXPEP[j][i]==1 && tabCartesYPEP[j][i]==2)
	    	{
	    	sprite(tabXPEP[j][i],tabYPEP[j][i],"Assets/stone-two.bmp");
	    	}
	    	else if(tabVieBrPEP[j][i]==2 && tabCartesXPEP[j][i]==3 && tabCartesYPEP[j][i]==3)
	    	{
	    	sprite(tabXPEP[j][i],tabYPEP[j][i],"Assets/stone-two.bmp");
	    	}
	    	else if(tabVieBrPEP[j][i]==2 && tabCartesXPEP[j][i]==2 && tabCartesYPEP[j][i]==4)
	    	{
	    	sprite(tabXPEP[j][i],tabYPEP[j][i],"Assets/stone-two.bmp");
	    	}
	    	else if (tabVieBrPEP[j][i]==2)
	    	{
	    	sprite(tabXPEP[j][i],tabYPEP[j][i],"Assets/stone-one.bmp");
	    	}
	    	
	    	}
      }
	    	
    
    for(int i=0;i<nombreColonne;i++) //nombre de colonnes = nombre de briques par ligne
    {	
   
	    for(int j=0;j<nombreLigne;j++) //nombre de lignes 
	    	
	    	{
	    	
	    	if(tabVieBrPEP[j][i]==1 && tabCartesXPEP[j][i]==1 && tabCartesYPEP[j][i]==5)
	    	{
	    	sprite(tabXPEP[j][i],tabYPEP[j][i],"Assets/coffre.bmp");
	    	compteurWinPEP++;
	    	tabVieBrPEP[j][i]--;
	    	}
	    	else if(tabVieBrPEP[j][i]==1 && tabCartesXPEP[j][i]==2 && tabCartesYPEP[j][i]==2)
	    	{
	    	sprite(tabXPEP[j][i],tabYPEP[j][i],"Assets/coffre.bmp");
	    	printf("coffre\n");
	    	compteurWinPEP++;
	    	tabVieBrPEP[j][i]--;
	    	}
	    	else if(tabVieBrPEP[j][i]==1 && tabCartesXPEP[j][i]==1 && tabCartesYPEP[j][i]==3)
	    	{
	    	sprite(tabXPEP[j][i],tabYPEP[j][i],"Assets/skull.bmp");
	    	printf("skull\n");
	    	coeurPEP--;
	    	tabVieBrPEP[j][i]--;
	    	} 
	    	else if(tabVieBrPEP[j][i]==1 && tabCartesXPEP[j][i]==3 && tabCartesYPEP[j][i]==3)
	    	{
	    	sprite(tabXPEP[j][i],tabYPEP[j][i],"Assets/skull.bmp");
	    	printf("skull\n");
	    	coeurPEP--;
	    	tabVieBrPEP[j][i]--;
	    	}
	    	else if(tabVieBrPEP[j][i]==1 && tabCartesXPEP[j][i]==3 && tabCartesYPEP[j][i]==4)
	    	{
	    	sprite(tabXPEP[j][i],tabYPEP[j][i],"Assets/coffre.bmp");
	    	printf("coffre\n");
	    	compteurWinPEP++;
	    	tabVieBrPEP[j][i]--;
	    	}
	    	else if(tabVieBrPEP[j][i]==1 && tabCartesXPEP[j][i]==5 && tabCartesYPEP[j][i]==1)
	    	{
	    	sprite(tabXPEP[j][i],tabYPEP[j][i],"Assets/skull.bmp");
	    	printf("skull\n");
	    	coeurPEP--;
	    	tabVieBrPEP[j][i]--;
	    	}
	    	/*else 
	    	{
	    		sprite(tabXPEP[j][i],tabYPEP[j][i],"Assets/chicken.bmp");
	    	}*/
	    	
	    	}
	}
	

// Affichage après avoir touché la brique : PEPE

for(int i=0;i<nombreColonne;i++) //nombre de colonnes = nombre de briques par ligne
    {
   
	    for(int j=0;j<nombreLigne;j++) //nombre de lignes 
	    	
	    	{
	    	
	    	if(tabVieBrPEP[j][i]==0 && tabCartesXPEP[j][i]==1 && tabCartesYPEP[j][i]==5)
	    	{
	    	sprite(tabXPEP[j][i],tabYPEP[j][i],"Assets/coffre.bmp");
	    	}
	    	else if(tabVieBrPEP[j][i]==0 && tabCartesXPEP[j][i]==2 && tabCartesYPEP[j][i]==2)
	    	{
	    	sprite(tabXPEP[j][i],tabYPEP[j][i],"Assets/coffre.bmp");
	    	
	    	}
	    	else if(tabVieBrPEP[j][i]==0 && tabCartesXPEP[j][i]==1 && tabCartesYPEP[j][i]==3)
	    	{
	    	sprite(tabXPEP[j][i],tabYPEP[j][i],"Assets/skull.bmp");
	    	} 
	    	else if(tabVieBrPEP[j][i]==0 && tabCartesXPEP[j][i]==3 && tabCartesYPEP[j][i]==3)
	    	{
	    	sprite(tabXPEP[j][i],tabYPEP[j][i],"Assets/skull.bmp");
	    	}
	    	else if(tabVieBrPEP[j][i]==0 && tabCartesXPEP[j][i]==3 && tabCartesYPEP[j][i]==4)
	    	{
	    	sprite(tabXPEP[j][i],tabYPEP[j][i],"Assets/coffre.bmp");
	    	}
	    	else if(tabVieBrPEP[j][i]==0 && tabCartesXPEP[j][i]==5 && tabCartesYPEP[j][i]==1)
	    	{
	    	sprite(tabXPEP[j][i],tabYPEP[j][i],"Assets/skull.bmp");
	    	}
	    	/*else 
	    	{
	    		sprite(tabXPEP[j][i],tabYPEP[j][i],"Assets/chicken.bmp");
	    	}*/
	    	
	    	}
	}

// Affichage briques : ROGUE

for(int i=0;i<nombreColonne;i++) //nombre de colonnes = nombre de briques par ligne
    {
   
	    for(int j=0;j<nombreLigne;j++) //nombre de lignes 
	    	
	    	{
	    	
	    	if (tabVieBrROG[j][i]==2 && tabCartesXROG[j][i]==2 && tabCartesYROG[j][i]==1)
	    	{
	    	sprite(tabXROG[j][i],tabYROG[j][i],"Assets/stone-two.bmp");
	    	}
	    	else if (tabVieBrROG[j][i]==2 && tabCartesXROG[j][i]==4 && tabCartesYROG[j][i]==1)
	    	{
	    	sprite(tabXROG[j][i],tabYROG[j][i],"Assets/stone-two.bmp");
	    	}
	    	else if(tabVieBrROG[j][i]==2 && tabCartesXROG[j][i]==1 && tabCartesYROG[j][i]==2)
	    	{
	    	sprite(tabXROG[j][i],tabYROG[j][i],"Assets/stone-two.bmp");
	    	}
	    	else if(tabVieBrROG[j][i]==2 && tabCartesXROG[j][i]==3 && tabCartesYROG[j][i]==3)
	    	{
	    	sprite(tabXROG[j][i],tabYROG[j][i],"Assets/stone-two.bmp");
	    	}
	    	else if(tabVieBrROG[j][i]==2 && tabCartesXROG[j][i]==2 && tabCartesYROG[j][i]==4)
	    	{
	    	sprite(tabXROG[j][i],tabYROG[j][i],"Assets/stone-two.bmp");
	    	}
	    	else if(tabVieBrROG[j][i]==2)
	    	{
	    	sprite(tabXROG[j][i],tabYROG[j][i],"Assets/stone-one.bmp");
	    	}
	    	
	    	}
      }

for(int i=0;i<nombreColonne;i++) //nombre de colonnes = nombre de briques par ligne
    {
   
	    for(int j=0;j<nombreLigne;j++) //nombre de lignes 
	    	
	    	{
	    	
	    	if(tabVieBrROG[j][i]==1 && tabCartesXROG[j][i]==1 && tabCartesYROG[j][i]==1)
	    	{
	    	sprite(tabXROG[j][i],tabYROG[j][i],"Assets/coffre.bmp");
	    	compteurWinROG++;
	    	tabVieBrROG[j][i]--;
	    	}
	    	else if(tabVieBrROG[j][i]==1 && tabCartesXROG[j][i]==3 && tabCartesYROG[j][i]==4)
	    	{
	    	sprite(tabXROG[j][i],tabYROG[j][i],"Assets/coffre.bmp");
	    	printf("coffre\n");
	    	compteurWinROG++;
	    	tabVieBrROG[j][i]--;
	    	}
	    	else if(tabVieBrROG[j][i]==1 && tabCartesXROG[j][i]==1 && tabCartesYROG[j][i]==3)
	    	{
	    	sprite(tabXROG[j][i],tabYROG[j][i],"Assets/skull.bmp");
	    	printf("skull\n");
	    	coeurROG--;
	    	tabVieBrROG[j][i]--;
	    	} 
	    	else if(tabVieBrROG[j][i]==1 && tabCartesXROG[j][i]==3 && tabCartesYROG[j][i]==2)
	    	{
	    	sprite(tabXROG[j][i],tabYROG[j][i],"Assets/skull.bmp");
	    	printf("skull\n");
	    	coeurROG--;
	    	tabVieBrROG[j][i]--;
	    	}
	    	else if(tabVieBrROG[j][i]==1 && tabCartesXROG[j][i]==4 && tabCartesYROG[j][i]==2)
	    	{
	    	sprite(tabXROG[j][i],tabYROG[j][i],"Assets/coffre.bmp");
	    	printf("coffre\n");
	    	compteurWinROG++;
	    	tabVieBrROG[j][i]--;
	    	}
	    	else if(tabVieBrROG[j][i]==1 && tabCartesXROG[j][i]==5 && tabCartesYROG[j][i]==5)
	    	{
	    	sprite(tabXROG[j][i],tabYROG[j][i],"Assets/skull.bmp");
	    	printf("skull\n");
	    	coeurROG--;
	    	tabVieBrROG[j][i]--;
	    	}
	    	
	    	}
	    	
	    	
     }
     
// affichage après avoir touché la brique : ROGUE

for(int i=0;i<nombreColonne;i++) //nombre de colonnes = nombre de briques par ligne
    {
   
	    for(int j=0;j<nombreLigne;j++) //nombre de lignes 
	    	
	    	{
	    	
	    if(tabVieBrROG[j][i]==0 && tabCartesXROG[j][i]==1 && tabCartesYROG[j][i]==1)
	    	{
	    	sprite(tabXROG[j][i],tabYROG[j][i],"Assets/potion.bmp");
	    	}
	    	else if(tabVieBrROG[j][i]==0 && tabCartesXROG[j][i]==2 && tabCartesYROG[j][i]==1)
	    	{
	    	sprite(tabXROG[j][i],tabYROG[j][i],"Assets/coffre.bmp");
	    	}
	    	else if(tabVieBrROG[j][i]==0 && tabCartesXROG[j][i]==3 && tabCartesYROG[j][i]==1)
	    	{
	    	sprite(tabXROG[j][i],tabYROG[j][i],"Assets/skull.bmp");
	    	} 
	    	else if(tabVieBrROG[j][i]==0 && tabCartesXROG[j][i]==2 && tabCartesYROG[j][i]==2)
	    	{
	    	sprite(tabXROG[j][i],tabYROG[j][i],"Assets/skull.bmp");
	    	}
	    	else if(tabVieBrROG[j][i]==0 && tabCartesXROG[j][i]==3 && tabCartesYROG[j][i]==2)
	    	{
	    	sprite(tabXROG[j][i],tabYROG[j][i],"Assets/coffre.bmp");
	    	}
	    	else if(tabVieBrROG[j][i]==0 && tabCartesXROG[j][i]==2 && tabCartesYROG[j][i]==3)
	    	{
	    	sprite(tabXROG[j][i],tabYROG[j][i],"Assets/skull.bmp");
	    	}
	    	
	    	}
	    	
	    	
     }
	    	
	    

//Collisions briques de PEPE
	
for(int i=0;i<nombreColonne;i++) 
    {
   
	    for(int j=0;j<nombreLigne;j++) //nombre de lignes 
	    	
	    	{
	    	
	    	if(tabVieBrPEP[j][i]==2 && 
	    	   yRondPEP+r>=tabYPEP[j][i] && yRondPEP<=tabYPEP[j][i]  && 
	    	   xRondPEP-r>=tabXPEP[j][i] && xRondPEP+r<=tabXPEP[j][i]+longBrickPEP
	    	   && vitesseyPEP>0)
	    	
	    	//Haut de la brique. Les deux conditions contradictoires de collision avec le côté de la brique doivent avoir un signe égal en plus de inférieur ou supérieur pour fonctionner. 
	    	//Pas de rayon pour la condition qui correspond à l'espace devant la collision
			  
			  { 
		  	    tabVieBrPEP[j][i]--;
		  	    nombreBrickPEP--;
			    vitesseyPEP=-vitesseyPEP;
			  } 
			  
		else if(tabVieBrPEP[j][i]==2 && 
			yRondPEP>=tabYPEP[j][i]+largBrickPEP && yRondPEP-r<=tabYPEP[j][i]+largBrickPEP && 
			xRondPEP-r>=tabXPEP[j][i] && xRondPEP+r<=tabXPEP[j][i]+longBrickPEP
			&& vitesseyPEP<0) // Bas de la brique
			  { 
		  	    tabVieBrPEP[j][i]--;
		  	    nombreBrickPEP--;
			    vitesseyPEP=-vitesseyPEP;
			  } 
			  
		else if(tabVieBrPEP[j][i]==2 && 
			xRondPEP<=tabXPEP[j][i] && xRondPEP+r>=tabXPEP[j][i] && 
			yRondPEP-r>=tabYPEP[j][i] && yRondPEP+r<=tabYPEP[j][i]+largBrickPEP && 
			vitessexPEP>0) // Côté gauche
			  { 
		  	    tabVieBrPEP[j][i]--;
		  	    nombreBrickPEP--;
			    vitessexPEP=-vitessexPEP;
			  } 
			  
		else if(tabVieBrPEP[j][i]==2 && 
			xRondPEP>=tabXPEP[j][i]+longBrickPEP && xRondPEP-r<=tabXPEP[j][i]+longBrickPEP && 
			yRondPEP>=tabYPEP[j][i] && yRondPEP+r<=tabYPEP[j][i]+largBrickPEP && 
			vitessexPEP<0) // Côté droit
			  { 
		  	    tabVieBrPEP[j][i]--;
		  	    nombreBrickPEP--;
			    vitessexPEP=-vitessexPEP;
			  }
		
        	else if(tabVieBrPEP[j][i]==2 && 
        		yRondPEP<=tabYPEP[j][i] && yRondPEP+r>=tabYPEP[j][i] && 
        		xRondPEP>=tabXPEP[j][i]+longBrickPEP && xRondPEP-r<=tabXPEP[j][i]+longBrickPEP && 
        		vitessexPEP<0 && vitesseyPEP>0) //haut droit
             		  { 
                	    
		  	    tabVieBrPEP[j][i]--;
		  	    nombreBrickPEP--;
			    vitessexPEP=-vitessexPEP;
			  } 
			  
		else if(tabVieBrPEP[j][i]==2 && 
			yRondPEP-r<=tabYPEP[j][i]+largBrickPEP && yRondPEP>=tabYPEP[j][i]+largBrickPEP && 
			xRondPEP>=tabXPEP[j][i]+longBrickPEP && xRondPEP-r<=tabXPEP[j][i]+longBrickPEP && 
			vitessexPEP<0 && vitesseyPEP<0) //bas droit
             		  { 
                	
		  	    tabVieBrPEP[j][i]--;
		  	    nombreBrickPEP--;
			    vitessexPEP=-vitessexPEP;
			  } 
		else if(tabVieBrPEP[j][i]==2 && 
			yRondPEP<=tabYPEP[j][i] && yRondPEP+r>=tabYPEP[j][i] && 
			xRondPEP+r>=tabXPEP[j][i] && xRondPEP<=tabXPEP[j][i] && 
			vitessexPEP>0 && vitesseyPEP>0) //haut gauche
             		  { 
                	
		  	    tabVieBrPEP[j][i]--;
		  	    nombreBrickPEP--;
			    vitessexPEP=-vitessexPEP;
			  } 
		else if(tabVieBrPEP[j][i]==2 && 
			yRondPEP-r<=tabYPEP[j][i]+largBrickPEP && yRondPEP>=tabYPEP[j][i]+largBrickPEP && 
			xRondPEP+r>=tabXPEP[j][i] && xRondPEP<=tabXPEP[j][i] && 
			vitessexPEP>0 && vitesseyPEP<0) //bas gauche
             		  { 
                	
		  	    tabVieBrPEP[j][i]--;
		  	    nombreBrickPEP--;
			    vitessexPEP=-vitessexPEP;
			  } 
			  
			    
		}
	
	 }
//Collisions briques de ROGUE
	
for(int i=0;i<nombreColonne;i++) 
    {
   
	    for(int j=0;j<nombreLigne;j++) //nombre de lignes 
	    	
	    	{
	    	
	    	if(tabVieBrROG[j][i]==2 && 
	    	   yRondROG+r>=tabYROG[j][i] && yRondROG<=tabYROG[j][i]  && 
	    	   xRondROG-r>=tabXROG[j][i] && xRondROG+r<=tabXROG[j][i]+longBrickROG
	    	   && vitesseyROG>0)
	    	
	    	//Haut de la brique. Les deux conditions contradictoires de collision avec le côté de la brique doivent avoir un signe égal en plus de inférieur ou supérieur pour fonctionner. 
	    	//Pas de rayon pour la condition qui correspond à l'espace devant la collision
			  
			  { 
		  	    tabVieBrROG[j][i]--;
		  	    nombreBrickROG--;
			    vitesseyROG=-vitesseyROG;
			  } 
			  
		else if(tabVieBrROG[j][i]==2 && 
			yRondROG>=tabYROG[j][i]+largBrickROG && yRondROG-r<=tabYROG[j][i]+largBrickROG && 
			xRondROG-r>=tabXROG[j][i] && xRondROG+r<=tabXROG[j][i]+longBrickROG
			&& vitesseyROG<0) // Bas de la brique
			  { 
		  	    tabVieBrROG[j][i]--;
		  	    nombreBrickROG--;
			    vitesseyROG=-vitesseyROG;
			  } 
			  
		else if(tabVieBrROG[j][i]==2 && 
			xRondROG<=tabXROG[j][i] && xRondROG+r>=tabXROG[j][i] && 
			yRondROG-r>=tabYROG[j][i] && yRondROG+r<=tabYROG[j][i]+largBrickROG && 
			vitessexROG>0) // Côté gauche
			  { 
		  	    tabVieBrROG[j][i]--;
		  	    nombreBrickROG--;
			    vitessexROG=-vitessexROG;
			  } 
			  
		else if(tabVieBrROG[j][i]==2 && 
			xRondROG>=tabXROG[j][i]+longBrickROG && xRondROG-r<=tabXROG[j][i]+longBrickROG && 
			yRondROG>=tabYROG[j][i] && yRondROG+r<=tabYROG[j][i]+largBrickROG && 
			vitessexROG<0) // Côté droit
			  { 
		  	    tabVieBrROG[j][i]--;
		  	    nombreBrickROG--;
			    vitessexROG=-vitessexROG;
			  }
		
        	else if(tabVieBrROG[j][i]==2 && 
        		yRondROG<=tabYROG[j][i] && yRondROG+r>=tabYROG[j][i] && 
        		xRondROG>=tabXROG[j][i]+longBrickROG && xRondROG-r<=tabXROG[j][i]+longBrickROG && 
        		vitessexROG<0 && vitesseyROG>0) //haut droit
             		  { 
                	    
		  	    tabVieBrROG[j][i]--;
		  	    nombreBrickROG--;
			    vitessexROG=-vitessexROG;
			  } 
			  
		else if(tabVieBrROG[j][i]==2 && 
			yRondROG-r<=tabYROG[j][i]+largBrickROG && yRondROG>=tabYROG[j][i]+largBrickROG && 
			xRondROG>=tabXROG[j][i]+longBrickROG && xRondROG-r<=tabXROG[j][i]+longBrickROG && 
			vitessexROG<0 && vitesseyROG<0) //bas droit
             		  { 
                	
		  	    tabVieBrROG[j][i]--;
		  	    nombreBrickROG--;
			    vitessexROG=-vitessexROG;
			  } 
		else if(tabVieBrROG[j][i]==2 && 
			yRondROG<=tabYROG[j][i] && yRondROG+r>=tabYROG[j][i] && 
			xRondROG+r>=tabXROG[j][i] && xRondROG<=tabXROG[j][i] && 
			vitessexROG>0 && vitesseyROG>0) //haut gauche
             		  { 
                	
		  	    tabVieBrROG[j][i]--;
		  	    nombreBrickROG--;
			    vitessexROG=-vitessexROG;
			  } 
		else if(tabVieBrROG[j][i]==2 && 
			yRondROG-r<=tabYROG[j][i]+largBrickROG && yRondROG>=tabYROG[j][i]+largBrickROG && 
			xRondROG+r>=tabXROG[j][i] && xRondROG<=tabXROG[j][i] && 
			vitessexROG>0 && vitesseyROG<0) //bas gauche
             		  { 
                	
		  	    tabVieBrROG[j][i]--;
		  	    nombreBrickROG--;
			    vitessexROG=-vitessexROG;
			  } 
			  
			    
		}
	
	 }	    	
    }
    
    

/*-------------------------Rebonds sur les côtés du jeu-----------------*/
void Rebonds()
{

    // Rebonds de PEPE

    if ((xRondPEP>=WINDOW_WIDTH/2-r)||(xRondPEP<=r))
    	{
    	vitessexPEP=-vitessexPEP; 
    	}
    	
    if((yRondPEP>=WINDOW_HEIGHT-r)||(yRondPEP<=r))
    	{
    	vitesseyPEP=-vitesseyPEP; // L'inverse de l'autre, si il est égal à -1, il fera l'inverse et inversement. 
    	}

	// Rebonds de ROGUE

    if ((xRondROG>=WINDOW_WIDTH-r)||(xRondROG<=WINDOW_WIDTH/2+r))
    	{
    	vitessexROG=-vitessexROG; 
    	}
    	
    if((yRondROG>=WINDOW_HEIGHT-r)||(yRondROG<=r))
    	{
    	vitesseyROG=-vitesseyROG; // L'inverse de l'autre, si il est égal à -1, il fera l'inverse et inversement. 
    	}	
    	
    	
    	
}

/*--------------------Vies du joueur-----------------------------*/
void vieJoueur()
{
    /*-----------PEPE-------------*/
    for(i=0;i<coeurPEP;i++)
 	
    {
    
    xViePEP=120+i*longViePEP;
    changeColor(222,29,29);
    drawRect(xViePEP,yViePEP,longViePEP,largViePEP);

    }
    
    if(coeurPEP>3)
    {
    coeurPEP--;
    }
    
  
   	
    /*-----------ROGUE-------------*/
    
    for(i=0;i<coeurROG;i++)
 	
    {
    
    xVieROG=WINDOW_WIDTH-i*longVieROG-167;
    changeColor(222,29,29);
    drawRect(xVieROG,yVieROG,longVieROG,largVieROG);

    }
    
    if(coeurROG>3)
    {
    coeurROG--;
    }
    
   
}

/*--------------------Game Over-----------------------------*/
void gameOver()
{
    if(coeurPEP==0) //faire un écran pour pépé
    {
    lancementJeu=0;
    sprite(0,0,"Assets/overPEPE.bmp");
    }
    if(coeurROG==0) //faire un écran pour ROGUE
    {
    lancementJeu=0;
    sprite(0,0,"Assets/overRog.bmp");
    }
}

/*--------------------Game win-----------------------------*/
void gameWin ()
{
	if(compteurWinPEP==3) 
	{
	lancementJeu=0;
	sprite(0,0,"Assets/pepewin.bmp");
	
	}
	if(compteurWinROG==3) 
	{
	lancementJeu=0;
	sprite(0,0,"Assets/roguewin.bmp");
	
	}
}


void init_game(){

    /*---------Jeu Bonus-----------------*/
    
   vitessejoueuse=10;
   xjoueuse=80;
   yjoueuse=WINDOW_HEIGHT-350;
   r=20;

   xDanger=WINDOW_WIDTH;
   yDanger=WINDOW_HEIGHT-350;
   vitesseDanger=5;

   lancementBonus=3;
   
   xFish=WINDOW_WIDTH;
   yFish=200;
   vitesseFish=2;
   xTurtle=0;
   yTurtle=WINDOW_HEIGHT-150;
   vitesseTurtle=1;
    

    /*---------lancementJeu du jeu---------*/

    start=0;
    
    startGame();
    lancementJeu=0;
    xGnome=0;
    yGnome=0;
    vitessexGnome=2;
    vitesseyGnome=2;
    
    
   /*---------compteur Gamewin---------*/
   
   compteurWinPEP=0;
   
   compteurWinROG=0;

   
 
    
   
    /*----------Vie du joueur PEPE----------*/
    
    
   coeurPEP=3; //Nombre de vies
   
   xViePEP; 
   yViePEP=955;
   longViePEP=46;
   largViePEP=20;
   
   /*----------Vie du joueur ROGUE----------*/
    
    
   coeurROG=3; //Nombre de vies
   
   xVieROG; 
   yVieROG=954;
   longVieROG=46;
   largVieROG=20;
   
    
    
    /*------Création de la balle PEPE------*/
    r=20;
    xRondPEP=WINDOW_WIDTH/4;
    yRondPEP=WINDOW_HEIGHT-120;
    
    vitessexPEP=2; 
    vitesseyPEP=-2;
    
    /*------Création de la balle ROGUE------*/
    r=20;
    xRondROG=xRondPEP*3;
    yRondROG=WINDOW_HEIGHT-120;
    
    vitessexROG=2; 
    vitesseyROG=-2;
    
    /*--------Création du Pad--------
    
    longPad=150;
    largPad=10;
    xPad=(WINDOW_WIDTH/2)-(longPad/2); 
    yPad=WINDOW_HEIGHT-100;
    
    compteurPad=10; */
    
    /*----Définition d'une brique et de sa vie----*/

   // PEPE

   longBrickPEP=110;
   largBrickPEP=70;
 
   xBrickPEP; 
   yBrickPEP;
   espaceBrickPEP=10;

   vieBrickMaxPEP=2;
   
   
   //ecartxPEP=(WINDOW_WIDTH-(nombreColonne*longBrickPEP+(nombreColonne-1)*espaceBrickPEP))/2; 
   ecartxPEP=WINDOW_WIDTH/10;
   ecartyPEP=300; 

   // ROGUE

   longBrickROG=110;
   largBrickROG=70;
 
   xBrickROG; 
   yBrickROG;
   espaceBrickROG=10;

   vieBrickMaxROG=2;
   
   
   ecartxROG=ecartxPEP*6; 
   ecartyROG=300; 
  
   
   /*---------Tableau de briques----------------*/
  
  // PEPE

  for(int i=0;i<nombreColonne;i++)
    {
    	for(int j=0;j<nombreLigne;j++)
    	 //nombre de lignes 
    	{
        xBrickPEP=ecartxPEP+i*(longBrickPEP+espaceBrickPEP);
        yBrickPEP=ecartyPEP+j*(largBrickPEP+espaceBrickPEP);
        
        tabXPEP[j][i]=xBrickPEP;
        tabYPEP[j][i]=yBrickPEP;
        
        tabVieBrPEP[j][i]=vieBrickMaxPEP;
        
        tabCartesXPEP[j][i]=i+1;
        tabCartesYPEP[j][i]=j+1;
        
        nombreBrickPEP++; //compteur pour la destruction des briques pour gagner
        
        }
    }

// ROGUE

  for(int i=0;i<nombreColonne;i++)
    {
    	for(int j=0;j<nombreLigne;j++)
    	 //nombre de lignes 
    	{
        xBrickROG=ecartxROG+i*(longBrickROG+espaceBrickROG);
        yBrickROG=ecartyROG+j*(largBrickROG+espaceBrickROG);
        
        tabXROG[j][i]=xBrickROG;
        tabYROG[j][i]=yBrickROG;
        
        tabVieBrROG[j][i]=vieBrickMaxROG;
        
        tabCartesXROG[j][i]=i+1;
        tabCartesYROG[j][i]=j+1;
        
        nombreBrickROG++; //compteur pour la destruction des briques pour gagner
        
        }
    }
   

  
   
  
}



void drawGame(){
 
	clear();

	drawWallpaper();
	
	if(lancementJeu==1)
	{
		vieJoueur();

		Rebonds();

		tabBrick();

		drawBallPEP();

		drawBallROG();

		drawGnome();
	}
		gameWin();

		gameOver(); 
	

	drawWallpaperBonus();
	
	drawFish();

	gnomeBonus();

	drawDanger();

	RebondsBonus();
	    	
	actualize();
	   
	usleep(1000000 / FPS); // 60 images par seconde | 1000000 = 1 seconde 

}




void KeyPressed(SDL_Keycode touche){
    /** @brief event.key.keysym.sym renvoi la touche appuyé
     *
     */
    switch (touche) {
        
        case SDLK_x:
        
        
        if(lancementBonus==2)
        {
        lancementBonus=3;
        }
        else
        {
        lancementJeu=1;
        }
        break;
        
        case SDLK_q:
            //touche q appuyé
            
            printf("Q\n");
       	    vitessexPEP=-2;
            xRondPEP+=vitessexPEP;
           
            break;
        case SDLK_d:

            printf("D\n");
            vitessexPEP=2;
            xRondPEP+=vitessexPEP;
            
            
            // Gnome jeu bonus
            if (lancementBonus==3)
            {
				xjoueuse+=vitessejoueuse;
				compteurPas++;
            if (compteurPas==6)
			{
				compteurPas=0;
			}
            }
            
	    
       
            break;

		case SDLK_z:
            
            printf("z\n");
            vitesseyPEP=-2;
            yRondPEP+=vitesseyPEP;
       
            break;	

		case SDLK_s:
            //touche d appuyé
            printf("z\n");
            vitesseyPEP=2;
            yRondPEP+=vitesseyPEP;
       
            break;
		
		case SDLK_UP:

		printf("up\n");
            	vitesseyROG=-2;
            	yRondROG+=vitesseyROG;
       
            break;
		
		case SDLK_DOWN:

		printf("down\n");
            	vitesseyROG=2;
            	yRondROG+=vitesseyROG;
       
            break;
        
		case SDLK_LEFT:

		printf("left\n");
            	vitessexROG=-2;
            	xRondROG+=vitessexROG;
       
            break;

		case SDLK_RIGHT:

		printf("right\n");
            	vitessexROG=2;
            	xRondROG+=vitessexROG;
       
            break;  
        case SDLK_ESCAPE:
            freeAndTerminate();
            break;

        case SDLK_SPACE:
            start=1;
            break;
        
        case SDLK_RETURN:
        if(compteurWinPEP==3 || compteurWinROG==3)
        	{
        	lancementBonus=2;
           	}
            break;
            

        default:
            break;
    }
}
void joyButtonPressed(){
}

void gameLoop() {
    int programLaunched = 1;
    while (programLaunched == 1) {
       
            
        
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            // boucle pour la gestion d'évenement
            switch (event.type) {
                
                case SDL_QUIT:
                    // quand on clique sur fermer la fénêtre en haut à droite
                    programLaunched = 0;
                    break;
                case SDL_MOUSEBUTTONUP:
                    /* clique de la souris
                     * event.motion.y | event.motion.x pour les positions de la souris
                     */
                    printf("position de la souris x : %d , y : %d\n", event.motion.x, event.motion.y);
                    break;
                case SDL_KEYDOWN:
                    KeyPressed(event.key.keysym.sym);
                    break;
                case SDL_JOYBUTTONDOWN:
                    break;
                default:
                    break;
            }
        }
        
         
        if(start==1)
        {
        printf("%d\n", lancementBonus);
        drawGame();

        }
        
        
        
    }
}

int main(){
	
    /** @description 3 fonctions dans le main qui permettent de créer l'application et la maintenir ouverte :
     *  init(...) : initialiser la SDL/ fenêtre
     *  gameLoop() : boucle de jeu dans laquelle l'application reste ouverte
     *  freeAndTerminate() : quitte le programme proprement
     */
    init(WINDOW_WIDTH, WINDOW_HEIGHT);

    init_game();
    gameLoop();
    printf("Fin du programme\n");
    freeAndTerminate();
}

