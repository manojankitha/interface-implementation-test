#ifndef COLLECTION_HPP
#define COLLECTION_HPP

template<typename T>
class collection{
    public:
    
        virtual bool Add(const T&) = 0;
        virtual T Get() = 0;
        virtual bool isEmpty() const = 0;
        virtual size_t size() const = 0;
};

#endif /* COLLECTION_HPP */
 
