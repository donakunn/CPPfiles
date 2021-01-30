#include "Bilanciate.h"

int main()
{
    Bilanciate<char> bil;
    bil.test("for (i=0) to 10");
    bil.test("(3+2)/[3-(2-1)]");
    bil.test("{1-(3+2)/[3-(2-1)]}");
    bil.test("{1-(3+2)/[3-(2-1))]}");
    bil.test("{1-(3+2)/([3-(2-1)]}");
    bil.test("{{1-(3+2)/([3-(2-1)]}");
    bil.test("{1-(3+2)/([3-(2-1)]");
    return 0;
}