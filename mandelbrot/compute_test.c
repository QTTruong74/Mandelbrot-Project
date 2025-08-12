#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "compute.h"
#include "mandelbrot_draw.h"

static void test__map(void){
        view viewport;
        viewport_init(&viewport);

        comp current;

        int x = 0;
        current.a = map(x, 0, WIDTH, viewport.min_x, viewport.max_x);
        assert(current.a == -2.0);
        x = 700;
        current.a = map(x, 0, WIDTH, viewport.min_x, viewport.max_x);
        assert(current.a == 1.5);
        
        int y = 0;
        current.b = map(y, 0, HEIGHT, viewport.min_y, viewport.max_y);
        assert(current.b == -2.0);
        y = 400;
        current.b = map(y, 0, HEIGHT, viewport.min_y, viewport.max_y);
        assert(current.b == 0.0);

}

static void test__multiply_comp(void){
        comp current;
        view viewport;
        
        current.a = 0;
        current.b = 0;
        viewport.max_iterations = 200;
        
        int n = multiply_comp(&current, &viewport);
        assert(n == viewport.max_iterations);

        current.a = 1;
        current.b = -1.5;
        n = multiply_comp(&current, &viewport);
        assert(n != viewport.max_iterations);
}

int main(){
    test__map();
    test__multiply_comp();
}