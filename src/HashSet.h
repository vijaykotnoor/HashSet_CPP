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
#include <vector>
using namespace std;
const static float kMaxBuckets = 20;
template <typename T>
class HashSet {
public:


	HashSet():bucket_size(0),
	bucket_count(0),
	buckets(){};




	/***************************************************************
	 * function needed to initialize media
	 * @param None
	 * @return True if init is well done
	 ****************************************************************/
	bool insert(T input)
	{
		if(find(input)) return false;
		if(buckets.empty())
		{
			rehash();
		}
		float avgsize = bucket_size/buckets.capacity();
		if(avgsize > kMaxBuckets)
		{
			rehash();
		}
		int bind = (std::hash<T>{}(input)) % buckets.capacity();
		if(bind < buckets.size())
		{
			std::list<T> tmplist;
			buckets.emplace_back(tmplist);
		}
		buckets[bind].emplace_back(input);
		bucket_size++;
        return true;
	}

	bool find(T input)
	{
		 //int bind = (std::hash<T>{}(input)) % buckets.size();
         return false;
	}

	void rehash()
	{

		if(buckets.empty())
		{
			std::list<T> tmplist;
			buckets.emplace_back(tmplist);
		}
		else
		{
			std::cout<< "REHASHING" << std::endl;
			std::vector<std::list<T>> tempbuckets;
			tempbuckets.reserve(buckets.size()*2);
			for(auto elem: buckets)
			{
				std::list<T> tmplist;
				for(auto ele : elem)
				{
					auto value = std::hash<T>{}(ele);
					std::cout << value << " " << tempbuckets.size() <<" ";
					//int bind = (value) % tempbuckets.size();
					//tempbuckets[bind].emplace_back(ele);
				}
			}
			//buckets.clear();
			//buckets = tempbuckets;*/
		}

	};


	void print()
	{
		for(auto elem: buckets)
		{
			for(auto ele : elem)
			{
				std::cout<< ele << std::endl;
			}
		}
		std::cout<< buckets.size() << std::endl;
	};

private:
	int bucket_size;
	int bucket_count;
	std::vector<std::list<T>> buckets;

};

#endif /* HASHSET_H_ */
