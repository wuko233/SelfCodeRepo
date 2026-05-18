# def max_score(r1, s1, p1, r2, s2, p2):
#     score = 0
#     # V aka. 1 win
#     score += min(r1, s2)
#     r1 -= min(r1, s2)
#     s2 -= min(r1, s2)
#     score += min(s1, p2)
#     s1 -= min(s1, p2)
#     p2 -= min(s1, p2)
#     score += min(p1, r2)
#     p1 -= min(p1, r2)
#     r2 -= min(p1, r2)

#     score -= min(r2, s1)
#     r2 -= min(r2, s1)
#     s1 -= min(r2, s1)
#     score -= min(s2, p1)
#     s2 -= min(s2, p1)
#     p1 -= min(s2, p1)
#     score -= min(p2, r1)
#     p2 -= min(p2, r1)
#     r1 -= min(p2, r1)

#     return score

def max_score(r1, s1, p1, r2, s2, p2):
    score = 0

    rwin = min(r1, s2)
    swin = min(s1, p2)
    pwin = min(p1, r2)

    if max(rwin, swin, pwin) == rwin:
        score += rwin
        r1 -= rwin
        s2 -= rwin

        if max(swin, pwin) == swin:
            score += swin
            s1 -= swin
            p2 -= swin

            score += pwin
            p1 -= pwin
            r2 -= pwin
        else:
            score += pwin
            p1 -= pwin
            r2 -= pwin

            score += swin
            s1 -= swin
            p2 -= swin


    elif max(rwin, swin, pwin) == swin:
        score += swin
        s1 -= swin
        p2 -= swin

        if max(rwin, pwin) == rwin:
            score += rwin
            r1 -= rwin
            s2 -= rwin

            score += pwin
            p1 -= pwin
            r2 -= pwin 
        
        else:
            score += pwin
            p1 -= pwin
            r2 -= pwin

            score += rwin
            r1 -= rwin
            s2 -= rwin

    else:
        score += pwin
        p1 -= pwin
        r2 -= pwin

        if max(rwin, swin) == rwin:
            score += rwin
            r1 -= rwin
            s2 -= rwin

            score += swin
            s1 -= swin
            p2 -= swin

    rlose = min(r2, s1)
    slose = min(s2, p1)
    plose = min(p2, r1)

    if min(rlose, slose, plose) == rlose:
        score -= rlose
        r2 -= rlose
        s1 -= rlose

        if min(slose, plose) == slose:
            score -= slose
            s2 -= slose
            p1 -= slose

            score -= plose
            p2 -= plose
            r1 -= plose
        else:
            score -= plose
            p2 -= plose
            r1 -= plose

            score -= slose
            s2 -= slose
            p1 -= slose

    elif min(rlose, slose, plose) == slose:
        score -= slose
        s2 -= slose
        p1 -= slose

        if min(rlose, plose) == rlose:
            score -= rlose
            r2 -= rlose
            s1 -= rlose

            score -= plose
            p2 -= plose
            r1 -= plose
        else:
            score -= plose
            p2 -= plose
            r1 -= plose

            score -= rlose
            r2 -= rlose
            s1 -= rlose
    else:
        score -= plose
        p2 -= plose
        r1 -= plose

        if min(rlose, slose) == rlose:
            score -= rlose
            r2 -= rlose
            s1 -= rlose

            score -= slose
            s2 -= slose
            p1 -= slose
        else:
            score -= slose
            s2 -= slose
            p1 -= slose

            score -= rlose
            r2 -= rlose
            s1 -= rlose
    
    return score



T = int(input());

for _ in range(T):
    n, r1, s1, p1, r2, s2, p2 = map(int, input().split())
    # rocck, scissors, paper


    maxs = max_score(r1, s1, p1, r2, s2, p2)
    mins = -1 * max_score(r2, s2, p2, r1, s1, p1)

    print(maxs, mins)
