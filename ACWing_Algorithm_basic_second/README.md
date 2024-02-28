# 算法基础二周目

## 排序

### 快速排序

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

### 归并排序

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



