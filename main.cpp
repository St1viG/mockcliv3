#include "include/InputHandler.h"
#include "include/ErrorHandler.h"

int main() {
    while(ErrorHandler::Instance()->getLoop()){
        try{
            InputHandler::Instance()->listen();
            clearerr(stdin);
            std::cin.clear();
        }catch(BaseException& e){
            ErrorHandler::handleError(e);
        }
        catch(...){
            std::cout<<"Unknown error occured"<<std::endl;
        }
    }


    return 0;
}
