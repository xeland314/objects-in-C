#ifndef _OBJECT_H_
#define _OBJECT_H_

#include <stdarg.h>
#include <stddef.h>

typedef struct {
    size_t size;
    void * (* ctor) (void * self, va_list * app);
    void * (* dtor) (void * self);
    void * (* clone) (const void * self);
    size_t (* sizeOf) (const void * self);
    int (* differ) (const void * self, const void * other);
    char * (* toString) (const void * self);
} Class;

void * new(const void * _class, ...);
void delete(void * self);
void * clone(const void * self);
int differ(const void * self, const void * other);
size_t sizeOf(const void * self);
char * toString(const void * self);

#endif // _OBJECT_H_
