a=open("output1.txt","w")

b=open("output.txt","r")

for i in b:
    for j in i:
        if(j=='0'):
            a.write('1')
        elif(j=='1'):
            a.write('0')
        elif(j=='\n'):
            a.write('\n')


