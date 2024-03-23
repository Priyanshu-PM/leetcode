#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

typedef tree<double, null_type, less_equal<double>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

class MedianFinder {
public:
    ordered_set st;
    int size = 0;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        st.insert(double(num));
        size++;
    }
    
    double findMedian() {
        int middle = size / 2;
        if(size % 2 == 1)
            return (*st.find_by_order(middle));
        else
            return ((*st.find_by_order(middle - 1)) + (*st.find_by_order(middle))) / 2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */