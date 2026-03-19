import subprocess
import sys

def mst_sum(n, edges):
    parent=list(range(n+1))
    def find(x):
        while parent[x]!=x:
            parent[x]=parent[parent[x]]
            x=parent[x]
        return x
    def union(a,b):
        ra,rb=find(a),find(b)
        if ra==rb: return False
        parent[rb]=ra
        return True
    s=0;cnt=0
    for u,v,w in sorted(edges,key=lambda x:x[2]):
        if union(u,v):
            s+=w;cnt+=1
            if cnt==n-1: break
    if cnt!=n-1: return None
    return s

exe = r"d:\MY_CODE\ACM\nowcoder\2026-2-7\output\E.exe"

for n in range(2,8):
    for m in range(n-1, min(12, n*(n-1)//2)+1):
        import subprocess
        import sys

        def mst_sum(n, edges):
            parent=list(range(n+1))
            def find(x):
                while parent[x]!=x:
                    parent[x]=parent[parent[x]]
                    x=parent[x]
                return x
            def union(a,b):
                ra,rb=find(a),find(b)
                if ra==rb: return False
                parent[rb]=ra
                return True
            s=0;cnt=0
            for u,v,w in sorted(edges,key=lambda x:x[2]):
                if union(u,v):
                    s+=w;cnt+=1
                    if cnt==n-1: break
            if cnt!=n-1: return None
            return s

        exe = r"d:\\MY_CODE\\ACM\\nowcoder\\2026-2-7\\output\\E.exe"

        for n in range(3,31):
            for m in range(n-1, min(60, n*(n-1)//2)+1):
                Mi = n*(n-1)//2
                for k in range(Mi, Mi+121):
                    inp = f"1\n{n} {m} {k}\n"
                    try:
                        p = subprocess.run([exe], input=inp.encode(), stdout=subprocess.PIPE, stderr=subprocess.PIPE, timeout=1)
                    except subprocess.TimeoutExpired:
                        print('hang',n,m,k)
                        sys.exit()
                    out = p.stdout.decode().strip().split()
                    if not out:
                        continue
                    if out[0] == 'NO':
                        continue
                    # parse edges
                    it = iter(out[1:])
                    edges = []
                    try:
                        while True:
                            u = int(next(it)); v = int(next(it)); w = int(next(it))
                            edges.append((u,v,w))
                    except StopIteration:
                        pass
                    if len(edges) != m:
                        print('found_bad: edge_count', n, m, k, len(edges))
                        sys.exit()
                    s = mst_sum(n, edges)
                    if s != k:
                        print('counterexample', n, m, k, 'mst=', s)
                        print('\n'.join(' '.join(map(str,e)) for e in edges))
                        sys.exit()
        print('no counterexample found')
