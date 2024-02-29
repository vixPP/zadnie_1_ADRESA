#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Address
{
private:
    string city;
    string street;
    int HouseNumber;
    int FlatNumber;

public:

    Address(string c, string s, int H, int F) :city(c),
        street(s), HouseNumber(H), FlatNumber(F) {}

    string get_output_address() {
        return city + ", " + street + ", " + to_string(HouseNumber) + ", " +
            to_string(FlatNumber) + ". ";

    }

};

int main()
{
    ifstream inputFile("C:\\Users\\vix\\source\\repos\\in.txt");
    ofstream outputFile("C:\\Users\\vix\\source\\repos\\out.txt");

    int N;
    inputFile >> N;

    vector<Address*> addresses;

    for (int i = 0; i < N; ++i)
    {

        string city, street;
        int HouseNumber, FlatNumber;

        inputFile >> city >> street >> HouseNumber >> FlatNumber;
        Address* address = new Address(city, street, HouseNumber, FlatNumber);
        addresses.push_back(address);
    }

    outputFile << N << endl;

    for (int i = N - 1; i >= 0; --i)
    {
        outputFile << addresses[i]->get_output_address() << endl;
        delete addresses[i];
    }

    inputFile.close();
    outputFile.close();

    return 0;
}

