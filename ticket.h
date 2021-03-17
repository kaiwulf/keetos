#ifndef __TICKETS_
#define __TICKETS_

#include <strings>
#include <vector>

using namespace std;

class Ticket {
    public:
        void create_ticket(string start_date, string project_name);
        void finish_ticket();
        void to_dos();
        tickets();

    private:
        bool s_checked
        string s_body;
        string s_assigned;
        string s_end_date;
        string s_date_created;
        string s_title;
        string s_project;
        vector<string> s_data;
}

#endif