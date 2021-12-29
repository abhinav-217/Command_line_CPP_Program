#include <iostream>
#include <cstring>
#include <typeinfo>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

string convertToString(char *a, int size)
{
    int i;
    string s = "";
    for (i = 0; i < size; i++)
    {
        s = s + a[i];
    }
    return s;
}
class MyTodo
{

public:
    int priority;
    string description;

    void Addlist(string name, int prio)
    {
        description = name;
        priority = prio;
        cout << "Added task "
             << "'" << description << "'"
             << " with priority "
             << "[" << priority << "]" << endl;
    }
};

MyTodo todolist[1000];
void dellist(int index)
{
    int count = 0;
    string st;
    fstream file("task.txt", ios::in | ios::out | ios::app);
    fstream out("temp.txt", ios::in | ios::out | ios::app);
    while (getline(file, st))
    {
        count++;
        if (count != index)
        {
            out << st << endl;
        }
    }
    file.close();
    out.close();
    remove("task.txt");
    rename("temp.txt", "task.txt");
    cout << "Task marked as done" << endl;
}
void task()
{
    ofstream outfile;
    outfile.open("task.txt");
    outfile << "";
}
void setdel()
{
    if (true)
    {
        int count = 0;
        int countdigit = 0;
        string abhi;
        string tempo;
        ifstream file("temp.txt");
        fstream temp("temp3.txt", ios::in | ios::out | ios::app);
        while (getline(file, abhi))
        {
            count++;
            tempo = abhi.substr(0, 3);
            for (int i = 0; i < tempo.length(); i++)
            {
                if (isdigit(tempo[i]))
                {
                    countdigit++;
                }
            }
            if (countdigit <= 1)
            {
                string s = abhi.substr(0, 1);
                int n = stoi(s);
                ostringstream ss;
                ss << count;
                string sx;
                sx = ss.str();
                if (count != n)
                {
                    string str = abhi.replace(0, 1, sx);
                    temp << str << endl;
                }
                else
                {
                    temp << abhi << endl;
                }
            }
            else if (countdigit > 1)
            {
                string s = abhi.substr(0, 2);
                int n = stoi(s);
                ostringstream ss;
                ss << count;
                string sx;
                sx = ss.str();
                if (count != n)
                {
                    string str = abhi.replace(0, 2, sx);
                    temp << str << endl;
                }
                else
                {
                    temp << abhi << endl;
                }
            }
            countdigit = 0;
        }
    }

    if (true)
    {
        task();
        string copy1;
        ifstream open("temp3.txt");
        ofstream out("temp.txt");

        while (getline(open, copy1))
        {
            out << copy1 << endl;
        }

        open.close();
        out.close();
        remove("temp3.txt");
    }
}
void setdone()
{
    if (true)
    {
        int count = 0;
        string abhi;
        string tempo;
        int countdigit = 0;
        ifstream file("task.txt");
        fstream temp("temp4.txt", ios::in | ios::out | ios::app);
        while (getline(file, abhi))
        {
            count++;
            tempo = abhi.substr(0, 3);
            for (int i = 0; i < tempo.length(); i++)
            {
                if (isdigit(tempo[i]))
                {
                    countdigit++;
                }
            }
            if (countdigit <= 1)
            {
                string s = abhi.substr(0, 1);
                int n = stoi(s);
                ostringstream ss;
                ss << count;
                string sx;
                sx = ss.str();
                if (count != n)
                {
                    string str = abhi.replace(0, 1, sx);
                    temp << str << endl;
                }
                else
                {
                    temp << abhi << endl;
                }
            }
            else if (countdigit > 1)
            {
                string s = abhi.substr(0, 2);
                int n = stoi(s);
                ostringstream ss;
                ss << count;
                string sx;
                sx = ss.str();
                if (count != n)
                {
                    string str = abhi.replace(0, 2, sx);
                    temp << str << endl;
                }
                else
                {
                    temp << abhi << endl;
                }
            }
            countdigit = 0;
        }
    }

    if (true)
    {
        task();
        string copy1;
        ifstream open("temp4.txt");
        ofstream out("task.txt");

        while (getline(open, copy1))
        {
            out << copy1 << endl;
        }

        open.close();
        out.close();
        remove("temp4.txt");
    }
}
int main(int argc, char **argv)
{
    int count = 0;
    int tempcount = 0;
    string st;
    if (argc <= 1)
    {
        cout << "Usage :-" << endl;
        // cout<<endl;
        cout << "$ ./task add 2 hello world     # Add a new item with priority 2 and text "
             << "\\"
             << "\"hello world\\"
             << "\""
             << " to the list" << endl;
        cout << "$ ./task ls                    # Show incomplete priority list items sorted by priority in ascending order" << endl;
        cout << "$ ./task del INDEX             # Delete the incomplete item with the given index" << endl;
        cout << "$ ./task done INDEX            # Mark the incomplete item with the given index as complete" << endl;
        cout << "$ ./task help                  # Show usage" << endl;
        cout << "$ ./task report                # Statistics" << endl;
    }
    else
    {
        int completed = 0;
        if (strcmp(argv[1], "help") == 0)
        {
            cout << "Usage :-" << endl;
            // cout<<endl;
            cout << "$ ./task add 2 hello world     # Add a new item with priority 2 and text "
                 << "\\"
                 << "\"hello world\\"
                 << "\""
                 << " to the list" << endl;
            cout << "$ ./task ls                    # Show incomplete priority list items sorted by priority in ascending order" << endl;
            cout << "$ ./task del NUMBER            # Delete the incomplete item with the given priority number" << endl;
            cout << "$ ./task done NUMBER           # Mark the incomplete item with the given PRIORITY_NUMBER as complete" << endl;
            cout << "$ ./task help                  # Show usage" << endl;
            cout << "$ ./task report                # Statistics" << endl;
        }
        else if (strcmp(argv[1], "add") == 0)
        {
            fstream file("task.txt", ios::in | ios::out | ios::app);
            int priority = stoi(argv[2]);
            int size = strlen(argv[3]);
            string name = convertToString(argv[3], size);
            todolist[1].Addlist(name, priority);
            ifstream in("task.txt");

            while (getline(in, st))
            {
                count++;
            }
            file << count + 1 << ". " << name << " [" << priority << "]" << endl;
        }
        else if (strcmp(argv[1], "report") == 0)
        {
            if (true)
            {
                ifstream in("task.txt");

                while (getline(in, st))
                {
                    count++;
                }
            }
            ifstream in("completed.txt");
            while (getline(in, st))
            {
                completed++;
            }
            cout << "Pending : " << count << endl;
            if (completed > 0)
            {
                if (true)
                {
                    ifstream in("task.txt");

                    while (getline(in, st))
                    {
                        cout << st << endl;
                    }
                }
            }
            cout << endl;
            string temp;
            int size;
            cout << "Completed : " << completed << endl;
            if (true)
            {
                if (completed > 0)
                {
                    ifstream in("completed.txt");

                    while (getline(in, st))
                    {
                        size = st.length();
                        temp = st.substr(0, size - 3);
                        cout << temp << endl;
                    }
                }
            }
        }
        else if (strcmp(argv[1], "ls") == 0)
        {

            ifstream in("task.txt");

            while (getline(in, st))
            {
                cout << st << endl;
            }
        }
        else if (strcmp(argv[1], "del") == 0)
        {
            int index = stoi(argv[2]);
            ifstream file("task.txt");
            fstream out("temp.txt", ios::in | ios::out | ios::app);
            while (getline(file, st))
            {
                count++;
                if (count != index)
                {
                    string temp = st;
                    out << temp << endl;
                }
            }
            setdel();
            file.close();
            out.close();
            remove("task.txt");
            rename("temp.txt", "task.txt");
            cout << "Deleted task #" << index << endl;
        }
        else if (strcmp(argv[1], "done") == 0)
        {
            int index = stoi(argv[2]);
            ifstream in("completed.txt");
            while (getline(in, st))
            {
                completed++;
            }
            ostringstream ss;
            ss << completed + 1;
            string s;
            s = ss.str();

            ifstream tskrd("task.txt");
            fstream file1("completed.txt", ios::in | ios::out | ios::app);
            while (getline(tskrd, st))
            {
                count++;
                if (count == index)
                {
                    string temp = st;
                    int size = st.length();
                    temp.replace(size - size, 1, s);
                    file1 << temp << endl;
                }
            }
            string temp;
            fstream file("task.txt", ios::in | ios::out | ios::app);
            fstream out("temp2.txt", ios::in | ios::out | ios::app);
            if (true)
            {
                while (getline(file, st))
                {
                    tempcount++;
                    if (tempcount != index)
                    {
                        string temp = st;
                        out << temp << endl;
                    }
                }
                task();
                ifstream del("temp2.txt");
                ofstream copy("task.txt");
                if (true)
                {
                    while (getline(del, temp))
                    {
                        copy << temp << endl;
                    }
                }
                setdone();
                file.close();
                out.close();
                del.close();
                copy.close();
                remove("temp2.txt");
                cout << "Marked item as Done." << endl;
            }
        }
        else
        {
            cout << "Invalid command Entered" << endl;
        }
    }
    return 0;
}