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


/*---------------Fond d'écran du jeu--------------------------*/ 
void drawWallpaper()
{	
		
	sprite(0,0,"Assets/Bonus/cave.bmp");
}


void drawDanger()
{
}
void drawGame(){
 
clear();

drawWallpaper();
	
actualize();

   
usleep(1000000 / FPS); // 60 images par seconde | 1000000 = 1 seconde 

}


void init_game(){
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
