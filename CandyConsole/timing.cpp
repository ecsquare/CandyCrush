#include "timing.h"
#include <bits/stdc++.h>
using namespace std;

timing::timing(int x)
{

    m=x/60;
    s=x-60*m;

}
void timing::afficherT(){

 printf("%02d:%02d",m,s);
}
