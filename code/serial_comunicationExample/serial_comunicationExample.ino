HardwareSerial *port;
float data_cpu_1[6];
float data_cpu_2[6];
float data_cpu_3[6];

void setup() {

  Serial.begin(115200); 
  Serial1.begin(115200); 
  Serial2.begin(115200); 
  Serial3.begin(115200);   

}


void loop() {
  unsigned long ini_times=millis();
  Serial1.println("Send data to Arduino1");
  read_data(&Serial1 , 10 ,',' , data_cpu_1,10);
  Serial2.println("Send data to Arduino2");
  read_data(&Serial2 , 10 ,',' , data_cpu_2,10);
  Serial3.println("Send data to Arduino3");  
  read_data(&Serial3 , 10 ,',' , data_cpu_3,10); 
    
  print_array(data_cpu_1,sizeof(data_cpu_1)/sizeof( data_cpu_1[0]));
  print_array(data_cpu_2,sizeof(data_cpu_2)/sizeof( data_cpu_2[0]));
  print_array(data_cpu_3,sizeof(data_cpu_3)/sizeof( data_cpu_3[0]));

  delay(10);
}


void read_data(HardwareSerial *port , int data_end , char sep, float array_data[], unsigned long time_out){
  // (serial port, end data, separator, array_data_out, serial timeout)
  unsigned long time_loop = 0, time_init = millis();
   if(port->available()>0){      
    time_loop = 0;
    int read_data = data_end - 1;
    unsigned int cont = 0; 
    String data= ""; // elements ==> (data_0,data_1,...data_n,data_end)
    unsigned int cont_sep = 0; 
    while(read_data != data_end){
      time_loop = millis()-time_init;
      read_data = port->read();    
      if((int)read_data != data_end && (int)read_data != -1)
      {
        data.concat((char)read_data);
        cont++; 
        if((char)read_data == sep)
          cont_sep++;
      }
      if(time_loop>=time_out){
        break;
      }
    }
    int var_sep = 0; 
    String data_sep = ""; 
    for(int i=0 ; i<cont;i++)
      {
        if(data[i]!=sep){        
          data_sep.concat(data[i]);
        }
        else{
          array_data[var_sep] = data_sep.toFloat();
          var_sep++;
          data_sep = "";
        }
      }
      array_data[cont_sep] = data_sep.toFloat();
  } 
}

void print_array(float array_data[],int len_array){
     
       Serial.print("Size of data: ");
       Serial.println (len_array);
       for(int j = 0 ;j<len_array  ;j++)
       {
          Serial.print(array_data[j]);
          if(j<len_array-1)
            Serial.print(",");
       }
       Serial.println("");
}
