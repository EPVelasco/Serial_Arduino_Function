# Serial_Arduino_Function
This code presents a simple function to unframe data received on a serial port.

This program has the function:
- **_read_data (serial port, end data, separator, array_data_out, serial timeout)_**.- This function reads data from the serial port in the following format:

  data_1 "separator" data_2 "separator" ... data_n "separator" final character
  
  **Frame example:**
  3.1,3.2,3.3,3.4,3.5,3.6/n

And makes it float:

  **_array_data_out = [data_1, data_2, ... data_n]_**

## Example Connection Diagram
<p float="center">
  <img src="/images/diagram.png" width="720"  />
 </p>
 


