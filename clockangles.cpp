//Clockangles.cpp
//All angles calculated with the assumption of finding the smallest of the two possible angles
//between the minute and hour hand

#include <iostream>
using namespace std;



double getAngle(int hour, int min){
    //everything in respect to 12:00, which is the 0deg angle
    double answer = 0.0;
    double hourAng = (hour * 30) + (min * 0.5);
    if(hourAng >= 360){
        hourAng = hourAng - 360;
    }
    double minAng = min * 6;
    if(minAng >= 360){
        minAng = minAng - 360;
    }
    answer = hourAng - minAng;
    if(answer < 0){
        answer = answer * -1;
    }
    if(answer > 180){
        answer = 360 - answer;
    } 
    return answer;
}


int main(int argc, char* argv[]) {
	if(argc != 3){
		cerr<<"Usage: "<<argv[0]<<" Enter a list of numbers separated by spaces"<<endl;
		exit(1);
	}
    int hour = atoi(argv[1]);
    int min = atoi(argv[2]);
    double answer = getAngle(hour, min);
    cout<<"The smallest angle between hour and minute hand is " <<answer<<" degrees."<<endl;
}