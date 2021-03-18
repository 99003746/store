from openpyxl import load_workbook
path ="Datasheet_3.xlsx"
wb = load_workbook(path)

#Function for Name

def name():
    ws=wb['Sheet1']
    data = []
    name = input("Enter a Name:- ")

    for i in range(1,ws.max_row+1):
        if (ws.cell(row=i,column=1).value == name):
            data.append(ws.cell(row=i,column=2).value)
            data.append(ws.cell(row=i,column=3).value)
    print(data)

#Function for PS NUmber

def ps_no():
    ws = wb['Sheet1']
    data = []
    ps_no = int(input("Enter a Ps number:- "))

    for i in range(1,ws.max_row+1):
        if (ws.cell(row=i, column=2).value == ps_no):
            data.append(ws.cell(row=i, column=1).value)
            data.append(ws.cell(row=i, column=3).value)
    print(data)

#Function for Email

def email():
    ws = wb['Sheet1']
    data = []
    email =input("Enter a Email_id:- ")

    for i in range(1,ws.max_row+1):
        if (ws.cell(row=i, column=3).value == email):
            data.append(ws.cell(row=i, column=1).value)
            data.append(ws.cell(row=i, column=2).value)
    print(data)


#Function for ALL

def all():
    data = []
    name = input("Enter Name:- ")
    ps_no = eval(input("Enter PS_Number:-"))
    email = input("Enter Email_ID:-")

    for sheet in wb.worksheets:

        for i in range(1, sheet.max_row + 1):

            if (sheet.cell(row=i, column=1).value == name):

                if (sheet.cell(row=i, column=2).value == ps_no):

                    if (sheet.cell(row=i, column=3).value == email):

                        sh = wb['Sheet1']
                        if sheet == sh:

                            for j in range(1, 11):
                                (sheet.cell(row=i, column=j).value)

                                data.append(sheet.cell(row=i, column=j).value)
                        else:

                            for j in range(4, 11):
                                data.append(sheet.cell(row=i, column=j).value)
    print(data)
    print(len(data))

#User Input

n=int(input("Which Data You have \n 1.Name \n 2.Ps number \n 3.Email \n 4.All \n"))

if n==1:
    name()
elif n==2:
    ps_no()
elif n==3:
    email()
elif n==4:
     all()
else:
    print('Data unavailable')

