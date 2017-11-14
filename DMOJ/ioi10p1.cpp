void Solve(){
    int i=1, j=1, k=1;
    while(true){
        int ret = Theory(i, j, k);
        if(ret==1) i++;
        else if(ret==2) j++;
        else if(ret==3) k++;
        else return;
    }
}