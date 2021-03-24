#ifndef __HELPER_
#define __HELPER_

#include <sstream>
#include <string>

string ss_get_fun();

string ss_get_fun() {
    stringstream sstr;
    while(cin >> sstr.rdbuf());
    return sstr.str();
}

#endif