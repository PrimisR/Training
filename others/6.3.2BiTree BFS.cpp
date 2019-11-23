#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

const int maxn=300;

char s[maxn];  //�������ڵ�
bool failed; //����Ƿ����ظ���ֵ
vector<int> ans;

struct Node
{
    bool have_value;  //�Ƿ񱻸�ֵ��
    int v;  //�ڵ�ֵ
    Node *left,*right; //���ҽڵ��ָ��
    Node():have_value(false),left(NULL),right(NULL){}   //���캯��
};

Node* newnode() {return new Node();} //����ռ䲢ִ�й��캯��,new��������ռ����ȷָ��

Node* root; //���ڵ�ָ��

void addnode(int v,char* s)//�ַ���char*
{
    int n=strlen(s);
    Node* u=root;  //�Ӹ��ڵ㿪ʼ����
    for(int i=0;i<n;i++) //���ֶ�ȡ�ַ������ź���Ĳ���
    {
        if(s[i]=='L')
        {
            if(u->left==NULL) u->left=newnode(); //�����ڵ�ָ��Ϊ�գ������ã���ô�����¿ռ�
            u=u->left; //������
        }
        else if(s[i]=='R')
        {
            if(u->right==NULL) u->right=newnode();
            u=u->right;
        }
    } //���������������������
    if(u->have_value) failed=true; //������ָýڵ��Ѿ�����ֵ���ˣ���ôʧ��
    u->v=v;
    u->have_value=true;
}

void remove_tree(Node* u)
{
    if(u==NULL) return; //�����ַΪNULL����ô����
    //������ǰ�ж��ǱȽ����׵�
    remove_tree(u->left); //�ݹ��ͷ��������Ŀռ�
    remove_tree(u->right); //�ݹ��ͷ��������Ŀռ�
    delete u; //����u�������������ͷ�u�ڵ㱾����ڴ�
}

bool read_input() //�����ַ��������ض�ȡ�ɹ����
{
    failed=false;
//��̬�����ڴ���ע���ڴ�й©
    remove_tree(root); //�������µ�һ�����ݣ������µ��ڴ�֮ǰ�����ͷ�ԭ�����ڴ棬�Ƴ�ԭ������
    root=newnode(); //�������ڵ㣨�ᱻ�����µĵ�ַ����ôԭ�����ڴ���Ҳ����ˣ��ᵼ���ڴ�й©��
    for(;;)
    {
        if(scanf("%s",s)!=1) return false; //�����������(�������������֮ǰ�ļ��������򷵻�0��������������֪��)
        if(!strcmp(s,"()")) break; //����������־���˳�ѭ����strcmp��ͬ�ַ�������0
        int v;
        sscanf(&s[1],"%d",&v); //��s[1]����ʼ����һ������
        addnode(v,strchr(s,',')+1); //���Ҷ���+1���Ѵ��ַ����������������ַ����뽨���ڵ�
    }
}

bool bfs(vector<int> & ans)  //����
{
    queue<Node*> q; //���Node*ָ��Ķ���
    ans.clear();
    q.push(root);  //������ڵ�
    while(!q.empty())
    {
        Node* u=q.front(); q.pop();
        if(!u->have_value) return false; //�������û�и�ֵ���򷵻�false
        ans.push_back(u->v); //�ѽڵ�ֵ�ŵ�vector��
        if(u->left!=NULL) q.push(u->left);
        if(u->right!=NULL) q.push(u->right); //�������/���ӽڵ㣬��ô�Ž�����
    }
    return true;//������ȷ
}//����һ��boolֵ���Ժܷ���ر����ȷʧ�����

int main()//��ζ�ζ����أ�
{
    read_input();
        bfs(ans);
        for(int i=0;i<ans.size();i++)
            printf("%d\n",ans[i]);
    return 0;
}
