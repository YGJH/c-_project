long double kake(vec *v, int v_len){ //旋转卡壳
    double ans = 1e15;
    int idx = 1;
    v[v_len] = v[0];
    for(int i = 0; i < v_len; ++i){
        while(fabs(cross(v[i + 1] - v[i], v[idx + 1] - v[i])) > fabs(cross(v[i + 1] - v[i], v[idx] - v[i]))){
            if(idx >= v_len) idx -= v_len;
            else idx+=1;
        }
        double now = fabs(cross(v[i + 1] - v[i], v[idx] - v[i])) / (v[i] - v[i + 1]).len();
        if(sgn(now - ans) == -1) ans = now;
    }
    // printf("%.16f\n", ans);
    return ans;
}