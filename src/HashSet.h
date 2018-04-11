/*
 * HashSet.h
 *
 *  Created on: Apr 4, 2018
 *      Author: vkotnoor
 */

#ifndef HASHSET_H_
#define HASHSET_H_
#include <list>
#include <functional>
#include <algorithm>
#include <vector>
using namespace std;
const static float kMaxBuckets = 50;
template <typename T>
class HashSet {
public:


    HashSet():bucket_size(0),
    bucket_count(0),
    buckets()
{
        rehash();
}




    /***************************************************************
     * function needed to initialize media
     * @param None
     * @return True if init is well done
     ****************************************************************/
    bool insert(T input)
    {
        if(find(input)) return false;
        float avgsize =  ((float)bucket_size/buckets.size());

        if(avgsize > kMaxBuckets)
        {
            rehash();
        }

        int bind = (std::hash<T>{}(input)) % buckets.size();
        buckets[bind].emplace_back(input);
        bucket_size++;
        return true;
    }

    bool find(T input)
    {
        int bind = (std::hash<T>{}(input)) % buckets.size();
        return ((std::find(buckets[bind].begin(), buckets[bind].end(), input)) != buckets[bind].end());
    }

    void rehash()
    {
        std::list<T> tmplist;
        buckets.emplace_back(tmplist);
        std::vector<std::list<T>> tempbuckets;
        for(int i = buckets.size(); i>0 ; i--)
        {
            tempbuckets.push_back(tmplist);

        }
        for(auto elem: buckets)
        {
            for(auto ele : elem)
            {
                int bind = (std::hash<T>{}(ele)) % buckets.size();
                tempbuckets[bind].push_back(ele);
            }
        }
        buckets.clear();
        buckets = tempbuckets;

    }


    void print()
    {
        std::cout<< "bucket_size = " << bucket_size << "bucket_count = " << buckets.size() << std::endl;
    }

private:
    int bucket_size;
    int bucket_count;
    std::vector<std::list<T>> buckets;

};

#endif /* HASHSET_H_ */
