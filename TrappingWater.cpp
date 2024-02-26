#include <bits/stdc++.h>
long long getTrappedWater(long long* arr, int n) {
    int prefix[n];
    prefix[0]=arr[0];
    for(int i=1;i<n;i++){
        prefix[i]=fmax(prefix[i-1],arr[i]);
    }
    int suffix[n];
    suffix[n-1]=arr[n-1];
    for(int i=n-2;i>=0;i--){
        suffix[i]=fmax(suffix[i+1],arr[i]);
    }

    long long waterTrapped=0;
    for(int i=0;i<n;i++){
        waterTrapped+=fmin(prefix[i],suffix[i])-arr[i];
    }       
    return waterTrapped;
}