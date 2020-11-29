#include <iostream>
#include "TQueueList.h"
int main()
{
    TQueueList<int> s;
    for (int i = 0; i < 20; ++i) {
        s.push(i);
    }
    s.save("trp.txt");
    return 0;
}
