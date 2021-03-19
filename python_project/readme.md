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
    b = (len(data))
    if b == 0:
        print('Given Name is not present in the list')
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
    a=(len(data))
    if a==0:
        print('Given Data is Incoorect')
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
    head= ['Name','Psno','email','Contact_No','Blood_Group','Adhaar','Gender','Age','Height','Weight',\
           'SEM-1 (ELECTRONICS)', 'SEM-1 (MATHS)', 'SEM-1 (BIOLOGY)','SEM-1 (GIOLOGY)','SEM-1 (AGRICULTURE)','SEM-1 (PHYSICS)','SEM-1 (CHEMISTRY)',\
           'SEM-2 (ELECTRONICS)', 'SEM-2 (MATHS)', 'SEM-2 (BIOLOGY)','SEM-2 (GIOLOGY)','SEM-2 (AGRICULTURE)','SEM-2 (PHYSICS)','SEM-2 (CHEMISTRY)',\
           'SEM-3 (ELECTRONICS)', 'SEM-3 (MATHS)', 'SEM-3 (BIOLOGY)','SEM-3 (GIOLOGY)','SEM-3 (AGRICULTURE)','SEM-3 (PHYSICS)','SEM-3 (CHEMISTRY)',\
           'SEM-4 (ELECTRONICS)', 'SEM-4 (MATHS)', 'SEM-4 (BIOLOGY)','SEM-4 (GIOLOGY)','SEM-4 (AGRICULTURE)','SEM-4 (PHYSICS)','SEM-4 (CHEMISTRY)']

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
values = Reference(sheet, min_col=11, min_row=2,
                   max_col=28, max_row=4)

chart = BarChart()

# adding data to the Bar chart object
chart.add_data(values)

# set the title of the chart
chart.title = " STUDENT CHART "

# set the title of the x-axis
chart.x_axis.title = " LIST OF STUDENTS "

# set the title of the y-axis
chart.y_axis.title = " EFFICIENCY "

# add chart to the sheet
# the top-left corner of a chart
# is anchored to cell E2 .
sheet.add_chart(chart, "E2")

# save the file
wb.save("Datasheet_3.xlsx")


