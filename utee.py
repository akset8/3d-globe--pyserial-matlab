##what i need to do now is :-

a=open("output1.txt","r")

b=open("output2.txt","w")

k=0

for i in a:
    for j in i:
        if(j=='1'):
            b.write('1')
            if(k<8):
                k+=1
            if(k==8):
                k=0
                b.write(' ')

        elif(j=='0'):
            b.write('0')
            if(k<8):
                k+=1
            if(k==8):
                k=0
                b.write(' ')
        elif(j=='\n'):
            b.write('\n')

        
        
            
        
