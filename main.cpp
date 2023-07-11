/*
 Project 3 - Part 4 / 5
 video: Chapter 2 - Part 9
 Member initialization tasks

 Create a branch named Part4

 1) do this for each class in this project:
    initialize some of your member variables either in-class or in the Constructor member initializer list.
    Show me that you understand how to use these language features.

 2) make some of your member functions use those initialized member variables via std::cout statements.

 3) click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 */

#include <iostream>
namespace Example
{
    struct UDT
    {
        int a; //a member variable that IS NOT initialized in-class
        float b { 2.f }; //a member variable that IS initialized in-class
        UDT() : a(0) { } // 'constructor-initializer-list' initializing the member that wasn't initialized in-class.
        void printAandB()  //the member function
        {
            std::cout << "UDT::printAandB() a:" << a << " b: " << b << std::endl;  //2) printing out something interesting
        }
    };

    int main()
    {
        UDT foo; //instantiating a Foo in main()
        foo.printAandB(); //calling a member function of the instance that was instantiated.
        return 0;
    }
}

//call Example::main()


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
    std::cout << "Consuming fuel...\n";
    return 0.0f;  // replace with actual implementation
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
