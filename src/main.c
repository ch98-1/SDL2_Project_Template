/* c standard libraries*/
#include <stdio.h>
#include <math.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

#include "dirent.h"

/* other libraries */
#include "kiss_fft.h"
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"

/* constants and defines */
#include "constants.h"

/* rendering helpers */
#include "text_rendering.h"
#include "rendering_helper.h"


int main(int argc, char* argv[])
{

  /* start of library initialisations */

  setlocale(LC_ALL, ".utf8"); /* //make the locale utf8 */


  if (SDL_Init(SDL_INIT_TIMER|SDL_INIT_AUDIO|SDL_INIT_VIDEO|SDL_INIT_EVENTS)) { /* initialise sdl */
    printf("Unable to initialize SDL: %s\n", SDL_GetError());
    exit(EXIT_FAILURE);
  }

  SDL_Window *window = NULL; /* main window pointer */
  SDL_Renderer *renderer = NULL; /* main renderer pointer */

  window = SDL_CreateWindow( /* create main window */
    "SDL2_Project_Template",                  /* window title */
    SDL_WINDOWPOS_UNDEFINED,           /* initial x position */
    SDL_WINDOWPOS_UNDEFINED,           /* initial y position */
    WINDOW_DEF_W,                               /* width, in pixels */
    WINDOW_DEF_H,                               /* height, in pixels */
    SDL_WINDOW_RESIZABLE|SDL_WINDOW_ALLOW_HIGHDPI
  );


  if (window == NULL) { /* check if window was created */
      printf("Could not create window: %s\n", SDL_GetError()); /* print out the error if it fails */
      exit(EXIT_FAILURE); /* shut down the program as program without a window is not very useful */
  }

  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC|SDL_RENDERER_ACCELERATED); /* sdl renderer speeds 2d drawing up */
  if (renderer == NULL) { /* check if renderer was created */
      printf("Could not create renderer: %s\n", SDL_GetError()); /* print out the error if it fails */
      exit(EXIT_FAILURE); /* shut down the program as program without a way to render to it is not very useful */
  }


   if(TTF_Init()==-1) { /* attempt to initialise ttf font system and check for success */
     printf("TTF_Init: %s\n", TTF_GetError()); /* print out the error if it fails */
     exit(EXIT_FAILURE); /* shut down the program as it might need a text output in some places */
   }

  SDL_SetWindowMinimumSize(window, WINDOW_MIN_W, WINDOW_MIN_H); /* set the minimum size for the window */

  /* end of library initialisations */



  /* start of program initialisations. edit here to your programs needs*/

  char* data_path = SDL_GetBasePath();/* get data path */

  /* get the path of the font and store it in font_dir */
  char font_dir[DIR_LENGTH];

  strcpy(font_dir, data_path);
  strcat(font_dir, "DejaVuSans.ttf");

  /* open fonts for fps text */
  TTF_Font *font;
  font=TTF_OpenFont(font_dir, FPS_FONT_SIZE);

  if(!font) { /* check if font actually got loaded */
    printf("TTF_OpenFont: %s\n", TTF_GetError()); /* print out the error if it fails */
    exit(EXIT_FAILURE); /* shut down the program as it might need a text output in some places */
  }


  /* generate the path for the image */
  char image_dir[DIR_LENGTH];
  strcpy(image_dir, data_path);
  strcat(image_dir, "bouncy_image.png");

  SDL_Texture *bouncy_image = get_image_texture(renderer, image_dir); /* load the image in to a texture */

  double pos_x = 0.2; /* position and direction of bouncy image */
  double pos_y = 0.5;
  int dir_x = 1;
  int dir_y = 1;

  int mouse_click_x = 0;
  int mouse_click_y = 0;
  int mouse_clicked = 0;


  /* colors being used */
  SDL_Color text_color={200,200,200,255};
  SDL_Color background_color={50,50,50,255};


  Uint64 SDL_time_Hz = SDL_GetPerformanceFrequency(); /* how many count per second on SDL_GetPerformanceCounter */

  SDL_Event e; /* variable that gets filled with events */
  int quit = 0; /* if quitting or not */
  Uint64 frames = 0;
  double fps = 0;

  Uint64 fps_display_t = SDL_GetPerformanceCounter(); /* time for fps display */
  Uint64 frame_delay_t = SDL_GetPerformanceCounter(); /* time for calculation of delay between frames */

  double loop_time = 0; /* time taken to complete the loop */
  /* end of program initialisations*/



  /* main event loop.
  This is where your program actually runs. In a graphical software of this type,
  the loop keeps running while continuously asking what events have occured, and
  you handle each event that's relevent to your program. The loop will keep going
  until something sets the quit flag to 1, including possibly the quit event.*/
  while (!quit){
    while (SDL_PollEvent(&e)){ /* keep asking for stored up events until they are all processed */
      /* process the events here */
      if (e.type == SDL_QUIT){ /* if there is a quit event */
          quit = 1; /* set the quit flag to 1 */
      }

      if (e.type == SDL_MOUSEBUTTONDOWN){ /* if there is a mouse button release event */
          mouse_clicked = 1; /* set the mosue clicked flag to 1 */
          mouse_click_x = e.button.x; /* set the current mouse coordinates */
          mouse_click_y = e.button.y; /* set the current mouse coordinates */
      }
      /* end of event processing */
    }


    int display_w, display_h; /* variable to fill with display size */
    SDL_GetRendererOutputSize(renderer, &display_w, &display_h); /* get display size in pixels */

    /* blank screen before drawing anything */
    SDL_SetRenderDrawColor(renderer, background_color.r, background_color.g, background_color.b, background_color.a); /* set the drawing color */
    SDL_RenderClear(renderer); /* blank screen with current render color */





    /* start of main program processing and drawing */
    int texture_w, texture_h;
    SDL_QueryTexture(bouncy_image, NULL, NULL, &texture_w, &texture_h); /* get size of bouncy image */

    double range_x = (display_w - texture_w)/(double)display_w; /* calculate the allowable range of the image for the current display size */
    double range_y = (display_h - texture_h)/(double)display_h;

    double move_x = (BOUNCE_SPEED/(double)(display_w - texture_w)) * loop_time * (double)dir_x; /* calculate the distance to move in each direction relative to display size */
    double move_y = (BOUNCE_SPEED/(double)(display_h - texture_h)) * loop_time * (double)dir_y;

    pos_x += move_x; /* move the calculated distance */
    pos_y += move_y;

    if(pos_x > 1){ /*bouncing code for each border */
      dir_x = -1;
    }
    if(pos_y > 1){
      dir_y = -1;
    }
    if(pos_x < 0){
      dir_x = 1;
    }
    if(pos_y < 0){
      dir_y = 1;
    }

    render_copy_relative_tl(renderer, bouncy_image, pos_x * range_x, pos_y * range_y);

    if(mouse_clicked){ /* handle mouse click */
      if ((mouse_click_x > display_w * pos_x * range_x) &&
          (mouse_click_x < display_w * pos_x * range_x + texture_w) &&
          (mouse_click_y > display_h * pos_y * range_y) &&
          (mouse_click_y < display_h * pos_y * range_y + texture_h)){ /* if clicked within range of image */
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Image Clicked", "You clicked the bouncy image!", window); /* show message box saying you clicked the bouncy image */
      }
      frame_delay_t = SDL_GetPerformanceCounter(); /* reset last time as message pauses everything */
      mouse_clicked = 0; /* reset mouse click */
    }
    /* end of main program processing and drawing */




    double loop_delay_time = ((SDL_GetPerformanceCounter() - frame_delay_t)/(double)SDL_time_Hz);/* calculate the time it took to do the loop minus the previous delay */
    double loop_delay = (1/(double)MAX_FRAMERATE) - loop_delay_time; /* calculate the amount of delay needed to keep the loop within max framerate */
    /* add delay if loop is going too fast */
    if ( loop_delay >= 0 ) {
      SDL_Delay((Uint32)round(loop_delay*1000));
    }
    loop_time = ((SDL_GetPerformanceCounter() - frame_delay_t)/(double)SDL_time_Hz);/* calculate the time it took to do the loop */
    frame_delay_t = SDL_GetPerformanceCounter();

    /* calculate fps every 30 loops */
    frames++;
    if (frames%30 == 0){
      fps = 30/((double)((SDL_GetPerformanceCounter() - fps_display_t)/(double)SDL_time_Hz));
      fps_display_t = SDL_GetPerformanceCounter();
    }

    /* fps display generation code */
    char fps_text[64]; /* text to fill with fps */
    sprintf(fps_text, "%6.1f fps", fps); /* generate the fps text */

    render_text_relative_br(renderer, font, fps_text, text_color, 1, 1); /* render the text on to the bottom right of the screen */


    SDL_RenderPresent(renderer); /* show what was rendered on to the screen */

  } /* end of main event loop */






  /* start of program cleanup. edit here to your programs needs*/
  SDL_DestroyTexture(bouncy_image); /* destroy bouncy image texture */
  TTF_CloseFont(font); /* close the font opened previously */
  font=NULL; /* setting it to NULL just in case */

  /* end of program cleanup */


  /* start of library cleanup */

  SDL_DestroyRenderer(renderer); /* destroy main renderer */
  SDL_DestroyWindow(window); /* destroy main window */


  TTF_Quit(); /* quit ttf */
  SDL_Quit(); /* quit everything */

  /* end of library cleanup */

  exit(EXIT_SUCCESS); /* exit the program */
}
