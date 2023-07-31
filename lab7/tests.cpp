#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Dictionary.h"
#include "Node.h"
#include "List.h"
#include "Person.h"

TEST_CASE("Insert and keys")
{
    Dictionary* dict = new Dictionary();
    Person p1 = Person("Jeff", "Lam", 10);
    Person p2 = Person("Joe", "Wong", 1);
    Person p3 = Person("Jennifer", "Lam", 1);
    CHECK(dict -> getKeys() == "");
    dict -> insert(p1);
    CHECK(dict -> getKeys() == "Lam, Jeff-->");
    dict -> insert(p2);
    CHECK(dict -> getKeys() == "Wong, Joe-->Lam, Jeff-->");
    dict -> insert(p3);
    CHECK(dict -> getKeys() == "Wong, Joe-->Lam, Jennifer-->Lam, Jeff-->");
    Person p4 = Person("Justin", "Wong", 1);
    dict -> insert(p4);
    CHECK(dict -> getKeys() == "Wong, Joe-->Wong, Justin-->Lam, Jennifer-->Lam, Jeff-->");
}

TEST_CASE("retrieve")
{
    Dictionary* dict = new Dictionary();
    Person p1 = Person("Jose", "Alvarado", 1);
    Person p2 = Person("Conor", "Mcgregor" , 1);
    Person p3 = Person("Dana", "White", 1);
    dict -> insert(p1);
    dict -> insert(p2);
    dict -> insert(p3);
    Node* n1 = dict -> retrieve(p1);
    Node* n2 = dict -> retrieve(p2);
    Node *n3 = dict -> retrieve(p3);
    CHECK(n1 -> getData().get_name() == p1.get_name());
    CHECK(n2 -> getData().get_name() == p2.get_name());
    CHECK(n3 -> getData().get_name() == p3.get_name());
    
}
