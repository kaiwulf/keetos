#include <iostream>
#include <strings>

using namespace std;

class tickets {
    public:
        void create_ticket(bool checked, string date, string start_date, string project);
        void finish_ticket();
        void to_dos();
        tickets();

    private:
        bool s_checked;
        string s_date;
        string s_body;
        string s_assigned;
        string s_end_date;
        string s_date_created;
        string s_title;
        string s_project;
}