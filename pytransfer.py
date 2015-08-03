f=open("output4.txt","r")

#import serial

import serial # if you have not already done so

ser = serial.Serial('COM6',9600)



for i in f:
    for j in i:
        if(j!=" " and j!="\n"):
            ser.write(j)
            print ord(j)," ",
    print "\n"
            
            
            
            



    
