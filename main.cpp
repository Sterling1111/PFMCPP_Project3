 /*
 Project 3 - Part 2 / 5
 Video: Chapter 2 Part 6
 Implementations tasks
 
Create a branch named Part2

 tasks
 0) delete all of the plain english pseudo-code you added in Part1.
   don't forget to remove the blank lines left behind after you remove your comments
   - you should be left with only your UDTs.
*/
// example:
// if you had something like this at the end of Part1e:
/*
Thing: Car Wash   
    5 properties:
        - number of vacuum cleaners
        - number of eco-friendly cleaning supplies
        - stores the amount of water used per week.
        - stores amount of profit made per week
        - number of cars serviced per day
    3 things it can do:
        - wash and wax car
        - charge customer
        - detail the car interior
 */

#include <iostream>
#include <string>
namespace Part1eVersion 
{
struct CarWash        
{
    //number of vacuum cleaners                     
    int numVacuumCleaners = 3; 
    //number of eco-friendly cleaning supplies      
    int numEcoFriendlyCleaningSupplies = 20;     
    //stores the amount of water used per week.     
    float waterUsedPerWeek = 200.f;            
    //stores amount of profit made per week         
    float profitPerWeek = 495.95f;               
    //number of cars serviced per day               
    int numberOfCarsServiced = 10;               
    
    struct Car  
    {
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        void fillTank(float costPerGallon, double fuelAmountInGallons = 2.0, bool requiresDiesel = false);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    //wash and wax car
    void washAndWaxCar( Car car ); 
    //charge customer
    float chargeCustomer(float discountPercentage);
    //detail the car interior
    void detailInterior( Car car );
    
    Car carBeingServiced;  
};
}

//this is what I want to see after the code is cleaned up: 
namespace Part2Version
{
struct CarWash        
{
    int numVacuumCleaners = 3; 
    int numEcoFriendlyCleaningSupplies = 20;     
    float waterUsedPerWeek = 200.f;            
    float profitPerWeek = 495.95f;               
    int numberOfCarsServiced = 10;               
    
    struct Car  
    {
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        void fillTank(double fuelAmountInGallons = 2.0);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    void washAndWaxCar( Car car ); 
    float chargeCustomer(float discountPercentage);
    void detailInterior( Car car );
    
    Car carBeingServiced;  
};
}
  /*
    The above snippet is just an example showing you how to clean up your code.  
    Do not put your cleaned up code into a namespace like I have done here.

 1) write the definition for the Type that leftFoot and rightFoot are instantiations of.
    don't forget to define and implement the member functions 'stepForward()' and 'stepSize()'
    you should be able to deduce the return type of those functions based on their usage in Person::run()
    You'll need to insert the Person struct from the video in the space below.
 */





 /*
 2) provide implementations for the member functions you declared in your 10 user-defined types from the previous video outside of your UDT definitions.
    If you have 'unused parameter' warnings, you aren't using one of your function parameters in your implementation.
    Solution: use the parameter in your implementation.

    If you have 'shadows a field of <classname>' warnings, a local variable in the function has the same name as a class member.  
    This local variable could also be a function parameter with the same name as the class member.
    Solution: change the local variable's name so it is different from the class member variable's name.
 
 3) be sure to write the correct full qualified name for the nested type's member functions.
 
 4) After you finish defining each type/function, click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 If your code produces -Wconversion warnings, do NOT use static_cast<> to solve the warnings.  
 Casting has not been covered yet.
 Change your code so that no warnings are produced WITHOUT using casting.
 This usually means you have to use identical types for all variables used in an expression that is producing that conversion warning.
 */


struct Computer
{
    /*
     5 properties:
        1) the frequency of processor (float)
        2) the amount of ram (int)
        3) the amount of storage (int)
        4) the number of cores in cpu (int)
        5) power supply wattage (int)
    3 things it can do:
        1) run web browser
        2) run adobe photoshop
        3) consume electricity
    */
    float clockFrequency{4.0f};
    int ramAmount{32};
    int storageAmount{512};
    int numCores{};
    int powerSupplyWattage{550};

    void launchWebBrowser();
    void launchAdobePhotoshop();
    void consumeElectricity();
};

struct Car
{
    /*
     5 properties:
        1) the color of the car (string)
        2) the horsepower (int)
        3) the cost (float)
        4) the brand (string)
        5) the year (int)
    3 things it can do:
        1) play music
        2) drive
        3) consume fuel
     */

    struct Fuel
    {
        int octaneRating{91};
        float costPerGallon{4.55f};
        std::string CountryOfOrigin{"Saudi Arabia"};
        std::string distributer{"Shell"};
        std::string color{"clear"};

        void burn();
        void smell();
        void flow();
    };

    int runWebBrowser(); //returns exit code of application
    int runAdobePhotoshop(); //returns exit code of application
    int consumeElectricity(); //returns amount of energy consumed in watt hours

    std::string carColor{"white"};
    int horsePower{200};
    float cost{32'000.f};
    std::string brand{"Honda"};
    int year{1997};

    void playMusic();
    void drive();
    void putFuelInCar(Fuel fule);
    float consumeFuel(); // return the fuel consumed in gallon

};

struct CellPhone
{
    /*
     5 properties:
        1) the color of the Phone (string)
        2) the data provider for the phone (string)
        3) the brand of the phone (string)
        4) the processor of the phone (string)
        5) the amount of ram of phone (int)
    3 things it can do:
        1) make calls
        2) browse web
        3) play music
     */

    struct Case
    {
        std::string color{"black"};
        std::string brand{"Spigen"};
        float cost{12.99f};
        std::string features{"kickstand"};
        bool isPadded{true};

        void wrapPhone();
        void providePadding();
        void preventScratches();
    };

    std::string color{"blue"};
    std::string dataProvider{"AT&T"};
    std::string brand{"Samsung"};
    std::string processor{"Qualcomm 865"};
    int ramAmount{12};

    void makeCall();
    void browseWeb();
    void playMusic();

    void changePhoneCase(Case phoneCase);
};

struct Screen
{
    /*
     5 properties:
        1) brand (string)
        2) refresh rate (int)
        3) pixels x (int)
        4) pixels y (int)
        5) connectors (string)
    3 things it can do:
        1) display images
        2) adjust color settings
        3) adjust refresh rate
     */

    std::string brand{"Dell"};
    int refreshRate{75};
    int pixelsX{920};
    int pixelsY{560};
    std::string connectors{"HDMI"};

    void displayImages();
    void adjustColorSettings();
    void adjustRefreshRate();
};

struct CPU
{
    /*
     5 properties:
        1) frequency in GHz (float)
        2) cache in Mb (int)
        3) number of cores (int)
        4) architecture (string)
        5) size of process in nm (int)
    3 things it can do:
        1) add numbers
        2) jump
        3) load data
     */

    float frequency{4.0f};
    int amountCache{20};
    int numCores{10};
    std::string architecture{"x86"};
    int nodeProcessSize{14};

    int addNumbers(int num1, int num2); //returns the result of addition.
    int jump(int offset); //returns the new address after the offset is added to curr address.
    int loadDate(int address); //returns the loaded data after gets from memory.
};

struct GraphicsCard
{
    /*
     5 properties:
        1) Cuda cores (int)
        2) RT cores (int)
        3) VRAM (int)
        4) brand (string)
        5) frequency in Ghz (float)
    3 things it can do:
        1) vector operations
        2) matrix operations
        3) texture operations
     */

    int numCudaCores{4000};
    int numRTCores{72};
    int amountVRAM{8};
    std::string brand{"NVIDIA"};
    float frequency{2.1f};

    void rotateMatrix();    //should take a matrix but not primitive
    void multipleMatrixByScalar(double scalar);
    void multiplyTwoMatrices(); //should take 2 matrices
};

struct RAM
{
    /*
     5 properties:
        1) quantity in GBs (int)
        2) transfer rate (int)
        3) generation (string)
        4) brand (string)
        5) cost (float)
    3 things it can do:
        1) write values
        2) read values
        3) display rgb lights
     */

    int numGBs{32};
    int transferRate{3700};
    std::string generation{"DDR4"};
    std::string brand{"Corsair"};
    float cost{124.99f};

    void writeData(int data);
    int readData(int address);  //reads data at given address
    void displayLights();
};

struct MotherBoard
{
    /*
     5 properties:
        1) Form factor (string)
        2) socket type (string)
        3) expandison slots (string)
        4) ram slots (string)
        5) i/o ports (string)
    3 things it can do:
        1) transfer data from cpu to ram
        2) transfer data from gpu to cpu
        3) transfer data from io ports to cpu
     */

    std::string formFactor{"form factor"};
    std::string socketType{"LGA"};
    std::string expansionSlots{"expansion slots"};
    std::string ramSlots{"ram slots"};
    std::string IOPorts{"io ports"};

    void transferDataFromCPUToRAM();
    void transferDataFromGPUToCPU();
    void transferDataFromIOToCPU();
};

struct PowerSupply
{
    /*
     5 properties:
        1) wattage (int)
        2) efficiency rating (string)
        3) form factor (string)
        4) modularity (string)
        5) connectors (string)
    3 things it can do:
        1) turn ac into dc
        2) provide electricity to components
        3) regulate voltage
     */

    int wattage{550};
    std::string efficientRating{"efficient rating"};
    std::string formFactor{"80+ gold"};
    std::string modularity{"modular"};
    std::string connectors{"connectors"};

    void turnACToDC();
    void provideElectricity();
    void regulateVoltage();
};

struct Desktop
{
    /*
     5 properties:
        1) CPU
        2) Graphics Card
        3) RAM
        4) Motherboard
        5) Power Supply
    3 things it can do:
        1) gaming
        2) web browsing
        3) code compile
     */

    CPU cpu{};
    GraphicsCard graphicsCard{};
    RAM ram{};
    MotherBoard motherBoard{};
    PowerSupply powerSupply{};

    void runGame(std::string nameOfGameToLaunch);
    void browseWeb();
    void compileCode();
};

int main()
{
    std::cout << "good to go!" << std::endl;
}
