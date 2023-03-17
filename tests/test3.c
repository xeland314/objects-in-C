#include "WString.h"
#include "Object.h"
#include "acutest.h"
#include <stdlib.h>
#include <stdio.h>
#include <wchar.h>

void test_differ(void) {
    void * a = new(WString, L"Hello, world"), * aa = clone(a);
    void * b = new(WString, L"b");
    TEST_CHECK(a != b);
    TEST_CHECK_(a != b, "%ls != %ls", toWchar(a), toWchar(b));
    TEST_CHECK_(a != aa, "%ls != %ls", toWchar(a), toWchar(aa));
    TEST_CHECK_(!differ(a, aa), "!differ(a, aa)");
    delete(a), delete(aa), delete(b);
}

void test_toWchar(void) {
    void * a = new(WString, L"Hello, world");
    wchar_t * expected = L"Hello, world";
    wchar_t * actual = toWchar(a);
    TEST_CHECK(wcscmp(actual, expected) == 0);
    delete(a);
}

TEST_LIST = {
    { "WString differ", test_differ },
    { "WString toWchar", test_toWchar },
    { NULL, NULL }
};
