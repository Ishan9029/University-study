#include <iostream>
#include <fstream>
using namespace std;

struct Data
{
    int id;
    char name[20];
};

int main()
{
    Data d = {32, "Ishan Ahmed"};
    ofstream out("data.bin", ios::binary);
    out.write((char *)&d, sizeof(d));
    out.close();

    Data readData;
    ifstream in("data.bin", ios::binary);
    in.read((char *)&readData, sizeof(readData));
    cout << "ID: " << readData.id << ", Name: " << readData.name << endl;
    in.close();
    return 0;
}
