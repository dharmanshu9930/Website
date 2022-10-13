def binary_search(l,low,high,val):
    if high<low:
        return None
    else:
        mid=low+((high-low)//2)
        
        if l[mid]>val:
            return binary_search(l,low,mid-1,val)
        elif l[mid]<val:
            return binary_search(l,mid+1,high,val)
        else:
            return mid
l=[12,23,34,43,56,67,78,89,98]
print(binary_search(l,0,8,56))
