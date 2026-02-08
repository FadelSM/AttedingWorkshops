#include<bits/stdc++.h>

using namespace std;

struct Workshop {
    int start_time;
    int duration;
    int end_time;
};

// Struct for all available workshops
struct Available_Workshops {
    int n; // number of workshops
    Workshop* workshops; // dynamic array of workshops
};

// Initialize function
Available_Workshops* initialize(int start_time[], int duration[], int n) {
    Available_Workshops* aw = new Available_Workshops;
    aw->n = n;
    aw->workshops = new Workshop[n];
    
    for(int i = 0; i < n; i++) {
        aw->workshops[i].start_time = start_time[i];
        aw->workshops[i].duration = duration[i];
        aw->workshops[i].end_time = start_time[i] + duration[i];
    }
    
    return aw;
}

// Function to calculate maximum number of non-overlapping workshops
int CalculateMaxWorkshops(Available_Workshops* ptr) {
    // Extract workshops
    vector<Workshop> ws(ptr->workshops, ptr->workshops + ptr->n);
    
    // Sort workshops by end time (greedy approach)
    sort(ws.begin(), ws.end(), [](Workshop a, Workshop b) {
        return a.end_time < b.end_time;
    });
    
    int count = 0;
    int last_end_time = 0;
    
    for(auto w : ws) {
        if(w.start_time >= last_end_time) {
            count++;
            last_end_time = w.end_time;
        }
    }
    
    return count;
}

int main(int argc, char *argv[]) {
    int n; // number of workshops
    cin >> n;
    // create arrays of unknown size n
    int* start_time = new int[n];
    int* duration = new int[n];

    for(int i=0; i < n; i++){
        cin >> start_time[i];
    }
    for(int i = 0; i < n; i++){
        cin >> duration[i];
    }

    Available_Workshops * ptr;
    ptr = initialize(start_time,duration, n);
    cout << CalculateMaxWorkshops(ptr) << endl;
    return 0;
}
