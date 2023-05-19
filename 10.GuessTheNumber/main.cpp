#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){
    // Declaring Variables
    int num = 0;
    int numGet = 0;
    int i = 0;
    int j = 0;
    int winNum[100];    // Storing the number of guesses in each round
    int lossNum = 0;    // Storing the number of lost rounds
    string play = "";
    while(1) // Loop for rounds of play
    {
        i = 0;
        numGet = 0;
        srand(unsigned(time(0)));   // Modifying the seed
        num = (rand() % 100) + 1;   // Generating a random number (0,100)

        while(i <= 5) // Loop for each guess
        {
            if (i == 5)
                {
                    cout << "You Lost!" << endl;
                    lossNum++;
                    break;
                }
            cout << "Number of guesses left: " << (5-i) << endl;
            cout << "Please Enter your number: ";
            cin >> numGet;

            if (numGet > num)
                    cout << "Your number is greater than expected!" << endl;
                else if(numGet < num )
                    cout << "Your number is smaller than expected!" << endl;
                else if (numGet == num)
                {
                    cout << "You guessed it right!" << endl;
                    break;
                }
                else
                    cout << "an error occured!" << endl;
                i++;
        }
        winNum[j] = (5-i);
        j++;
        cout << "\nYou have played " << j << " times." << endl;
        for(int p = 0; p < j; p++)
        {
            if (winNum[p] != 0)
                cout << "\t *In round " << p+1 << " you guessed the number in " << (6 - winNum[p]) << " guesses." << endl;
            else if(winNum[p] == 0)
                cout << "\t *In round " << p+1 << " you didn't guess the number" << endl;
        }
        
        cout << "\nIn total you have won " << (j - lossNum) << " times and lost " << lossNum << " times." << endl;
        cout << "Do you wanna continue playing? (Y/N) ";
        cin >> play;
        if (play == "N" || play == "n")
            break;
        cout << endl;
    }
    return 0;
}