#include<iostream>
#include<vector>
using namespace std;
//https://blog.csdn.net/king13059595870/article/details/103421774
//https://blog.csdn.net/qq_28584889/article/details/88136498
/*
  因此，我们可以得到下面的结论：当基准数选择最左边的数字时，那么就应该先从右边开始搜索；
  当基准数选择最右边的数字时，那么就应该先从左边开始搜索。不论是从小到大排序还是从大到小排序！
*/
//挖坑法
void quickSort(int left, int right, vector<int>& a)
{
	if (left >= right) return;
	//以第一个元素为基准，执行一趟划分
	int i = left, j = right;
	int t = a[left];
	while (i < j)
	{
		while (i < j && a[j] >= t) //从右向左扫描，选取第一个小于t的元素交换
			j--;
		a[i] = a[j];
		while (i < j && a[i] <= t) //再从左往右扫描，选取第一个大于t的元素交换
			i++;
		a[j] = a[i];
	}
	//std::cout << "base:" << "i:" << i << "," << a[i] << ",j:" << j << "," << a[j]  << std::endl;
	a[i] = t;//基准位放到i和j相等的位置，即一轮判断后的中间位置

	////递归执行划分
	//for (int i = 0; i <= 6; i++) {
	//	cout << a[i] << " ";
	//}
	//cout << endl;
	quickSort(left, i - 1, a);
	quickSort(i + 1, right, a);
}
////左右指针法
//快速排序（从小到大）
void quickSort1(int left, int right, vector<int>& arr)
{
	if (left >= right)
		return;
	int i, j, base, temp;
	i = left, j = right;
	base = arr[left];  //取最左边的数为基准数
	while (i < j)
	{
		while (arr[j] >= base && i < j)
			j--;
		while (arr[i] <= base && i < j)
			i++;
		if (i < j)
		{
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	//基准数归位
	arr[left] = arr[i];
	arr[i] = base;
	quickSort1(left, i - 1, arr);//递归左边
	quickSort1(i + 1, right, arr);//递归右边
}



//左右指针法


//快排是直接修改vector的值，所以vector传引用，这样源vector的内容也被改变了
//快排，排序的是数组，所以可以直接通过下标获得左边的值和右边的值
void QuickSort_my(int left, int right,vector<int> &nums)
{
	//每次递归时都得判断 ，left和right是否合法，
	if (left >= right)
		return;
	//以首元素作为枢纽元素
	int i = left;
	int j = right;
	int pivot = nums[left];
	//这里都是细节呀。遍历到 left 小于right，而不是小于等于

	while (left < right)
	{
		//先从右边找到比枢纽元素小的值,这是一个持续的寻找，直到找到比枢纽元素小的值
		//所以是个while循环持续的找
		//也要控制好边界，i的下标总是小于j的下标
		//如果右边的节点比枢纽 pivot大，就一直向前找nums[right]>privot ，直到找到比枢纽小的值
		while ((left < right) &&( nums[right] >= pivot)  )
		{
			right--;
 
		}
		//开始查询左边比pivot大的值，如果当nums[left]比pivot小，就持续while寻找，直到找到比枢纽值大的，就退出while循环
		while ((left < right) && (nums[left] <= pivot))
		{
			left++;
 
		}
 
		//两个while循环退出后，说明此时左边找到比枢纽大的值，并且右边也找到比枢纽小的值，
		//此时交换两个值
		int temp = nums[left];
		nums[left] = nums[right];
		nums[right] = temp;
	}
	//外出循环退出后，说明此时left = right遍历了一轮。此时需要把枢纽放到中心位置处，
    //枢纽放到中心位置后，相当于把数组分割成了两个部分，左边的都小于枢纽；右边都大于枢纽
	//把枢纽放到 left和right相等的位置
	//当i和j相等的时，此时num[i]和num[j]指向同一个位置，且这个位置肯定比枢纽元素小（这个自己画一画，推导一下就知道了
 
	/*
	nums[i] = nums[right];
	nums[right] = pivot;*/
	nums[i] = nums[left];
	nums[left] = pivot;
	//此时枢纽左边的值都比它小，枢纽右边的值都比它大
	//再继续递归左右区域
	QuickSort_my( i, left-1, nums);
	QuickSort_my(left + 1, j,nums);

 
}



int main() {



	std::vector<int>vec = { 2,4,1,0,3,5 };
	QuickSort_my(0, vec.size()-1, vec);
	cout << "sorted..." << endl;
	for (int i = 0; i< vec.size(); i++) {
		cout << vec[i] << " ";
	}
	//system("pause");
	return 0;
}