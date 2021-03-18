#ifndef __UI_
#define __UI_
#include <string>
#include <vector>
#include "ticket.h"

using namespace std;

class UI {
    public:
        ui();
        void cli_repl();
        void get_args(int argc, char **argv);
        void arg_parse();
        // Ticket new_ticket();
        void help();

    private:
        vector<string> s_usr_args;
        string s_get;
}

#endif