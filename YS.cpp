#include <iostream>


using namespace std;

void repeatedsentence(string words)
{  for(int i =0; i<2; i++){            //if i is same with 2 or greater than 2, then loop will be stopped.
        cout<<words<<endl;             //if not, this function repetedly  prints words.
    }                                   //when the for loop is implemented, add 1 to the i value

}




int main()
{
    repeatedsentence("Hello, World!");     //input parameters and call repeatedsentence function
    repeatedsentence("How are you?");
    return 0;

}
