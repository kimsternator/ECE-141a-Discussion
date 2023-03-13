#include <iostream>

int main() {
	std::cout << "Hello, World!" << std::endl;
	return 0;
}

template<typename T>
bool func(T aArg) {
    return false;
}

template<typename T>
bool func(T* aArg) {
    return true;
}

class Block{};
class Storage{};
class Chunker{};
class Archive {
    // Storing files in an archive
        /* Block (overarching file - object as data)
         * Storing blocks - storage
         * Chunking blocks - Chunker
         */
    // has-a
    Storage singleon_;
    Chunker staticclass;
};

/*
 * OOP + STL
 * 		Encapsulation
 * 		Inheritance
 * 		Polymorphism
General Polymorphism
 	CompileTime
 		Function overloading
 		Operator Overloading
 	Runtime
 		Virtual Function (Overriding)
	What type is template? - compile time
Solid Principles
 	SRP (Divide and Conquer)
 	Open-closed (interface)
 	Liskov
 	Interface Segregation
 	Dependency Inversion
Design Patterns
 	Creational
 		Factory
 		Builder
 		Prototype
 		Singleton
 	Behavioral
 		Command
 		Chair of Responsibility
 		Iterator
 		Observer
 		Visitor
 	Structural
 		Adapter
 		Decorator
 		Proxy
Communication Patterns
 	MVC
 	API (ReST)
 	Layers
 	Subscription
Control/Flow Patterns
 	Outside In
 	Inside out
(Avoiding) Anti-Patterns
 	Magic Numbers
 	const right
 */