#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <direct.h>
#include <conio.h>
using namespace std;

class FileManager
{
public:
    void makeDirectory(const string &directoryName)
    {
        if (_mkdir(directoryName.c_str()) == 0)
        {
            cout << "Directory '" << directoryName << "' created successfully." << endl;
        }
        else
        {
            cout << "Error creating directory '" << directoryName << "'." << endl;
        }
    }

    void listFiles()
    {
        struct _finddata_t file_info;
        intptr_t handle = _findfirst("*.*", &file_info);
        if (handle != -1)
        {
            cout << "List of files in the current directory:" << endl;
            do
            {
                cout << file_info.name << endl;
            } while (_findnext(handle, &file_info) == 0);
            _findclose(handle);
        }
        else
        {
            cout << "Error listing files in the current directory." << endl;
        }
    }

    void clearScreen()
    {
        system("cls");
    }

    void createFile(const string &filename)
    {
        ofstream file(filename);
        if (file.is_open())
        {
            cout << "File '" << filename << "' created successfully." << endl;
            file.close();
        }
        else
        {
            cout << "Error creating file '" << filename << "'." << endl;
        }
    }

    void createFile(const string &filename, const string &content)
    {
        ofstream file(filename);
        if (file.is_open())
        {
            file << content;
            cout << "File '" << filename << "' created successfully with content." << endl;
            file.close();
        }
        else
        {
            cout << "Error creating file '" << filename << "'." << endl;
        }
    }

    void writeFile(const string &filename, const string &data)
    {
        ofstream file(filename, ios::app);
        if (file.is_open())
        {
            file << data << endl;
            cout << "Data written to '" << filename << "' successfully." << endl;
            file.close();
        }
        else
        {
            cout << "Error writing to file '" << filename << "'." << endl;
        }
    }

    void readFile(const string &filename)
    {
        ifstream file(filename);
        if (file.is_open())
        {
            string line;
            cout << "Contents of '" << filename << "':" << endl;
            while (getline(file, line))
            {
                cout << line << endl;
            }
            file.close();
        }
        else
        {
            cout << "Error reading file '" << filename << "'." << endl;
        }
    }

    void deleteFile(const string &filename)
    {
        if (remove(filename.c_str()) == 0)
        {
            cout << "File '" << filename << "' deleted successfully." << endl;
        }
        else
        {
            cout << "Error deleting file '" << filename << "'." << endl;
        }
    }
};

int main()
{
    FileManager manager;
    string word, filename, data;
    cout << "File Handling System" << endl;
    cout << "You are entering an interactive shell. Type '-h' for help or 'continue' to proceed." << endl;
    cin >> word;
    if (word == "-h")
    {
        cout << setw(10) << left << "clear : clear screen" << endl;
        cout << setw(10) << left << "ls : list files" << endl;
        cout << setw(10) << left << "mkdir : make directory" << endl;
        cout << setw(10) << left << "EXIT" << endl;
    }
    cout << "\n\n";

    while (true)
    {
        cout << setw(10) << "1. " << left << "Create File (Empty)" << endl;
        cout << setw(10) << "2. " << left << "Create File with Content" << endl;
        cout << setw(10) << "3. " << left << "Write to File" << endl;
        cout << setw(10) << "4. " << left << "Read File" << endl;
        cout << setw(10) << "5. " << left << "Delete File" << endl;
        cout << setw(10) << "6. " << left << "Exit" << endl;
        cout << "Enter a command: ";
        string command;
        cin >> command;

        if (command == "clear")
        {
            manager.clearScreen();
        }
        else if (command == "ls")
        {
            manager.listFiles();
        }
        else if (command == "mkdir")
        {
            cout << "Enter directory name to create: ";
            string directoryName;
            cin >> directoryName;
            manager.makeDirectory(directoryName);
        }
        else if (command == "EXIT")
        {
            cout << "Exiting program." << endl;
            return 0;
        }
        else
        {
            int mm = stoi(command);
            switch (mm)
            {
            case 1:
                cout << "Enter filename to create: ";
                cin >> filename;
                manager.createFile(filename);
                break;
            case 2:
                cout << "Enter filename to create: ";
                cin >> filename;
                cout << "Enter content for the file: ";
                cin.ignore();
                getline(cin, data);
                manager.createFile(filename, data);
                break;
            case 3:
                cout << "Enter filename to write to: ";
                cin >> filename;
                cin.ignore();
                cout << "Enter data to write: ";
                getline(cin, data);
                manager.writeFile(filename, data);
                break;
            case 4:
                cout << "Enter filename to read: ";
                cin >> filename;
                manager.readFile(filename);
                break;
            case 5:
                cout << "Enter filename to delete: ";
                cin >> filename;
                manager.deleteFile(filename);
                break;
            case 6:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
                break;
            }
        }
    }

    return 0;
}
