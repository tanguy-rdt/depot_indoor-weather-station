#ifndef SINGLETON_H
#define SINGLETON_H

namespace Core {


/**
 * @class Singleton
 * @brief Template class to implement the Singleton design pattern.
 *
 * The `Singleton` template ensures that a class has only one instance, 
 * and provides a global point of access to it. It is implemented using 
 * the Meyers' Singleton pattern, which leverages a static local variable 
 * to guarantee thread-safe lazy initialization.
 *
 * @tparam T The class type that should follow the Singleton pattern.
 */
template <typename T>
class Singleton {
    public:

        /**
        * @brief Retrieves the single instance of the class.
        *
        * This method ensures that only one instance of the class exists. 
        * The instance is created on first access and is destroyed when 
        * the program terminates.
        *
        * @return A reference to the single instance of the class.
        */
        static T& getInstance() {
            static T instance; 
            return instance;
        }


        /**
        * @brief Deleted copy constructor.
        *
        * Prevents copying of the Singleton instance to ensure 
        * that there is only one instance of the class.
        */
        Singleton(const Singleton&) = delete;


        /**
        * @brief Deleted assignment operator.
        *
        * Prevents assigning one Singleton instance to another, 
        * preserving the single-instance guarantee.
        */
        void operator=(const Singleton&) = delete;

    protected:
    
        /**
        * @brief Protected default constructor.
        *
        * Ensures that only the derived class can construct an instance.
        */
        Singleton() = default;


        /**
        * @brief Protected destructor.
        *
        * Ensures that only the derived class or the Singleton implementation 
        * can destroy the instance.
        */
        ~Singleton() = default;
};

}

#endif