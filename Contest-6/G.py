import math

def are_close(x, y, tol=1e-9):
    return abs(x - y) < tol

def count_unique_roots(n, coefficients):
    roots = []
    
    for i in range(n):
        A, B, C = coefficients[i]
        if A == 0 and B == 0 and C == 0:
            return -1
        
        if A == 0:
            if B != 0:
                root = -C / B
                if not any(are_close(root, r) for r in roots):
                    roots.append(root)
        else:
            delta = B * B - 4 * A * C
            if delta > 0:
                root1 = (-B + math.sqrt(delta)) / (2.0 * A)
                root2 = (-B - math.sqrt(delta)) / (2.0 * A)
                if not any(are_close(root1, r) for r in roots):
                    roots.append(root1)
                if not any(are_close(root2, r) for r in roots):
                    roots.append(root2)
            elif delta == 0:
                root = -B / (2.0 * A)
                if not any(are_close(root, r) for r in roots):
                    roots.append(root)
    
    return len(roots)

n = int(input())
coefficients = [tuple(map(int, input().split())) for _ in range(n)]
print(count_unique_roots(n, coefficients))