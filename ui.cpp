#include <iostream>
#include <vector>

#include "ui.h"


UI::ui()  {

}

void UI::cli_repl(int argc, char **argv) {

}

void UI::get_args(int argc, char **argv) {

    if(argc > 4) {
        s_usr_args.assign(argv + 1, argv + argc);
        arg_parse();
    } else if(argc == 1) {
        Keetos state;
        cout << "This is KEETOS." << endl << "a) 'create' a ticket" << endl
             << "'list' TO-DOs" << endl
             << "'find' a specific ticket" << endl
             << "'project' - retrieve ticket(s) related to a project" << endl
             << "'finish' a ticket" << endl
             << "'delete' a ticket" << endl;
        cin  << s_get;
    
        state.run(s_get);
    
    } else {
        help();
    }
}


void UI::arg_parse() {
    Keetos state;
    state.new_ticket(s_usr_args[0] /* project name */, s_usr_args[1] /* start date */);
}

// Ticket UI::new_ticket(string start_date, string project) {
//     Ticket a_new_one(start_date, project);
//     return a_new_one;
// }

void UI::help() {
    cout << "Usage:" << endl
        << "keetos [<project name> <start_date>]" << endl
        << "or" << endl
        << "keetos [?] (for repl)" << endl;
}