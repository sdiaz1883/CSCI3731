//
//  makefile.c
//  pA_4.4
//
//  Created by Sammuel Diaz on 2/5/22.
//

#include "makefile.h"
//
//  Makefile.c
//  pA_4.4
//
//  Created by Sammuel Diaz on 2/2/22.
//

#include "Makefile.h"
pA_4.4: pA_4.4.o
    gcc pA_4.4.o

pA_4.4.o: pA_4.4.c
    gcc -c pA_4.4.c
