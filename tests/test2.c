#include "Color.h"
#include "Object.h"
#include "acutest.h"
#include <stdlib.h>
#include <stdio.h>

void test_color(void) {
    void * blue = new(Color, NORMAL, BLUE, WHITE);
    void * blue2 = clone(blue);
    void * red = new(Color, NORMAL, RED, YELLOW);

    TEST_CHECK_(differ(blue, red), "differ(blue, red)");
    TEST_CHECK_(!differ(blue, blue2), "!differ(blue, blue2)");
    TEST_CHECK_(blue != blue2, "blue != blue2");

    char expected_output_blue[100] = {0};
    snprintf(expected_output_blue, sizeof(expected_output_blue), "\033[0;34;47mTexto en azul\033[0m");
    char expected_output_red[100] = {0};
    snprintf(expected_output_red, sizeof(expected_output_red), "\033[0;31;43mTexto en rojo\033[0m");

    char output[100] = {0};
    snprintf(output, sizeof(output), "%sTexto en azul%s", toString(blue), NORMAL_STDOUT);
    TEST_CHECK_(strcmp(output, expected_output_blue) == 0, "Blue output differs: %s != %s", output, expected_output_blue);

    snprintf(output, sizeof(output), "%sTexto en rojo%s", toString(red), NORMAL_STDOUT);
    TEST_CHECK_(strcmp(output, expected_output_red) == 0, "Red output differs: %s != %s", output, expected_output_red);

    // clean up
    delete(blue), delete(blue2), delete(red);
}

TEST_LIST = {
    { "color", test_color },
    { NULL, NULL }
};
