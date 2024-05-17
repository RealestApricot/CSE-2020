#ifndef RANDOM_H
#define RANDOM_H

#include <cstdlib>
#include "Vector-1.h"
#include <ctime>
#include "List.h"

using namespace std;

void rand_seed();
int rand_int(int, int);

void random_vector(int, int, int, Vector<int>&, int);
void random_vector_norep(int, int, int, Vector<int>&, int);

void random_list(int, int, int, List<int>&, int); 

#endif
