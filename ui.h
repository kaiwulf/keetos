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
        bool find_xml();
        vector<string> ui_usr_args;
        string ui_get;
};

#endif