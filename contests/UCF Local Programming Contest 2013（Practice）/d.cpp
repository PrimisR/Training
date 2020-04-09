#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

struct contact
{
    string first;
    string last;
    bool operator<(const contact &o) const
    {
        return (this->last == o.last) ? this->first < o.first : this->last < o.last;
    }
    bool operator>(const contact &o) const
    {
        return (this->last == o.last) ? this->first > o.first : this->last > o.last;
    }
    bool operator==(const contact &o) const
    {
        return (this->first == o.first) && (this->last == o.last);
    }
};

struct info
{
    set<string> email;
    set<string> phone;
};

int main()
{
    int n;
    int l = 0;
    while (cin >> n && n)
    {
        map<contact, int> m;
        info in[105];
        int id = 0;
        while (n--)
        {
            string first, last;
            string msg;
            cin >> first >> last >> msg;
            contact u;
            u.first = first;
            u.last = last;
            if (m.count(u))
            {
                int uid = m[u];
                if (msg.find('@') == msg.npos)
                {
                    in[uid].phone.insert(msg);
                }
                else
                {
                    in[uid].email.insert(msg);
                }
            }
            else
            {
                id++;
                m[u] = id;
                int uid = id;
                if (msg.find('@') == msg.npos)
                {
                    in[uid].phone.insert(msg);
                }
                else
                {
                    in[uid].email.insert(msg);
                }
            }
        }
        cout << "Contact list #" << ++l << ":" << endl;
        for (map<contact, int>::iterator it = m.begin(); it != m.end(); it++)
        {
            pair<contact, int> item = (*it);
            contact u = item.first;
            int uid = item.second;
            cout << u.first << " " << u.last << endl;
            cout << "Phone:" << endl;
            for (set<string>::iterator it = in [uid].phone.begin(); it != in[uid].phone.end(); it++)
            {
                string s = (*it);
                cout << "(";
                for (int i = 0; i < 3; i++)
                    cout << s[i];
                cout << ")";
                for (int i = 3; i < 6; i++)
                    cout << s[i];
                cout << "-";
                for (int i = 6; i < s.length(); i++)
                    cout << s[i];
                cout << endl;
            }
            cout << "E-Mail:" << endl;
            for (set<string>::iterator it = in [uid].email.begin(); it != in[uid].email.end(); it++)
            {
                string s = (*it);
                cout << s << endl;
            }
            cout << "###" << endl;
        }
        cout << endl;
    }
    return 0;
}