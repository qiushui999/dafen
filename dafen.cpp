#include<iostream>
#include<string>
#include<vector>
#include<deque>
#include<algorithm>
using namespace std;

class Person
{
public:
    Person(string name,float score)
    {
        this->m_name=name;
        this->m_score=score;
    }
    string m_name;
    float m_score;//平均分
};

void CreatePeason(vector<Person>&v)
{
    string nameseed="ABCDE";
    int score=0;
    for(int i=0;i<5;i++)
    {
        string name="选手";
        name += nameseed[i];
        score=0;
        Person p(name,score);
        
        v.push_back(p);//将选手放入容器中
    }
}
void PrintPeason(vector<Person>&v)
{
    for(vector<Person>::iterator it=v.begin();it!=v.end();it++)
    {
        cout<<"选手名字："<<(*it).m_name<<"  "
            <<"选手分数："<<(*it).m_score<<endl;
    }
}

void SetScore(vector<Person>&v)
{
    int num=1;
    float score=0;
    
    for(vector<Person>::iterator it=v.begin();it!=v.end();it++)//遍历
    {
        float sum=0;
        deque<float>d;//将评委分数放入deque容器中
        cout<<"第"<<num<<"个选手，请打分："<<endl;
        for(int i=0;i<5;i++)
        {
            cout<<"评委"<<i+1<<"打分：";
            cin>>score;
            d.push_back(score);
        }
        num++;
        sort(d.begin(),d.end());//排序
        d.pop_back();
        d.pop_front();//去除最大最小值
        
        for(deque<float>::iterator dit=d.begin();dit!=d.end();dit++)
        {
            sum+=*dit;
        }
        float avg=sum/d.size();//平均分
        it->m_score=avg;
    }
}
bool mycompare(Person &p1,Person&p2)
{
    return p1.m_score>p2.m_score;
}
//打分系统
int main()
{

    vector<Person>v;//存放选手容器

    CreatePeason(v);//创建选手

    // vector<Person>::iterator it=v.begin();//创建迭代器

    // cout<<(*it).m_name<<(*it).m_score<<endl;
    // it++;
    // cout<<(*it).m_name<<endl;
    //打分
    SetScore(v);
    PrintPeason(v);
    sort(v.begin(),v.end(),mycompare);
    cout<<"排序后"<<endl;
    PrintPeason(v);




    system("pause");
}
