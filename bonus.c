#include <SDL2/SDL.h>
#include <unistd.h>
#include "function.h"

#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080
#define FPS 60
#define nombreColonne 3
#define nombreLigne 5

int xDanger;
int yDanger;

int xGnome;
int yGnome;
int compteurPas;
int vitesseGnomex;



/*---------------Fond d'écran du jeu--------------------------*/ 
void drawWallpaper()
{	
		
	sprite(0,0,"Assets/Bonus/cave.bmp");
}

void Gnome()
{


if (compteurPas==0)
{
sprite(xGnome,yGnome,"Assets/Bonus/gnome1.bmp");
}
if (compteurPas==1)
{
sprite(xGnome,yGnome,"Assets/Bonus/gnome1.bmp");
}
if (compteurPas==2)
{
sprite(xGnome,yGnome,"Assets/Bonus/gnome2.bmp");
}
if (compteurPas==3)
{
sprite(xGnome,yGnome,"Assets/Bonus/gnome3.bmp");
}
if (compteurPas==4)
{
sprite(xGnome,yGnome,"Assets/Bonus/gnome4.bmp");
}
if (compteurPas==5)
{
sprite(xGnome,yGnome,"Assets/Bonus/gnome5.bmp");
}
if (compteurPas==6)
{
sprite(xGnome,yGnome,"Assets/Bonus/gnome6.bmp");
}


	
}

void drawDanger()
{
}
void drawGame(){
 
clear();
drawWallpaper();
Gnome();


actualize();

   
usleep(1000000 / FPS); // 60 images par seconde | 1000000 = 1 seconde 

}


void init_game(){

//Initialisation de Gnome

vitesseGnomex=10;
xGnome;

}



void KeyPressed(SDL_Keycode touche){
    /** @brief event.key.keysym.sym renvoi la touche appuyé
     *
     */
    switch (touche) {
        
        case SDLK_x:
        
       
        break;
        
        case SDLK_q:
            
            
            
            break;
        case SDLK_d:
        
        
        compteurPas++;
        if (compteurPas==6)
        {
        compteurPas=0;
        }
        xGnome+=vitesseGnomex;
            
            
       
            break;

		case SDLK_z:
            
            
            break;	

		case SDLK_s:
            
            break;
		
		case SDLK_UP:

            break;
		
		case SDLK_DOWN:

       
            break;
        
		case SDLK_LEFT:

       
            break;

		case SDLK_RIGHT:


       
            break;  
            
        case SDLK_ESCAPE:
            freeAndTerminate();
            break;

        case SDLK_SPACE:
           
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
        
         
       
        drawGame();

    
        
        
        
    }
}

int main(){

bonus();
	
}
