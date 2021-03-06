"""
Description:This program takes a user input as a keyword and search the
            occurrence of the word in the Excel file and assembles all
            corresponding data from 5 sheets, and store these details in
            a  Master Sheet.
Author:  NITIN N SHETTY
PS No:   99003746
Contact: nitin.shetty1@ltts.com
Date of Creation: 20/03/2021
"""


# "---------- IMPORTING LIBRARIES -----------------"

from openpyxl import load_workbook
from openpyxl.chart import BarChart,  Reference
path = "Datasheet_3.xlsx"
wb = load_workbook(path)


# '''------CREATION OF FIRST-CLASS FOR FOUR FUNCTIONS----'''

# "---FUNCTION FOR FINDING MULTIPLE NAMES-----"

class SingleData:
    data = []

    def name(self):

        ws = wb['Sheet1']
        data = []
        name = input("Enter a Name:- ")

        for i in range(1, ws.max_row+1):
            if ws.cell(row=i, column=1).value==name:
                data.append(ws.cell(row=i, column=2).value)
                data.append(ws.cell(row=i, column=1).value)
                data.append(ws.cell(row=i, column=3).value)

        print(data)
        b = (len(data))
        if b == 0:
            print('Given Name is not present in the list')
        data = all()
        return data

# "---FUNCTION FOR FINDING MULTIPLE PS-NO -----"

    def ps_no(self):
        ws = wb['Sheet1']
        data = []
        ps_no = int(input("Enter a Ps number:- "))

        for i in range(1, ws.max_row+1):
            if (ws.cell(row=i, column=2).value == ps_no):
                data.append(ws.cell(row=i, column=2).value)
                data.append(ws.cell(row=i, column=1).value)
                data.append(ws.cell(row=i, column=3).value)
        print(data)
        data = all()
        return data

# "---FUNCTION FOR FINDING MULTIPLE EMAILS-----"

    def email(self):
        ws = wb['Sheet1']
        data = []
        email =input("Enter a Email_id:- ")

        for i in range(1, ws.max_row+1):
            if ws.cell(row=i, column=3).value == email:
                data.append(ws.cell(row=i, column=3).value)
                data.append(ws.cell(row=i, column=1).value)
                data.append(ws.cell(row=i, column=2).value)
        print(data)
        data = all()
        return data

# "------------------------------END OF FIRST CLASS----------------------------"

# "-----------------------CREATION OF SECOND CLASS FOR ALL-DATA FUNCTION-----------" #


class AllData:


# "---------FUNCTION FOR FETCHING DETAILS OF SELECTED STUDENT----------------------"#

    def all(self):
        data = []
        name = input("Enter Name:- ")
        ps_no = eval(input("Enter PS_Number:-"))
        email = input("Enter Email_ID:-")

        for sheets in wb.worksheets:

            for rw in range(1, sheets.max_row + 1):

                if sheets.cell(row=rw, column=1).value == name:

                    if sheets.cell(row=rw, column=2).value == ps_no:

                        if sheets.cell(row=rw, column=3).value == email:

                            sh = wb['Sheet1']
                            if sheets == sh:

                                for col in range(1, 11):
                                    data.append(sheets.cell(row=rw, column=col).value)
                            else:

                                for x in range(4, 11):
                                    data.append(sheets.cell(row=rw, column=x).value)
        print(data)
        a=len(data)
        if a==0:
            print('Given Data is Incoorect')
        return data



# -------------------CREATING OBJECT FOR CLASSES-----------------------#



obj_single_data = SingleData()
obj_all_data = AllData()


# ------------------User Input----------------------#

n=int(input("Which Data You have \n 1.Name \n 2.Ps number \n 3.Email \n 4.All \n"))

if n==1:
    data = obj_single_data.name()
elif n==2:
    data = obj_single_data.ps_no()
elif n==3:
    data = obj_single_data.email()
elif n==4:
    data = obj_all_data.all()
else:
    print('Data unavailable')


# -----------------Creating Master Sheet-----------------#

if 'Master_Sheet' not in wb.sheetnames:

    Header=[]
    for sheet in wb.worksheets:
        i=1
        if sheet==wb['Sheet1']:
            for j in range(1, 11):
                Header.append(sheet.cell(row=i, column=j).value)
        else:
            for j in range(4, 11):
                Header.append(sheet.cell(row=i, column=j).value)

    ws = wb.create_sheet('Master_Sheet')
    print("CREATED Master_Sheet")
    s=ws.max_row          # variable to store max rows for sl num

    for i in range(1, 39):

        ws.cell(row=1, column=i).value=Header[i-1]
    print("Data", len(data))
    for i in range(1, 39):

        ws.cell(row=s+1, column=i).value=data[i-1]

    wb.save(path)

else:
    ws=wb['Master_Sheet']

    s = ws.max_row

    for i in range(1, 39):

        ws.cell(row=s+1, column=i).value= data[i-1]

    wb.save(path)


# ------------------------------Creating graph-----------------------------#

sheet = wb['Master_Sheet']

values = Reference(sheet, min_col=11, min_row=2,
                   max_col=38, max_row=sheet.max_row)

# Create object of BarChart3D class
chart = BarChart()
chart.style = 15
chart.add_data(values)

# set the title of the chart
chart.title = " Student Marks Analysis "

# set the title of the x-axis
chart.x_axis.title = " MARKS "

# set the title of the y-axis
chart.y_axis.title = " NO. OF STUDENTS "

# add chart to the sheet
# the top-left corner of a chart
# is anchored to cell E2.
sheet.add_chart(chart, "E2")

# save the file
wb.save("Datasheet_3.xlsx")
