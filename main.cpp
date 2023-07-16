/*
 Project 3 - Part 5 / 5
 video: Chapter 2 - Part 10
 Scope and Lifetime tasks
 
Create a branch named Part5

 video covered:
    variable scope and lifetime relative to { }
    while loops
    for loops()
 
 tasks
 
 1) add some new member functions to EACH of your types. 
 
 2) inside these new member functions, use while() and for() loops to do something interesting 
         a) example: have a loop that modifies a member variable of some object created outside the loop.
         b) when that member variable reaches a certain threshold, return it mid-loop.
         c) maybe use function parameters to control the starting value of that member variable or control the threshold
         
 3) call those new member functions in main()
 
 4) use std::cout statements to print out information about what your loops did.
    Your code should produce a lot of console output now.

 5) Remember to use pre-increment/decrement in your loops. 
 You can learn why post-increment/decrement is not ideal here:
 https://en.cppreference.com/w/cpp/language/operator_incdec 
 
 6) click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 */

#include <iostream>
namespace Example 
{
struct Bar 
{ 
    int num = 0; 
    Bar(int n) : num(n) { } 
};
struct Foo
{
    Bar scopeLifetimeFunc( int threshold, int startingVal ) //1), 2c) 
    {
        Bar bar(startingVal);                //2a)
        while( bar.num < threshold )         //2a) 
        { 
            ++bar.num;                    //2a), 5)
            std::cout << "  increasing bar.num: " << bar.num << std::endl; //4)
            if( bar.num >= threshold )       //2b)
                return bar;
        }
        
        return Bar {-1}; //if your startingValue >= threshold, the while loop never runs
    }
};

int main()
{
    Foo foo;
    auto bar = foo.scopeLifetimeFunc(3, 1);        //3) 
    
    std::cout << "bar.num: " << bar.num << std::endl;     //4) 
    return 0;
}
}

//call Example::main() in main()





struct Computer
{
    Computer();

    float clockFrequency{4.0f};
    int ramAmount;
    int storageAmount{512};
    int numCores{};
    int powerSupplyWattage{550};

    void launchWebBrowser();
    void launchAdobePhotoshop();
    void consumeElectricity();

    int allocateMemory(int);
};

Computer::Computer() : ramAmount{16}
{
    std::cout << "Computer being constructed" << std::endl;
}

void Computer::launchWebBrowser()
{
    std::cout << clockFrequency << " " << ramAmount << std::endl;
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

int Computer::allocateMemory(int memory)
{
    int allocatedMemory{0};
    
    while( allocatedMemory != memory && ramAmount > 0)
    {
        std::cout << "Allocated memory: " << ++allocatedMemory << std::endl;
        --ramAmount;
    }

    return allocatedMemory;
}

struct Car
{
    Car();

    struct Fuel
    {
        Fuel();

        int octaneRating;
        float costPerGallon{4.55f};
        std::string CountryOfOrigin{"Saudi Arabia"};
        std::string distributer{"Shell"};
        std::string color{"clear"};

        void burn();
        void smell();
        void flow();

        float buyGas(float);
    };

    std::string carColor;
    int horsePower{200};
    float cost{32'000.f};
    std::string brand{"Honda"};
    int year{1997};

    void playMusic();
    void drive();
    void putFuelInCar(Fuel fule);
    float consumeFuel(); // return the fuel consumed in gallon

};

Car::Car() : carColor{"green"}
{
    std::cout << "Car being constructed" << std::endl;
}

void Car::playMusic()
{
    std::cout << "Playing music...\n";
}

void Car::drive()
{
    std::cout << carColor << std::endl;
    std::cout << "Driving...\n";
}

void Car::putFuelInCar(Car::Fuel fuel)
{
    std::cout << "Putting fuel in car from " << fuel.distributer << "...\n";
}

float Car::consumeFuel()
{
    for(int i = 0; i < 5; ++i)
    {
        std::cout << "Consuming " << i << " gallons of fuel" << std::endl;
    }
    std::cout << "Consuming fuel...\n";
    return 5.0f;  // replace with actual implementation
}

Car::Fuel::Fuel() : octaneRating{98}
{
    std::cout << "Fuel being constructed" << std::endl;
}

void Car::Fuel::burn()
{
    std::cout << octaneRating << std::endl;
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

float Car::Fuel::buyGas(float gallons)
{
    for(float i = 1; i <= gallons; i++)
    {
        std::cout << "Total cost after gallon " << i << ": " << i * costPerGallon << std::endl; 
    }
    return costPerGallon * gallons;
}

struct CellPhone
{
    CellPhone();

    struct Case
    {
        Case();

        std::string color;
        std::string brand{"Spigen"};
        float cost{12.99f};
        std::string features{"kickstand"};
        bool isPadded{true};

        void wrapPhone();
        void providePadding();
        void preventScratches();
    };

    std::string color;
    std::string dataProvider{"AT&T"};
    std::string brand{"Samsung"};
    std::string processor{"Qualcomm 865"};
    int ramAmount{12};

    void makeCall();
    void browseWeb();
    void playMusic();

    void changePhoneCase(Case phoneCase);
};

CellPhone::CellPhone() : color{"red"}
{
    std::cout << "CellPhone being constructed" << std::endl;
}

void CellPhone::makeCall()
{
    std::cout << color << std::endl;
    std::cout << "Making call...\n";

    int callTime{5};

    for(int i = 1; i <= callTime; ++i)
    {
        std::cout << i << " minutes on the call" << std::endl;
    }

    std::cout << "call ended" << std::endl;
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

CellPhone::Case::Case()
{
    std::cout << "Case being constructed" << std::endl;
}

void CellPhone::Case::wrapPhone()
{
    std::cout << color << std::endl;
    std::cout << "Wrapping phone...\n";
}

void CellPhone::Case::providePadding()
{
    std::cout << "Providing padding...\n";
}

void CellPhone::Case::preventScratches()
{
    std::cout << "Preventing scratches...\n";

    for(int i = 0; i < 5; ++i)
    {
        std::cout << i << " scratches prevented" << std::endl;
    }
}

struct Screen
{
    Screen();

    std::string brand;
    int refreshRate{75};
    int pixelsX{920};
    int pixelsY{560};
    std::string connectors{"HDMI"};

    void displayImages();
    void adjustColorSettings();
    void adjustRefreshRate();

    int setPixels(int, int);
};

Screen::Screen() : brand{"Dell"}
{
    std::cout << "Screen being constructed" << std::endl;
}

void Screen::displayImages()
{
    std::cout << brand << std::endl;
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

int Screen::setPixels(int numPixels, int alpha)
{
    for(int i = 1; i <= numPixels; ++i)
    {
        std::cout << i << " pixels set to alpha level " << alpha << std::endl;
    }
    return numPixels;
}

struct CPU
{
    CPU();

    float frequency;
    int amountCache{20};
    int numCores{10};
    std::string architecture{"x86"};
    int nodeProcessSize{14};

    int addNumbers(int num1, int num2); //returns the result of addition.
    int jump(int offset); //returns the new address after the offset is added to curr address.
    int loadDate(int address); //returns the loaded data after gets from memory.

    int allocateCache(int);
};

CPU::CPU() : frequency{4.0f}
{
    std::cout << "CPU being constructed" << std::endl;
}

int CPU::addNumbers(int num1, int num2)
{
    std::cout << frequency << std::endl;
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

int CPU::allocateCache(int cache)
{
    int allocatedCache{0};
    
    while( allocatedCache != cache && amountCache > 0)
    {
        std::cout << "Allocated cache: " << ++allocatedCache << std::endl;
        --amountCache;
    }

    return allocatedCache;
}

struct GraphicsCard
{
    GraphicsCard();

    int numCudaCores;
    int numRTCores{72};
    int amountVRAM{8};
    std::string brand{"NVIDIA"};
    float frequency{2.1f};

    void rotateMatrix();    //should take a matrix but not primitive
    void multipleMatrixByScalar(double scalar);
    void multiplyTwoMatrices(); //should take 2 matrices

    int allocateVRAM(int);
};

GraphicsCard::GraphicsCard() : numCudaCores{4000}
{
    std::cout << "GraphicsCard being constructed" << std::endl;
}

void GraphicsCard::rotateMatrix()
{
    std::cout << numCudaCores << std::endl;
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

int GraphicsCard::allocateVRAM(int VRAM)
{
    int allocatedVRAM{0};
    
    while( allocatedVRAM != VRAM && amountVRAM > 0)
    {
        std::cout << "Allocated memory: " << ++allocatedVRAM << std::endl;
        --amountVRAM;
    }

    return allocatedVRAM;
}

struct RAM
{
    RAM();

    int numGBs;
    int transferRate{3700};
    std::string generation{"DDR4"};
    std::string brand{"Corsair"};
    float cost{124.99f};

    void writeData(int data);
    int readData(int address);  //reads data at given address
    void displayLights();

    int allocateRAM(int);
};

RAM::RAM() : numGBs{32}
{
    std::cout << "RAM being constructed" << std::endl;
}

void RAM::writeData(int data)
{
    std::cout << numGBs << std::endl;
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

int RAM::allocateRAM(int ram)
{
    int allocatedRAM{0};
    
    while( allocatedRAM != ram & numGBs > 0)
    {
        std::cout << "Allocated memory: " << ++allocatedRAM << std::endl;
        --numGBs;
    }

    return allocatedRAM;
}

struct MotherBoard
{
    MotherBoard();

    std::string formFactor;
    std::string socketType{"LGA"};
    std::string expansionSlots{"expansion slots"};
    std::string ramSlots{"ram slots"};
    std::string IOPorts{"io ports"};

    void transferDataFromCPUToRAM();
    void transferDataFromGPUToCPU();
    void transferDataFromIOToCPU();
};

MotherBoard::MotherBoard() : formFactor{"formFactor"}
{
    std::cout << "MotherBoard being constructed" << std::endl;
}

void MotherBoard::transferDataFromCPUToRAM()
{
    std::cout << formFactor << std::endl;
    std::cout << "Transferring data from CPU to RAM...\n";
}

void MotherBoard::transferDataFromGPUToCPU()
{
    std::cout << "Transferring data from GPU to CPU...\n";

    for(int i = 1; i < 5; ++i)
    {
        std::cout << i << " data transfered" << std::endl;
    }
}

void MotherBoard::transferDataFromIOToCPU()
{
    std::cout << "Transferring data from IO to CPU...\n";
}


struct PowerSupply
{
    PowerSupply();

    int wattage;
    std::string efficientRating{"efficient rating"};
    std::string formFactor{"80+ gold"};
    std::string modularity{"modular"};
    std::string connectors{"connectors"};

    void turnACToDC();
    void provideElectricity();
    void regulateVoltage();
};

PowerSupply::PowerSupply() : wattage{650}
{
    std::cout << "PowerSupply being constructed" << std::endl;
}

void PowerSupply::turnACToDC()
{
    std::cout << wattage << std::endl;
    std::cout << "Turning AC to DC...\n";
}

void PowerSupply::provideElectricity()
{
    std::cout << "Providing electricity...\n";

    int wattsRequired = 3;
    int wattsGiven = 0;

    while(wattsGiven < wattsRequired and wattsGiven < wattage)
    {
        std::cout << "whatts given: " << wattsGiven++ << std::endl;
    }
}

void PowerSupply::regulateVoltage()
{
    std::cout << "Regulating voltage...\n";
}

struct Desktop
{
    Desktop();

    CPU cpu{};
    GraphicsCard graphicsCard{};
    RAM ram{};
    MotherBoard motherBoard{};
    PowerSupply powerSupply{};

    void runGame(std::string nameOfGameToLaunch);
    void browseWeb();
    void compileCode();

    void completeTasks(int);
};

Desktop::Desktop()
{
    std::cout << "Desktop being constructed" << std::endl;
}

void Desktop::runGame(std::string nameOfGameToLaunch)
{
    std::cout << cpu.frequency << std::endl;
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

void Desktop::completeTasks(int numTasks)
{
    for(int i = 1; i <= numTasks; ++i)
    {
        std::cout << "Completing task " << i << std::endl;
    }
}

int main()
{
    Example::main();

    //Computer
    Computer computer;

    computer.launchWebBrowser();
    computer.launchAdobePhotoshop();
    computer.consumeElectricity();

    int allocatedMemory = computer.allocateMemory(5);

    std::cout << "Total memory allocated: " << allocatedMemory << std::endl;

    std::cout << "Computer details: \n"
              << "Clock Frequency: " << computer.clockFrequency << " GHz\n"
              << "RAM Amount: " << computer.ramAmount << " GB\n"
              << "Storage Amount: " << computer.storageAmount << " GB\n"
              << "Number of Cores: " << computer.numCores << "\n"
              << "Power Supply Wattage: " << computer.powerSupplyWattage << " W\n";


    //Fuel
    Car::Fuel fuel;

    fuel.burn();
    fuel.smell();
    fuel.flow();

    float cost = fuel.buyGas(5);

    std::cout << "Cost to buy 5 gallons of gas: " << cost << std::endl;

    std::cout << "Fuel details: \n"
              << "Octane Rating: " << fuel.octaneRating << "\n"
              << "Cost Per Gallon: " << fuel.costPerGallon << " $/gallon\n"
              << "Country of Origin: " << fuel.CountryOfOrigin << "\n"
              << "Distributer: " << fuel.distributer << "\n"
              << "Color: " << fuel.color << "\n";


    //Car
    Car car;

    car.playMusic();
    car.drive();
    car.putFuelInCar(fuel);
    car.consumeFuel();

    std::cout << "Car details: \n"
              << "Color: " << car.carColor << "\n"
              << "Horse Power: " << car.horsePower << "\n"
              << "Cost: " << car.cost << " $\n"
              << "Brand: " << car.brand << "\n"
              << "Year: " << car.year << "\n";

    //Case
    CellPhone::Case phoneCase;

    phoneCase.wrapPhone();
    phoneCase.providePadding();
    phoneCase.preventScratches();

    std::cout << "Phone Case details: \n"
              << "Color: " << phoneCase.color << "\n"
              << "Brand: " << phoneCase.brand << "\n"
              << "Cost: " << phoneCase.cost << " $\n"
              << "Features: " << phoneCase.features << "\n"
              << "Is Padded? " << (phoneCase.isPadded ? "Yes" : "No") << "\n";

    //CellPhone
    CellPhone cellPhone;

    cellPhone.makeCall();
    cellPhone.browseWeb();
    cellPhone.playMusic();
    cellPhone.changePhoneCase(phoneCase);

    std::cout << "CellPhone details: \n"
              << "Color: " << cellPhone.color << "\n"
              << "Data Provider: " << cellPhone.dataProvider << "\n"
              << "Brand: " << cellPhone.brand << "\n"
              << "Processor: " << cellPhone.processor << "\n"
              << "RAM Amount: " << cellPhone.ramAmount << " GB\n";

    //Screen
    Screen screen;

    screen.displayImages();
    screen.adjustColorSettings();
    screen.adjustRefreshRate();

    int numPixels = screen.setPixels(1, 2);

    std::cout << numPixels << " changed" << std::endl;

    std::cout << "Screen details: \n"
              << "Brand: " << screen.brand << "\n"
              << "Refresh Rate: " << screen.refreshRate << " Hz\n"
              << "Resolution: " << screen.pixelsX << "x" << screen.pixelsY << "\n"
              << "Connectors: " << screen.connectors << "\n";

    //CPU
    CPU cpu;

    std::cout << cpu.addNumbers(3, 5) << std::endl;
    std::cout << cpu.jump(5) << std::endl;
    std::cout << cpu.loadDate(36) << std::endl;

    int cache = cpu.allocateCache(3);

    std::cout << "Amount of cache allocated " << cache << std::endl; 

    std::cout << "CPU details: \n"
              << "Frequency: " << cpu.frequency << " GHz\n"
              << "Cache Amount: " << cpu.amountCache << " MB\n"
              << "Number of Cores: " << cpu.numCores << "\n"
              << "Architecture: " << cpu.architecture << "\n"
              << "Node Process Size: " << cpu.nodeProcessSize << " nm\n";

    //GraphicsCard
    GraphicsCard graphicsCard;

    graphicsCard.rotateMatrix();
    graphicsCard.multipleMatrixByScalar(3.0);
    graphicsCard.multiplyTwoMatrices();

    int VRAM = graphicsCard.allocateVRAM(3);

    std::cout << "VRAM allocated " << VRAM << std::endl;

    std::cout << "Graphics Card details: \n"
              << "Number of CUDA Cores: " << graphicsCard.numCudaCores << "\n"
              << "Number of RT Cores: " << graphicsCard.numRTCores << "\n"
              << "Amount of VRAM: " << graphicsCard.amountVRAM << " GB\n"
              << "Brand: " << graphicsCard.brand << "\n"
              << "Frequency: " << graphicsCard.frequency << " GHz\n";

    //RAM
    RAM ram;

    ram.writeData(36);
    std::cout << ram.readData(360) << std::endl;
    ram.displayLights();
    int ramAllocated = ram.allocateRAM(3);

    std::cout << "Amount of ram allocated: " << ramAllocated << std::endl;

    std::cout << "RAM details: \n"
              << "Number of GBs: " << ram.numGBs << "\n"
              << "Transfer Rate: " << ram.transferRate << " MT/s\n"
              << "Generation: " << ram.generation << "\n"
              << "Brand: " << ram.brand << "\n"
              << "Cost: $" << ram.cost << "\n";

    //Motherboard
    MotherBoard motherBoard;

    motherBoard.transferDataFromCPUToRAM();
    motherBoard.transferDataFromGPUToCPU();
    motherBoard.transferDataFromIOToCPU();

    std::cout << "Motherboard details: \n"
              << "Form Factor: " << motherBoard.formFactor << "\n"
              << "Socket Type: " << motherBoard.socketType << "\n"
              << "Expansion Slots: " << motherBoard.expansionSlots << "\n"
              << "RAM Slots: " << motherBoard.ramSlots << "\n"
              << "IO Ports: " << motherBoard.IOPorts << "\n";

    //PowerSuppy
    PowerSupply powerSupply;

    powerSupply.turnACToDC();
    powerSupply.provideElectricity();
    powerSupply.regulateVoltage();

    std::cout << "Power Supply details: \n"
              << "Wattage: " << powerSupply.wattage << "\n"
              << "Efficiency Rating: " << powerSupply.efficientRating << "\n"
              << "Form Factor: " << powerSupply.formFactor << "\n"
              << "Modularity: " << powerSupply.modularity << "\n"
              << "Connectors: " << powerSupply.connectors << "\n";

    //Desktop
    Desktop desktop;

    desktop.runGame("game");
    desktop.browseWeb();
    desktop.compileCode();
    desktop.completeTasks(4);

    //dont have print outs for the member variables because i already printed out values for such types above.

    std::cout << "good to go!" << std::endl;
}
