from openpyxl import load_workbook
from openpyxl.chart import BarChart, Reference
path ="Datasheet_3.xlsx"
wb = load_workbook(path)






#Function for Name
data=[]
def name():
    ws=wb['Sheet1']
    data = []
    name = input("Enter a Name:- ")

    for i in range(1,ws.max_row+1):
        if (ws.cell(row=i,column=1).value == name):
            data.append(ws.cell(row=i,column=1).value)
            data.append(ws.cell(row=i,column=2).value)
            data.append(ws.cell(row=i,column=3).value)

    print(data)
    exit()
#Function for PS NUmber

def ps_no():
    ws = wb['Sheet1']
    data = []
    ps_no = int(input("Enter a Ps number:- "))

    for i in range(1,ws.max_row+1):
        if (ws.cell(row=i, column=2).value == ps_no):
            data.append(ws.cell(row=i, column=2).value)
            data.append(ws.cell(row=i, column=1).value)
            data.append(ws.cell(row=i, column=3).value)
    print(data)
    exit()

#Function for Email

def email():
    ws = wb['Sheet1']
    data = []
    email =input("Enter a Email_id:- ")

    for i in range(1,ws.max_row+1):
        if (ws.cell(row=i, column=3).value == email):
            data.append(ws.cell(row=i, column=3).value)
            data.append(ws.cell(row=i, column=1).value)
            data.append(ws.cell(row=i, column=2).value)
    print(data)
    exit()

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
    return(data)


#User Input

n=int(input("Which Data You have \n 1.Name \n 2.Ps number \n 3.Email \n 4.All \n"))

if n==1:
    name()
elif n==2:
    ps_no()
elif n==3:
    email()
elif n==4:
     data= all()
else:
    print('Data unavailable')


##Creating Master Sheet

if 'Master_Sheet' not in wb.sheetnames:
    head=[]
    head= ['Name','PS_No','Email','a1','a2','a3','a4','a5','a6','a7',\
           'b1', 'b2', 'b3','b4','b5','b6','b7',\
           'c1','c2', 'c3','c4','c5','c6','c7',\
           'd1','d2','d3','d4','d5','d6','d7',\
           'e1','e2','e3','e4','e5','e6','e7']

    ws = wb.create_sheet('Master_Sheet')
    print("CREATING Master_Sheet")
    s=ws.max_row          # variable to store max rows for sl num

    for i in range(1,39):

        ws.cell(row=1,column=i).value=head[i-1]
    print("Data", len(data))
    for i in range(1,39):

        ws.cell(row=s+1,column=i).value=data[i-1]

    wb.save(path)

else:
     ws=wb['Master_Sheet']

     s = ws.max_row

     for i in range(1,39):

        ws.cell(row=s+1,column=i).value= data[i-1]

     wb.save(path)



    ##Creating Chart

sheet = wb['Master_Sheet']
values = Reference(sheet, min_col=3, min_row=2,
                   max_col=10, max_row=4)

chart = BarChart()

# adding data to the Bar chart object
chart.add_data(values)

# set the title of the chart
chart.title = " STUDENT CHART "

# set the title of the x-axis
chart.x_axis.title = " X_AXIS "

# set the title of the y-axis
chart.y_axis.title = " Y_AXIS "

# add chart to the sheet
# the top-left corner of a chart
# is anchored to cell E2 .
sheet.add_chart(chart, "E2")

# save the file
wb.save("Datasheet_3.xlsx")


