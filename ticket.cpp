#include <iostream>
#include <string>

#include "ticket.h"
#include "helper.h"


Ticket::Ticket() {

}

void Ticket::create_ticket(string start_date, string project_name) {

    t_checked = false;
    
    // t_data.push_back(t_start_date);
    t_start_date = start_date;
    
    t_project_name = project_name;
    // t_data.push_back(t_project_name);

    cout << "Assignment title: ";
    cin >> t_title;

    cout << "Assignment description:" << endl;
    t_body = ss_get_fun();

    t_end_date = "tbd";
}

// setters
void Ticket::set_checked(bool checked) {
    t_checked = checked;
}


// getters
string Ticket::get_proj_name() {
    return t_project_name;
}

bool Ticket::get_checked() {
    return t_checked;
}

string Ticket::get_title() {
    return t_title;
}

string Ticket::get_start_date() {
    return t_start_date;
}

string Ticket::get_end_date() {
    return t_end_date;
}

string Ticket::get_body() {
    return t_body;
}

void Ticket::display_info() {
    cout << "Project name " << t_project_name << endl;
    cout << "Done? " << t_checked << endl;
    cout << "Start date " << t_start_date << endl;
    cout << "Assignment title " << t_title << endl;
    cout << "Assignment description:" << endl << t_body << endl;
}