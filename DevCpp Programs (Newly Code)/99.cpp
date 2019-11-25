
#include <iostream>
#include <cstdlib>
#include <cmath>

#define MAX 1000  // max array size
#define Q 1    // quantum time unit to be used by round robin scheduling
#define BUSY 1
#define IDLE 0

using namespace std;

//global variables
struct process_type{
    int pid;
    float BT;
    float AT;
    int priority;
};

struct stat_type{
    int pid;
    float BT;
    float AT;
    int priority;
    float ET;
    float TT;
    float WT;
};

process_type process_list[MAX], ready_q[MAX];
stat_type process_stat[MAX];

float sim_time; // the simulation clock
float next_arrival; //next arrival time
float next_departure; // next departure time
int server_status; //is the cpu busy or idle?
int listsize, qsize; //# of processes in the process list and ready queue
int pid;    // current process id,
int nxt_aps; // process id of next arriving process
int nxt_rps; // process id of next process to use the cpu

//function prototypes
void initialize(float mean_arrival, float mean_burst, int num_process);
void remove_from_list(int idx);
void remove_from_readyq(int idx);
int get_next_arriving_process(int n);
int get_nxt_run_process(int algorithm);
float expon(float mean);
void printstat(int n);


//function definitions
int main(){
    int seed_num = 1;   // used by random-number generator
    int num_process = 0; // number of process using the cpu;
    int required_process = 5;  //number of processes that will use the cpu
    float mean_arrival = 5.0;  //average arrival rate
    float mean_burst = 6.5;    // average cpu burst rate
    int algo = 2;  // algorithm to use: 2 = SJF
    int cpid;      // pid using the cpu
    
    
    srandom(seed_num);  //initialize random number generator
           // change to srand() on windows platform and compiler is not gnu cpp

    
    initialize(mean_arrival, mean_burst, required_process);
    do{
        
        if ((next_arrival < next_departure) && (listsize > 0)){
        //next event is arrival        
        if (server_status == BUSY){
            //if server is busy, enqueue
            sim_time = next_arrival;
                    pid = process_list[nxt_aps].pid;                    
                    cout << "Time = " << sim_time << ". Process " << pid
                         << " arrived. Server is busy. Enqueueing." << endl;
                    ready_q[qsize].pid = process_list[nxt_aps].pid;
                    ready_q[qsize].AT = process_list[nxt_aps].AT;
            ready_q[qsize].BT = process_list[nxt_aps].BT;
            ready_q[qsize].priority = process_list[nxt_aps].priority;            
                    qsize++;
                    remove_from_list(nxt_aps); //remove from process list;
                    //schedule next arrival
                    nxt_aps = get_next_arriving_process(listsize);
                    next_arrival = process_list[nxt_aps].AT;                                        
        }
        else{ // server is IDLE, run process
            // get next arrival
            sim_time = next_arrival;
                    pid = process_list[nxt_aps].pid;
                    cout << "Time = " << sim_time << ". Process " << pid
                         << " arrived. Server is idle." << endl;
                    cout << "          CPU will run process until time = "
                         << sim_time + process_list[nxt_aps].BT << endl;
                    //get statistics data
                    process_stat[pid-1].pid = pid;
                    process_stat[pid-1].BT = process_list[nxt_aps].BT;
                    process_stat[pid-1].AT = process_list[nxt_aps].AT;
                    process_stat[pid-1].priority = process_list[nxt_aps].priority;
                    process_stat[pid-1].WT = 0.0;
                    process_stat[pid-1].ET = sim_time;
                    process_stat[pid-1].TT = process_list[nxt_aps].BT + 0.0;

                    server_status = BUSY;
                    cpid = pid; // pid using the cpu
                    next_departure = sim_time + process_list[nxt_aps].BT;
                    remove_from_list(nxt_aps); //remove from process list;
                    nxt_aps = get_next_arriving_process(listsize);
            next_arrival = process_list[nxt_aps].AT;                                        
        }
        }
        else{
        // next event is departure    
        //if queue is empty,
        if (qsize == 0){
        // wait queue is empty, wait for next arrival
            sim_time = next_departure;
                    cout << "Time = " << sim_time << ". Process " << cpid 
                        << " is finished with the CPU . Ready queue is empty."
                        << endl;
            server_status = IDLE;
                    // make sure that next_arrival is always < next_departure
                    next_departure = 1.0e+30;
        }        
        else{ 
            //get next process from wait queue
            sim_time = next_departure;
                    cout << "Time = " << sim_time << ". Process " << cpid
                         << " is finished with the CPU. " << endl;
                    cout << "      Getting next process from the ready queue."
                         << endl;
                    //run new process in CPU
            nxt_rps = get_nxt_run_process(algo);
                    cpid = ready_q[nxt_rps].pid;
                    cout << "      Running next process: Process "
                         << cpid << "."<< endl;
                    cout << "      CPU will run process until time = "
                         << sim_time + ready_q[nxt_rps].BT << endl;

                    //get statistics data
                    process_stat[cpid-1].pid = ready_q[nxt_rps].pid;
                    process_stat[cpid-1].BT = ready_q[nxt_rps].BT;
                    process_stat[cpid-1].AT = ready_q[nxt_rps].AT;
                    process_stat[cpid-1].priority = ready_q[nxt_rps].priority;
                    process_stat[cpid-1].WT = sim_time - ready_q[nxt_rps].AT;
                    process_stat[cpid-1].ET = sim_time;
                    process_stat[cpid-1].TT = ready_q[nxt_aps].BT + (sim_time - ready_q[nxt_rps].AT);

                    //schedule next departure
            next_departure = sim_time + ready_q[nxt_rps].BT;
            remove_from_readyq(nxt_rps);                    
                }
                num_process++;
        }
        
    }while (num_process < required_process);

        cout << "Simulation Ends." << endl;
        cout << "*******************************" << endl;
        cout << "Simulation Statistics:" << endl;
        printstat(required_process);

    return 0;
}


void initialize(float mean_arrival, float mean_burst, int num_process){
// the initialization function, of course
    int i;
    
    sim_time = 0.0; //initialize simulation clock
        listsize = num_process;
        //initialize process list
    for (i=0; i< num_process; i++){
            process_list[i].pid = i+1;
            process_list[i].AT = expon(mean_arrival);
        process_list[i].BT = expon(mean_burst);
        process_list[i].priority = random();
    }
    // print process list
    for (i=0; i< num_process; i++)
        cout << i+1 << " " << process_list[i].AT << " " <<
        process_list[i].BT << " " <<
        process_list[i].priority << endl;
    cout << "**********************************" << endl;
        cout << "Simulation starts." << endl;
        cout << "Time = 0.0" << endl;
    // get next arrival;
    nxt_aps = get_next_arriving_process(num_process);    
    //schedule next arrival
    next_arrival = sim_time + process_list[nxt_aps].AT;
    //schedule next departure
    next_departure = 1.0e+30;
    qsize = 0;
    server_status = IDLE;
}

void remove_from_list(int idx){
// remove contents of process_list[idx]
    int i;
    for (i=idx+1; i< listsize; i++){
            process_list[i-1].pid = process_list[i].pid;
        process_list[i-1].AT = process_list[i].AT;
        process_list[i-1].BT = process_list[i].BT;
        process_list[i-1].priority = process_list[i].priority;
    }
    listsize--;
}

void remove_from_readyq(int idx){
// remove contents of process_list[idx]
    int i;
    for (i=idx+1; i< qsize; i++){
            ready_q[i-1].pid = ready_q[i].pid;
        ready_q[i-1].AT = ready_q[i].AT;
        ready_q[i-1].BT = ready_q[i].BT;
        ready_q[i-1].priority = ready_q[i].priority;
    }
    qsize--;
}

int get_next_arriving_process(int n){
// return the index with the smallest AT value;
    float min_AT = process_list[0].AT;
    int min_idx = 0;
    int i;// current process id,

    for (i=1; i< n; i++){// current process id,
        if (process_list[i].AT < min_AT){
        min_AT = process_list[i].AT;
        min_idx = i;
        }
    }
    return min_idx;
}

int get_nxt_run_process(int algorithm){
// determines the next process to execute from among the processes in the ready
// queue. The algorithm used determines which process is chosen.
    int i;
    float min_value;
    int  min_idx;
    switch (algorithm){
        case 1: // First Come, First Serverd
        break;
        case 2: // Shortest Job First (Non-preemptive)
        min_value = ready_q[0].BT;
        min_idx = 0;
        for (i= 1; i < qsize; i++){
            if (ready_q[i].BT < min_value){
            min_value = ready_q[i].BT;
            min_idx = i;
            }
        }
        break;
        case 3: // Priority (non-preemptive)
        break;
        case 4: // Round-robin with quantum Q (non-preemptive)
        break;
    }
    return min_idx;
}


float expon(float mean){
// exponential random variate generation 
    float u, x;
    
    // generate a U(0,1) random variate 
    x = random(); 
       // change to rand() on windows platform and compiler is not gnu cpp
    u = x / RAND_MAX;
    
    return (-mean * log(u));
}

void printstat(int n){
    int i;
    float sum_WT, sum_TT;

        sum_WT = 0.0;
        sum_TT = 0.0;
        for (i=0; i < n; i++){
            cout << "PID  = " << process_stat[i].pid << ". ";
            cout << "A.T. = " << process_stat[i].AT << ". ";
            cout << "B.T. = " << process_stat[i].BT << ". ";
            cout << "prio = " << process_stat[i].priority << endl;
            cout << "          E.T. = " << process_stat[i].ET << ". ";
            cout << "W.T. = " << process_stat[i].WT << ". ";
            cout << "T.T. = " << process_stat[i].TT << endl;
            sum_WT = sum_WT + process_stat[i].WT;
            sum_TT = sum_TT + process_stat[i].TT;
        }
        cout << "Average process waiting time = " << sum_WT / n << endl;
        cout << "Average process turnaround time = " << sum_TT / n << endl;

}
