# include <iostream>
# include <fstream>

using namespace std;

class library
{
    protected:
        int choice;

    public:
        int getter1()
        {
            return choice;
        }

        void getChoice1()
        {
            cout << "1. Login as Teacher" << endl;
            cout << "2. Login as Student" << endl;
            cout << "3. Exit" << endl << endl;
            cout << "Enter your choice: ";
            cin >> choice;
        }

        void addBook()
        {
            string bookName;

            cout << endl << "Enter name of book: " << endl;
            cin.ignore();
            getline(cin, bookName);

            fstream dataFile;
            dataFile.open("Books.txt", ios :: app);
            dataFile << endl << bookName;
            dataFile.close();

            cout << endl << '"' << bookName;
        }

        void deleteBook()
        {
            string bookName;
            string line;

            cout << endl << "Enter name of book: " << endl;
            cin.ignore();
            getline(cin, bookName);

            ifstream oldFile;
            oldFile.open("Books.txt");
            ofstream newFile;
            newFile.open("Temporary.txt");

            while (! (oldFile.eof()))
            {
                getline(oldFile, line);

                if (line != bookName)
                {
                    newFile << line << endl;
                }
            }

            oldFile.close();
            newFile.close();

            remove("Books.txt");
            rename("Temporary.txt", "Books.txt");

            cout << endl << '"' << bookName;
        }

        void showList()
        {
            cout << endl;

            ifstream dataFile;
            dataFile.open("Books.txt");

            string line;

            while (! (dataFile.eof()))
            {
                getline(dataFile, line);
                cout << line << endl;
            }

            dataFile.close();
        }
};

class teacher: public library
{
    public:
        int getter2()
        {
            return choice;
        }

        void getChoice2() 
        {
            cout << endl;
            cout << "What would you like to do now?" << endl << endl;
            cout << "1. Add new book" << endl;
            cout << "2. Delete book" << endl;
            cout << "3. Show list of available books" << endl;
            cout << "4. Exit" << endl << endl;
            cout << "Enter your choice: ";
            cin >> choice;
        }
};

class student: public library
{
    public:
        int getter3()
        {
            return choice;
        }

        void getChoice3() 
        {
            cout <<  endl;
            cout << "What would you like to do now?" << endl << endl;
            cout << "1. Borrow book" << endl;
            cout << "2. Return book" << endl;
            cout << "3. Show list of available books" << endl;
            cout << "4. Exit" << endl << endl;
            cout << "Enter your choice: ";
            cin >> choice;
        }
};

int main()
{
    cout << endl << endl << endl << "~~~~~~~~~~ Library Management System ~~~~~~~~~~" << endl << endl << endl << endl;

    library l;
    l.getChoice1();

    while (l.getter1() < 1 or l.getter1() > 3)
    {
        cout << endl << "Invalid choice" << endl << endl;
        l.getChoice1();
    }

    if (l.getter1() == 1)
    {
        cout << endl << endl << "~~~~~~~~~~ Teacher Login Successful ~~~~~~~~~~" << endl << endl;
        teacher t;

        do
        {
            t.getChoice2();

            while (t.getter2() < 1 or t.getter2() > 4)
            {
                cout << endl << "Invalid choice" << endl << endl;
                t.getChoice2();
            }

            switch (t.getter2())
            {
                case 1:
                    t.addBook();
                    cout  << '"' << " has been successfully added to the list." << endl;
                    break;

                case 2:
                    t.deleteBook();
                    cout << '"' << " has been successfully deleted from the list." << endl;
                    break;

                case 3:
                    t.showList();
                    break;
            }
        } while (t.getter2() != 4);
    }

    else if (l.getter1() == 2)
    {
        cout << endl << endl << "~~~~~~~~~~ Student Login Successful ~~~~~~~~~~" << endl << endl;
        student s;
        do
        {
            s.getChoice3();

            while (s.getter3() < 1 or s.getter3() > 4)
            {
                cout << endl << "Invalid choice" << endl << endl;
                s.getChoice3();
            }

            switch (s.getter3())
            {
                case 1:
                    s.deleteBook();
                    cout << '"' << " has been borrowed by you." << endl;
                    break;

                case 2:
                    s.addBook();
                    cout << '"' << " has been returned by you." << endl;
                    break;

                case 3:
                    s.showList();
                    break;
            }
        } while (s.getter3() != 4);
    }

    else if (l.getter1() == 3)
    {
        cout << endl << endl << "Thank you!" << endl;
    }
    
    return 0;
}
