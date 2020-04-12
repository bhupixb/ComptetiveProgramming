ll Euler(int mod){
    ll res = mod;
    
    for(int i = 2 ; i * i <= mod ; i++){
        if(mod % i == 0){
            res = (res * (i - 1))/i;
            while(mod % i == 0)
                mod /= i;
        }
    }
    if(mod > 1)
        res = (res * (mod - 1))/mod;
    return res;
}