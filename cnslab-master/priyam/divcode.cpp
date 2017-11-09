void sub ( int a[],int b[],int res[]){
    for(int i=0;i<8;i++){
        res[i]=a[i]^b[i];

    }
}
void copy_array(int src[],int dest[]){
    for(int i=8;i>=0;i--)
        dest[i]=src[i];
}

void multiply_by_x(int a[],int res[]){
    for(int i=8;i>=0;i--){
        res[i]=a[i-1];
    }
    res[0]=0;
    if(res[8]==1){
        add(res,mod_array,res);
    }
}
void multiply_with_k(int a[],int k,int res[]){
        int new_res[9];
        for(int i=0;i<8;i++){
            res[i]=a[i];
        }
        for(int i=0;i<k;i++){
            memset(new_res,0,sizeof(new_res));
            multiply_by_x(res,new_res);
                for(int i=0;i<8;i++){
                    res[i]=new_res[i];
                }
        }
}
void division_poly(int a[],int b[],int res[],int reminder[]){

    int new_res[9],temporary[9];
    memset(new_res,0,sizeof(new_res));
    memset(temporary,0,sizeof(temporary));
    int maxdegb=find_maxdegree(b);
    if(maxdegb==-1){
        copy_array(res,a);
        return ;
    }
    int maxdega=find_maxdegree(a);
    while(maxdega>=maxdegb){
        int dif=maxdega-maxdegb;
        res[dif]=1;
        multiply_with_k(b,dif,temporary);
        sub(a,temporary,new_res);
        copy_array(new_res,a);
        maxdega=find_maxdegree(a);
    }

    cout<<"Quotient\n";
    print_array(res);
    cout<<"Reminder\n";
    print_array(a);
}