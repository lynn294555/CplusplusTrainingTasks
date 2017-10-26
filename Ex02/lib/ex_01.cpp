#include "ex_01.h"

using namespace std;


void CDArray::Init()
{
    m_Max=1;
    m_nSize=0;
    m_pData=new double [m_Max];

}
void	CDArray::Free()
{
    if (m_pData!=NULL)
        delete m_pData;
    m_pData=NULL;
}

inline	int	CDArray::InvalidateIndex(int nIndex)	// 判断下标的合法性
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
CDArray::CDArray()// 缺省构造函数
{
    Init();
}
CDArray::CDArray(int nSize, double dValue)// 其他构造函数，设置一定数组大小，并设置所有元素为0；当然还可以定义其他不同参数的构造函数，以方便用户使用
{
    if(nSize==0)
        Init();
    else
    {
        m_nSize=nSize;
        m_Max=nSize*2;
        m_pData=new double[m_Max];

        for(int i=0;i<nSize;i++)
        {
            m_pData[i]=dValue;
        }
    }


}

CDArray::CDArray(const CDArray& arr)// 拷贝构造函数（最好为所有包含动态分配成员的类都提供拷贝构造函数）
{
    m_nSize=arr.m_nSize;
    m_Max=arr.m_Max;
    m_pData=new double [m_Max];
    memcpy(m_pData, arr.m_pData, m_nSize*sizeof(double));
    // for(int i=0;i<m_nSize;i++)
    //{
    //    m_pData[i]=arr.m_pData[i];

    //}
}


CDArray::~CDArray()		// 析构函数
{
    Free();
}

void		CDArray::Print()				// 输出显示所有数组元素的值
{
    if(m_nSize==0)
    {
        cout<<"error";
        exit(0);

    }
    else
    {
        for(int i =0;i<m_nSize;++i)//*****++i not i++
            cout<<m_pData[i]<<" ";


    } cout<<endl;
}

int		CDArray::GetSize()			// 获取数组大小（元素个数）
{
    return m_nSize;
}
int		CDArray::SetSize(int nSize)		// 重新设置数组的大小。注：若nSize小于原数组大小，可截断取前nSize个元素作为新数组的元素；若nSize大于原数组大小，新增的元素的值设置缺省值0即可
{
    if(nSize<m_nSize)
    {

        for(int i=nSize; i<m_nSize; ++i)
            m_pData[i] = 0;


    }
    if(m_nSize<=nSize&&nSize<=m_Max)
    {
        for(int i=m_nSize;i<nSize-1;i++)//hedfjhwefihwigh
        {
            m_pData[i]=0;
        }

    }

    //donot forgot this situation
    if(nSize>m_Max)
    {
        m_Max=2*nSize;
        double *temp=new double[m_Max];
        memcpy(temp, m_pData, m_nSize*sizeof(double));
        for(int i=m_nSize;i<nSize;++i)//zhe ge di fang xu yao ba m_nSize yi hou de she wei 0
        {
            temp[i]=0;
            delete [] m_pData;
            m_pData=temp;
        }

    }
    m_nSize=nSize;
    return 1;
}
double	CDArray::GetAt(int nIndex)			// 获取某个元素
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
double 	CDArray::operator[] (int nIndex) const// 重载[]操作符，以便像传统数组那样通过a[k]来获取元素值
{
    if(nIndex<0 || nIndex>=m_nSize)
    {
        cout << "Error: the index in [] is invalid!" << endl;
        exit(0);
    }
    return m_pData[nIndex];
}
int		CDArray::SetAt(int nIndex, double dValue)	// 设置某个元素的值
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


int		CDArray::PushBack(double dValue)		// 追加一个新的元素到数组末尾
{
    if(m_nSize<m_Max)
    {
        m_pData[m_nSize]=dValue;
    }
    else
    {
        m_Max=2*m_Max;
        double *temp=new double[m_Max];
        memcpy(temp, m_pData, m_nSize*sizeof(double));

        delete [] m_pData;
        m_pData=temp;
        m_pData[m_nSize]=dValue;
    }

    ++m_nSize;

    return 1;

}


int		CDArray::DeleteAt(int nIndex)		// 从数组中删除一个元素
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
int		CDArray::InsertAt(int nIndex, double dValue)
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
        double* temp = new double[m_Max];
        memcpy(temp, m_pData, m_nSize*sizeof(double));
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
 CDArray& CDArray::operator=(const CDArray& arr)
{
    if(this == &arr)  /*自赋值*/
        return *this;
    m_nSize = arr.m_nSize;
    m_Max = arr.m_Max;
    /* 先将右侧对象拷贝到临时对象中，然后再销毁左侧对象*/
    double *m_Temp = new double[m_Max];
    memcpy(m_Temp, arr.m_pData, m_nSize*sizeof(double));
    delete [] m_pData;
    m_pData = m_Temp;

    return *this;
}




