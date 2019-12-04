#ifndef GETEXCEPTION_HPP
#define GETEXCEPTION_HPP
#include <exception>
#include <string>

class GetException{
    private:
        GetException() {}
        std::string mErrorMessage;
    
    public:
        GetException(const std::string ErrMsg): mErrorMessage(ErrMsg){ }  // Exception Handling Error Message
        const std::string what() const noexcept{ return mErrorMessage;}   

};

#endif /* GETEXCEPTION_HPP */

