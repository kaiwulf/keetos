#include <iostream>
#include <string>

#include "ticket.h"

Ticket::Ticket() {

}

void Ticket::create_ticket(string start_date, string project_name) {

    s_checked = false;
    
    s_data.push_back(s_start_date);
    s_start_date = start_date;
    
    s_project_name = project_name;
    s_data.push_back(s_project_name);

    cout << "Assignment title: ";
    cin >> s_title;
    s_data.push_back(s_title);

    cout << "Assignment description";
    cin >> s_body;	// TO-Do implement alternative input methods, ie text file
}

// setters
void Ticket::set_checked(bool checked) {
    s_checked = checked;
}


// getters
string Ticket::get_proj_name() {
    return s_project_name;
}

string Ticket::get_assigned() {
    return s_assigned;
}

bool Ticket::get_checked() {
    return s_checked;
}

string Ticket::get_title() {
    return s_title;
}

string Ticket::get_start_date() {
    return s_start_date;
}

string Ticket::get_end_date() {
    return s_end_date;
}

string Ticket::get_body() {
    return s_body;
}

void Ticket::display_info() {
    cout << "Project name " << s_project_name << endl;
    cout << "Done? " << s_checked << endl;
    cout << "Start date " << s_start_date << endl;
    cout << "Assignment title " << s_title << endl;
    cout << "Assignment description:" << endl << s_body << endl;
}