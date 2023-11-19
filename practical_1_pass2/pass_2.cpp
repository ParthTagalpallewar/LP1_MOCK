#include<bits/stdc++.h>
using namespace std;

vector<vector<string>> intermediateCode;

class Utils{
    public:

    static vector<string> split(string line)
    {

        vector<string> result;

        string word = "";

        for (char i : line)
        {

            if (i == ' ')
            {
                result.push_back(word);
                word = "";
            }
            else
            {
                word += i;
            }
        }

        result.push_back(word);

        return result;
    }
};

void handleLine(vector<string> line){

    string output;

    if(line.size() == 1){
        return;
    }

    if(line.size() == 2){
        
    }


}

int main(){

    fstream fin;
    fin.open("intermediate_code.txt", ios::in);

    string line;

    //skip first line
    getline(fin, line);

    while(getline(fin, line)){
        vector<string> myline = Utils::split(line);
    }
    

}