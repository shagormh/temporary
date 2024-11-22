cnt = 0;
for i in range(10):
    word_input = input().strip().upper();
    if 'T' in word_input:
        cnt += 1;

print(cnt);