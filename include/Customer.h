#pragma once

#include "interface/ICustomer.h"

class Customer: public ICustomer {
    std::string name;
    std::string address;
    std::vector<std::unique_ptr<IRentable>> rented;
    Money balance;
public:
    Customer(const std::string& name, std::string address="", Money balance={0,0});
    
    const std::string& Name() const override;
    const std::string& Address() const override;
    Money Balance() const override;
    const std::vector<std::unique_ptr<IRentable>>& Rentals() const override;    
    virtual void AssignRental(std::unique_ptr<IRentable> item) override;
    virtual std::unique_ptr<IRentable> RemoveRental(size_t i) override;

    virtual void AdjustBalance(Money amount) override;
};