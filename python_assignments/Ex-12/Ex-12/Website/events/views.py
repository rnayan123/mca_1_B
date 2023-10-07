from django.shortcuts import render, redirect
from django.http import HttpResponse

# Create your views here.

food_list = []

def index(request):
    return render(request, "events/layout.html", {
        "foods" : food_list
    })

def addFooditem(request):

    if request.method == "POST":
        if request.POST.get("fooditem") and request.POST.get("quantity") and request.POST.get("price"):
            item ={
                "fooditem" : request.POST.get("fooditem"),
                "quantity" : request.POST.get("quantity"),
                "price" : request.POST.get("price")
            }

            food_list.append(item)


        return render(request, "events/events.html",{
            "foods" : food_list
        })