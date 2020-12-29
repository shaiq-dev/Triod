#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "include/Triod.h"


void HTLogTokenError(char* err, int type) {
    fprintf(stderr, "Unexpected Token '%s' with type '%d'",err,type);
}
