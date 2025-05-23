/*
Феликс большой специалист в области фотографии. Особенно удачно у него выходят
фотографии деревьев. Феликс отыскал в своем любимом городе аллею, вдоль которой друг за
другом растут N деревьев. Для удобства он пронумеровал все деревья по порядку от 1 до N.
Феликс может сделать фотографию, на которой изображено некоторое количество растущих
подряд деревьев. Однако не каждая фотография деревьев может получиться удачной.
По опыту Феликс знает, что фотография будет идеальной, если первое дерево, попавшее в
кадр, имеет высоту X, второе – высоту X+1, третье – X+2 и так далее, где X это значение
светосилы объектива фотоаппарата. Так как Феликс сам собрал свой фотоаппарат, он может
подкрутить в нём гайки и поменять значение светосилы в любой момент.
Фотографии Феликса не всегда выходят идеальными, поэтому он решил оценивать
удачность фотографии, как количество деревьев, которые имеют ровно такую высоту, какую
должны иметь деревья на идеальной фотографии. Например, фотографируя деревья с высотами
3, 2 и 5 метров и светосилой объектива равной 3, Феликс получит фотографию с удачностью 2,
так как первое и последнее деревья имеют высоту 3 и 5, а высота второго дерева не равна 4.
Феликс уже оценил высоту каждого дерева вдоль аллеи и знает, что дерево с номером i
имеет высоту Ai метров. Он хочет сделать M фотографий деревьев так, чтобы на j-ю из них
попали все деревья с номерами от Lj до Rj включительно, а светосила объектива была равна Xj.
Однако, до того как приступить, ему очень хочется знать, насколько удачной будет фотосессия, а
именно какова удачность каждой отдельной фотографии. Помогите Феликсу определить эти
значения.
*/


#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<ll> a(n + 1), b(n + 1);
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        b[i] = a[i] - i;
    }
    unordered_map<ll, vector<int>> mp;
    for(int i = 1; i <= n; i++)
    {
        mp[b[i]].push_back(i);
    }
    while(m--)
    {
        int l, r;
        ll x;
        cin >> l >> r >> x;
        ll k = x - l;
        auto it = mp.find(k);
        if(it == mp.end())
        {
            cout << 0 << endl;
            continue;
        }
        auto v = it->second;
        auto lo = lower_bound(v.begin(), v.end(), l);
        auto hi = upper_bound(v.begin(), v.end(), r);
        cout << hi - lo << endl;
    }
    return 0;
}