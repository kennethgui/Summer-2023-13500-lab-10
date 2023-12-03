/*
Author: Kenneth Guillont
Course: CSCI-136
Instructor: Brandon Foster
Assignment: Lab 10 Task C. TimeSlot ending time and printTimeSlot

In the same program time.cpp, implement your own printing function 
printTimeSlot(TimeSlot ts). It should make output in the following format:

Back to the Future COMEDY (116 min) [starts at 9:15, ends by 11:11]
*/

#include <iostream>
using namespace std;

class Time { 
public:
    int h;
    int m;
};

enum Genre {ACTION, COMEDY, DRAMA, ROMANCE, THRILLER};

class Movie { 
public: 
    string title;
    Genre genre;     // only one genre per movie
    int duration;    // in minutes
};

class TimeSlot { 
public: 
    Movie movie;     // what movie
    Time startTime;  // when it starts
};

Time addMinutes(Time time0, int min)
{
    Time addTime;
    addTime.h = time0.h + (min / 60);
    addTime.m = time0.m + (min % 60);
    if (addTime.m >= 60) 
    {
        addTime.h += addTime.m / 60;
        addTime.m %= 60;
    }
    return addTime;
}

int minutesSinceMidnight(Time time)
{
    int hourCounter = time.h;
    int minuteCounter = (hourCounter * 60) + time.m;

    return minuteCounter;
}

int minutesUntil(Time earlier, Time later)
{
    int hoursToMins;
    hoursToMins = (later.h - earlier.h) * 60;


    int mins;
    mins = (later.m - earlier.m);

    int timeUntil = hoursToMins + mins;
    return timeUntil;
}

void printMovie(Movie mv){
    string g;
    switch (mv.genre) {
        case ACTION   : g = "ACTION"; break;
        case COMEDY   : g = "COMEDY"; break;
        case DRAMA    : g = "DRAMA";  break;
        case ROMANCE  : g = "ROMANCE"; break;
        case THRILLER : g = "THRILLER"; break;
    }
    cout << mv.title << " " << g << " (" << mv.duration << " min)";
}

void printTimeSlot(TimeSlot ts)
{
    Time endTime = addMinutes(ts.startTime, ts.movie.duration);

    printMovie(ts.movie); 
    cout <<  " " << "[starts at " << ts.startTime.h << ":" << ts.startTime.m
    << ", ends by " << endTime.h << ":" << endTime.m << "]" << endl;
}

TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie)
{
    TimeSlot scheduled;
    scheduled.movie = nextMovie;

    scheduled.startTime = addMinutes(ts.startTime, ts.movie.duration);

    return scheduled;
}

bool timeOverlap(TimeSlot ts1, TimeSlot ts2)
{
    Time endts1 = addMinutes(ts1.startTime, ts1.movie.duration);
    Time endts2 = addMinutes(ts2.startTime, ts2.movie.duration);

    if (ts1.startTime.h < endts2.h || (ts1.startTime.h == endts2.h && ts1.startTime.m < endts2.m))
    {
        if (endts1.h > ts2.startTime.h || (endts1.h == ts2.startTime.h && endts1.m > ts2.startTime.m))
            return true;
    }
    return false;
}

int main()
{

    TimeSlot testTime1 = {{"The Wolf of Wall Street", COMEDY, 180}, {10, 30}};
    TimeSlot testTime2 = {{"5 Centimeters Per Second", DRAMA, 63}, {8, 30}};
    cout << timeOverlap(testTime1, testTime2);

    return 0;
}