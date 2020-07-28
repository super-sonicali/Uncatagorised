//Import modules
#include <iostream>
#include <string>
#include <algorithm> //Module to convert string to uppercase
#include < windows.h> //Module to allow the opening of a webpage
using namespace std;

//Define variables
//Array of characters that is used for encrypting/decrypting the user input
char alpha[52] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z','A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
//The input from the user
char rawInput[140];
//The upper case version of the user input
char unencryptedData[140];
//Define functions
char getInput(); //Gets input from the user
char Encryption(char encrypt[140], char unencryptedData[140]); //Function to encrypt an array of characters and return encrypted array
char Decryption(char decrypt[140], char unencryptedData[140]); //Function to decrypt an array of characters and return unencrypted array
char inputValidation(); //Function to check if the input is valid
void instructions(); //Function to display instructions to the user
void magicBehindTheScenes();//Function that displays how it works

int main()
{
	//Define Functions
	char encrypt[140] = {}; //The encrypted data
	char decrypt[140] = {}; //The decrypted data
	
	//Define variables
	string data; //Temporarily store the user's input so that it can be converted to upper case
	int end; //Stores the length of the string that the user inputted
	char choice; //Stores a character that the user has entered to decide whether to encrypt/decrypt

	//Calls a function to display instructions to the user
	instructions();

	//Tells the user what to input
	cout << "If decrypting press 'D'" << endl << "If encrypting press 'E'" << endl;
	choice = inputValidation(); //checks user input

	//Tells the user to input string to be encrypted/decrypted 
	cout << "Input: " << endl;

	//gets said input from user
	rawInput[140] = getInput();
	
	//If statement to encrypt/decrypt based on the user's choice
	if (choice == 'E')
	{
		//Set the array "rawInput" to a string so it can be converted to uppercase
		data = rawInput;
		//Convert the string to uppercase
		transform(data.begin(), data.end(), data.begin(), ::toupper);

		//Find out the length of the string
		end = data.length();
		//For loop to convert the string back to an array of characters
		for (int i = 0; i < end; i++)
		{
			//Set the next space in the array to the first character in the string
			unencryptedData[i] = data[0];
			//Reduce the string by one character
			data = data.substr(1, end);
		}

		//Calling a function to encrypt an array of characters and store as an array
		encrypt[140] = Encryption(encrypt, unencryptedData);

		//clear display
		system("cls");

		//For loop to display the encrypted data
		for (int index = 0; index < 140; index++)
		{
			//Display the next character in the encrypted data
			cout << encrypt[index];
		}
	}//Else If
	else if (choice == 'D')
	{
		//Set the array "rawInput" to a string so it can be converted to uppercase
		data = rawInput;
		//Convert the string to uppercase
		transform(data.begin(), data.end(), data.begin(), ::toupper);

		//Find out the length of the string
		end = data.length();
		
		//For loop to convert the string back to an array of characters
		for (int i = 0; i < end; i++)
		{
			//Set the next space in the array to the first character in the string
			unencryptedData[i] = data[0];
			//Reduce the string by one character
			data = data.substr(1, end);
		}

		//Calling a function to decrypt an array of characters and store as an array
		decrypt[140] = Decryption(decrypt, unencryptedData);

		//clear display
		system("cls");

		//For loop to display the decrypted data
		for (int index = 0; index < 140; index++)
		{
			//Display the next character in the decrypted data
			cout << decrypt[index];
		}
	}//else if 
	//Function displays how the magic work
	magicBehindTheScenes();
	//Code to open the webpage for the pseudocode
	ShellExecute(NULL, L"open", L"[YOUR_WEBPAGE_HERE]", NULL, NULL, SW_SHOWNORMAL);
	system("pause");
	return 0;
}//main

//Function to encypt data
char Encryption(char encrypt[140], char upperCaseInput[140]) {
	//Define variables
	int key = 0;  //Stores the cipher key

	//Display a message to the user to tell them to enter cipher key
	cout << "\nPlease enter the cipher key: ";
	//Recieve input from the user
	cin >> key;
	//If statment to deal with errors
	if ((key == 0) || (key > 26) || (key < -26)) {
		//Clear the input
		cin.clear();
		//Ignore the characters that were previously inputted
		cin.ignore(1000, '\n');
		//Tell the user what is wrong
		cout << "Unusable cipher key.\n";
		//Return a function call so that the function is called again and the user gets another chance to input the cipher key
		return Encryption(encrypt, upperCaseInput);
	}
	//Change the cipher key to a constant so that it can be used to index the array of the alphabet
	const int(int(key));
	//For loop to encrypt the data
	for (int counter = 0; counter < 140; counter++)
	{
		//If statment to move the alphabet the correct way
		if (key > 0) {
			//Switch statment to store the ammended letter
			switch (upperCaseInput[counter]) {
			case 'A': encrypt[counter] = alpha[26 - key]; break;
			case 'B': encrypt[counter] = alpha[27 - key]; break;
			case 'C': encrypt[counter] = alpha[28 - key]; break;
			case 'D': encrypt[counter] = alpha[29 - key]; break;
			case 'E': encrypt[counter] = alpha[30 - key]; break;
			case 'F': encrypt[counter] = alpha[31 - key]; break;
			case 'G': encrypt[counter] = alpha[32 - key]; break;
			case 'H': encrypt[counter] = alpha[33 - key]; break;
			case 'I': encrypt[counter] = alpha[34 - key]; break;
			case 'J': encrypt[counter] = alpha[35 - key]; break;
			case 'K': encrypt[counter] = alpha[36 - key]; break;
			case 'L': encrypt[counter] = alpha[37 - key]; break;
			case 'M': encrypt[counter] = alpha[38 - key]; break;
			case 'N': encrypt[counter] = alpha[39 - key]; break;
			case 'O': encrypt[counter] = alpha[40 - key]; break;
			case 'P': encrypt[counter] = alpha[41 - key]; break;
			case 'Q': encrypt[counter] = alpha[42 - key]; break;
			case 'R': encrypt[counter] = alpha[43 - key]; break;
			case 'S': encrypt[counter] = alpha[44 - key]; break;
			case 'T': encrypt[counter] = alpha[45 - key]; break;
			case 'U': encrypt[counter] = alpha[46 - key]; break;
			case 'V': encrypt[counter] = alpha[47 - key]; break;
			case 'W': encrypt[counter] = alpha[48 - key]; break;
			case 'X': encrypt[counter] = alpha[49 - key]; break;
			case 'Y': encrypt[counter] = alpha[50 - key]; break;
			case 'Z': encrypt[counter] = alpha[51 - key]; break;
			case ' ': encrypt[counter] = ' '; break;
			}//switch
		}//if
		//Else if part of if statment to move the alphabet the correct way
		else if (key < 0) {
			//Switch statment to store the ammended letter
			switch (upperCaseInput[counter]) {
			case 'A': encrypt[counter] = alpha[0 - key]; break;
			case 'B': encrypt[counter] = alpha[1 - key]; break;
			case 'C': encrypt[counter] = alpha[2 - key]; break;
			case 'D': encrypt[counter] = alpha[3 - key]; break;
			case 'E': encrypt[counter] = alpha[4 - key]; break;
			case 'F': encrypt[counter] = alpha[5 - key]; break;
			case 'G': encrypt[counter] = alpha[6 - key]; break;
			case 'H': encrypt[counter] = alpha[7 - key]; break;
			case 'I': encrypt[counter] = alpha[8 - key]; break;
			case 'J': encrypt[counter] = alpha[9 - key]; break;
			case 'K': encrypt[counter] = alpha[10 - key]; break;
			case 'L': encrypt[counter] = alpha[11 - key]; break;
			case 'M': encrypt[counter] = alpha[12 - key]; break;
			case 'N': encrypt[counter] = alpha[13 - key]; break;
			case 'O': encrypt[counter] = alpha[14 - key]; break;
			case 'P': encrypt[counter] = alpha[15 - key]; break;
			case 'Q': encrypt[counter] = alpha[16 - key]; break;
			case 'R': encrypt[counter] = alpha[17 - key]; break;
			case 'S': encrypt[counter] = alpha[18 - key]; break;
			case 'T': encrypt[counter] = alpha[19 - key]; break;
			case 'U': encrypt[counter] = alpha[20 - key]; break;
			case 'V': encrypt[counter] = alpha[21 - key]; break;
			case 'W': encrypt[counter] = alpha[22 - key]; break;
			case 'X': encrypt[counter] = alpha[23 - key]; break;
			case 'Y': encrypt[counter] = alpha[24 - key]; break;
			case 'Z': encrypt[counter] = alpha[25 - key]; break;
			case ' ': encrypt[counter] = ' '; break;
			}//switch
		}//else
	}//for loop
	//return the encrypted array
	return encrypt[140];
}//char

//Function to decrypt data
char Decryption(char decrypt[140], char upperCaseInput[140]) {
	//Define variables
	int key = 0; //Stores  the cipher key

	//Display a message to the user to tell them what to do
	cout << "\nPlease enter the cipher key: ";
	//Recieve input from the user
	cin >> key;
	//If statment to deal with errors
	if ((key == 0) || (key > 26) || (key < -26)) {
		//Clear the input
		cin.clear();
		//Ignore the characters that were previously inputted
		cin.ignore(1000, '\n');
		//Tell the user what is wrong
		cout << "Unusable cipher key.\n";
		//Return a function call so that the function is called again and the user gets another chance to input the cipher key
		return Decryption(decrypt, upperCaseInput);
	}
	//Change the cipher key to a constant so that it can be used to index the array of the alphabet
	const int(int(key));
	//For loop to encrypt the data
	for (int counter = 0; counter < 140; counter++)
	{
		//If statment to move the alphabet the correct way
		if (key < 0) {
			//Switch statment to store the ammended letter
			switch (upperCaseInput[counter]) 
			{
			case 'A': decrypt[counter] = alpha[26 + key]; break;
			case 'B': decrypt[counter] = alpha[27 + key]; break;
			case 'C': decrypt[counter] = alpha[28 + key]; break;
			case 'D': decrypt[counter] = alpha[29 + key]; break;
			case 'E': decrypt[counter] = alpha[30 + key]; break;
			case 'F': decrypt[counter] = alpha[31 + key]; break;
			case 'G': decrypt[counter] = alpha[32 + key]; break;
			case 'H': decrypt[counter] = alpha[33 + key]; break;
			case 'I': decrypt[counter] = alpha[34 + key]; break;
			case 'J': decrypt[counter] = alpha[35 + key]; break;
			case 'K': decrypt[counter] = alpha[36 + key]; break;
			case 'L': decrypt[counter] = alpha[37 + key]; break;
			case 'M': decrypt[counter] = alpha[38 + key]; break;
			case 'N': decrypt[counter] = alpha[39 + key]; break;
			case 'O': decrypt[counter] = alpha[40 + key]; break;
			case 'P': decrypt[counter] = alpha[41 + key]; break;
			case 'Q': decrypt[counter] = alpha[42 + key]; break;
			case 'R': decrypt[counter] = alpha[43 + key]; break;
			case 'S': decrypt[counter] = alpha[44 + key]; break;
			case 'T': decrypt[counter] = alpha[45 + key]; break;
			case 'U': decrypt[counter] = alpha[46 + key]; break;
			case 'V': decrypt[counter] = alpha[47 + key]; break;
			case 'W': decrypt[counter] = alpha[48 + key]; break;
			case 'X': decrypt[counter] = alpha[49 + key]; break;
			case 'Y': decrypt[counter] = alpha[50 + key]; break;
			case 'Z': decrypt[counter] = alpha[51 + key]; break;
			case ' ': decrypt[counter] = ' '; break;
			}//switch
		}//if
		 //Else part of if statment to move the alphabet the correct way
		else if (key > 0) 
		{
			//Switch statment to store the ammended letter
			switch (upperCaseInput[counter]) 
			{
			case 'A': decrypt[counter] = alpha[0 + key]; break;
			case 'B': decrypt[counter] = alpha[1 + key]; break;
			case 'C': decrypt[counter] = alpha[2 + key]; break;
			case 'D': decrypt[counter] = alpha[3 + key]; break;
			case 'E': decrypt[counter] = alpha[4 + key]; break;
			case 'F': decrypt[counter] = alpha[5 + key]; break;
			case 'G': decrypt[counter] = alpha[6 + key]; break;
			case 'H': decrypt[counter] = alpha[7 + key]; break;
			case 'I': decrypt[counter] = alpha[8 + key]; break;
			case 'J': decrypt[counter] = alpha[9 + key]; break;
			case 'K': decrypt[counter] = alpha[10 + key]; break;
			case 'L': decrypt[counter] = alpha[11 + key]; break;
			case 'M': decrypt[counter] = alpha[12 + key]; break;
			case 'N': decrypt[counter] = alpha[13 + key]; break;
			case 'O': decrypt[counter] = alpha[14 + key]; break;
			case 'P': decrypt[counter] = alpha[15 + key]; break;
			case 'Q': decrypt[counter] = alpha[16 + key]; break;
			case 'R': decrypt[counter] = alpha[17 + key]; break;
			case 'S': decrypt[counter] = alpha[18 + key]; break;
			case 'T': decrypt[counter] = alpha[19 + key]; break;
			case 'U': decrypt[counter] = alpha[20 + key]; break;
			case 'V': decrypt[counter] = alpha[21 + key]; break;
			case 'W': decrypt[counter] = alpha[22 + key]; break;
			case 'X': decrypt[counter] = alpha[23 + key]; break;
			case 'Y': decrypt[counter] = alpha[24 + key]; break;
			case 'Z': decrypt[counter] = alpha[25 + key]; break;
			case ' ': decrypt[counter] = ' '; break;
			}//switch
		}//else
	}//for loop
	//return the dencrypted array
	return decrypt[140];
}//char

//Function to get raw input from the user
char getInput()
{
	//Get input from the user
	cin.getline(rawInput, 140);
	//Confirm input by displaying it
	cout << rawInput << endl;
	//Return the raw input
	return rawInput[140];
}

//Checks that the first letter is valid 
char inputValidation()
{
	char letters[140]; //Stores input from the user
	string data; //Temporarily stores the input from the user so that it can be converted to upper case

	//Get input from the user
	cin.getline(letters, 140);
	//Store as a string to make converting it to upper case easier
	data = letters;
	//Use a predefined function to convert the string to uppper case
	transform(data.begin(), data.end(), data.begin(), ::toupper);
	//If statment to check if the first letter of the string is correct and ignore the rest
	if ((data[0] == 'E') || (data[0] == 'D')) {
		//Return the first letter
		return data[0];
	}
	//Else part of if statment to re-get input from the user
	else
	{
		//Return a function call to recursively call the function
		return inputValidation();
	}
}//char

 //Function to display instructions to the user
void instructions()
{
	cout << "\n\n\tInstructions\n\n" << endl;
	cout << "1. Decide whether you wish to encrypt or decrypt text." << endl;
	cout << "2. Input 'E' or 'D' as appropriate." << endl;
	cout << "3. Input the text you want to be encrypted/decrypted. (character limit of 140 letters and spaces)" << endl;
	cout << "4. Input the cipher key" << endl;
	cout << "(the number of places you want the alphabet to be shifted, this has a range of - 25 to 25 not including 0)" << endl;
	cout << "5. Wait for the magic to happen!" << endl;
	cout << "6. View your encrypted/decrypted message." << endl << endl;
}

//Function to display behind the magic
void magicBehindTheScenes()
{
	cout << "\n\n\tBehind the Magic\n\n" << endl;
	cout << "The user states whether they are encrypting or decrypting." << endl;
	cout << "The user inputs an array of characters (char rawInput[140])." <<endl;
	cout << "This is then displayed to confirm the input" << endl;;
	cout << "The user enters a cipher key." << endl;
	cout << "The screen is then cleared" << endl;
	cout << "The array is converted into uppercase text." << endl << endl;
	cout << "For Encryption:" << endl;
	cout << "\tThey array is fed through the machine of ciphers" << endl;
	cout << "\t(char[] --> string --> upper --> char[])." << endl;
	cout << "\tThe array is encrypted by shifting the characters to either the left" << endl;
	cout << "\tor the right by the cipher key (+ve right, -ve left)" << endl;
	cout << "\tThe encrypted array is then displayed" << endl << endl;
	cout << "For Deryption:" << endl;
	cout << "\tThey array is fed through the machine of ciphers" << endl;
	cout << "\t(char[] --> string --> upper --> char[])." << endl;
	cout << "\tThe array is decrypted by shifting the characters to either the left" << endl;
	cout << "\tor the right by the cipher key (+ve right, -ve left)" << endl;
	cout << "\tThe decrypted array is then displayed" << endl << endl << endl;
}