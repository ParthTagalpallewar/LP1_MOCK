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

    Process(int burst_time){
        this->burst_time = burst_time;
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

    //sort processes according to arrival time
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

    void sjf(){

        //sort process according to arrival time
        sort_processes();
        int timer = 0;
        int completed_processes = 0;

        while(completed_processes < n){

            //choose process who have arrival time <= timer and min burst time != 0
            Process* curr = new Process(99999);
            for(Process* process: processes){
                if(process->arrival_time <= timer && process->burst_time != 0 && process->burst_time < curr->burst_time){
                    curr = process;
                }
               
            }
            curr->burst_time -= 1;

            if (curr->burst_time == 0)
            {
                curr->completion_time = timer + 1;
                completed_processes += 1;
            }
            timer += 1;
        }

        for (Process *process : processes)
        {
            process->calculate_turn_around_time();
            process->calculate_waiting_time();
            process->print();
        }
    }

    
};

int main(){

    Scheduling scheduling;
   scheduling.sjf();
    // for(Process* p: scheduling.processes){
    //     cout << p->name << " " << p->arrival_time << " " << p->burst_time << endl;
    // }


}