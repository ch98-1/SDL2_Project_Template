#include "text_rendering.h"

/* create texture for text */
SDL_Texture* get_text_texture(SDL_Renderer* renderer, TTF_Font *font, const char *text, SDL_Color color){
  SDL_Surface* surface = TTF_RenderUTF8_Blended( font, text, color ); /* create surface */
  SDL_Texture* texture = SDL_CreateTextureFromSurface( renderer, surface ); /* convert to texture */
  SDL_FreeSurface(surface); /* free surface */
  return texture;
}


/* render with coordinates on display. Returns SDL_Rect of the rendered output including background */

/* render utf8 text with absolute coordinate on top left */
SDL_Rect render_text_absolute_tl(SDL_Renderer* renderer, TTF_Font *font, const char *text, SDL_Color color, int x, int y){
  SDL_Texture* texture = get_text_texture(renderer, font, text, color); /* generate text texture */
  SDL_Rect dstrect = render_copy_absolute_tl(renderer, texture, x, y); /* render generated texture */
  SDL_DestroyTexture(texture); /* clean up */
  return dstrect;
}

/* render utf8 text with absolute coordinate on top right */
SDL_Rect render_text_absolute_tr(SDL_Renderer* renderer, TTF_Font *font, const char *text, SDL_Color color, int x, int y){
  SDL_Texture* texture = get_text_texture(renderer, font, text, color); /* generate text texture */
  SDL_Rect dstrect = render_copy_absolute_tr(renderer, texture, x, y); /* render generated texture */
  SDL_DestroyTexture(texture); /* clean up */
  return dstrect;
}

/* render utf8 text with absolute coordinate on bottom left */
SDL_Rect render_text_absolute_bl(SDL_Renderer* renderer, TTF_Font *font, const char *text, SDL_Color color, int x, int y){
  SDL_Texture* texture = get_text_texture(renderer, font, text, color); /* generate text texture */
  SDL_Rect dstrect = render_copy_absolute_bl(renderer, texture, x, y); /* render generated texture */
  SDL_DestroyTexture(texture); /* clean up */
  return dstrect;
}

/* render utf8 text with absolute coordinate on bottom right */
SDL_Rect render_text_absolute_br(SDL_Renderer* renderer, TTF_Font *font, const char *text, SDL_Color color, int x, int y){
  SDL_Texture* texture = get_text_texture(renderer, font, text, color); /* generate text texture */
  SDL_Rect dstrect = render_copy_absolute_br(renderer, texture, x, y); /* render generated texture */
  SDL_DestroyTexture(texture); /* clean up */
  return dstrect;
}

/* render utf8 text with absolute coordinate on center */
SDL_Rect render_text_absolute_c(SDL_Renderer* renderer, TTF_Font *font, const char *text, SDL_Color color, int x, int y){
  SDL_Texture* texture = get_text_texture(renderer, font, text, color); /* generate text texture */
  SDL_Rect dstrect = render_copy_absolute_c(renderer, texture, x, y); /* render generated texture */
  SDL_DestroyTexture(texture); /* clean up */
  return dstrect;
}


/* render with coordinates in float from 0 to 1 */

/* render utf8 text with relative coordinate on top left */
SDL_Rect render_text_relative_tl(SDL_Renderer* renderer, TTF_Font *font, const char *text, SDL_Color color, float x, float y){
  SDL_Texture* texture = get_text_texture(renderer, font, text, color); /* generate text texture */
  SDL_Rect dstrect = render_copy_relative_tl(renderer, texture, x, y); /* render generated texture */
  SDL_DestroyTexture(texture); /* clean up */
  return dstrect;
}

/* render utf8 text with relative coordinate on top right */
SDL_Rect render_text_relative_tr(SDL_Renderer* renderer, TTF_Font *font, const char *text, SDL_Color color, float x, float y){
  SDL_Texture* texture = get_text_texture(renderer, font, text, color); /* generate text texture */
  SDL_Rect dstrect = render_copy_relative_tr(renderer, texture, x, y); /* render generated texture */
  SDL_DestroyTexture(texture); /* clean up */
  return dstrect;
}

/* render utf8 text with relative coordinate on bottom left */
SDL_Rect render_text_relative_bl(SDL_Renderer* renderer, TTF_Font *font, const char *text, SDL_Color color, float x, float y){
  SDL_Texture* texture = get_text_texture(renderer, font, text, color); /* generate text texture */
  SDL_Rect dstrect = render_copy_relative_bl(renderer, texture, x, y); /* render generated texture */
  SDL_DestroyTexture(texture); /* clean up */
  return dstrect;
}

/* render utf8 text with relative coordinate on bottom right */
SDL_Rect render_text_relative_br(SDL_Renderer* renderer, TTF_Font *font, const char *text, SDL_Color color, float x, float y){
  SDL_Texture* texture = get_text_texture(renderer, font, text, color); /* generate text texture */
  SDL_Rect dstrect = render_copy_relative_br(renderer, texture, x, y); /* render generated texture */
  SDL_DestroyTexture(texture); /* clean up */
  return dstrect;
}

/* render utf8 text with relative coordinate on center */
SDL_Rect render_text_relative_c(SDL_Renderer* renderer, TTF_Font *font, const char *text, SDL_Color color, float x, float y){
  SDL_Texture* texture = get_text_texture(renderer, font, text, color); /* generate text texture */
  SDL_Rect dstrect = render_copy_relative_c(renderer, texture, x, y); /* render generated texture */
  SDL_DestroyTexture(texture); /* clean up */
  return dstrect;
}




/* render with filled background color */
/* render with coordinates on display */

/* render utf8 text with absolute coordinate on top left */
SDL_Rect render_text_absolute_fb_tl(SDL_Renderer* renderer, TTF_Font *font, const char *text, SDL_Color color, int x, int y, Uint8 r, Uint8 g, Uint8 b, Uint8 a){
  SDL_Texture* texture = get_text_texture(renderer, font, text, color); /* generate text texture */
  SDL_Rect dstrect = render_copy_absolute_fb_tl(renderer, texture, x, y, r, g, b, a); /* render generated texture */
  SDL_DestroyTexture(texture); /* clean up */
  return dstrect;
}

/* render utf8 text with absolute coordinate on top right */
SDL_Rect render_text_absolute_fb_tr(SDL_Renderer* renderer, TTF_Font *font, const char *text, SDL_Color color, int x, int y, Uint8 r, Uint8 g, Uint8 b, Uint8 a){
  SDL_Texture* texture = get_text_texture(renderer, font, text, color); /* generate text texture */
  SDL_Rect dstrect = render_copy_absolute_fb_tr(renderer, texture, x, y, r, g, b, a); /* render generated texture */
  SDL_DestroyTexture(texture); /* clean up */
  return dstrect;
}

/* render utf8 text with absolute coordinate on bottom left */
SDL_Rect render_text_absolute_fb_bl(SDL_Renderer* renderer, TTF_Font *font, const char *text, SDL_Color color, int x, int y, Uint8 r, Uint8 g, Uint8 b, Uint8 a){
  SDL_Texture* texture = get_text_texture(renderer, font, text, color); /* generate text texture */
  SDL_Rect dstrect = render_copy_absolute_fb_bl(renderer, texture, x, y, r, g, b, a); /* render generated texture */
  SDL_DestroyTexture(texture); /* clean up */
  return dstrect;
}

/* render utf8 text with absolute coordinate on bottom right */
SDL_Rect render_text_absolute_fb_br(SDL_Renderer* renderer, TTF_Font *font, const char *text, SDL_Color color, int x, int y, Uint8 r, Uint8 g, Uint8 b, Uint8 a){
  SDL_Texture* texture = get_text_texture(renderer, font, text, color); /* generate text texture */
  SDL_Rect dstrect = render_copy_absolute_fb_br(renderer, texture, x, y, r, g, b, a); /* render generated texture */
  SDL_DestroyTexture(texture); /* clean up */
  return dstrect;
}

/* render utf8 text with absolute coordinate on center */
SDL_Rect render_text_absolute_fb_c(SDL_Renderer* renderer, TTF_Font *font, const char *text, SDL_Color color, int x, int y, Uint8 r, Uint8 g, Uint8 b, Uint8 a){
  SDL_Texture* texture = get_text_texture(renderer, font, text, color); /* generate text texture */
  SDL_Rect dstrect = render_copy_absolute_fb_c(renderer, texture, x, y, r, g, b, a); /* render generated texture */
  SDL_DestroyTexture(texture); /* clean up */
  return dstrect;
}


/* render with coordinates in float from 0 to 1 */

/* render utf8 text with relative coordinate on top left */
SDL_Rect render_text_relative_fb_tl(SDL_Renderer* renderer, TTF_Font *font, const char *text, SDL_Color color, float x, float y, Uint8 r, Uint8 g, Uint8 b, Uint8 a){
  SDL_Texture* texture = get_text_texture(renderer, font, text, color); /* generate text texture */
  SDL_Rect dstrect = render_copy_relative_fb_tl(renderer, texture, x, y, r, g, b, a); /* render generated texture */
  SDL_DestroyTexture(texture); /* clean up */
  return dstrect;
}

/* render utf8 text with relative coordinate on top right */
SDL_Rect render_text_relative_fb_tr(SDL_Renderer* renderer, TTF_Font *font, const char *text, SDL_Color color, float x, float y, Uint8 r, Uint8 g, Uint8 b, Uint8 a){
  SDL_Texture* texture = get_text_texture(renderer, font, text, color); /* generate text texture */
  SDL_Rect dstrect = render_copy_relative_fb_tr(renderer, texture, x, y, r, g, b, a); /* render generated texture */
  SDL_DestroyTexture(texture); /* clean up */
  return dstrect;
}

/* render utf8 text with relative coordinate on bottom left */
SDL_Rect render_text_relative_fb_bl(SDL_Renderer* renderer, TTF_Font *font, const char *text, SDL_Color color, float x, float y, Uint8 r, Uint8 g, Uint8 b, Uint8 a){
  SDL_Texture* texture = get_text_texture(renderer, font, text, color); /* generate text texture */
  SDL_Rect dstrect = render_copy_relative_fb_bl(renderer, texture, x, y, r, g, b, a); /* render generated texture */
  SDL_DestroyTexture(texture); /* clean up */
  return dstrect;
}

/* render utf8 text with relative coordinate on bottom right */
SDL_Rect render_text_relative_fb_br(SDL_Renderer* renderer, TTF_Font *font, const char *text, SDL_Color color, float x, float y, Uint8 r, Uint8 g, Uint8 b, Uint8 a){
  SDL_Texture* texture = get_text_texture(renderer, font, text, color); /* generate text texture */
  SDL_Rect dstrect = render_copy_relative_fb_br(renderer, texture, x, y, r, g, b, a); /* render generated texture */
  SDL_DestroyTexture(texture); /* clean up */
  return dstrect;
}

/* render utf8 text with relative coordinate on center */
SDL_Rect render_text_relative_fb_c(SDL_Renderer* renderer, TTF_Font *font, const char *text, SDL_Color color, float x, float y, Uint8 r, Uint8 g, Uint8 b, Uint8 a){
  SDL_Texture* texture = get_text_texture(renderer, font, text, color); /* generate text texture */
  SDL_Rect dstrect = render_copy_relative_fb_c(renderer, texture, x, y, r, g, b, a); /* render generated texture */
  SDL_DestroyTexture(texture); /* clean up */
  return dstrect;
}



/* render with outlined background*/
/* render with coordinates on display */

/* render utf8 text with absolute coordinate on top left */
SDL_Rect render_text_absolute_ob_tl(SDL_Renderer* renderer, TTF_Font *font, const char *text, SDL_Color color, int x, int y, Uint8 r, Uint8 g, Uint8 b, Uint8 a){
  SDL_Texture* texture = get_text_texture(renderer, font, text, color); /* generate text texture */
  SDL_Rect dstrect = render_copy_absolute_ob_tl(renderer, texture, x, y, r, g, b, a); /* render generated texture */
  SDL_DestroyTexture(texture); /* clean up */
  return dstrect;
}

/* render utf8 text with absolute coordinate on top right */
SDL_Rect render_text_absolute_ob_tr(SDL_Renderer* renderer, TTF_Font *font, const char *text, SDL_Color color, int x, int y, Uint8 r, Uint8 g, Uint8 b, Uint8 a){
  SDL_Texture* texture = get_text_texture(renderer, font, text, color); /* generate text texture */
  SDL_Rect dstrect = render_copy_absolute_ob_tr(renderer, texture, x, y, r, g, b, a); /* render generated texture */
  SDL_DestroyTexture(texture); /* clean up */
  return dstrect;
}

/* render utf8 text with absolute coordinate on bottom left */
SDL_Rect render_text_absolute_ob_bl(SDL_Renderer* renderer, TTF_Font *font, const char *text, SDL_Color color, int x, int y, Uint8 r, Uint8 g, Uint8 b, Uint8 a){
  SDL_Texture* texture = get_text_texture(renderer, font, text, color); /* generate text texture */
  SDL_Rect dstrect = render_copy_absolute_ob_bl(renderer, texture, x, y, r, g, b, a); /* render generated texture */
  SDL_DestroyTexture(texture); /* clean up */
  return dstrect;
}

/* render utf8 text with absolute coordinate on bottom right */
SDL_Rect render_text_absolute_ob_br(SDL_Renderer* renderer, TTF_Font *font, const char *text, SDL_Color color, int x, int y, Uint8 r, Uint8 g, Uint8 b, Uint8 a){
  SDL_Texture* texture = get_text_texture(renderer, font, text, color); /* generate text texture */
  SDL_Rect dstrect = render_copy_absolute_ob_br(renderer, texture, x, y, r, g, b, a); /* render generated texture */
  SDL_DestroyTexture(texture); /* clean up */
  return dstrect;
}

/* render utf8 text with absolute coordinate on center */
SDL_Rect render_text_absolute_ob_c(SDL_Renderer* renderer, TTF_Font *font, const char *text, SDL_Color color, int x, int y, Uint8 r, Uint8 g, Uint8 b, Uint8 a){
  SDL_Texture* texture = get_text_texture(renderer, font, text, color); /* generate text texture */
  SDL_Rect dstrect = render_copy_absolute_ob_c(renderer, texture, x, y, r, g, b, a); /* render generated texture */
  SDL_DestroyTexture(texture); /* clean up */
  return dstrect;
}


/* render with coordinates in float from 0 to 1 */

/* render utf8 text with relative coordinate on top left */
SDL_Rect render_text_relative_ob_tl(SDL_Renderer* renderer, TTF_Font *font, const char *text, SDL_Color color, float x, float y, Uint8 r, Uint8 g, Uint8 b, Uint8 a){
  SDL_Texture* texture = get_text_texture(renderer, font, text, color); /* generate text texture */
  SDL_Rect dstrect = render_copy_relative_ob_tl(renderer, texture, x, y, r, g, b, a); /* render generated texture */
  SDL_DestroyTexture(texture); /* clean up */
  return dstrect;
}

/* render utf8 text with relative coordinate on top right */
SDL_Rect render_text_relative_ob_tr(SDL_Renderer* renderer, TTF_Font *font, const char *text, SDL_Color color, float x, float y, Uint8 r, Uint8 g, Uint8 b, Uint8 a){
  SDL_Texture* texture = get_text_texture(renderer, font, text, color); /* generate text texture */
  SDL_Rect dstrect = render_copy_relative_ob_tr(renderer, texture, x, y, r, g, b, a); /* render generated texture */
  SDL_DestroyTexture(texture); /* clean up */
  return dstrect;
}

/* render utf8 text with relative coordinate on bottom left */
SDL_Rect render_text_relative_ob_bl(SDL_Renderer* renderer, TTF_Font *font, const char *text, SDL_Color color, float x, float y, Uint8 r, Uint8 g, Uint8 b, Uint8 a){
  SDL_Texture* texture = get_text_texture(renderer, font, text, color); /* generate text texture */
  SDL_Rect dstrect = render_copy_relative_ob_bl(renderer, texture, x, y, r, g, b, a); /* render generated texture */
  SDL_DestroyTexture(texture); /* clean up */
  return dstrect;
}

/* render utf8 text with relative coordinate on bottom right */
SDL_Rect render_text_relative_ob_br(SDL_Renderer* renderer, TTF_Font *font, const char *text, SDL_Color color, float x, float y, Uint8 r, Uint8 g, Uint8 b, Uint8 a){
  SDL_Texture* texture = get_text_texture(renderer, font, text, color); /* generate text texture */
  SDL_Rect dstrect = render_copy_relative_ob_br(renderer, texture, x, y, r, g, b, a); /* render generated texture */
  SDL_DestroyTexture(texture); /* clean up */
  return dstrect;
}

/* render utf8 text with relative coordinate on center */
SDL_Rect render_text_relative_ob_c(SDL_Renderer* renderer, TTF_Font *font, const char *text, SDL_Color color, float x, float y, Uint8 r, Uint8 g, Uint8 b, Uint8 a){
  SDL_Texture* texture = get_text_texture(renderer, font, text, color); /* generate text texture */
  SDL_Rect dstrect = render_copy_relative_ob_c(renderer, texture, x, y, r, g, b, a); /* render generated texture */
  SDL_DestroyTexture(texture); /* clean up */
  return dstrect;
}
