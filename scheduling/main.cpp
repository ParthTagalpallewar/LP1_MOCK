#include<bits/stdc++.h>
using namespace std;

class Process{
public:
    string name;
    int arrival_time;
    int burst_time;
    int completion_time;
    int turn_around_time;
    int waiting_time;

    Process(){
        cout << "Enter Name of Process ";
        cin >> this->name;

        cout << "Enter Arrival Time ";
        cin >> this->arrival_time;

        cout << "Enter Burst Time ";
        cin >> this->burst_time;
        this->completion_time = 0;
        this->turn_around_time = 0;
        this->waiting_time = 0;

        cout << endl;
    }

    void calculate_turn_around_time(){
        this->turn_around_time = this->completion_time - this->arrival_time;
    }

    void calculate_waiting_time(){
        this->waiting_time = this->turn_around_time - this->burst_time;
    }

    void print(){
        cout << name << " " << arrival_time << " " << burst_time << " " << completion_time << " " << turn_around_time << " " << waiting_time << endl;
    }

    
};

class Scheduling{
public:

    vector<Process*> processes;
    int n = 0;

    Scheduling(){

        cout << "Enter Number of Processes  ";
        cin >> n;

        for(int i=0; i<n; i++){
            Process* process = new Process();
            processes.push_back(process);
        }
        
    }

    void swap(int i, int j){

        if(i == j) return;

        Process* temp = processes[j];
        processes[j] = processes[i];
        processes[i] = temp;

    }

    void sort_processes(){

        for(int i=0; i<n; i++){

            int min = i;

            for(int j = i+1; j < n; j++){

                if(processes[j]->arrival_time < processes[min]->arrival_time){
                    min = j;
                }

            }

            swap(i, min);

        }

    }

    void fcfs(){

        sort_processes();

        processes[0]->completion_time = processes[0]->burst_time + processes[0]->arrival_time;

        for(int i=1; i<n; i++){

            Process* prev = processes[i-1];
            Process* curr = processes[i];

            if(prev->completion_time >= curr->arrival_time){
                curr->completion_time = prev->completion_time + curr->burst_time;
            }else{
                int waiting_time = curr->arrival_time - prev->completion_time;
                cout << "waiting time is " << waiting_time << endl;
                curr->completion_time = prev->completion_time + waiting_time + curr->burst_time;
            }

        }

        for(Process* process: processes){
            process->calculate_turn_around_time();
            process->calculate_waiting_time();
            process->print();
        }

        
    }

};

int main(){

    Scheduling scheduling;
    scheduling.fcfs();



}