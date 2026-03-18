// APSC 142 Engineering Programming Project Starter Code
// Copyright Sean Kauffman 2024

#include "defines.h"
#include "character.h"
#include <stdio.h>
#include <stdlib.h>

extern char * map;
extern int height;
extern int width;

char sees_player(int player_y, int player_x, int minotaur_y, int minotaur_x) {
    // check to see if the Minotaur has caught the player
    if (player_x==minotaur_x&&player_y==minotaur_y) {
        return CAUGHT_PLAYER;

    }
    // check if neither the x nor y coordinate is the same as the player
    if (player_x!=minotaur_x|| player_y!=minotaur_y) {
        return SEES_NOTHING;
    }
    // if there's a wall in between, they can't see
    if (player_x==minotaur_x) {
        for (int i=0; i<abs(player_x-minotaur_x); i++){
            if (map[minotaur_y*width+i]==
        }
    }
    // if one of them is the same, check if the path in between is clear
    return SEES_NOTHING;
}
int move_character(int * y, int * x, char direction, char character) {
    // check for an invalid direction (not LEFT, RIGHT, UP, or DOWN)
    if (direction != LEFT && direction != RIGHT && direction != UP && direction != DOWN) {
        return MOVED_INVALID_DIRECTION;
    }
    //scanf("s");

    // calculate the new coordinates to use on success (store in local variables)
    int newy = *y;
    int newx = *x;
    if (direction==LEFT) {
        newx-=1;
    }    if (direction==RIGHT) {
        newx+=1;
    }
    if (direction==UP) {
        newy-=1;
    }    if (direction==DOWN) {
        newy+=1;
    }
    // check if the new coordinates point to a wall
            //printf("%c ",map[i*width+j]);
    printf("%d, %d", newy, newx);
    printf("%c", map[newy*width+newx]);
    if (map[newy*width+newx] == WALL) {
        return MOVED_WALL;
        //printf("Moved wall");
    }

    // at this point, the move is known to be valid (OK direction and not a wall)
    // remove character from the old position and replace with EMPTY
    map[*x*width+*y] = EMPTY;

    // set character in the new position in map
    map[(newy)*width+(newx)] = character;
    // update the x/y coordinate pointers
    *x=newx;
    *y=newy;
    return MOVED_OKAY;
}

int charge_minotaur(int *y, int *x, int player_y, int player_x, char charge_direction) {
    // call move_character twice or until a wall is hit
    int newx;
    int newy;
    move_character(y, x, charge_direction, MINOTAUR);
    move_character(y, x, charge_direction, MINOTAUR);
    // when the wall is hit, move the Minotaur into the wall in the direction it is charging
    if (map[*y*width+*x] == WALL) {
        map[*y*width+*x] = MINOTAUR;
    }
    // calculate the new coordinates
    newx = *x;
    newy = *y;
    return MOVED_OKAY;
}
