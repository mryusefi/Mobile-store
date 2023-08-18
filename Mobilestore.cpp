#include <iostream>
#include <string>

enum OS
{
    IoS, Android, WindowsPhone
};
enum Ram
{
    r2GB, r4GB, r6GB, r8GB, r12GB, r16GB, r32GB, r64GB
};
enum Storage
{
    s16GB, s32GB, s64GB, s128GB, s256GB, s512GB, s1TB, s2TB
};
enum Color
{
    white, black, blue
};

using namespace std;

struct Mobile
{
    string Name;
    string Company;
    OS os;
    Ram ram;
    Storage storage;
    Color color;
    int price;
    int AvailablePhoneNumber;
    int PhoneSoldNumber;
};

void SortBySold(Mobile*&, int&);
void AddPhone(Mobile*&, int&);
void GetInformationPhone(Mobile*&, int&);
void Show(Mobile*&, int&);
void DeletePhone(Mobile*&, int&);
void SortByPrice(Mobile*&, int&);
void Serch(Mobile*&, int&);
void chengeOs(Mobile*&, int&);
void chengeRam(Mobile*&, int&);
void chengeStorage(Mobile*&, int&);
void chengePrice(Mobile*&, int&);
void chengeaColor(Mobile*&, int&);
void ChengeMobileDetalies(Mobile*&, int&);
void SellPhone(Mobile*&, int&);
void PrintPhone(Mobile*&, int&);

void AddPhone(Mobile*& mobile, int& size)
{
    Mobile* temp = new Mobile[size + 1];
    for (int i = 0; i < size; i++)
    {
        temp[i] = mobile[i];
    }
    if (size != 0)
    {
        delete[] mobile;
    }
    mobile = new Mobile[size + 1];
    for (int i = 0; i < size + 1; i++)
    {
        mobile[i] = temp[i];
    }
    delete[] temp;
    size++;
}

void GetInformationPhone(Mobile*& mobile, int& size)
{
    cout << "--------------------------------------------\n";
    string name, company;
    bool check = true;
    int x;
    int Dublicate = 0;
    while (true)
    {
        Dublicate = 0;
        cout << "Enter Name : ";
        cin >> name;
        cout << "Enter Company : ";
        cin >> company;
        for (int i = 0; i < size; i++)
        {
            if (name == mobile[i].Name && company == mobile[i].Company)
            {
                Dublicate++;
            }
        }
        if (Dublicate == 0)
        {
            check = false;
            break;
        }
    }
    if (check == false)
    {
        AddPhone(mobile, size);
        mobile[size - 1].Name = name;
        mobile[size - 1].Company = company;

        cout << "Enter OS(0:IoS, 1:Android, 2:WindowsPhone) : ";
        int Os;
        cin >> Os;
        switch (Os)
        {
        case 0:
            mobile[size - 1].os = OS::IoS;
            break;
        case 1:
            mobile[size - 1].os = OS::Android;
            break;
        case 2:
            mobile[size - 1].os = OS::WindowsPhone;
            break;
        }
        cout << "Enter Ram(0:2GB, 1:4GB, 2:6GB, 3:8GB, 4:12GB, 5:16GB, 6:32GB, 7:64GB) : ";
        int RAm;
        cin >> RAm;
        switch (RAm)
        {
        case 0:
            mobile[size - 1].ram = Ram::r2GB;
            break;
        case 1:
            mobile[size - 1].ram = Ram::r4GB;
            break;
        case 2:
            mobile[size - 1].ram = Ram::r6GB;
            break;
        case 3:
            mobile[size - 1].ram = Ram::r8GB;
            break;
        case 4:
            mobile[size - 1].ram = Ram::r12GB;
            break;
        case 5:
            mobile[size - 1].ram = Ram::r16GB;
            break;
        case 6:
            mobile[size - 1].ram = Ram::r32GB;
            break;
        case 7:
            mobile[size - 1].ram = Ram::r64GB;
            break;
        }

        cout << "Enter Storage(0:16GB, 1:32GB, 2:64GB, 3:128GB, 4:256GB, 5:512GB , 6:1TB, 7:2TB) : ";
        int STorage;
        cin >> STorage;
        switch (STorage)
        {
        case 0:
            mobile[size - 1].storage = Storage::s16GB;
            break;
        case 1:
            mobile[size - 1].storage = Storage::s32GB;
            break;
        case 2:
            mobile[size - 1].storage = Storage::s64GB;
            break;
        case 3:
            mobile[size - 1].storage = Storage::s128GB;
            break;
        case 4:
            mobile[size - 1].storage = Storage::s256GB;
            break;
        case 5:
            mobile[size - 1].storage = Storage::s512GB;
            break;
        case 6:
            mobile[size - 1].storage = Storage::s1TB;
            break;
        case 7:
            mobile[size - 1].storage = Storage::s2TB;
            break;
        }
        cout << "Enter Color(0:with,1:black,2:blue) : ";
        int COlor;
        cin >> COlor;
        switch (COlor)
        {
        case 0:
            mobile[size - 1].color = Color::white;
            break;
        case 1:
            mobile[size - 1].color = Color::black;
            break;
        case 2:
            mobile[size - 1].color = Color::blue;
            break;
        }

        cout << "Enter Price : ";
        int Price;
        cin >> Price;
        mobile[size - 1].price = Price;

        cout << "Enter Available : ";
        int available;
        cin >> available;
        mobile[size - 1].AvailablePhoneNumber = available;

        cout << "Enter Sold Number : ";
        int sold;
        cin >> sold;
        mobile[size - 1].PhoneSoldNumber = sold;
        cout << "--------------------------------------------\n";
    }
}

void Show(Mobile*& mobile, int& a)
{
    cout << "--------------------------------------------\n";
    cout << "Name : " << mobile[a].Name << endl;
    cout << "Company : " << mobile[a].Company << endl;

    cout << "system : ";

    if (mobile[a].os == OS::Android)
    {
        cout << "android" << endl;
    }
    else if (mobile[a].os == OS::IoS)
    {
        cout << "iOS" << endl;
    }
    else if (mobile[a].os == OS::WindowsPhone)
    {
        cout << "windows phone" << endl;
    }

    cout << "Ram : ";

    if (mobile[a].ram == Ram::r2GB)
    {
        cout << "2GB" << endl;
    }
    else if (mobile[a].ram == Ram::r4GB)
    {
        cout << "4GB" << endl;
    }
    else if (mobile[a].ram == Ram::r6GB)
    {
        cout << "6GB" << endl;
    }
    else if (mobile[a].ram == Ram::r8GB)
    {
        cout << "8GB" << endl;
    }
    else if (mobile[a].ram == Ram::r12GB)
    {
        cout << "12GB" << endl;
    }
    else if (mobile[a].ram == Ram::r16GB)
    {
        cout << "16GB" << endl;
    }
    else if (mobile[a].ram == Ram::r32GB)
    {
        cout << "32GB" << endl;
    }
    else if (mobile[a].ram == Ram::r64GB)
    {
        cout << "64GB" << endl;
    }

    cout << "Storage : ";

    if (mobile[a].storage == Storage::s16GB)
    {
        cout << "16GB" << endl;
    }
    else if (mobile[a].storage == Storage::s32GB)
    {
        cout << "32GB" << endl;
    }
    else if (mobile[a].storage == Storage::s64GB)
    {
        cout << "64GB" << endl;
    }
    else if (mobile[a].storage == Storage::s128GB)
    {
        cout << "128GB" << endl;
    }
    else if (mobile[a].storage == Storage::s256GB)
    {
        cout << "256GB" << endl;
    }
    else if (mobile[a].storage == Storage::s512GB)
    {
        cout << "512GB" << endl;
    }
    else if (mobile[a].storage == Storage::s1TB)
    {
        cout << "1TB" << endl;
    }
    else if (mobile[a].storage == Storage::s2TB)
    {
        cout << "2TB" << endl;
    }

    cout << "Color : ";

    if (mobile[a].color == Color::black)
    {
        cout << "Black" << endl;
    }
    else if (mobile[a].color == Color::blue)
    {
        cout << "Blue" << endl;
    }
    else if (mobile[a].color == Color::white)
    {
        cout << "White" << endl;
    }

    cout << "Price : " << mobile[a].price << endl;
    cout << "Available : " << mobile[a].AvailablePhoneNumber << endl;

    cout << "Sold : " << mobile[a].PhoneSoldNumber << endl;
    cout << "--------------------------------------------\n";
}

void DeletePhone(Mobile*& mobile, int& size)
{
    cout << "--------------------------------------------\n";
    string Name, Company;
    cout << "Enter name :";
    cin >> Name;
    cout << "Enter Company :";
    cin >> Company;
    bool Dele = true;
    for (int i = 0; i < size; i++)
    {
        if (mobile[i].Name == Name && mobile[i].Company == Company)
        {
            for (int j = i; j < size - 1; j++)
            {
                mobile[j] = mobile[j + 1];
            }
            Mobile* p = new Mobile[size - 1];
            for (int j = 0; j < size - 1; j++)
            {
                p[j] = mobile[j];
            }
            delete[] mobile;

            mobile = new Mobile[size - 1];
            for (int i = 0; i < size - 1; i++)
            {
                mobile[i] = p[i];
            }

            delete[] p;
            size--;
            Dele = false;
            cout << "Delete Complete :)" << endl;
        }
    }

    if (Dele)
    {
        cout << "not found\n";
    }
    cout << "--------------------------------------------\n";
}

void SortByPrice(Mobile*& mobile, int& size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (mobile[j].price > mobile[j + 1].price)
            {
                swap(mobile[j], mobile[j + 1]);
            }
        }
    }
    cout << "--------------------------------------------\n";
    int k = 0;
    while (k < size)
    {
        Show(mobile, k);
        k++;
    }
}

void Serch(Mobile*& mobile, int& size)
{
    cout << "--------------------------------------------\n";
    string name, company;
    bool found = false;
    cout << "Name : ";
    cin >> name;
    cout << "Company : ";
    cin >> company;
    int k = 0;
    do
    {
        if (mobile[k].Name == name && mobile[k].Company == company)
        {
            Show(mobile, k);
            found = true;
        }
        k++;
    } while (k < size);
    if (!found)
    {
        cout << "Not found ... " << endl;
    }
    cout << "--------------------------------------------\n";
}

void chengeOs(Mobile*& mobile, int& a)
{
    cout << "Enter OS(0:IoS, 1:Android, 2:WindowsPhone) : ";
    int Os;
    cin >> Os;
    switch (Os)
    {
    case 0:
        mobile[a].os = OS::IoS;
    case 1:
        mobile[a].os = OS::Android;
    case 2:
        mobile[a].os = OS::WindowsPhone;
    }
}

void chengeRam(Mobile*& mobile, int& a)
{
    cout << "Enter Ram(0:2GB, 1:4GB, 2:6GB, 3:8GB, 4:12GB, 5:16GB, 6:32GB, 7:64GB) : ";
    int RAm;
    cin >> RAm;
    switch (RAm)
    {
    case 0:
        mobile[a].ram = Ram::r2GB;
    case 1:
        mobile[a].ram = Ram::r4GB;
    case 2:
        mobile[a].ram = Ram::r6GB;
    case 3:
        mobile[a].ram = Ram::r8GB;
    case 4:
        mobile[a].ram = Ram::r12GB;
    case 5:
        mobile[a].ram = Ram::r16GB;
    case 6:
        mobile[a].ram = Ram::r32GB;
    case 7:
        mobile[a].ram = Ram::r64GB;
    }
}

void chengeStorage(Mobile*& mobile, int& a)
{
    cout << "Enter Storage(0:16GB, 1:32GB, 2:64GB, 3:128GB, 4:256GB, 5:512GB , 6:1TB, 7:2TB) : ";
    int STorage;
    cin >> STorage;
    switch (STorage)
    {
    case 0:
        mobile[a].storage = Storage::s16GB;
    case 1:
        mobile[a].storage = Storage::s32GB;
    case 2:
        mobile[a].storage = Storage::s64GB;
    case 3:
        mobile[a].storage = Storage::s128GB;
    case 4:
        mobile[a].storage = Storage::s256GB;
    case 5:
        mobile[a].storage = Storage::s512GB;
    case 6:
        mobile[a].storage = Storage::s1TB;
    case 7:
        mobile[a].storage = Storage::s2TB;
    }
}

void chengePrice(Mobile*& mobile, int& a)
{
    cout << "Enter Price : ";
    int Price;
    cin >> Price;
    mobile[a].price = Price;
}

void chengeaColor(Mobile*& mobile, int& a)
{
    cout << "Enter Color(0:with,1:black,2:blue) : ";
    int COlor;
    cin >> COlor;
    switch (COlor)
    {
    case 0:
        mobile[a].color = Color::white;
    case 1:
        mobile[a].color = Color::black;
    case 2:
        mobile[a].color = Color::blue;
    }
}

void ChengeMobileDetalies(Mobile*& mobile, int& size)
{
    cout << "--------------------------------------------\n";
    string name, company;
    cout << "Name : ";
    cin >> name;
    cout << "Company : ";
    cin >> company;
    for (int i = 0; i < size; i++)
    {
        if (mobile[i].Name == name && mobile[i].Company == company)
        {
            cout << "1.os\n2.ram\n3.storage\n4.price\n5.color\nwhat do you want : ";
            int chose;
            cin >> chose;
            switch (chose)
            {
            case 1:
                chengeOs(mobile, i);
                break;
            case 2:
                chengeRam(mobile, i);
                break;
            case 3:
                chengeStorage(mobile, i);
                break;
            case 4:
                chengePrice(mobile, i);
                break;
            case 5:
                chengeaColor(mobile, i);
                break;
            }
        }
    }
    cout << "--------------------------------------------\n";
}

void SellPhone(Mobile*& mobile, int& size)
{
    cout << "--------------------------------------------\n";
    for (int i = 0; i < size; i++)
    {
        cout << i + 1 << "." << mobile[i].Name << "   " << mobile[i].Company << endl;
    }
    int priceMobile;
    cin >> priceMobile;
    mobile[priceMobile - 1].AvailablePhoneNumber--;
    mobile[priceMobile - 1].PhoneSoldNumber++;
    cout << "--------------------------------------------\n";
}

void PrintPhone(Mobile*& mobile, int& size)
{
    for (int i = 0; i < size; i++)
    {
        Show(mobile, i);
    }
}

void SortBySold(Mobile*& mobile, int& size)
{
    Mobile* t = new Mobile[size];
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - (i + 1); j++)
        {
            if (mobile[j].PhoneSoldNumber > mobile[j + 1].PhoneSoldNumber)
            {
                t[j + 1] = mobile[j + 1];
                mobile[j + 1] = mobile[j];
                mobile[j] = t[j + 1];
            }
        }
    }
    int k = 0;
    while (k < size)
    {
        Show(mobile, k);
        k++;
    }
}
int main()
{
    Mobile* MobileArray;
    int Size = 0;

    int select;
    do
    {
        cout << "Available Phone in store : " << Size << endl;
        cout << "1- Add a phone" << endl
            << "2- Remove a phone" << endl
            << "3- Sort phones by price" << endl
            << "4- Search a phone" << endl
            << "5- Change mobile info" << endl
            << "6- Sell a phone" << endl
            << "7- Print phones" << endl
            << "8- Print phones sorted by the most sold to the least" << endl
            << "9- Quit" << endl;
        cout << "What do you want : ";
        cin >> select;

        switch (select)
        {
        case 1:
            GetInformationPhone(MobileArray, Size);
            break;
        case 2:
            DeletePhone(MobileArray, Size);
            break;
        case 3:
            SortByPrice(MobileArray, Size);
            break;
        case 4:
            Serch(MobileArray, Size);
            break;
        case 5:
            ChengeMobileDetalies(MobileArray, Size);
            break;
        case 6:
            SellPhone(MobileArray, Size);
            break;
        case 7:
            PrintPhone(MobileArray, Size);
            break;
        case 8:
            SortBySold(MobileArray, Size);
            break;
        }
    } while (select != 9);
}
