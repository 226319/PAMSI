#include "Headers.hh"
#include "Stack.hh"
#include "Queue.hh"
#include "Node.hh"
#include "List.hh"

#define TEST 10
int main() {

	Node node, node1;
	Node* node_ptr = &node1;
	List list;

	node.SetElement() = 5;
	node.SetNext( node_ptr );
	node.Next()->SetElement() = 4;
	std::cerr << node1.GetElement() << std::endl;


	list.Add(-4,0);
	list.Add(-3,0);
	std::cerr << list.Size() << std::endl;
	std::cerr << list.Add(-4,2) << std::endl;
	list.Add(3,5);
	std::cerr << list.Size() << std::endl;





}
