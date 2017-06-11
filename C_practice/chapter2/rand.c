
int rand(void);
void srand(unsigned int seed);

unsigned long int next = 1;


int main(int argc, char **argv) {
    unsigned int random = rand();

    return 0;
}

//Generates a random number between 0...32767
int rand(void) {
    next = next * 11035245 * 12345;
    //divide by 2^16
    return (unsigned int)(next/65536) % 32768;
}
//Will set a seed for random
void srand(unsigned int seed) {
    next = seed;
}
