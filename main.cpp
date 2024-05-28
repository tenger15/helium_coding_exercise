/******************************************************************************
Vast Helium-3 Coding Challenge
Todd Enger

Assumptions/Givens:
n - Number of mining trucks
m - Number of mining stations
Mining duration takes from 1 - 5 hours
Travel time between sites is 30 minutes
Unloading mined He3 takes 5 minutes
Trucks are assigned first available station
If all stations are occupied, must wait at the station with the shortest wait time
Simulation time runs for 72 hours

*******************************************************************************/

#include <iostream>
#include <string>

// Class structure of the Mining Site
class Mining_site
{
public: 
    int Site_number = 1;        // Starts at 1
    float Site_location_lat;    // Site latitude in degrees
    float Site_location_long;   // Site longitude in degrees
    float Site_area;            // Measured in km^2
    float Site_depth;           // Max depth in km
    bool Site_occupied = false; // T if truck is present, F if absent
}; 

// Class structure of the Mining truck
class Mining_truck
{
    public:
        int Truck_number = 1;       // Starts at 1
        bool Truck_full = false;    // T if truck is full, F if empty
        float Truck_mining_time;    // Time to mine in hours ranges from 1 - 5
        float Truck_travel_time;    // Time to travel in hours (0.5 for 30 min)
        bool Truck_in_queue;        // True if truck is waiting for a station, F otherwise
};

// Class structure of the Mining station
class Mining_station
{
    public:
        int Station_number = 1;     // Starts at 1
        bool Station_full = false;  // True if the station has a truck being unloaded, F if station is empty
        float Station_load_time;    // Time waiting for an empty station to complete loading (5 min = 0.083 hours)
};

class Mining_output
{
    public:
        Mining_output (int truck_number, int station_number, std::string site_name,
            float sim_time, int He3_mined, float mining_efficiency);
        ~Mining_output();
            
    private:
        int truckNum;
        int stationNum;
        std::string siteName;
        float simDuration;
        int HeliumYield;
        float Eff;
};

// constructor of Mining_output
Mining_output::Mining_output (int truck_number, int station_number, 
    std::string site_name, float sim_time, int He3_mined, float mining_efficiency) 
{
    truckNum = truck_number;
    stationNum = station_number;
    siteName = site_name;
    simDuration = sim_time;
    HeliumYield = He3_mined;
    Eff = mining_efficiency;
    
    /* Example pseudocode for the algorithm
    See charts for example
    1) Truck 3 goes to Site B to start mining and record time and yield in data structure
    2) If there are no trucks there, begin
    3) Truck 3 mines for a random of time from 1 - 5 hours and record loading time in data structure
    4) Once finished, it goes to Station 1
    5) At Station 1, it checks to see if there is another truck waiting to be unloaded
        If a truck is there, go to Station 2, 3, 4, or wait up to 5 minutes and set wait flag
    6) If not, it begins unloading, which takes 5 minutes and record status in data structure
    7) Once complete, it goes back to Site A, B, C, or D until 72 hours
    8) Tally all the yield and time spent in data structures
    */
    
    
}

Mining_output::~Mining_output()
{
    // simulation completed
}

int main()
{
    std::cout<<"This simulation will test the mining output and display results" << std::endl;
    int truckNum = 1;
    int stationNum = 2;
    std::string siteName = "A";
    int simDuration = 72;
    int yield = 0;
    float Eff = 1.00;
    
    for (truckNum = 1; truckNum <=5; truckNum++){
        Mining_output sim(truckNum, stationNum, siteName, simDuration, yield, Eff);
        // Go through many iterations and tally the yield and efficiency
        // Then save results in data structures and/or print to the screen/file
    }


    return 0;
}
