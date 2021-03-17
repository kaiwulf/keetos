#include <iostream>
#include <strings>

#include "ticket.h"

tickets::tickets() {

}

void ticket::create_ticket(string start_date, string project_name) {

    s_checked = false;
    
    s_data.pusback(s_date_created);
    s_date_created = start_date;
    
    s_project = project_name;
    s_data.pusback(s_project);

    cout << "Assignment title: ";
    cin >> s_title;
    s_data.pusback(s_title);

    cout << "Assignment description";
    cin >> s_body;	// TO-Do implement alternative input methods, ie text file
    s_data.pusback(s_body);
}

void ticket::finish_ticket(string project_name) {

}


