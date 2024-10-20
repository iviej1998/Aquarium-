
#include <iostream>
#include <ctime>
using namespace std;

//TO DO
// JILL - ADD FILTER CODE FROM RESEARCH
// BOTH- STORE DATA INTO LINKED LIST (optional)
//BOTH- OVERLOAD OPERATOR CS225
//			insertion 
//			addition
//BOTH - SAVE FUNCTIONS INTO MULTIPLE FILES (CS225) ("".h)
//BOTH - SORTING ALGORITHM?
		//highest -lowest values (summary - month)



class Aquarium {
private:
	string userInputMonth;
	string userInput;

public:

	Aquarium() {}//constructor

	int setMonth(const string& userInputMonth) {
		if (userInputMonth == "January" || userInputMonth == "january") {
			return 1;
		}
		else if (userInputMonth == "February" || userInputMonth == "february") {
			return 2;
		}
		else if (userInputMonth == "March" || userInputMonth == "march") {
			return 3;
		}
		else if (userInputMonth == "April" || userInputMonth == "april") {
			return 4;
		}
		else if (userInputMonth == "May" || userInputMonth == "may") {
			return 5;
		}
		else if (userInputMonth == "June" || userInputMonth == "june") {
			return 6;
		}
		else if (userInputMonth == "July" || userInputMonth == "july") {
			return 7;
		}
		else if (userInputMonth == "August" || userInputMonth == "august") {
			return 8;
		}
		else if (userInputMonth == "September" || userInputMonth == "september") {
			return 9;
		}
		else if (userInputMonth == "October" || userInputMonth == "october") {
			return 10;
		}
		else if (userInputMonth == "November" || userInputMonth == "november") {
			return 11;
		}
		else if (userInputMonth == "December" || userInputMonth == "december") {
			return 12;
		}
		else {
			return -1;
		}
	}

	string CapitalizeFirstLetter(string userInput) {
		if (!userInput.empty()) { //if the name array isn't empty
			userInput[0] = toupper(userInput[0]); //initialize character to capitalized version
			for (int i = 1; i < userInput.length(); i++) {
				userInput[i] = tolower(userInput[i]); //initialize all other characters to lowercased
			}
		}
		return userInput;
	}
};

class chemicalParameters : public Aquarium {

private:
	double pHLevel;
	double ammoniaLevel;
	double nitriteLevel;
	double nitrateLevel;
	string pHAction;
	string ammoniaAction;
	string nitriteAction;
	string nitrateAction;

public:

	chemicalParameters() {} //default constructor

	// chemical value setters 
	void setpH(double pHLevel) { this->pHLevel = pHLevel; }

	void setAmmonia(double ammoniaLevel) { this->ammoniaLevel = ammoniaLevel; }

	void setNitrite(double nitriteLevel) { this->nitriteLevel = nitriteLevel; }

	void setNitrate(double nitrateLevel) { this->nitrateLevel = nitrateLevel; }

	// chemical value getters

	double getAmmonia() { return ammoniaLevel; }

	double getpH() { return pHLevel; }

	double getNitrite() { return nitriteLevel; }

	double getNitrate() { return nitrateLevel; }

	// chemical action setters

	void setpHAction(string pHAction) { this->pHAction = pHAction; }

	void setAmmoniaAction(string ammoniaAction) { this->ammoniaAction = ammoniaAction; }

	void setNitriteAction(string nitriteAction) { this->nitriteAction = nitriteAction; }

	void setNitrateAction(string nitrateAction) { this->nitrateAction = nitrateAction; }

	// chemical action getters

	string getpHAction() { return pHAction; }

	string getAmmoniaAction() { return ammoniaAction; }

	string getNitriteAction() { return nitriteAction; }

	string getNitrateAction() { return nitrateAction; }


	//this function evaluates use-_entered pH level and prints instructions
	void maintainpH(double pHLevel) {
		char userInput;
		if ((pHLevel <= 8.4) && (pHLevel >= 8.2))
			cout << "\npH is within normal limits. Continue weekly monitoring." << endl;
		else if (pHLevel > 8.4) {
			cout << "\nThe pH is too high!" << endl;
			//causes? solutions?
		}
		else if (pHLevel < 8.2) {
			cout << endl;
			cout << "The pH is too low!\n This can be due to:\n1. Animal waste decomposing and producing organic acids." << endl;
			cout << "2. Uneaten food is decomposing and producing organic acids." << endl;
			cout << "3. Animal respiration making the water acidic." << endl;
			cout << endl;
			cout << "The first solution is to perform a water change." << endl;
			cout << "Have you already performed a recent water change due to this issue?(y/n): ";
			cin >> userInput;
			if (userInput == 'y' || userInput == 'Y') {
				cout << endl;
				cout << "Add 4.5 scoops of PROPER pH 8.2 powder. Re-check pH levels tomorrow." << endl;
				pHAction = "Added 4.5 scoops of PROPER pH 8.2 powder. Will re-check pH levels tomorrow.";
				setpHAction(pHAction);
			}
			else if (userInput == 'n' || userInput == 'N') {
				cout << endl;
				cout << "Perform a partial water change today. Re-check pH levels tomorrow." << endl;
				pHAction = "Performed a partial water change today. Will Re-check pH levels tomorrow.";
				setpHAction(pHAction);
			}
		}

	}

	//this function evaluates user-entered ammonia levels and prints instructions
	void maintainAmmonia(double ammoniaLevel) {
		char userInput;
		if (ammoniaLevel > 0.0) {
			cout << endl;
			cout << "Ammonia level is elevated!" << endl;
			cout << "Fish continually release ammonia through their gills, urine, and solid waste." << endl;
			cout << "Uneaten food or decaying organic matter (dead fish) left in the tank can elevate Ammonia." << endl;
			cout << endl;
			cout << "Is this the first abnormal ammonia test this week? (y/n): ";
			cin >> userInput;
		}
		if (userInput == 'y' || userInput == 'Y') {
			cout << endl;
			cout << "Add 40 - 60 ml of API QUICK START to the aquarium. Nitrifying bacteria will help lower ammonia and reduce the risk of fish loss." << endl;
			cout << "Re-check ammonia levels tomorrow." << endl;
			cout << endl;
			ammoniaAction = "Added API Quick Start to the aquarium. Will re-check ammonia levels tomorrow.";
			setAmmoniaAction(ammoniaAction);
		}
		else if (userInput == 'n' || userInput == 'N') {
			cout << endl;
			cout << "Perform a 25% water change, then add 20 ml of API AMMO LOCK Detoxifier." << endl;
			cout << "It works instantly to convert poisonous ammonia to a non-toxic form." << endl;
			cout << "Repeat every TWO days until ammonia is no longer detected.\n" << endl; //set a reminder
			ammoniaAction = "Performed a 25% water change. Added 20 ml of API AMMO LOCK Detoxifier.\n Will send an alert in TWO days as a reminder to repeat the process.";
			setAmmoniaAction(ammoniaAction);
		}
		else if (ammoniaLevel == 0.0) {
			cout << "Ammonia is non-existent. Continue weekly monitoring." << endl;
			ammoniaAction = "No actions needed.";
			setAmmoniaAction(ammoniaAction);
		}
	}

	//this function evaluates user-entered ammonia levels and prints instructions 
	void maintainNitrite(double nitriteLevel) {
		if (nitriteLevel > 0.0) {
			cout << endl;
			cout << "Nitrite level is elevated!" << endl;
			cout << "Perform a partial water change, add API quick start." << endl;
			nitriteAction = "Performed at partial water change. API quick start added.";
			setNitriteAction(nitriteAction);
		}
		else if (nitriteLevel == 0.0) {
			cout << "Nitrite is non-existent. continue weekly monitoring." << endl;
			nitriteAction = "No actions taken.";
			setNitriteAction(nitriteAction);
		}
	}

	//this function evaluates user-entered nitrate levels and prints instructions
	void maintainNitrate(double nitrateLevel) {
		int userInput = 0;
		if (nitrateLevel < 3.0) {
			cout << endl;
			cout << "Nitrate level is too low! " << endl;
			cout << "This can be due to: \n1. Overly efficient filtration.\n2. Underfeeding the fish.\n3. Too few fish in the tank." << endl;
			cout << "4. Too frequent large water changes with low quality water." << endl;
			cout << "\n This can lead to:\n1. Coral starvation.\n2. Algae blooms." << endl;
			cout << "Tips for elevating the nitrate level: " << endl;
			cout << "1. Increase feedings - give the fish slightly more food, ensuring they are eating all the food you provide." << endl;
			cout << "2. Adjust the frequency of your filter down slightly." << endl;
			cout << "3. Reduce water change frequency." << endl;
			cout << "4. For extreme cases nitrate substances need to be added. *CAUTION* Choose this option when all other options are exhausted!" << endl;
			cout << endl;
			cout << "Which option do you prefer?" << endl;
			cin >> userInput;
			if (userInput == 1) {
				nitrateAction = "Feedings will be increased.";
				setNitrateAction(nitrateAction);
			}
			else if (userInput == 2) {
				nitrateAction = "The frequency of the filter has been adjusted down.";
				setNitrateAction(nitrateAction);
			}
			else if (userInput == 3) {
				nitrateAction = "The frequency of water changes will be reduced.";
				setNitrateAction(nitrateAction);
			}
			else if (userInput == 4) {
				//code for nitrate chemicals
			}
			else {
				cout << "Error. Please enter a number between 1 and 4: ";
				cin >> userInput;
				if (userInput == 1) {
					nitrateAction = "Feedings will be increased.";
					setNitrateAction(nitrateAction);
				}
				else if (userInput == 2) {
					nitrateAction = "The frequency of the filter has been adjusted down.";
					setNitrateAction(nitrateAction);
				}
				else if (userInput == 3) {
					nitrateAction = "The frequency of water changes will be reduced.";
					setNitrateAction(nitrateAction);
				}
				else if (userInput == 4) {
					//code for nitrate chemicals
				}
			}
		}
		else if (nitrateLevel >= 3.0 && nitrateLevel <= 5.0) {
			cout << endl;
			cout << "Nitrate levels are within normal limits." << endl;
			nitrateAction = " No action needed.";
			setNitrateAction(nitrateAction);
		}
	}

};

class Saltwater : public Aquarium {
private:
	int userInputDay;
	double waterTemp;
	double salinity;
	string waterTempAction;
	string salinityAction;
public:
	Saltwater() {}

	//water setters
	void setWaterTemp(double waterTemp) { this->waterTemp = waterTemp; }

	void setWaterTempAction(string waterTempAction) { this->waterTempAction = waterTempAction; }

	void setSalinity(double salinity) { this->salinity = salinity; }

	void setSalinityAction(string salinityAction) { this->salinityAction = salinityAction; }

	//water getters
	double getWaterTemp() { return waterTemp; }

	string getWaterTempAction() { return waterTempAction; }

	double getSalinity() const { return salinity; }
	
	string getSalinityAction() { return salinityAction; }

	int waterChange(string userInputDay) {
		int userInput = 0;
		if (userInputDay == "Saturday" || userInputDay == "saturday") {
			cout << "\nThe tank is due for a weekly 50% water change." << endl;
			cout << "Choose from the following: " << endl;
			cout << "(1) The water change has been completed.\n(2) The water change cannot be completed at this time." << endl;
			cin >> userInput;
			if (userInput == 1) {
				return 1;
			}
			else {
				return 2;
			}

		}
		return 0;
	}

	void maintainWaterTemp(string& userInputMonth) {
		int monthValue = 0;
		double userInputWater = 0.0;
		string userInputCorrect;
		int userInput = 0;

		monthValue = setMonth(CapitalizeFirstLetter(userInputMonth)); //use setMonth to get month as an integer
		if (monthValue == 1 || monthValue == 12) {
			cout << "\n******* It's winter season! The water will likely need a heater! *******\n" << endl;
		}
		cout << "Measured water temperature: ";
		cin >> userInputWater;
		setWaterTemp(userInputWater);
		cout << "You entered " << userInputWater << endl;
		cout << "Is this correct? ";
		cin >> userInputCorrect;
		while (userInputCorrect == "No" || userInputCorrect == "no") {
			cout << "Measured water temperature: ";
			cin >> userInputWater;
			setWaterTemp(userInputWater);
		}
		if (userInputWater < 77.0) {
			cout << endl;
			cout << "The water temperature should be between 77.0 degrees F and 79.0 degrees F. " << endl;
			cout << "Please turn the heat up in the tank." << endl;
			waterTempAction = "The user increased the heat in the tank.";
			setWaterTempAction(waterTempAction);
		}
		else if (userInputWater >= 77.0 && userInputWater <= 79.0) {
			cout << endl;
			cout << "The water temperature is within normal limits." << endl;
			waterTempAction = "No actions needed.";
			setWaterTempAction(waterTempAction);
		}
		else if (userInputWater > 79.0) {
			cout << endl;
			cout << "The water temperature is too high." << endl;
			cout << "Tips for lowering the water tempature: " << endl;
			cout << "1. Freeze RO water into ice cubes and add a tray of ice cubes into the tank." << endl;
			cout << "2. Turn the AC on in the room and point it at the tank." << endl;
			cout << "3. Freeze a plastic bottle of water and insert the bottle into the tank.\n" << endl;
			cout << "Which one do you prefer? (1 - 3) ";
			cin >> userInput;
			cout << endl;
			if (userInput == 1) {
				waterTempAction = "A tray of RO ice cubes dispensed into the tank.";
				setWaterTempAction(waterTempAction);
			}
			else if (userInput == 2) {
				waterTempAction = "Turned on the AC and pointed it at the tank.";
				setWaterTempAction(waterTempAction);
			}
			else if (userInput == 3) {
				waterTempAction = "A frozen plastic bottle of water placed into the tank.";
				setWaterTempAction(waterTempAction);
			}

		}
		else {
			cout << endl;
			cout << "Error. Please re-enter the measured water temperature: ";
			cin >> userInputWater;
			cout << "You entered " << userInputWater << endl;
			cout << "Is this correct? ";
			while (userInputCorrect == "No" || userInputCorrect == "no") {
				cout << "Measured water temperature: ";
				cin >> userInputWater;
				if (userInputCorrect == "Yes" || userInputCorrect == "yes") {
					if (userInputWater < 77.0) {
						cout << endl;
						cout << "The water temperature should be between 77.0 degrees F and 79 degrees F. " << endl;
						cout << "Please turn the heat up in the tank." << endl;
						cout << endl;
					}
					else if (userInputWater > 77.0 || userInputWater < 79.0) {
						cout << endl;
						cout << "The water temperature is within normal limits." << endl;
						cout << endl;
					}
					else if (userInputWater > 79.0) {
						cout << "The water temperature is too high!" << endl;
						cout << "Tips for lowering the water tempature: " << endl;
						cout << "1. Freeze RO water into ice cubes and add a tray of ice cubes into the tank." << endl;
						cout << "2. Turn the AC on in the room and point it at the tank." << endl;
						cout << "3. Freeze a plastic bottle of water and insert the bottle into the tank." << endl;
						cout << "Which one do you prefer? (1 - 3) ";
						cin >> userInput;
						cout << endl;
						if (userInput == 1) {
							waterTempAction = "A tray of RO ice cubes dispensed into the tank.";
							setWaterTempAction(waterTempAction);
						}
						else if (userInput == 2) {
							waterTempAction = "Turned on the AC and pointed it at the tank.";
							setWaterTempAction(waterTempAction);
						}
						else if (userInput == 3) {
							waterTempAction = "A frozen plastic bottle of water placed into the tank.";
							setWaterTempAction(waterTempAction);
						}
					}
				}
			}
		}
	}
	void maintainSalinity(double salinity) {
		double targetSalinity = 1.025;
		if (salinity < 1.024) {
			cout << "\nSalinity is too low!" << endl;
			cout << "Increase salinity by " << targetSalinity - salinity << endl;
			cout << endl;
			salinityAction = "Salinity will be increased.";
			setSalinityAction(salinityAction);
		}
		else if (salinity >= 1.024 && salinity <= 1.026) {
			cout << "\nSalinity is within normal limits. " << endl;
			salinityAction = "No actions needed.";
			cout << endl;
			setSalinityAction(salinityAction);
		} 
		else if (salinity > 1.026) {
			cout << "\nSalinity is too low!" << endl;
			cout << "Increase the salinity by " << salinity - targetSalinity << endl;
			cout << endl;
			salinityAction = "Salinity will be decreased.";
			setSalinityAction(salinityAction);
		}
	}
};

class Filter : public Aquarium {
private:
public:

};

int main() {
	// create a parent and children objects
	Aquarium aquarium;
	chemicalParameters parameters;
	Saltwater saltwater;
	// initialize variables
	double userInputWater = 0.0;
	double userInputSalinity = 0.0;
	double userInputpH = 0.0;
	double userInputAmmonia = 0.0;
	double userInputNitrite = 0.0;
	double userInputNitrate = 0.0;
	string userInputDay; 
	string userInputCorrect;
	string userInputMonth;
	int dayValue = 0;
	int userInputDayNum = 0; 
	//int monthValue = 0;


	//greet the user
	cout << "**************** Welcome to your Saltwater Tank Management System ****************" << endl;

	while (true) {
		//prompt the user to enter the date
		cout << "Please enter the month: ";
		cin >> userInputMonth;
		//monthValue = aquarium.setMonth(userInputMonth);
		if (userInputMonth[0] != toupper(userInputMonth[0])) {
			userInputMonth = aquarium.CapitalizeFirstLetter(userInputMonth);
		}
		cout << "You entered: " << userInputMonth << endl;
		cout << "Is this correct? ";
		cin >> userInputCorrect;
		while (userInputCorrect == "No" || userInputCorrect == "no") {
			cout << "Please enter the month: " << endl;
			cin >> userInputMonth;
			//monthValue = aquarium.setMonth(userInputMonth);
			if (userInputMonth[0] != toupper(userInputMonth[0])) {
				userInputMonth = aquarium.CapitalizeFirstLetter(userInputMonth);
			}
			cout << "You entered: " << userInputMonth << endl;
			cout << "Is this correct? ";
			cin >> userInputCorrect;
		}
		if (userInputCorrect == "yes" || userInputCorrect == "Yes") {
			cout << "Please enter the day of the week: ";
			cin >> userInputDay;
			if (userInputDay[0] != toupper(userInputDay[0])) {
				userInputDay = aquarium.CapitalizeFirstLetter(userInputDay);
			}
			cout << "You entered: " << userInputDay << endl;
			cout << "Is this correct? ";
			cin >> userInputCorrect;
			dayValue = saltwater.waterChange(userInputDay);
			while (userInputCorrect == "No" || userInputCorrect == "no") {
				cout << "Please enter the day of the week: ";
				cin >> userInputDay;
				if (userInputDay[0] != toupper(userInputDay[0])) {
					userInputDay = aquarium.CapitalizeFirstLetter(userInputDay);
				}
				cout << "You entered: " << userInputDay << endl;
				cout << "Is this correct? ";
				cin >> userInputCorrect;
			}
			if (userInputCorrect == "yes" || userInputCorrect == "Yes") {
				cout << "Please enter the day of the month (a number): ";
				cin >> userInputDayNum;
				cout << "You entered: " << userInputDayNum << endl;
				cout << "Is this correct? ";
				cin >> userInputCorrect;
				while (userInputCorrect == "No" || userInputCorrect == "no") {
					cout << "Please enter the day of the month (a number): ";
					cin >> userInputDayNum;
					cout << "You entered: " << userInputDay << endl;
					cout << "Is this correct? ";
					cin >> userInputCorrect;
				}
				if (userInputCorrect == "yes" || userInputCorrect == "Yes") {
					cout << "\nToday is " << userInputDay << "," << userInputMonth <<" "<< userInputDayNum << endl;
				}

			}
			//call water function
			saltwater.setWaterTemp(userInputWater);
			saltwater.maintainWaterTemp(userInputMonth);

			//prompt the user to enter a salinity value
			cout << "Measured Salinity: ";
			cin >> userInputSalinity;
			cout << "You entered " << userInputSalinity;
			cout << "Is this correct? ";
			cin >> userInputCorrect;
			while (userInputCorrect == "No" || userInputCorrect == "no") {
				cout << "Measured Salinity: ";
				cin >> userInputSalinity;
				cout << "You entered " << userInputSalinity;
				cout << "Is this correct? ";
				cin >> userInputCorrect;
			}
			//call salinity function
			saltwater.setSalinity(userInputSalinity);
			saltwater.maintainSalinity(userInputSalinity);

			//prompt the user to enter a pH value 
			cout << "Measured pH Level: ";
			cin >> userInputpH;
			cout << "You entered " << userInputpH << endl;
			cout << "Is this correct? ";
			cin >> userInputCorrect;
			while (userInputCorrect == "No" || userInputCorrect == "no") {
				cout << "Measured pH Level: ";
				cin >> userInputpH;
				cout << "You entered " << userInputpH << endl;
				cout << "Is this correct? ";
				cin >> userInputCorrect;
			}
			//call pH function
			parameters.setpH(userInputpH);
			parameters.maintainpH(userInputpH);

			//prompt the user to enter an Ammonia value
			cout << "Measured Ammonia Level: ";
			cin >> userInputAmmonia;
			cout << "You entered " << userInputAmmonia << endl;
			cout << "Is this correct? ";
			cin >> userInputCorrect;
			while (userInputCorrect == "No" || userInputCorrect == "no") {
				cout << "Measured Ammonia Level: ";
				cin >> userInputAmmonia;
				cout << "You entered " << userInputAmmonia << endl;
				cout << "Is this correct? ";
				cin >> userInputCorrect;
			}
			//call ammonia function
			parameters.setAmmonia(userInputAmmonia);
			parameters.maintainAmmonia(userInputAmmonia);

			//prompt the user to enter a nitrite value
			cout << "Measured Nitrite Level: ";
			cin >> userInputNitrite;
			cout << "You entered " << userInputNitrite << endl;
			cout << "Is this correct? ";
			cin >> userInputCorrect;
			while (userInputCorrect == "No" || userInputCorrect == "no") {
				cout << "Measured Nitrite Level: ";
				cin >> userInputNitrite;
				cout << "You entered " << userInputNitrite << endl;
				cout << "Is this correct? ";
				cin >> userInputCorrect;
			}
			//call nitrite function
			parameters.setNitrite(userInputNitrite);
			parameters.maintainNitrite(userInputNitrite);

			//prompt the user to enter a nitrate value
			cout << "Measured Nitrate Level: ";
			cin >> userInputNitrate;
			cout << "You entered: " << userInputNitrate << endl;
			cout << "Is this correct? ";
			cin >> userInputCorrect;
			while (userInputCorrect == "No" || userInputCorrect == "no") {
				cout << "Measured Nitrate Level: ";
				cin >> userInputNitrate;
				cout << "You entered: " << userInputNitrate << endl;
				cout << "Is this correct? ";
				cin >> userInputCorrect;
			}
			//call nitrate function
			parameters.setNitrate(userInputNitrate);
			parameters.maintainNitrate(userInputNitrate);

		}

		cout << endl;
		cout << "Today's Summary:" << endl;
		cout << "Measured Water Temparature was " << saltwater.getWaterTemp() << endl;
		cout << "Actions taken: " << endl;
		cout << saltwater.getWaterTempAction() << endl;
		cout << "Measured Salinity was: " << saltwater.getSalinity() << endl;
		cout << "Actions taken: " << endl;
		cout << saltwater.getSalinity() << endl;
		cout << "Measured pH Level was: " << parameters.getpH() << endl;
		cout << "Actions taken: " << endl;
		cout << parameters.getpHAction();
		cout << "Measured Ammonia Level was: " << parameters.getAmmonia() << endl;
		cout << "Actions taken: " << endl;
		cout << parameters.getAmmoniaAction() << endl;
		cout << "Measured Nitrite Level was: " << parameters.getNitrite() << endl;
		cout << "Actions taken: " << endl;
		cout << parameters.getNitriteAction() << endl;
		cout << "Measured Nitrate Level was: " << parameters.getNitrate() << endl;
		cout << "Actions taken: " << endl;
		cout << parameters.getNitrateAction() << endl;
		cout << endl;

		cout << "Writing today's summary into a file for record keeping..." << endl;

		//code for file writing goes here 

		//possible linked list code
	}



return 0;
}