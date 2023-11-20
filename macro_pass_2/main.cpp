#include<bits/stdc++.h>
using namespace std;

map<string, int> mnt;
vector<string> mdt;
map<string, string> kpdt;

fstream fin;


class Utils{
public:

    static vector<string> split(string line){

        vector<string> result;
        string word = "";

        for(char ch: line){

            if(ch == ',') continue;

            if(ch == ' '){

                result.push_back(word);
                word = "";

            }else{

                word += ch;

            }

        }

        if(word != ""){
            result.push_back(word);
        }

        return result;

    }

    static void getmnt(){
        fstream fin;
        fin.open("mnt.txt", ios::in);

        string line;
        while(getline(fin, line)){

            vector<string> words = split(line);

            mnt[words[0]] = stoi(words[1]);
        }
    }
    static void savemdt(){
        fstream fin;
        fin.open("mdt.txt", ios::in);

        string line;
        while(getline(fin, line)){

            mdt.push_back(line);
            
        }
    }
    static void getkpdt(){
        fstream fin;
        fin.open("kpd.txt", ios::in);

        string line;
        while (getline(fin, line))
        {

            vector<string> words = split(line);

            kpdt[words[0]] = words[1];
        }
    }
    static int extractNumber(string word){
        string number = "";

        for(char ch: word){

            if(ch >= '0' && ch <= '9'){
                number += ch;
            }

        }

        return stoi(number);
    }
};

vector<string> handleMacro(vector<string> firstLine){
    
    vector<string> output;
    
    string macroname = firstLine[0];
    int mdt_index = mnt[macroname];

    vector<string> mdt_macro_first_line = Utils::split(mdt[mdt_index]);

    vector<string> parameters(mdt_macro_first_line.size());

    for(int i=1; i<mdt_macro_first_line.size(); i++){

        string curr = mdt_macro_first_line[i];

        if(kpdt.find(curr) != kpdt.end()){
            parameters[i] = kpdt[curr];
        }else{
            parameters[i] = curr;
        }

    }

    for(int i=1; i<firstLine.size(); i++){
        parameters[i] = firstLine[i];
    }

    for (int i = 1; i < parameters.size(); i++)
    {
        cout << parameters[i] << " ";
    }
    cout << endl;

    cout << "---------------" << endl;

    

    for(int i = mdt_index+1; i<mdt.size(); i++){
        string conversion = "";
        if(mdt[i] == "MEND") return output;

        vector<string> words = Utils::split(mdt[i]);
        conversion += words[0];

        for(int i=1; i<words.size(); i++){
            int idx = Utils::extractNumber(words[i]);
            conversion += " "; 
            conversion += parameters[idx];
        }
        output.push_back(conversion);
    }

   
    return output;

}

int main(){

    fin.open("pass2_input.txt", ios::in);

    fstream fout;
    fout.open("output.txt", ios::out);

    Utils::savemdt();
    Utils::getmnt();
    Utils::getkpdt();

    string line;
    while(getline(fin, line)){

        vector<string> words = Utils::split(line);

        //if line is macro call
        if(mnt.find(words[0]) != mnt.end()){

            vector<string> macro_output = handleMacro(words);

            for(string data: macro_output){
                fout << data << endl;
            }


        }else{

            fout << line << endl;


        }


    }

    


}