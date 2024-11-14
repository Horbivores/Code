struct Edge {
    int to;
    int next;
};

class Solution {
private:
    Edge edge[200010];
    int head[100010];
    int val[100010];
    int edgeCnt;
    int ans;
    void addedge(int u, int v) {
        edge[edgeCnt].to = v;
        edge[edgeCnt].next = head[u];
        head[u] = edgeCnt++;
    }

    void dfs(int u, int fa) {
        int temp = 0, fl = 0;
        for (int i = head[u]; i != -1; i = edge[i].next) {
            int v = edge[i].to;
            if (v == fa) {
                continue;
            }

            dfs(v, u);

            if (temp == 0) {
                temp = val[v];
            }

            if (temp != val[v]) {
                fl = 1;
            }
            
            val[u] += val[v];
        }
        val[u]++;
        if (fl == 0) {
            ans++;
        }
    }

public:
    int countGoodNodes(vector<vector<int>>& edges) {
        memset(head, -1, sizeof(head));
        memset(val, 0, sizeof(val));
        edgeCnt = 0;
        ans = 0;
        for (auto& e : edges) {
            addedge(e[0], e[1]);
            addedge(e[1], e[0]);
        }
        dfs(0, -1);
        return ans;
    }
};