# 算法基础二周目

## 基础算法

### 排序

#### 快速排序

快速排序的基本思想基于分治法

在待排序表$L[1 ...n]$任取一个元素pivot作为枢轴（基准）



通过一趟排序待排序表划分为独立的两部分$L[1 ... k-1]$和$L[1 ...k+1]$

使得$L[1 ...k-1]$中的所有元素小于pivot，$L[1 ...k+1]$中的所有元素大于等于pivot

pivot放在$L[k]$上，称为一次划分



然后在两个独立部分上递归重复上述过程，直到每部分只有一个元素或者空为止

函数实现

```c++
void quick_sort(int num[],int l,int r){
    //终止条件
    if(l>=r) return;
    
    //进行第一步的划分
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
    
    //进行第一步划分
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

#### 归并排序

归并排序也是一个递归的思想，采用分治法

第一步先划分

第二步递归排序

第三步进行子序列融合（归并）

比较复杂的是归并的步骤：**将相邻的两个有序表归并成一个有序表**

两个有序表$A[low...mid]$和$A[mid+1 ...high]$存放在同一顺序表中的相邻位置，并将他们复制到辅助数组B中。

每次从对应B中的两个段取出一个记录进行关键字的比较，将较小者放入A中，当数组B中有一段的下表超出对应的表长，将剩余的另一段中剩余部分直接复制进A中

```c++
int tmp[N];
void Merge(int num[],int low,int mid,int high){
    for(int k=low;k<=high;k++){
        tmp[k]=num[k];
    }
    
    //这一步做的就是双表融合
    for(int i=low,j=mid+1,k=i;i<=mid&&j<=high;k++){
        if(tmp[i]<=tmp[j]){
            num[k]=tmp[i++];
        }else{
            num[k]=tmp[j++];
        }
    }
    
    //将两表中某一个表的剩余部分全部复制过来
    while(i<=mid) num[k++]=tmp[i++];
    while(j<=high) num[k++]=tmp[j++];
}
```

整个归并排序函数的实现

```c++
void merge_sort(int num[],int l,int r){
    //递归终止条件
    if(l>=r) return;
    
	//1.分
	int mid=l+r>>1;
	
	//2.递归排序
	merge_sort(num,l,mid);
	merge_sort(num,mid+1,r);
	
	//3.归并
	for(int i=l;i<=r;i++){
		tmp[i]=num[i];
	} 

	//i在左子序列,j在右子序列 ,k用于定位最终次序 
	int i,j,k;
	for(i=l,j=mid+1,k=i;i<=mid&&j<=r;k++){
		if(tmp[i]<tmp[j]){
			num[k]=tmp[i++];
		}else{
			num[k]=tmp[j++];
		}
	}
	
	//将剩余部分全复制进表
	while(i<=mid)  num[k++]=tmp[i++];
	while(j<=r) num[k++]=tmp[j++];
}
```

### 二分

这是一道二分查找的题目

二分查找肯定发生在一个有序的序列里 **有序才能二分**

二分最难界定的就是边界的取值

题目数的范围中翻译出来就是找到$ \ge x$的第一个数，另一个就是$\le x$的最后一个数

分为两部

1. 查找$ \ge x$的第一个数

   二分找到中点，然后与中点比较

   ```c++
   int l=0.r=n-1;
   while(l<r){
       int mid=l+r>>1;
       if(a[mid]<x) l=mid+1;
       else r=mid;
   }
   ```

2. 查找$\le x$的最后一个数

   有多种写法

   * 从已找到的范围下限开始二分

     ```c++
     int l1=l,r1=n;//由于l1可能是最后一位，r1需要取n
     while(l1+1<r1){
         int mid=l1+r1>>1;
         if(a[mid]<=x) l1=mid;
         else r1=mid;
     }
     ```

   * 从0开始二分查找

     ```c++
     int l1=0,r1=n-1;
     while(l1<r1){
         int mid=l1+r1+1>>1;
         if(a[mid]<=x) l1=mid;
         else r=mid-1;
     }
     ```

完整解决

```c++
#include<bits/stdc++.h>
using namespace std;

const int N=100005;
int n,q,k;
int num[N];

int main(){
    cin>>n>>q;
    
    for(int i=0;i<n;i++){
        cin>>num[i];
    }
    
    for(int i=1;i<=q;i++){
        cin>>k;
        
        //找下限
        int l=0,r=n-1;
        while(l<r){
            int mid=l+r>>1;
            if(num[mid]<k) l=mid+1;
            else r=mid;
        }
        if(num[l]!=k){
            cout<<"-1 -1"<<endl;
            continue;
        }
        
        int l1=l,r1=n;
        while(l1+1<r1){
            int mid=l1+r1>>1;
            if(num[mid]<=k) l1=mid;
            else r1=mid;
        }
        
        cout<<l<<" "<<l1<<endl;
    }
}
```

### 高精度

使用向量来替代数字，将每一位数作为向量元素

使用字符串输入，每一位减掉'0'的ascii码值就是该数字，推进vector

在输入的时候，要记得将数翻过来存储，向量的低位才能是数的低位

#### 高精度加法

补充一位用于进位

```
#include<iostream>
#include<vector>

using namespace std;

const int N=1e6+10;
vector<int> A,B;

vector<int> add(vector<int> &a,vector<int> &b){
    vector<int> c;
    //t用于记录进位
    int t=0;
    for(int i=0;i<a.size()||i<b.size();i++){
        if(i<a.size()) t+=a[i];
        if(i<b.size()) t+=b[i];
        c.push_back(t%10);
        t/=10;
    }
    if(t) c.push_back(1);
    return c;
}

int main(){
    string a,b;
    cin>>a>>b;
    
    //将数翻过来存储，向量的低位才能是数的低位
    for(int i=a.size()-1;i>=0;i--) A.push_back(a[i]-'0');
    for(int i=b.size()-1;i>=0;i--) B.push_back(b[i]-'0');
    
    vector<int> c=add(A,B);
    
    //将数翻过来输出才是高位在前
    for(int i=c.size()-1;i>=0;i--) cout<<c[i];
    
    cout<<endl;
    
    return 0;
}
```



