#include "../include/Object.h"
#include <stdlib.h>
#include <assert.h>

void * new(const void * _class, ...)
{
    const Class * class = _class;
    void * object = calloc(1, class -> size); 
    assert(object);
    * (const Class **) object = class;
    
    if(class -> ctor)
    {
        va_list args;
        va_start(args, _class);
        object = class -> ctor(object, &args);
        va_end(args);
    }
    return object;
}

void delete(void * self)
{
    const Class ** object = self;
    if(self && * object && (* object) -> dtor)
        self = (* object) -> dtor(self);
    free(self);
}

void * clone(const void * self)
{
    const Class * const * object = self;
    assert(self && *object && (*object) -> clone);
    return (*object) -> clone(self);
}

int differ(const void * self, const void * other)
{
    const Class * const * object = self;
    assert(self && *object && (*object) -> differ);
    return (*object) -> differ(self, other);
}

size_t sizeOf(const void * self)
{
    const Class * const * object = self;
    assert(self && *object);
    return (* object) -> size;
}

char * toString(const void * self)
{
    const Class * const * object = self;
    assert(self && *object);
    return (* object) -> toString(self);
}

