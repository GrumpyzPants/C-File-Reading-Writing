#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cmath>
using namespace std;

//Given in previous codes
string strtolower(string);
string trim(string);
int ProcessCommand(string);

//Tokenizer class -- given in previous codes
class Tokenizer {

private:
	vector <string> tokens;

public:
	Tokenizer(string, char);

	int GetNumTokens();
	bool HasMoreTokens();
	string NextToken();

};

//Main function 
int main() {
	//Creates a string cmd that will pass command values to the function: ProcessCommand
	string cmd;

	//Formatting stuff -- mainly for spacing and clarity this is dup'd once
	cout << "Enter a Command: ";		//Asks for user to enter command
	getline(cin, cmd);					//Gets value from users input
	ProcessCommand(cmd);				//Passes value to function 

	//Loops until told to exit by 'quit' or 'exit' cmd
	while (true) {
		cout << "\nEnter a Command: ";	//same as above
		getline(cin, cmd);
		ProcessCommand(cmd);

	}

	return 0;							//exits
}

//Given in previous codes
class EZFileRead {
	// Fields
private:
	vector<string> v;

	// Constructor
public:
	EZFileRead(string);

	// Functions
	size_t GetNumLines();
	string GetLine(size_t);
};

//Function for processing commands
int ProcessCommand(string raw) {

	//Resets position to find the cmd within string
	string cmd = raw.substr(0, raw.find(":"));
	//Takes the cmd -> removes spacing and converts to lowercase
	cmd = trim(strtolower(cmd));

	//if cmd is project - prints following
	if (cmd == "project") {
		cout << "This is the final project for CSCI 0066" << endl;
	}

	//if cmd is points - prints following
	else if (cmd == "points") {
		cout << "This assignment is worth 250 points" << endl;
	}

	//if cmd is display - prints value after display
	else if (cmd == "display") {
		string message = raw.substr(raw.find(":") + 1);		//Goes to position after ':' and saves all values after as a string message
		cout << trim(message) << endl;				//Prints message
	}

	//if cmd is sqrt or square root - takes sqrt of number and prints result
	else if (cmd == "sqrt" || cmd == "square root") {
		int num = stoi(raw.substr(raw.find(":") + 1));
		cout << "The sqrt of " << num << " is: " << sqrt(num) << endl;
	}

	//if cmd is log - takes log of given number
	else if (cmd == "log2" || cmd == "logarithm 2") {
		int num = stoi(raw.substr(raw.find(":") + 1));
		cout << "The log2 of " << num << " is: " << log2(num) << endl;
	}

	//if cmd is add - adds two given numbers
	else if (cmd == "add") {
		size_t pos = raw.find(":") + 1;								//Finds position of first ":" + 1 -> stores as pos
		int num1 = stoi(raw.substr(pos, raw.find(",") - pos));					//Takes pos - finds next pos of "," - stores anything between as num1
		pos = raw.find(",") + 1;								//Takes pos and sets to ","
		int num2 = stoi(raw.substr(pos));							//Takes pos and returns anything after the "," that pos is saved to - stores as num

		cout << num1 << " + " << num2 << " = " << (num1 + num2) << endl;			//Does the math
	} 

	//if cmd is subtract - subtracts two given numbers
	else if (cmd == "sub" || cmd == "subtract") {
		size_t pos = raw.find(":") + 1;
		int num1 = stoi(raw.substr(pos, raw.find(",") - pos));
		pos = raw.find(",") + 1;
		int num2 = stoi(raw.substr(pos));

		cout << num1 << " + " << num2 << " = " << (num1 - num2) << endl;
	}

	//if cmd is mul - multiplies two given number
	else if (cmd == "mul" || cmd == "multiply") {
		size_t pos = raw.find(":") + 1;
		int num1 = stoi(raw.substr(pos, raw.find(",") - pos));
		pos = raw.find(",") + 1;
		int num2 = stoi(raw.substr(pos));

		cout << num1 << " * " << num2 << " = " << (num1 * num2) << endl;
	}

	//if cmd is div - divides two given numbers (checks if 2nd number is 0 to avoid dividing by zero)
	else if (cmd == "div" || cmd == "divide") {
		size_t pos = raw.find(":") + 1;
		int num1 = stoi(raw.substr(pos, raw.find(",") - pos));
		pos = raw.find(",") + 1;
		int num2 = stoi(raw.substr(pos));

		if (num2 == 0) {
			cout << "Dividing by is Undefined" << endl;
		}
		else {
			cout << num1 << " / " << num2 << " = " << (num1 / num2) << endl;
		}
	}

	//if cmd is mod - takes modulus of two given numbers
	else if (cmd == "mod" || cmd == "modulus") {
		size_t pos = raw.find(":") + 1;
		int num1 = stoi(raw.substr(pos, raw.find(",") - pos));
		pos = raw.find(",") + 1;
		int num2 = stoi(raw.substr(pos));

		cout << num1 << " % " << num2 << " = " << (num1 % num2) << endl;
	}

	//if cmd is shr - takes given value then shifts right by other given value
	else if (cmd == "shr" || cmd == "shift right") {
		size_t pos = raw.find(":") + 1;
		int num1 = stoi(raw.substr(pos, raw.find(",") - pos));
		pos = raw.find(",") + 1;
		int num2 = stoi(raw.substr(pos));

		cout << num1 << " >> " << num2 << " = " << (num1 >> num2) << endl;
	}

	//if cmd is shl - takes given value then shifts left by other given value
	else if (cmd == "shl" || cmd == "shift left") {
		size_t pos = raw.find(":") + 1;
		int num1 = stoi(raw.substr(pos, raw.find(",") - pos));
		pos = raw.find(",") + 1;
		int num2 = stoi(raw.substr(pos));

		cout << num1 << " << " << num2 << " = " << (num1 << num2) << endl;
	}

	//if cmd is add3 - takes three numbers and adds them together
	else if (cmd == "add3" || cmd == "add 3") {
		size_t pos = raw.find(":") + 1;									//finds position of ":" - sets to variable pos but plus 1 in position
		int num1 = stoi(raw.substr(pos, raw.find(",") - pos));						//takes pos - then finds position of first found "," - returns values between as substring stored in num1
		pos = raw.find(",") + 1;									//sets pos to first found "," + 1
		int num2 = stoi(raw.substr(pos, raw.find(",") - pos));						//takes pos - then finds next "," - returns value between as substring stored in num2
		pos = raw.find_last_of(",") + 1;								//Finds last ","
		int num3 = stoi(raw.substr(pos));								//takes pos and returns and value after stored in num3

		cout << num1 << " + " << num2 << " + " << num3 << " = " << (num1 + num2 + num3) << endl;	//does the math
	}

	//if cmd is mul3 - takes three numbers and multiplies them together
	else if (cmd == "mul3" || cmd == "multiply 3") {
		size_t pos = raw.find(":") + 1;
		int num1 = stoi(raw.substr(pos, raw.find(",") - pos));
		pos = raw.find(",") + 1;
		int num2 = stoi(raw.substr(pos, raw.find(",") - pos));
		pos = raw.find_last_of(",") + 1;
		int num3 = stoi(raw.substr(pos));

		cout << num1 << " * " << num2 << " * " << num3 << " = " << (num1 * num2 * num3) << endl;
	}

	//if cmd is fact - finds factorial of provided number
	else if (cmd == "fact" || cmd == "factorial") {
		int num = stoi(raw.substr(raw.find(":") + 1));
		
		int result = 1;
		for (int i = 1; i <= num; i++) {
			result *= i;
		}

		cout << "Factorial " << num << "! is: " << result << endl;
	}

	//if cmd is load - loads file found in .cpp file location
	else if (cmd == "load" || cmd == "load file") {
		string filename = trim(raw.substr(raw.find(":") + 1));
		EZFileRead fileReader("script.txt");
		cout << "Processing script... " << endl;
		for (size_t i = 0; i < fileReader.GetNumLines(); i++) {
			string line = fileReader.GetLine(i);
			ProcessCommand(line);
		}
	}

	//if cmd is adv load - asks for file path and executes any cmds found within the file
	else if (cmd == "adv load" || cmd == "advanced load") {
		string loc;
		cout << "Please enter the file path: ";
		getline(cin, loc);
		string filename = trim(raw.substr(raw.find(":") + 1));
		EZFileRead fileReader(loc);
		cout << "Processing script... " << endl;
		for (size_t i = 0; i < fileReader.GetNumLines(); i++) {
			string line = fileReader.GetLine(i);
			ProcessCommand(line);
		}
	}

	//Help function to display all cmds 
	else if (cmd == "help") {
		cout << "-----------------------\nHere are list of commands the user can input (please expand cmd window to full): \n" << endl;

		cout << "|----------|----------------------------------------------------------------------------------------|---------------------------------------|" << endl;
		cout << "| Name     | Description                                                                            | Syntax                                |" << endl;
		cout << "|----------|----------------------------------------------------------------------------------------|---------------------------------------|" << endl;
		cout << "| Project  | Displays details about the project.                                                    | project                               |" << endl;
		cout << "| Points   | Displays the points of the project.                                                    | points                                |" << endl;
		cout << "| Display  | Displays the words after display.                                                      | display: (contents)                   |" << endl;
		cout << "| Sqrt     | Square roots a provided integer value.                                                 | sqrt: (integer value)                 |" << endl;
		cout << "| log2     | Performs log2 on a provided integer value.                                             | log2: (integer value)                 |" << endl;
		cout << "| Add      | Adds two integer values together.                                                      | add: (value 1), (value 2)             |" << endl;
		cout << "| Sub      | Subtracts two integer values together.                                                 | sub: (value 1), (value 2)             |" << endl;
		cout << "| Mul      | Mulitplies two integer values together.                                                | mul: (value 1), (value 2)             |" << endl;
		cout << "| Div      | Divides two integer values together.                                                   | div: (value 1), (value 2)             |" << endl;
		cout << "| Mod      | Takes the modulus of two integer values together.                                      | mod: (value 1), (value 2)             |" << endl;
		cout << "| Shr      | Shifts the value of a provided number x values to the right (bitwise opperation).      | shr: (value), (shift)                 |" << endl;
		cout << "| Shl      | Shifts the value of a provided number x values to the left (bitwise opperation).       | shr: (value), (shift)                 |" << endl;
		cout << "| Add3     | Adds three integer values together.                                                    | add3: (value 1), (value 2), (value 3) |" << endl;
		cout << "| Mul3     | Mulitplies three integer values together.                                              | mul: (value 1), (value 2), (value 3)  |" << endl;
		cout << "| Fact     | Takes the factorial of a number.                                                       | fact: (value)                         |" << endl;
		cout << "| Load     | Loads a provided 'script.txt' file and runs any commands found within.                 | load                                  |" << endl;
		cout << "| Adv Load | Loads a provided file path and runs any commands found within.                         | adv load                              |" << endl;
		cout << "| Quit     | Exits code.                                                                            | quit                                  |" << endl;
		cout << "|----------|----------------------------------------------------------------------------------------|---------------------------------------|\n" << endl;
	}

	//If cmd is quit or exit, exits loop thus ending code
	else if (cmd == "quit" || cmd == "exit") {
		exit(0);
	}

	//Any cmd not recognized displays the following
	else {
		cout << "Unknown Command" << endl;
	}

	return 0;
}



//////////// HELPER FUNCTIONS ////////////

//All below are provided in previous codes
EZFileRead::EZFileRead(string filename) {
	ifstream f;
	f.open(filename);
	if (!f.is_open()) {
		cout << "File not successfully opened...operation aborted." << endl;
		return;
	}
	// Read in the file (if there is anything to read)
	string inp;
	while (getline(f, inp))
		v.push_back(inp);
	f.close();
}

size_t EZFileRead::GetNumLines() {
	return v.size();
}

string EZFileRead::GetLine(size_t index) {
	if (index >= v.size())			return "NO SUCH ELEMENT";
	return v.at(index);
}

/* Returns a lower case string */
string strtolower(string str) {
	string ret = str;
	for (size_t i = 0; i < str.size(); i++) {
		ret.at(i) = tolower(str.at(i));
	}
	return ret;
}

/* Returns a string without the leading and trailing whitespace */
string trim(string str) {
	size_t first = str.find_first_not_of(' ');
	if (first == string::npos)
		return "";
	if (string::npos == first)
	{
		return str;
	}
	size_t last = str.find_last_not_of(' ');
	return str.substr(first, (last - first + 1));
}

/* Constructor for Tokenizer */
Tokenizer::Tokenizer(string raw, char delimiter) {
	if (raw.size() == 0)			return;
	size_t start = 0;
	size_t end = 0;
	for (size_t i = 0; i < raw.size(); i++) {
		char c = raw.at(i);
		// Acquire tokens
		if (c == delimiter) {
			end = i;
			size_t len = end - start;
			if (len > 0) {
				string token = raw.substr(start, len);
				tokens.push_back(token);
			}
			start = i + 1;
		}
	}
	// Acquire the final token
	end = raw.size();
	size_t len = end - start;
	if (len > 0) {
		string token = raw.substr(start, len);
		tokens.push_back(token);
	}
}

/* Return how many tokens are in token buffer */
int Tokenizer::GetNumTokens() {
	return (int)tokens.size();
}

/* Returns whether there are any more tokens in buffer */
bool Tokenizer::HasMoreTokens() {
	return tokens.size() != 0;
}

/* Gets the next token available in the token buffer */
string Tokenizer::NextToken() {
	string ret = "NULL";
	if (HasMoreTokens()) {
		ret = tokens.front();
		tokens.erase(tokens.begin());
	}
	return ret;
}
