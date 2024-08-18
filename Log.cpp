#include <iostream>
#include <fstream>
#include <iomanip>
#include <ctime>
#include <chrono>

using namespace std;

ofstream outputFile;

string getCurrentTimeString(){
    auto now = chrono::system_clock::now();
    time_t currentTime = chrono::system_clock::to_time_t(now);

    tm* localTime = localtime(&currentTime);

    auto ms = chrono::duration_cast<chrono::milliseconds>(now.time_since_epoch()) % 1000;

    stringstream ss;
    ss << "[" << put_time(localTime, "%Y-%m-%d %H:%M:%S")
       << ":" << setfill('0') << setw(3) << ms.count() << "]";

    return ss.str();
}



void Log(string info)
{
    string time = getCurrentTimeString();
    outputFile.open("History.txt", ios::app);
    if(outputFile.is_open()){
        outputFile << "INFO:" << time << info << endl;
        outputFile.close();
    }
    else{
        cout << "File Error" << endl;
    }
}