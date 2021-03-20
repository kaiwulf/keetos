#ifndef __UI_
#define __UI_
#include <string>
#include <vector>

using namespace std;

class UI {
    public:
        UI();
        void cli_repl(int argc, char **argv);
        void get_args(int argc, char **argv);
        void arg_parse();
        void help();

    private:
        vector<string> s_usr_args;
        string s_get;
};

#endif