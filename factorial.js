const factorial = (n)=>{
    const res = 1;
    while(n>0){
        res*=n;
        n-=1;
    }
    return res;
}