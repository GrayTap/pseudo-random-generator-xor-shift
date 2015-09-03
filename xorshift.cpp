#include <iostream>
#include <stdint.h>

using namespace std;

class RandomGenerator
{
protected:
    int x = 123456789;
    int y = 362436069;
    int z = 521288629;
public:
    int w = 88675123;
    int setSeed (int s)
    {
        this->w = s;
    }
    int random (void)
    {
        uint32_t t = ( x ^ (x << 11) ) & 0x7fffffff;

        x = y;
        y = z;
        z = w;
        return w = ( w ^ (w >> 19) ^ ( t ^ ( t >> 8 )) );
    }
};

int main (void)
{
    RandomGenerator ranGen;
    ranGen.setSeed(12345); //or you could use ranGen.w = 12345

    for(int i = 0; i <= 10; i++)
    {
        cout << i << ": " << ranGen.random() % 100 << endl;
    }
    return 0;
}
