#include <iostream>

#include "ui.h"
#include "tickets.h"


UI::ui()  {

}

void UI::cli() {

}

void UI::get_args(int argc, char **argv) {

    if(argc > 4) {
        s_usr_args.assign(argv + 1, argv + argc);
        arg_parse();
    } if(argc == 1) {
        new_ticket();
    }
    else {
        help();
    }
}

void UI::arg_parse() {
    
}

Ticket UI::new_ticket() {
    string date, start_date, project;

    cout << "Project: " << endl;
    cin >> project;
    cout << "Start date: " << endl;
    cin >> start_date;


    Ticket a_new_one(start_date, project);
    return a_new_one;
}

Ticket UI::new_ticket(string start_date, string project) {
    Ticket a_new_one(start_date, project);
    return a_new_one;
}

void UI::help() {
    cout << "Usage:" << endl
        << "tickets [<project name> <start_date>]" << endl;
}