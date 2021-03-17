#include <iostream>
#include <strings>

#include "tickets.h"

tickets::tickets() {

}

void ticket::create_ticket(string date, string start_date, string project) {

    s_checked = false;
    s_date_created = start_date;
    s_project = project;

    cout << "Assignment title: ";
    cin >> s_title;
    cout << "Assignment description";
    cin >> s_body;
}

void ticket::finish_ticket() {

}

void ticket::to_dos() {

}