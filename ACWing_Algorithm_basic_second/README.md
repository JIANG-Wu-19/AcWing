# 算法基础二周目

## 排序

### 快速排序

快速排序的基本思想基于分治法

在待排序表$L[1...n]$任取一个元素pivot作为枢轴（基准）



通过一趟排序待排序表划分为独立的两部分$L[1...k-1]$和$L[1...k+1]$

使得$L[1...k-1]$中的所有元素小于pivot，$L[1...k+1]$中的所有元素大于等于pivot

pivot放在$L[k]$上，称为一次划分



然后在两个独立部分上递归重复上述过程，直到每部分只有一个元素或者空为止

函数实现

```c++
void quick_sort(int num[],int l,int r){
    //终止条件
    if(l>=r) return;
    
    //进行第一部的划分
    int i=l-1,j=r+1,pivot=num[l+r>>1];
    while(i<j){
        do{
            i++;
        }while(num[i]<pivot);
        do{
            j--;
        }while(num[j]>pivot);
        
        //两个异类的交换
        if(i<j) swap(num[i],num[j]);
    }
    
    //进行子部分的递归
    quick_sort(num,l,j),quick_sort(num,j+1,r);
}
```

快排衍生出的topk问题，但是这里应该是减治的思想，因为第k小的数不可能在另外一块区域

```c++
int findK(int num[],int l,int r,int k){
    //终止条件
    if(l>=r) return num[l];
    
    //进行第一部划分
    int i=l-1,j=r+1,pivot=num[l+r>>1];
    
    while(i<j){
        do{
            i++;
        }while(num[i]<pivot);
        do{
            j--;   
        }while(num[j]>pivot);
        
        if(i<j) swap(num[i],num[j]);
    }
    
    //这里运用减治，丢掉其中一部分
    if(j>=k){
        findK(num,l,j,k);
    }else{
        findK(num,j+1,r,k);
    }
}
```

### 归并排序

