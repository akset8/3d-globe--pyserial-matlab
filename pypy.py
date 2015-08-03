a=open("output2.txt","r")

b=open("output3.txt","w")
c=open("output4.txt","w")

sum1 = 0
index = 0

for i in a:
    for j in i:
        if(j!=' ' and  j!='\n'):
            #print ord(j)
            k = ord(j) - ord('0')
            
            sum1 = sum1 + k * (2**index)
            
            index+=1
            
        if(j==' '):
            b.write(str(sum1))
            c.write(chr(sum1))
            sum1=0
            index=0
            b.write(' ')
            c.write(' ')

    b.write('\n')
    c.write('\n')


            


                
                
                


       
            
            

        
        



