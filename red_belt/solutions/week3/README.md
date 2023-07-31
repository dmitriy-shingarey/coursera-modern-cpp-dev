## C++ memory model

## [Programming Assignment: Pool of Objects](1_pool_of_objects)

In practice, there are often objects that take considerable time to create, such as threads, TCP connections or database connections. Therefore, when such an object is no longer needed, it is not destroyed, but put aside to be reused later. In this task, you will have to implement such a scheme - you need to write a template of the ObjectPool class:

```cpp
template <class T>
class ObjectPool {
public:
  T* Allocate();
  T* TryAllocate();

  void Deallocate(T* object);

  ~ObjectPool();

private:
  ...
};
```

* An ```ObjectPool``` class object must support two sets of objects: allocated and freed - initially both sets are empty.
* The ```Allocate``` method should work like this:
    1. if there is at least one freed object, it should be moved to the set of allocated objects and return a pointer to it as the function result
    2. if there are no freed objects, a new object is created, placed into the set of allocated objects, and the pointer to it is returned as the function result.
* ```TryAllocate``` method works similarly, but if there are no freed objects, it should just return ```nullptr```.
* The ```Deallocate``` method moves an object from the allocated set to the freed set; if the passed object is not contained in the allocated set, the ```Deallocate``` method should throw an ```invalid_argument exception```.
* The ```Allocate``` and ```TryAllocate``` methods must return objects in FIFO order, i.e. the set of freed objects must be a queue: methods