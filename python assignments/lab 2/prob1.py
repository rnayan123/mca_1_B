mylist=["food item id","food item name","description","price","category"]
mylist2=["lastname,email,phonenumber"]
i=0
mylist.append("avaibility")
mylist.insert(2,"firstname")
mylist.extend(mylist2)
dict={"hyundai":"creta","tata":"nexon","suzuki":"swift"}
mylist.append(dict)
for i in range(0,len(mylist)):
    print(mylist[i])