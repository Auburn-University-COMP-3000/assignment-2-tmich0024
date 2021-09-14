#include <iostream>

using namespace std;

bool isLeapYear(int year){
    if (year%400 == 0){
        return true;
    }
    else{
        return false;
    }
}

int getCenturyValue(int year){
    int firstPart = year/100;
    return (3-firstPart%4)*2;
}

int getYearValue(int year){
    int lastPart = year%100;
    return lastPart+lastPart/4;
}

int getMonthValue(int month, int year){
    if (isLeapYear(year)){
        if (month == 1){
            return 6;
        }
        else if (month ==2){
            return 2;
        }
    }
    
    switch (month){
        case 1:
            return 0;
            break;
        case 2:
            return 3;
            break;
        case 3:
            return 3;
            break;
        case 4:
            return 6;
            break;
        case 5:
            return 1;
            break;
        case 6:
            return 4;
            break;
        case 7:
            return 6;
            break;
        case 8:
            return 2;
            break;
        case 9:
            return 5;
            break;
        case 10:
            return 0;
            break;
        case 11:
            return 3;
            break;
        case 12:
            return 5;
            break;
            
    }
    return 0;
}


int main(){

   int month,
        day = 0, 
        year = 0, 
        sum = 0,
        day_of_week = 0;
    string day_string = ""; 

    cout << "enter the month"<< endl; 

    cin >> month; 

    while (month < 1 || month > 12){

        cout << "please give a valid month";
        cin >> month; 
    }

    cout << "enter a day" << endl;

    cin >> day; 

    if (month == 4 || month == 6|| month == 9 || month ==11 ){

        while (day < 1 || day > 30) {
			cout << "Enter a value between 1 and 30:";
			cin  >> day;
		}



    }

    cout << "enter the year" << endl;

    cin >> year;

    // Calculate the day of week
	sum = day + getMonthValue(month,year) + getYearValue(year) + getCenturyValue(year);
	day_of_week = sum % 7;
	
	// Find corresponding day name
	switch(day_of_week) {

        case 0: 
            day_string = "Sunday"; 
            break; 

        case 1:
            day_string = "Monday"; 
            break; 

        case 2:
            day_string = "Tuesday"; 
            break; 

        case 3: 
            day_string = "Wednesday"; 
            break; 

        case 4:
            day_string = "Thursday"; 
            break; 

        case 5:
            day_string = "Friday"; 
            break; 

        case 6:
            day_string = "Saturday"; 
            break; 

        
    }

    cout << day_string ;
    return 0; 
}