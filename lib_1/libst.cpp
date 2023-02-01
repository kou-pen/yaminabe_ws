#include <iostream>
#include <libserial/SerialStream.h>
using namespace LibSerial ;

int main(){

    SerialStream my_serial_stream( "/dev/ttyACM0" ) ;
    my_serial_stream.SetBaudRate( LibSerial::BaudRate::BAUD_115200 );
    my_serial_stream.SetCharacterSize( LibSerial::CharacterSize::CHAR_SIZE_8 );
    //FIXME:my_serial_stream.SetFlowControl( LibSerial:FlowControl::FLOW_CONTROL_HARD );
    my_serial_stream.SetParity( LibSerial::Parity::PARITY_NONE );
    my_serial_stream.SetStopBits( LibSerial::StopBits::STOP_BITS_1 ) ;
    
    
    //const int BUFFERSIZE = 256;
    
    char my_message[2];
    /*
    int j;
    for (int i = 0; i < 2; i++){
        j = i + '0';
        my_message[i] = j ;
        
    }*/
    my_message[0] = '5';
    my_message[1] = '7';

    //uint8_t my_messages = 5;
    //my_serial_stream << my_messages << std::endl ;
    my_serial_stream.write(my_message,2);//char janaito error
    
    printf("sent message.\n");
    my_serial_stream.Close();
}