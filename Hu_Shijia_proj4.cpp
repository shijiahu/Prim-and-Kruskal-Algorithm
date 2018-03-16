//
//  main.cpp
//  Prim
//
//  Created by shijia hu on 4/24/17.
//  CopyrimatrixAht © 2017 shijia hu. All rimatrixAhts reserved.
//

#include <iostream>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

#define Ver 15
#define infinity 100
using namespace std;

int prim[15] = {0};
int set[15] = {0};
int height[15] = {0};
int edge[100][3];
int edge2[100][3];
int T[15][3];

int find3(int x){
    int root = x;
    while (root!= set[root]) {
        root = set[root];
        
    }
    int node  = x;
    int parent;
    
    while (node!=root) {
        parent = set[node];
        set[node] = root;
        node = parent;
    }
    
    return root;
}

void union3(int repx, int repy){
    if (height[repx] == height[repy]) {
        height[repx]++;
        set[repy] = repx;
    }else if (height[repx] > height[repy])
            set[repy] = repx;
        else set[repx] = repy;
}

void insertionSort(int *array, int n){
    int temp[3], j;
    for (int i = 1; i < n; i++) {
        temp[2] = array[i*3 + 2];
        temp[1] = array[i*3 + 1];
        temp[0] = array[i*3 + 0];
        if(temp[2] < array[(i-1)*3 +2])
        {
            for (j = i-1; j >= 0 && temp[2] < array[j*3 + 2]; j--) {
                array[(j+1)*3 +2] = array[(j*3) +2];
                 array[(j+1)*3 +1] = array[(j*3) +1];
                 array[(j+1)*3 +0] = array[(j*3) +0];
                
            }
            array[(j+1)*3 +2] = temp[2];
            array[(j+1)*3 +1] = temp[1];
            array[(j+1)*3 +0] = temp[0];
        }
    }
}



void myPrim(int **graph, int n){
    int parent[Ver]; // Array to store constructed MST
    int key[Ver];   // Key values used to pick minimum weight edge in cut
    bool mstSet[Ver]; // To represent set of vertices not yet included in MST
    int min, min_index;

    for (int i = 0; i < n; i++)
        key[i] = 250, mstSet[i] = false;
    

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < n-1; count++)
    {

        min = 250;
        min_index = 0;
        
        for (int v = 0; v < n; v++)
            if (mstSet[v] == false && key[v] < min)
                min = key[v], min_index = v;
        
        int u = min_index;
        
        mstSet[u] = true;

        for (int v = 0; v < n; v++)
 
            if (graph[u][v] && mstSet[v] == false && graph[u][v] <  key[v])
                parent[v]  = u, key[v] = graph[u][v];
    }
 
    for (int i = 1; i < n; i++)
        cout<<"V"<<parent[i]<<"---V"<<i<<"  Weight "<<graph[i][parent[i]]<<endl;
}
                       
                       
                       
void myKruskal(int **matrixA, int n){
    int k = 0;
    
    for (int i = 0; i<n; i++) {
        for (int j = 1; j<n ; j++) {
            if (i != j && i < j) {
                edge[k][0] = i;
                edge[k][1] = j;
                edge[k][2] = matrixA[i][j];
                k++;
            }
        }
    }
//            for (int i = 0; i<k; i++) {
//                for (int j = 0; j<3; j++) {
//                    cout<<edge[i][j]<<" ";
//                }
//                cout<<endl;
//            }
    
    
//    for (int i = 0; i<n; i++) {
//        for (int j = 0; j<n; j++) {
//            edge[i][0] = j;
//            edge[i][1] = j;
//            edge[i][2] = matrixA[i][j];
//        }
//    }
    insertionSort(*edge, k);
    
//    cout<<"+++++++++++++++++++++++++"<<endl;
//    for (int i = 0; i<k; i++) {
//        for (int j = 0; j<3; j++) {
//            cout<<edge[i][j]<<" ";
//        }
//        cout<<endl;
//    }
    
    k =0 ;
    
    for (int i = 0; i<n; i++) {

        set[i]= i;
    }
    
    for (int i = 0; i<n-1 ;) {
        
        int ucomp = find3(edge[k][0]);
        int vcomp = find3(edge[k][1]);

        if (ucomp != vcomp) {
            T[i][0] = edge[k][0];
            T[i][1] = edge[k][1];
            union3(ucomp, vcomp);
            
            cout<<"V"<<T[i][0]<<"---V"<<T[i][1]<<"  Weight "<<edge[k][2]<<endl;
            i++;
        }
        k++;
    }
    
    
    
}


int main() {
    
    
    while(1){
        srand(time(0));
        int n;
        n = rand() % (10-5+1)+5;
        
        cout<<"Selected n = "<<n<<endl;
        
        int **matrixA;
        matrixA = new int *[n+1];
        for (int i = 0; i<n; i++) {
            matrixA[i] = new int[n+1];
        }
        for (int i = 0; i<n; i++) {
            matrixA[i][i] = 0;
        }
        for (int i = 0; i<n; i++) {
            for (int j = 1; j<n ; j++) {
                if (i != j && i < j) {
                    matrixA[i][j] = rand() % n + 1;
                    matrixA[j][i] = matrixA[i][j];
                }
            }
        }
        
        
        for (int i = 0; i<n; i++) {
            for (int j = 0; j<n; j++) {
                cout<<matrixA[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<"*****************************************************"<<endl;
        cout<<"************* 1   Prim’s                *************"<<endl;
        cout<<"************* 2   Kruskal’s             *************"<<endl;
        cout<<"*****************************************************"<<endl;
        
        int number;
//        int flamatrixAflamatrixAflamatrixA = 0;
//        int flamatrixAflamatrixA = 0;
        
        while (1) {
            cout<<"Please select a minimum spanning tree algorithm(1-2):"<<endl;
            cin>>number;
            if (number != 1 && number != 2) {
                cout<<"Wrong number of selection!"<<endl;
            }else{
                break;
            }
        }
        switch (number) {
            case 1:
                int father[15];
                myPrim(matrixA,n);
                cout<<endl<<endl;
                break;
            case 2:
                myKruskal(matrixA,n);
                cout<<endl<<endl;
                break;
            default:
                break;
        }
//        printf("Input any character to continue or input N to exit:");
//        char icontinue;
//        scanf("\n%c",&icontinue);
//        if (icontinue =='N' || icontinue =='n') {
//            break;
//        }

    }

    
//    n = 5;
//    int m[5][5] = {{0, 2, 100, 6, 100},
//        {2, 0, 3, 8, 5},
//        {100, 3, 0, 100, 7},
//        {6, 8, 100, 0, 9},
//        {100, 5, 7, 9, 0},
//    };
//        for (int i = 0; i<n; i++) {
//            for (int j = 0; j<n ; j++) {
//    
//                    matrixA[i][j] = m[i][j];
//    
//            }
//        }
//    
////    int father[5];
////    myPrim(matrixA, n, father);
//    myKruskal(matrixA,n);
    
    return 0;
//        printf("Input any character to continue or input N to exit:");
//        char icontinue;
//        scanf("\n%c",&icontinue);
//        if (icontinue =='N' || icontinue =='n') {
//            break;
//        }
    
}
