#include <iostream>
#include <iomanip>

using namespace std;

double convertToMPH(int minutes, int seconds);
double convertToMPH(double kph);

int main() {
	int minutes = 0,
	    seconds = 0;
	double kph = 0.0,
		mph = 0.0;

	cout << "What is the running pace? Enter minutes:";
	cin >> minutes;

	while (minutes < 0){
		cout << "Enter a number greater than 0";
		cin >> minutes;
	}

	cout << "Enter seconds:";
	cin >> seconds;

	while (seconds < 0 && seconds > 60){
		cout << "Enter a number greater than 0 and less than 60";
		cin >> seconds;
	}

	cout << "Enter a KPH time:";
	cin >> kph;

	cout << "A " << minutes << " minute and " << seconds << " second time is " << convertToMPH(minutes, seconds) << "MPH" << endl;
	cout << kph << "KPH is " << convertToMPH(kph) << "MPH";

	return 0;
}

double convertToMPH(int minutes, int seconds) {
	// There are 3600 seconds in an hour
	return (3600.0 / ((minutes * 60) + seconds));
}

double convertToMPH(double kph) {
	return (kph / 1.61);
}
