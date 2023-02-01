#include <libserial/SerialPort.h>
#include <iostream>
#include <unistd.h>

using namespace LibSerial;

int main(){
    //FIXME:instance
    //check port:ls -l /dev/serial/by-id/
    //open port 
    SerialPort   serial_port;
    serial_port.Open( "/dev/ttyACM0" );
    //Baudrate
    serial_port.SetBaudRate( LibSerial::BaudRate::BAUD_115200 );
    //char size
    serial_port.SetCharacterSize( LibSerial::CharacterSize::CHAR_SIZE_8 );
    //Flow control
    //TODO:serial_port.SetFlowControl( FLOW_CONTROL_HARD );
    //parity bit
    serial_port.SetParity( LibSerial::Parity::PARITY_NONE);
    //stop bit
    serial_port.SetStopBits( LibSerial::StopBits::STOP_BITS_2 ) ;
    
    //main
    std::string my_string = "Hello, Serial Port.\n";
    

    serial_port.Write( my_string );
        
  

    //close port
    serial_port.Close();
}

