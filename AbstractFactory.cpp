#include <iostream>

// Herbivore Abstract Class (Abstract Product)
class Herbivore abstract
{
public:
    // Virtual Methods
    virtual float getWeight() abstract;
    virtual void Eat() abstract;
    virtual void Live() abstract;
    virtual std::string getName() abstract;
    virtual void Dead() abstract;
protected:
    std::string name_;
    bool live_;
    size_t weight_;
};
// Wildebeest Class (Concrete Product)
class Wildebeest : public Herbivore
{
public:
    // Default Constructor 
    Wildebeest()
    {
        name_ = "Wildebeest";
        live_ = true;
        weight_ = 20;
    }
    // Get Wildebeest Weight Method
    float getWeight() override final 
    {
        return weight_;
    }
    // Wildebeest Eat Method
    void Eat() override final 
    {
        std::cout << name_ << " Eat Grass\n";
    }
    // Wildebeest Display Life Indicator Method
    void Live() override final 
    {
        if (live_)
            std::cout << name_ << " Alive\n";
        else
            std::cout << name_ << " Dead :c \n";
    }
    // Wildebeest Get Name Method
    std::string getName() override final
    {
        return name_;
    }
    // Wildebeest Set Dead Life Indicator
    void Dead() override
    {
        live_ = 0;
    }
private:

};
// Buffalo Class (Concrete Product)
class Buffalo : public Herbivore
{
public:
    // Default Constructor 
    Buffalo()
    {
        name_ = "Buffalo";
        live_ = true;
        weight_ = 30;
    };
    // Get Wildebeest Weight Method
    float getWeight() override
    {
        return weight_;
    }
    // Wildebeest Eat Method
    void Eat() override
    {
        std::cout << name_ << " Eat Grass\n";
    }
    // Wildebeest Display Life Indicator Method
    void Live() override
    {
        if (live_)
            std::cout << name_ << " Alive\n";
        else
            std::cout << name_ << " Dead :c \n";
    }
    // Wildebeest Get Name Method
    std::string getName()
    {
        return name_;
    }
    // Wildebeest Set Dead Life Indicator
    void Dead() override
    {
        live_ = 0;
    }
private:

};
// Elk Class (Concrete Product)
class Elk : public Herbivore
{
public:
    // Default Constructor 
    Elk()
    {
        name_ = "Elk";
        live_ = true;
        weight_ = 50;
    }
    // Get Wildebeest Weight Method
    float getWeight() override
    {
        return weight_;
    }
    // Wildebeest Eat Method
    void Eat() override
    {
        std::cout << name_ << " Eat Grass\n";
    }
    // Wildebeest Display Life Indicator Method
    void Live() override
    {
        if (live_)
            std::cout << name_ << " Alive\n";
        else
            std::cout << name_ << " Dead :c \n";
    }
    // Wildebeest Get Name Method
    std::string getName() override
    {
        return name_;
    }
    // Wildebeest Set Dead Life Indicator
    void Dead() override
    {
        live_ = 0;
    }
private:

};

// Carnivorous Abstract Class (Abstract Product)
class Carnivorous abstract
{
public:
    // Virtual Methods
    virtual std::string getName() abstract;
    virtual float getPower() abstract;
    virtual void Eat(Herbivore& h) abstract;
    virtual void showPower() abstract;
protected:
    std::string name_;
    float power_;
};
// Leo Class (Concrete Product)
class Leo : public Carnivorous
{
public:
    // Default Constructor
    Leo()
    {
        name_ = "Lion";
        power_ = 200;
    }
    // Display Power Indicator Method
    void showPower() override
    {
        std::cout << name_ << " Power: " << power_ << "\n";
    }
    // Get Leo Name Method
    std::string getName() override
    {
        return name_;
    }
    // Get Leo Power Method
    float getPower() override
    {
        return power_;
    }
    // Wildebeest Display Eat Herbivore Method
    void Eat(Herbivore& h) override
    {
        std::cout << name_ << " Eats " << h.getName()  << "\n";
        h.Dead();
    }
private:

};
// Wolf Class  (Concrete Product)
class Wolf : public Carnivorous
{
public:
    // Default Constructor
    Wolf()
    {
        name_ = "Wolf";
        power_ = 100;
    }
    // Get Wolf Name Method
    std::string getName() override
    {
        return name_;
    }
    // Display Power Indicator Method
    void showPower() override
    {
        std::cout << name_ << " Power: " << power_ << "\n";
    }
    // Get Wolf Power Method
    float getPower() override
    {
        return power_;
    }
    // Wildebeest Display Eat Herbivore Method
    void Eat(Herbivore& h) override
    {
        std::cout << name_ << " eats " << h.getName() << "\n";
        h.Dead();
    }
private:

};
// Tiger Class (Concrete Product)
class Tiger : public Carnivorous
{
public:
    // Default Constructor
    Tiger()
    {
        name_ = "Tiger";
        power_ = 150;
    }
    // Get Tiger Name Method
    std::string getName() override
    {
        return name_;
    }
    // Get Wolf Power Method
    float getPower() override
    {
        return power_;
    }
    // Display Power Indicator Method
    void showPower()
    {
        std::cout << name_ << " Power: " << power_ << "\n";
    }
    // Wildebeest Display Eat Herbivore Method
    void Eat(Herbivore& h)
    {
        std::cout << name_ << " Eats " << h.getName() << "\n";
        h.Dead();
    }
private: 

};

// Continent Abstract Class (Abstract Factory)
class ContinentFactory abstract
{
public:
    // Create Herbivore
    virtual Herbivore& CreateHerbivore() abstract;

    // Create Carnivorous
    virtual Carnivorous& CreateCarnivore() abstract;
};

// Continent Class (Concrete Factory)
class Africa : public ContinentFactory
{
    // Create Herbivore
    Herbivore& CreateHerbivore()
    {
        return *(dynamic_cast<Herbivore*>(new Wildebeest()));
    }
    // Create Carnivorous
    Carnivorous& CreateCarnivore()
    {
        return *(dynamic_cast<Carnivorous*>(new Leo()));
    }
};
// Continent Class (Concrete Factory)
class NorthAmerica : public ContinentFactory
{
    // Create Herbivore
    Herbivore& CreateHerbivore()
    {
        return *(dynamic_cast<Herbivore*>(new Buffalo()));
    }
    // Create Carnivorous
    Carnivorous& CreateCarnivore()
    {
        return *(dynamic_cast<Carnivorous*>(new Wolf()));
    }
};
// Continent Class (Concrete Factory)
class Eurasia : public ContinentFactory
{
    // Create Herbivore
    Herbivore& CreateHerbivore()
    {
        return *(dynamic_cast<Herbivore*>(new Elk()));
    }
    // Create Carnivorous
    Carnivorous& CreateCarnivore()
    {
        return *(dynamic_cast<Carnivorous*>(new Tiger()));
    }
};

// Client Class 
class AnimalWorld
{
public:
    // Constructor with Parametres 
    AnimalWorld(ContinentFactory& factory) :_herbivore(factory.CreateHerbivore()), _carnivore(factory.CreateCarnivore())
    {
    }
    // Main Food Chain Loop 
    void RunFoodChain()
    {
        _herbivore.Live();
        _herbivore.Eat();
        _carnivore.showPower();
        _carnivore.Eat(_herbivore);
        _herbivore.Live();
    }
private:
    Herbivore& _herbivore;
    Carnivorous& _carnivore;
};

int main()
{
    // Create Factory 
    ContinentFactory& africa = *(dynamic_cast<ContinentFactory*>(new Africa()));
    AnimalWorld& world1 = *(new AnimalWorld(africa));
    world1.RunFoodChain();

    // Create Factory 
    ContinentFactory& america = *(dynamic_cast<ContinentFactory*>(new NorthAmerica()));
    AnimalWorld& world2 = *(new AnimalWorld(america));
    world2.RunFoodChain();

    // Create Factory 
    ContinentFactory& eurasia = *(dynamic_cast<ContinentFactory*>(new Eurasia()));
    AnimalWorld& world3 = *(new AnimalWorld(eurasia));
    world3.RunFoodChain();
}
