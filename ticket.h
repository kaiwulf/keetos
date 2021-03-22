#ifndef __TICKETS_
#define __TICKETS_

#include <string>
#include <vector>

using namespace std;

class Ticket {
    public:
        void create_ticket(string start_date, string project_name);
        // getters
        string get_proj_name();
        string get_title();
        bool get_checked();
        string get_assigned();
        string get_start_date();
        string get_end_date();
        string get_body();

        void to_dos();
        void display_info();

        //setters
        void set_checked(bool checked);

        Ticket();

    private:
        bool s_checked;
        string s_body;
        string s_assigned;
        string s_end_date;
        string s_start_date;
        string s_title;
        string s_project_name;
        vector<string> s_data;
};

#endif