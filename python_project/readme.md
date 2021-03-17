from openpyxl import load_workbook
path ="Datasheet.xlsx"
wb = load_workbook(path)
#ws=wb.get_sheet_by_name('Sheet1')

#ws=wb['Sheet1']
#s=ws.max_row                         # variable to store max rows for sl num


data=[]
name=input("Enter Name: ")

'''
for sheet in wb.worksheets:
    for i in range(1,ws.max_row+1  ):
        if(ws.cell(row=i,column=1).value == name):
           for j in range (1,12):
            #print(ws.cell(row=i,column=j).value)
            (ws.cell(row=i, column=j).value)
            data.append(ws.cell(row=i,column=j).value)
    print(data)
''' #New

for sheet in wb.worksheets:
    for i in range(1,sheet.max_row+1):
        if(sheet.cell(row=i,column=1).value == name):
            sh = wb["Sheet1"]
            if sheet == sh:

                for j in range (1,12):
                #print(ws.cell(row=i,column=j).value)
                    (sheet.cell(row=i, column=j).value)

                    data.append(sheet.cell(row=i,column=j).value)
            else:

                for j in range (2,12):
                #print(ws.cell(row=i,column=j).value)
                #(sheet.cell(row=i, column=j).value)
                    data.append(sheet.cell(row=i,column=j).value)
print(data)









#ws=wb.get_sheet_by_name('Sheet2')

'''
ws=wb['Sheet2']
#s=ws.max_row                              # variable to store max rows for sl num

for i in range(1,ws.max_row+1):
    if(ws.cell(row=i,column=1).value == name):
        for j in range(2,12):
             #print(ws.cell(row=i,column=j).value)
             (ws.cell(row=i, column=j).value)
             data.append(ws.cell(row=i,column=j).value)
print(data)

'''
#print(wb.sheetnames)

if 'Master_Sheet' not in wb.sheetnames:
    head=[]
    head= ['Comapany_Name','1771','1772','1773','1774','1775','1776','1777','1778','1779','1880',\
           '1881', '1882', '1883', '1884','1885','1886','1887','1888','1889','1890',\
           '1891','1892', '1893','1894','1895','1896','1897','1898','1899','1990',\
           '1991','1992','1993','1994','1995','1996','1997','1998','1999','2000'\
           '2001','2002','2003','2004','2005','2006','2007','2008','2009','2010']

    ws = wb.create_sheet('Master_Sheet')
    print("CREATING")
    s=ws.max_row          # variable to store max rows for sl num

    for i in range(1,52):

        ws.cell(row=1,column=i).value=head[i+1]

    for i in range(1,52):

        ws.cell(row=s+1,column=i).value=data[i-1]

    wb.save(path)

else:

    #ws = wb.get_sheet_by_name('Sheet0')

    ws=wb['Master_Sheet']

    s = ws.max_row

    for i in range(1,52):

        ws.cell(row=s+1,column=i).value= data[i-1]

    wb.save(path)







///////////////////////////////////////////////////////////////////////////////////New One//////////////////////////////////////////////////////////////////////////////
from openpyxl import load_workbook
path ="Datasheet_3.xlsx"
wb = load_workbook(path)

data=[]
name=input("Enter Name: ")
ps_no=int(input("Enter PS_Number"))
email=input("Enter Email_ID")

for sheet in wb.worksheets:

    for i in range(1, sheet.max_row+1):


        if(sheet.cell(row=i,column=1).value == name):

            if(sheet.cell(row=i,column=2).value == ps_no):
               if(sheet.cell(row=i,column=3).value == email):

                    sh = wb['Sheet1']
                    if sheet == sh:

                        for j in range (1,11):
                        #print(ws.cell(row=i,column=j).value)
                            (sheet.cell(row=i, column=j).value)

                            data.append(sheet.cell(row=i,column=j).value)
                    else:

                        for j in range (4,11):
                        #print(ws.cell(row=i,column=j).value)
                        #(sheet.cell(row=i, column=j).value)
                            data.append(sheet.cell(row=i,column=j).value)
print(data)
print(len(data))








