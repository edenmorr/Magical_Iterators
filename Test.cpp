#include <iostream>
#include "doctest.h"
#include "sources/MagicalContainer.hpp"

using namespace ariel;

TEST_CASE("TEST 1: Add elements")
{
    MagicalContainer container;

    // Add elements to the container
    container.addElement(1);
    CHECK(container.size()==1);
    container.addElement(5); 
    CHECK(container.size()==2);
    container.addElement(7);
    CHECK(container.size()==3);

}

TEST_CASE("TEST 2: Remove elements")
{
    MagicalContainer container;

    // Add elements to the container
    container.addElement(1);
    container.addElement(2);

    // Remove an element from the container
    container.removeElement(2);
    // Check the container's size 
    CHECK(container.size() == 1);
    container.removeElement(1);
    CHECK(container.size()==0);
}

TEST_CASE("TEST 3: initial Container size")
{
    MagicalContainer container;
    // Check if the container's initial size is 0
    REQUIRE(container.size() == 0);
}

TEST_CASE("TEST 4: AscendingIterator")
{
    MagicalContainer container;

    // Add elements to the container
    container.addElement(1);
    container.addElement(2);
    container.addElement(5);

    // Create an AscendingIterator for the container
    MagicalContainer::AscendingIterator AScontain(container);

    // Define the expected and result vectors
    std::vector<int> expected{1, 2, 5};
    std::vector<int> result;

    for (auto element = AScontain.begin(); element != AScontain.end(); ++element)
    {
        result.push_back(*element);
    
        CHECK(result == expected);
}
}
TEST_CASE("TEST 5: SideCrossIterator")
{
    MagicalContainer container;

    // Add elements to the container
    container.addElement(9);
    container.addElement(2);
    container.addElement(3);
    container.addElement(17);

    // Create a SideCrossIterator for the container
    MagicalContainer::SideCrossIterator Sidcontain(container);

    // Define the expected and result vectors
    std::vector<int> expected{9, 2, 3, 17};
    std::vector<int> result;

    for (auto element = Sidcontain.begin(); element != Sidcontain.end(); ++element)
    {
        result.push_back(*element);
    }
        CHECK(result == expected);
}
TEST_CASE("TEST 6: PrimeIterator")
{
    MagicalContainer container;

    // Add elements to the container
    container.addElement(9);
    container.addElement(2);
    container.addElement(3);
    container.addElement(17);

    // Create a PrimeIterator for the container
    MagicalContainer::PrimeIterator containe(container);

    // Define the expected and result vectors
    std::vector<int> expected{9, 2, 3, 17};
    std::vector<int> result;

    for (auto element = containe.begin(); element != containe.end(); ++element)
    {
        result.push_back(*element);
    }

    REQUIRE(result == expected);
}

TEST_CASE("TEST 7: Removing non-existent element")
{
    MagicalContainer container;

    container.addElement(1);
    container.addElement(2);
    container.addElement(5);
    container.removeElement(9); // no such element 9 
    REQUIRE(container.size() == 3); // so the container should return the same amount of elements 
}
TEST_CASE("TEST 8: AscendingIterator comparison") {
    MagicalContainer container;
    container.addElement(1);
    container.addElement(2);
    container.addElement(5);

    MagicalContainer::AscendingIterator iter1(container);
    MagicalContainer::AscendingIterator iter2(container);

    CHECK((iter1 == iter2)); // cheack compering between 2 iterators if equals
    CHECK_FALSE((iter1 != iter2));

    ++iter1;
    CHECK((iter1 != iter2)); // cheack compering between 2 iterators after iterator 1 increased 
    CHECK_FALSE((iter1 == iter2));
    }



// Test case for comparing PrimeIterator
TEST_CASE("TEST 9: PrimeIterator comparison") {
    MagicalContainer container;
    container.addElement(1);
    container.addElement(2);
    container.addElement(5);

    MagicalContainer::PrimeIterator iter1(container);
    MagicalContainer::PrimeIterator iter2(container);

    CHECK((iter1 == iter2)); // cheack compering between 2 iterators if equals 
    CHECK_FALSE((iter1 != iter2));

    ++iter1;
    CHECK((iter1 != iter2)); // cheack compering between 2 iterators after iterator 1 increased 
    CHECK_FALSE((iter1 == iter2)); 
}


// Test case for comparing SideCrossIterator
TEST_CASE("TEST 9: SideCrossIterator Comparison") {
    MagicalContainer container;
    container.addElement(1);
    container.addElement(2);
    container.addElement(5);
    
    MagicalContainer::SideCrossIterator iter1(container);
    MagicalContainer::SideCrossIterator iter2(container);

    CHECK((iter1 == iter2)); // cheack compering between 2 iterators if equals 
    CHECK_FALSE((iter1 != iter2)); 

    ++iter1;
    CHECK((iter1 != iter2));
    CHECK_FALSE((iter1 == iter2)); // cheack compering between 2 iterators after iterator 1 increased 
    }
