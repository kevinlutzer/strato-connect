# StratoConnect
A RF module you can comunicate with over I2C to send AX.25 formatted data over (G)FSK

# Rev 2.0 Todo

1. The current boost regulator doesn't really work. We are getting voltage drops when there are current spikes. 
2. IRQ was not connected.
3. RX/TX labels are wrong for the uart port. 
4. Switch the JST connectors to be the 1.0mm pitch connector type used for QT/QWICC

# Code

To compile and run tests use: `g++ test/test.cpp ax25/ax25.* test/ax25_test.h -lgtest -std=c++17 && ./a.out`
To compile code for arduino use: `arduino-cli compile -b MiniCore:avr:328 --library=ax25,rf4463`