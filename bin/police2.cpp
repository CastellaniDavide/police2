/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 * NOTE: it is recommended to use this even if you don't
 * understand the following code.
 */

#include <assert.h>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std; 

// constraints
#define MAXN 100000

// input data
int N, i;
int V[MAXN];

int main() {
  //  uncomment the following lines if you want to read/write from files
  // freopen("input1.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);

  assert(1 == scanf("%d", &N));
  for (i = 0; i < N; i++)
    assert(1 == scanf("%d", &V[i]));

  int loop_max = 0;
  
  for(int i = 0; i < 3; i++){
    
    int loop = 1;
    vector<int> visited; 
    int house_to_visit = i;

    while (!(std::count(visited.begin(), visited.end(), house_to_visit))){
      visited.push_back(house_to_visit);
      house_to_visit = V[house_to_visit];
    }

    if(house_to_visit == visited[0]){
      loop = visited.size();
    }
    else{
      int j = visited.size() - 1;
      while ((visited[j] != house_to_visit)&(j>=0)){
        j--;
        loop++;
      }
    }

    if (loop > loop_max)
      loop_max = loop;
    
  }

  printf("%d\n", loop_max); // print the result
  return 0;
}
