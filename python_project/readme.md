from openpyxl import load_workbook
path ="Datasheet.xlsx"
wb = load_workbook(path)
#ws=wb.get_sheet_by_name('Sheet1')
ws=wb['_001']
s=ws.max_row                         # variable to store max rows for sl num


data=[]
name=input("Enter Name: ")
for i in range(1,s+1):
    if(ws.cell(row=i,column=1).value == name):
        for j in range (1,6):
            print(ws.cell(row=i,column=j).value)
            data.append(ws.cell(row=i,column=j).value)
print(data)

#ws=wb.get_sheet_by_name('Sheet2')


ws=wb['_002']
s=ws.max_row                              # variable to store max rows for sl num

for i in range(1,s+1):
    if(ws.cell(row=i,column=1).value == name):
        print(ws.cell(row=i,column=5).value)
        data.append(ws.cell(row=i,column=4).value)
print(data)


#print(wb.sheetnames)
if 'Master_Sheet' not in wb.sheetnames:
    head=[]
    head= ['Name', 'PS Number', 'Email', 'Phone Number', 'Batch']
    ws = wb.create_sheet('Master_Sheet')
    print("CREATING")
    s=ws.max_row# variable to store max rows for sl num

    for i in range(1, 6):

        ws.cell(row=1,column=i).value=head[i-1]

    for i in range(1,6):

        ws.cell(row=s+1,column=i).value= data[i-1]

    wb.save(path)

else:

    #ws = wb.get_sheet_by_name('Sheet0')

    ws=wb['Master_Sheet']

    s = ws.max_row

    for i in range(1,6):

        ws.cell(row=s+1,column=i).value= data[i-1]

    wb.save(path)
