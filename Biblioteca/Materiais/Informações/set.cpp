set<int> st;

// Complexidade: O(log(n))
st.insert(x);
st.erase(x);
st.find(x);
st.erase(st.find(x));


// Complexidade: O(1)
st.size();
st.empty();

// Complexidade: O(n)
st.clear();
for (auto x : st) {}

             |  priority_queue |       set       | 
-------------+-----------------+-----------------+--------
op           | call   | compl  | call   | compl  | melhor
-------------+--------+--------+--------+--------+--------
insert       | push   | log(n) | insert | log(n) | pq
erase_menor  | pop    | log(n) | erase  | log(n) | pq
get_menor    | top    |    1   | begin  |   1    | set
get_maior    |   -    |    -   | rbegin |   1    | set
erase_number | remove |    n   | erase  | log(n) | set
find_number  |   -    |    -   | find   | log(n) | set
find_>=      |   -    |    -   | lower  | log(n) | set
find_<=      |   -    |    -   | upper  | log(n) | set
iterate      | for    |    n   | for    |    n   | set
-------------+--------+--------+--------+--------+--------

