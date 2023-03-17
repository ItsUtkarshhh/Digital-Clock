#include<iostream>
#include<unistd.h>
#include<windows.h>
#include<conio.h>
using namespace std;

int hours, minutes, seconds;

void Clock() {
    cout<<"Enter time in H : M : S format : ";
    cin>>hours>>minutes>>seconds;
    hours %= 24; minutes %= 60; seconds %= 60;
    while(true)
    {
        while (hours < 24) {
	    	while (minutes < 60) {
	    		while (seconds < 60) {
	    			cout <<"Current Time : "<<hours<<":"<<minutes<<":"<<seconds++;
	    			//HH:MM:SS columns in output
	    			sleep(1);
	    			system("cls");
	    		}
	    		seconds = 0; minutes++;
	    	}
	    	minutes = 0; hours++;
	    }
        if((hours==0||hours==24)&&(minutes==0||minutes==60)&&(seconds==0||seconds==60))
        {
            Beep(200,250); Beep(200,250);
        }
        hours = 0; seconds = 0; minutes = 0;
    }
    return;
}

int main() {
    Clock();
    getch();
    return 0;
}