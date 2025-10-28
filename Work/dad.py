l=float(input('Enter the length :   '))
b=float(input('Enter the width :   '))
a=int((l*b)/9)
if a%2!=0:
    print('Khetra padam : ' , a)
    a1 = (a * 9 )%120
    print('Aayush / age ' , a1)
    a2 = (a*9)%8
    l1=[1,3,5,7,9]
    l2=[0,2,4,6]
    if a2 in l1:
        print('Good ', a2)
    else:
        if(a2==0):
            a2=8.0
        print('Bad ',a2)
    a3 = (a*6)%9
    l3=[0,2,3,7,8,9]
    l4=[1,4,5,6]
    if(a3==0):
            a3=9.0
    if a3 in l3:
        print('Good ',a3)
    else:
        print('Bad ',a3)
    a4=(a*8)%12
    a5=(a*3)%8
    if a4==0.0:
        print('Dhanam ',12.0)
        a4=12.0
    print('Dhanam ',a4)
    print('Runam ',a5)
    if(a4>a5):
        print('GOOOOD')
    else:
        print('BAD')
else:
    print('Even :',a)
    
