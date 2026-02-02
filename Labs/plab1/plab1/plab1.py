def calculate_delivery_cost(weight, price, address_type, customer_type="regular", remote=False):

    if weight <= 0 or weight > 50:
        if weight <= 0:
            return {"success": False, "cost": 0.0, "message": "вес заказа должен быть положительным числом"}
        else:
            return {"success": False, "cost": 0.0, "message": "максимальный вес для доставки: 50 кг"}
    
    if price < 1000:
        return {"success": False, "cost": 0.0, "message": "минимальная стоимость заказа для доставки: 1000 рублей"}
    
    if address_type == "самовывоз":
        return {"success": True, "cost": 0.0, "message": "самовывоз"}
    
    if not remote and (customer_type == "vip" and price >= 5000 or price >= 10000):
        if customer_type == "vip":
            return {"success": True, "cost": 0.0, "message": "бесплатная доставка для VIP-клиента"}
        else:
            return {"success": True, "cost": 0.0, "message": "бесплатная доставка при заказе от 10000 рублей"}
    
    if address_type == "Нижнекамск":
        if weight < 5:
            cost = 300
        elif weight <= 10:
            cost = 500
        else:
            cost = 500 + (weight - 10) * 50
    else:
        cost = 1000 + weight * 100
    
    if remote:
        cost = cost * 1.2
    
    if customer_type == "new":
        cost = cost * 0.85
    
    return {"success": True, "cost": round(cost, 2), "message": "Стоимость доставки рассчитана"}


print("заказ с нулевым весом")
print(calculate_delivery_cost(weight=0, price=2000, address_type="Нижнекамск"))
print()

print("cамовывоз")
print(calculate_delivery_cost(weight=5, price=2000, address_type="самовывоз"))
print()

print("VIP-клиент с заказом от 5000 рублей")
print(calculate_delivery_cost(weight=3, price=6000, address_type="Нижнекамск", customer_type="vip"))
print()

print("новый клиент")
print(calculate_delivery_cost(weight=3, price=2000, address_type="Нижнекамск", customer_type="new"))
print()

print("отдаленный регион")
print(calculate_delivery_cost(weight=3, price=2000, address_type="Нижнекамск", remote=True))
print()

print("заказ от 10000 рублей в неотдаленный регион")
print(calculate_delivery_cost(weight=2, price=12000, address_type="Нижнекамск"))
print()

print("вес более 50 кг")
print(calculate_delivery_cost(weight=55, price=2000, address_type="Нижнекамск"))
print()

print("заказ менее 1000 рублей")
print(calculate_delivery_cost(weight=2, price=500, address_type="Нижнекамск"))
print()