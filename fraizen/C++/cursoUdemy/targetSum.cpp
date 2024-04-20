#include<bits/stdc++.h>
using namespace std;

int ans = 0;

void count(vector<int> &nums, int target, int index, int suma) {
    cout << "Index " << index << " con suma " << suma << endl;
    //ya termine de sumar todo, entonces retorno
    if (index == (int)nums.size() && target == suma){
        ans++;
        return;
    } else if (index == (int)nums.size()){
        return;
    }
    //caso normal, pongo sumando y restando
    cout << "Ahora llamo con " <<  suma + nums[index] << endl;
    count(nums, target, index+1, suma + nums[index]);
    cout << "Ahora llamo con " <<  suma - nums[index] << endl;
    count(nums, target, index+1, suma - nums[index]);
}

int findTargetSumWays(vector<int> nums, int target) {
    count(nums, target, 0, 0);
    return ans;
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    #ifdef JP
        freopen("A.in", "r", stdin);
        freopen("A.out", "w", stdout);
	#endif

    int cases = 1;
    vector<int> nums = {1,1,1,1,1};
    int target = 3;
    while(cases--){
        findTargetSumWays(nums, target);
        cout << ans << endl;
    }

    #ifdef JP
		cerr << "Time elapsed: " <<  clock() * 1000 / CLOCKS_PER_SEC << " ms\n";
	#endif

    return 0;
}