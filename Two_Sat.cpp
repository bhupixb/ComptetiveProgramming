struct Two_Sat {
  vector<vector<int>> g, gt; // adjacency list
  vector<bool> used, assignment; 
  vector<int> order, comp;
  int n; // number of variables (excluding negations)

  // if i < n then it's variable i else it's negation of variable i - n

  // zero based indexing
  Two_Sat(int _n) : n(_n) {
    g.resize(n << 1); // x2 for negations
    gt.resize(n << 1);
  }

  // normal directed edge addition from p -> q
  void add_edge(int p, int q) {    
    g[p].push_back(q); 
    gt[q].push_back(p);
  }

  // ~ denotes negation here  
  // p or q = (~p -> q) and (~q -> p)
  // p xor q = (p or q) and (~p or ~q) (forces p and q to be either (0, 1) or (1, 0))
  // ~ (p xor q) = (~p or q) and (p or ~q) (forces p and q to be either (1, 1) or (0, 0))

  int negation(int p) {
    return (p >= n ? p - n : p + n);
  }
  void p_or_q(int p, int q) {
    add_edge(negation(p), q);
    add_edge(negation(q), p);
  }
  void p_xor_q(int p, int q) {
    // var(p, q);
    p_or_q(p, q);
    p_or_q(negation(p), negation(q));
  }
  void not_p_xor_q(int p, int q) {
    p_or_q(negation(p), q);
    p_or_q(p, negation(q));
  }

  void dfs1(int v) { // to find topological ordering/sort
    used[v] = true;
    for (int u : g[v]) {
      if (!used[u])
        dfs1(u);
    }
    order.push_back(v);
  }
  void dfs2(int v, int cl) { // to find strongly connected components
    comp[v] = cl;
    for (int u : gt[v]) {
      if (comp[u] == -1)
        dfs2(u, cl);
    }
  }
  bool solve_2SAT() {
    int mx = n << 1;
    used.assign(mx, false);
    for (int i = 0; i < mx; ++i) {
      if (!used[i])
        dfs1(i);
    }

    comp.assign(mx, -1);
    for (int i = 0, j = 0; i < mx; ++i) {
      int v = order[mx - i - 1];
      if (comp[v] == -1)
        dfs2(v, j++);
    }

    assignment.assign(n, false);
    for (int i = 0; i < n; ++i) {
      if (comp[i] == comp[i + n]) // p and ~p belongs to same Connected Component
        return false;
      assignment[i] = comp[i] > comp[i + n];
    }
    return true;
  }
};
