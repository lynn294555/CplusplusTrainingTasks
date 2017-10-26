#if !defined _DYNAMICARRAY_H_
#define _DYNAMICARRAY_H_
#include<iostream>
#include<cstring>  // memcpy
#include<cstdlib>  // exit
#include <stdio.h>
#include <stdlib.h>
#include <typeinfo>
#include <string.h>


using namespace std;


template <typename DataType>
class CDArray;                                          //类声明

template <typename DataType>
ostream& operator<<(ostream &os,CDArray<DataType> &s);
//ostream& operator<<(ostream &os,CDArray<DataType> &s);



template <typename DataType>
class CDArray
{
private:
        DataType *m_pData;	// 存放数组的动态内存指针
        int	m_nSize;
        int     m_Max;// 数组的元素个数

private:
        void	Init();		// 初始化
        void	Free();		// 释放动态内存
        inline	int	InvalidateIndex(int nIndex);	// 判断下标的合法性

public:
        CDArray();			// 缺省构造函数
        CDArray(int nSize, DataType dValue = 0);	// 其他构造函数，设置一定数组大小，并设置所有元素为0；当然还可以定义其他不同参数的构造函数，以方便用户使用
        CDArray(const CDArray& arr);	// 拷贝构造函数（最好为所有包含动态分配成员的类都提供拷贝构造函数）
        ~CDArray();		// 析构函数

        //int		Print();				// 输出显示所有数组元素的值
        int		GetSize();			// 获取数组大小（元素个数）
        int		SetSize(int nSize);		// 重新设置数组的大小。注：若nSize小于原数组大小，可截断取前nSize个元素作为新数组的元素；若nSize大于原数组大小，新增的元素的值设置缺省值0即可

        DataType	GetAt(int nIndex);				// 获取某个元素
        DataType 	operator[] (int nIndex) const; 	// 重载[]操作符，以便像传统数组那样通过a[k]来获取元素值
        int		SetAt(int nIndex, DataType dValue);	// 设置某个元素的值

        void		Pushback(DataType dValue);		// 追加一个新的元素到数组末尾
        int            DeleteAt(int nIndex);			// 从数组中删除一个元素
        int		InsertAt(int nIndex, DataType dValue);	// 插入一个新的元素到数组中

        CDArray& operator=(const CDArray& arr);	                      // 重载赋值操作符号"="
        friend ostream& operator<< <DataType> (ostream &os,CDArray<DataType> &s);//模板函数做友元要显式的声明模板形参,（其实是外部函数，直接拿过来用在class里面用）
        //friend ostream& operator<< < >(ostream &os,CDArray<DataType> &s);
};
#endif


template<typename DataType>
void CDArray<DataType>::Init()
{
    m_Max=1;
    m_nSize=0;
    m_pData=new DataType [m_Max];

}
template<typename DataType>
void	CDArray<DataType>::Free()
{
    if (m_pData!=NULL)
        delete m_pData;
    m_pData=NULL;
}
template<typename DataType>
inline	int	CDArray<DataType>::InvalidateIndex(int nIndex)	// 判断下标的合法性
{
    if (nIndex>=0&&nIndex<m_nSize)//*****
    {
        return 0;
    }

    else
    {
        return 1;
    }


}
template<typename DataType>
CDArray<DataType>::CDArray()// 缺省构造函数
{
    Init();
}
template<typename DataType>
CDArray<DataType>::CDArray(int nSize, DataType dValue)// 其他构造函数，设置一定数组大小，并设置所有元素为0；当然还可以定义其他不同参数的构造函数，以方便用户使用
{
    if(nSize==0)
        Init();
    else
    {
        m_nSize=nSize;
        m_Max=nSize*2;
        m_pData=new DataType[m_Max];

        for(int i=0;i<nSize;i++)
        {
            m_pData[i]=dValue;
        }
    }


}
template<typename DataType>
CDArray<DataType>::CDArray(const CDArray& arr)// 拷贝构造函数（最好为所有包含动态分配成员的类都提供拷贝构造函数）
{
    m_nSize=arr.m_nSize;
    m_Max=arr.m_Max;
    m_pData=new DataType [m_Max];
    memcpy(m_pData, arr.m_pData, m_nSize*sizeof(DataType));
    // for(int i=0;i<m_nSize;i++)
    //{
    //    m_pData[i]=arr.m_pData[i];

    //}
}

template<typename DataType>
CDArray<DataType>::~CDArray()		// 析构函数
{
    Free();
}
//template<typename DataType>
//int	CDArray<DataType>::Print()				// 输出显示所有数组元素的值
//{
//    if(m_nSize==0)
//    {
//        cout<<"error";
//        return 0;
//    }
//    for(int i=0;i<m_nSize;++i)
//    {
//        char const *typen = typeid( DataType).name();
//        if( !strcmp( typen, "double" ) )
//                printf(" type: %lf ", m_pData[i] );
//        else if( !strcmp( typen, "int" ) )
//                printf(" type: %d ", m_pData[i] );
//        else if( !strcmp(typen,"char"))
//            cout<<m_pData[i]<<" ";

//        printf("\n");

//    }
//    return 1;
//}
template<typename DataType>
int	CDArray<DataType>::GetSize()			// 获取数组大小（元素个数）
{
    return m_nSize;
}
template<typename DataType>
int	CDArray<DataType>::SetSize(int nSize)		// 重新设置数组的大小。注：若nSize小于原数组大小，可截断取前nSize个元素作为新数组的元素；若nSize大于原数组大小，新增的元素的值设置缺省值0即可
{
    if(nSize<m_nSize)
    {

        for(int i=nSize; i<m_nSize; ++i)
            m_pData[i] = 0;


    }
    if(m_nSize<=nSize&&nSize<=m_Max)
    {
        for(int i=m_nSize;i<nSize-1;++i)//hedfjhwefihwigh
        {
            m_pData[i]=0;
        }

    }

    //donot forgot this situation
    if(nSize>m_Max)
    {
        m_Max=2*nSize;
        DataType *temp=new DataType[m_Max];
        memcpy(temp, m_pData, m_nSize*sizeof(DataType));
        for(int i=m_nSize;i<nSize;++i)//zhe ge di fang xu yao ba m_nSize yi hou de she wei 0
        {
            temp[i]=0;

        }
        delete [] m_pData;
        m_pData=temp;
    }
    m_nSize=nSize;
    return 1;
}
template<typename DataType>
DataType	CDArray<DataType>::GetAt(int nIndex)			// 获取某个元素
{
    if(InvalidateIndex(nIndex))
    {
        cout<<"invalidate index input"<<endl;
        exit(0) ;
    }
    else
    {
        return m_pData[nIndex];
    }
}
template<typename DataType>
DataType 	CDArray<DataType>::operator[] (int nIndex) const// 重载[]操作符，以便像传统数组那样通过a[k]来获取元素值
{
    if(nIndex<0 || nIndex>=m_nSize)
    {
        cout << "Error: the index in [] is invalid!" << endl;
        exit(0);
    }
    return m_pData[nIndex];
}
template<typename DataType>
int		CDArray<DataType>::SetAt(int nIndex, DataType dValue)	// 设置某个元素的值
{
    if(InvalidateIndex(nIndex))
    {
        cout<<"invalidate index input"<<endl;
        return 0;
    }
    else
    {
        m_pData[nIndex]=dValue;
        return 1;
    }
}
template<typename DataType>
void CDArray<DataType>::Pushback(DataType dValue)
{
        if(m_nSize < m_Max)
        {
                m_pData[m_nSize] = dValue;
        }
        else
        {
                m_Max = m_Max*2;
                DataType* temp = new DataType[m_Max];
                memcpy(temp, m_pData, m_nSize*sizeof(DataType));
                delete [] m_pData;
                m_pData = temp;
                m_pData[m_nSize] = dValue;
        }
        ++m_nSize;  /*数组大小加1*/
}





template<typename DataType>
int	CDArray<DataType>::DeleteAt(int nIndex)		// 从数组中删除一个元素
{
    if(InvalidateIndex(nIndex))
    {
        cout<<"invalidate index input"<<endl;
        return 0;
    }
    else
    {
        for(int i =nIndex ;i<m_nSize;++i)
            m_pData[i]=m_pData[i+1];
        m_pData[m_nSize-1]=0;
        --m_nSize;
        return 1;
    }



}
template<typename DataType>
int	CDArray<DataType>::InsertAt(int nIndex, DataType dValue)
{
    if( InvalidateIndex(nIndex) )
    {
        cout<<"Index is invalide in InsertAt()!"<<endl;
        return 0;
    }
    if(m_nSize<m_Max)
    {
        for( int i=m_nSize-1; i>=nIndex; --i )
        {
            m_pData[i+1] = m_pData[i];
        }
        m_pData[nIndex]=dValue;
    }
    else
    {

        m_Max = m_Max*2;
        DataType* temp = new DataType[m_Max];
        memcpy(temp, m_pData, m_nSize*sizeof(DataType));
        delete [] m_pData;
        m_pData = temp;
        for(int i=m_nSize-1; i>=nIndex; --i)
            m_pData[i+1] = m_pData[i];
        m_pData[nIndex] = dValue;
    }

    ++m_nSize;
    return 1;
}	// 插入一个新的元素到数组中

    // 重载赋值操作符号"="
template<typename DataType>
CDArray<DataType>& CDArray<DataType>::operator=(const CDArray<DataType> & arr)
 //CDArray& CDArray<DataType>::operator=(const CDArray& arr)
{
    if(this == &arr)  /*自赋值*/
        return *this;
    m_nSize = arr.m_nSize;
    m_Max = arr.m_Max;
    /* 先将右侧对象拷贝到临时对象中，然后再销毁左侧对象*/
    DataType *m_Temp = new DataType[m_Max];
    memcpy(m_Temp, arr.m_pData, m_nSize*sizeof(DataType));
    delete [] m_pData;
    m_pData = m_Temp;

    return *this;
}


template<typename DataType>
ostream& operator<< (ostream &os,CDArray<DataType> &s)
{
    for(int i=0;i<s.m_nSize;++i)
    {
        os<<s.m_pData[i]<<" ";

    }
    return os;
}
//注释：输出运算符重载的时候<<，operator重载函数要在类前全局声明，而且只有在public底下<<后需要加入<DataType>
//解释为operator<< <T>这样的形式只能放在类中//表明template operator<<和class共用同样的模版参数
//friend ostream& operator<< <DataType> (ostream &os,CDArray<DataType> &s);





