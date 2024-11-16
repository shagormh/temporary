x,y,z = map(int,input().split());

case1 = 2 * z + y;
case2 = z + x+ 2 * y;
case3 = 2 * x + 3 * y;

minumum_cost = min(case1,case2,case3);

print(minumum_cost);
print(x,y,z);