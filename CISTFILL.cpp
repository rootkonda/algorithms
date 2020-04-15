/**
https://www.spoj.com/problems/CISTFILL/

1. height*width*depth = Volume.
2. Calculate total volume for all cisteren's and check if total volume is strictly less than given Volume of water, then return "OVERFLOW"
3. If the calculated volume is more than given volume of water, then use binary search to find the right level where the water will be filled in all possible cisterens.
4. For every cisteren, set the present level and then check if the total height is below or equal to present level, if so then you have to only consider the heigth within the present level and then calculate the volume for that space.
   volume += ((presentLevel - (*it).base) * ((*it).width) * ((*it).depth));
   
5. if the base+height < present level then just calculate the volume and add it to the total volume.
6. Move the low level and high level and at some point the difference between two pointers will be nearly 0. then we have found the correct level where the volume of water is filled in all possible cisterens.
**/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Cistern{
    int base;
    int height;
    int width;
    int depth;
};

int main() {
    int k, n;
    double V, volume, highLevel, lowLevel, presentLevel;
    struct Cistern cis;
    vector<Cistern> Cisterns;
    vector<Cistern>::iterator it;
    scanf("%d", &k);
    while(k--)
    {
        volume = 0.0;
        scanf("%d", &n);
        for(int i = 0; i < n; i++) {
            scanf("%d %d %d %d", &cis.base, &cis.height, &cis.width, &cis.depth);
            volume += (cis.height * cis.width * cis.depth);
            Cisterns.push_back(cis);
        }
        scanf("%lf", &V);
        if(volume < V) {
            printf("OVERFLOW\n");
        }else{
            lowLevel = 0.0;
            highLevel = 1e7;
            while(highLevel - lowLevel > 0.000001) {
                presentLevel = (highLevel + lowLevel) / 2;
                volume = 0.0;
                for(it = Cisterns.begin(); it != Cisterns.end(); it++) {
                    if((*it).base >= presentLevel){
                        continue;
                    }else if(((*it).base < presentLevel) && (((*it).base + (*it).height) >= presentLevel)) {
                        volume += ((presentLevel - (*it).base) * ((*it).width) * ((*it).depth));
                    }else if(((*it).base + (*it).height) < presentLevel) {
                        volume += (((*it).height) * ((*it).width) * ((*it).depth));
                    }
                }
                if(volume >= V) {
                    highLevel = presentLevel;
                }else{
                    lowLevel = presentLevel;
                }
            }
            printf("%.2lf\n", presentLevel);
        }
        Cisterns.erase(Cisterns.begin(), Cisterns.end());
    }
    return 0;
}
