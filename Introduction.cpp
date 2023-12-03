#include <iostream>
using namespace std; 


class Time {
    public:
        int h;
        int m;
};

void printTime (Time time)
{
    cout << time.h << ":" << time.m << endl;
}

int main()
{
    Time morningLecture = {8,10};
    Time myAlarm;

    myAlarm = morningLecture;

    printTime(morningLecture);
    printTime(myAlarm);

    return 0;
}