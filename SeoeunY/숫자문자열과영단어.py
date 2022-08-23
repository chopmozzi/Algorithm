def solution(s):
    sArr = ['zero','one','two','three','four','five','six','seven','eight','nine']
    nArr = ['0','1','2','3','4','5','6','7','8','9']
    
    for i in range(len(sArr)):
        if (sArr[i] in s):
            s = s.replace(sArr[i],nArr[i])
    answer = int(s)
        
    return answer