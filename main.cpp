/*
 Project 3 - Part 3 / 5
 video: Chapter 2 - Part 8
 Constructors tasks

 Create a branch named Part3

 On this new branch:

 0) if you opted to not fill in any of your member functions in part2, 
    fill in ALL of your member functions
    
 1) Add a constructor for each User-Defined-Type.
    The constructor should be the first declaration in your UDT, before all member variables and member functions.
    add a std::cout message in the constructor that prints out the name of the class being constructed.  
    When you run your code, you'll see the order that your objects are created in the program output. 
 
 2) For each User-Defined-Type:
        amend some of the member functions to print out something interesting via std::cout
 
 3) Instantiate 1 or 2 instances of EACH of your user-defined types in the main() function.  
    You should have at least 12 different variables declared in main(), because you have written 12 different types (including the nested types)

 4) For each instantiated UDT: 
        call each of that instance's member functions.
        You're doing this to show that your code doesn't produce warnings when you call the functions that take arguments.
 
 5) add some std::cout statements in main() that print out your UDT's member variable values or values returned from your UDT member functions (if they return values)
 
 After you finish defining each type/function:
 click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 
 example:
 */

#include <iostream>
namespace Example 
{
struct UDT  // my user defined type named 'UDT'
{
    int thing = 0; //a member variable
    UDT();              //1) the constructor
    void printThing();  //the member function
};

//the function definitions are outside of the class
UDT::UDT()
{
    std::cout << "UDT being constructed!" << std::endl; //1) 
}

void UDT::printThing()
{
    std::cout << "UDT::printThing() " << thing << std::endl;  //2) printing out something interesting
}

int main()
{
    UDT foo;              //3) instantiating a UDT named 'foo' in main()
    foo.printThing();     //4) calling a member function of the UDT instance.
    
    //5) a std::cout statement accessing foo's member variable.
    //It also demonstrates a 'ternary expression', which is syntactic shorthand for an 'if/else' expression
    std::cout << "Is foo's member var 'thing' equal to 0? " << (foo.thing == 0 ? "Yes" : "No") << "\n";
    
    return 0;
}
} //end namespace Example

//insert Example::main() into main() of user's repo.





struct Computer
{
    Computer();
    
    float clockFrequency{4.0f};
    int ramAmount{32};
    int storageAmount{512};
    int numCores{};
    int powerSupplyWattage{550};

    void launchWebBrowser();
    void launchAdobePhotoshop();
    void consumeElectricity();
};

Computer::Computer()
{
    std::cout << "Computer being constructed" << std::endl;
}

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
    Car();

    struct Fuel
    {
        Fuel();

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

Car::Car() 
{
    std::cout << "Car being constructed" << std::endl;
}

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

Car::Fuel::Fuel()
{
    std::cout << "Fuel being constructed" << std::endl;
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
    CellPhone();

    struct Case
    {
        Case();

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

CellPhone::CellPhone() 
{
    std::cout << "CellPhone being constructed" << std::endl;
}

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

CellPhone::Case::Case() 
{
    std::cout << "Case being constructed" << std::endl;
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
    Screen();

    std::string brand{"Dell"};
    int refreshRate{75};
    int pixelsX{920};
    int pixelsY{560};
    std::string connectors{"HDMI"};

    void displayImages();
    void adjustColorSettings();
    void adjustRefreshRate();
};

Screen::Screen() 
{
    std::cout << "Screen being constructed" << std::endl;
}

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
    CPU();

    float frequency{4.0f};
    int amountCache{20};
    int numCores{10};
    std::string architecture{"x86"};
    int nodeProcessSize{14};

    int addNumbers(int num1, int num2); //returns the result of addition.
    int jump(int offset); //returns the new address after the offset is added to curr address.
    int loadDate(int address); //returns the loaded data after gets from memory.
};

CPU::CPU() 
{
    std::cout << "CPU being constructed" << std::endl;
}

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
    GraphicsCard();

    int numCudaCores{4000};
    int numRTCores{72};
    int amountVRAM{8};
    std::string brand{"NVIDIA"};
    float frequency{2.1f};

    void rotateMatrix();    //should take a matrix but not primitive
    void multipleMatrixByScalar(double scalar);
    void multiplyTwoMatrices(); //should take 2 matrices
};

GraphicsCard::GraphicsCard() 
{
    std::cout << "GraphicsCard being constructed" << std::endl;
}

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
    RAM();

    int numGBs{32};
    int transferRate{3700};
    std::string generation{"DDR4"};
    std::string brand{"Corsair"};
    float cost{124.99f};

    void writeData(int data);
    int readData(int address);  //reads data at given address
    void displayLights();
};

RAM::RAM() 
{
    std::cout << "RAM being constructed" << std::endl;
}

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
    MotherBoard();

    std::string formFactor{"form factor"};
    std::string socketType{"LGA"};
    std::string expansionSlots{"expansion slots"};
    std::string ramSlots{"ram slots"};
    std::string IOPorts{"io ports"};

    void transferDataFromCPUToRAM();
    void transferDataFromGPUToCPU();
    void transferDataFromIOToCPU();
};

MotherBoard::MotherBoard() 
{
    std::cout << "MotherBoard being constructed" << std::endl;
}

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
    PowerSupply();

    int wattage{550};
    std::string efficientRating{"efficient rating"};
    std::string formFactor{"80+ gold"};
    std::string modularity{"modular"};
    std::string connectors{"connectors"};

    void turnACToDC();
    void provideElectricity();
    void regulateVoltage();
};

PowerSupply::PowerSupply() 
{
    std::cout << "PowerSupply being constructed" << std::endl;
}

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
    Desktop();

    CPU cpu{};
    GraphicsCard graphicsCard{};
    RAM ram{};
    MotherBoard motherBoard{};
    PowerSupply powerSupply{};

    void runGame(std::string nameOfGameToLaunch);
    void browseWeb();
    void compileCode();
};

Desktop::Desktop() 
{
    std::cout << "Desktop being constructed" << std::endl;
}

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
    Example::main();

    //Computer
    Computer computer;
    
    computer.launchWebBrowser();
    computer.launchAdobePhotoshop();
    computer.consumeElectricity();

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

    //dont have print outs for the member variables because i already printed out values for such types above.
    
    std::cout << "good to go!" << std::endl;
}