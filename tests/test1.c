#include "String.h"
#include "Object.h"
#include "acutest.h"
#include <stdlib.h>
#include <stdio.h>

void TEST_CHECK_STRING_EQUAL(void * a, void * b) {
    if(!TEST_CHECK(strcmp(toString(a), toString(b)) == 0)) {
        TEST_MSG("a: %s", toString(a));
        TEST_MSG("b: %s", toString(b));
    }
    delete(a), delete(b);
}

void test_String_differ(void) {
    void * a = new(String, "hEllo, World!!");
    void * aa = clone(a);
    void * b = new(String, "b");
    TEST_CHECK(a != b);
    TEST_CHECK_(a != b, "%s != %s", toString(a), toString(b));
    TEST_CHECK_(a != aa, "%s != %s", toString(a), toString(aa));
    TEST_CHECK_(!differ(a, aa), "!differ(a, aa)");
    delete(a), delete(aa), delete(b);
}

void test_String_capitalize(void) {
    void * a = new(String, "hello, world!!");
    void * b = new(String, "Hello, world!!");
    a = String_capitalize(a);
    TEST_CHECK_STRING_EQUAL(a, b);
}

void test_String_casefold(void) {
    void * a = new(String, "hEllo, WorlD!!");
    void * b = new(String, "hello, world!!");
    a = String_casefold(a);
    TEST_CHECK_STRING_EQUAL(a, b);
}

void test_String_reverse(void) {
    void * a = new(String, "Hello, World!!");
    void * b = new(String, "!!dlroW ,olleH");
    a = String_reverse(a);
    TEST_CHECK_STRING_EQUAL(a, b);
}

void test_String_swapcase(void) {
    void * a = new(String, "hEllo, World!!");
    void * b = new(String, "HeLLO, wORLD!!");
    a = String_swapcase(a);
    TEST_CHECK_STRING_EQUAL(a, b);
}

void test_String_title(void) {
    void * a = new(String, "hello, world!!");
    void * b = new(String, "Hello, World!!");
    a = String_title(a);
    TEST_CHECK_STRING_EQUAL(a, b);
}

void test_String_toupper(void) {
    void * a = new(String, "hEllo, World!!");
    void * b = new(String, "HELLO, WORLD!!");
    a = String_toupper(a);
    TEST_CHECK_STRING_EQUAL(a, b);
}

void test_String_appendString(void) {
    void * a = new(String, "hello");
    void * b = new(String, ", world!!");
    void * c = new(String, "hello, world!!");
    String_appendString(a, b);
    TEST_CHECK_STRING_EQUAL(a, c);
    delete(b);
}

void test_String_appendChar(void) {
    void * a = new(String, "hello");
    void * b = new(String, "helloh");
    String_appendChar(a, "h");
    TEST_CHECK_STRING_EQUAL(a, b);
}

void test_String_center(void) {
    void * a = new(String, "hello");
    void * b = new(String, "     hello     ");
    a = String_center(a, 15);
    TEST_CHECK_STRING_EQUAL(a, b);
}

void test_String_centerWithChar(void) {
    void * a = new(String, "hello");
    void * b = new(String, "-----hello-----");
    a = String_centerWithChar(a, 15, "-");
    TEST_CHECK_STRING_EQUAL(a, b);
}

void test_String_endswith(void) {
    void * a = new(String, "hello, world!!");
    TEST_CHECK(String_endswith(a, "world!!"));
    TEST_CHECK(!String_endswith(a, "World!!"));
    TEST_CHECK(!String_endswith(a, "l!"));
    delete(a);
}

TEST_LIST = {
    { "String_differ", test_String_differ },
    { "String_capitalize", test_String_capitalize },
    { "String_casefold", test_String_casefold },
    { "String_reverse", test_String_reverse },
    { "String_swapcase", test_String_swapcase },
    { "String_title", test_String_title },
    { "String_toupper", test_String_toupper },
    { "String_appendString", test_String_appendString },
    { "String_appendChar", test_String_appendChar },
    { "String_center", test_String_center },
    { "String_centerWithChar", test_String_centerWithChar },
    { "String_endswith", test_String_endswith },
    { NULL, NULL }
};
