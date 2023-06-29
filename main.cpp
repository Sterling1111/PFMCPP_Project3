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

struct Foot
{
    int distance;

    int stepForward();
    int stepSize();
};

int Foot::stepForward()
{
    return stepSize();
}

int Foot::stepSize()
{
    return distance;
}

struct Person 
{
    int age;
    int height;
    float hairLength;
    float GPA;
    unsigned int SATScore;
    int distanceTraveled;
    Foot leftFoot;
    Foot rightFoot;

    int run(bool startWithLeftFoot);

    
};

int Person::run(bool startWithLeftFoot) 
{
    if(startWithLeftFoot == true)
    {
        return leftFoot.stepForward() + rightFoot.stepForward();
    }
    else
    {
        return rightFoot.stepForward() + leftFoot.stepForward();
    }
}



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
    float clockFrequency{4.0f};
    int ramAmount{32};
    int storageAmount{512};
    int numCores{};
    int powerSupplyWattage{550};

    void launchWebBrowser();
    void launchAdobePhotoshop();
    void consumeElectricity();
};

void Computer::launchWebBrowser()
{
    std::cout << "Launching web browser...\n";
}

void Computer::launchAdobePhotoshop()
{
    std::cout << "Launching Adobe Photoshop...\n";
}

void Computer::consumeElectricity()
{
    std::cout << "Consuming electricity...\n";
}

struct Car
{
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

void Car::playMusic()
{
    std::cout << "Playing music...\n";
}

void Car::drive()
{
    std::cout << "Driving...\n";
}

void Car::putFuelInCar(Car::Fuel fuel)
{
    std::cout << "Putting fuel in car from " << fuel.distributer << "...\n";
}

float Car::consumeFuel()
{
    std::cout << "Consuming fuel...\n";
    return 0.0f;  // replace with actual implementation
}

void Car::Fuel::burn()
{
    std::cout << "Burning fuel...\n";
}

void Car::Fuel::smell()
{
    std::cout << "Smelling fuel...\n";
}

void Car::Fuel::flow()
{
    std::cout << "Fuel is flowing...\n";
}

struct CellPhone
{
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

void CellPhone::makeCall()
{
    std::cout << "Making call...\n";
}

void CellPhone::browseWeb()
{
    std::cout << "Browsing web...\n";
}

void CellPhone::playMusic()
{
    std::cout << "Playing music...\n";
}

void CellPhone::changePhoneCase(CellPhone::Case newPhoneCase)
{
    std::cout << "Changing phone case to " << newPhoneCase.brand << "...\n";
}

void CellPhone::Case::wrapPhone()
{
    std::cout << "Wrapping phone...\n";
}

void CellPhone::Case::providePadding()
{
    std::cout << "Providing padding...\n";
}

void CellPhone::Case::preventScratches()
{
    std::cout << "Preventing scratches...\n";
}

struct Screen
{
    std::string brand{"Dell"};
    int refreshRate{75};
    int pixelsX{920};
    int pixelsY{560};
    std::string connectors{"HDMI"};

    void displayImages();
    void adjustColorSettings();
    void adjustRefreshRate();
};

void Screen::displayImages()
{
    std::cout << "Displaying images...\n";
}

void Screen::adjustColorSettings()
{
    std::cout << "Adjusting color settings...\n";
}

void Screen::adjustRefreshRate()
{
    std::cout << "Adjusting refresh rate...\n";
}

struct CPU
{
    float frequency{4.0f};
    int amountCache{20};
    int numCores{10};
    std::string architecture{"x86"};
    int nodeProcessSize{14};

    int addNumbers(int num1, int num2); //returns the result of addition.
    int jump(int offset); //returns the new address after the offset is added to curr address.
    int loadDate(int address); //returns the loaded data after gets from memory.
};

int CPU::addNumbers(int num1, int num2)
{
    return num1 + num2;
}

int CPU::jump(int offset)
{
    return offset;
}

int CPU::loadDate(int address)
{
    return address;
}

struct GraphicsCard
{
    int numCudaCores{4000};
    int numRTCores{72};
    int amountVRAM{8};
    std::string brand{"NVIDIA"};
    float frequency{2.1f};

    void rotateMatrix();    //should take a matrix but not primitive
    void multipleMatrixByScalar(double scalar);
    void multiplyTwoMatrices(); //should take 2 matrices
};

void GraphicsCard::rotateMatrix()
{
    std::cout << "Rotating matrix...\n";
}

void GraphicsCard::multipleMatrixByScalar(double scalar)
{
    std::cout << "Multiplying matrix by " << scalar << " ...\n";
}

void GraphicsCard::multiplyTwoMatrices()
{
    std::cout << "Multiplying two matrices...\n";
}

struct RAM
{
    int numGBs{32};
    int transferRate{3700};
    std::string generation{"DDR4"};
    std::string brand{"Corsair"};
    float cost{124.99f};

    void writeData(int data);
    int readData(int address);  //reads data at given address
    void displayLights();
};

void RAM::writeData(int data)
{
    std::cout << "Writing data " << data << " to RAM...\n";
}

int RAM::readData(int address)
{
    return address; // implementation depends on actual memory management
}

void RAM::displayLights()
{
    std::cout << "Displaying lights...\n";
}

struct MotherBoard
{
    std::string formFactor{"form factor"};
    std::string socketType{"LGA"};
    std::string expansionSlots{"expansion slots"};
    std::string ramSlots{"ram slots"};
    std::string IOPorts{"io ports"};

    void transferDataFromCPUToRAM();
    void transferDataFromGPUToCPU();
    void transferDataFromIOToCPU();
};

void MotherBoard::transferDataFromCPUToRAM()
{
    std::cout << "Transferring data from CPU to RAM...\n";
}

void MotherBoard::transferDataFromGPUToCPU()
{
    std::cout << "Transferring data from GPU to CPU...\n";
}

void MotherBoard::transferDataFromIOToCPU()
{
    std::cout << "Transferring data from IO to CPU...\n";
}


struct PowerSupply
{
    int wattage{550};
    std::string efficientRating{"efficient rating"};
    std::string formFactor{"80+ gold"};
    std::string modularity{"modular"};
    std::string connectors{"connectors"};

    void turnACToDC();
    void provideElectricity();
    void regulateVoltage();
};

void PowerSupply::turnACToDC()
{
    std::cout << "Turning AC to DC...\n";
}

void PowerSupply::provideElectricity()
{
    std::cout << "Providing electricity...\n";
}

void PowerSupply::regulateVoltage()
{
    std::cout << "Regulating voltage...\n";
}

struct Desktop
{
    CPU cpu{};
    GraphicsCard graphicsCard{};
    RAM ram{};
    MotherBoard motherBoard{};
    PowerSupply powerSupply{};

    void runGame(std::string nameOfGameToLaunch);
    void browseWeb();
    void compileCode();
};

void Desktop::runGame(std::string nameOfGameToLaunch)
{
    std::cout << "Running game " << nameOfGameToLaunch << "...\n";
}

void Desktop::browseWeb()
{
    std::cout << "Browsing web...\n";
}

void Desktop::compileCode()
{
    std::cout << "Compiling code...\n";
}

int main()
{
    std::cout << "good to go!" << std::endl;
}
