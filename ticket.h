#ifndef __TICKETS_
#define __TICKETS_

#include <strings>
#include <vector>

using namespace std;

class Ticket {
    public:
        void create_ticket(string start_date, string project_name);
        string get_proj_name();
        bool get_checked();
        void to_dos();
        tickets();

    private:
        bool s_checked
        string s_body;
        string s_assigned;
        string s_end_date;
        string s_date_created;
        string s_title;
        string s_project_name;
        vector<string> s_data;
}

#endif