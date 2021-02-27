lst_old = ['Hello', 'World', 18, 'Apple', None]

lst_str_lower = [ele.lower() for ele in lst_old if isinstance(ele, str)]
lst_str_lower_all = [str(ele).lower() if not isinstance(ele, str) else ele.lower() for ele in lst_old]

print(lst_str_lower)
print(lst_str_lower_all)
