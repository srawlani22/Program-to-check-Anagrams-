#include <iostream>// included a standard c++ library
#include <string>// included the string library to capture the string input
using namespace std;
// references: geeksforgeeks and help from Nora Riches

void removeSpace(string example);// defined both the functions globally.
bool anagramCheck(string check1, string check2);

int main(){
    string example1 = "listen";// considered two strigs as examples of anagrams, these don't have spaces, but the code also works with the strings having spaces
    string example2 = "silent";

    cout << "The two strings that would be tested are: " << example1 << " and " << example2 << endl;// the two strings are displayed

    if(anagramCheck(example1, example2)==true){// if the two strings are anagrams, the condition is true otherwise not, the anagram function checks if the example strings are anagrams or not
        cout << "The two strings are anagrams of each other" << endl;
    }
    else{// an if else statement is the best way to display the outcomes of two different situations.
        cout <<"The two strings are not the anagrams of each other" << endl;
    }

    return 0;
}

//function removeSpace
// the function removes spaces between the strings so that the spaces aren't counted between the characters of the string, my example has no spaces, but it also works with strings with spaces
//Input: an string example from which all the spaces are removes(if there are any)
//output: the same string comes out, but spaces are not counted while checking for anagrams
void removeSpace(string example){
    for(int i=0; i<=example.size(); i++){// a for loop keeps checking the entire string for spaces and cleares based on their iterated position if there are any
        if(example[i]==' '){
            example.erase(i,1);// spaces are erased if their are any, any if statement checks for spaces first and then removes it.
        }
    }
}

// function anagramCheck
// checks if an string is the anagram of aother string
// Input: two strings that will be passed from the main function
//Output: Tells whether the strings are anagrams of each other or not. If yes, retyrn true otherwise returns false.
bool anagramCheck(string check1, string check2){

    removeSpace(check1);// initially the spaces are removed from both the strings and then they are checked for anagrams
    removeSpace(check2);

    int num1=0; // declared two integers, the first one needs to be zero because it will be hold all the characters of all strings and will be incremented
    int num2;// the second one will be indexed as a bunch of characters in the two strings

    for(int i=0; i<=check1.size(); i++){// a for loop goes through the first string, checks its size and finds the same characters using the find() keyword of c++
        num2=check2.find(check1[i]);// finds the same characters

        if(num2 != -1){// in case the indexing of the second string goes away, the if statement checks for it and removes the spaces 
            check2.erase(num2,1);
            num1++;// the first integer gets incremented at last
        }
    }

    if(check2=="" && num1==check1.size()){// finally if their are no spaces in second string and the first string's size and characters are same as the second one, the function returns true, else returns false
        return true;
    }
    else{
        return false;
    }
}