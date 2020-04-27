#include "Customer.h"
#include "mocks/MockRentable.h"

using trompeloeil::deathwatched;

TEST_CASE("Customer class correctly assigns name John Smith") {
    Customer custImpl{"John Smith"};
    const ICustomer& cust = custImpl; 
    REQUIRE(cust.Name() == "John Smith");
}

TEST_CASE("Customer class correctly assigns name Judge Dredd") {
    Customer custImpl{"Judge Dredd"};
    const ICustomer& cust = custImpl; 
    REQUIRE(cust.Name() == "Judge Dredd");
}

TEST_CASE("Customer class correctly stores and deletes some Rentable Items") {
    auto item = std::make_unique<deathwatched<MockRentable>>();
    REQUIRE_DESTRUCTION(*item);

    Customer custImpl{"John Smith"};
    ICustomer& cust = custImpl;

    cust.AssignRental(std::move(item));
    REQUIRE(cust.Rentals().size() == 1);
    cust.RemoveRental(0);
    REQUIRE(cust.Rentals().size() == 0);
}

TEST_CASE("The rest of Customer class is implemented correctly") {
    Customer custImpl{"John Smith", "23 Human Street"};
    ICustomer& cust = custImpl;
    CHECK(cust.Name() == "John Smith");
    CHECK(cust.Address() == "23 Human Street");
    CHECK(cust.Balance() == Money{0,0});
    cust.AdjustBalance({3, 46});
    CHECK(cust.Balance() == Money{3, 46});
    cust.AdjustBalance({-1, -86});
    CHECK(cust.Balance() == Money{1, 60});
}

