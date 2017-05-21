#include "ChildNode_Test.hh"

void CN_Constructors_Test() {

	Element NewElement( 44, "Content" );
	ChildNode Root, AnotherOne(NewElement);


	BOOST_CHECK(Root.getLeft() == nullptr);
	BOOST_CHECK(Root.getRight() == nullptr);
	BOOST_CHECK(Root.getParent() ==  nullptr);
	BOOST_CHECK_EQUAL(Root.getElement().getKey(), 0 );
	BOOST_CHECK_EQUAL(Root.getElement().getContent(), "No Content" );

	BOOST_CHECK_EQUAL(AnotherOne.getElement().getKey(), 44 );
	BOOST_CHECK_EQUAL(AnotherOne.getElement().getContent(), "Content" );


}


void CN_CpyConstructor_Test() {

	Element NewElement( 44, "Content" );
	ChildNode NewOne(NewElement);
	ChildNode Left,Right,Parent;
	ChildNode* p = &Left;

	NewOne.setLeft(p);
	p = &Right;
	NewOne.setRight(p);
	p = &Parent;
	NewOne.setParent(p);

	ChildNode Root(NewOne);

	BOOST_CHECK(Root.getLeft() == &Left );
	BOOST_CHECK(Root.getRight() == &Right);
	BOOST_CHECK(Root.getParent() == &Parent );
	BOOST_CHECK_EQUAL(Root.getElement().getKey(), 44 );
	BOOST_CHECK_EQUAL(Root.getElement().getContent(), "Content" );


}








