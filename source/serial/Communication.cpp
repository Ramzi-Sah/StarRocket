#include "Communication.hpp"

std::vector<COM> Communication::ports;
int Communication::selectedPort = -1;
bool Communication::connected = false;

std::vector<COM> Communication::getPorts() {
    return ports;
};
int Communication::getSelectedPort() {
    return selectedPort;
};
void Communication::setSelectedPort(int _selectedPort) {
    selectedPort = _selectedPort;
};
void Communication::scanPorts() {
    // clear ports
    ports.clear();

    // checking ports from COM0 to COM255
    char lpTargetPath[5000];
    for (int i = 0; i < 255; i++) {
        std::string port = "COM" + std::to_string(i);
        DWORD test = QueryDosDevice(port.c_str(), lpTargetPath, 5000);

        //QueryDosDevice returns zero if it didn't find an object
        if (test != 0) {
            // std::cout << port << ": " << lpTargetPath << std::endl;
            ports.push_back(COM(port, std::string(lpTargetPath)));
        };
    };

    // if found ports
    if (ports.size() > 0) {
        selectedPort = 0;
    };
};

bool Communication::getConnectedStatus() {
    return connected;
};

//------------------------------------------------------------------------------
std::thread Communication::thread1;
int Communication::thread1_stop_signal;
void Communication::connect() {
    thread1 = std::thread(Communication::com_instance, ports[selectedPort]);
    thread1.detach();
};
void Communication::disconnect() {
    thread1_stop_signal++;
    // thread1.join(); // should join the thread
};

void Communication::com_instance(COM port_com) {
    const char* portPath = std::string("\\\\.\\").append(port_com.port).c_str();

    Serial* SP = new Serial(portPath);

    if (SP->IsConnected()) {
        Communication::connected = true;
        // disconnected message
        Console::addMessage("[INFO] connected to " + port_com.port);
    };

    // pre-allocate memory
    char incomingData[256] = "";
    int dataLength = 255;
    int readResult = 0;

    int stop_signal_value = thread1_stop_signal;
    while(SP->IsConnected() && thread1_stop_signal == stop_signal_value) {
        readResult = SP->ReadData(incomingData, dataLength);
        // incomingData[readResult] = 0;

        // printf("%s", incomingData);

        // add message to console
        Console::addMessage("[Recieved msg] " + std::string(incomingData));

        Sleep(100);
    };

    Communication::connected = false;
    delete SP;

    // disconnected message
    Console::addMessage("[INFO] disconnected from " + port_com.port);

};
