#include "util.h"

void printLine( std::ostream &out, std::string s, int num, bool newline) {
    for ( int i = 0; i < num; ++ i ) {
        out << s;
    }
    if ( newline ) out << std::endl;
}
