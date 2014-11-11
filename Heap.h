#include "Queue.h"
#include <utility>

//This should be the initial arrSize
#define START_SIZE 10

/*
 * This is a priority queue, which means that as items are removed in order
 * of decreasing priority.
 *
 * 
 */
template<class Pri, class T>
class Heap : public Queue<std::pair<Pri, T> > {
public:
  Heap();
  ~Heap();

  //Add a new item
  virtual void add(std::pair<Pri,T> toAdd);

  //Remove the item with lowest priority, and return it
  //If the queue is empty, throw a string exception
  virtual std::pair<Pri,T> remove();

  //Return the number of items currently in the queue
  virtual unsigned long getNumItems();

private:
  int arrSize;
  int numItems;
  std::pair<Pri, T>* backingArray;

  //Grow the backingArray by making a new array of twice the size,
  // and copying over the data
  void grow();

  //Check the item at index, and make sure it is in the right place.
  // If not, swap it up the "tree" of the heap until you find the right
  // place
  void bubbleUp(unsigned long index);

  //Check the item at index, and make sure it is in the right place.
  // If not, swap it down the "tree" of the heap until you find the right
  // place
  void trickleDown(unsigned long index);  
};

//Heap.ipp file


#include <string>

template<class Pri, class T>
Heap<Pri,T>::Heap(){
  numItems = 0;
  arrSize = START_SIZE;
  backingArray = new std::pair<Pri, T> [arrSize];
}

template<class Pri, class T>
Heap<Pri,T>::~Heap(){
	delete[] backingArray;
}

template<class Pri, class T>
void Heap<Pri,T>::grow(){
	std::pair<Pri, T>* tempArray = backingArray;
	backingArray = new std::pair<Pri, T> [arrSize * 2];
	for (int i = 0; i < numItems; i++){
		add(tempArray[i]);
	}
	delete tempArray;
}

template<class Pri, class T>
void Heap<Pri,T>::add(std::pair<Pri,T> toAdd){
	backingArray[numItems] = toAdd;
	bubbleUp(numItems);
	numItems++;
}

template<class Pri, class T>
void Heap<Pri,T>::bubbleUp(unsigned long index){
	int parent = (index - 1) / 2;
  
  if (index > 0 && (backingArray[parent].first > backingArray[index].first)) {
	  backingArray[parent].swap(backingArray[index]);
	  bubbleUp(parent);
  }

}

template<class Pri, class T>
void Heap<Pri,T>::trickleDown(unsigned long index){
	int left = (2 * index) + 1;
	int right = (2 * index) + 2;
	if (backingArray[index] > backingArray[left] || backingArray[index] > backingArray[right]){
		if (backingArray[left] < backingArray[right] && backingArray[left].first != 0) {
				backingArray[index].swap(backingArray[left]);
				trickleDown(left);			
		}
		else if (backingArray[right].first != 0) {
			
				backingArray[index].swap(backingArray[right]);
				trickleDown(right);
			
		}
		else if (backingArray[left].first != 0) {
			backingArray[index].swap(backingArray[left]);
			trickleDown(left);	

		}



	}


}

template<class Pri, class T>
std::pair<Pri,T> Heap<Pri,T>::remove(){
	if (numItems == 0) {
		throw std::string("In remove(), no items to remove!");
	}
	std::pair<Pri,T> tmp = backingArray[0];
	backingArray[0] = backingArray[(numItems - 1)];
	backingArray[numItems - 1] = *(new std::pair<Pri,T>);
	trickleDown(0);
	numItems--;
	return tmp;
}

template<class Pri, class T>
unsigned long Heap<Pri,T>::getNumItems(){
  	return numItems;
}

