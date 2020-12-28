#ifndef SR_COMMUNICATION
#define SR_COMMUNICATION

#include <iostream>
#include <vector>
#include <thread>

#ifdef _WIN32
    #include <Windows.h>
#else
    // TODO: handle linux tty devices
#endif

#include "Serial.hpp"
#include "../window/fragments/Console.hpp"

struct COM {
    std::string port = "";
    std::string name = "";

    COM(std::string _port ,std::string  _name) {
        port = _port;
        name = _name;
    };
};

class Communication {
private:
    static std::vector<COM> ports;
    static int selectedPort;
    static bool connected;

    static std::thread thread1;
    static int thread1_stop_signal;
    static void com_instance(COM port_com);

public:
    static void scanPorts();
    static std::vector<COM> getPorts();
    static int getSelectedPort();
    static void setSelectedPort(int _selectedPort);

    static void connect();
    static void disconnect();
    static bool getConnectedStatus();
};

#endif
