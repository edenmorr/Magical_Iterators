#pragma once
#include <vector>
#include <cmath>
#include<iostream>

namespace ariel
{
    class MagicalContainer
    {
    private:
        std::vector<int> vec;

    public:
        void addElement(int element)
        {
            vec.push_back(element);
        }
        unsigned long int size() const
        {
            return vec.size();
        }
        void removeElement(int element)
        {
        }

        class AscendingIterator
        {

        private:
            const MagicalContainer &container;
            std::vector<int>::const_iterator iter;

        public:
            // Default constructor
            AscendingIterator(const MagicalContainer &container)
                : container(container), iter(container.vec.begin()) {}
            // Destructor
            ~AscendingIterator(){};

            // Copy constructor
            AscendingIterator(const AscendingIterator &other)
                : container(other.container), iter(other.iter) {} ////////////////???????????

            // Assignment operator "="
            AscendingIterator &operator=(const AscendingIterator &other)
            {
                return *this;
            }

            // Equality comparison (operator==)
            bool operator==(const AscendingIterator &other) const
            {
                return iter == other.iter;
            }

            // Inequality comparison (operator!=)
            bool operator!=(const AscendingIterator &other) const
            {
                return !(*this == other);
            }
            // Pre-increment operator (operator++)
            AscendingIterator &operator++()
            {
                ++iter;
                return *this;
            }

            // Dereference operator (operator*)
            int operator*() const
            {
                return *iter;
            }
            AscendingIterator begin()
            {
                return AscendingIterator(container);
            }
            AscendingIterator end()
            {
                return AscendingIterator(container);
            }
        };

        class SideCrossIterator
        {

        private:
            const MagicalContainer &container;
            std::vector<int>::const_iterator iter;
            bool isReversed;

        public:
            // Default constructor
            SideCrossIterator(const MagicalContainer &cont, bool revers = false)   ////////////////////////////////
                : container(cont), isReversed(revers) {}
            // Destructor
            ~SideCrossIterator(){};

            // Equality comparison (operator==)
            bool operator==(const SideCrossIterator &other) const{
                return iter == other.iter;
            }

            // Inequality comparison (operator!=)
            bool operator!=(const SideCrossIterator &other) const{
                return !(*this == other);
            }
            // Pre-increment operator (operator++)
            SideCrossIterator &operator++(){
                if(isReversed)
                {
                    --iter;
                }
                else{
                    ++iter;
                }
                return *this;
            }

            // Dereference operator (operator*)
            int operator*() const{
                return *iter;
            }

            SideCrossIterator begin(){
                return SideCrossIterator(container);
            }
            SideCrossIterator end(){
                return SideCrossIterator(container);
            }
        };

        class PrimeIterator
        {

        private:
            const MagicalContainer &container;
            std::vector<int>::const_iterator iter;

            bool isPrime(int num) const{
                if(num<2){
                    return false;
                }
            for(int i=2; i<=std::sqrt(num);++i){
                if(num % i == 0){
                    return false;
                }
            }
            return true;
            }

        public:
            // Default constructor
            PrimeIterator(const MagicalContainer &cont)
                : container(cont), iter(container.vec.begin())
            {
                while ((iter != container.vec.end() && !isPrime(*iter)))
                {
                    ++iter;
                }
                
            }
            // Destructor
            ~PrimeIterator(){};

            // Equality comparison (operator==)
            bool operator==(const PrimeIterator &other) const{
                return iter == other.iter;
            }

            // Inequality comparison (operator!=)
            bool operator!=(const PrimeIterator &other) const{
                return !(*this ==other);
            }

            // Pre-increment operator (operator++)
            PrimeIterator &operator++(){
                ++iter;
                return *this;
            }

            // Dereference operator (operator*)
            int operator*() const{
                return *iter;
            }

            PrimeIterator begin(){
                return PrimeIterator(container);
            }
            PrimeIterator end(){
                return PrimeIterator(container);
            }
        };
    }; 
};