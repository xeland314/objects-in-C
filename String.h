#ifndef _STRING_H_
#define _STRING_H_

typedef struct _string {
    char * text;
} String;

void String_init(String * str, const char * text);

int String_size(String * str);
int String_compare(String* str, String * otherStr);

void String_setText(String * str, const char * text);
void String_println(String * str);
void String_print(String * str);
void String_delete(String * str);

void String_capitalize(String * str);
void String_casefold(String * str);

String String_clone(String * str);

#endif // _STRING_H_
