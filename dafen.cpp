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
    float m_score;//ƽ����
};

void CreatePeason(vector<Person>&v)
{
    string nameseed="ABCDE";
    int score=0;
    for(int i=0;i<5;i++)
    {
        string name="ѡ��";
        name += nameseed[i];
        score=0;
        Person p(name,score);
        
        v.push_back(p);//��ѡ�ַ���������
    }
}
void PrintPeason(vector<Person>&v)
{
    for(vector<Person>::iterator it=v.begin();it!=v.end();it++)
    {
        cout<<"ѡ�����֣�"<<(*it).m_name<<"  "
            <<"ѡ�ַ�����"<<(*it).m_score<<endl;
    }
}

void SetScore(vector<Person>&v)
{
    int num=1;
    float score=0;
    
    for(vector<Person>::iterator it=v.begin();it!=v.end();it++)//����
    {
        float sum=0;
        deque<float>d;//����ί��������deque������
        cout<<"��"<<num<<"��ѡ�֣����֣�"<<endl;
        for(int i=0;i<5;i++)
        {
            cout<<"��ί"<<i+1<<"��֣�";
            cin>>score;
            d.push_back(score);
        }
        num++;
        sort(d.begin(),d.end());//����
        d.pop_back();
        d.pop_front();//ȥ�������Сֵ
        
        for(deque<float>::iterator dit=d.begin();dit!=d.end();dit++)
        {
            sum+=*dit;
        }
        float avg=sum/d.size();//ƽ����
        it->m_score=avg;
    }
}
bool mycompare(Person &p1,Person&p2)
{
    return p1.m_score>p2.m_score;
}
//���ϵͳ
int main()
{

    vector<Person>v;//���ѡ������

    CreatePeason(v);//����ѡ��

    // vector<Person>::iterator it=v.begin();//����������

    // cout<<(*it).m_name<<(*it).m_score<<endl;
    // it++;
    // cout<<(*it).m_name<<endl;
    //���
    SetScore(v);
    PrintPeason(v);
    sort(v.begin(),v.end(),mycompare);
    cout<<"�����"<<endl;
    PrintPeason(v);




    system("pause");
}
