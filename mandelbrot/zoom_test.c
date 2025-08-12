#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "mandelbrot_draw.h"
#include "zoom.h"

static void test__zoom__and__move(void){
        view viewport;
        viewport_init(&viewport);

        /*Test zoom_in function*/
        zoom_in(&viewport);
        assert(viewport.min_x == -1.8);
        assert(viewport.max_x == 1.8);
        assert(viewport.min_y == -1.8);
        assert(viewport.max_y == 1.8);

        /*Test zoom_out function*/
        zoom_out(&viewport);
        assert(viewport.min_x == -2.0);
        assert(viewport.max_x == 2.0);
        assert(viewport.min_y == -2.0);
        assert(viewport.max_y == 2.0);

        /*Test move_left function*/
        move_left(&viewport);
        assert(viewport.center_x == -0.8);

        /*Test move_right function*/
        move_right(&viewport);
        assert(viewport.center_x == 0.0);

        /*Test move_up function*/
        move_up(&viewport);
        assert(viewport.center_y == -0.8);

        /*Test move_down function*/
        move_down(&viewport);
        assert(viewport.center_y == 0.0);

}

int main(){
    test__zoom__and__move();
}