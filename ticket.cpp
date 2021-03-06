#include <iostream>
#include <string>

#include "ticket.h"
#include "helper.h"


Ticket::Ticket() {

}

void Ticket::create_ticket(string start_date, string project_name) {

    t_checked = false;

    t_start_date = start_date;
    
    t_project_name = project_name;

    cout << "Assignment title: ";
    getline(cin, t_title);

    cout << "Assignment description: ";
    getline(cin, t_body);

    t_end_date = "tbd";
}

// setters
void Ticket::set_checked(bool checked) {
    t_checked = checked;
}

void Ticket::set_body(string body) {
    t_body = body;
}

void Ticket::set_end_date(string date) {
    t_end_date = date;
}

void Ticket::set_start_date(string date) {
    t_start_date = date;
}

void Ticket::set_title(string title) {
    t_title = title;
}

void Ticket::set_proj_name(string proj) {
    t_project_name = proj;
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
    cout << endl << endl << "************* " << t_project_name << " ***************" << endl;
    cout << "Project name: " << t_project_name << endl;
    cout << "Done?: " << t_checked << endl;
    cout << "Start date: " << t_start_date << endl;
    cout << "Assignment title: " << t_title << endl;
    cout << "Assignment description: " << t_body << endl;
    cout << "*****************************" << endl << endl;
}