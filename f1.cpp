#include <bits/stdc++.h>
#define MAX 1000001
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#define ll long long
#define SIZE 5005
using namespace std;
ll n,Q,t,a,b,v,k;
int smallest,maxXor;
ll wt[SIZE],tree[SIZE][SIZE],treeEnd[SIZE],allParents[SIZE];
void parentDFS(ll node,ll parent);
void dfs(ll node);

class FastInput {
    public:
        FastInput() {
                        m_dataOffset = 0;
                        m_dataSize = 0;
                        m_v = 0x80000000;
                }
                uint32_t ReadNext() {
                        if (m_dataOffset == m_dataSize) {
                                int r = read(0, m_buffer, sizeof(m_buffer));
                                if (r <= 0) return m_v;
                                m_dataOffset = 0;
                                m_dataSize = 0;
                                int i = 0;
                                if (m_buffer[0] < '0') {
                                        if (m_v != 0x80000000) {
                                                m_data[m_dataSize++] = m_v;
                                                m_v = 0x80000000;
                                        }
                                        for (; (i < r) && (m_buffer[i] < '0'); ++i);
                                }
                                for (; i < r;) {
                                        if (m_buffer[i] >= '0') {
                                                m_v = m_v * 10 + m_buffer[i] - 48;
                                                ++i;
                                        } else {
                                                m_data[m_dataSize++] = m_v;
                                                m_v = 0x80000000;
                                                for (i = i + 1; (i < r) && (m_buffer[i] < '0'); ++i);
                                        }
                                }
                        }
                        return m_data[m_dataOffset++];
                }
        public:
                uint8_t m_buffer[32768];
                uint32_t m_data[16384];
                size_t m_dataOffset, m_dataSize;
                uint32_t m_v;
};
class FastOutput {
        public:
                FastOutput() {
                        m_dataOffset = 0;
                }
                ~FastOutput() {
                }
                void Flush() {
                        if (m_dataOffset) {
                                if (write(1, m_data, m_dataOffset));
                                m_dataOffset = 0;
                        }
                }
                void PrintUint(uint32_t v, char d) {
                        if (m_dataOffset + 11 > sizeof(m_data)) Flush();
                        if (v < 100000) {
                                if (v < 1000) {
                                        if (v < 10) {
                                                m_data[m_dataOffset + 0] = v + 48;
                                                m_dataOffset += 1;
                                        } else if (v < 100) {
                                                m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48; v /= 10;
                                                m_data[m_dataOffset + 0] = v + 48;
                                                m_dataOffset += 2;
                                        } else {
                                                m_data[m_dataOffset + 2] = v - v / 10 * 10 + 48; v /= 10;
                                                m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48; v /= 10;
                                                m_data[m_dataOffset + 0] = v + 48;
                                                m_dataOffset += 3;
                                        }
                                } else {
                                        if (v < 10000) {
                                                m_data[m_dataOffset + 3] = v - v / 10 * 10 + 48; v /= 10;

                                                m_data[m_dataOffset + 2] = v - v / 10 * 10 + 48; v /= 10;

                                                m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48; v /= 10;

                                                m_data[m_dataOffset + 0] = v + 48;

                                                m_dataOffset += 4;

                                        } else {

                                                m_data[m_dataOffset + 4] = v - v / 10 * 10 + 48; v /= 10;

                                                m_data[m_dataOffset + 3] = v - v / 10 * 10 + 48; v /= 10;

                                                m_data[m_dataOffset + 2] = v - v / 10 * 10 + 48; v /= 10;

                                                m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48; v /= 10;

                                                m_data[m_dataOffset + 0] = v + 48;

                                                m_dataOffset += 5;

                                        }

                                }

                        } else {

                                if (v < 100000000) {

                                        if (v < 1000000) {

                                                m_data[m_dataOffset + 5] = v - v / 10 * 10 + 48; v /= 10;

                                                m_data[m_dataOffset + 4] = v - v / 10 * 10 + 48; v /= 10;

                                                m_data[m_dataOffset + 3] = v - v / 10 * 10 + 48; v /= 10;

                                                m_data[m_dataOffset + 2] = v - v / 10 * 10 + 48; v /= 10;

                                                m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48; v /= 10;

                                                m_data[m_dataOffset + 0] = v + 48;

                                                m_dataOffset += 6;

                                        } else if (v < 10000000) {

                                                m_data[m_dataOffset + 6] = v - v / 10 * 10 + 48; v /= 10;

                                                m_data[m_dataOffset + 5] = v - v / 10 * 10 + 48; v /= 10;

                                                m_data[m_dataOffset + 4] = v - v / 10 * 10 + 48; v /= 10;

                                                m_data[m_dataOffset + 3] = v - v / 10 * 10 + 48; v /= 10;

                                                m_data[m_dataOffset + 2] = v - v / 10 * 10 + 48; v /= 10;

                                                m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48; v /= 10;

                                                m_data[m_dataOffset + 0] = v + 48;

                                                m_dataOffset += 7;

                                        } else {

                                                m_data[m_dataOffset + 7] = v - v / 10 * 10 + 48; v /= 10;

                                                m_data[m_dataOffset + 6] = v - v / 10 * 10 + 48; v /= 10;

                                                m_data[m_dataOffset + 5] = v - v / 10 * 10 + 48; v /= 10;

                                                m_data[m_dataOffset + 4] = v - v / 10 * 10 + 48; v /= 10;

                                                m_data[m_dataOffset + 3] = v - v / 10 * 10 + 48; v /= 10;

                                                m_data[m_dataOffset + 2] = v - v / 10 * 10 + 48; v /= 10;

                                                m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48; v /= 10;

                                                m_data[m_dataOffset + 0] = v + 48;

                                                m_dataOffset += 8;

                                        }

                                } else {

                                        if (v < 1000000000) {

                                                m_data[m_dataOffset + 8] = v - v / 10 * 10 + 48; v /= 10;

                                                m_data[m_dataOffset + 7] = v - v / 10 * 10 + 48; v /= 10;

                                                m_data[m_dataOffset + 6] = v - v / 10 * 10 + 48; v /= 10;

                                                m_data[m_dataOffset + 5] = v - v / 10 * 10 + 48; v /= 10;

                                                m_data[m_dataOffset + 4] = v - v / 10 * 10 + 48; v /= 10;

                                                m_data[m_dataOffset + 3] = v - v / 10 * 10 + 48; v /= 10;

                                                m_data[m_dataOffset + 2] = v - v / 10 * 10 + 48; v /= 10;

                                                m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48; v /= 10;

                                                m_data[m_dataOffset + 0] = v + 48;

                                                m_dataOffset += 9;

                                        } else {

                                                m_data[m_dataOffset + 9] = v - v / 10 * 10 + 48; v /= 10;

                                                m_data[m_dataOffset + 8] = v - v / 10 * 10 + 48; v /= 10;

                                                m_data[m_dataOffset + 7] = v - v / 10 * 10 + 48; v /= 10;

                                                m_data[m_dataOffset + 6] = v - v / 10 * 10 + 48; v /= 10;

                                                m_data[m_dataOffset + 5] = v - v / 10 * 10 + 48; v /= 10;

                                                m_data[m_dataOffset + 4] = v - v / 10 * 10 + 48; v /= 10;

                                                m_data[m_dataOffset + 3] = v - v / 10 * 10 + 48; v /= 10;

                                                m_data[m_dataOffset + 2] = v - v / 10 * 10 + 48; v /= 10;

                                                m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48; v /= 10;

                                                m_data[m_dataOffset + 0] = v + 48;

                                                m_dataOffset += 10;

                                        }

                                }

                        }

                        m_data[m_dataOffset++] = d;

                }

                void PrintChar(char d) {

                        if (m_dataOffset + 1 > sizeof(m_data)) Flush();

                        m_data[m_dataOffset++] = d;

                }

                void ReplaceChar(int offset, char d) {

                        m_data[m_dataOffset + offset] = d;

                }



        public:

                uint8_t m_data[32768];

                size_t m_dataOffset;

};



FastInput g_fi;

FastOutput g_fo;
int main()
{
   /* int n,t,ans;
    t=g_fi.ReadNext();
    while(t--)
    {
        n=g_fi.ReadNext();
        ans=n%6;
        if(ans==0 || ans==1)
            g_fo.PrintChar('B');
        else
            g_fo.PrintChar('A');
        g_fo.PrintChar('\n');
    }
    g_fo.Flush();
*/

    t=g_fi.ReadNext();   // scanf("%lld",&t);
    while(t--){
        //scanf("%lld %lld",&n,&Q);
        n=g_fi.ReadNext();
        Q=g_fi.ReadNext();
        for(ll i=1;i<=n;i++){
            wt[i]=g_fi.ReadNext();  //scanf("%lld",&wt[i]);
            treeEnd[i]=-1;
        }

        for(ll i=1;i<=n-1;i++){
            //scanf("%lld %lld",&a,&b);
            a=g_fi.ReadNext();
            b=g_fi.ReadNext();

            treeEnd[a]++;    treeEnd[b]++;
            tree[a][treeEnd[a]]=b;
            tree[b][treeEnd[b]]=a;
        }

        parentDFS(1,0);


        ll vl=0,kl=0;
        for(ll i=0;i<Q;i++){
            //scanf("%lld %lld",&a,&b);
            a=g_fi.ReadNext();
            b=g_fi.ReadNext();

            v = (a^vl); k = (b^kl);
            smallest=v; maxXor=(wt[smallest]^k);
            dfs(v);
            vl = smallest;  kl=maxXor;
            //printf("%lld %lld\n",smallest,maxXor);
            g_fo.PrintUint(smallest,' '); g_fo.PrintUint(maxXor,'\n');
        }
    }
    g_fo.Flush();
}


void parentDFS(ll node,ll parent){
    allParents[node]=parent;
    if(node!=1&&treeEnd[node]==0){
        return;
    }else{
        for(ll i=0;i<=treeEnd[node];i++){
            if(tree[node][i]!=parent){
                parentDFS(tree[node][i],node);
            }
        }
    }
}

void dfs(ll node){
    if(node!=1&&treeEnd[node]==0){
        ll temp = (wt[node]^k);
        if(temp>maxXor){
            maxXor=temp;
            smallest=node;
        }else if(temp==maxXor){
            if(smallest>node){
                smallest=node;
            }
        }
    }else {
        ll temp = (wt[node]^k);
        if(temp>maxXor){
            maxXor=temp;
            smallest=node;
        }else if(temp==maxXor){
            if(smallest>node){
                smallest=node;
            }
        }

        for(ll i=0;i<=treeEnd[node];i++){
            if(tree[node][i]!=allParents[node]){
                dfs(tree[node][i]);
            }
        }
    }
}
