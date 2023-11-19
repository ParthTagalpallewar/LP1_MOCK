#include<bits/stdc++.h>
using namespace std;

vector<pair<string, int>> mnt; //this table stores name of micro and its address in mdt
vector<string> mdt;
map<string, string> kpd;
fstream fin;

class Utils{
    public:

    static vector<string> split(string line){
        vector<string> words;
        string output = "";

        for(char ch: line){

            if(ch == ' '){
                
                if(output == " ") continue;

                words.push_back(output);
                output = "";
                continue;

            }

            if(ch == ',') continue;

            output += ch;

        }

        if(output != " " && output != ""){
            words.push_back(output);
        }

        return words;


    }
    
    static bool is_default_parameter(string parameter){

        int n = parameter.size();

        //iterate over string is = is found inbetween then its default parameter

        for(int i=0; i<n; i++){

            if(parameter[i] == '='){

                return i < n-1;

            }

        }

        return false;
        


    }

    static vector<string> splitDefaultParameter(string p){

        string keyword = "";
        string value = "";
        bool flag = false;

        for(char ch: p){

            if(ch == '='){
                flag = true;
                continue;
            }

            if(flag){
                value += ch;
            }else{
                keyword += ch;
            }

        }

        return {keyword, value};


    }
};

void handleMacro(){
    
    string line;
    getline(fin, line); // getting first line of macro
    string macroMdtFirstLine = "";
    vector<string> firstLine = Utils::split(line);

    //store macro name and mdt address in mnt
    mnt.push_back({firstLine[0], mdt.size()});

    macroMdtFirstLine += firstLine[0];
    macroMdtFirstLine += " ";

    map<string, int> macro_parameters;

    for(int i=1; i<firstLine.size(); i++){

        string curr_para = firstLine[i];

        if(Utils::is_default_parameter(curr_para)){
            vector<string> default_parameter = Utils::splitDefaultParameter(curr_para);

            string key = default_parameter[0];
            string value = default_parameter[1];

            //store key value pair in kpdt
            kpd[key] = value;
            macro_parameters[key] = i;
            macroMdtFirstLine += key;
            macroMdtFirstLine += " ";
        }else{
            
            macro_parameters[curr_para] = i;
            macroMdtFirstLine += curr_para;
            macroMdtFirstLine += " ";
        }    
    }

    mdt.push_back(macroMdtFirstLine);

    while(getline(fin, line)){

        vector<string> words = Utils::split(line);

        if(words.size() == 1){
            mdt.push_back(words[0]);
            return;
        }

        string output = words[0];
        output += " ";

        for(int i=1; i<words.size(); i++){

            output += "#";
            output += to_string(macro_parameters[words[i]]);
            output += " ";
        }

        mdt.push_back(output);

    }


}

int main(){

    
    fin.open("input.txt", ios::in);

    string line;
    while(getline(fin, line)){
        vector<string> words = Utils::split(line);

        int n = words.size();

        //macro starts here
        if(n == 1 && words[0] == "MACRO"){
            handleMacro();
        }

        if(n == 1 && words[0] == "START"){
            break;
        }
    }

    cout << "MDT Table" << endl;
    for(string data: mdt){
        cout << data << endl;
    }

    

}